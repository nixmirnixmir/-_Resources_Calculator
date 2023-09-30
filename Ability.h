#pragma once
#include <stdlib.h>
#include <time.h>
#include <string>

class Ability
{
private:
	static constexpr int FIRST_LEVEL = 1;
	static constexpr int MAX_LEVEL = 10;
	static constexpr int DEFAULT_DAMAGE = 50;
	static constexpr float DAMAGE_MULTYLPLIER_FOR_LEVELING_UP_SKILL = 0.54;
	static constexpr int MIN_COOLDOWN_IN_SECONDS = 5;
	static constexpr int MAX_COOLDOWN_IN_SECONDS = 15;
	static constexpr int RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL = 3;

	std::string name;
	int level;
	int damage;
	int cooldownInSeconds;

public:
	Ability(const char name[], int level, int damage, int cooldownInSeconds);
	Ability(const char name[]);
	Ability();

	std::string GetInformation();
	int SetRandomCooldownInSeconds();
	int CalculateResourcesForLevelingUpAbility();
};

Ability::Ability(const char name[], int level, int damage, int cooldownInSeconds)
{
	this->name = name;
	this->level = level;
	this->damage = damage;
	this->cooldownInSeconds = cooldownInSeconds;
}

Ability::Ability(const char name[])
{
	this->name = name;
	level = FIRST_LEVEL;
	damage = DEFAULT_DAMAGE;
	cooldownInSeconds = SetRandomCooldownInSeconds();
}

int Ability::SetRandomCooldownInSeconds()
{
	srand(time(NULL));
	return MIN_COOLDOWN_IN_SECONDS + rand() % (MAX_COOLDOWN_IN_SECONDS - MIN_COOLDOWN_IN_SECONDS + 1);
}

Ability::Ability()
{
	level = FIRST_LEVEL;
	damage = DEFAULT_DAMAGE;
	cooldownInSeconds = SetRandomCooldownInSeconds();
}

std::string Ability::GetInformation()
{
	std::string abilityInformation;
	abilityInformation.append(name).append(" ").append(std::to_string(level)).append(" Lvl. deals ").append(std::to_string(damage)).append(" per ").append(std::to_string(cooldownInSeconds)).append(" seconds.");
	return abilityInformation;
}

int Ability::CalculateResourcesForLevelingUpAbility()
{
	return RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL * (MAX_LEVEL - level);
}