.SUFFIXES:
.PHONY: x1, x2, clean

compilador:=g++
opcionesc:= -std=c++11 -pthread -Wfatal-errors
hmonsrcs:= HoareMonitor.h HoareMonitor.cpp Semaphore.h Semaphore.cpp

vlifo: varios_lifo_su_exe
	./$<

vfifo: varios_fifo_su_exe
	./$<

fumadores: fumadores_su_exe
	./$<

barberia: barberia_su_exe
	./$<

varios_lifo_su_exe: varios_lifo_su.cpp $(hmonsrcs)
	$(compilador) $(opcionesc) -o $@ $< HoareMonitor.cpp Semaphore.cpp

varios_fifo_su_exe: varios_fifo_su.cpp $(hmonsrcs)
	$(compilador) $(opcionesc) -o $@ $< HoareMonitor.cpp Semaphore.cpp

fumadores_su_exe: fumadores_su.cpp $(hmonsrcs)
	$(compilador) $(opcionesc)  -o $@ $< HoareMonitor.cpp Semaphore.cpp

barberia_su_exe: barberia_su.cpp $(hmonsrcs)
	$(compilador) $(opcionesc)  -o $@ $< HoareMonitor.cpp Semaphore.cpp

clean:
	rm -f *_exe
