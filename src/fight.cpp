#include "fight.h"

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
    bool result;
	// TODO: Complete this function and replace return value
    std::ifstream fileRead(fileName);
    std::vector<std::string> heroString;
    //Checking if file is open
    if (fileRead.is_open()) {
        //Reading the file till the end.
        while (!fileRead.eof()) {
            
            std::string inputLine;
            getline(fileRead, inputLine);
            Hero* myHero = new Hero(inputLine);
            heroVector.push_back(myHero);
        }
        fileRead.close();
        result = true;
    }
    else {
        std::cout << "Unable to load file." << std::endl << std::endl;
        result = false;
    }
	return result;
    // Location for the file as input/heroes.txt wasn't working.
    ///Users/trippy/Documents/GitHub/hw02-nishanttrippy/input
}

Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
	// TODO: Complete this function and replace return value.
    //Simply giving the prompt and taking in user input
    int userSelect;
    out << prompt;
    in >> userSelect;
    
    //Converting user input into the selected hero.
    return heroVector[userSelect];
    
}

void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
	// TODO: Complete this function
    //Resetting hero health before they fight
    heroA->resetHealth();
    heroB->resetHealth();
    
    //Initializing fight result to 0
    int fightResult = 0;
    
    //Heroes will fight till one of them reaches 0 health.
    while (heroA->getHealth() != 0 && heroB->getHealth() != 0) {
        output << "---------------------------------------" << std::endl;
        //Printing hero health
        output << heroA->getName() << " has " << heroA->getHealth() << " health" << std::endl;
        output << heroB->getName() << " has " << heroB->getHealth() << " health" << std::endl;
        
        //Hero uses power here
        Power* powA = heroA->useRandomPower();
        Power* powB = heroB->useRandomPower();
        
        //Couting hero's sick moves
        std::cout << heroA->getName() << " " << powA->use() << std::endl;
        std::cout << heroB->getName() << " " << powB->use() << std::endl;
        
        //Storing the result of the fight
        fightResult = powA->fight(powB);
        
        //3 possible scenarios after the conclusion of the fight.
        if (fightResult == 1) {
            heroB->takeDamage();
            std::cout << heroA->getName() << " CRUSHES " << heroB->getName() << " TO INFLICT MASSIVE DAMAGE!" << std::endl;
        }
        else if(fightResult == -1) {
            heroA->takeDamage();
            std::cout << heroB->getName() << " CRUSHES " << heroA->getName() << " TO INFLICT MASSIVE DAMAGE!" << std::endl;
        }
        else {
            heroA->takeDamage();
            heroB->takeDamage();
            std::cout << " IT'S A TIE!, BOTH HIT EACH OTHER WITH EQUAL FORCE" << std::endl;
        }
    }
    output << "---------------------------------------" << std::endl;
    
    //Printing the victorious hero
    if(heroA->getHealth() > 0) {
        output << heroA->getName() << " WINS!!!" << std::endl << std::endl;
    }
    else {
        output << heroB->getName() << " WINS!!!" << std::endl << std::endl;
    }
}

int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
	// TODO: Complete this function and replace return value
    // For Travis to use.
    std::ifstream inputStream(inputFileName);
    std::ofstream outputStream(outputFileName);
    fight(inputStream, outputStream, seed);
    inputStream.close();
    outputStream.close();
	return 0;
}

int fight(std::istream& input, std::ostream& output, unsigned seed)
{
	// TODO: Complete this function
    //Initializing the seed and the other variables needed.
    std::srand(seed);
    std::string userChoice;
    std::vector<Hero*> heroVector;
    
    //Printing Seed
    output << "Seed: " << seed << std::endl << std:: endl;
    
    //Initilizing user input to zero to start menu in a while loop till user decides to quit.
    int userInput = 0;
    while(userInput != 4) {
        
        //Menu of choices
        output << "Choose an option:" << std::endl
               << "1. Load Heroes" << std::endl
               << "2. Print Hero Roster" << std::endl
               << "3. Hero Fight!" << std::endl
               << "4. Quit" << std::endl
               << "> ";
        input >> userInput;
        //Added curly braces after switch blocks as compiler was giving error.
        switch (userInput) {
                
            //Load Heroes
            case 1: {
                output << std::endl << "Enter the file to load: " << std::endl;
                input >> userChoice;
                loadHeroes(userChoice, heroVector);
                break;
            }
                
            //Print Hero Roster
            case 2: {
                output << std::endl << "The following " << heroVector.size() << " heroes are loaded..." << std::endl;
                for(Hero* hero : heroVector) {
                    output << "---------------------------------------" << std::endl;
                    output << (*hero);
                }
                output << "---------------------------------------" << std::endl;
                break;
            }
                
            //Hero Fight!
            case 3: {
                //Printing list of hero names.
                output << std::endl;
                for (int i = 0; i < heroVector.size(); i++) {
                    output << std::to_string(i) + ": " + heroVector[i]->getName() << std::endl;
                }
                Hero* heroA = selectHero(heroVector, "Select your first hero: ", output, input);
                Hero* heroB = selectHero(heroVector, "Select your second hero: ", output, input);
                heroCombat(heroA, heroB, output);
                break;
            }
                
            //Quit
            case 4: {
                output << std::endl << "Goodbye" << std::endl;
                break;
            }
                
            //Error handling
            default: {
                output << "Invalid Input. Please try again!" << std::endl;
                break;
            }
        }
    }
    
	return 0;
}
