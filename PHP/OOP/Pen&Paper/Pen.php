<?php

    include 'Paper.php';

    class Penn {
        private $inkAmount, $inkCapacity;

        private function validate($value) {
            if ( is_numeric($value) ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }

        private function strValidate($value) {
            if ( is_string($value) ) {
                return;
            }
            throw new Exception("Invalid param");
        }

        public function __construct ($inkCapacity=1024) {
            $this->inkAmount = $this->validate($inkCapacity);
            $this->inkCapacity = $inkCapacity;
        }

        public function __get($name) {
            return $this->$name;
        }

        public function write(Pape $paper, $message) {
            $this->strValidate($message);

            if ( $this->inkAmount == 0 ) {
                throw new Exception("OutOfInkException");
            }
            if ( strlen($message) > $this->inkAmount ) {
                $paper->addContent(substr($message, 0, $this->inkAmount));
                $this->inkAmount = 0;
                return;
            }
            $paper->addContent($message);
            $this->inkAmount -= strlen($message);
        }

        public function refill() {
            $this->inkAmount = $this->inkCapacity;
        }
    }

    $paper = new Pape();
    $pen = new Penn();

    $pen->write($paper, "Hello, world!");
    $paper->show();
?>