MODULE_NAME = mod4

TARGET_DIR = ../../libs
TARGET_NAME = lib$(MODULE_NAME).a
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -fPIC -Wall -Werror
LDFLAGS = 

$(TARGET): $(OBJ1)
	 ar rcs $@ $^ 
	
$(OBJ1): $(MODULE_NAME).cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) $(OBJ1)

install:
	cp *.h ../../share_headers/
