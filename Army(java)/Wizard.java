import java.util.Map;
import java.util.Scanner;

public class Wizard extends SpellCaster {
    public Wizard(String name) {
        super(name);
        this.spellBook.put(SpellList.FIREBALL, new MagicAttack(40, 20));
        this.spellBook.put(SpellList.FREEZ, new MagicAttack(20, 5));
        this.spellBook.put(SpellList.FLOOD, new MagicAttack(15, 1));
        this.spellBook.put(SpellList.PATCHUP, new MagicHeal(10,5));
    }

    @Override
    public void spellCast(Unit enemy) {
        int spellToUse;
        StringBuffer buffer = new StringBuffer();
        Scanner scanner = new Scanner(System.in);

        for ( Map.Entry<SpellList, Spell> entry : this.spellBook.entrySet() ) {
            if ( entry.getKey() == SpellList.FIREBALL ) {
                buffer.append(SpellList.FIREBALL.ordinal()+" - Fireball\n");
            } else if ( entry.getKey() == SpellList.FREEZ ) {
                buffer.append(SpellList.FREEZ.ordinal()+" - Freez\n");
            } else if ( entry.getKey() == SpellList.FLOOD ) {
                buffer.append(SpellList.FLOOD.ordinal()+" - Flood\n");
            } else if ( entry.getKey() == SpellList.AVALANCHE ) {
                buffer.append(SpellList.AVALANCHE.ordinal()+" - Avalanche\n");
            } else if ( entry.getKey() == SpellList.PATCHUP ) {
                buffer.append(SpellList.PATCHUP.ordinal()+" - Patch up\n");
            } else if ( entry.getKey() == SpellList.HEAL ) {
                buffer.append(SpellList.HEAL.ordinal()+" - Heal\n");
            }
        }
        buffer.append("Type in which spell to use");

        System.out.println(buffer);

        spellToUse = scanner.nextInt();

        this.spellBook.get(SpellList.values()[spellToUse]).spellCast(enemy, this);
    }
}