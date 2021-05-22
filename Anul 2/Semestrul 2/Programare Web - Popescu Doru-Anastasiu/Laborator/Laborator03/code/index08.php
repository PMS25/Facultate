<?php
$p = 0;

echo "Răspuns intrebare 1: ","<br>";
$b01 = $_POST['Buton01'];
if($b01 == 2) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>B</b>;", "<br>";

echo "Răspuns intrebare 2: ","<br>";
$b02 = $_POST['Buton02'];
if($b02 == 3) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>C</b>;", "<br>";

echo "Răspuns intrebare 3: ","<br>";
$b03 = $_POST['Buton03'];
if($b03 == 2) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>B</b>;", "<br>";

echo "Răspuns intrebare 4: ","<br>";
$b04 = $_POST['Buton04'];
if($b04 == 1) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>A</b>;", "<br>";

echo "Răspuns intrebare 5: ","<br>";
$b05 = $_POST['Buton05'];
if($b05 == 1) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>A</b>;", "<br>";

echo "Răspuns intrebare 6: ","<br>";
$b06 = $_POST['Buton06'];
if($b06 == 2) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>B</b>;", "<br>";

echo "Răspuns intrebare 7: ","<br>";
$b07 = $_POST['Buton07'];
if($b07 == 3) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>C</b>;", "<br>";

echo "Răspuns intrebare 8: ","<br>";
$b08 = $_POST['Buton08'];
if($b08 == 1) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>A</b>;", "<br>";

echo "Răspuns intrebare 9: ","<br>";
$b09 = $_POST['Buton09'];
if($b09 == 3) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>C</b>;", "<br>";

echo "Răspuns intrebare 10: ","<br>";
$b10 = $_POST['Buton10'];
if($b10 == 2) { echo "Răspuns <b>CORECT</b> ", "<br>"; $p++; }
else echo "Răspuns <b>INCORECT</b>. ", "Soluţie: <b>B</b>;", "<br>";

echo "Punctaj Obţinut: $p";
?>