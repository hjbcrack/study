CC=g++
BIN1=paixu
BIN2=suanfa
INCLUDE_DIR="./../common/"
COMMON_DIR="./../common/common.c"

paixu: clean
	$(CC) paixu.c $(COMMON_DIR) -o $(BIN1) -I$(INCLUDE_DIR) -lrt

suanfa: clean
	$(CC) suanfa.c $(COMMON_DIR) -o $(BIN2) -I$(INCLUDE_DIR) -lrt -lpthread

all: paixu suanfa

clean:
	-rm paixu suanfa
