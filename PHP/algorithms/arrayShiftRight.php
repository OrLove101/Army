<?php
function arrayShiftRight(&$array, $size) {
    $length = $size - 1;
    $last = $array[$length];
    
    for ( ; $length > 0; $length-- ) {
        $array[$length] = $array[$length-1];
    }
    $array[0] = $last;
}
?>