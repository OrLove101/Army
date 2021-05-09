open class Healer(name: String): Wizard(name) {
    init {
        this.state.isHealer = true
        this.spellBook[SpellList.HEAL] = MagicHeal(100, 20)
    }
}