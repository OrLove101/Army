interface Observable {
    fun add(observer: Observer)
    fun remove(observer: Observer)
    fun notifyObserver()
}

interface Observer {
    fun update()
}