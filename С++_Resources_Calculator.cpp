#include <iostream>
#include <string.h>

#include "Character.h"
#include "Ability.h"
#include "Artifact.h"
#include "Weapon.h"
#include "ResouresCalculator.h"

int main()
{
    Weapon lightOfFoliarIncision("Light of Foliar Incision", 1, 44);
    Weapon amosBow("Amos' Bow", 1, 46);
    Weapon kitainCrossSpear("Kitain Cross Spear", 1, 46);
    Weapon magicGuide("Magic Guide", 1, 38);

    Weapon* dynamicArrayOfWeapons = new Weapon[4];
    dynamicArrayOfWeapons[0] = lightOfFoliarIncision;
    dynamicArrayOfWeapons[1] = amosBow;
    dynamicArrayOfWeapons[2] = kitainCrossSpear;
    dynamicArrayOfWeapons[3] = magicGuide;

    delete[] dynamicArrayOfWeapons;

    Artifact* oneArtifact = new Artifact("Emblem of Severed Fate", 5, "increases Elemental Burst DMG by 25% of Energy Recharge");
    Artifact* anotherOneArtafact = new Artifact("Gilded Dreams", 20, "increases Elemental Mastery by 80");

    Artifact arrayOfDynamicObjectsArtifacts[]{ *oneArtifact, *anotherOneArtafact };

    delete anotherOneArtafact;

    ResourcesCalculatorForLevelingUpCharacters* calculator = new ResourcesCalculatorForLevelingUpCharacters();

    Ability pyronado("Pyronado", 3, 128, 20);
    Character xiangling("Xiangling", 60, kitainCrossSpear, *oneArtifact, pyronado);

    calculator->CalculateResorces(xiangling);
}