public class Priest extends Healer {
    public Priest(String name) {
        super(name);
        this.getState().changePriestState();
    }
}