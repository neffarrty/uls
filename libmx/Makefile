CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
ARFLAGS = rcs

TARGET = libmx.a

OBJ_DIR = obj
SRC_DIR = src

.PHONY: all clean uninstall reinstall

all: $(TARGET)
	
$(TARGET):	
	@mkdir $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC_DIR)/*.c
	@mv *.o $(OBJ_DIR)
	@ar $(ARFLAGS) $@ $(OBJ_DIR)/*.o

clean:
	@rm -rf $(OBJ_DIR)

uninstall:
	@rm -f $(TARGET)

reinstall: clean reinstall all


