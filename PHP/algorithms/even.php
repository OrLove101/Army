<?php
    $limit = rtrim(fgets(STDIN));

    echo implode(' ', range(0, $limit, 2)) . PHP_EOL;
?>