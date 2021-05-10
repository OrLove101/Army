<?php
    function arrayScan($in, $limit) {
        $numbers = explode(" ", trim(fread($in, $limit)));
        return count($numbers);
    }

    $in = fopen("task.in", "r");
    $num = arrayScan($in, 3);

    echo $num . PHP_EOL;
?>