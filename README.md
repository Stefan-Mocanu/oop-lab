Tema acestui proiect este companie aeriana.
In implementare s-au folosit 2 clase:
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

Lista aeroporturilor mentionate:
1. OTP - Otopeni(Bucuresti) Romania
2. TSR - Timisoara Romania
3. BCM - Bacau Romania
4. FCO - Fiumicino(Roma) Italia
5. BGY - Bergamo(Milano) Italia
6. BCN - Barelona Spania 
7. JFK - New York USA 
8. LAX - Los Angeles USA 
9. LTN - Luton(Londra) UK
