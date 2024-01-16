QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    component/combine/combine.cpp \
    component/frameless/frameless.cpp \
    component/rounded_corner/rounded_corner.cpp \
    component/select/select.cpp \
    main.cpp \
    control_panel.cpp

HEADERS += \
    component/combine/combine.h \
    component/frameless/frameless.h \
    component/rounded_corner/rounded_corner.h \
    component/select/select.h \
    control_panel.h

FORMS += \
    control_panel.ui

TRANSLATIONS += \
    control_panel_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
