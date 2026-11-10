CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = application.exe
OBJS = app.o circle.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

app.o: app.cpp circle.h
	$(CXX) $(CXXFLAGS) -c app.cpp

circle.o: circle.cpp circle.h
	$(CXX) $(CXXFLAGS) -c circle.cpp

clean:
	C:/msys64/usr/bin/rm.exe -f $(TARGET) $(OBJS)

.PHONY: all clean
