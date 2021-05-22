<?php

function sir($n){
    for($i = 1; $i <= $n; $i++)
        $x[$i] = 2 ** $i;
    echo("Crescator: ");
    for($i = 1; $i <= $n; $i++)
        echo("$x[$i] ");
    echo("<br>");
    echo("Descrescator: ");
    for($i = $n; $i >= 1; $i--)
        echo("$x[$i] ");
    echo("<br>");
}

$n=$_POST['n'];

sir($n);
?>
