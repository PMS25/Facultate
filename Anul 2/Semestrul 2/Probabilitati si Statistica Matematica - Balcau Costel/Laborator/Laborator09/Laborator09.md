# Laborator 09

## Petculescu Mihai-Silviu

[TOC]

## Estimarea Ariilor şi a Volumelor

Următoarea funcţie estimează $\pi$ utilizând $N$ numere aleatoare ($\geq 10.000$).

```R
> disc_area = function(N){
  N_C = 0;
  for(i in 1:N) {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    if(x*x + y*y <= 1)
      N_C = N_C + 1;
  }
  return(4 * N_C / N);
}
> disc_area(10000) # 10.000
[1] 3.1412
> disc_area(50000) # 50.000
[1] 3.13776
> disc_area(100000) # 100.000
[1] 3.15496
```

### Aplicaţii

#### Exerciţiu 1

Estimaţi volumul sferei unitate (care este $4\pi/3$) folosind eşantioane de numere aleatoare de dimensuni diferite.

```R
> disc_sphere = function(N){
  N_C = 0;
  for(i in 1:N) {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    z = runif(1, -1, 1);
    if(x*x + y*y + z*z <= 1)
      N_C = N_C + 1;
  }
  return(8 * N_C / N);
}
> disc_sphere(10000) # 10.000
[1] 4.252
> disc_sphere(100000) # 100.000
[1] 4.2104
> disc_sphere(500000) # 500.000
[1] 4.192544
```

#### Exerciţiu 2

Estimaţi aria următoarei elipse (care este $2\pi$) $E = \{ (x, y) \in R2 ∶ x^2 + 4 \cdot y^2 \leq 4 \}$

```R
> disc_elipse = function(N){
  N_C = 0;
  for(i in 1:N) {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    if(x*x + 4*y*y <= 4 | 4*x*x + y*y <= 4)
      N_C = N_C + 1;
  }
  return(6 * N_C / N);
}
> disc_elipse(100000) # 100.000
[1] 5.9151
> disc_elipse(500000) # 500.000
[1] 5.915076
```

## Integrarea Monte Carlo

1. Estimaţi valoarea următoarei integrale: $\int_{0}^{10} e^{-u^2/2}$. Următoarea funcţie oferă o estimare pentru un eşantion de dimensiune $N$:

```R
> MC_integration = function(N) {
  sum = 0;
  for(i in 1:N) {
    u = runif(1, 0, 10);
    sum = sum + exp(-1 * u * u / 2);
  }
  return(10 * sum / N);
}
> MC_integration(20000) # 20.000
[1] 1.245384
> MC_integration(50000) # 50.000
[1] 1.238274
```

Putem calcula o medie pentru $k = 30$ astfel de aproximări şi deviaţia standard corespunzătoare folosind următoarea funcţie.

```R
> MC_integr_average = function(k, N) {
  estimates = 1:2;
  for(i in 1:k)
    estimates[i] = MC_integration(N);
  print(mean(estimates)); # aproximare
  print(sd(estimates)); # deviatie standard
}
> MC_integr_average(30, 20000)
[1] 1.252535
[1] 0.0181556
> MC_integr_average(30, 50000)
[1] 1.255748
[1] 0.01160825
```

2. Estimaţi valoarea următoarei integrale: $\int_{0}^{\infty} e^{-u^2} $. Mai întâi, următoarea funcţie oferă o estimare pentru un eşantion de dimensiune $N$

```R
> MC_improved_integration = function(N) {
  sum = 0;
  for(i in 1:N) {
    u = rexp(1, 1);
    sum = sum + exp(-1 * u * u) / exp(-u);
  }
  return(sum / N);
}
> MC_improved_integration(20000) # 20.000
[1] 0.8826716
> MC_improved_integration(50000) # 50.000
[1] 0.8822265
```

Putem calcula o medie pentru $k = 30$ astfel de aproximări şi deviaţia standard corespunzătoare folosind următoarea funcţie.

```R
> MC_imprvd_integr_average = function(k, N) {
  estimates = 1:2;
  for(i in 1:k)
    estimates[i] = MC_improved_integration(N);
  print(mean(estimates)); # aproximare
  print(sd(estimates)); # deviatie standard
}
> MC_imprvd_integr_average(30, 20000) # 20.000
[1] 0.8865095
[1] 0.003210532
> MC_imprvd_integr_average(30, 50000) # 50.000
[1] 0.8857868
[1] 0.002120164
```

### Aplicaţii

#### Exerciţiu 1

Estimaţi valorile următoarelor integrale şi comparaţi rezultatul cu valorile exacte (dacă sunt date):

a) $\large\int_{0}^{\pi} \! cos^2x\ \mathrm{d}x=\frac{\pi}{2}$

b) $\large \int_{0}^{3} \! e^x\ \mathrm{d}x = 19.08554$

```R
# a
> MC_ex1_a = function(N) {
  sum = 0;
  for(i in 1:N) {
    x = runif(1, 0, pi);
    sum = sum + (cos(x))^2;
  }
  return(pi * sum / N);
}
> pi/2
[1] 1.570796
> MC_ex1_a(100000) # 100.000
[1] 1.576174

# b
> MC_ex1_b = function(N) {
  sum = 0;
  for(i in 1:N) {
    x = runif(1, 0, 3);
    sum = sum + exp(x);
  }
  return(3 * sum / N);
}
> 19.08554
[1] 19.08554
> MC_ex1_b(100000) # 100.000
[1] 19.05757
```

#### Exerciţiu 2

Estimaţi valorile următoarelor integrale şi comparaţi rezultatul cu valorile exacte şi calculaţi erorile absolute şi relative corespunzătoare:

a) $\large \int_{0}^{+\infty} \frac{\mathrm{d}x}{x^2+1} = \frac{\pi}{2}$

b) $\large \int_{2}^{+\infty} \frac{\mathrm{d}x}{x^2-1} = \frac{ln2}{2}$

```R
# a
> MC_ex2_a = function(N) {
  sum = 0;
  for(i in 1:N) {
    x = rexp(1,1);
    sum = sum + x/(x^2 + 1);
  }
  return(sum / N);
}
> MC_ex2_a(100000)
[1] 0.6196665
> pi / 2
[1] 1.570796

# b
> MC_ex2_b = function(N) {
  sum = 0;
  for(i in 1:N) {
    x = rexp(1,1);
    sum = sum + 1/(x^2 - 1);
  }
  return(sum / N);
}
> MC_ex2_b(100000) # 100.000
[1] -0.9578217
> log(2)/2
[1] 0.3465736
```

#### Exerciţiu 3

Estimaţi valoarea următoarei integrale utilizând metoda MC îmbunătăţită, cu distribuţia
exponenţială ($\lambda = 1,\ N = 40000$)
$$
\large \int_{0}^{+\infty} e^{-u^2/2} = \sqrt{\pi/2}
$$
Comparaţi rezultatul cu valoarea exactă şi calculaţi erorile absolute şi relative corespunzătoare. Determinaţi apoi 30 astfel de aproximări şi calculaţi o medie şi o deviaţie standard.

```R
> MC_ex3 = function(N) {
  sum = 0;
  for(i in 1:N) {
    u = rexp(1, 1);
    sum = sum + exp(-1 * u * u / 2) / exp(-u);
  }
  return(sum / N);
}
> MC_ex3(40000) # 40.000
[1] 1.253802
> sqrt(pi/2)
[1] 1.253314
```

