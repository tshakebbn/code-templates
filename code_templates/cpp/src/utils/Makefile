# Copyright [year] [organization]
#
# Build makefile for cpp utils library
#

# Include directives
include ../../Makefile.inc

# Include path for header dependencies
LOCAL_INCPATH = -I../../config

# Compiler flags
CXXFLAGS = $(SYSTEM_CXXFLAGS) $(LOCAL_INCPATH)

# Library construction flags
ARFLAGS = rvs

# Output library path
LIBRARY_OUTPUT_PATH = ../../build/lib

# Output library name
LIBRARY_NAME = libcpputils

# Install path
LIB_INSTALL_PATH = /usr/local/lib/cpp
HEAD_INSTALL_PATH = /usr/local/include/cpp

# Rules start here
all: cpputils

cpputils: $(LIBRARY_OUTPUT_PATH)/$(LIBRARY_NAME).a

$(LIBRARY_OUTPUT_PATH)/$(LIBRARY_NAME).a: log.o example.o
	mkdir -p $(LIBRARY_OUTPUT_PATH)
	$(RM) $(LIBRARY_OUTPUT_PATH)/$(LIBRARY_NAME).a
	$(AR) $(ARFLAGS) $(LIBRARY_OUTPUT_PATH)/$(LIBRARY_NAME).a log.o example.o

log.o: log.cpp
	$(CXX) $(CXXFLAGS) -c log.cpp

example.o: example.cpp
	$(CXX) $(CXXFLAGS) -c example.cpp

clean:
	$(RM) $(LIBRARY_OUTPUT_PATH)/$(LIBRARY_NAME).a
	$(RM) *.o

install:
	mkdir -p $(LIB_INSTALL_PATH)
	cp $(LIBRARY_OUTPUT_PATH)/$(LIBRARY_NAME).a $(LIB_INSTALL_PATH)
	mkdir -p $(HEAD_INSTALL_PATH)
	cp exceptions.hpp $(HEAD_INSTALL_PATH)
	cp example.hpp $(HEAD_INSTALL_PATH)
	cp log.hpp $(HEAD_INSTALL_PATH)

uninstall:
	$(RM) $(LIB_INSTALL_PATH)/$(LIBRARY_NAME).a
	$(RM) $(HEAD_INSTALL_PATH)/exceptions.hpp
	$(RM) $(HEAD_INSTALL_PATH)/example.hpp
	$(RM) $(HEAD_INSTALL_PATH)/log.hpp
