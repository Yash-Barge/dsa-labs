queue_linked_list: driver.o queue_ll.o linked_list.o
	gcc -o queue_linked_list driver.o queue_ll.o linked_list.o
	rm -f *.o
	./queue_linked_list
driver.o: driver.c queue.h
	gcc -c driver.c
queue_ll.o: queue_ll.c queue.h linked_list.h
	gcc -c queue_ll.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
