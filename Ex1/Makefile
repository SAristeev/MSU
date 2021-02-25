prog: main1.o fun.o malloc.o Makefile
	g++ -o prog main1.o fun.o malloc.o
main1.o: main1.cpp class.h walloc.h Makefile
	g++ -c -std=c++11 -fno-elide-constructors main1.cpp
fun.o: fun.cpp class.h walloc.h Makefile
	g++ -c -std=c++11 -fno-elide-constructors fun.cpp
malloc.o: malloc.cpp class.h walloc.h Makefile
	g++ -c -std=c++11 -fno-elide-constructors malloc.cpp
clean:
	rm prog main1.o class.o malloc.o
