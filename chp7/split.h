#pragma once
#ifndef GUARD_split.h
#define GUARD_split.h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

 bool space(char);
 bool not_space(char);
 vector<string> split(const string& str);
#endif