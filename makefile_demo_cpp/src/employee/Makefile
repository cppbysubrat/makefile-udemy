# Static Library creation
# AUTHOR:SUBRAT(V1.0)
#----------------------------
# NOTES:
#************************************************************************

BUILD_TYPE = $(RELEASE)
#BUILD_TYPE = $(DEBUG)
MODULE_NAME = employee
TARGET_NAME = emp

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
TARGET = $(TARGET_DIR)/lib$(TARGET_NAME).a

# C++ compiler
CXX = $(shell echo $$CXX)
ifeq ($(CXX),)
CXX = g++
endif

LDXX = ar rcs 

STDFLAG = -std=c++17

#*****DONT MODIFY ABOVE ATTRIBUTES****#
SOURCE_1 = $(MODULE_NAME).cpp
OBJ_1 = $(OBJ_DIR)/$(MODULE_NAME).o

ALL_OBJS = $(OBJ_1)

INC = -I./ -I$(PROJ_ROOT_DIR)/shared_headers

#choose release/debug
DEBUG = -pipe -g -Wall -W -fPIC
RELEASE = -pipe -O2 -Wall -W -fPIC

# -D stands for DEFINE. If want to define any macro which is used in code for\
    #  timestamp or git revision etc, can be used in this way.
CC_OPT = -DBUILD_TIMESTAMP_STR=\"$(BUILD_TIMESTAMP)\" \
	 -DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)\"

#UNCOMMENT IF LIKE TO SEE FOLLOWING WARNINGS. ATLEAST ONCE THIS NEEDS TO BE RUN\
    FOR EACH MODULE
WARN=-Wall -Wextra -Werror -Wwrite-strings -Wno-parentheses -pedantic \
     -Warray-bounds -Wno-unused-variable -Wno-unused-function \
     -Wno-unused-parameter -Wno-unused-result

CCFLAGS = $(STDFLAG) $(BUILD_TYPE) $(CC_OPT) $(WARN) $(INC)

all: $(TARGET)

$(TARGET): $(ALL_OBJS)
	$(LDXX) $@ $^ 
	make install

$(OBJ_1): $(SOURCE_1)
	$(CXX) $(CCFLAGS) -o $@ -c $<

build_dir:
	@echo Creating object directory if not exist
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TARGET_DIR) 
# It also can be written as $(TARGET_DIR)

clean:
	@echo Clean Build
	-rm $(ALL_OBJS)
	-rm -f $(TARGET)

install:
	rsync -avz *.h $(PROJ_ROOT_DIR)/share_headers/

.PHONY: clean build_dir test all install
