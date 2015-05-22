
CC=g++
CFLAGS=-c -Wall -s
LDFLAGS=-lallegro

SOURCEDIR=src
BUILDDIR=build
SOURCES=src/main.cpp

OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
EXECUTABLE=bricks

all: clean dir $(BUILDDIR)/$(EXECUTABLE) 

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf $(BUILDDIR)/*

