CPP=g++
CPPFLAGS=--std=c++14
RM=rm -f

SRCS=build_test.cpp build.cpp
TARGET=build

all:
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)

run:
	./$(TARGET)