<?php
    $number = fgets(STDIN);
    $result = gmp_fact($number);

    echo $result . PHP_EOL;
?>
