CONFIG += qt debug
QT     += core widgets sql

DESTDIR  = bin
TARGET   = Menugen
TEMPLATE = app

TEMP_FILES  = bin/tmp
MOC_DIR     = $$TEMP_FILES
OBJECTS_DIR = $$TEMP_FILES


SOURCES += src/main.cpp \
           src/MainWindow.cpp \


HEADER  += src/MainWindow.hpp \

FORMS   += ui/MainWindow.ui
