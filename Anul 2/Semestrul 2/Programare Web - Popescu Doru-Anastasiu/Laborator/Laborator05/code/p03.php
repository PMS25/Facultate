<?php
$file_out = fopen("test03-w.txt", "w") or die("Unable to open file!");

if ($file = fopen("test03.txt", "r")) {
    while(!feof($file)) {
        $line = fgets($file);
        $words = preg_split("/[\s]+/", $line, -1, PREG_SPLIT_NO_EMPTY);

        foreach ($words as $w)
            if (filter_var($w, FILTER_VALIDATE_EMAIL)){
                echo "$w <br>";
                fwrite($file_out, "$w\n");
            }
    }
    fclose($file);
}

fclose($file_out);
?>