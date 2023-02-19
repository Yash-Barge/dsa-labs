insertion_sort: driver.o insertion_sort.o
	gcc -o insertion_sort driver.o insertion_sort.o
	rm -f *.o
	./insertion_sort
driver.o: driver.c insertion_sort.h
	gcc -c driver.c
insertion_sort.o: insertion_sort.c insertion_sort.h
	gcc -c insertion_sort.c
