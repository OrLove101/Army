public class Rogue extends Soldier {
    public Rogue(String name) {
        super(name);
        this.state.changeCounterAttackable();
    }
}