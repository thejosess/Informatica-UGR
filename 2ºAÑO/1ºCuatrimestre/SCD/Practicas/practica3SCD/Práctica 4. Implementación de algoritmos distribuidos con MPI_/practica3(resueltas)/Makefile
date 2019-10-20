###############################################################################
#
# SCD - Sistemas Concurrentes y Distribuidos
# Grado en Ingeniería Informática
#
# 2014 - Ernesto Serrano <erseco@correo.ugr.es>
# ---------------------------------------------
#
# Fichero Makefile para generacion de ejecutables, paquetes y documentacion
#
###############################################################################

# VARIABLES
BIN 	= bin
SRC 	= src
OBJ 	= obj
LIB 	= lib
INCLUDE = include

# Definición de compiladores
CXX = mpicxx
CC = mpicxx

# banderas para el enlazador
LDFLAGS = -Wall

OBJECTS = p3_ejercicio_01_productor_consumidor p3_ejercicio_02_filosofos p3_ejercicio_03_filosofos_camarero

#OBJECTS = fuma_ex prod-cons-D1-opcionD


# TODO (sin empaquetado)
all: clean $(OBJECTS)


# COMPILACION
$(OBJECTS):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cpp -I$(INCLUDE) $(LDFLAGS)


# DOCUMENTACION
# Genera la documentacion mediante doxygen en la carpeta doc
.PHONY: doc
doc:
	doxygen doc/doxys/Doxyfile

run1: all
	mpirun -np 10 $(BIN)/p3_ejercicio_01_productor_consumidor

run2: all
	mpirun -np 10 $(BIN)/p3_ejercicio_02_filosofos

run3: all
	mpirun -np 11 $(BIN)/p3_ejercicio_03_filosofos_camarero

# EMPAQUETADO
# Genera el archivo .zip de la práctica mediante la linea de comandos
# Omite los archivos propios de MacOSX y coge el nombre del directorio como nombre
.PHONY: package
package: clean
	@echo "Empaquetando..."
	zip $(shell basename "$(CURDIR)")_Ernesto_Serrano.zip -9 -r ./* -x "*.DS_Store" -x "__MACOSX"

# LIMPIEZA
# Limpia los archivos compilados, así como los archivos objeto y los paquetes zip
.PHONY: clean
clean:
	@echo "Limpiando..."
	@rm -f $(OBJ)/*\
        $(BIN)/*\
        ./*.zip
