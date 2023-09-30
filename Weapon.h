#pragma once
#include <string>

class Weapon
{
private:
	static constexpr int FIRST_LEVEL = 1;
	static constexpr int MAX_LEVEL = 90;
	static constexpr int DEFAULT_WEAPON_DAMAGE = 40;
	static constexpr char DEFAULT_WEAPON_NAME[16] = "Nameless Weapon";
	static constexpr int RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL = 10;

	std::string name;
	int level;
	int damage;

public:
	Weapon(const char name[], int level, int damage);
	Weapon(const char name[]);
	Weapon();

	std::string GetInformation();
	int CalculateResourcesForLevelingUp();
};

Weapon::Weapon(const char name[], int level, int damage)
{
	this->name = name;
	this->level = level;
	this->damage = damage;
}

Weapon::Weapon(const char name[])
{
	this->name = name;
	level = FIRST_LEVEL;
	damage = DEFAULT_WEAPON_DAMAGE;
}

Weapon::Weapon()
{
	this->name = DEFAULT_WEAPON_NAME;
	this->level = FIRST_LEVEL;
	this->damage = DEFAULT_WEAPON_DAMAGE;
}

std::string Weapon::GetInformation()
{
	std::string weaponInformation;
	weaponInformation.append(name).append(" ").append(std::to_string(level)).append(" Lvl. deals ").append(std::to_string(damage)).append(" damage. ");
	return weaponInformation;
}

int Weapon::CalculateResourcesForLevelingUp()
{
	return RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL * (MAX_LEVEL - level);
};