CPP=g++
CPPFLAGS=--std=c++14
RM=rm -f

SRCS=huffcode.cpp huffcode_test.cpp
TARGET=out

all:
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)

run:
	./$(TARGET)

rebuild: clean all
	./$(TARGET)