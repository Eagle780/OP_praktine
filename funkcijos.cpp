#include "funkcijos.h"

void skaitytiFaila(string failas, map<string, int> &zodziai1, map<string, set<int>> &zodziai2, set<string> domenai, set<string> &nuorodos)
{
    cout << "Skaitomas teksto failas..." << endl;
    try
    {
        ifstream fd(failas);
        string eilute;
        string simbolis = ".,-_!?%()[]–—";
        int eile = 0;

        map<string, string> lietuviskosMazosios = {
            {"Ą", "ą"},
            {"Č", "č"},
            {"Ę", "ę"},
            {"Ė", "ė"},
            {"Į", "į"},
            {"Š", "š"},
            {"Ų", "ų"},
            {"Ū", "ū"},
            {"Ž", "ž"},
        };

        while (getline(fd, eilute))
        {
            istringstream iss(eilute);
            string zodis;
            eile++;

            while (iss >> zodis)
            {
                zodis = salintiPaskutine(zodis, simbolis);
                zodis = salintiPirma(zodis, simbolis);
                if (zodis == "")
                    continue;
                if (zodis.substr(0, 7) == "http://" || zodis.substr(0, 8) == "https://")
                {
                    nuorodos.insert(zodis);
                    continue;
                }
                for (const string &dom : domenai)
                {

                    if (zodis.size() >= dom.size())
                    {
                        if (zodis.substr(zodis.size() - dom.size()) == dom)
                        {
                            nuorodos.insert(zodis);
                            continue;
                        }
                    }
                }

                if (arSkaicius(zodis))
                    continue;

                zodis = mazosiosRaides(zodis, lietuviskosMazosios);

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

void skaitytiDomenus(string failas, set<string> &domenai)
{
    cout << "Skaitomas domenu failas..." << endl;
    try
    {
        ifstream fd(failas);
        string dom;

        while (fd >> dom)
        {
            dom = "." + dom;
            domenai.insert(dom);
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

void rasytiLinkus(string failas, set<string> nuorodos)
{
    ofstream fr(failas);
    for (string linkas : nuorodos)
    {
        fr << linkas << endl;
    }
    fr.close();
}

string salintiPaskutine(string &zodis, string sim)
{
    char raide = zodis.back();
    if (sim.find(raide) != string::npos)
    {
        if (zodis.length() <= 2 && raide == '.')
        {
            zodis = "";
            return zodis;
        }
        zodis.pop_back();
        salintiPaskutine(zodis, sim);
    }
    return zodis;
}

string salintiPirma(string &zodis, string sim)
{
    char raide = zodis.front();
    if (sim.find(raide) != string::npos)
    {
        zodis.erase(0, 1);
        salintiPirma(zodis, sim);
    }
    return zodis;
}

bool arSkaicius(string zodis)
{
    istringstream iss(zodis);
    double d;
    char c;
    return (iss >> d) && !(iss >> c);
}

string mazosiosRaides(const string &zodis, map<string, string> &lietuviskosMazosios)
{
    string zodisMaz;
    for (int i = 0; i < zodis.size();)
    {
        unsigned char r = zodis[i];
        int raides_ilgis = 1;

        if ((r & 0xE0) == 0xC0)
            raides_ilgis = 2;
        else if ((r & 0xF0) == 0xE0)
            raides_ilgis = 3;
        else if ((r & 0xF8) == 0xF0)
            raides_ilgis = 4;

        string utf8_raide = zodis.substr(i, raides_ilgis);
        if (lietuviskosMazosios.count(utf8_raide))
            zodisMaz += lietuviskosMazosios[utf8_raide];
        else
            zodisMaz += utf8_raide;

        i += raides_ilgis;
    }

    return zodisMaz;
}