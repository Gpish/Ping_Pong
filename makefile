#compiler
CXX = g++

#libraries
LD = -lglfw3

#includes
INC = -I/Users/IGupta/playground/Includes/GLM

#frameworks
LF = -framework Cocoa -framework IOKit -framework OpenGL

#all object files
objects = App.o shader.o buffer.o window.o config.o game.o paddle.o

#main App
app = App

#final executable file
EXE = exec

$(EXE): $(objects)
	$(CXX) -v $(objects) -o $(EXE) $(INC) $(LD) $(LF)

$(app).o: $(app).cpp
	$(CXX) -c $(app).cpp

config.o: ./Sources/config.cpp
	$(CXX) -c ./Sources/config.cpp

window.o: ./Sources/window.cpp
	$(CXX) -c ./Sources/window.cpp

buffer.o: ./Sources/buffer.cpp
	$(CXX) -c ./Sources/buffer.cpp

shader.o: ./Sources/shader.cpp
	$(CXX) -c ./Sources/shader.cpp

game.o: ./Sources/game.cpp
	$(CXX) -c ./Sources/game.cpp

paddle.o: ./Sources/paddle.cpp
	$(CXX) -c ./Sources/paddle.cpp

clean:
	rm $(objects)
