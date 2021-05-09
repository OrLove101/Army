class Berserker(name: String): Soldier(name) {
    init {
        this.state.canTakeMagic = false
    }
}