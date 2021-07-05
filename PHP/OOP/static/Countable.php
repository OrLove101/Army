<?php
    class Countabl {
        private static $quantity = 0;

        public function __construct() {
            Countabl::$quantity += 1;
        }

        public static function getQuantity() {
            return Countabl::$quantity;
        }
    }

    $a = new Countabl();

    echo Countabl::getQuantity() . PHP_EOL;

    $b = new Countabl();
    $c = new Countabl();

    echo Countabl::getQuantity() . PHP_EOL;
?>