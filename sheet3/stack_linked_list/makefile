run_stack_ll: stack_driver.o stack_ll.o linked_list.o
	gcc -o run_stack_ll stack_driver.o stack_ll.o linked_list.o
	rm -f *.o
	./run_stack_ll
stack_driver.o: stack_driver.c stack.h
	gcc -c stack_driver.c
stack_ll.o: stack_ll.c linked_list.h stack.h
	gcc -c stack_ll.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
clean:
	rm -f *.o run_stack_ll
