<?php
    class Identifiabl {
        private static $globalId = 0;
        private $id;

        public function __construct() {
            Identifiabl::$globalId += 1;
            $this->id = Identifiabl::$globalId;
        }

        public static function getGlobalId() {
            return Identifiabl::$globalId;
        }
        public function __get($name) {
            return $this->$name;
        }
    }
    $a = new Identifiabl();

    echo Identifiabl::getGlobalId() . PHP_EOL;
    echo $a->id . PHP_EOL;

    $b = new Identifiabl();
    $c = new Identifiabl();

    echo Identifiabl::getGlobalId() . PHP_EOL;
?>