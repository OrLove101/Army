public class Berserker extends Soldier {
    public Berserker(String name) {
        super(name);
        this.state.changeMagicResist();
    }
}