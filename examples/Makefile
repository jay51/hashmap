
#gcc -I../src/ main.c ../src/map.c 

INCLUDE = -I../src/
FLAGS = -g -Wall
SRCDIR = ../
OBJECTS := $(shell find  $(SRCDIR) -name "*.c")



#test: main.c ../src/map.c
	#gcc $(FLAGS) main.c ../src/map.c -o test


test: $(OBJECTS) 
	gcc $(INCLUDE) $(FLAGS) $(OBJECTS) -o  test
	
	
clean:
	rm -rf *.o test
