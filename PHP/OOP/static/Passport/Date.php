<?php

class Datee {
    private $day, $month, $year;

    private function validate($day, $month, $year) {
        if ( $year <= 0 || $month <= 0 || $day <= 0) {
            throw new Exception("Negative Date");
        }
        if ( $month < 1 && $month > 12 ) {
            throw new Exception("Invalid month");
        }
        if ( $month == 2 && $day == 29 && $year % 400 != 0 ) {
            if ( $year % 100 == 0 || $year % 4 != 0 ) {
                throw new Exception("Invalid day");
            }
        }
        if ( ($month == 1 || $month == 3 || $month == 5 || $month == 7 || $month == 8 || $month == 10) && $day > 31 ) {
            throw new Exception("Invalid day");
        } else if ( ($month == 4 || $month == 6 || $month == 9 || $month == 11 || $month == 12 ) && $day > 30 ) {
            throw new Exception("Invalid day");
        }
    }

    public function __construct($day=1, $month=1, $year=1970) {
        $this->validate($day, $month, $year);
        $this->day = $day;
        $this->month = $month;
        $this->year = $year;
    }

    public function __get($name) {
        return $this->$name;
    }

    public function __toString() {
        $string = $this->day . ".";

        if ( $this->month < 10 ) {
            $string .= "0";
        }
        $string .= $month . "." . $year;
        return $string;
    }
}

?>