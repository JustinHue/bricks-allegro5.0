
CC := g++
CFLAGS := -c -Wall -s
LDFLAGS := -lallegro -lallegro_primitives

SOURCEDIR := src
BUILDDIR := build
MAIN := $(SOURCEDIR)/main.cpp
EXECUTABLE := bricks

SOURCES := $(filter-out $(MAIN), $(wildcard $(SOURCEDIR)/*.cpp)) $(wildcard $(SOURCEDIR)/*/*.cpp)
OBJECTS := $(addprefix $(BUILDDIR)/,$(notdir $(SOURCES:.cpp=.o)))

all: clean dir $(BUILDDIR)/$(EXECUTABLE) 

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(MAIN) -o $@ $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf $(BUILDDIR)/*

