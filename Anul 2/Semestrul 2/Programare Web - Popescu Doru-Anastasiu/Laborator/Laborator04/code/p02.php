<?php
function afisare_divizibile_k($a, $b, $k){
    for($i = $a; $i <= $b; $i++){
        if($i % $k == 0)
            echo "$i <br>";
    }
}

$a=$_POST['a'];
$b=$_POST['b'];
$k=$_POST['k'];

if($a < $b)
    afisare_divizibile_k($a, $b, $k);
else
    afisare_divizibile_k($b, $a, $k);
?>
