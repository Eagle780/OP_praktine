#include "header.h"
#include "funkcijos.h"

int main()
{
    map<string, int> zodziai1;
    map<string, set<int>> zodziai2;
    set<string> domenai, nuorodos;
    skaitytiDomenus("domenai.txt", domenai);
    skaitytiFaila("tekstas.txt", zodziai1, zodziai2, domenai, nuorodos);
    rasytiFaila("ats1.txt", "ats2.txt", zodziai1, zodziai2);
    rasytiLinkus("linkai.txt", nuorodos);

    cout << "Paspauskite \"Enter\", kad iseitumete...";
    cin.get();

    return 0;
}