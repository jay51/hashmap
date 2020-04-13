
#gcc -I../src/ main.c ../src/map.c 

FLAGS = -I../src/

SRCDIR = ../
OBJECTS := $(shell find  $(SRCDIR) -name "*.c")



#test: main.c ../src/map.c
	#gcc $(FLAGS) main.c ../src/map.c -o test


test: $(OBJECTS) 
	gcc $(FLAGS) $(OBJECTS) -o  test
	
	
clean:
	rm -rf *.o test
