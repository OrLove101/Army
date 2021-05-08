public class Vampire extends Soldier {
    public Vampire(String name) {
        super(name);
        this.getState().changeVampireState();
        this.getState().changeUndeadState();
    }
}