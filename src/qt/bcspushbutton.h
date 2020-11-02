#ifndef BCSPUSHBUTTON_H
#define BCSPUSHBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QIcon>

class BCSPushButton : public QPushButton
{
public:
    explicit BCSPushButton(QWidget * parent = Q_NULLPTR);
    explicit BCSPushButton(const QString &text, QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateIcon(QStyleOptionButton &pushbutton);

private:
    bool m_iconCached;
    QIcon m_downIcon;
};

#endif // BCSPUSHBUTTON_H
