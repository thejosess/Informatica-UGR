SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
LIB = ./lib
ZIP = ./zip
DAT = ./datos
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

PRJ = practica2


all: $(BIN)/pruebadiccionario
	$(BIN)/pruebadiccionario $(DAT)/diccionario.txt

short: $(BIN)/pruebadiccionario
	$(BIN)/pruebadiccionario $(DAT)/diccionario2.txt

# ** Generación de documentación **
doxy:
	doxygen doc/Doxyfile


# ** Compilación de módulos **
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(LIB)/libdiccionario.a
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o -I$(INC) -L$(LIB) -ldiccionario

$(LIB)/libdiccionario.a : $(OBJ)/Termino.o $(OBJ)/Diccionario.o
	ar rvs $(LIB)/libdiccionario.a $(OBJ)/Termino.o $(OBJ)/Diccionario.o

$(OBJ)/Termino.o : $(SRC)/Termino.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INC)

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INC)

zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

# ** Limpieza **
clean :
	@echo "Limpiando..."
	-rm $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/html

rmdoxy : clean
	-rm doc/html/*