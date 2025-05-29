#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cctype>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios_base;
using std::istringstream;
using std::map;
using std::ofstream;
using std::set;
using std::string;
using std::tolower;
using std::transform;

void skaitytiFaila(string failas, map<string, int> &zodziai1, map<string, set<int>> &zodziai2);
void rasytiFaila(string failas1, string failas2, map<string, int> zodziai1, map<string, set<int>> zodziai2);