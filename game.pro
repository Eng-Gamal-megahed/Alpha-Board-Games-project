QT       += core gui multimedia  # Added multimedia for sound support

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17  # Using C++17

# Uncomment to disable deprecated APIs before Qt 6.0.0
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Source files
SOURCES += \
    basic.cpp \
    fivexfive.cpp \
    fourxfour.cpp \
    inverse.cpp \
    main.cpp \
    mainwindow.cpp \
    numaric.cpp \
    pyramic.cpp \
    sus.cpp \
    word.cpp

# Header files
HEADERS += \
    BoardGame_Classes.h \
    basic.h \
    fivexfive.h \
    fourxfour.h \
    inverse.h \
    mainwindow.h \
    numaric.h \
    pyramic.h \
    sus.h \
    word.h

# UI files
FORMS += \
    basic.ui \
    fivexfive.ui \
    fourxfour.ui \
    inverse.ui \
    mainwindow.ui \
    numaric.ui \
    pyramic.ui \
    sus.ui \
    word.ui

# Deployment rules (for Unix systems)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    My_Resources.qrc

    RC_ICONS = Logo.ico
