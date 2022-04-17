CC=gcc

SRCDIR=src
INCLDIR=include

all:
	make monkey
	make controller
	

controller: $(SRCDIR)/controller.c controller 
	$(CC) -I$(INCLDIR) $(SRCDIR)/controller.c  -o controller

monkey: $(SRCDIR)/monkey.c monkey 
	$(CC) -I$(INCLDIR) $(SRCDIR)/monkey.c  -o monkey
	
clean:
	rm controller
	rm monkey

remove_output:
	rm -rf output
	
run:
	./controller
	
	