#include "Unit.hpp"
#include "Werewolf.hpp"
#include "Soldier.hpp"
#include "Rogue.hpp"
#include "Berserker.hpp"
#include "Vampire.hpp"

int main() {
    Werewolf* werewolf = new Werewolf("Mihalich");
    Werewolf* werewolf2 = new Werewolf("Sanich");
    Vampire* vampire = new Vampire("Hahakula");
    Soldier* soldier = new Soldier("Capral");
    Rogue* rogue = new Rogue("Blinde Bob");
    Berserker* berserk = new Berserker("Guts");

    std::cout << *werewolf << " vs " << *werewolf2 << std::endl;

    werewolf->attack(*werewolf2);

    std::cout << *werewolf << " vs " << *werewolf2 << std::endl;

    werewolf2->transform();

    std::cout << "-------------------------------" << std::endl;

    std::cout << *werewolf << " vs " << *werewolf2 << std::endl;

    werewolf2->transform();

    std::cout << *werewolf << " vs " << *werewolf2 << std::endl;

    vampire->attack(*soldier);

    std::cout << *soldier << " vs " << *vampire << std::endl;

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