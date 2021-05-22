<?php
//conectarea la MySql
$conectare = mysqli_connect("localhost", "root", "");

if(!$conectare){
    echo "Eroare de conexiune la server MySql"."<br>";
    exit;
}else{
    echo "Merge!"."<br>";
}

$db = mysqli_select_db($conectare, "pw2021");
if(!$db){ //crearea bazei de date
    if($conectare->query("CREATE DATABASE pw2021"))
        echo "Baza de date creata"."<br>";
    else
        echo "Eroare: ".$conectare->error;
}

// crearea tabelului informatii
$creare_tabel = "CREATE TABLE informatii ( nume char(40) PRIMARY KEY, cnp char(13), ci char(8), inaltime int )";

if($conectare->query($creare_tabel))
    echo "Tabela CONTINENTE creata cu success!"."<br>";
else
    echo "Fail to create"." ".$conectare->error."<br>";

// preluarea datelor din formular
$nume = $_POST['nume'];
$cnp = $_POST['cnp'];
$ci = $_POST['ci'];
$inaltime = $_POST['inaltime'];

//introducerea inregistrarilor in tabel
$introducere = "INSERT INTO informatii VALUES('$nume', '$cnp', '$ci', '$inaltime')";

if(!$conectare->query($introducere))
    echo "Eroare la introducerea datelor"."<br>";
else
    echo "Introducere cu succes in tabelul informatii"."<br>";
?>
