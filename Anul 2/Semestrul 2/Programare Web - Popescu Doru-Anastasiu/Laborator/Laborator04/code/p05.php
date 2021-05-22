<?php

function matrice($n){
    for($i = 1; $i <= $n; $i++)
        for($j = 1; $j <= $n; $j++)
            $x[$i][$j] = $i + $j;

    echo("Afisare: <br>");
    for($i = 1; $i <= $n; $i++){
        for($j = 1; $j <= $n; $j++)
            echo ($x[$i][$j]." ");
        echo("<br>");
    }
}

$n=$_POST['n'];

matrice($n);
?>
