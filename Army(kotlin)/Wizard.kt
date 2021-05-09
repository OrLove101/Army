open class Wizard(name: String): SpellCaster(name) {
    init {
        this.spellBook[SpellList.FIREBALL] = MagicAttack(40,20)
        this.spellBook[SpellList.FREEZ] = MagicAttack(20,5)
        this.spellBook[SpellList.FLOOD] = MagicAttack(15,1)
        this.spellBook[SpellList.PATCHUP] = MagicHeal(10, 5)
    }

    override fun spellCast(enemy: Unit) {
        val spellToUse: Int
        val buffer: StringBuilder = StringBuilder()

        this.spellBook.forEach { (key, value) ->
            when (key) {
                SpellList.FIREBALL -> buffer.append("${SpellList.FIREBALL.ordinal} - Fireball\n")
                SpellList.FREEZ -> buffer.append("${SpellList.FREEZ.ordinal} - Freez\n")
                SpellList.FLOOD -> buffer.append("${SpellList.FLOOD.ordinal} - Flood\n")
                SpellList.AVALANCHE -> buffer.append("${SpellList.AVALANCHE.ordinal} - Avalanche\n")
                SpellList.PATCHUP -> buffer.append("${SpellList.PATCHUP.ordinal} - Patch up\n")
                SpellList.HEAL -> buffer.append("${SpellList.HEAL.ordinal} - Heal\n")
            }
        }
        buffer.append("Type in which spell to use")

        println(buffer)

        spellToUse = readLine()?.toInt() ?: return

        this.spellBook[SpellList.values()[spellToUse]]?.spellCast(enemy, this)
    }
}