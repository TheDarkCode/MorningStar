TEMPLATE = app
TARGET = morningstar-qt
VERSION = 1.0.7
INCLUDEPATH += . json qt
DEFINES += QT_GUI BOOST_THREAD_USE_LIB BOOST_SPIRIT_THREADSAFE
CONFIG += no_include_pwd
CONFIG += thread

MORNINGSTAR_ROOT = $${PWD}/../

VPATH += $${MORNINGSTAR_ROOT}/wallet/ $${MORNINGSTAR_ROOT}/wallet/json $${MORNINGSTAR_ROOT}/wallet/qt


# use: qmake "MORNINGSTAR_REST=1"
contains(MORNINGSTAR_REST, 1) {
    DEFINES += MORNINGSTAR_REST
    # restbed
    LIBS += -L"$(CURDIR)/restbed/distribution/library" -lrestbed
    INCLUDEPATH += "$(CURDIR)/restbed/distribution/include/"
    QMAKE_CXXFLAGS += -std=c++11
}

include(wallet.pri)
include(wallet-libs.pri)

RESOURCES += \
    qt/bitcoin.qrc

system($$QMAKE_LRELEASE -silent $$_PRO_FILE_)

DISTFILES +=                                \
    .travis.yml                             \
    ci_scripts/test_linux-daemon.py         \
    ci_scripts/test_linux-gui_wallet.py     \
    ci_scripts/test_win32-gui_wallet.py     \
    ci_scripts/morningstar_ci_libs/__init__.py   \
    ci_scripts/morningstar_ci_libs/common.py
