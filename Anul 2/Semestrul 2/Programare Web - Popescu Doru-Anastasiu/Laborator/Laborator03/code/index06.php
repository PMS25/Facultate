<?php
$a = $_POST["a"];
$b = $_POST["b"];

for($i=$a + ($a+1) % 2; $i<=$b; $i+=2)
    echo "$i <br>";
?>