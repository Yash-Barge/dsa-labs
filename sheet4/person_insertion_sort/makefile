person_insertion_sort: driver.o insertion_sort.o
	gcc -o person_insertion_sort driver.o insertion_sort.o
	rm -f *.o
	./person_insertion_sort
driver.o: driver.c person.h insertion_sort.h
	gcc -c driver.c
insertion_sort.o: insertion_sort.c person.h insertion_sort.h
	gcc -c insertion_sort.c
