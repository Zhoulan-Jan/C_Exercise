.PHONY:all
all:day_first simple

day_first:day_first.c
	gcc -o day_first day_first.c

simple:simple.c
	gcc -o simple simple.c

.PHONY:clean  
clean:
	rm -f day_first simple 
