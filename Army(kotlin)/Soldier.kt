open class Soldier(name: String): Unit(name) {
    override fun attack(enemy: Unit) {
        this.attack.attack(enemy)
    }

    override fun counterAttack(enemy: Unit) {
        this.attack.counterAttack(enemy)
    }

    override fun transform(enemy: Unit) {
        this.ability.transform(enemy)
    }

    override fun transform() {
        this.ability.transform()
    }
}

fun main(args: Array<String>) {
    val soldier = Soldier("Vasya")
    val warlock: Warlock = Warlock("Galya")
    val necr = Necromancer("Necr")

    soldier.attack(necr)

    println("$soldier vs $necr")

    val demon: Demon = warlock.summon()

    soldier.attack(demon)

    println("$demon vs $soldier")
    println(necr)
}