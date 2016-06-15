# Generated automatically from Makefile.in by configure.
SHELL			=	/bin/sh

prefix			=	/home/cbilder
exec_prefix		=	${prefix}
host_os			=	linux-gnu
srcdir			=	.
top_srcdir		=	.
enable_debug		=	no

# Where to find includes for libraries that Benchtest depends on.
INCPATHS = -I$(prefix)/include  -I/usr/lib/qt-2.3.0/include -I/usr/share/pvm3/include

# libs that the program depends on
LIBS = -lBenchmarkLib  -lMiscUtils -lqt -lpvm3 

# lib dirs that the program needs
LIBDIRS = -L/usr/lib/qt-2.3.0/lib -L$(prefix)/lib -L/usr/share/pvm3/lib/LINUX

ifeq ($(enable_debug),yes)
DEBUG= -g -Wall
else
DEBUG= -O2
endif


CC= gcc
CXX= c++
CXXFLAGS= $(NOUCHAR) $(DEBUG) $(INCPATHS)
RANLIB=ranlib

SRCS=   main.cpp \
	PVMSBenchResultsDialog.cpp \
	PVMSBenchmarkInput.cpp  \
	PVMSBenchTester.cpp \
	PVMSBenchResults.cpp \
	PVMServerBenchmarkInputDialog.cpp \
	moc_PVMServerBenchmarkInputDialog.cpp \
	moc_PVMSBenchmarkInput.cpp \
	moc_PVMSBenchResults.cpp

OBJS=$(SRCS:.cpp=.o)

.SUFFIXES: .o .cpp

# Suffix rules
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

all: pvmsbenchtest
	@echo "WhooHoo!."

pvmsbenchtest: files $(OBJS)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $(OBJS) -o pvmsbenchtest $(LIBS)

clean::
	rm -f pvmsbenchtest core *~ $(OBJS) PVMSBenchmarkInput.h PVMSBenchmarkInput.cpp PVMSBenchResults.h PVMSBenchResults.cpp moc_PVMSBenchmarkInput.cpp moc_PVMSBenchResults.cpp

files: PVMSBenchmarkInput.cpp PVMSBenchResults.cpp

distclean: clean
	rm -f Makefile config.h config.status config.cache config.log 

PVMSBenchmarkInput.h:
	uic -o PVMSBenchmarkInput.h PVMServerBenchmark.ui

PVMSBenchmarkInput.cpp: PVMSBenchmarkInput.h
	uic -i PVMSBenchmarkInput.h -o PVMSBenchmarkInput.cpp PVMServerBenchmark.ui

PVMSBenchResults.h:
	uic -o PVMSBenchResults.h PVMSBenchResults.ui

PVMSBenchResults.cpp: PVMSBenchResults.h
	uic -i PVMSBenchResults.h -o PVMSBenchResults.cpp PVMSBenchResults.ui 

moc_PVMSBenchmarkInput.cpp: PVMSBenchmarkInput.h
	moc -o moc_PVMSBenchmarkInput.cpp PVMSBenchmarkInput.h

moc_PVMSBenchResults.cpp: PVMSBenchResults.h
	moc -o moc_PVMSBenchResults.cpp PVMSBenchResults.h
moc_PVMServerBenchmarkInputDialog.cpp:
	moc -o moc_PVMServerBenchmarkInputDialog.cpp PVMServerBenchmarkInputDialog.h
