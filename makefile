#-- program name, sources and obj --
TARGET=Pong
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)

ifeq (${OS}, Windows_NT)
	#SFMLDIR=./SFML_Windows_x64
	SFMLDIR=./SFML_Windows_Sources
	DEL=del src\*.o $(TARGET)
else
	#SFMLDIR=./SFML_GNU_Linux
	DEL_ARGS=rm -f $(OBJ) $(TARGET) src/*~ include/*~ *~
endif

#-- compiler/linker settings --
CXX=g++
CXXFLAGS=-W -Wall -Wno-long-long -pedantic #-g #-std=c++11
IFLAGS=-I$(SFMLDIR)/include -I./include
LDFLAGS=-L$(SFMLDIR)/lib -Wl,-rpath,${SFMLDIR}/lib -lsfml-graphics -lsfml-window -lsfml-system

#-- main target to obtain --
all : $(TARGET)

#-- linker command to produce the executable file --
$(TARGET) : $(OBJ)
	@echo Linking $@ ...
	$(CXX) $^ -o $@ $(LDFLAGS) 
	@echo

#-- source file header files dependencies --
src/Appli.o : include/Window.h include/Rectangle.h include/Circle.h include/Color.h
src/Color.o :
src/Shape.o : include/Color.h
src/Circle.o: include/Color.h include/Shape.h
src/Rectangle.o: include/Color.h include/Shape.h
src/Triangle.o: include/Color.h include/Shape.h
src/Pong.o : include/Color.h include/Circle.h include/Rectangle.h include/Shape.h
src/Window.o: include/Window.h include/Color.h include/Circle.h include/Rectangle.h


#-- compiler command for every source file --
%.o : %.cpp 
	@echo Compiling $< ....
	$(CXX) -c $< $(IFLAGS) -o $@ $(CXXFLAGS) 
	@echo

.PHONY: clean

#-- system-specific command to remove those files --
clean :
	@echo Cleaning...
	$(DEL)
	@echo

run :
	./$(TARGET)