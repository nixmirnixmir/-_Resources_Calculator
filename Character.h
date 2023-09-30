#pragma once
#include <string>
#include "Weapon.h"
#include "Ability.h"
#include "Artifact.h"

class Character
{
private:
	static constexpr int FIRST_LEVEL = 1;
	static constexpr int MAX_LEVEL = 90;
	static constexpr char DEFAULT_NAME[16] = "Nameless Person";
	static constexpr int RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL = 5;

	std::string name;
	int level;
	Weapon weapon;
	Artifact artifact;
	Ability ability;

public:
	Character(const char name[], int level, Weapon weapon, Artifact artifact, Ability ability);
	Character(const char name[]);
	Character();

	Weapon getWeapon();
	Artifact getArtifact();
	Ability getAbility();

	void PrintInformation();
	int CalculateResourcesForLevelingUp();
};

Character::Character(const char name[], int level, Weapon weapon, Artifact artifact, Ability ability)
{
	this->name = name;
	this->level = level;
	this->weapon = weapon;
	this->artifact = artifact;
	this->ability = ability;
}

Character::Character(const char name[])
{
	this->name = name;
	level = FIRST_LEVEL;

	Weapon weapon;
	weapon = weapon;

	Artifact artifact;
	artifact = artifact;

	Ability ability;
	ability = ability;
}

Character::Character()
{
	this->name = DEFAULT_NAME;
	this->level = FIRST_LEVEL;

	Weapon weapon;
	weapon = weapon;

	Artifact artifact;
	artifact = artifact;

	Ability ability;
	ability = ability;
}

Weapon Character::getWeapon() { return weapon; }

Artifact Character::getArtifact() { return artifact; }

Ability Character::getAbility() { return ability; }

void Character::PrintInformation()
{
	std::cout << name << " " << level << "  Lvl. " << weapon.GetInformation() << " "
		<< artifact.GetInformation() << " " << ability.GetInformation() << std::endl;
}

int Character::CalculateResourcesForLevelingUp()
{
	return RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL * (MAX_LEVEL - level);
}
