---

title: Linear Algebra II
tags: 2020, LinearAlgebra, NCTU 
author : maxwill lin, yan-tong lin
description :  Linear Algebra II

---

# Linear Algebra II

[TOC]


## week 1-1 (3/2/2020)

* review
    * linear independency
    * basis and dimension
    * dimension theorem
    * direct sum
    * matrix representation :
     $$
     Rep_{\alpha,\beta}(T) = (Rep_\beta(T(\vec{\alpha_1}) ...Rep_\beta(T(\vec{\alpha_i}))
     $$
    * change of basis
     $$
     Rep_\alpha(T) = Rep_{\beta,\alpha}(id)Rep_\beta(T)Rep_{\alpha,\beta}(id)
     $$
    * determinant
    * Invariant Subspace
        * direct sum of it
    * Eigenspace
* attendence 10%
* next quiz hint:
    * matrix representation + diagonization
* lecturing
    * $T:V\rightarrow V$ be linear transformation
    * For $\vec{v} \in V$ what is the smallest T-invariant subspace?
    * Theorem :
    ::: info
    let $W = span\{v, T(v), T^2(v), T^3(v)...\}$ 
    then 
    1. $W$ is a F-invariant subspace
    2. let $dim(W) = m$, then $$\alpha = \{ \vec{v} , T(\vec{v}), T^2(\vec{v}), ...T^{m-1}(\vec{v})\}$$ is a basis of $W$
    4. $T^m(\vec{v}) = \sum a_iT^i(\vec{v})$
    5. $Rep_{\alpha}(T)$ = \begin{bmatrix}
                           0 & 0 & ...& a_0 \\
                           1 & 0 & ...& a_1 \\
                           0 & 1 & ...& ...\\
                           0 & 0 & ...& a_{m-1}
                        \end{bmatrix} 
    6. determinant and characristic function by MI

    :::
    
    ::: info
    Proof:
        1. By definition : $W = span\{w, T(w), T^2(w), T^3(w)...\}$
        2. some $k\ s.t. T^k \in span\{w, T(w), T^2(w), T^3(w)...T^{k-1}(w)\}$ exist for V is finite-dimentional
        3. $T^k(w)$ is linear combination of $\alpha$
        4. by induction , $T^{n}$ with $n > k$ is too
        5. then $T(\vec{w}) \in W$ is trivial
    :::
    * asked teaher for concept confirmation

