SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
LIB = ./lib
ZIP = ./zip
DAT = ./datos
DOC = ./doc
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

PRJ = practica3


all: $(BIN)/pruebacola_max
# ** Generación de documentación **
doxy: $(DOC)/Doxyfile
	doxygen $(DOC)/Doxyfile

# ** Compilación de módulos **
$(BIN)/pruebacola_max: $(OBJ)/pruebacola_max.o
	$(CXX) -o $(BIN)/pruebacola_max $(OBJ)/pruebacola_max.o -I$(INC)

$(OBJ)/pruebacola_max.o : $(SRC)/pruebacola_max.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp

run: $(BIN)/pruebacola_max
	$(BIN)/pruebacola_max

zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

# ** Limpieza **
clean :
	@echo "Limpiando..."
	-rm $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/html

rmdoxy : clean
	-rm doc/html/*
