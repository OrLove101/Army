<?php

    include 'Date.php';

    class Passportt {
        private $uniqNum;
        private $series, $name, $lastName;
        private $personDate;

        private static $globalSeries = "AA";
        private static $globalNum = 1;

        private function validate($name, $lastName) {
            if ( is_string($name) || is_string($lastName) ) {
                return;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($name, $lastName, Datee $date) {
            $this->validate($name, $lastName);

            $this->name = $name;
            $this->lastName = $lastName;
            $this->personDate = $date;
            $this->uniqNum = Passportt::$globalNum;
            $this->series = Passportt::$globalSeries;
            Passportt::$globalNum += 1;

            if ( Passportt::$globalNum > 999999 ) {
                echo "Type in a new series: " . PHP_EOL;
                Passportt::$globalSeries = rtrim(fgets(STDIN));

                Passportt::$globalNum = 1;
            }
        }

        public function __get($name) {
            return $this->$name;
        }

        public static function getGlobalSeries() {
            return Passportt::$globalSeries;
        }

        public static function getGlobalNum() {
            return Passportt::$globalNum;
        }

        public static function setGlobalSeries($newSeries, $startNumber=1) {
            if ( $startNumber > 999999 ) {
                throw new Exception("Invalid number");
            }
            Passportt::$globalSeries = $newSeries;
            Passportt::$globalNum = $startNumber;
        }
    }
    $n1 = new Passportt("Danya", "Orlov", new Datee(25, 10, 2002));

    $n1->setGlobalSeries("BB");

?>