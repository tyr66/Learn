[TOC]

# 对角化和矩阵乘幂
-----------


设矩阵$A$ 为一个$nxn$矩阵，并且它有$n$ 个线性无关的特征向量， 矩阵$S$ 为矩阵$A$ 的特征向量矩阵，特征向量矩阵
$S$ 为矩阵$A$的$n$ 个线性无关的特征向量按列组成的矩阵。矩阵$\Lambda$ 为对角矩阵，并且其对角线的元素为矩阵$S$ 中对应的特征向量的特征值。
<br></br>

## 1.矩阵的对角化
-------------

$$
AS = A\left[ \begin{array}{cccc}
\\
x_1&x_2&.......&x_n \\
\\
\end{array} \right] =
\left[\begin{array}{cccc}
\\
\lambda_1 x_1&\lambda_2 x_2&.....&\lambda_n x_n
\\ \\
\end{array} \right] \\ 

\left[\begin{array}{cccc}
\\
\lambda_1 x_1&\lambda_2 x_2&.....&\lambda_n x_n
\\ \\
\end{array} \right] = \left[ \begin{array}{cccc}
\\
x_1&x_2&.......&x_n \\
\\
\end{array} \right] \left[ \begin{array}{cccc}
\lambda_1&0&....&0 \\
0&\lambda_2&....&0 \\
...&...&...&... \\
0&0&...& \lambda_n
\end{array} \right]
$$

由上可知可以将$AS = S \Lambda$ ，矩阵$\Lambda=\left[ \begin{array}{cccc}\lambda_1&0&...&0 \\0&\lambda_2&....&0 \\...&...&...&... \\0&0&...& \lambda_n\end{array} \right]$，最终得到
如下两个方程
$$
\begin{array}{l}
\\S^{-1}AS = \Lambda \\\\
A = S\Lambda S^{-1}
\end{array}
$$


## 2.矩阵的幂
---------
对于矩阵$A^n$，由上述公式可知
$$
A^n = S \Lambda^n S^{-1}
$$

当矩阵$A$ 的所有特征值$\lambda_m < 1$ 的时候，矩阵$A^n$ 就越趋近 $0$。
因此对角化矩阵可以很简单的求解矩阵的幂问题。

<br></br>

设方程为$u_{k+1} = Au_k$则u_k的通项公式为
$$
u_k = A^ku_0
$$

因为向量$u_0$ 一定在矩阵$A$的列空间中(因为矩阵$A$ 为一个方阵并且可逆，它的列空间就是整个$n$维空间)，而矩阵$A$ 存在$n$ 个线性无关的特征向量，这$n$个特征向量都在矩阵$A$ 的列空间中，所以它们可以组成该矩阵的列空间，所以$u_0$ 可以被分解为矩阵$A$特征向量的线性组合形式，如下所示。
$$
u_0 = c_1x_1+c_2x_2+....+c_nx_n
$$

那么通项公式可以被转化为
$$
Ax = \lambda x \\
A^2x = \lambda A x \\
A^2x = \lambda^2 x \\

Au_0 = c_1\lambda_1 x_1+c_2\lambda_2 x_2+....+c_n\lambda_n x_n \\

A^nu_0 = c_1\lambda_1^n x_1+c_2\lambda_2^n x_2+....+c_n\lambda_n^n x_n \\
u_n = A^nu_0 = \Lambda^nSc
$$

其中$c$ 为一个向量$c = \left[\begin{array}{c} c_1\\c_2\\...\\...\\c_n \end{array}\right]$

<br/>

## 3.斐波那契数列和矩阵的幂
----------

斐波那契数列的公式为
$$
\begin{array}{c}
F_0 = 0,F_1 = 1 \\
F_{n} = F_{n-1}+F_{n-2}
\end{array}
$$

上面的为斐波那契数列的代数形式，想要将其转化为矩阵乘积形式，考虑下列方程组
$$
\begin{array}{l}
F_{k+2} = F_{k+1}+F_{k} \\\\
F_{k+1} = F_{k+1}
\end{array}
$$

设向量$u_k = \left[\begin{array}{c} F_{k+1}\\F_{k} \end{array}\right]$ ，向量$u_{k+1} = \left[\begin{array}{c} F_{k+2}\\F_{k+1} \end{array}\right]$ ,矩阵$A = \left[\begin{array}{cccc} 1&1\\1&0\end{array}\right]$，上述方程可以转化为以下形式
$$

u_{k+1} = u_kA

$$

矩阵$A$ 为一个$2x2$ 方阵，其中的列向量线性无关，求其特征值

$$
det{(A - \lambda I)} = \left| \begin{array}{cccc}
 1-\lambda &1\\
 1&-\lambda
 \end{array} \right| =0
$$
解方程$\lambda(\lambda -1) -1 =0$ ，如下所示
$$
\begin{array}{c}
\lambda^2 - \lambda-1 = 0 \\\\
\lambda_1 = \frac{1+\sqrt{1+4}}{2} \approx 1.618 ,\lambda_2 = \frac{1-\sqrt{1+4}}{2} \approx -0.618
\end{array}
$$

因此特征值为 $\lambda_1 = 1.618 ,\lambda_2 = -0.618$ .又因为矩阵$A$ 和 向量$u_k$ 之间存在如下关系

$$
u_n = A^nu_0 = \Lambda^nSc \\
$$

因此
$$
u_n = c_1\lambda_1^n x_1+c_2\lambda_2^n x_2+....+c_n\lambda_n^n x_n
$$

$\lambda_1 = 1.618 ,\lambda_2 = -0.618$ 可以看出随着$n$ 增大 $\lambda_2$ 对$u_n$ 值的影响会越来越小最终会趋近于无穷小，也就是说数列的增长主要是$\lambda_1 = 1.618$ 起到主要作用，它反映了数列的增长趋势。

**可以看出矩阵特征值和数列之间的关系**