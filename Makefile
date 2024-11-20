CXX = g++
CXXFLAGS = -std=c++11 -Wall

SOURCES = main.cpp LibraryItem.cpp Book.cpp AudioCD.cpp DVD.cpp Patron.cpp Loan.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = library_system

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)
