#include "Unit.hpp"
#include "Soldier.hpp"
#include "Rogue.hpp"

int main() {
    Soldier* soldier = new Soldier("Capral");
    Soldier* soldier2 = new Soldier("Cap");
    Rogue* rogue = new Rogue("Blinde Bob");

    std::cout << *soldier << " vs " << *soldier2 << std::endl;

    soldier2->attack(*soldier);

    std::cout << *soldier << " vs " << *soldier2 << std::endl;

    std::cout << "-------------------------------" << std::endl;
    std::cout << *soldier << " vs " << *rogue << std::endl;

    rogue->attack(*soldier);

    std::cout << *soldier << " vs " << *rogue << std::endl;

    soldier->attack(*rogue);

    std::cout << *soldier << " vs " << *rogue << std::endl;


    return 0;
}