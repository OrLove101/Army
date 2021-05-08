import java.util.HashMap;
import java.util.Map;

public abstract class SpellCaster extends Soldier {
    protected Mana mana = new Mana();
    protected enum SpellList { FIREBALL, FREEZ, FLOOD, AVALANCHE, PATCHUP, HEAL }
    protected Map<SpellList, Spell> spellBook = new HashMap<>();

    {
        this.getHealth().setHitPointsLimit(50); //initializationBlock copies in every constructor
        this.getHealth().setHitPoints(50);
        this.getAttack().setDamage(3);
    }

    public SpellCaster(String name) {
        super(name);
    }

    public Mana getMana() {
        return this.mana;
    }

    public abstract void spellCast(Unit enemy);

    protected class Mana {
        private int manaLimit = 100;
        private int currentMana = manaLimit;

        public void takeMana(int mana) throws OutOfManaException {
            if ( this.currentMana < mana ) {
                throw new OutOfManaException();
            }
            this.currentMana -= mana;
        }

        public int getManaLimit() {
            return this.manaLimit;
        }
        public void setManaLimit(int manaLimit) {
            this.manaLimit = manaLimit;
        }

        public int getCurrentMana() {
            return this.currentMana;
        }
        public void setCurrentMana(int currentMana) {
            this.currentMana = currentMana;
        }
    }

    @Override
    public String toString() {
        return super.toString() + " mana: " + this.getMana().getCurrentMana() + "/" + this.getMana().getManaLimit();
    }
}