//3/17/2022
//This is a battle royale simulator between 4 creatures
//(human,elf, cyberdemon, and balrog). Each creature receives a base
//strength and hitpoints(health) and enter the battle arena to 
//see who will achieve vitory.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Creature {
protected:
	int type;
	int strength;
	int hitpoints;
	virtual string getSpecies();
public:
	Creature();
	Creature(int newType, int newStrength, int newHit);

	virtual int getDamage() = 0;//allowed main access the derrived functions
	virtual int getHitPoints() = 0;//allowed battleArena access hitpoints
};

//Default Constructor 
Creature::Creature() {
	type = 0;
	strength = 10;
	hitpoints = 10;
}
//Overloaded Constructor
Creature::Creature(int newType, int newStrength, int newHit) {
	type = newType;
	strength = newStrength;
	hitpoints = newHit;
}

//Return the name of the species being called
string Creature::getSpecies() {
	switch (type)
	{
	case 0: return "Human";
	case 1: return "Cyberdemon";
	case 2: return "Balrog";
	case 3: return "Elf";
	}
	return "unknown";
}

void battleArena(Creature& creature1, Creature& creature2);

class Human : public Creature {
public:
	Human(int, int);

	int getDamage() override;
	string getSpecies() override;
	int getHitPoints() override;
};

//Overloaded Constructor
Human::Human(int s, int h) {
	strength = s;
	hitpoints = h;
}

//Return how much human can deal damage on others
int Human::getDamage() {
	int damage;
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;
	return damage;
}

//return the name of the species beign called 
//by accessing the base class function
string Human::getSpecies() {
	return Creature::getSpecies();
}

//return hitpoints from the overloaded constructor
int Human::getHitPoints() {
	return hitpoints;
}

class Elf : public Creature {
public:
	Elf();
	Elf(int, int);

	int getDamage() override;
	string getSpecies() override;
	int getHitPoints() override;
};

//Default constructor
//initialized type elf
Elf::Elf() {
	type = 3;
}

//Overloaded constructor 
Elf::Elf(int s, int h) {
	type = 3;
	strength = s;
	hitpoints = h;
}

//Return how much elf can deal damage on others
int Elf::getDamage() {
	int damage;
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;

	if ((rand() % 10) == 0)
	{
		cout << "Magical attack inflicts " << damage <<
			" additional damage points!" << endl;
		damage = damage * 2;
	}
	return damage;
}

//return the name of the species beign called 
//by accessing the base class function
string Elf::getSpecies() {
	return Creature::getSpecies();
}

//return hitpoints from the overloaded constructor
int Elf::getHitPoints() {
	return hitpoints;
}

class Demon : public Creature {
public:
	int getDamage() override;
	string getSpecies() override;
	int getHitPoints() override;
protected:
	int damage;
};

//Return how much demon can deal damage on others
//Note: Balrog have additonal attributes 
int Demon::getDamage() {
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;

	if ((rand() % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "
			<< " additional damage points!" << endl;
	}
	return damage;
}

//return the name of the species beign called 
//by accessing the base class function
string Demon::getSpecies() {
	return Creature::getSpecies();
}

//return hitpoints from the overloaded constructor
int Demon::getHitPoints() {
	return hitpoints;
}

class Cyberdemon : public Demon {
public:
	Cyberdemon();
	Cyberdemon(int, int);

	int getDamage() override;
	string getSpecies() override;
	int getHitPoints() override;
};

//Default constructor
//initialized type cyberdemon
Cyberdemon::Cyberdemon() {
	type = 1;
}

//Overloaded constructor
Cyberdemon::Cyberdemon(int s, int h) {
	type = 1;
	strength = s;
	hitpoints = h;
}

//Return how much cyberdemon can deal damage on others
//by calling demon base class
int Cyberdemon::getDamage() {
	return Demon::getDamage();
}

//return the name of the species beign called 
//by accessing the demon base class function
string Cyberdemon::getSpecies() {
	return Demon::getSpecies();
}

//return hitpoints from the overloaded constructor
int Cyberdemon::getHitPoints() {
	return hitpoints;
}

class Balrog : public Demon {
public:
	Balrog();
	Balrog(int, int);

	int getDamage() override;
	string getSpecies() override;
	int getHitPoints() override;
};

//Default constructor
//initialized type Balrog
Balrog::Balrog() {
	type = 2;
}

//Overloaded constructor
Balrog::Balrog(int s, int h) {
	type = 2;
	strength = s;
	hitpoints = h;
}

//Return how much balrog can deal damage on others
//with additonal attributes
int Balrog::getDamage() {
	Demon::getDamage();
	int damage2 = (rand() % strength) + 1;
	cout << "Balrog speed attack inflicts " << damage2 <<
		" additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}

//return the name of the species beign called 
//by accessing the demon base class function
string Balrog::getSpecies() {
	return Demon::getSpecies();
}

//return hitpoints from the overloaded constructor
int Balrog::getHitPoints() {
	return hitpoints;
}

int main()
{
	srand(static_cast<int>(time(NULL)));
	Human human1(30, 10);
	human1.getDamage();
	cout << endl;

	Elf elf1;
	elf1.getDamage();
	cout << endl;

	Balrog balrog1(50, 50);;
	balrog1.getDamage();
	cout << endl;

	Cyberdemon cdemon(30, 40);
	cdemon.getDamage();
	cout << endl;

	Elf elf2(50, 50);

	Balrog balrog2(50, 50);
	cout << endl;

	battleArena(elf2, balrog2);
	
}

//Recieve the address of creature1 and creature2
//Function: checks which creature is stronger 
void battleArena(Creature& creature1, Creature& creature2) {

	int c2health = creature2.getHitPoints() - creature1.getDamage();
	cout << "Creature 2 has " << c2health << " points." << endl;

	int c1health =  creature1.getHitPoints() - creature2.getDamage();
	cout << "Creature 1 has " << c1health << " points." << endl;

	cout << endl;

	if (c1health > c2health) {
		cout << "Creature 1 wins!" << endl;
	}
	else if (c2health > c1health) {
		cout << "Creature 2 wins!" << endl;
	}
	else {
		cout << "battle results in a tie!" << endl;
	}
	
}

/*Human attacks for 19 points!

Elf attacks for 3 points!

Balrog attacks for 15 points!
Balrog speed attack inflicts 32 additional damage points!

Cyberdemon attacks for 30 points!


Elf attacks for 39 points!
Creature 2 has 11 points.
Balrog attacks for 23 points!
Balrog speed attack inflicts 18 additional damage points!
Creature 1 has 9 points.

Creature 2 wins!*/