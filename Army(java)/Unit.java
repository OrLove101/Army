import java.util.ArrayList;
import java.util.Objects;

public abstract class Unit implements Cloneable, Observable {
    protected String name;
    protected Health health = new Health();
    protected Attack attack = new Attack();
    protected State state = new State();
    protected Ability ability = new Ability();
    protected ArrayList<Observer> observers = new ArrayList<>();

    public Unit(String name) {
        this.name = name;
    }

    public Unit() {
        this("Vasiliy");
    }

    public Health getHealth() {
        return this.health;
    }

    public Attack getAttack() {
        return this.attack;
    }

    public State getState() { return this.state; }

    public String getName() {
        return this.name;
    }

    @Override
    public void add(Observer observer) {
        this.observers.add(observer);
    }
    @Override
    public void remove(Observer observer) {
        this.observers.remove(observer);
    }
    @Override
    public void notifyObserver() {
        for ( Observer observer : observers ) {
            observer.update();
        }
    }

    public abstract void takeDamage(int dmg);
    public abstract void attack(Unit enemy);
    public abstract void counterAttack(Unit enemy);
    public abstract void transform(Unit enemy);
    public abstract void transform();

    @Override
    public Unit clone() throws CloneNotSupportedException {
        return (Unit) super.clone();
    }

    @Override
    public boolean equals(Object other) {
        if ( this == other ) return true;
        if ( other == null || this.getClass() != other.getClass() ) return false;
        Unit otherUnit = (Unit) other;
        return this.name == otherUnit.getName() && this.health == otherUnit.getHealth() &&
                this.getAttack() == otherUnit.getAttack();
    }

    @Override
    public int hashCode() {
        return Objects.hash(this.name, this.attack, this.health, this.state, this.ability);
    }

    @Override
    public String toString() {
        return this.getName() + " " + this.getHealth().getHitPoints() + "/" +
                this.getHealth().getHitPointsLimit() + "hp, damage: " + this.getAttack().getDamage();
    }

    protected class Health {
        private int hitPoints = 100;
        private int hitPointsLimit = 100;

        public Health() {}

        public boolean ensureIsAlive() {
            return this.hitPoints > 0;
        }

        public void takeDamage(int dmg) {
            if ( this.ensureIsAlive() ) {
                int potentialHp = this.hitPoints - dmg;

                if ( potentialHp < 0 ) {
                    potentialHp = 0;
                }
                this.hitPoints = potentialHp;
            }
        }

        public int getHitPoints() {
            return this.hitPoints;
        }
        public void setHitPoints(int hp) {
            this.hitPoints = hp;
        }

        public int getHitPointsLimit() {
            return this.hitPointsLimit;
        }
        public void setHitPointsLimit(int hp) {
            this.hitPointsLimit = hp;
        }

        public void addHitPoints(int hp) {
            if ( this.ensureIsAlive() ) {
                int potentialHp;

                potentialHp = this.hitPoints + hp;
                if ( potentialHp > this.hitPointsLimit ) {
                    potentialHp = this.hitPointsLimit;
                }
                this.hitPoints = potentialHp;
            }
        }
    }

    protected class Attack {
        private int damage = 10;
        private Unit thisUnit = Unit.this;

        public void attack(Unit enemy) {
            if ( thisUnit.getHealth().ensureIsAlive() ) {
                int potentialDamage = this.damage;

                enemy.getHealth().takeDamage(potentialDamage);
                if ( enemy.getHealth().getHitPoints() == 0 ) {
                    enemy.notifyObserver();
                }
                if (this.thisUnit.getState().isVampire()) {
                    thisUnit.getHealth().addHitPoints(potentialDamage / 2);
                }
                if (this.thisUnit.getState().isCounterAttackable()) {
                    enemy.getAttack().counterAttack(thisUnit);
                }
            }
        }
        public void counterAttack(Unit enemy) {
            int counterAttackDamage = this.damage / 2;

            enemy.getHealth().takeDamage(counterAttackDamage);
            if ( enemy.getHealth().getHitPoints() == 0 ) {
                enemy.notifyObserver();
            }
            if ( this.thisUnit instanceof Observer ) {
                enemy.add((Observer) thisUnit);
            }
            if ( this.thisUnit.getState().isVampire() ) {
                thisUnit.getHealth().addHitPoints(counterAttackDamage/4);
            }
        }

        public int getDamage() {
            return this.damage;
        }
        public void setDamage(int dmg) {
            this.damage = dmg;
        }
    }

    protected class State {
        private boolean counterAttackable = true;
        private boolean canTakeMagic = true;
        private boolean unitIsVampire;
        private boolean unitIsUndead;
        private boolean unitIsWerewolf;
        private boolean unitIsWolf;
        private boolean unitIsHealer;
        private boolean unitIsPriest;

        public boolean isCounterAttackable() {
            return this.counterAttackable;
        }
        public void changeCounterAttackable() {
            this.counterAttackable = !this.counterAttackable;
        }

        public boolean isCanTakeMagic() {
            return this.canTakeMagic;
        }
        public void changeMagicResist() {
            this.canTakeMagic = !this.canTakeMagic;
        }

        public boolean isVampire() { return this.unitIsVampire; }
        public void changeVampireState() { this.unitIsVampire = !this.unitIsVampire; }

        public boolean isUndead() { return this.unitIsUndead; }
        public void changeUndeadState() { this.unitIsUndead = !this.unitIsUndead; }

        public boolean isWerewolf() { return this.unitIsWerewolf; }
        public void changeWerewolfState() { this.unitIsWerewolf = !this.unitIsWerewolf; }

        public boolean isWolf() { return this.unitIsWolf; }
        public void changeWolfState() { this.unitIsWolf = !this.unitIsWolf; }

        public boolean isHealer() {return this.unitIsHealer;}
        public void changeHealerState() {this.unitIsHealer = !this.unitIsHealer;}

        public boolean isPriest() { return this.unitIsPriest; }
        public void changePriestState() { this.unitIsPriest = !this.unitIsPriest; }
    }

    protected class Ability {
        private Unit thisUnit = Unit.this;

        public void transform(Unit enemy) {
            if ( this.thisUnit.getState().isVampire() && !enemy.getState().isWerewolf() ) {
                enemy.getState().changeVampireState();
            } else if ( this.thisUnit.getState().isWerewolf() && !enemy.getState().isVampire() ) {
                enemy.getState().changeWerewolfState();
            }
        }

        public void transform() {
            if ( this.thisUnit.getState().isWerewolf() && !this.thisUnit.getState().isWolf() ) {
                int wolfHp = 200;
                int wolfDamage = 40;

                this.thisUnit.getState().changeWolfState();

                this.thisUnit.getHealth().setHitPointsLimit(wolfHp);
                this.thisUnit.getHealth().setHitPoints(wolfHp);

                this.thisUnit.getAttack().setDamage(wolfDamage);
            } else if ( this.thisUnit.getState().isWerewolf() ) {
                int humanHp = 100;
                int humanDamage = 10;

                this.thisUnit.getState().changeWolfState();

                this.thisUnit.getHealth().setHitPointsLimit(humanHp);
                this.thisUnit.getHealth().setHitPoints(humanHp);

                this.thisUnit.getAttack().setDamage(humanDamage);
            }
        }
    }
}
