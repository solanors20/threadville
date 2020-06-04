# The Nightmare of Threadville

![alt text](https://media1.tenor.com/images/3d8fc15eb8db50e77d72d45684a31ee0/tenor.gif?itemid=15476610)

1. Descargar GTK con
```bash
sudo apt-get install libgtk-3-dev
```

2. Compilar threadville.c con
```bash
gcc `pkg-config --cflags gtk+-3.0` -o threadville threadville.c `pkg-config --libs gtk+-3.0`
```

3. Ejecutarlo con
```bash
./threadville
```

## Developed by
[Kevin Hernández](https://github.com/kevinah95), [Steven Solano](https://github.com/solanors20), [Elisa Argueta](https://github.com/elisa7143), and [Jose Pablo Araya](https://github.com/arayajosepablo)