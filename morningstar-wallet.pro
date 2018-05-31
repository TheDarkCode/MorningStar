include(morningstar-wallet.pri)

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += wallet

#MORNINGSTAR_CONFIG += Tests

contains( MORNINGSTAR_CONFIG, Tests ) {
    SUBDIRS += wallet/test
}
