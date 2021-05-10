<?php
    $max = rtrim(fgets(STDIN));
    $a = rtrim(fgets(STDIN));
    $b = rtrim(fgets(STDIN));
    $c = rtrim(fgets(STDIN));
    $d = rtrim(fgets(STDIN));

    if ( $a > $max ) {
        $max = $a;
    }
    if ( $b > $max ) {
        $max = $a;
    }
    if ( $c > $max ) {
        $max = $a;
    }
    if ( $d > $max ) {
        $max = $d;
    }
    echo $max . PHP_EOL;
?>