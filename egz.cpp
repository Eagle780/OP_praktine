#include "header.h"
#include "funkcijos.h"

int main()
{
    set<string> zodziai;
    skaitytiFaila("test.txt", zodziai);
    rasytiFaila("ats.txt", zodziai);

    return 0;
}