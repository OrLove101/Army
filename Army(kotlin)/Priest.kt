class Priest(name: String): Healer(name) {
    init {
        this.state.isPriest = true
    }
}