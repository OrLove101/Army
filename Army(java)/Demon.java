public class Demon extends Soldier {
    private static Demon demon;
    private int demonHealthLimit = 1000;
    private int demonCurrentHealth = 1000;
    private int demonDamage = 250;

    private Demon(String name) {
        super(name);
        this.getHealth().setHitPointsLimit(this.demonHealthLimit);
        this.getHealth().setHitPoints(this.demonCurrentHealth);
        this.getAttack().setDamage(this.demonDamage);
    }

    public static Demon getDemon(String name) {
        if ( Demon.demon == null ) {
            Demon.demon = new Demon(name);
        }
        return Demon.demon;
    }
}