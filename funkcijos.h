#pragma once

#include <iostream>
#include <fstream>
#include <string>
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
using std::ofstream;
using std::set;
using std::string;
using std::tolower;
using std::transform;

void skaitytiFaila(string failas, set<string> &zodziai);
void rasytiFaila(string failas, set<string> zodziai);