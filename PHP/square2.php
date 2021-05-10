<?php
    $length = rtrim(fgets(STDIN));
    $counter = 1;

    for ( $i = 0; $i < $length; $i++ ) {
        echo implode(' ', range($counter, $counter+($length-1))) . PHP_EOL;
        $counter += $length;
    }
?>