#include "Wizard.hpp"

Wizard::Wizard(const std::string& name): SpellCaster(name) {
    this->spellBook->insert(std::pair<SpellList, Spell&>(FIREBALL, *new MagicAttack(30, 10)));
}

void Wizard::spellCast(Unit& enemy) {
    int spellToUse;

    std::cout << "You open your spell book and see: " << std::endl;

    std::map<SpellList, Spell&>::iterator it;

    for ( it = this->spellBook->begin(); it != this->spellBook->end(); it++ ) {
        if ( it->first == FIREBALL ) {
            std::cout << FIREBALL << " - Fireball" << std::endl;
        } else if ( it->first == FREEZ ) {
            std::cout << FREEZ << " - Freez" << std::endl;
        } else if ( it->first == FLOOD ) {
            std::cout << FLOOD << " - Flood" << std::endl;
        } else if ( it->first == AVALANCHE ) {
            std::cout << AVALANCHE << " - Avalanche" << std::endl;
        } else if ( it->first == PATCHUP ) {
            std::cout << PATCHUP << " - Patch up" << std::endl;
        } else if ( it->first == HEAL ) {
            std::cout << HEAL << " - Heal" << std::endl;
        }

    std::cout << "Type in which spell you want to use" << std::endl;
    std::cin >> spellToUse;

    this->spellBook->find(static_cast<SpellList>(spellToUse))->second.spellCast(enemy, *this);
    }
}