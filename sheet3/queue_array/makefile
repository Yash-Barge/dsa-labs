stack_array: driver.o queue_array.o
	gcc -o stack_array driver.o queue_array.o
	rm -f *.o
	./stack_array
driver.o: driver.c queue.h
	gcc -c driver.c
queue_array.o: queue_array.c queue.h
	gcc -c queue_array.c
