MODULE_NAME = mod2
TEST_MODULE = test_mod2
TEST_BIN_DIR = ../../test_bins
TEST_TARGET = $(TEST_BIN_DIR)/$(TEST_MODULE)

TARGET_DIR = ../../libs
TARGET_NAME = lib$(MODULE_NAME).so
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -fPIC -Wall -Werror
LDFLAGS = 

$(TARGET): $(OBJ1)
	g++ -shared $< -o $@ $(LDFLAGS)
	
$(OBJ1): $(MODULE_NAME).cpp
	g++ $(CFLAGS) -c $< -o $@

test:  $(TEST_MODULE).cpp $(TARGET)
	g++ $< -o $(TEST_TARGET) -L$(TARGET_DIR) -l$(MODULE_NAME)

clean:
	rm $(TARGET) $(OBJ1) $(TEST_TARGET)

build_dir:
	mkdir -p $(TEST_BIN_DIR)

install:
	cp *.h ../../share_headers/

.PHONEY: install test clean build_dir

