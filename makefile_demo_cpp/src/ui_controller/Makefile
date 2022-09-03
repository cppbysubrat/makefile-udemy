#************************************************************************
# SAMPLE MAKEFILE FOR TARGET - BINARY
# # NOTES:
# We may have to modify following attributes.

#************************************************************************
BUILD_TYPE = $(RELEASE)
#BUILD_TYPE = $(DEBUG)
MODULE_NAME = ui_controller
TARGET_NAME = uic

PROJ_ROOT_DIR = ../..
OBJ_DIR = $(PROJ_ROOT_DIR)/objs/$(MODULE_NAME)

#*****DONT MODIFY BELOW ATTRIBUTES****#
BUILD_TIMESTAMP = $(shell date +'%d-%m-%Y.%H-%M-%S.%N')

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
ifeq ($(INSTALLATION_PATH),)
        INSTALLATION_PATH = $(PROJ_ROOT_DIR)
#       INSTALLATION_PATH = /usr/local/mycustombuild

endif

TARGET_DIR = $(INSTALLATION_PATH)/bins
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

LIBRARY_DIR = $(INSTALLATION_PATH)/libs

# C++ compiler
CXX = $(shell echo $$CXX)
ifeq ($(CXX),)
CXX = g++
endif

# C++ linker
LDXX = $(shell echo $$CXX)
ifeq ($(LDXX),)
LDXX = g++
endif

STDFLAG = -std=c++17


#*****DONT MODIFY ABOVE ATTRIBUTES****#

MAIN_OBJ = $(OBJ_DIR)/main.o

SOURCE_1 = $(MODULE_NAME)
OBJ_1 = $(OBJ_DIR)/$(SOURCE_1).o

#MAY NEED TO ADD MORE DEPENDENCIES AS PER REQUIREMENT.\
    1. DONT ADD EXTENSION C/CPP AS IT MAKES EASIER TO CREATE .o FILE \
    OTHERWISE IT'LL CREATE *.cpp.o WHICH IS OK! \
    2. ADD *.o IN ALL_OBJS. \
    3. ADD INSTRUCTION TO BUILD TARGET(.o)

#SOURCE_2 =
#OBJ_2 = $(OBJ_DIR)/$(SOURCE_2).o
#SOURCE_3 = module-name
#OBJ_3 = $(OBJ_DIR)/$(SOURCE_3).o

# Add OBJ_* in the begining if required
ALL_OBJS = $(OBJ_1) $(MAIN_OBJ)

INC = -I./ -I$(PROJ_ROOT_DIR)/share_headers

#choose release/debug
DEBUG = -pipe -g -Wall -W -fPIC
#RELEASE =-DNDEBUG -W -fPIC
RELEASE = -pipe -O3 -Wall -W -fPIC

# -D stands for DEFINE. If want to define any\
    macro which is used in code for timestamp or git revision etc, can use in\
    this way.
DEFINES = -DBUILD_TIMESTAMP_STR=\"$(BUILD_TIMESTAMP)\" \
	  -DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)\"
#LD_OPT = -Wl,-O1

#UNCOMMENT IF LIKE TO SEE FOLLOWING WARNINGS. ATLEAST ONCE THIS NEEDS TO BE \
    RUN FOR EACH MODULE
WARN = -Wall -Wextra -Werror -Wwrite-strings -Wno-parentheses -pedantic \
     -Warray-bounds -Wno-unused-variable -Wno-unused-function \
     -Wno-unused-parameter -Wno-unused-result

CCFLAGS = $(STDFLAG) $(BUILD_TYPE) $(DEFINES) $(WARN) $(INC)

# Add dependency library here by speparating them with space. Below example is \
# to add libzmq, libm & libcustomlib

#Note: Add the "<path-to-library> -llibaryname" by keeping space in between as \
    shown below. If library is present in the current directory, \
    we can use path as L.

DEP_LIBS = -L$(LIBRARY_DIR) -ldb_mgr

# RPATH IS USED FOR LINKING LIBS IN SPECIFIC PATH
#RPATH="-Wl,-rpath,$(LIBRARY_DIR):$(THIRD_PARTY_LIB_DIR)"
RPATH="-Wl,-rpath,$(LIBRARY_DIR)"

#LDFLAGS = $(DEBUG) $(PROF) -L$(LIBRARY_DIR) -L$(THIRD_PARTY_LIB_DIR) -fPIC \
    -lpthread $(DEP_LIBS) $(RPATH)
LDFLAGS = $(DEP_LIBS) $(RPATH)

all: $(TARGET)

$(TARGET): $(ALL_OBJS)
	$(LDXX) $(LD_OPT) -o $@ $^ $(LDFLAGS)

$(MAIN_OBJ): main.cpp
	$(CXX) $(CCFLAGS) -o $@ -c $<

$(OBJ_1): $(SOURCE_1).cpp
	$(CXX) $(CCFLAGS) -o $@ -c $<

#$(OBJ_2): $(SOURCE_2).cpp
#	$(CXX) $(CCFLAGS) -o $@ -c $<


build_dir:
	@echo Creating object directory if not exist
	mkdir -p $(OBJ_DIR) $(TARGET_DIR)

clean:
	@echo Clean Build
	-rm $(ALL_OBJS)
	-rm $(TARGET)

.PHONY: clean build_dir all
