<?php
    $in = fopen("task.in", "r");
    $out = fopen("task.out", "w");
    $result;

    fscanf($in, "%d %d", $x, $y);

    $result = gmp_lcm($x, $y);
    
    fwrite($out, $result);
?>