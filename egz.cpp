#include "header.h"
#include "funkcijos.h"

int main()
{
    map<string, int> zodziai1;
    map<string, set<int>> zodziai2;
    skaitytiFaila("test.txt", zodziai1, zodziai2);
    rasytiFaila("ats1.txt", "ats2.txt", zodziai1, zodziai2);

    return 0;
}