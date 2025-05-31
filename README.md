# Objektinio programavimo praktinė užduotis

Ši programa suskaičiuoja, kiek kartų pasikartoja žodžiai, kurie yra "tekstas.txt" faile esančiame tekste. Suskaičiavusi žodžius programa į "ats1.txt" išveda zodžius ir jų pasikartojimų skaičių, o į "ats2.txt" - žodžius su skaičiais, kurie nurodo, kuriose eilutėse buvo rasti žodžiai. Į failus išvedami tik tie žodžiai, kurie tekse pasikartoja daugiau nei vieną kartą.

Programa iš duoto teksto taip pat išrenka ir pateiktus link'us (URL adresus) ir juos išveda į "linkai.txt" failą. Faile "domenai.txt" pateikiami visi galimi domenai, pagal kuriuos ieškomi link'ai. Taip pat tikrinama, ar "žodis" neprasideda 'https://' arba 'http://'.

## Failai

1. egz.cpp - pagrindinis programos paleidimo failas,
2. header.h - egz.cpp header'io failas,
3. funkcijos.cpp - failas, kuriame aprašomos naudojamos funkcijos,
4. funkcijos.h - funkcijos.cpp header'is, kuriame taip pat aprašomi funkcijų prototipai,
5. tekstas.txt - failas, kuriame yra nuskaitomas tekstas,
6. domenai.txt - galimų domenų failas.

## Kaip Paleisti Programą

Klonuokite repozitoriją:

    git clone https://github.com/Eagle780/OP_praktine.git

Aplanke atsidarykite terminalą ir įrašykite:

    mkdir build
    cd build
    cmake ..
    cmake --build . --config Release

Paleidžiamasis failas (Egzaminas.exe) atsiras build/Release aplanke. Į tą patį aplanka reikia nukopijuoti "tekstas.txt" ir "domenai.txt" failus.

Programą taip par galima paleisti per terminalą kitu būdu:

    g++ -O2 -o main egz.cpp funkcijos.cpp
    .\main.exe

Šiuo atveju jokių failų perkopijuoti nereikės, kadangi visi failai but reikiamoje vietoje.

Failai su rezultatais atsiras toje pačioje vietoje, kur yra .exe failas.
