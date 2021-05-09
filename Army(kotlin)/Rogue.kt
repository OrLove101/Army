class Rogue(name: String): Soldier(name) {
    init {
        this.state.counterAttackable = false
    }
}