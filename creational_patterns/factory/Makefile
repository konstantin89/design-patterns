CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = example.cpp
EXECUTABLE = example

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE)