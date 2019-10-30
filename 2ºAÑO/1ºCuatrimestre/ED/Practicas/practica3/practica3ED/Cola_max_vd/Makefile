SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
LIB = ./lib
ZIP = ./zip
DAT = ./datos
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

PRJ = practica3


all: $(BIN)/pruebacola_max
# ** Generación de documentación **
doxy:
	doxygen doc/Doxyfile

# ** Compilación de módulos **
$(BIN)/pruebacola_max: $(OBJ)/pruebacola_max.o $(OBJ)/Cola_max_vd.o
	$(CXX) -o $(BIN)/pruebacola_max $(OBJ)/Cola_max_vd.o $(OBJ)/pruebacola_max.o  -I$(INC)

$(OBJ)/Cola_max_vd.o : $(SRC)/Cola_max_vd.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Cola_max_vd.o $(SRC)/Cola_max_vd.cpp -I$(INC)

$(OBJ)/pruebacola_max.o : $(SRC)/pruebacola_max.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebacola_max.o $(SRC)/pruebacola_max.cpp -I$(INC)

zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

# ** Limpieza **
clean :
	@echo "Limpiando..."
	-rm $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/html

rmdoxy : clean
	-rm doc/html/*
