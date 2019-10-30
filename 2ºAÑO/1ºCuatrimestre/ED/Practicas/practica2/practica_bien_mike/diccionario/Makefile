SRC = src
INCLUDE = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c

all: $(BIN)/pruebadiccionario

# ************ Compilación de módulos ************
$(OBJ)/termino.o: $(SRC)/Termino.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/termino.o $(SRC)/Termino.cpp -I$(INCLUDE)

$(OBJ)/diccionario.o: $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/diccionario.o $(SRC)/Diccionario.cpp -I$(INCLUDE)

$(OBJ)/pruebadiccionario.o: $(SRC)/Pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pruebadiccionario.o $(SRC)/Pruebadiccionario.cpp -I$(INCLUDE)

$(BIN)/pruebadiccionario: $(OBJ)/termino.o $(OBJ)/diccionario.o $(OBJ)/pruebadiccionario.o 
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/termino.o $(OBJ)/diccionario.o $(OBJ)/pruebadiccionario.o -I$(INCLUDE)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*

