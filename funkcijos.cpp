#include "funkcijos.h"

void skaitytiFaila(string failas, set<string> &zodziai)
{
    cout << "Skaitomas teksto failas..." << endl;
    try
    {
        ifstream fd(failas);
        string eilute;
        string simbolis = ".,/-_!?";

        while (fd)
        {
            getline(fd, eilute);
            istringstream iss(eilute);
            string zodis;

            while (iss >> zodis)
            {
                char raide = zodis.back();
                if (simbolis.find(raide) != string::npos)
                {
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

                zodziai.insert(zodis);
            }
        }
        fd.close();
    }
    catch (ios_base::failure &e)
    {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
}

void rasytiFaila(string failas, set<string> zodziai)
{
    ofstream fr(failas);
    for (auto zodis : zodziai)
    {
        fr << zodis << endl;
    }
    fr.close();
}
