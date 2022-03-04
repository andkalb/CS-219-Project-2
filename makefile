alu: AssemblyTools.h AssemblyTools.o
	g++ -o alu main.cpp AssemblyTools.h AssemblyTools.o

AssemblyTools.o: AssemblyTools.h
	g++ -c AssemblyTools.cpp

clean:
	rm *.o alu