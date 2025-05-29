#include "header.h"
#include "funkcijos.h"

int main()
{
    map<string, int> zodziai;
    skaitytiFaila("test.txt", zodziai);
    rasytiFaila("ats.txt", zodziai);

    return 0;
}