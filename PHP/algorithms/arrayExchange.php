<?php
    function arrayExchange(&$array, $len) {
    for ( $i = 0, $last = $len - 1; $i < $last; $i += 2 ) {
        $previous = $array[$i];
        
        $array[$i] = $array[$i+1];
        $array[$i+1] = $previous;
    }
}
?>