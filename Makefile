# Makefile para el programa rastreador. Cuando se ejecuta el commando 'make' se compila y se crea el ejecutable.
# La carpeta 'target/' va a servir como punto en donde se van a dejar los archivos resultantes del proceso
# de compilacion

COMPRESS_FILENAME=Araya-Argueta-Hernandez-Solano.tgz

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

EXECUTABLE=threadville

ODIR=target
CFLAGS= `pkg-config --cflags gtk+-3.0`
LDFLAGS= -Wl,--export-dynamic `pkg-config --libs gtk+-3.0` -pthread


all: clean $(EXECUTABLE)

build:
	$(CC) -c $(CFLAGS) $(SOURCES) $(LDFLAGS)
	mv *.o src/ 

$(EXECUTABLE): $(ODIR) build
	$(CC) $(OBJECTS) $(CFLAGS) -o $(ODIR)/$(EXECUTABLE) $(LDFLAGS)

$(ODIR):
	mkdir target/

clean:
	rm -f $(OBJECTS)  
	rm -rf target/
	rm -f $(COMPRESS_FILENAME)

compress:
	git archive -o $(COMPRESS_FILENAME) HEAD
