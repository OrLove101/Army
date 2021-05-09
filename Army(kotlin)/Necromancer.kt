class Necromancer(name: String): Wizard(name), Observer {
    private val hpFromVictim = 25

    override fun update() {
        this.health.addHitPoints(hpFromVictim)
    }

    override fun attack(enemy: Unit) {
        super.attack(enemy)
        enemy.add(this)
    }

    override fun spellCast(enemy: Unit) {
        super.spellCast(enemy)
        enemy.add(this)
    }

    override fun counterAttack(enemy: Unit) {
        super.counterAttack(enemy)
        enemy.add(this)
    }
}