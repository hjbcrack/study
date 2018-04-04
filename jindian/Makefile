CC=g++
BIN=jindian
INCLUDE_DIR="./../common/"
COMMON_DIR="./../common/common.c"

jindian: clean
	$(CC) jindian.c $(COMMON_DIR) -o $(BIN) -I$(INCLUDE_DIR)

all: jindian


clean:
	-rm jindian
