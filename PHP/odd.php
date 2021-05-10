<?php
    $limit = rtrim(fgets(STDIN));

    echo implode(' ', range(1, $limit, 2)) . PHP_EOL;
?>