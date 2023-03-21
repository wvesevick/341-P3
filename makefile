blah: main.cpp bitarray.o set.o dictionary.o
	g++ main.cpp bitarray.o set.o dictionary.o -o blah

bitarray.o: bitarray.cpp bitarray.h
	g++ -c bitarray.cpp

dictionary.o: dictionary.cpp dictionary.h
	g++ -c dictionary.cpp

set.o: set.cpp set.h
	g++ -c set.cpp

clean:
	rm -f *.o blah
