# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = Prototype_Fantasy_Maze
DESTDIR = ./Win32/Debug
QT += core gui network xml webkit svg declarative
CONFIG += qtestlib help debug console
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL QT_OPENGL_LIB QT_NETWORK_LIB QT_SQL_LIB QT_XML_LIB QT_SVG_LIB QT_WEBKIT_LIB QT_XMLPATTERNS_LIB QT_DECLARATIVE_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(Prototype_Fantasy_Maze.pri)
TRANSLATIONS += prototype_fantasy_maze_de.ts
win32:RC_FILE = Prototype_Fantasy_Maze.rc
