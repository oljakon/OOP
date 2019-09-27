#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T14:59:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_03
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
	gui/mainwindow.cpp \
    3dparty/jsmn.c \
    upload/uploader.cpp \
    objects/model.cpp \
    objects/camera.cpp \
    transformations/dimensional_transformations.cpp \
    controller/controller.cpp \
    scene/scene.cpp \
    transformations/transformation_interface.cpp \
    objects/composite_object.cpp \
    upload/builder.cpp \
    objects/node.cpp \
    objects/edge.cpp

HEADERS  += gui/mainwindow.hpp \
    containers/vector/vector_base.hpp \
    containers/vector/vector.hpp \
    containers/iterator/iterator_base.hpp \
    containers/matrix/matrix_base.hpp \
    containers/matrix/matrix.hpp \
    containers/iterator/const_iterator.hpp \
    containers/iterator/iterator.hpp \
    upload/uploader.hpp \
    exceptions/base_exception.hpp \
    exceptions/container_exceptions.hpp \
    exceptions/upload_exceptions.hpp \
    primitives/point3d.hpp \
    containers/pair/pair.hpp \
    3dparty/jsmn.h \
    objects/visible_object.hpp \
    objects/invisible_object.hpp \
    objects/scene_object.hpp \
    objects/model.hpp \
    objects/camera.hpp \
    managers/upload_manager.hpp \
    managers/camera_manager.hpp \
    managers/model_manager.hpp \
    managers/draw_manager.hpp \
    controller/controller.hpp \
    facade/facade.hpp \
    scene/scene.hpp \
    commands/command.hpp \
    model_view/model_view.hpp \
    exceptions/model_view_exceptions.hpp \
    exceptions/scene_exceptions.hpp \
    transformations/dimensional_transformations.hpp \
    transformations/transformation_interface.hpp \
    transformations/base_transformations.hpp \
    transformations/model_transformations.hpp \
    primitives/matrix4x4.hpp \
    primitives/vector4d.hpp \
    transformations/command_interface.hpp \
    gui/drawer.hpp \
    objects/composite_object.hpp \
    upload/base_uploader.hpp \
    upload/base_builder.hpp \
    upload/builder.hpp \
    objects/node.h \
    objects/edge.h

FORMS    += gui/mainwindow.ui
