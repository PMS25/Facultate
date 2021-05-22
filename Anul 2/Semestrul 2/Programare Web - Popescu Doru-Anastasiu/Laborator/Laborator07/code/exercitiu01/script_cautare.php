<?php
//conectarea la MySql
$conectare = mysqli_connect("localhost", "root", "");

if(!$conectare){
    echo "Eroare de conexiune la server MySql";
    exit;
}

$db = mysqli_select_db($conectare, "pw2021");
if(!$db){
    echo "Eroare la selectarea bazei de date!"."<br>";
}

$cnp = $_POST['cnp'];
$comanda_afisare = "SELECT * FROM informatii WHERE cnp = '$cnp'";
$rez = $conectare->query($comanda_afisare);

if(!$rez){
    echo "Eroare la afisarea datelor"."<BR>";
    exit;
}

//afisare tabelata a informatiilor din tabela informatii
echo "Tabelul persoanele cautate <br><br>";
echo "<table border = 1>";
echo "<tr> <td> Nume </td> <td> CNP </td> <td> CI </td> <td> Inaltime </td> </tr>";
while ($x = mysqli_fetch_array($rez)){
    echo "<tr>";
    echo "<td>" . $x['nume'] . "</td>";
    echo "<td>" . $x['cnp'] . "</td>";
    echo "<td>" . $x['ci'] . "</td>";
    echo "<td>" . $x['inaltime'] . "</td>";
    echo "</tr>";
}
echo "</table>";
?>