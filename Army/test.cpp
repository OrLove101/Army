#include "Unit.hpp"
#include "Soldier.hpp"

int main() {
    Soldier* soldier = new Soldier("Capral");
    Soldier* soldier2 = new Soldier("Cap");

    std::cout << *soldier << " vs " << *soldier2 << std::endl;

    soldier2->attack(*soldier);

    std::cout << *soldier << " vs " << *soldier2 << std::endl;

    return 0;
}