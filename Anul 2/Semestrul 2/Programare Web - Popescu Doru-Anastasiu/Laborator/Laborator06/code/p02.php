<?php
// Functions
function show_records($view, $con){
    $result = $con->query($view);
    while($x = mysqli_fetch_array($result))
        echo $x[0].' - '.$x[1].' - '.$x[2].' - '.$x[3].' - '.$x[4]."<br>";
    echo("<br>");
}

function logging($message){
    echo $message."<br>";
}

function insert_data($insert, $con){
    foreach($insert as $element)
        if($con->query($element))
            logging("Element ($element) inserat cu success");
    echo("<br>");
}

function create_db($con){
    $db = mysqli_select_db($con, "pw2021");

    if(!$db){
        $sql = "CREATE DATABASE pw2021";
        if($con->query($sql) === TRUE)
            logging("Database created successfully.");
        else
            logging("Error creating database: ".$conn->error);
    }else
        logging("Baza de date existenta!");
}

function create_table($con){
    $createTable = "create table MAGAZINE (cod_mag int, denumire char(20), cod_prod int, cantitate int, pret_unit int)";
    if($con->query($createTable))
        logging("Tabela MAGAZINE creata cu success!");
    else
        logging("Fail to create"." ".$con->error);
}

// Create connection
$con = mysqli_connect("localhost", "root", "");

if(!$con){
    logging("Eroare de conexiune la server MySql.");
    exit;
}else
    logging("Conectare OK.");

// Create DB
create_db($con);

// Create Table
create_table($con);

// Data to be inserted 
$insert=[];
array_push($insert, "insert into MAGAZINE values (1,'Elefant',21,200,23)"); // carte
array_push($insert, "insert into MAGAZINE values (1,'Elefant',25,180,42)"); // carte
array_push($insert, "insert into MAGAZINE values (1,'Elefant',38,230,28)"); // carte
array_push($insert, "insert into MAGAZINE values (2,'Emag',3328,440,80)");
array_push($insert, "insert into MAGAZINE values (3,'Altex',239,80,2040)");  

// Clear previous records 
logging("Stergere date pre-existente.");
$con->query("delete from MAGAZINE");

// Insert Data
logging("Inserare date in db.");
insert_data($insert, $con);

// Show Data From DB
logging("Afisare date din db.");
show_records("select * from MAGAZINE", $con);

// Show Data From DB (Order by cod_prod, Cresc)
logging("Date ordonate dupa cod_produs (cresc)");
show_records("select * from MAGAZINE order by cod_prod", $con);

// Show Data From DB (Order by cod_prod, Desc)
logging("Date ordonate dupa cod_produs (desc)");
show_records("select * from MAGAZINE order by cod_prod desc", $con);

// Show Data From DB (With cod_mag given)
logging("Date de la magazinul 1");
show_records("select * from MAGAZINE where cod_mag = 1", $con);
?>