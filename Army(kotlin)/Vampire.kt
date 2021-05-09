class Vampire(name: String): Soldier(name) {
    init {
        this.state.isVampire = true
    }
}