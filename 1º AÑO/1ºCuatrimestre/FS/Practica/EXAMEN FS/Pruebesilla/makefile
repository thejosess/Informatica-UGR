EXE=serie

CC=g++

source=main.cpp resta.cpp suma.cpp
objects=$(source:.cpp=.o)

dir_cab=./includes


$(EXE): $(objects)
	$(CC) -o $@ $^
    
main.o: main.cpp $(dir_cab)/funciones.h
	$(CC) -I$(dir_cab) -c $<

suma.o: suma.cpp $(dir_cab)/funciones.h
	$(CC) -I$(dir_cab) -c $<

resta.o: resta.cpp $(dir_cab)/funciones.h
	$(CC) -I$(dir_cab) -c $<
