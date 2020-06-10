CC = gcc
INCDIR = -Iinclude
LIBDIR = -Llib -Wl,-rpath,lib

CFLAGS += -O2 -Wall -std=c11

LDFLAGS += -lraylib

ODIR=target

.PHONY: all clean

all: $(ODIR)
	$(CC) src/main.c -o  $(ODIR)/main $(CFLAGS) $(INCDIR) $(LIBDIR) $(LDFLAGS)

$(ODIR):
	mkdir target/

clean:
	rm -rf target
