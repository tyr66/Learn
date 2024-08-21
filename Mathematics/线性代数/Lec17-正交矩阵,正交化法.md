[TOC]



# 正交矩阵,正交化

--------------

标准正交基可以让许多问题的计算大大简化，线性代数中的许多问题都是建立在标准正交基下的。


## 1.正交矩阵
-------------

<br></br>

### 1.1 正交矩阵的性质

--------------------

假设存在一组标准正交基向量$q_1,q_2,q_3.....q_n$ ，让这些向量组成一个矩阵$Q = \left[\begin{array}{cccc} q_1&q_2&q_3.....q_n \end{array}\right]$ 对于矩阵$Q$ 由如下性质。
$$
Q^TQ = I
$$

$$
\left[\begin{array}{cccc}
q_1 \\q_2\\q_3\\....\\...\\q_n
\end{array}\right]
\left[\begin{array}{cccc} q_1&q_2&q_3.....q_n \end{array}\right] = I
$$


如果矩阵$Q$ 是一个方阵，并且矩阵$Q$ 中的列向量是一组标准正交基，那么矩阵$Q$ 被称为**正交矩阵**





### 1.2 正交矩阵的性质

--------------

- 正交矩阵$Q$ ， $Q^T = Q^{-1}$
- 正交矩阵$Q$ 中的列向量为一组标准正交基





### 1.3 正交矩阵的作用

-------------

在将一个向量投影到某个矩阵的列空间的时候，可以使用如下公式。
$$
A^TAx = A^Tb
$$
当矩阵$A$ 为一个正交矩阵的时候，上述公式被简化为：
$$
x = A^Tb
$$
可以看到如果能将矩阵转变为一个正交矩阵的同时，不改变该矩阵的列空间那么就能大大的简化投影的运算。

<br></br>

## 2.矩阵正交化

-----------





### 2.1 格拉姆-斯密特 正交化法

------------

设有一组线性无关的向量$a_1,a_2,a_3,........,a_n$ ，这些向量组成矩阵$A = \left[\begin{array}{cccc} a_1&a_2&a_3 &.....& &a_n\end{array}\right]$ 正交化矩阵$A$ 是指将矩阵$A$ 中的列向量转变为一组标准正交基。



**列向量正交化**

考虑向量$a_1$ ，它为矩阵中的第一个列向量，它保持不变。
$$
\hat{a_1} = a_1
$$


考虑向量$a_2$ ，它为矩阵中的第二个向量，它必须与向量$\hat{a_1}$ 垂直，想要让向量$\hat{a_2}$ 垂直$\hat{a_1}$ 只需将其投影到向量$\hat{a_1}$ 组成的空间上，然后求其和该空间的垂线，如下所示。
$$
\hat{a_2} = a_2 - \frac{\hat{a_1}^T a_2}{\hat{a_1}^T \hat{a_1}}\hat{a_1}
$$
如果向量$\hat{a_2}$ 垂直于向量$\hat{a_1}$ ，它们之间一定有$\hat{a_1}^T\hat{a_2} = 0$  如下所示。
$$
\hat{a_1}^T\hat{a_2} = \hat{a_1}^T(a_2 -\frac{\hat{a_1}^T a_2}{\hat{a_1}^T \hat{a_1}}\hat{a_1})\\
$$
 $\hat{a_1}^T\hat{a_2}$ 为一个数字，并非向量。因此可以进行乘积顺序的调整
$$
\hat{a_1}^T\hat{a_2} = \hat{a_1}^T(a_2 -\frac{\hat{a_1}^T a_2}{\hat{a_1}^T \hat{a_1}}\hat{a_1})\\

\hat{a_1}^T\hat{a_2} = \hat{a_1}^T(a_2 -\frac{\hat{a_1}}{\hat{a_1}^T \hat{a_1}}\hat{a_1}^Ta_2)\\

\hat{a_1}^T\hat{a_2} = \hat{a_1}^Ta_2 - \hat{a_1}^Ta_2 = 0
$$
因此$\hat{a_1}^T\hat{a_2} = 0$ 向量$\hat{a_1}$ 和 $\hat{a_2}$ 互相垂直。



考虑向量$a_3$ ，它需要和向量$\hat{a_1}$ 以及向量$\hat{a_2}$ 垂直，则它的正交化公式为：
$$
\hat{a_3} = a_3 - \frac{\hat{a_1}^Ta_3}{\hat{a_1}^T \hat{a_1}}\hat{a_1} -  \frac{\hat{a_2}^Ta_3}{\hat{a_2}^T \hat{a_2}}\hat{a_2}
$$
向量$\hat{a_3}$ 和向量$\hat{a_1},\hat{a_2}$ 垂直，则必有 $\hat{a_1}^T\hat{a_3} = 0 , \hat{a_2}^T\hat{a_3} = 0$ 。证明方法和上述一致,不再阐述。因此向量$\hat{a_3}$ 和向量$\hat{a_1},\hat{a_2}$ 垂直。



