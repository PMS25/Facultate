<?php
function nr_divizori($n){
    $k = 0;
    for($i = 1; $i<=$n; $i++)
        if($n % $i == 0)
            $k++;
    return $k;
}

function afisare_nr_cu_3_divizori($a){
    for($i = 1; $i<=$a; $i++){
        if(nr_divizori($i) == 3)
            echo("$i <br>");
    }
}

$a=$_POST['a'];

afisare_nr_cu_3_divizori($a);
?>
