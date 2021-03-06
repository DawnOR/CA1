CFLAGS	= -c -Wall
CC	= gcc
DISTDIR = dist
LIBDIR  = lib
OBJECTS = $(DISTDIR)/simulate.o\
	  $(DISTDIR)/my-functions.o

link: $(OBJECTS) 
	$(CC) $? -o $(DISTDIR)/simulate

$(DISTDIR)/simulate.o: simulate.c
	$(CC) $(CFLAGS) $? -o $(DISTDIR)/simulate.o

$(DISTDIR)/my-functions.o:$(DISTDIR)/my-functions.c
	$(CC) $(CFLAGS) $? -o $(DISTDIR)/my-functions.o

clean:
	rm -rf ./dist && mkdir ./dist
