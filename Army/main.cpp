#include "Unit.hpp"
#include "Werewolf.hpp"
#include "Soldier.hpp"
#include "Rogue.hpp"
#include "Berserker.hpp"
#include "Vampire.hpp"
#include "SpellCaster.hpp"
#include "Wizard.hpp"

int main() {

    Wizard* wizard = new Wizard("Invoker");
    // Werewolf* werewolf = new Werewolf("Mihalich");
    // Vampire* vampire = new Vampire("Hahakula");
    Soldier* soldier = new Soldier("Capral");
    // Rogue* rogue = new Rogue("Blinde Bob");
    // Berserker* berserk = new Berserker("Guts");
    
    // rogue->attack(*soldier);

    std::cout << *soldier << " vs " << *wizard << std::endl;

    wizard->spellCast(*soldier);

    std::cout << *soldier << " vs " << *wizard << std::endl;

    // std::cout << "-------------------------------" << std::endl;

    // std::cout << *berserk << " vs " << *rogue << std::endl;

    // berserk->attack(*rogue);

    // std::cout << *berserk << " vs " << *rogue << std::endl;

    // std::cout << "-------------------------------" << std::endl;

    // std::cout << *berserk << " vs " << *vampire << std::endl;

    // berserk->attack(*vampire);

    // std::cout << *berserk << " vs " << *vampire << std::endl;

    // std::cout << "-------------------------------" << std::endl;

    // std::cout << *werewolf << " vs " << *berserk << std::endl;

    // werewolf->attack(*berserk);

    // std::cout << *werewolf << " vs " << *berserk << std::endl;

    // werewolf->transform();
    // std::cout << "transformation" << std::endl;

    // std::cout << *werewolf << " vs " << *berserk << std::endl;

    // werewolf->transform();
    // werewolf->transform(*berserk);
    // berserk->transform();
    // std::cout << "transformation" << std::endl;

    // std::cout << *werewolf << " vs " << *berserk << std::endl;

    // std::cout << *soldier << " vs " << *rogue << std::endl;

    // rogue->attack(*soldier);

    // std::cout << *soldier << " vs " << *rogue << std::endl;

    // soldier->attack(*rogue);

    // std::cout << *soldier << " vs " << *rogue << std::endl;


    return 0;
}