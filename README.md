# X si 0 (Tic-Tac-Toe)

Joc X si 0 in consola, scris in C++.

## Structura proiectului

- `GameEngine` - logica jocului (tabla, mutari, castigator)
- `Listener` - citeste comenzile de la tastatura
- `Renderer` - afiseaza tabla si mesajele
- `main.cpp` - bucla principala

Fiecare clasa are un fisier `.hpp` (declaratii) si un fisier `.cpp` (implementari).

## Constructie

Cu Makefile:

```
make
./tictactoe
```

Curatare (sterge fisierele obiect si executabilul):

```
make clean
```

Manual, din linia de comanda:

```
g++ -c GameEngine.cpp              
g++ main.cpp GameEngine.cpp Listener.cpp Renderer.cpp -o tictactoe
```

## Comenzi in joc

- `rand coloana` (ex: `2 3`) - pune simbolul pe pozitia respectiva
- `r` - restart
- `q` - iesire
