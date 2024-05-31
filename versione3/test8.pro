QT += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = progetto
INCLUDEPATH += .

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/charts_layout.cpp \
    View/confirm_delete_window.cpp \
    Controller/controller.cpp \
    View/create_sensor_window.cpp \
    View/custom_button.cpp \
    View/info_layout.cpp \
    main.cpp \
    View/mainwindow.cpp \
    View/modify_sensor_window.cpp \
    Model/sensor.cpp \
    Model/sensor_filter.cpp \
    Model/sensor_generator.cpp \
    Model/sensor_humidity.cpp \
    View/sensor_info_visitor.cpp \
    Model/sensor_light.cpp \
    Model/sensor_manager.cpp \
    View/sensor_modify_visitor.cpp \
    View/sensor_options.cpp \
    Model/sensor_temperature.cpp \
    Model/sensor_volume.cpp \
    View/sensors_list_layout.cpp \
    View/single_sensor_layout.cpp \
    View/top_layout.cpp


HEADERS += \
    View/charts_layout.h \
    View/confirm_delete_window.h \
    Controller/controller.h \
    View/create_sensor_window.h \
    View/custom_button.h \
    View/info_layout.h \
    View/mainwindow.h \
    View/modify_sensor_window.h \
    Model/sensor.h \
    Model/sensor_filter.h \
    Model/sensor_generator.h \
    Model/sensor_humidity.h \
    View/sensor_info_visitor.h \
    Model/sensor_light.h \
    Model/sensor_manager.h \
    View/sensor_modify_visitor.h \
    Model/sensor_observer_interface.h \
    View/sensor_options.h \
    Model/sensor_temperature.h \
    Model/sensor_visitor_interface.h \
    Model/sensor_volume.h \
    View/sensors_list_layout.h \
    View/single_sensor_layout.h \
    View/top_layout.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
