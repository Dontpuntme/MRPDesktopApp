#pragma once
namespace mrp {
    int roll();
    int calcDamage(int damage, int power, int accuracyWithRoll, int evade, int armour, int elusiveness, int lethality, int roll, int coverage, int criticalHitRatio, int yield);
}
