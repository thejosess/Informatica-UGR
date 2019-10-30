SRC = ./src
INC = ./include
OBJ = ./obj
BIN = ./bin
LIB = ./lib
ZIP = ./zip
DAT = ./data
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

PRJ = practicafinal

letras_L: $(BIN)/letras
	$(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras.txt 8 L

letras_P: $(BIN)/letras
	$(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras.txt 8 P

cantidad: $(BIN)/cantidad_letras
	$(BIN)/cantidad_letras $(DAT)/spanish.txt $(DAT)/letras.txt $(DAT)/salida.txt

test: $(BIN)/testlista_palabras
	$(BIN)/testlista_palabras $(DAT)/spanish.txt

# ** Generación de documentación **
doxy:
	doxygen doc/Doxyfile


# ** Compilación de módulos **
$(OBJ)/lista_palabras.o: $(SRC)/lista_palabras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/lista_palabras.o $(SRC)/lista_palabras.cpp -I$(INC)

$(OBJ)/letra.o: $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letra.o $(SRC)/letra.cpp -I$(INC)

$(OBJ)/conjunto_letras.o: $(SRC)/conjunto_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp -I$(INC)

$(OBJ)/bolsa_letras.o: $(SRC)/bolsa_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp -I$(INC)


$(OBJ)/testlista_palabras.o: $(SRC)/testlista_palabras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testlista_palabras.o $(SRC)/testlista_palabras.cpp -I$(INC)

$(OBJ)/letras.o: $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letras.o $(SRC)/letras.cpp -I$(INC)

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp -I$(INC)


$(BIN)/testlista_palabras: $(OBJ)/lista_palabras.o $(OBJ)/conjunto_letras.o $(OBJ)/testlista_palabras.o $(OBJ)/letra.o
	$(CXX) -o $(BIN)/testlista_palabras $(OBJ)/lista_palabras.o $(OBJ)/conjunto_letras.o $(OBJ)/letra.o $(OBJ)/testlista_palabras.o -I$(INC)

$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/lista_palabras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/lista_palabras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o -I$(INC)

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/lista_palabras.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/letra.o $(OBJ)/conjunto_letras.o $(OBJ)/lista_palabras.o -I$(INC)


zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

# ** Limpieza **
clean :
	@echo "Limpiando..."
	-rm $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/html

rmdoxy : clean
	-rm doc/html/*

tar: clean
	tar czvf ../letras.tgz ../letras