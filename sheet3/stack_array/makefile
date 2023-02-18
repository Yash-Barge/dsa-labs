run_stack_array: stack_driver.o stack_array.o
	gcc -o run_stack_array stack_driver.o stack_array.o
	rm -f *.o
	./run_stack_array
stack_driver.o: stack_driver.c stack.h
	gcc -c stack_driver.c
stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c
clean:
	rm -f *.o run_stack_array
