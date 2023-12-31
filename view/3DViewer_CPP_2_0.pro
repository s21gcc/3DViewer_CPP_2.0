QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../model/model.cc \
    ../model/obj/obj.cc \
    ../model/transformer/affine_transformer.cc \
    main.cpp \
    mainwindow.cpp \
    render.cpp

HEADERS += \
    ../model/model.h \
    ../model/obj/obj.h \
    ../model/transformer/affine_transformer.h \
    mainwindow.h \
    render.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
