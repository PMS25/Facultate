<?php
function afisare($x){
    $file_out = fopen("test02-w.txt", "w") or die("Unable to open file!");
    foreach ($x as $i){
        echo "$i <br>";
        fwrite($file_out, "$i");
    }
    fclose($file_out);
}

if($file = fopen("test02.txt", "r")){
    $n = fgets($file);
    for($i = 1; $i <= $n; $i++){
        $x[$i] = fgets($file);
    }
    sort($x);
    afisare($x);
}
?>