public class Warlock extends Wizard {
    private Demon demon;
    private int summonManaConsume = 100;

    public Warlock(String name) {
        super(name);
        this.spellBook.put(SpellList.AVALANCHE, new MagicAttack(35, 15));
    }
    public Demon summon(String name) {
        try {
            this.getMana().takeMana(summonManaConsume);
        } catch ( OutOfManaException e ) {
            return null;
        }
        return Demon.getDemon(name);
    }
}