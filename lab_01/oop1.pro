QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        mainwindow.cpp \
    memory.cpp \
    geometry.cpp \
    actiongeometry.cpp \
    action.cpp \
    mygraphicview.cpp \
    drawing.cpp \
    file.cpp \
    counts.cpp \
    edge.cpp \
    edges.cpp \
    point.cpp \
    points.cpp \
    model.cpp \
    processor.cpp \
    controller.cpp \
    pointmath.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui \
    mygraphicview.ui \
    controller.ui

HEADERS  += mainwindow.h \
    memory.h \
    geometry.h \
    actiongeometry.h \
    action.h \
    mygraphicview.h \
    my_scene.h \
    drawing.h \
    error.h \
    file.h \
    counts.h \
    edge.h \
    edges.h \
    point.h \
    points.h \
    model.h \
    processor.h \
    controller.h \
    pointmath.h

