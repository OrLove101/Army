<?php
    class Gun {
        private $amount;
        private $capacity;
        private $isReady;
        private $model;
        private $totalShots;

        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($model="Beretta", $capacity=8) {
            $this->model = $model;
            $this->capacity = $this->validate($capacity);
            $this->totalShots = 0;
            $this->amount = 0;
            $this->isReady = 0;
        }

        public function __get($name) {
            return $this->$name;
        }
        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }

        public function prepare() {
            if ( $this->isReady ) {
                return;
            }
            $this->isReady = !$this->isReady;
        }

        public function reload() {
            $this->amount = $this->capacity;
            $this->isReady = 0;
        }

        public function shoot() {
            if ( !$this->isReady ) {
                throw new Exception("NotReadyException");
            }
            if ( $this->amount == 0 ) {
                throw new Exception("OutOfRoundsException");
            }
            echo "Bang" . PHP_EOL;
            $this->amount -= 1;
            $this->totalShots += 1;
        }

        public function __toString() {
            $string = "Gun: Model - " . $this->model . "; Rounds - " . $this->amount . "/" . $this->capacity . "; Total Shots - " . $this->totalShots . "; Status: ";

            if ( $this->isReady ) {
                $string .= " is ready to shoot!";
            } else {
                $string .= " is not ready to shoot!";
            }
            return $string;
        }
    }

        //Compare values
        function compare($x, $y) {
            if ( $x == $y ) {
                echo $x . " is equal to " . $y . PHP_EOL;
            } else {
                echo $x . " is not equal to " . $y . PHP_EOL;
            }
        }
        //Compare references
        function isTheSameInstance($x, $y) {
            if ( $x === $y ) {
                echo $x . " and " . $y . " is references to the same instance" . PHP_EOL;
            } else {
                echo $x . " and " . $y . " is different instances" . PHP_EOL;
            }
        }

    $a = new Gun("Deagle", 7);
    $b = new Gun();
    $c = new Gun();
    $d = $a; //Reference copy
    $e = clone $a; //Instance copy

    $c->reload();
    $c->prepare();
    $c->shoot();

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;

    compare($a, $b);
    compare($b, $c);

    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);
?>