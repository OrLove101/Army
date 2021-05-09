class Werewolf(name: String): Soldier(name) {
    init {
        this.state.isWerewolf = true
    }
}