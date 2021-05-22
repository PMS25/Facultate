<?php
$n = $_POST["n"];
$s = 0;

for($i=2; $i<=$n; $i+=2)
    $s += $i;

echo "Suma numere pare mai mici ca $n = $s";
?>