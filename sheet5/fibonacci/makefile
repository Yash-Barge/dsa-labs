fibonacci: driver.o fibonacci.o
	gcc -o fibonacci driver.o fibonacci.o
	rm -f *.o
	./fibonacci
driver.o: driver.c fibonacci.h
	gcc -c driver.c
fibonacci.o: fibonacci.c fibonacci.h
	gcc -c fibonacci.c
