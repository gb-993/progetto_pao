QT       += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    main.cpp \
    mainwindow.cpp \
    sensor.cpp \
    sensor_filter.cpp \
    sensor_generator.cpp \
    sensor_humidity.cpp \
    sensor_light.cpp \
    sensor_manager.cpp \
    sensor_temperature.cpp \
    sensor_volume.cpp

HEADERS += \
    controller.h \
    mainwindow.h \
    sensor.h \
    sensor_filter.h \
    sensor_generator.h \
    sensor_humidity.h \
    sensor_light.h \
    sensor_manager.h \
    sensor_temperature.h \
    sensor_volume.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
