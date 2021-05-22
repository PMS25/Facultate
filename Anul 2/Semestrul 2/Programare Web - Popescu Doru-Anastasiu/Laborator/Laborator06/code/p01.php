<?php
// Functions
function show_records($view, $con){
    $result = $con->query($view);
    while($x = mysqli_fetch_array($result))
        echo $x[0].' - '.$x[1].' - '.$x[2].' - '.$x[3]."<br>";
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
    $createTable = "create table CONTINENTE (continent char(15), tara char(15), suprafata int, nr_loc int)";
    if($con->query($createTable))
        logging("Tabela CONTINENTE creata cu success!");
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
array_push($insert, "insert into CONTINENTE values ('asia','armenia',30,3)");
array_push($insert, "insert into CONTINENTE values ('africa','botswana',58,23)");
array_push($insert, "insert into CONTINENTE values ('europa','france',640,67)");
array_push($insert, "insert into CONTINENTE values ('europa','russia',170,146)");
array_push($insert, "insert into CONTINENTE values ('america','mexico',197,126)");

// Clear previous records 
logging("Stergere date pre-existente.");
$con->query("delete from CONTINENTE");

// Insert Data
logging("Inserare date in db.");
insert_data($insert, $con);

// Show Data From DB
logging("Afisare date din db.");
show_records("select * from CONTINENTE", $con);

// Update Data From DB
logging("Update date.");
$con->query("update CONTINENTE set nr_loc = nr_loc + (nr_loc/10)");
show_records("select * from CONTINENTE", $con);

// Show Data From DB (Order by nr_loc)
logging("Date ordonate dupa nr_loc");
show_records("select * from CONTINENTE order by nr_loc", $con);

// Show Countries
logging("Lista Tari");
show_records("select tara from CONTINENTE", $con);
?>