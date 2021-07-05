<?php
    $dividend = fgets(STDIN);
    $divisor = fgets(STDIN);

    $result = ($dividend / $divisor) * $divisor;
    if ( $dividend < 0 && $divisor != $dividend ) {
        if ( $divisor > 0 ) {
            $divisor *= (-1);
        }
        if ( $dividend % $divisor < 0 ) {
            $result = $dividend + $divisor - ($dividend % $divisor);
        }
    }
    echo $result . PHP_EOL;
?>