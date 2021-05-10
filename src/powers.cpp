#include "powers.h"

#include <iostream>

POWER_ID Power::getID()
{
	// TODO: Complete this function and replace return value
    //Simple getter.
	return mPowerID;
}


/********************************
TODO: CODE FOR EACH POWER GOES HERE
*********************************/
//StrengthPower
StrengthPower::StrengthPower() {
    
    //Initializing member variables.
    mPowerID = POWER_STRENGTH;
    mDescription = "Mega Colossal Biceps";
}

std::string StrengthPower::use() {
    return "sucker punched opponent into space!";
}

int StrengthPower::fight(Power *other) {
    
    //Setting result according to which power this power faces.
    int result;
    if(other->getID() == 0) {
        result = 0;
    }
    else if(other->getID() == 1) {
        result = -1;
    }
    else if(other->getID() == 2) {
        result = 1;
    }
    else if(other->getID() == 3) {
        result = -1;
    }
    else if(other->getID() == 4) {
        result = 1;
    }
    else {
        result = 1;
    }
    return result;
}

//FlightPower
FlightPower::FlightPower() {
    
    //Initializing member variables.
    mPowerID = POWER_FLIGHT;
    mDescription = "Airborne Meteor Smash";
}

std::string FlightPower::use() {
    return "Drop kicked opponent from 30,000 feet in the air!";
}

int FlightPower::fight(Power *other) {
    
    //Setting result according to which power this power faces.
    int result;
    if(other->getID() == 0) {
        result = 1;
    }
    else if(other->getID() == 1) {
        result = 0;
    }
    else if(other->getID() == 2) {
        result = -1;
    }
    else if(other->getID() == 3) {
        result = 1;
    }
    else if(other->getID() == 4) {
        result = -1;
    }
    else {
        result = 1;
    }
    return result;
}

//LaserPower
LaserPower::LaserPower() {
    
    //Initializing member variables.
    mPowerID = POWER_LASER;
    mDescription = "Extremely Powerful Laser";
}

std::string LaserPower::use() {
    return "Burned and Pierced opponent through the laser!";
}

int LaserPower::fight(Power *other) {
    
    //Setting result according to which power this power faces.
    int result;
    if(other->getID() == 0) {
        result = -1;
    }
    else if(other->getID() == 1) {
        result = 1;
    }
    else if(other->getID() == 2) {
        result = 0;
    }
    else if(other->getID() == 3) {
        result = 1;
    }
    else if(other->getID() == 4) {
        result = -1;
    }
    else {
        result = 1;
    }
    return result;
}

//IntelPower
IntelPower::IntelPower() {
    
    //Initializing member variables.
    mPowerID = POWER_INTEL;
    mDescription = "High Intelligence Intel";
}

std::string IntelPower::use() {
    return "Found Weak Spot in opponent and ticked that spot";
}

int IntelPower::fight(Power *other) {
    
    //Setting result according to which power this power faces.
    int result;
    if(other->getID() == 0) {
        result = 1;
    }
    else if(other->getID() == 1) {
        result = -1;
    }
    else if(other->getID() == 2) {
        result = -1;
    }
    else if(other->getID() == 3) {
        result = 0;
    }
    else if(other->getID() == 4) {
        result = 1;
    }
    else {
        result = 1;
    }
    return result;
}

//GadgetPower
GadgetPower::GadgetPower() {
    
    //Initializing member variables.
    mPowerID = POWER_GADGETS;
    mDescription = "Super Duper Expensive Gadget";
}

std::string GadgetPower::use() {
    return "Used gadget to rip opponent to shreds";
}

int GadgetPower::fight(Power *other) {
    
    //Setting result according to which power this power faces.
    int result;
    if(other->getID() == 0) {
        result = -1;
    }
    else if(other->getID() == 1) {
        result = 1;
    }
    else if(other->getID() == 2) {
        result = 1;
    }
    else if(other->getID() == 3) {
        result = -1;
    }
    else if(other->getID() == 4) {
        result = 0;
    }
    else {
        result = 1;
    }
    return result;
}

//NationalPower
NationalPower::NationalPower() {
    
    //Initializing member variables.
    mPowerID = POWER_NATIONAL;
    mDescription = "Patriotism is key";
}

std::string NationalPower::use() {
    return "Screams My Country! My Pride!";
}

int NationalPower::fight(Power *other) {
    
    //Setting result according to which power this power faces.
    int result;
    if(other->getID() == 0) {
        result = -1;
    }
    else if(other->getID() == 1) {
        result = -1;
    }
    else if(other->getID() == 2) {
        result = -1;
    }
    else if(other->getID() == 3) {
        result = -1;
    }
    else if(other->getID() == 4) {
        result = -1;
    }
    else {
        result = 0;
    }
    return result;
}

Power* powerFactory(const std::string& powerName)
{
	// TODO: Complete this function and replace return value
    //Conberting power strings into power classes/objects
    Power* newPower;
    if(powerName == "strength") {
        newPower = new StrengthPower();
    }
    else if(powerName == "flight") {
        newPower = new FlightPower();
    }
    else if(powerName == "laser") {
        newPower = new LaserPower();
    }
    else if(powerName == "intel") {
        newPower = new IntelPower();
    }
    else if(powerName == "gadget") {
        newPower = new GadgetPower();
    }
    else if(powerName == "national") {
        newPower = new NationalPower();
    }

        return newPower;
}

std::ostream& operator<<(std::ostream& out, const Power& p)
{
	out << p.mDescription;
	return out;
}
