public class MagicAttack extends Spell {
    public MagicAttack(int magicPower, int manaConsume) {
        super(magicPower, manaConsume);
    }

    @Override
    public void affect(Unit enemy, int power) {
        enemy.getHealth().takeDamage(power);
    }
}