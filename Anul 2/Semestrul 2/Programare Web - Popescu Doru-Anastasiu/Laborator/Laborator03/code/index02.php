<?php
$L = $_POST["L"];
$l = $_POST["l"];

$arie = $L * $l;
$perimetru = 2*($L + $l);

echo "Perimetru = $perimetru <br>";
echo "Arie = $arie";
?>