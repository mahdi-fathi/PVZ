CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g -O0 -I./include
LFLAGS = -L./files -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRCDIR = src
OBJDIR = obj
BUILDDIR = build
EXECUTABLE = $(BUILDDIR)/PVZ.out
MEDIA_PATH = ./files/

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

debug: $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES) $(LFLAGS)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(SRCDIR)/*.hpp)
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(MEDIA_PATH)

clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)
