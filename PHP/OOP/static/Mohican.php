<?php
    class Mohica {
        private static $lastMohican = 0;

        public function __construct() {
            Mohica::$lastMohican = &$this;
        }

        public static function getLastMohican() {
            return Mohica::$lastMohican;
        }
    }
    $a = new Mohica();

    echo (Mohica::getLastMohican() === $a) . PHP_EOL;

    $b = new Mohica();
    $c = new Mohica();

    echo (Mohica::getLastMohican() === $c) . PHP_EOL;
    echo (Mohica::getLastMohican() === $b) . PHP_EOL;
?>