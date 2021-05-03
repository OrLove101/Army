#include "Unit.hpp"
#include "Werewolf.hpp"
#include "Soldier.hpp"
#include "Rogue.hpp"
#include "Berserker.hpp"
#include "Vampire.hpp"
#include "SpellCaster.hpp"
#include "Wizard.hpp"
#include "Healer.hpp"
#include "Priest.hpp"
#include "Warlock.hpp"
#include "Necromancer.hpp"

int main() {

    Necromancer* necromancer = new Necromancer("Necro");
    Warlock* warlock = new Warlock("Warlock");
    // Priest* priest = new Priest("Batushka");
    // Wizard* wizard = new Wizard("Invoker");
    // Healer* healer = new Healer("Witch Doctor");
    // // Werewolf* werewolf = new Werewolf("Mihalich");
    // Vampire* vampire = new Vampire("Hahakula");
    Soldier* soldier = new Soldier("Capral");
    Deamon* deamon = &warlock->summon();
    // Deamon* deamon2 = &warlock->summon();
    // // Rogue* rogue = new Rogue("Blinde Bob");
    // //Berserker* berserk = new Berserker("Guts");

    soldier->attack(*necromancer);
    necromancer->attack(*soldier);

    std::cout << *soldier << " vs " << *necromancer << std::endl;

    std::cout << *soldier << " vs " << *deamon << std::endl;

    soldier->attack(*deamon);

    std::cout << *soldier << " vs " << *necromancer << std::endl;
    // std::cout << *soldier << " vs " << *deamon2 << std::endl;
    // std::cout << *warlock << std::endl;
    
    // priest->attack(*vampire);
    // // priest->attack(*soldier);

    // std::cout << *vampire << " vs " << *priest << std::endl;
    // // std::cout << *soldier << " vs " << *priest << std::endl;

    // vampire->attack(*priest);
    // // soldier->attack(*priest);

    // std::cout << *vampire << " vs " << *priest << std::endl;
    // std::cout << *soldier << " vs " << *priest << std::endl;

    // std::cout << *soldier << " vs " << *wizard << std::endl;

    // healer->spellCast(*soldier);

    // std::cout << *soldier << " vs " << *wizard << std::endl;

    // healer->spellCast(*soldier);

    // std::cout << *soldier << " vs " << *wizard << std::endl;

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