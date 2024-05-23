QT += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    charts_layout.cpp \
    confirm_delete_window.cpp \
    controller.cpp \
    create_sensor_window.cpp \
    general_window.cpp \
    info_layout.cpp \
    main.cpp \
    mainwindow.cpp \
    modify_sensor_window.cpp \
    sensor.cpp \
    sensor_filter.cpp \
    sensor_generator.cpp \
    sensor_humidity.cpp \
    sensor_info_visitor.cpp \
    sensor_light.cpp \
    sensor_manager.cpp \
    sensor_modify_visitor.cpp \
    sensor_options.cpp \
    sensor_temperature.cpp \
    sensor_volume.cpp \
    sensors_list_layout.cpp \
    single_sensor_layout.cpp \
    top_layout.cpp

HEADERS += \
    charts_layout.h \
    confirm_delete_window.h \
    controller.h \
    create_sensor_window.h \
    general_window.h \
    info_layout.h \
    mainwindow.h \
    modify_sensor_window.h \
    sensor.h \
    sensor_filter.h \
    sensor_generator.h \
    sensor_humidity.h \
    sensor_info_visitor.h \
    sensor_light.h \
    sensor_manager.h \
    sensor_modify_visitor.h \
    sensor_observer_interface.h \
    sensor_options.h \
    sensor_temperature.h \
    sensor_visitor_interface.h \
    sensor_volume.h \
    sensors_list_layout.h \
    single_sensor_layout.h \
    top_layout.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
