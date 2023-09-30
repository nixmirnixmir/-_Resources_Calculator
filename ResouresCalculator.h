#pragma once
#include <string>
#include "Character.h"

class ResourcesCalculatorForLevelingUpCharacters
{
public:
	ResourcesCalculatorForLevelingUpCharacters();

	void CalculateResorces(Character character);
};

ResourcesCalculatorForLevelingUpCharacters::ResourcesCalculatorForLevelingUpCharacters()
{

}


void ResourcesCalculatorForLevelingUpCharacters::CalculateResorces(Character character)
{
	std::cout << "You need " << character.CalculateResourcesForLevelingUp() << " Wanderer's Advice, "
		<< character.getWeapon().CalculateResourcesForLevelingUp() << " Enhancement Ores, "
		<< character.getArtifact().CalculateResourcesForLevelingUp() << " Sanctifying Unctions and "
		<< character.getAbility().CalculateResourcesForLevelingUpAbility() << " Teachings of Freedom." << std::endl;
}



