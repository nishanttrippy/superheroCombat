#include "strlib.h"
#include <sstream>


std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	// TODO: Complete this function and fix the return;
    std::vector<std::string> result;
    std::string separatedWord;
    std::istringstream input(str);
    while(getline(input, separatedWord, splitChar)) {
        result.push_back(separatedWord);
    }

	return result;
}

