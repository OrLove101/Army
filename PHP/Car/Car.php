<?php
    include 'Point.php';

    class Car {
        private $fuelAmount, $fuelCapacity, $fuelConsumption;
        private $location;
        private $model;

        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        public function __construct($capacity, $consumption, Point $location, $model) {
            $this->fuelCapacity = $this->validate($capacity);
            $this->fuelAmount = $this->fuelCapacity;
            $this->fuelConsumption = $this->validate($consumption);
            $this->location = $location;
            $this->model = $model;
        }

        public function __get($name) {
            return $this->$name;
        }
        public function __set($name, $value) {
            $this->$name = $this->validate($value);
        }

        public function drivePoint(Point $destination) {
            $fuelNeeded = $this->location->distance($destination) * $fuelConsumption;

            if ( $this->fuelAmount < $fuelNeeded ) {
                throw new Exception("OutOfFuelException");
            }
            $this->location = $destination;
            $this->fuelAmount -= $fuelNeeded;
        }

        public function drive($x, $y) {

            $destination = new Point($this->validate($x), $this->validate($y));
            $fuelNeeded = $this->location->distance($destination) * $this->fuelConsumption;

            if ( $this->fuelAmount < $fuelNeeded ) {
                throw new Exception("OutOfFuelException");
            }
            $this->location = $destination;
            $this->fuelAmount -= $fuelNeeded;
        }

        public function refill($fuel) {
            $potentialAmount = $this->fuelAmount + $this->validate($fuel);

            if ( $potentialAmount > $this->fuelCapacity ) {
                throw new Exception("ToMuchFuel");
            }
            $this->fuelAmount += $fuel;
        }

        public function __toString() {
            return "Car: model - " . $this->model . "; location - " . $this->location . "; Fuel: " . $this->fuelAmount . "/" . $this->fuelCapacity . ";";
        }
    }

    $a = new Car(100, 20, new Point(0, 0), "Mers");
    $b = new Car(200, 30, new Point(0, 0), "BMW");
    $c = new Car(200, 5, new Point(0, 0), "BMW");
    $d = $a; //Reference copy
    $e = clone $a; //Instance copy

    $c->drive(5, 5);

    echo "a: " . $a . PHP_EOL;
    echo "b: " . $b . PHP_EOL;
    echo "c: " . $c . PHP_EOL;

    compare($a, $b);
    compare($b, $c);

    isTheSameInstance($a, $b);
    isTheSameInstance($a, $d);

?>