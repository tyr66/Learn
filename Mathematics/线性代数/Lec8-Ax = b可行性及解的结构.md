[TOC]

# Ax = b 可行性及解的结构
-----------

设有方程组如下所示：
$$
x_1+2x_2+2x_3+2x_4 = b1 \\
2x_1+4x_2+6x_3+8x_4 = b2 \\
3x_1+6x_2+8x_3+10x_4 = b3
$$
转化为矩阵形式为：
$$
\left[\begin{array}{cccc}
1&2&2&2\\
2&4&6&8\\
3&6&8&10
\end{array}\right]
\left[\begin{array}{c}x_1\\x_2\\x_3\\x_4\end{array}\right] = 
\left[\begin{array}{c}b_1\\b_2\\b_3\end{array}\right]
$$

**想要方程有解那么向量$b$就必须在矩阵的列空间中**

<br></br>

## 1.求解过程
----------


### 1.1算法步骤
---------------

- 进行消元，转化为阶梯矩阵或者是简化行阶梯矩阵
- 找出矩阵中的主列和自由列
- 设所有的自由列对应的向量b中的分量为0
- 算出一个特解$x_P$
- 算出矩阵$A$的零空间所有特解的线性组合$x_n$
- 解为$x_p+x_n$







### 1.2求解例子

-----------------------



设向量$b = \left[\begin{array}{c} 1\\5\\6\\\end{array}\right]$，那么$Ax = b$为：

$$
\begin{array}{c}
Ax = b \\\\
\left[\begin{array}{cccc}
1&2&2&2\\
2&4&6&8\\
3&6&8&10
\end{array}\right]
\left[\begin{array}{c}x_1\\x_2\\x_3\\x_4\end{array}\right] = 
\left[\begin{array}{c}1\\5\\6\end{array}\right]
\end{array}
$$

对矩阵进行消元可得

$$
\left[\begin{array}{cccc}
1&2&2&2\\
0&0&2&4\\
0&0&0&0
\end{array}\right]
\left[\begin{array}{c}x_1\\x_2\\x_3\\x_4\end{array}\right] = 
\left[\begin{array}{c}1\\3\\0\end{array}\right]
$$

可以看出第2，4个列向量为自由列，第1,3列向量为主列，将自由列对应的$x_2,x_4$取0可以解出$Ax = b$的一个特解$x_p$


$$
x_p = \left[\begin{array}{c} -2 \\0\\ 3/2\\0 \end{array}\right]
$$
继续算出矩阵的零空间可得$x_n$
$$
x_n = cu+dv  =
c \left[\begin{array}{c} -2 \\1\\ 0\\0 \end{array}\right] +
d \left[\begin{array}{c} 2 \\0\\ -2\\1 \end{array}\right]
$$


因此方程的解为：
$$
x = x_p +x_n = \left[\begin{array}{c} -2 \\0\\ 3/2\\0 \end{array}\right]
+c \left[\begin{array}{c} -2 \\1\\ 0\\0 \end{array}\right] +
d \left[\begin{array}{c} 2 \\0\\ -2\\1 \end{array}\right]
$$




------------------------





## 2.为何方程的解为$x_p+x_n$
-------------
首先检验$x_p+x_n$是否为方程$Ax =b$的解
$$
A(x_p+x_n) = Ax_p+Ax_n \\
Ax_p = b \\
Ax_n = 0 \\
Ax_p+Ax_n = b+0 = b \\
A(x_p+x_n) = b
$$

可以看出$x_p+x_n$确实为方程的解

那么下一个问题时 $x_p+x_n$ 是否可以表示方程所有的解。
我们假设不能表示所有的解，即存在$x_q = x_p+x_m$，并且$x_m$ 不在矩阵$A$ 的零空间中。那么有如下所示方程

$$
\begin{array}{c}
Ax_q = A(x_p+x_m) = Ax_p+Ax_m\\\\
\end{array}
$$

因为$Ax_m!=0$，所以可以得出
$$
Ax_q = A(x_p+x_m) !=b
$$

假设不成立。

那么从向量的方面考虑$x_p+x_n$是否可以组合出所有符合$Ax = b$的向量$x$



----------------












