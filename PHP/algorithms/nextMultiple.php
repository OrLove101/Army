<?php
    $dividend = rtrim(fgets(STDIN));
    $divisor = rtrim(fgets(STDIN));
    $remainder;

    $remainder = $dividend % $divisor;
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    if ( $remainder > 0 ) {
        $dividend += $divisor;
    }
    echo $dividend-$remainder . PHP_EOL;
?>