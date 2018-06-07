# Copyright [year] [organization]
#
# Top level makefile include directives for cpp
#

# Setup tool directives
AR = ar
CXX = g++

# System definitions
SYSTEM_CXXFLAGS += -DBOOST_LOG_DYN_LINK -Wall -O3
