<?php
    class Complex {
        private $real, $imaginary;

        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($real=0, $imaginary=0) {
            $this->real = $this->validate($real);
            $this->imaginary = $this->validate($imaginary);
        }

        public function __get($name) {
            return $this->$name;
        }

        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }

        public function __toString() {
            if ( $this->imaginary >= 0 ) {
                return $this->real . "+" . $this->imaginary . "i" . PHP_EOL;
            } else {
                return $this->real . "" . $this->imaginary . "i" . PHP_EOL;
            }
        }
    }
    function compare($x, $y) {
        if ( $x == $y ) {
            echo $x . " is equal to " . $y . PHP_EOL;
        } else {
            echo $x . " is not equal to " . $y . PHP_EOL;
        }
    }
    function isTheSameInstance($x, $y) {
        if ( $x === $y ) {
            echo $x . " and " . $y . " is references to the same instance" . PHP_EOL;
        } else {
            echo $x . " and " . $y . " is different instances" . PHP_EOL;
        }
    }

    $a = new Complex(2, 5);
    $b = new Complex(3, 7);
    $c = new Complex(3, 7);
    $d = $a;
    $e = clone $a;

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;

    compare($a, $b);
    compare($b, $c);

    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);
?>