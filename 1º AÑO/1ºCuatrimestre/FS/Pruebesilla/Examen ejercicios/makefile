#Nombre archivo: makefile

#Uso: make -f makefile



CC=g++


Include_Dir=~/Escritorio/Home/includes


Archivos_Fuentes=main.cpp suma.cpp resta.cpp


Modulos_Objetos=$(Archivos_Fuentes:.cpp=.o)


Ejecutable=serie


all: $(Modulos_Objetos) $(Ejecutable)


$(Ejecutable): $(Modulos_Objetos)


$(CC) -I$(Include_Dir) $^ -o $@

