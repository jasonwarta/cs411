CPP=g++
CPPFLAGS=--std=c++14
RM=rm -f

SRCS=contigsum_test.cpp
TARGET=out

all:
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)

run:
	clear;clear;./$(TARGET)

rebuild: clean all
	./$(TARGET)