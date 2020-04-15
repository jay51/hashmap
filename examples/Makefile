INCLUDE = -I../src/
FLAGS = -g -Wall
SRCDIR = ../
OBJECTS := $(shell find  $(SRCDIR) -name "*.c")


test: $(OBJECTS) 
	gcc $(INCLUDE) $(FLAGS) $(OBJECTS) -o  test
	
	
clean:
	rm -rf *.o test
