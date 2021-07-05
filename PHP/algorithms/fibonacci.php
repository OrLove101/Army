<?php
    function fibonacci($number) {
        echo round(pow((sqrt(5)+1)/2, $number) / sqrt(5)) . PHP_EOL;
    }
?>