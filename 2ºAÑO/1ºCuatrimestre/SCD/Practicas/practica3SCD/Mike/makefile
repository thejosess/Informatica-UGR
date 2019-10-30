.SUFFIXES:
.PHONY:    pcm,pcf,pcl,f,fi,fc,clean

compilador := mpicxx -std=c++11
flagsc     := -g -Wall

pcf: prodcons2-mu-fifo_exe
	mpirun -np  10 ./$<

e2: ejercicio2_exe
	mpirun -np  10 ./$<

e3: ejercicio3_exe
	mpirun -np  10 ./$<

e4: ejercicio4_exe
	mpirun -np  10 ./$<

pcl: prodcons2-mu-lifo_exe
	mpirun -np  10 ./$<

fi: filosofos-interb_exe
	mpirun -np 10 ./$<

f: filosofos_exe
	mpirun -np 10 ./$<

fc: filosofos-cam_exe
	mpirun -np 11 ./$<

%_exe: %.cpp
	$(compilador) $(flagsc) -o $@ $<

clean:
	rm -rf *_exe *.dSYM
