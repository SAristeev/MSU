CC = g++
CFLAGS = -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized -fopenmp -O2 -O3 -fno-elide-constructors\
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

prog: main1.o fun.o Makefile
	$(CC) $(CFLAGS) -o prog main1.o fun.o
fun.o: fun.cpp class.h Makefile
	$(CC) $(CFLAGS) -c fun.cpp
main1.o: main1.cpp class.h Makefile
	$(CC) $(CFLAGS) -c main1.cpp
clean:
	rm -f prog main.o fun.o vgcore* out*.txt