<?php
$file_out = fopen("iesire.out", "w") or die("Unable to open file!");

if($file = fopen("intrare.in", "r")){
    $a = strrev(fgets($file));
    $b = strrev(fgets($file));

    fwrite($file_out, "$a\n");
    echo "$a <br>";
    
    fwrite($file_out, "$b\n");
    echo "$b <br>";
}

fclose($file_out);
?>