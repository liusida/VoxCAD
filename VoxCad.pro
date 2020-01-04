TEMPLATE = app
TARGET = VoxCad
QT += core gui xml opengl concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += debug
DEFINES += QT_XML_LIB QT_OPENGL_LIB USE_ZLIB_COMPRESSION USE_OPEN_GL QT_DLL PREC_MED
INCLUDEPATH += ../../../../Libs/qwt/src \
    . \
    ./../Voxelyze \
    ./Voxelyze/include \
    ../Voxelyze \
    ./GeneratedFiles/$(Configuration) \
    ./GeneratedFiles \
    ./../Utils \
    /usr/include/qwt
LIBS += \
#-lqwt \
#    -lOpenGL32 \
    -lGL \
 #   -lglu32 \
    -lglut \
    -lGLU \
    -lz \
    -lm
 #   -l qwt-qt4
DEPENDPATH += .
#DESTDIR = release
#MOC_DIR += ./GeneratedFiles/release
#OBJECTS_DIR += release
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(VoxCad.pri)
