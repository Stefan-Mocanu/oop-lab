Tema acestui proiect este companie aeriana.
In implementare s-au folosit mai multe clase:
1. Avioane are ca membri
    - inmatriculare care retine nr. de inmatriculare a unui avion. Atat in realitate, cat si in proiect nr. de inmatriculare este de forma "COD-XXX". COD reprezinta codul tarii de origine.(Codul Romaniei este YR). XXX reprezinta 3 litere majuscule care identifica avionul.
    - modelul avionului
    - distanta maxima pe care o poate pargurge avionul cu kerosenul din rezervorul plin
    - consumul la 100 de km in litri de kerosen
2. Zboruri are ca membri
    - plecare
    - destinatie
    - (membrii de mai sus contin codul in formatul IATA(3 litere distinctive pt fiecare aeroport civil din lume) al aeroportului de plecare/destinatie)
    - distanta dintre cele 2 aeroporturi in kilometri
3. Personal, clasa virtuala pura care are ca membrii:
    - cod_angajat
    - nume
    - prenume
4. Personal navigant, mostenita din Personal, care are ca membrii:
    - un vector care retine modelele de avioane pe care angajatul poate zbura
    - job
5. Personal nenavigant, mostenita din Personal, care are ca membrii:
    - aeroport de baza
    - job
6. Nu exista si Input invalid:
    - clase mostenite din std::exception si au ca scop semnalarea problemor de input
7. Meniu
    - are doar functii statice 
In fisierul tastatura.txt se afla urmatoarele comenzi:
1. Afisarea tuturor avioanelor inregistrate
2. Operatia de stergere a avionului cu nr. de inmatriculare YR-MIZ din flota
3. Afisarea tuturor avioanelor inregistrate(fara YR-MIZ)
4. Verificarea avioanelor car pot circula pe ruta BCN JFK (nici un avion nu poate circula)
5. Introducerea a 2 avioane in flota
6. Verificarea avioanelor car pot circula pe ruta BCN(Barcelona) JFK(New York) (YR-RIC introdus la 6 poate cirucula)
7. Afisarea tuturor rutelor disponibile
8. Introducerea rutei OTP TSR
9. Verificare rutelor disponibile pt avionul YR-MIV
10. Stergerea rutei OTP BCM
11. Verificare rutelor disponibile pt avionul YR-MIV(fara OTP BCM)
12. Afisarea intregului personal
13. Verificarea personalului care poate circula pe YR-RIC (niciunul)
14. Adaugarea a 4 membrii de personal
15. Afisarea intregului personal
16. Verificarea personalului care poate circula pe YR-RIC (3 rezultate, introduse anterior)
17. Verificarea personalului nenavigant care are baza la OTP
18. Eliminarea angajatului 114
19. Verificarea personalului nenavigant care are baza la OTP(fara 114)
20. Verificarea avioanelor pe care poate circula 102
21. Verificarea rutelor care ating aeroportul de baza al angajatului 113

Lista aeroporturilor mentionate:
1. OTP - Otopeni(Bucuresti) Romania
2. TSR - Timisoara Romania
3. BCM - Bacau Romania
4. FCO - Fiumicino(Roma) Italia
5. BGY - Bergamo(Milano) Italia
6. BCN - Barcelona Spania 
7. JFK - New York USA 
8. LAX - Los Angeles USA 
9. LTN - Luton(Londra) UK
