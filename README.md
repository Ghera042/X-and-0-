# X-and-0
Joc de consolă pentru doi jucători, realizat în cadrul lucrării de laborator nr. 1.

# Descrierea proiectului / reguli de joc

Jocul se desfășoară pe o tablă de 3×3 celule între doi jucători: X și 0.

1. Jucătorul X mută primul, apoi jucătorii mută pe rând.
2. La fiecare tură, jucătorul alege o celulă liberă și o marchează cu simbolul său.
3. Câștigă cel care are primul 3 simboluri identice pe un rând, pe o coloană sau pe o diagonală.
4. Dacă toate cele 9 celule sunt ocupate și nimeni nu a câștigat, jocul se termină la egalitate.

# Comenzi

 `restart` (sau `r`) | Începe un joc nou 
 `quit` (sau `q`) | Iese din joc

# Structura proiectului

 `GameEngine.hpp`  Motorul de joc: tabla, tura curentă, validarea mutărilor, determinarea câștigătorului 
 `Renderer.hpp`  Desenatorul: afișează tabla și starea jocului în consolă 
 `Listener.hpp`  Ascultătorul: citește comanda utilizatorului de la tastatură 
 `main.cpp`  Bucla principală care leagă cele trei componente 
