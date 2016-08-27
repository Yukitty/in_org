CC=gcc
RES=windres
CFLAGS= -Wall -Wextra -O2
LFLAGS= -shared -s
OBJECTS= in_org.o in_org-res.o

in_org.dll: $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $(OBJECTS)

%.o: %.c $(wildcard *.inc)
	$(CC) -c -o $@ $< $(CFLAGS)

in_org-res.o: in_org.rc in_org.h
	$(RES) $< $@

