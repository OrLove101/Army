public class Werewolf extends Soldier {
    public Werewolf(String name) {
        super(name);
        this.getState().changeWerewolfState();
    }
}