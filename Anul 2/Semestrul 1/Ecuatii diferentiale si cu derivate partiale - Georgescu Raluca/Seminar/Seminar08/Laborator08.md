# Seminar08

## Aplicaţii ale ecuaţiilor diferenţiale liniare de ordinul al doilea

[TOC]

## Oscilaţii liniare

Considerăm un corp material supus unei forţe de tip elastic. Vom privi corpul ca un punct material cu masa constantă $\large m$. Pe baza cunoscutei legi a lui Hooke forţa elastică este direct proporţională cu vectorul de mişcare $\large x$. Modelul matematic al mişcărilor provine din legea a II-a a lui Newton.

### Oscilaţii libere

**Considerăm că forţa elastică este singura forţă ce acţionează asupra punctului material.**

Modelul matematic al mişcărilor liniare este: $\large m \cdot \ddot{x} = -k \cdot x$, unde $\large k$ este o constantă strict pozitivă numită constanta elastică. Ecuaţia diferenţială poate fi scrisă sub forma $\large m \cdot \ddot{x} + k \cdot x = 0$, care este o ecuaţie diferenţială de ordinul 2, liniară şi omogenă.

### Oscilaţii amortizate

**Punctul material este acţionat de forţa elastică şi o forţă de frecare cu un mediu rezistent.**

Modelul matematic al mişcărilor liniare este: $\large m \cdot \ddot{x} = -k \cdot x - \mu \cdot \dot{x}$. Ecuaţia diferenţială poate fi scrisă sub forma $\large m \cdot \ddot{x} + \mu \cdot \dot{x} + k \cdot x = 0$ care este o ecuaţie diferenţială de ordinul 2, liniară şi omogenă.

## Mişcarea pendulului simplu

Pendulul simplu este un punct material cu masa $m$ suspendat de o articulaţie fixă $\large O$ prin intermediul unui fir inextensibil şi fără greutate având lungimea $\large l$. La momentul $\large t = 0$, pendulul se află într-o configuraţie de repaus, în care firul formează cu verticala unghiul $\large \theta > 0$. Din această poziţie, el este lăsat să se mişte liber. În afară de greutatea proprie, asupra punctului material acţionează tensiunea din fir (vom neglija frânarea exercitată de aerul atmosferic). Aceste forţe definesc planul traiectoriei parcurse de pendul.

Simplificat, mişcarea punctului material poate fi descrisă cu ajutorul funcţiei $\large \theta = \theta(t),\ t \geq 0$ şi este reprezentată de ecuaţia diferenţială liniară şi omogenă $\large \ddot{\theta} + \frac{g}{\ell} \theta = 0 $.

## Mişcarea pendulului simplu în prezenţa frânării exercitate de aerul atmosferic

Vom relua exemplul precedent, ţinând cont şi de rezistenţa aerului atmosferic. Admitem că frânarea este proporţională cu viteza punctului material. De asemenea, adoptăm ipoteza micilor oscilaţii.

Model mathematic este $\large m\ell\ddot\theta + b\dot\theta + mg\theta = 0$ unde $\large b > 0$ este rezistenţa aerului (presupusă constantă). Pentru comoditatea calculelor, este convenabilă definirea coeficientului de frânare $\large \gamma = \frac{b}{2m\ell}$. Cu ajutorul acestei mărimi, ecuaţia diferenţială devine $\large \ddot\theta + 2 \gamma\dot\theta + \frac{g}{\ell}\theta = 0$.