---

title: Introduction to Analysis II
tags: 2020, LinearAlgebra, NCTU 
author : maxwill lin, yan-tong lin
description :  Introduction to Analysis II

---

# Introduction to Analysis II

[TOC]

## week 1-1 (3/3/2020)

### Reimann Intergral
* partition and refinement
    * refinement = add points to partition
* definition of Reimann sum ($U_f(P), L_f(P), R_f(P)$)
    * show  $L_f(P) \le L_f(Q)$ and $U_f(P) \ge U_f(Q)$
    * hint : $Q = P \cup (Q-P)$ 
* Reimann intergral
* Reimann intergrability 
:::info
Proof of Prop. 31.3

31.3.1
since f is $bounded$, by the $completeness$ of $R$,
$m_i \le f(x_i) \le M_i$ are all well defined.


31.3.2

:::

## Week 1-2

### Reimann Intergrability
* http://home.iitk.ac.in/~psraj/mth101/lecture_notes/lecture15-16.pdf
* inf and suf and reimann intergral definition
* ![](https://i.imgur.com/6cBS3AF.png)
### refinement
![](https://i.imgur.com/XYx6J5Y.png)
Note: proof of equivalence part use the property of inf and sup 
![](https://i.imgur.com/U8VwsNN.png)
![](https://i.imgur.com/7CYSkNE.png)

### boundedness and monotonicity => integrability
* P = $\{a=x_0<x_1<...<x_n=b\}$ where $x_i = a+i\frac{b-a}{n}$
* $U_f(P) - L_f(P) = \frac{b-a}{n}[f(b)-f(a)]$
* Q.E.D
* end of class

## Week 1-3(3/5/2020)

### part 1 (pdf 32)
### Theorem 32.4 : **continuity** on a **closed** interval => **integrability**
* closed and bounded on $R$ $\implies$ compact
* teacher hint : **continuity and compact** relation
* [review: compact - f(cont.) -> compact](https://proofwiki.org/wiki/Continuous_Image_of_Compact_Space_is_Compact)
    * not used here
* Theorem 11.3 says [f is continuous on a compact space then it is uniformly continuous](https://math.stackexchange.com/questions/110573/continuous-mapping-on-a-compact-metric-space-is-uniformly-continuous)
* $f$ is $uniformly\ continuous$ on $[a, b]$
* the left is trivial
* let P be a partition with $|x_{i+1}-x_i|\lt\delta$
* then $M_i-m_i \le \epsilon\ \forall i$ by uniform continuouity
* (actually) $\forall \epsilon\ \exists \delta$
* then $U_f(P) - L_f(P) = \sum (M_i-m_i)*(x_i-x_{i-1})$
* $\le \epsilon \sum (x_i-x_{i-1})$
* $= \epsilon (b-a)$
* then for more formal proof replace $\epsilon$ with $\frac{\epsilon}{3*(b-a)}$
* $Q.E.D.$


### Theorem 32.5 (**the Intergrability Theorem**)
* $If\ f\ :\ [a, b]\rightarrow\mathbb{R}\ be\  continous\ at\ all\ except\ finite\ many\ points\ in\ [a,b]$
* $then\ f\ is\ Reimann\ integrable\ on\ [a,b]$
* proof:
* key idea : remove not continous points
* let M, m be global $suf$ $inf$
* reduce to $((M-m)+(b-a))*\epsilon$
<!--
* {not continous points} finite => exist M, m
-->

* To review, when will $Min, Max$ exist
    * compact in $\mathbb{R}$, closed and bounded
    * idea : proof $I$ bounded + $sup/inf \in I$?

### Definition 32.6 (content zero and measure zero)
* see pdf definition
* show $\{\frac{1}{n}\mid n\in\mathbb{N}\}$ is content zero
    * only finite elements out of $epsilon$ range
* show Q is measure zero
    * show that length of ${\bigcup^{\infty}_{0}}I_i$ is finite(by $\epsilon(1+\frac{1}{2}+\frac{1}{4}+...)$ trick

### Theorem 32.7 (contious except content zero implies integrability)
* similar method with 32.5
* sketch of proof
* try to remove the points like we did in Theorem 32.5
* use definition of content zero
* show $[a,b]-{\bigcup^{k}_{0}}I_i$ is compact by removing boundary of $I_i$

### Theorem 32.8 (the Riemann-Lebesgue theorem in one variable: Lebesgue’s criterion for Riemann-integrability)
* mentioned, will cover if have time
* Theorem 32.9 : my guess by substraction and 32.5
* Theorem 33.1 (the fundamental theorem of calculus) 


## Week 2-1(03/10/2020)

### Theorem 33.1 (the fundamental theorem of calculus)
* part1
* proof sketch:
    * Riemann integrable $\implies$ **bounded** on $[a,b]$
    * $\exists M > 0 \ni |f(t)| \le M \forall t \in (a,b)$
    * then uniform continuity on $[a, b]$ is trivial
        * $\forall x,y \in [a,b] \ni |x-y|<\delta$
        * $|\int_{a}^{x}f(t)dt - \int_{a}^{y}f(t)dt| \le M*\delta$
        * $\epsilon - \delta$ trick, M is constant
    * def of **f continuous**
    * $for\ x \in [a,b] \ni x > x_0$
    * **express** $f(x_0)$ as $f(x_0)\frac{\int_{x0}^{x}1dt}{x-x_0} = \frac{\int_{x0}^{x}f(x_0)dt}{x-x_0}$
    * we have $\frac{\int_{a}^{x}f(t)dt - \int_{a}^{x0}f(t)dt}{x-x_0} - f(x_0) = \frac{\int_{a}^{x}f(t)dt - \int_{a}^{x0}f(t)dt}{x-x_0} - \frac{\int_{x0}^{x}f(x_0)dt}{x-x_0}$
    * thus if $x \in [a,b] \ni x_0<x<x_0+\delta$
    * then $|\frac{\int_{a}^{x}f(t)dt - \int_{a}^{x0}f(t)dt}{x-x_0} - \frac{\int_{x0}^{x}f(x_0)dt}{x-x_0}| = |\frac{\int_{x_0}^{x}f(t)-f(x_0)dt}{x-x_0}| \le \frac{\int_{x_0}^{x}|f(t)-f(x_0)|dt}{|x-x_0|}$
    * since f is continuous
    * $\frac{\int_{x_0}^{x}|f(t)-f(x_0)|dt}{|x-x_0|} < \frac{\int_{x_0}^{x} \epsilon dt}{x-x_0} = \epsilon$
    * $x < x_0$ case can be done similarly
    * above proves $$\frac{d}{dt}(\int_{a}^{x}f(t)dt)\mid_{x=x_0} = f(x_0)\ \forall x_0\ at\ which\ f\ is\ continous$$
* part2 : $\int_{a}^{b}f(t)dt = F(b)-F(a)$
* proof sketch:
    * by def $\forall \epsilon \exists\ partition\ P \ni U_f(P)-L_f(P) < \epsilon$ 
    * make a **refinement Q of P to exlude finite indifferentiable points** 
    * apply **MVT**(mean value theorem) to intervals
        * $F(b)-F(a) = \sum F(x_i)-F(x_{i-1})$
        * = $\sum F^{'}(t_i)(x_i-x_{i-1})$
        * = $\sum f(t_i)(x_i-x_{i-1})$
    * $L_f(Q) \le F(b)-F(a) \le U_f(Q)$
    * $L_f(P) \le \int_{a}^{b}f(t)dt \le U_f(P)$
    * then $|\int_{a}^{b}f(t)dt-(F(b)-F(a))| < \epsilon$

## Week 2-2 ()
* 