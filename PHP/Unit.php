<?php
class Unitt {
    private $damage;
    private $hitPoints, $hitPointsLimit;
    private $name;

    private function validate($hp, $dmg) {
        if ( is_numeric($hp) && is_numeric($dmg) ) {
            return;
        }
        throw new Exception("Invalid param");
    }

    private function ensureIsAlive() {
        if ( $this->hitPoints == 0 ) {
            throw new Exception("UnitIsDeadException");
        }
    }

    public function __construct($name="Barbarian", $hp=100, $dmg=5) {
        $this->validate($hp, $dmg);

        $this->name = $name;
        $this->hitPoints = $hp;
        $this->hitPointsLimit = $hp;
        $this->damage = $dmg;
    }

    public function __get($name) {
        return $this->$name;
    }

    public function addHitPoints($hp) {
        $potentialHp;

        $this->ensureIsAlive();
        if ( $hp > 0 ) {
            $potentialHp = $this->hitPoints + $hp;
            if ( $potentialHp > $this->hitPointsLimit ) {
                $potentialHp = $this->hitPointsLimit;
            }
            $this->hitPoints = $potentialHp;
        }
    }

    public function takeDamage($dmg) {
        $potentialHp;

        $this->ensureIsAlive();
        if ( $dmg > 0 ) {
            $potentialHp = $this->hitPoints - $dmg;
            if ( $potentialHp < 0 ) {
                $potentialHp = 0;
            }
            $this->hitPoints = $potentialHp;
        }
    }

    public function attack(Unitt $enemy) {
        $enemy->takeDamage($this->damage);

        if ( $enemy->hitPoints != 0 ) {
            $enemy->counterAttack($this);
        }
    }

    public function counterAttack(Unitt $enemy) {
        $enemy->takeDamage($this->damage/2);
    }

    public function __toString() {
        return $this->name . " " . $this->hitPoints . "/" . $this->hitPointsLimit . "hp, damage: " . $this->damage;
    }
}

$a = new Unitt();
$b = new Unitt("Knight", 200, 20);

echo $a . " vs " . $b . PHP_EOL;

$b->attack($a);

echo $a . " vs " . $b . PHP_EOL;

?>