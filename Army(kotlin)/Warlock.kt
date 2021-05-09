class Warlock(name: String): Wizard(name) {
    private lateinit var demon: Demon
    private val summonManaConsume: Int = 100

    init {
        this.spellBook[SpellList.AVALANCHE] = MagicAttack(35,15)
    }

    fun summon(): Demon {
        this.mana.takeMana(summonManaConsume)
        if ( !::demon.isInitialized ) {
            this.demon = Demon
        }
        return this.demon
    }
}

object Demon: Soldier("Demon") {
    val demonHealth = 1000
    val demonAttack = 250

    init {
        this.health.hitPointsLimit = demonHealth
        this.health.hitPoints = demonHealth
        this.attack.damage = demonAttack
    }
}