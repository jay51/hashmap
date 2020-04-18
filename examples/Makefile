INCLUDE = -I../src/
FLAGS = -g -Wall
SRCDIR = ../
OBJECTS := $(shell find  $(SRCDIR) -name "*.c")


test: $(OBJECTS)
	gcc $(INCLUDE) $(FLAGS) $(OBJECTS) -o  test && bash -c "./test"
	
	
clean:
	rm -rf *.o test
