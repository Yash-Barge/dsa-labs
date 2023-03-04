count_sort: main.o count_sort.o
	gcc -o count_sort main.o count_sort.o
	rm -f *.o
	./count_sort
main.o: main.c count_sort.h
	gcc -c main.c
count_sort.o: count_sort.c count_sort.h
	gcc -c count_sort.c
clean:
	rm -f *.o count_sort
