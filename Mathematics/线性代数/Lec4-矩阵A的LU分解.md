[TOC]

#  矩阵A的LU分解

--------------------

在线性代数中，LU分解(LU Factorization) 是矩阵分解的一种，可以将一个矩阵分解为一个单位下三角矩阵和一个上三角矩阵的乘积(有时候还需要乘以一个置换矩阵)。LU分解主要应用在数值分析中，用来解线性方程、或计算行列式。




## 1.不存在行交换的LU分解

----------------------

假设存在可逆矩阵$A$。
$$
A = 
\left[\begin{array}{cccc}
2 & 1 \\
8 & 7
\end{array}\right]
$$



通过高斯消元法可以将矩阵$A$转化成一个上三角矩阵$U$
$$
EA = U =
\left[\begin{array}{cccc}
1 & 0 \\
-4 & 1
\end{array}\right]
\left[\begin{array}{cccc}
2 & 1 \\
8 & 7
\end{array}\right] = 
\left[\begin{array}{cccc}
2 & 1 \\
0 & 3
\end{array}\right]
$$
其中 $E = \left[\begin{array}{cccc}1 & 0 \\-4 & 1\end{array}\right]$，$U =\left[\begin{array}{cccc}2 & 1 \\0 & 3\end{array}\right]$ ，$E$为消元矩阵，一定可逆，且为单位下三角矩阵。等号左边和右边各左乘矩阵$E$的逆矩阵 $E^{-1}$可得
$$
A = E^{-1}U =
\left[\begin{array}{cccc}
2 & 1 \\
8 & 7
\end{array}\right] = 
\left[\begin{array}{cccc}
1 & 0 \\
4 & 1
\end{array}\right]
\left[\begin{array}{cccc}
2 & 1 \\
0 & 3
\end{array}\right]
$$


因为$E^{-1}$为一个单位下三角矩阵，将$E^{-1}$记作$L$可得
$$
A = LU
$$


由此一个可逆矩阵可以被分解为一个单位下三角矩阵和一个上三角矩阵的乘积。




<br></br>


## 2.存在行交换的LU分解

--------------

当矩阵$A$在进行消元的时候，需要进行行交换(Row Exchange)。此时的LU分解就变为
$$
PA = LU
$$
矩阵$P$为置换矩阵，矩阵$L$为单位下三角矩阵，矩阵$U$为上三角矩阵。等号左右两边左乘矩阵$P$的逆矩阵可得。
$$
A =P^{-1}LU
$$
因为 矩阵$P$为置换矩阵，所以其转置矩阵就为其逆矩阵$P^{-1} = P^{T}$，可得
$$
A =P^{T}LU
$$


**只有在行交换之后，矩阵中主元(Pivot)才不为0，高斯消元法才可以正确进行。**





























