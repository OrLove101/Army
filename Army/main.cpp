#include "Unit.hpp"
#include "Soldier.hpp"
#include "Rogue.hpp"
#include "Berserker.hpp"
#include "Vampire.hpp"

int main() {
    Vampire* vampire = new Vampire("Hahakula");
    Soldier* soldier = new Soldier("Capral");
    // Soldier* soldier2 = new Soldier("Cap");
    // Rogue* rogue = new Rogue("Blinde Bob");
    // Berserker* berserk = new Berserker("Guts");

    std::cout << *soldier << " vs " << *vampire << std::endl;

    soldier->attack(*vampire);

    std::cout << *soldier << " vs " << *vampire << std::endl;

    std::cout << "-------------------------------" << std::endl;

    vampire->attack(*soldier);

    std::cout << *soldier << " vs " << *vampire << std::endl;

    // std::cout << *soldier << " vs " << *rogue << std::endl;

    // rogue->attack(*soldier);

    // std::cout << *soldier << " vs " << *rogue << std::endl;

    // soldier->attack(*rogue);

    // std::cout << *soldier << " vs " << *rogue << std::endl;
    // std::cout << "-------------------------------" << std::endl;
    // std::cout << *berserk << " vs " << *rogue << std::endl;

    // berserk->attack(*rogue);

    // std::cout << *berserk << " vs " << *rogue << std::endl;

    return 0;
}