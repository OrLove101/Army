#include "Unit.hpp"
#include "Soldier.hpp"
#include "Rogue.hpp"
#include "Berserker.hpp"

int main() {
    Soldier* soldier = new Soldier("Capral");
    Soldier* soldier2 = new Soldier("Cap");
    Rogue* rogue = new Rogue("Blinde Bob");
    Berserker* berserk = new Berserker("Guts");

    std::cout << *soldier << " vs " << *soldier2 << std::endl;

    soldier2->attack(*soldier);

    std::cout << *soldier << " vs " << *soldier2 << std::endl;

    std::cout << "-------------------------------" << std::endl;
    std::cout << *soldier << " vs " << *rogue << std::endl;

    rogue->attack(*soldier);

    std::cout << *soldier << " vs " << *rogue << std::endl;

    soldier->attack(*rogue);

    std::cout << *soldier << " vs " << *rogue << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << *berserk << " vs " << *rogue << std::endl;

    berserk->attack(*rogue);

    std::cout << *berserk << " vs " << *rogue << std::endl;

    return 0;
}