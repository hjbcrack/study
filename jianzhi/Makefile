CC=g++
BIN=jianzhi
INCLUDE_DIR="./../common/"
COMMON_DIR="./../common/common.c"

jianzhi: clean
	$(CC) jianzhi.c $(COMMON_DIR) -o $(BIN) -I$(INCLUDE_DIR)

all: jianzhi

clean:
	-rm jianzhi
