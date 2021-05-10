#include "hero.h"
#include "strlib.h"
#include <iostream>

Hero::Hero(const std::string& heroDef)
{
	// TODO: Complete this function
    //Setting the delimiter to |
    char splitChar = '|';
    
    //Parsing data into a vector
    std::vector<std::string> parsedMemberData = strSplit(heroDef, splitChar);
    
    //Sending parsed data to member variables to create a new hero.
    mName = parsedMemberData[0];
    mMaxHealth = std::stoi(parsedMemberData[2]);
    mHealth = mMaxHealth;
    
    //Setting up a new string to parse for powers.
    std::string parsedPowers = parsedMemberData[1];
    
    //Clearing the vector to add in parsed data back into it
    parsedMemberData.clear();
    
    //Setting the delimiter to ,
    splitChar = ',';
    
    //Parsing data to vector
    parsedMemberData = strSplit(parsedPowers, splitChar);
    
    //Using loop to parse each power into mPowers by running through power factory to convert power string to a power class.
    for(const std::string s : parsedMemberData) {
        mPowers.push_back(powerFactory(s));
    }
}

std::string Hero::getName()
{
	// TODO: Complete this function and replace return value
    //Simple getter
	return mName;
}

Power* Hero::useRandomPower()
{
	// TODO: Complete this function and replace return value
    //Using random to produce numbers between 0 and the number of powers-1
    int randomIndex = rand()%(mPowers.size());
	return mPowers[randomIndex];
}

int Hero::getHealth()
{
	// TODO: Complete this function and replace return value
    //Simple getter
	return mHealth;
}

void Hero::takeDamage()
{
    //Decreasing health by 1
    mHealth -= 1;
}

void Hero::resetHealth()
{
    //Setting health to max health
    mHealth = mMaxHealth;
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;
	
	for (int i = 0; i < h.mPowers.size(); i++)
	{
		std::cout << "\t" << *(h.mPowers[i]) << std::endl;
	}

	return out;
}
