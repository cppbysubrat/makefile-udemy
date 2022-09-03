# Shared Library creation
# AUTHOR:SUBRAT(V1.0)
#----------------------------
# NOTES:
#************************************************************************

BUILD_TYPE = $(RELEASE)
#BUILD_TYPE = $(DEBUG)
TARGET_NAME = db_mgr
MODULE_NAME = db_mgr

PROJ_ROOT_DIR = ../..
OBJ_DIR = $(PROJ_ROOT_DIR)/objs/$(MODULE_NAME)

#*****DONT MODIFY BELOW ATTRIBUTES****#
BUILD_TIMESTAMP = $(shell date +'%d-%m-%Y.%H-%M-%S.%N')

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
ifeq ($(INSTALLATION_PATH),)
        INSTALLATION_PATH = $(PROJ_ROOT_DIR)
#       INSTALLATION_PATH = /usr/local/mycustombuild

endif

TARGET_DIR = $(INSTALLATION_PATH)/libs
TARGET = $(TARGET_DIR)/lib$(TARGET_NAME).so
LIBRARY_DIR = $(TARGET_DIR)

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
#ADD ALL THE SOURCE FILES HERE. Don't put extenstion C/CPP. \
    As it makes creation of object files easy. If adding SOURCE_2, WE HAVE TO \
    UPDATE THE ALL_OBJS & TERGET(.o) EXPLICITLY#

SOURCE_1 = $(MODULE_NAME)
OBJ_1 = $(OBJ_DIR)/$(SOURCE_1).o
SOURCE_2 = db_reader
OBJ_2 = $(OBJ_DIR)/$(SOURCE_2).o

ALL_OBJS = $(OBJ_2) $(OBJ_1)

INC = -I./ -I$(PROJ_ROOT_DIR)/share_headers


#choose release/debug
DEBUG = -pipe -g -Wall -W -fPIC
RELEASE = -pipe -O3 -Wall -W -fPIC

# -D stands for DEFINE. If want to define any macro which is used in code for \
    #  timestamp or git revision etc, can be used in this way.
DEFINES = -DBUILD_TIMESTAMP_STR=\"$(BUILD_TIMESTAMP)\" \
	  -DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)\"

#UNCOMMENT IF LIKE TO SEE FOLLOWING WARNINGS. ATLEAST ONCE THIS NEEDS TO BE RUN\
FOR EACH MODULE
WARN=-Wall -Wextra -Werror -Wwrite-strings -Wno-parentheses \
     -pedantic -Warray-bounds -Wno-unused-variable -Wno-unused-function \
     -Wno-unused-parameter -Wno-unused-result

CCFLAGS = $(STDFLAG) $(BUILD_TYPE) $(DEFINES) $(WARN) $(INC)

# Add dependency library here by speparating them with space. \
    # Below example is to add libzmq & libm
#Add the "-L<path-to-library> -llibaryname" by keeping space in between \
    as shown below
DEP_LIBS = -L$(LIBRARY_DIR) -lemp

# RPATH IS USED FOR LINKING USER DEFINED LIBS IN SPECIFIC PATH DURING
# BUILDING THE MODULE.It is needed for the User of the .so. \
    # Unit test binary may use it.
#RPATH="-Wl,-rpath,$(TARGET_DIR):$(TARGET_DIR)/3rd_party_lib"
RPATH="-Wl,-rpath,$(TARGET_DIR)"

LDFLAGS = $(DEP_LIBS) $(RPATH)

.PHONY:testing_target

testing_target: %.o:%.cpp
	echo $<




all: $(TARGET)

$(TARGET): $(ALL_OBJS)
	$(LDXX) -shared -o $@ $^ $(LDFLAGS)
	make install

$(OBJ_1): $(SOURCE_1).cpp
	$(CXX) $(CCFLAGS) -o $@ -c $<

$(OBJ_2): $(SOURCE_2).cpp
	$(CXX) $(CCFLAGS) -o $@ -c $<

build_dir:
	@echo Creating object directory if not exist
	mkdir -p $(OBJ_DIR)

clean:
	@echo Clean Build
	-rm $(ALL_OBJS)
	-rm -f $(TARGET)

install:
	rsync -avz *.h $(PROJ_ROOT_DIR)/share_headers/

.PHONY: clean build_dir test all install
