<?php
    class Pape {
        private $content;
        private $maxSymbols;

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

        public function __construct($maxSymbols=4096) {
            $this->maxSymbols = $this->validate($maxSymbols);
        }

        public function __get($name) {
            return $this->$name;
        }

        public function addContent($message) {
            $this->strValidate($message);

            $total = strLen($this->content) + strLen($message);

            if ( strLen($this->content) == $this->maxSymbols ) {
                throw new Exception("OutOfSpaceException");
            }
            if ( $total > $this->maxSymbols ) {
                $this->content .= substr($message, 0, $this->maxSymbols-strLen($this->content));
                return;
            }
            $this->content .= $message;
        }

        public function show() {
            echo $this->content . PHP_EOL;
        }
    }
?>