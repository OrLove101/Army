<?php
    $max = rtrim(fgets(STDIN));
    $a = rtrim(fgets(STDIN));
    $b = rtrim(fgets(STDIN));

    if ( $a > $max ) {
        $max = $a;
    }
    if ( $b > $max ) {
        $max = $b;
    }
    echo $max . PHP_EOL;
?>