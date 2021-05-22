<?php
function prim($n) {
    if ($n < 2) return 0;
    for ($i = 2; $i * $i <= $n; $i++)
        if ($n % $i == 0)
            return 0;
    return 1;
}

function pp($n) {
    $i = 1;
    while ($i * $i < $n)
        $i++;
    if ($i * $i == $n)
        return 1;
    return 0;
}


function cp($n) {
    $i = 1;
    while ($i * $i * $i < $n)
        $i++;
    if ($i * $i * $i == $n)
        return 1;
    return 0;
}

$n = $_POST['n'];
$op = $_POST['lista'];

if ($op == "op 1 - prim") {
    if (prim($n) == 1) echo "numarul $n este prim";
    else echo "numarul $n nu este prim";
}

if ($op == "op 2 - pp") {
    if (pp($n) == 1) echo "numarul $n este patrat perfect";
    else echo "numarul $n nu este patrat perfect";
}

if ($op == "op 3 - cp") {
    if (cp($n) == 1) echo "numarul $n este cub perfect";
    else echo "numarul $n nu este cub perfect";
}
?>