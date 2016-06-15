# Generated automatically from Makefile.in by configure.
SHELL			=	/bin/sh

prefix			=	/home/cbilder
exec_prefix		=	${prefix}
host_os			=	linux-gnu
srcdir			=	.
top_srcdir		=	.
enable_debug		=	no

# Where to find includes for libraries that Benchtest depends on.
INCPATHS = -I$(prefix)/include  -I/usr/share/pvm3/include

# libs that the program depends on
LIBS = -lBenchmarkLib  -lMiscUtils -lpvm3 

# lib dirs that the program needs
LIBDIRS = -L$(prefix)/lib -L/usr/share/pvm3/lib/LINUX

ifeq ($(enable_debug),yes)
DEBUG= -g -Wall
else
DEBUG= -O2
endif


CC= gcc
CXX= c++
CXXFLAGS= $(NOUCHAR) $(DEBUG) $(INCPATHS)
RANLIB=ranlib

SRCS=   ServerBenchConsole.cpp \
	main.cpp

OBJS=$(SRCS:.cpp=.o)

.SUFFIXES: .o .cpp

# Suffix rules
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

all: pvmsbenchtest
	@echo "WhooHoo!."

pvmsbenchtest: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) $(OBJS) -o pvmsbenchtest $(LIBS)

clean::
	rm -f pvmsbenchtest core *~ $(OBJS)

distclean: clean
	rm -f Makefile config.h config.status config.cache config.log 