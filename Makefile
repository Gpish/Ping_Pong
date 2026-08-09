CXX = clang++
CXXFLAGS = -std=c++17

CC = clang

TARGET = build/pingpong

CPP_SOURCES = \
	src/game.cpp \
	$(wildcard src/dataloaders/*.cpp) \
	$(wildcard src/buffers/*.cpp) \
	$(wildcard src/shaders/*.cpp) \
	$(wildcard src/renderers/*.cpp) \
	$(wildcard src/transformations/*.cpp) \
	$(wildcard src/inputHandlers/*.cpp) \
	$(wildcard src/logger/*.cpp) \
	$(wildcard src/gameObjects/*.cpp)

C_SOURCES = src/glad.c

# CPP_TESTS = $(wildcard tests/dataloaders/*.cpp)

CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)
C_OBJECTS = $(C_SOURCES:.c=.o)
# CPP_TESTS_OBJECTS = $(CPP_TESTS:.cpp=.o)

OBJECTS = $(CPP_OBJECTS) $(C_OBJECTS)

FRAMEWORKS = \
	-framework OpenGL \
	-framework Cocoa \
	-framework IOKit

LIBS = \
	-lglfw3

INCLUDES = \
	-I/Users/IGupta/playground/Games/PingPong/include/

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LIBS) $(FRAMEWORKS) $(INCLUDES) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

run : all
	./$(TARGET)

clean :
	rm -f src/*.o \
		  src/dataloaders/*.o \
		  src/buffers/*.o \
		  src/shaders/*.o \
		  src/renderers/*.o \
		  src/transformations/*.o \
		  src/inputHandlers/*.o \
		  src/logger/*.o \
		  src/gameObjects/*.o \
		  log.txt

	rm -rf build

# test : 

# showSources:
# 	echo $(CPP_SOURCES)
# 	echo $(FRAMEWORKS)
# 	echo $(INCLUDES)
# 	echo game