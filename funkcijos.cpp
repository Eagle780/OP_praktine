#include "funkcijos.h"

void skaitytiFaila(string failas, map<string, int> &zodziai1, map<string, set<int>> &zodziai2)
{
    cout << "Skaitomas teksto failas..." << endl;
    try
    {
        ifstream fd(failas);
        string eilute;
        string simbolis = ".,/-_!?%()[]";
        int eile = 0;

        while (getline(fd, eilute))
        {
            istringstream iss(eilute);
            string zodis;
            eile++;

            while (iss >> zodis)
            {
                char raide = zodis.back();
                if (simbolis.find(raide) != string::npos)
                {
                    if (zodis.length() == 2 && raide == '.')
                        continue;
                    zodis.pop_back();
                }
                raide = zodis.front();
                if (simbolis.find(raide) != string::npos)
                {
                    zodis.erase(0, 1);
                }

                transform(zodis.begin(), zodis.end(), zodis.begin(),
                          [](unsigned char s)
                          { return tolower(s); });

                if (!zodis.empty())
                {
                    zodziai1[zodis]++;
                    zodziai2[zodis].insert(eile);
                }
            }
            eilute.clear();
        }
        fd.close();
    }
    catch (ios_base::failure &e)
    {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
}

void rasytiFaila(string failas1, string failas2, map<string, int> zodziai1, map<string, set<int>> zodziai2)
{
    ofstream fr1(failas1);
    for (auto zodis : zodziai1)
    {
        if (zodis.second > 1)
            fr1 << zodis.first << ": " << zodis.second << endl;
    }
    fr1.close();

    ofstream fr2(failas2);
    for (auto zodis : zodziai2)
    {
        if (zodis.second.size() > 1)
        {
            fr2 << zodis.first << ":";
            for (int eile : zodis.second)
            {
                fr2 << " " << eile;
            }
            fr2 << endl;
        }
    }
    fr2.close();
}
