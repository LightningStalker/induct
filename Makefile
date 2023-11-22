CC = gcc
RM = rm -f
CCFLAGS = -Wall
M = -lm

all: induct

induct:
	$(CC) $(CCFLAGS) -o cap cap.c $(M)
	$(CC) $(CCFLAGS) -o elcut elcut.c
	$(CC) $(CCFLAGS) -o iloc iloc.c $(M)
	$(CC) $(CCFLAGS) -o tankfreq tankfreq.c $(M)

clean:
	$(RM) cap
	$(RM) elcut
	$(RM) iloc
	$(RM) tankfreq

distclean: clean

