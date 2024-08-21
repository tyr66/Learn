[TOC]
# 矩阵乘法和逆

-------------------

假设有矩阵$A$，矩阵$B$，矩阵$C$。$A*B = C$

矩阵A为：
$$
A = 
\left[\begin{array}{cccc}
2 & 7 \\
3 & 8 \\
4 & 9 \\
\end{array}\right]
$$

矩阵$B$为：

$$
B = 
\left[\begin{array}{cccc}
1 & 6 \\
0 & 0 \\
\end{array}\right]
$$

则矩阵$C$为：
$$
C = 
\left[\begin{array}{cccc}
2 & 7 \\
3 & 8 \\
4 & 9 \\
\end{array}\right]
\left[\begin{array}{cccc}
1 & 6 \\
0 & 0 \\
\end{array}\right] = 
\left[\begin{array}{cccc}
2 & 12 \\
3 & 18 \\
4 & 24
\end{array}\right]
$$






## 1.矩阵乘法的五种形式

----------------

矩阵乘法有五种形式，这几种形式得到的结果都是完全一致的。通过这几种不同的形式，有时候可以更好的去理解问题。






### 1.1行向量乘以列向量形式
-----------------

**矩阵C中每一个元素为矩阵A的行向量乘以矩阵B的列向量的值**

最终$A*B =C$ 中   $C$的每一元素的值可以通过下列的公式求得。



$$
\left[\begin{array}{cccc}
A_1 &A_2 \\
A_3 & A_4
\end{array}\right]
\left[\begin{array}{cccc}
B_1 &B_2 \\
B_3 & B_4
\end{array}\right]
 = 
 \left[\begin{array}{cccc}
A_1B_1+A_2B_3 &A_1B_2+A_2B_4 \\
A_3B_1+A_4B_3 & A_3B_2+A_4B_4
\end{array}\right]
$$

$$
C_{i j} = (A B)_{i j}=\sum_{k=1}^{p} a_{i k} b_{k j}=a_{i 1} b_{1 j}+a_{i 2} b_{2 j}+\cdots+a_{i p} b_{p j}
$$





### 1.2列向量线性组合形式

------------

**列向量形式的矩阵乘法为：矩阵C中的列向量为矩阵A中列向量的线性组合**

矩阵$C$中的列向量为
$$
Column_1 = \left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array}\right]
Column_2 = \left[\begin{array}{c} 12 \\ 18 \\ 24 \end{array}\right]
$$


则矩阵C的列向量可以表示为：
$$
1 \left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array}\right] + 0 \left[\begin{array}{c} 7 \\ 8 \\ 9 \end{array}\right] = \left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array}\right] = Column_1
$$

$$
6 \left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array}\right] + 0 \left[\begin{array}{c} 7 \\ 8 \\ 9 \end{array}\right] = \left[\begin{array}{c} 12 \\ 18 \\ 24 \end{array}\right] = Column_2
$$

$$
\left[\begin{array}{cccc}
2 & 7 \\
3 & 8 \\
4 & 9 \\
\end{array}\right]
\left[\begin{array}{cccc}
1 & 6 \\
0 & 0 \\
\end{array}\right] = 
\left[\begin{array}{c}
\left(1 \left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array}\right] + 0 \left[\begin{array}{c} 7 \\ 8 \\ 9 \end{array}\right]\right) & 
\left(6 \left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array}\right] + 0 \left[\begin{array}{c} 7 \\ 8 \\ 9 \end{array}\right] \right)
\end{array}\right] = 
\left[\begin{array}{cccc}
2 & 12 \\
3 & 18 \\
4 & 24
\end{array}\right]
$$


### 1.3行向量线性组合形式

-------------

**行向量形式的矩阵乘法为：矩阵C中的行向量为矩阵B中行向量的线性组合**

矩阵$C$中的行向量为：
$$
\begin{array}{l}
Row_1 = \left[\begin{array}{c} 2 & 12  \end{array}\right] \\
Row_2 = \left[\begin{array}{c} 3 & 18  \end{array}\right] \\
Row_3 = \left[\begin{array}{c} 4 & 24  \end{array}\right]
\end{array}
$$

则矩$C$中的行向量可以用矩阵$B$ 中行向量的线性组合来表示：
$$
2 \left[\begin{array}{c} 1 & 6  \end{array}\right] + 
7  \left[\begin{array}{c} 0 & 0  \end{array}\right] =
\left[\begin{array}{c} 2 & 12  \end{array}\right] = Row_1 \\

3 \left[\begin{array}{c} 1 & 6  \end{array}\right] + 
8  \left[\begin{array}{c} 0 & 0  \end{array}\right] =
\left[\begin{array}{c} 3 & 18  \end{array}\right] = Row_2 \\

4 \left[\begin{array}{c} 1 & 6  \end{array}\right] + 
9  \left[\begin{array}{c} 0 & 0  \end{array}\right] =
\left[\begin{array}{c} 4 & 24  \end{array}\right] = Row_3
$$







### 1.4列向量乘以行向量形式

------------

**矩阵C为矩阵A中列向量乘以矩阵B中行向量的结果矩阵之和**

