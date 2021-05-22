<?php

// functii
function insert($con) {
    $semestru = $_POST["semestru"];
    $zi = $_POST["zi"];
    $interval = $_POST["interval_orar"];
    $an = $_POST["an_studiu"];
    $grupa = $_POST["grupa"];
    $denumire = $_POST["denumire"];
    $tip = $_POST["tip"];
    $sala = $_POST["sala"];
    $profesor = $_POST["profesor"];
    $insert="INSERT INTO orar VALUES ($semestru, '$zi', '$interval', $an, $grupa, '$denumire','$tip','$sala','$profesor')";
    if($con->query($insert))
        echo "Date adaugate cu success"."<br>";
    else
        echo "Probleme la insert: ".$con->error;
}

function afisare($con, $view){
    echo "Tabel cu informatii"."<br>";
    echo "<table border = 2>";
    echo "<tr> <td>Semestru</td> <td>Zi</td> <td>Interval</td> <td>An</td> <td>Grupa</td> <td>Denumire</td> <td>Tip</td> <td>Sala</td> <td>Profesor</td> </tr>";
    $result = $con->query($view);
    while($x=mysqli_fetch_array($result)){
        echo "<tr>";
        for ($i = 0; $i <= 8; $i++)
            echo "<td>".$x[$i]."</td>";
        echo "</tr>";
    }
    echo "</table>";       
}

// creare conexiune
$con = mysqli_connect("localhost", "root", "");
if(!$con){
    echo "Eroare de conexiune la server MySql"."<br>";
    exit;
}

// crearea bazei de date
$db = mysqli_select_db($con, "pw2021");
if(!$db){
    if($con->query("CREATE DATABASE pw2021"))
        echo "Baza de date creata"."<br>";
    else
        echo "Eroare: ".$con->error;
}

// crearea tabelului informatii
$creare_tabel = "CREATE TABLE orar (semestru int, zi char(20), interval_orar char(20), an_studiu int, grupa int, denumire char(50), tip char(20), sala char(50), profesor char(50))";

if($con->query($creare_tabel))
    echo "Tabela orar creata cu success!"."<br>";
else
    echo "Fail to create"." ".$con->error."<br>";

// prelucrare actiuni
if(isset($_POST['insert'])) {
    insert($con);
}

if(isset($_POST['view_all'])) {
    afisare($con,"select * from orar");
}

if(isset($_POST['search_course'])) {
    $semestru = $_POST["semestru"];
    $zi = $_POST["zi"];
    $interval = $_POST["interval_orar"];
    if($interval == '')
        afisare($con, "SELECT * FROM orar WHERE `semestru`=$semestru AND `zi`='$zi'");
    else
        afisare($con, "SELECT * FROM orar WHERE `semestru`=$semestru AND `zi`='$zi' AND `interval_orar`='$interval'");
}

if(isset($_POST['view_group'])) {
    $grupa = $_POST["grupa"];
    afisare($con, "SELECT * FROM orar WHERE `grupa`='$grupa' ORDER BY `zi`"); 
}

if(isset($_POST['view_teacher'])) {
    $profesor = $_POST["profesor"];
    afisare($con, "SELECT * FROM orar WHERE `profesor`='$profesor' ORDER BY `zi`");  
}

if(isset($_POST['delete_all'])){
    if($con->query("DELETE FROM orar"))
        echo "Resetare realizata cu success"."<br>";
    else
        echo "Erroare la resetare: ".$con->error."<br>";
}

if(isset($_POST['delete_course'])){
    $semestru = $_POST["semestru"];
    $zi = $_POST["zi"];
    $interval = $_POST["interval_orar"];
    if($con->query("DELETE FROM orar WHERE `semestru`='$semestru' AND `zi`='$zi' AND `interval_orar`='$interval'"))
        echo "Date eliminate cu success"."<br>";
    else
        echo "Erroare la stergere: ".$con->error."<br>";
}
?>