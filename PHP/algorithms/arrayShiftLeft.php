<?php
    function arrayShiftLeft(&$array) {
        $shifted = array_shift($array);
        $array[] = $shifted;
    }
?>