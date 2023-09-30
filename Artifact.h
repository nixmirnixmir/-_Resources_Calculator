#pragma once
#include <iostream>
#include <string>

class Artifact
	{
	private:
		static constexpr int FIRST_LEVEL = 0;
		static constexpr int MAX_LEVEL = 20;
		static constexpr char DEFAULT_NAME[18] = "Nameless Artifact";
		static constexpr char DEFAULT_DESCRIPTION[31] = "gives 18% ability damage buff.";
		static constexpr int RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL = 15;

		std::string name;
		int level;
		std::string description;

	public:
		Artifact(const char name[], int level, const char description[]);
		Artifact(const char name[]);
		Artifact();

		std::string GetInformation();
		int CalculateResourcesForLevelingUp();
	};

	Artifact::Artifact(const char name[], int level, const char description[])
	{
		this->name = name;
		this->level = level;
		this->description = description;
	}

	Artifact::Artifact(const char name[])
	{
		this->name = name;
		level = FIRST_LEVEL;
		description = DEFAULT_DESCRIPTION;
	}

	Artifact::Artifact()
	{
		name = DEFAULT_NAME;
		level = FIRST_LEVEL;
		description = DEFAULT_DESCRIPTION;
	}

	std::string Artifact::GetInformation()
	{
		std::string artifactInformation;
		artifactInformation.append(name).append(" ").append(std::to_string(level)).append(" Lvl. ").append(description);
		return artifactInformation;
	}

	int Artifact::CalculateResourcesForLevelingUp()
	{
		return RESOURCES_AMOUNT_FOR_LEVELING_UP_FOR_ONE_LEVEL * (MAX_LEVEL - level);
	}
