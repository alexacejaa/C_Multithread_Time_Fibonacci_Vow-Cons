###########################################################
#
# Simple Makefile for Operating Systems Project 3
# Alexa Ceja
#
###########################################################
.SUFFIXES: .c .o

all: project3a project3b project3c

project3a: project3a.c
	gcc project3a.c -o proj3a -lpthread

project3b: project3b.c
	gcc -std=c99 project3b.c -o proj3b -lpthread 

project3c: project3c.c
	gcc -std=c99 project3c.c -o proj3c -lpthread

clean: 
	/bin/rm -f *.o *~ core project3


