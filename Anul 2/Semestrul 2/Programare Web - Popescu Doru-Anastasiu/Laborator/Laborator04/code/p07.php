<?php
$lista01=$_POST['lista01']; # 2
$lista02=$_POST['lista02']; # 1
$lista03=$_POST['lista03']; # 1
$lista04=$_POST['lista04']; # 3
$lista05=$_POST['lista05']; # 1
$lista06=$_POST['lista06']; # 3
$lista07=$_POST['lista07']; # 2
$lista08=$_POST['lista08']; # 1
$lista09=$_POST['lista09']; # 3
$lista10=$_POST['lista10']; # 1

function verificare($nr, $question, $answer){
    echo "Întrebarea $nr: ";
    if($question == $answer)
        echo "<span style=\"color:green;\">CORECT</span>";
    else
        echo "<span style=\"color:red;\">INCORECT</span>. Answer: $answer";
    echo "<br>";
}

verificare( 1, $lista01, 2);
verificare( 2, $lista02, 1);
verificare( 3, $lista03, 1);
verificare( 4, $lista04, 3);
verificare( 5, $lista05, 1);
verificare( 6, $lista06, 3);
verificare( 7, $lista07, 2);
verificare( 8, $lista08, 1);
verificare( 9, $lista09, 3);
verificare(10, $lista10, 1);

?>
