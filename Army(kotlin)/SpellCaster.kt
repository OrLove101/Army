abstract class SpellCaster(name: String): Soldier(name) {
    val mana: Mana = Mana()
    protected enum class SpellList {
        FIREBALL,
        FREEZ,
        FLOOD,
        AVALANCHE,
        PATCHUP,
        HEAL,
    }
    protected val spellBook = mutableMapOf<SpellList, Spell>()

    init {
        this.health.hitPointsLimit = 50
        this.health.hitPoints = 50
        this.attack.damage = 3
    }

    abstract fun spellCast(enemy: Unit)

    inner class Mana {
        var manaLimit = 100
        var currentMana = manaLimit

        fun takeMana(mana: Int) {
//            if ( this.currentMana < mana ) throw OutOfManaException()
            check(this.currentMana >= mana) { "Out of mana" }
            this.currentMana -= mana
        }
    }

    override fun toString(): String {
        return super.toString() + " mana: ${this.mana.currentMana}/${this.mana.manaLimit}"
    }
}
//class OutOfManaException: Exception("OutOfManaException") {}