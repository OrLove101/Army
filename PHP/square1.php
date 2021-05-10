<?php
    $length = rtrim(fgets(STDIN));

    for ( $i = 0; $i < $length; $i++ ) {
        echo implode(' ', range(1, $length)) . PHP_EOL;
    }
?>