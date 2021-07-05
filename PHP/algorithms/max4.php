<?php
    $max = rtrim(fgets(STDIN));
    $a = rtrim(fgets(STDIN));
    $b = rtrim(fgets(STDIN));
    $c = rtrim(fgets(STDIN));

    if ( $a > $max ) {
        $max = $a;
    }
    if ( $b > $max ) {
        $max = $b;
    }
    if ( $c > $max ) {
        $max = $c;
    }
    echo $max . PHP_EOL;
?>