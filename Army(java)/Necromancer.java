public class Necromancer extends Wizard implements Observer {
    private int hpFromVictim = 20;

    public Necromancer(String name) {
        super(name);
        this.spellBook.put(SpellList.AVALANCHE, new MagicAttack(35, 15));
    }

    @Override
    public void update() {
        this.getHealth().addHitPoints(hpFromVictim);
    }

    @Override
    public void attack(Unit enemy) {
        super.attack(enemy);
        enemy.add(this);
    }

    @Override
    public void spellCast(Unit enemy) {
        super.spellCast(enemy);
        enemy.add(this);
    }
}