# Proiect_snake
1. Arhitectura de date 
Structura hărții: Folosirea unei matrice pătratice drept 
hartă a jocului; Definirea limitelor hărții pentru a verifica 
mai apoi coliziunea cu marginile; 
Structura șarpelui: Folosirea unei structuri formată din 
corp, lungimea curentă a corpului și o variabilă pentru 
direcția actuală (sus, jos, stânga, dreapta); 
Inițializare: La începutul jocului, șarpele trebuie să aibă 
lungimea 1 și să fie plasat în mijlocul hărții; 
Generarea hranei: Apariția aleatorie a hranei și 
asigurarea că aceasta nu apare peste corpul șarpelui; 
Validarea pentru deplasare: Programul refuză mutările 
când se apasă caractere invalide, șarpele continuând să 
meargă în ultima direcție validă; Se verifică ca șarpele să 
nu se întoarcă la 180 de grade. ( daca se deplasează către 
dreapta, tasta A trebuie ignorată); 
Sistemul de culori: Folosirea codurilor ANSI pentru 
aspect; 
2. Interfața vizuală 
Șarpele: va avea culoarea verde; 
Hrana: va avea culoarea roșie; 
Scorul: va avea culoarea galben; 
3. Mecanica jocului 
Logica de creștere: Când coordonatele capului sunt 
aceleași cu ale hranei, atunci lungimea corpului va crește 
cu 1, iar scorul va fi incrementat. 
Auto-coliziune: Verificarea dacă capul a lovit marginea 
sau orice segment al corpului său, ceea ce va duce la 
Game Over.
Modul de a juca: Apeși oricare dintre tastele A,S,D,W, respectiv X(daca se dorește ieșirea din joc); Punctul verde(care reprezintă șarpele), $-reprezintă mâncarea; Rolul acestui joc este ca șarpele să mănânce cât mai mult, fără să se izbească de pereții matricei sau de propriul corp.
