<?php
    $limit = rtrim(fgets(STDIN));

    echo implode(' ', range(1, $limit)) . PHP_EOL;
?>