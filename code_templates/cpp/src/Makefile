# Copyright [year] [organization]
#
# Build makefile for cpp apps
#

# Include directives
include ../Makefile.inc

# Include path for header dependencies
LOCAL_INCPATH = -I../build/include -I../config

# Include path for library dependencies
LIB_INCPATH = -L../build/lib

# Compiler flags
CXXFLAGS = $(SYSTEM_CXXFLAGS) $(LOCAL_INCPATH) $(LIB_INCPATH)

# Linking dependencies
LDFLAGS = -lcpputils -lboost_log -lpthread -lboost_thread -lboost_system -lboost_log_setup -lboost_program_options

# Output executable path
EXE_OUTPUT_PATH = ../build/bin

# Output executable name
EXAMPLE_EXE_NAME = cpp_example_app

# Install path
BIN_INSTALL_PATH = /usr/local/bin

# Rules start here
all: cpputils cpp-example-app

cpputils:
	$(MAKE) -C utils/

cpp-example-app: $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)

$(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME): example_app.o
	mkdir -p $(EXE_OUTPUT_PATH)
	$(RM) $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)
	$(CXX) $(CXXFLAGS) example_app.o -o $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME) $(LDFLAGS)

example_app.o: example_app.cpp
	$(CXX) $(CXXFLAGS) -c example_app.cpp $(LDFLAGS)

clean:
	$(MAKE) -C utils/ clean
	$(RM) $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)
	$(RM) *.o

install:
	$(MAKE) -C utils/ install
	cp $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME) $(BIN_INSTALL_PATH)

uninstall:
	$(MAKE) -C utils/ uninstall
	$(RM) $(BIN_INSTALL_PATH)/$(EXAMPLE_EXE_NAME)
