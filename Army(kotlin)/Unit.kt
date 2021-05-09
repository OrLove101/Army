import java.util.*

abstract class Unit(protected val name: String = "Vasiliy"): Observable {
    val health: Health = Health()
    protected val attack: Attack = Attack()
    val state: State = State()
    protected val ability: Ability = Ability()
    private val observers = mutableSetOf<Observer>()

    abstract fun attack(enemy: Unit)
    abstract fun counterAttack(enemy: Unit)
    abstract fun transform(enemy: Unit)
    abstract fun transform()

    override fun add(observer: Observer) {
        this.observers.add(observer)
    }

    override fun remove(observer: Observer) {
        this.observers.remove(observer)
    }

    override fun notifyObserver() {
        for ( element in observers ) { element.update() }
    }

    inner class Health {
        var hitPoints: Int = 100  // by default private with getter and setter
        var hitPointsLimit: Int = 100// equals to below // get and set have the same access modifier as property
//        get() = field
//        set(value) {field = value}

        fun ensureIsAlive(): Boolean {
            return this.hitPoints > 0
        }

        fun takeDamage(dmg: Int) {
            if ( this.ensureIsAlive() ) {
                var potentialHp: Int = this.hitPoints - dmg

                if ( potentialHp <= 0 ) {
                    potentialHp = 0
                    this@Unit.notifyObserver()
                }
                this.hitPoints = potentialHp
            }
        }

        fun addHitPoints(hp: Int) {
            if ( this.ensureIsAlive() ) {
                var potentialHp: Int = this.hitPoints + hp

                if ( potentialHp > this.hitPointsLimit ) {
                    potentialHp = this.hitPointsLimit
                }
                this.hitPoints = potentialHp
            }
        }
    }

    protected inner class Attack {
        var damage: Int = 10
        var thisUnit: Unit = this@Unit

        fun attack(enemy: Unit) {
            if ( this.thisUnit.health.ensureIsAlive() ) {
                var potentialDamage: Int = this.damage

                if ( this@Unit.state.isPriest && enemy.state.isUndead ) potentialDamage *= 2

                enemy.health.takeDamage(potentialDamage)
                if ( thisUnit.state.isVampire ) thisUnit.health.addHitPoints(potentialDamage/2)

                if ( this.thisUnit.state.counterAttackable ) enemy.counterAttack(thisUnit)
            }
        }

        fun counterAttack(enemy: Unit) {
            var counterAttackDamage = this.damage / 2


            enemy.health.takeDamage(counterAttackDamage)
            if ( this@Unit.state.isVampire ) {
                this@Unit.health.addHitPoints(counterAttackDamage/4)
            }
        }
    }

    data class State(var counterAttackable: Boolean = true,
                               var canTakeMagic: Boolean = true,
                               var isVampire: Boolean = false,
                               var isWerewolf: Boolean = false,
                               var isWolf: Boolean = false,
                     var isHealer: Boolean = false,
                     var isPriest: Boolean = false,
                     var isUndead: Boolean = false,
    )

    protected inner class Ability {
        fun transform(enemy: Unit) {
            if ( this@Unit.state.isVampire && !enemy.state.isWerewolf ) {
                enemy.state.isVampire = true
            } else if ( this@Unit.state.isWerewolf && !enemy.state.isVampire ) {
                enemy.state.isWerewolf = true
            }
        }
        fun transform() {
            if ( this@Unit.state.isWerewolf && !this@Unit.state.isWolf ) {
                val wolfHp: Int = 200
                val wolfDamage: Int = 40

                this@Unit.state.isWolf = true

                this@Unit.health.hitPointsLimit = wolfHp
                this@Unit.health.hitPoints = wolfHp

                this@Unit.attack.damage = wolfDamage
            } else if ( this@Unit.state.isWerewolf ) {
                val humanHp: Int = 100
                val humanDamage: Int = 10

                this@Unit.state.isWolf = false

                this@Unit.health.hitPointsLimit = humanHp
                this@Unit.health.hitPoints = humanHp

                this@Unit.attack.damage = humanDamage
            }
        }
    }

    override fun toString(): String {
        return "${this.name} ${this.health.hitPoints}/${this.health.hitPointsLimit}hp, damage: ${this.attack.damage}"
    }

    override fun equals(other: Any?): Boolean {
        val otherUnit: Unit = other as Unit

        return when {
            this === other -> true
            this::class != other::class -> false
            this.name == otherUnit.name && this.health == otherUnit.health && this.attack == otherUnit.attack -> true
            else -> false
        }
    }

    override fun hashCode(): Int {
        return Objects.hash(this.name, this.attack, this.health, this.state)
    }
}