$$
A*B =
\left[\begin{array}{cccc}
2 & 7 \\
3 & 8 \\
4 & 9 \\
\end{array}\right]
\left[\begin{array}{cccc}
1 & 6 \\
0 & 0 \\
\end{array}\right] = 
\left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array} \right] 
\left[\begin{array}{c} 1 & 6 \end{array} \right] +
\left[\begin{array}{c} 7 \\ 8 \\ 9 \end{array} \right] 
\left[\begin{array}{c} 0 & 0 \end{array} \right] = 
\left[\begin{array}{cccc}
2 & 12 \\
3 & 18 \\
4 & 24
\end{array}\right]
$$

其中
$$
\begin{array}{l}
\left[\begin{array}{c} 2 \\ 3 \\ 4 \end{array} \right] 
\left[\begin{array}{c} 1 & 6 \end{array} \right] = 
\left[\begin{array}{cccc}
2 & 12 \\
3 & 18 \\
4 & 24
\end{array}\right] \\\\
\left[\begin{array}{c} 7 \\ 8 \\ 9 \end{array} \right] 
\left[\begin{array}{c} 0 & 0 \end{array} \right] = 
\left[\begin{array}{cccc}
0 & 0 \\
0 & 0 \\
0 & 0
\end{array}\right] \\
\end{array}
$$







### 1.5分块形式

-------------------

可以将矩阵分块，从而进行分块的矩阵乘法

设矩阵A为： 
$$
\left[\begin{array}{cccc}
A_1 & A_2 \\
A_3 & A_4 
\end{array}\right]
$$

矩阵B为：
$$
\left[\begin{array}{cccc}
B_1 & B_2 \\
B_3 & B_4 
\end{array}\right]
$$

则矩阵C为：
$$
\left[\begin{array}{cccc}
A_1 & A_2 \\
A_3 & A_4 
\end{array}\right]
\left[\begin{array}{cccc}
B_1 & B_2 \\
B_3 & B_4 
\end{array}\right] = 
\left[\begin{array}{cccc}
A_1 * B_1+A_2 * B_3  & A_1 * B_2+A_2 * B_4 \\
A_3 * B_1+A_4 * B_3  & A_3 * B_2+A_4 * B_4
\end{array}\right]
$$


<br></br>

## 2.矩阵的逆
-----------------

- **并非所有矩阵都有逆**
- **非方阵的矩阵没有逆矩阵**
- **奇异矩阵没有逆矩阵**
- **矩阵的行列式为0，则该矩阵没有逆矩阵**
- **能找到一个非零向量$x$ ，使得$Ax = 0$,则该矩阵没有逆矩阵**
- **Gauss-jordan 消元法能同时处理两个方程组**



### 2.1 矩阵没有逆的本质
---------------

并非所有矩阵都存在对应的逆矩阵，有许多情况下矩阵都不存在逆矩阵，例如奇异矩阵没有逆矩阵，行列式为0的矩阵没有逆矩阵等等。**矩阵不存在逆矩阵可以通过列向量或者行向量的形式来进行理解，当矩阵中的行向量或者是列向量存在共线的时候该矩阵不存在逆矩阵。**

如果能找到一个非零向量$x$，对于矩阵$A$ ,有$Ax = 0$ 成立。那么矩阵$A$ 不存在逆矩阵。

证明：

​	&ensp;反证法：假如能找到一个非零向量$x$，对于矩阵$A$ ,有$Ax = 0$ 成立	并且该矩阵存在逆矩阵$A^{-1}$

​	&ensp;则对于$Ax = 0$ ,有$A^{-1}Ax = 0$ ，则$x= 0$。

​	&ensp;和假设相矛盾。



### 2.3 矩阵与逆矩阵的左乘右乘
------------------
设矩阵$A$ 可逆并且逆矩阵为$A^{-1}$，它们之间关系如下。

$$
A^{-1}A = I
$$

则
$$
AA^{-1} = I
$$
是否成立呢？


假设矩阵 $B，C$ 分别为矩阵A的右乘逆矩阵和左乘逆矩阵。
$$
AB = I \\
CA = I \\
(CA)B = C(AB)
$$

可以得出$B = C$ ，矩阵的左乘逆矩阵和右乘逆矩阵是相等的。







### 2.2 Gauss-jordan 消元法求逆
------------------

设矩阵A为：
$$
A = 
\left[\begin{array}{cccc}
1 & 3 \\
2 & 7 \\
\end{array}\right]
$$

矩阵A 的逆矩阵为 $A^{-1}$ 为：
$$
A^{-1} = 
\left[\begin{array}{cccc}
a & c \\
b & d \\
\end{array}\right]
$$

则有：
$$
A^{-1}A = I
$$

设**增广矩阵**为：
$$
\left[\begin{array}{c} A & I \end{array}\right] = 
\left[\begin{array}{cccc}
1 & 3 & 1 & 0 \\
2 & 7 & 0 & 1 
\end{array}\right]
$$

将**增广矩阵**中**A**的部分消元成矩阵**I**：可得

$$
\left[\begin{array}{c} I & A^{-1} \end{array}\right] = 
\left[\begin{array}{cccc}
1 & 0 & 7 & -3 \\
0 & 1 & 2 & 1 
\end{array}\right]
$$

矩阵$A^{-1}$为：
$$
A^{-1} = 
\left[\begin{array}{cccc}
 7 & -3 \\
 2 & 1 
\end{array}\right]
$$


我们在将**增广矩阵**中**A**的部分消元成**I**的过程实质上就是乘以**消元矩阵**。该**消元矩阵**使得 $EA = I，EI = E$。所以该消元矩阵就为矩阵A的逆矩阵。


