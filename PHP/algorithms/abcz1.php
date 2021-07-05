<?php
    $val = fgets(STDIN);

    if ( $val % 2 == 0 ) {
        echo "alpha" . PHP_EOL;
    } else if ( $val % 3 == 0 ) {
        echo "bravo" . PHP_EOL;
    } else if ( $val % 5 == 0 ) {
        echo "charlie" . PHP_EOL;
    } else {
        echo "zulu" . PHP_EOL;
    }
?>