#include "mrpGame.h"
#include <stdlib.h>
#include <iostream>
#include <apparel.h>

#define pointPrecision = 1
#define linePrecision = 0.5
#define noPrecision = 0
namespace mrp {

    int roll() {
        return rand() % 20 + 1; 
    }

    int calcDamage(int damage, int power, int accuracyWithRoll, int evade, int armour, int elusiveness, int lethality, int roll, int coverage,int criticalHitRatio, int yield) {

        double efficiency = (accuracyWithRoll - 20 + evade) / 10.0;
        double armourCalc = 100;
        
        

        if (efficiency > 0) {
            efficiency = efficiency > 1 ? 1 : efficiency;
            power = power * efficiency;
            damage = damage * efficiency;
        }
        else {
            return 0;
        }
//        std::cout << efficiency << std::endl; 

        

        // Eventually loop through list of armour
        if (criticalHitRatio != 0) {
            int critRating = 20-((100 - coverage) / 100.0 * criticalHitRatio * (lethality / elusiveness) * 20.0);
            if (roll >= critRating)
                armour = 0;
        }
        if (armour > 0) {

            armourCalc = static_cast<double>(armour) / power * 100.0; 
            armourCalc = yield < armourCalc ? yield : armourCalc;
            std::cout << armourCalc << std::endl;

            damage = std::roundf(damage * (armourCalc / 100.0));
            power = std::roundf(power * (armourCalc / 100.0));
        }
        
//        std::cout << damage  << std::endl;
        return damage;
    }
}
