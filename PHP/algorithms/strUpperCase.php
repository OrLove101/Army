<?php
    function strUpperCase(&$string) {
        $string = strtoupper($string);
    }
    $a = "hello";
    strUpperCase($a);
    echo $a;
?>