# Makefile para el programa rastreador. Cuando se ejecuta el commando 'make' se compila y se crea el ejecutable.
# La carpeta 'target/' va a servir como punto en donde se van a dejar los archivos resultantes del proceso
# de compilacion

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
EXECUTABLE=threadville
ODIR=target
#CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -fPIC $(OPTFLAGS)
LDFLAGS='-export-dynamic'


all: clean $(EXECUTABLE)

build:
	$(CC) -c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` $(SOURCES) 
	mv *.o src/ 

$(EXECUTABLE): $(ODIR) build
	$(CC) $(OBJECTS) -o $(ODIR)/$(EXECUTABLE) -Wl,--export-dynamic `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -pthread

$(ODIR):
	mkdir target/

clean:
	rm -f $(OBJECTS)  
	rm -rf target/


