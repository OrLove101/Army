sealed class Spell(var magicPower: Int, var manaConsume: Int) {
    fun spellCast(enemy: Unit, thisCaster: SpellCaster) {
        var potentialPower: Int = this.magicPower

        thisCaster.mana.takeMana(this.manaConsume)
        if ( enemy.state.canTakeMagic ) {
            if ( thisCaster.state.isHealer && this is MagicAttack ) {
                potentialPower /= 2
                if ( thisCaster.state.isPriest && enemy.state.isUndead ) potentialPower *= 2
            } else if ( !thisCaster.state.isHealer && this is MagicHeal ) potentialPower /= 2
            affect(enemy, potentialPower)
        }
    }
    abstract fun affect(enemy: Unit, power: Int)
}

class MagicAttack(magicPower: Int, manaConsume: Int): Spell(magicPower, manaConsume) {
    override fun affect(enemy: Unit, power: Int) {
        enemy.health.takeDamage(power)
    }
}

class MagicHeal(magicPower: Int, manaConsume: Int): Spell(magicPower, manaConsume) {
    override fun affect(enemy: Unit, power: Int) {
        enemy.health.addHitPoints(power)
    }
}