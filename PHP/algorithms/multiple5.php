<?php
    $number = rtrim(fgets(STDIN));

    $number -= $number % 5;
    echo implode(' ', range(0, $number, 5)) . PHP_EOL;
?>