#include "bcspushbutton.h"
#include <QStylePainter>

BCSPushButton::BCSPushButton(QWidget *parent):
    QPushButton(parent),
    m_iconCached(false)
{}

BCSPushButton::BCSPushButton(const QString &text, QWidget *parent):
    QPushButton(text, parent),
    m_iconCached(false)
{}

void BCSPushButton::paintEvent(QPaintEvent *)
{
    QStylePainter p(this);
    QStyleOptionButton option;
    initStyleOption(&option);
    updateIcon(option);
    p.drawControl(QStyle::CE_PushButton, option);
}

void BCSPushButton::updateIcon(QStyleOptionButton &pushbutton)
{
    // Update sunken icon
    if((pushbutton.state & QStyle::State_Enabled) &&
            !pushbutton.icon.isNull() &&
            isDown())
    {
        if(!m_iconCached)
        {
            QIcon icon = pushbutton.icon;
            QPixmap pixmap = icon.pixmap(pushbutton.iconSize, QIcon::Selected, QIcon::On);
            m_downIcon = QIcon(pixmap);
            m_iconCached = true;
        }
        if(!m_downIcon.isNull())
            pushbutton.icon = m_downIcon;
    }
}
