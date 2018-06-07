# Copyright [year] [organization]
#
# Build makefile for cpp tests
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
LDFLAGS = -lcpputils -lgtest -lboost_log -lpthread -lboost_thread -lboost_system -lboost_log_setup -lboost_program_options

# Output executable path
EXE_OUTPUT_PATH = ../build/bin

# Output executable names
EXAMPLE_EXE_NAME = test_example
LOG_EXE_NAME = test_log

# Rules start here
all: test-log test-example

test-log: $(EXE_OUTPUT_PATH)/$(LOG_EXE_NAME)

$(EXE_OUTPUT_PATH)/$(LOG_EXE_NAME): test_log.o
	mkdir -p $(EXE_OUTPUT_PATH)
	$(CXX) $(CXXFLAGS) test_log.o -o $(EXE_OUTPUT_PATH)/$(LOG_EXE_NAME) $(LDFLAGS)

test_log.o: test_log.cpp
	$(CXX) $(CXXFLAGS) -c test_log.cpp $(LDFLAGS)

test-example: $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)

$(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME): test_example.o
	mkdir -p $(EXE_OUTPUT_PATH)
	$(CXX) $(CXXFLAGS) test_example.o -o $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME) $(LDFLAGS)

test_example.o: test_example.cpp
	$(CXX) $(CXXFLAGS) -c test_example.cpp $(LDFLAGS)

clean:
	$(RM) $(EXE_OUTPUT_PATH)/$(LOG_EXE_NAME)
	$(RM) $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)
	$(RM) *.o
