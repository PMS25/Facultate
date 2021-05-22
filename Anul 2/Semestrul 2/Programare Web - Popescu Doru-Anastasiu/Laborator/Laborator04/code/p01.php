<?php
function suma_puteri($a, $b){
    return $a ** $b + $b ** $a;
}

$a=$_POST['a'];
$b=$_POST['b'];

echo suma_puteri($a, $b);
?>
