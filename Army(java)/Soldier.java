public class Soldier extends Unit {
    public Soldier(String name) {
        super(name);
    }

    public Soldier() {}

    @Override
    public void takeDamage(int dmg) {
        this.health.takeDamage(dmg);
    }

    @Override
    public void attack(Unit enemy) {
        this.attack.attack(enemy);
    }

    @Override
    public void counterAttack(Unit enemy) {
        this.attack.counterAttack(enemy);
    }

    @Override
    public void transform(Unit enemy) {
        this.ability.transform(enemy);
    }

    @Override
    public void transform() {
        this.ability.transform();
    }
}