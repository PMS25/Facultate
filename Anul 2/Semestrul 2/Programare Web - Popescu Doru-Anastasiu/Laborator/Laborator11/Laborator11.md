# Laborator 11

## Petculescu Mihai-Silviu

[TOC]

### Cod comun

![lab11_1](./img/lab11_1.png) 

```html
<div>
  <p>1. Citiţi trei numere şi afişaţi suma şi produsul lor.</p>
  <button onclick="f01()">Start</button>
  <div id="p01"></div>
  <p>2. Citiţi a, b numere naturale şi rezolvaţi ecuaţia ax+b=0.</p>
  <button onclick="f02()">Start</button>
  <div id="p02"></div>
  <p>3. Citiţi a, b, c numere natural nenule şi rezolvaţi ecuaţia ax<sup>2</sup>+bx+c=0.</p>
  <button onclick="f03()">Start</button>
  <div id="p03"></div>
  <p>4. Citiţi n numere naturale şi afişaţi aceste numere în ordine crescătoare, respectiv descrescătoare.</p>
  <button onclick="f04()">Start</button>
  <div id="p04"></div>
  <p>5. Citiţi numele şi prenumele unei presoane şi apoi afişaţi separate numele, respectiv prenumele pe rânduri diferite.</p>
  <button onclick="f05()">Start</button>
  <div id="p05"></div>
  <p>6. Citiţi cnp-ul unei persoane şi afişaţi data naşterii, urmată de varsta sa.</p>
  <button onclick="f06()">Start</button>
  <div id="p06"></div>
  <p>7. Citiţi n cuvinte şi afişaţi cuvintele de lungime maximă.</p>
  <button onclick="f07()">Start</button>
  <div id="p07"></div>
  <p>8. Citiţi un text în care cuvintele sunt separate prin câte un spaţiu. Apoi afişaţi primul şi ultimul cuvânt.</p>
  <button onclick="f08()">Start</button>
  <div id="p08"></div>
  <p>9. Citiţi un text în care cuvintele sunt separate prin câte un spaţiu. Apoi afişaţi cuvintele pe rânduri diferite.</p>
  <button onclick="f09()">Start</button>
  <div id="p09"></div>
</div>
```

```javascript
function clearBox(elementID) {
  document.getElementById(elementID).innerHTML = "";
}

function insertBox(elementID, input, output) {
  document.getElementById(elementID).innerHTML = `Input: <br> ${input} <br> Rezultat: <br> ${output}`;
}
```

### Problema 1

Citiţi trei numere şi afişaţi suma şi produsul lor.

```javascript
function f01() {
  const id = "p01";
  clearBox(id);
  const a = parseInt(prompt("Introduceti un numar natural a =", 0));
  const b = parseInt(prompt("Introduceti un numar natural b =", 0));
  const c = parseInt(prompt("Introduceti un numar natural c =", 0));
  const output = `Suma = ${a + b + c} \n Produs = ${a * b * c}`;
  insertBox(id, `a = ${a}, b = ${b}, c = ${c}`, output);
}
```

### Problema 2

Citiţi a, b numere naturale şi rezolvaţi ecuaţia ax+b=0.

```javascript
function f02() {
  const id = "p02";
  clearBox(id);
  const a = parseInt(prompt("Introduceti un numar natural a =", 0));
  const b = parseInt(prompt("Introduceti un numar natural b =", 0));
  const output = `Pentru ${a}*x + ${b} = 0 => x = ${-b / a}`;
  insertBox(id, `a = ${a}, b = ${b}`, output);
}
```

### Problema 3

Citiţi a, b, c numere natural nenule şi rezolvaţi ecuaţia ax2+bx+c=0.

```javascript
function f03() {
  const id = "p03";
  clearBox(id);
  const a = parseInt(prompt("Introduceti un numar natural a =", 0));
  const b = parseInt(prompt("Introduceti un numar natural b =", 0));
  const c = parseInt(prompt("Introduceti un numar natural c =", 0));
  let d = b * b - 4 * a * c;
  let output = "";
  if (d < 0) {
    // 1, 2, 4
    s = Math.round(Math.sqrt(-d) * 100) / 100;
    output = `x1 = (${-b / (2 * a)} + ${s / (2 * a)}*i) <br> x2 = (${-b / (2 * a)} - ${s / (2 * a)}*i)`;
  } else if (d == 0) {
    let x = -b / (2 * a);
    output = `x = ${x}`;
  } else {
    // 1, -5, 6
    let x1 = Math.round(((-b + Math.sqrt(d)) / (2 * a)) * 100) / 100;
    let x2 = Math.round(((-b - Math.sqrt(d)) / (2 * a)) * 100) / 100;
    output = `x1 = ${x1} <br> x2 = ${x2}`;
  }
  insertBox(id, `a = ${a}, b = ${b}, c = ${c}`, output);
}
```

