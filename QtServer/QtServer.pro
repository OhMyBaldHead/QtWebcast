QT      += core gui
QT      += network
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    chatmanager.cpp \
    clientsocket.cpp \
    dbhelper.cpp \
    main.cpp \
    mainwindow.cpp \
    onlinedao.cpp \
    onlinedaoimp.cpp \
    socketmanager.cpp \
    user.cpp \
    userdao.cpp \
    userdaoimp.cpp

HEADERS += \
    chat.h \
    chatmanager.h \
    clientsocket.h \
    dbhelper.h \
    mainwindow.h \
    onlinedao.h \
    onlinedaoimp.h \
    socketmanager.h \
    user.h \
    userdao.h \
    userdaoimp.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
