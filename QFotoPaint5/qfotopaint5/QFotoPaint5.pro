#-------------------------------------------------
#
# Project created by QtCreator 2022-09-01T12:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFotoPaint5

TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    ajustelineal.cpp \
    bajorrelieve.cpp \
    capturarvideo.cpp \
    color_falso.cpp \
    convolucion.cpp \
    copiar_efecto.cpp \
    mainwindow.cpp \
    imagenes.cpp \
    dialognueva.cpp \
    brillocontraste.cpp \
    mat_sat_lum.cpp \
    modelo_color.cpp \
    morfo_mat.cpp \
    perspectiva.cpp \
    pinchar_estirar.cpp \
    rotar_imagen.cpp \
    suavizados.cpp \
    ver_info.cpp \
    video.cpp \
    rotaravideo.cpp \
    mediaponderada.cpp \
    acercade.cpp \
    mediadevideo.cpp

HEADERS  += mainwindow.h \
    ajustelineal.h \
    bajorrelieve.h \
    capturarvideo.h \
    color_falso.h \
    convolucion.h \
    copiar_efecto.h \
    imagenes.h \
    dialognueva.h \
    brillocontraste.h \
    mat_sat_lum.h \
    modelo_color.h \
    morfo_mat.h \
    perspectiva.h \
    pinchar_estirar.h \
    rotar_imagen.h \
    suavizados.h \
    ver_info.h \
    video.h \
    rotaravideo.h \
    mediaponderada.h \
    acercade.h \
    mediadevideo.h

FORMS    += mainwindow.ui \
    ajustelineal.ui \
    bajorrelieve.ui \
    capturarvideo.ui \
    color_falso.ui \
    convolucion.ui \
    copiar_efecto.ui \
    dialognueva.ui \
    brillocontraste.ui \
    mat_sat_lum.ui \
    modelo_color.ui \
    morfo_mat.ui \
    perspectiva.ui \
    pinchar_estirar.ui \
    rotar_imagen.ui \
    suavizados.ui \
    rotaravideo.ui \
    mediaponderada.ui \
    acercade.ui \
    mediadevideo.ui \
    ver_info.ui

INCLUDEPATH += "C:\OpenCV\OpenCV4.6.0G\include"

LIBS += -L"C:\OpenCV\OpenCV4.6.0G\lib"\
        -llibopencv_world460

RESOURCES += recursos.qrc

RC_ICONS = imagenes/icono.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
