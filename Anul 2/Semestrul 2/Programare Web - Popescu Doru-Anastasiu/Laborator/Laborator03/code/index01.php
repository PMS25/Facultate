<?php
$n = $_POST["n"];
$s = 1;

for($i=2; $i<=$n; $i++)
    $s += $i;

echo "s = $s";
?>