### Problema 4

Citiţi n numere naturale şi afişaţi aceste numere în ordine crescătoare, respectiv descrescătoare.

```javascript
function f04() {
  const id = "p04";
  clearBox(id);
  const n = parseInt(prompt("Dati n = ", 0));
  const input = prompt(`Dati ${n} numere, separate prin spatiu: `, 0);
  let arr = input.split(" ").map((e) => parseInt(e));
  arr = arr.slice(0, Math.min(n, arr.length));
  let arr_c = arr.sort();
  let arr_d = [...arr].reverse();
  const output = `Crescator: ${arr_c} <br> Descrescator: ${arr_d}`;
  insertBox(id, `n = ${n}, lista: ${input}`, output);
}
```

### Problema 5

Citiţi numele şi prenumele unei presoane şi apoi afişaţi separate numele, respectiv prenumele pe rânduri diferite.

```javascript
function f05() {
  const id = "p05";
  clearBox(id);
  const input = prompt("Dati numele si prenumele: ", "");
  let text = input.split(" ");
  const output = `Nume: ${text[0]} <br> Prenume: ${text[Math.min(0, text.length - 1)]}`;
  insertBox(id, input, output);
}
```

### Problema 6

Citiţi cnp-ul unei persoane şi afişaţi data naşterii, urmată de varsta sa.

```javascript
function f06() {
  const id = "p06";
  const cnp = prompt("Dati cnp-ul: ", "");
  if (cnp.length < 7) insertBox(id, cnp, "Date incomplete.");
  else {
    let s = parseInt(cnp[0]);
    let an = parseInt(cnp.substring(1, 3));
    let luna = parseInt(cnp.substring(3, 5));
    let zi = parseInt(cnp.substring(5, 7));

    if (s == 1 || s == 2) an += 1900;
    else if (s == 3 || s == 4) an += 1800;
    else if (s >= 5 && s <= 8) an += 2000;

    let today = new Date();

    let varsta = today.getFullYear() - an;
    let m = today.getMonth() - luna;
    if (m < 0 || (m == 0 && today.getDate() < zi)) varsta--;

    const output = `Data nastere: ${zi}.${luna}.${an} <br> Varsta: ${varsta}`;
    insertBox(id, cnp, output);
  }
}
```

### Problema 7

Citiţi n cuvinte şi afişaţi cuvintele de lungime maximă.

```javascript
function f07() {
  const id = "p07";
  clearBox(id);
  const n = parseInt(prompt("Dati n = ", 0));
  const input = prompt(`Dati cele ${n} cuvinte, separate prin cate un spatiu: `, "");
  let text = input.split(" ").slice(0, Math.min(n, input.split(" ").length));
  let maxim = Math.max(...text.map((e) => e.length));
  
  const output = text.filter((e) => {
    if (maxim == e.length) return e;
  });
  
  insertBox(id, `${n}, ${input}`, output);
}
```

### Problema 8

Citiţi un text în care cuvintele sunt separate prin câte un spaţiu. Apoi afişaţi primul şi ultimul cuvânt.

```javascript
function f08() {
  const id = "p08";
  clearBox(id);
  const input = prompt("Introduceti textul: ", "");
  let text = input.split(" ");
  const output = `Primul: ${text[0]} <br> Ultimul: ${text[Math.max(0, text.length - 1)]}`;
  insertBox(id, input, output);
}
```

### Problema 9

Citiţi un text în care cuvintele sunt separate prin câte un spaţiu. Apoi afişaţi cuvintele pe rânduri diferite.

```javascript
function f09() {
  const id = "p09";
  clearBox(id);
  const input = prompt("Introduceti textul: ", "");
  const output = input.replaceAll(" ", "<br>");
  insertBox(id, input, output);
}
```
