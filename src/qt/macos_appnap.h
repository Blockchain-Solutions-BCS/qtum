// Copyright (c) 2011-2018 The Bitcoin Core developers
// Copyright (c) 2017-2020 The Qtum Core developers
// Copyright (c) 2020 The BCS Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_MACOS_APPNAP_H
#define BITCOIN_QT_MACOS_APPNAP_H

#include <memory>

class CAppNapInhibitor final
{
public:
    explicit CAppNapInhibitor();
    ~CAppNapInhibitor();

    void disableAppNap();
    void enableAppNap();

private:
    class CAppNapImpl;
    std::unique_ptr<CAppNapImpl> impl;
};

#endif // BITCOIN_QT_MACOS_APPNAP_H
