.SUFFIXES:
.PHONY: pc
.PRECIOUS: %_exe

compilador:=g++

pc: prodcons_exe
	./$<

cont: contador_exe
	./$<

fibo: fibonacci_exe
	./$<

co: coste_exe
	./$<

fu: fumadores_exe
	./$<

ex: examenscd_exe
	./$<

%_exe: %.cpp
		$(compilador) -std=c++11 -pthread -o $@ $< Semaphore.cpp 

clean:
	rm -f *_exe
