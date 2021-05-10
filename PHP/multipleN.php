<?php
    $max = rtrim(fgets(STDIN));
    $divisor = rtrim(fgets(STDIN));

    $max -= $max % $divisor;
    if ( $divisor < 0 ) {
        $divisor *= -1;
    }
    echo implode(' ', range(0, $max, $divisor)) . PHP_EOL;
?>