对于向量$a_n$ 它的正交化公式为：
$$
\hat{a_n} = a_n -\frac{\hat{a_1}^Ta_n}{\hat{a_1}^T \hat{a_1}}\hat{a_1}-\frac{\hat{a_2}^Ta_n}{\hat{a_2}^T \hat{a_2}}\hat{a_2} - ......-\frac{\hat{a_{n-1}}^T a_{n}}{\hat{a_{n-1}}^T \hat{a_{n-1}}}\hat{a_{n-1}}
$$




**列向量标准化**

将向量组$a_1,a_2,a_3,........,a_n$ 正交化为向量组$\hat{a_1},\hat{a_2},\hat{a_3},.........,\hat{a_n}$ 后再将其标准化，将其中的每一个 向量转变为长度为1的向量。此时就会生成一组标准正交基$q_1,q_2,q_3,.......,q_n$ 如下所示。


$$
q_1 = \frac{\hat{a_1}}{||\hat{a_1}||} \\
q_2 = \frac{\hat{a_2}}{||\hat{a_2}||}\\
q_3 = \frac{\hat{a_3}}{||\hat{a_3}||}\\
...\\
...\\
...\\
q_n = \frac{\hat{a_n}}{||\hat{a_n}||}
$$




此时矩阵$A = \left[\begin{array}{cccc} a_1&a_2&a_3 &.....& &a_n\end{array}\right]$  就被转变为一个正交矩阵$Q = \left[\begin{array}{cccc} q_1&q_2&q_3 &.....& &q_n\end{array}\right]$





### 2.2 正交化过程中列空间为何不变 

----------------

在矩阵$A$ 正交化过程中列空间是保持不变的，即矩阵$A$ 的列空间和矩阵$Q$ 的列空间相同。矩阵$A$ 转化为矩阵$Q$ 的过程其实就是矩阵$A$ 中列向量的线性组合，如下所示。
$$
\hat{a_n} = \textcolor{red}{a_n} -\frac{a_1^Ta_n}{a_1^Ta_1}\textcolor{red}{a_1}-\frac{a_2^Ta_n}{a_2^Ta_2}\textcolor{red}{a_2} - ......-\frac{a_{n-1}^Ta_n}{a_{n-1}^Ta_{n-1}}\textcolor{red}{a_{n-1}}
$$
可以发现向量$\hat{a_n}$ 是由矩阵$A$ 中的列向量线性组合而来。而且标准化向量的过程只改变了列向量的长度，而没有改变列向量的方向，因此**矩阵$A$ 的列空间和矩阵$Q$ 的列空间相同。**



### 2.3 矩阵$A$ 的QR分解

-------------

由上述过程可知矩阵可以被分解为正交矩阵$Q$ 乘以矩阵$R$ 
$$
A = QR
$$
矩阵$R$ 是一个什么形式的矩阵呢？反过来思考上述的正交化过程。

对于向量$a_1$ ，$q_1 = a_1/||a_1||$ ，那么$a_1 = q_1||a_1||$。

对于向量$a_2$ ,$\hat{a_2} = a_2 - \frac{\hat{a_1}^T a_2}{\hat{a_1}^T \hat{a_1}}\hat{a_1}$ ,即$q_2||\hat{a_2}|| = a_2 - \frac{\hat{a_1}^Ta_2}{\hat{a_1}^T \hat{a_1}}\hat{a_1}$  可得


$$
\hat{a_2}+ \frac{\hat{a_1}^T a_2}{\hat{a_1}^T \hat{a_1}}\hat{a_1} = a_2 
$$
可以看出$a_2$ 是由向量$\hat{a_1},\hat{a_2}$ 线性组合而来，又因为$q_1 = \frac{\hat{a_1}}{||\hat{a_1}||},q_2 = \frac{\hat{a_2}}{||\hat{a_2}||}$ ，因此向量$a_2$  也可以说是由向量$q_1,q_2$ 线性组合而来。并没有涉及到向量$q_3 .... q_n$ ，对于其他的向量$a_n$同理， 因此**矩阵$R$是一个上三角矩阵**


$$
A = QR \\
Q^TA = R \\
R = Q^TA = \left[\begin{array}{lll} 
q_{1}^T \\  q_{2}^T \\ q_{3}^T
\end{array}\right]
\left[\begin{array}{lll}
a & b & c
\end{array}\right] = \left[\begin{array}{lll}
q_{1}^{\mathrm{T}} \boldsymbol{a} & \boldsymbol{q}_{1}^{\mathrm{T}} \boldsymbol{b} & \boldsymbol{q}_{1}^{\mathrm{T}} \boldsymbol{c} \\
& \boldsymbol{q}_{2}^{\mathrm{T}} \boldsymbol{b} & \boldsymbol{q}_{2}^{\mathrm{T}} \boldsymbol{c} \\
& & \boldsymbol{q}_{3}^{\mathrm{T}} \boldsymbol{c}
\end{array}\right]
$$
