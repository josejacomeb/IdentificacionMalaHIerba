TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

unix:!macx: LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_video -lopencv_features2d -lopencv_videoio -lopencv_tracking -lopencv_imgcodecs

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include


