<?php
    $length = rtrim(fgets(STDIN));

    for ( $i = 1; $i <= $length; $i++ ) {
        $numbers = ($length * $length) - ($length * $i) + 1;

        echo implode(' ', range($numbers , ($length-1)+$numbers)) . PHP_EOL;
        $numbers += 1;
    }
?>