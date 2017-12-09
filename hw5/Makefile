CPP=g++
CPPFLAGS=--std=c++14
RM=rm -f

SRCS=build_test2.cpp build.cpp
TARGET=out

all:
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(TARGET)

clean:
	$(RM) $(TARGET)

run:
	./$(TARGET)

rebuild: clean all
	./$(TARGET)