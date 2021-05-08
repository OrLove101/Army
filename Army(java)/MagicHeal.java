public class MagicHeal extends Spell {
    public MagicHeal(int magicPower, int manaConsume) {
        super(magicPower, manaConsume);
    }

    @Override
    public void affect(Unit enemy, int power) {
        enemy.getHealth().addHitPoints(power);
    }
}