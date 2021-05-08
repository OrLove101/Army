public class Healer extends Wizard {
    public Healer(String name) {
        super(name);
        this.getState().changeHealerState();
        this.spellBook.put(SpellList.HEAL, new MagicHeal(100, 20));
    }
}