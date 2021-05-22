<?php
$a = $_POST["a"];
$b = $_POST["b"];
$c = $_POST["c"];

if($a == $b - 1 && $b == $c - 1)
    echo "Numerele $a, $b, $c SUNT consecutive.";
else
    echo "Numerele $a, $b, $c NU SUNT consecutive.";
?>