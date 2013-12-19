TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
	node.cpp \
	listadj.cpp \
	graph.cpp \
	bipart.cpp \
	tree.cpp \
        cover.cpp \
        smallcovergraph.cpp

HEADERS += \
    node.h \
    listadj.h \
    graph.h \
    bipart.h \
    tree.h \
    cover.h \
    smallcovergraph.h

