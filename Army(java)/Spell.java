public abstract class Spell {
    protected int magicPower;
    protected int manaConsume;

    public Spell(int magicPower, int manaConsume) {
        this.magicPower = magicPower;
        this.manaConsume = manaConsume;
    }

    void spellCast(Unit enemy, SpellCaster thisCaster) {
        int potentialPower = this.magicPower;

        try {
            thisCaster.getMana().takeMana(this.manaConsume);
        } catch (OutOfManaException e) {
            return;
        }
        if ( enemy.getState().isCanTakeMagic() ) {
            if ( thisCaster.getState().isHealer() && this instanceof MagicAttack ) {
                potentialPower /= 2;
                if ( thisCaster.getState().isPriest() && enemy.getState().isUndead() ) {
                    potentialPower *= 2;
                }
            } else if ( !thisCaster.getState().isHealer() && this instanceof MagicHeal ) {
                potentialPower /= 2;
            }
            affect(enemy, potentialPower);
        }
    }
    abstract void affect(Unit enemy, int power);
}