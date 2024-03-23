QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += $$PWD/gt668

LIBS += -L$$PWD/gt668/libs -lGT668

SOURCES += \
    inputsdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    systemdialog.cpp \
    unitdialog.cpp

HEADERS += \
    gt668/gt668drv.h \
    inputsdialog.h \
    mainwindow.h \
    settingsdialog.h \
    systemdialog.h \
    unitdialog.h

FORMS += \
    inputsdialog.ui \
    mainwindow.ui \
    settingsdialog.ui \
    systemdialog.ui \
    unitdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore


