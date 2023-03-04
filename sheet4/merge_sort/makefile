merge_sort: main.o merge_sort.o
	gcc -o merge_sort main.o merge_sort.o
	rm -f *.o
	./merge_sort
main.o: main.c merge_sort.h
	gcc -c main.c
merge_sort.o: merge_sort.c merge_sort.h
	gcc -c merge_sort.c
clean:
	rm -f *.o merge_sort