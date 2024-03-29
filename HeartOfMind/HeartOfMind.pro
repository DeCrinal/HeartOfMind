QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core.cpp \
    gui/authdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    programmsetting.cpp \
    pwdmanager/pwdmanager.cpp \
    pwdmanager/pwdnote.cpp \
    pwdmanager/pwdstorage.cpp \
    versioncontroller.cpp

HEADERS += \
    core.h \
    gui/authdialog.h \
    mainwindow.h \
    programmsetting.h \
    pwdmanager/pwdmanager.h \
    pwdmanager/pwdnote.h \
    pwdmanager/pwdstorage.h \
    versioncontroller.h

FORMS += \
    gui/authdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mainrc.qrc
