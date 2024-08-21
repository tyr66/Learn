[TOC]

# 矩阵的四个基本子空间

--------------



## 1矩阵的列空间(Column Space)

----------------

假设存在矩阵$A = \left[\begin{array}{cccc}1 & 4 \\2 & 4 \\3 & 1 \end{array}\right]$，该矩阵中的列向量分别为$\left[\begin{array}{c} 1 \\ 2 \\ 3 \end{array}\right],\left[\begin{array}{c} 4 \\ 4 \\ 1 \end{array}\right]$，这些列向量的线性组合可以组成一个向量空间记作$C(A)$，该向量空间为一个过原点的平面并且是$R^{3}$的一个子空间。$C(A)$被称为矩阵$A$的列空间。




### 1.1 使用矩阵的列空间理解Ax = b

--------------------

设$A = \left[ \begin{array}{cccc} 1&1&2\\ 2& 1&3 \\ 3& 1&4\\ 4&1&5 \end{array} \right]$ ,x = $\left[ \begin{array}{c} x \\ y \\ z \end{array}\right]$，b = $\left[\begin{array}{c} b_{1} \\ b_{2} \\ b_{3} \end{array}\right]$
$$
Ax = b =\left[ \begin{array}{cccc} 1&1&2\\ 2& 1&3 \\ 3& 1&4\\ 4&1&5 \end{array} \right]\left[ \begin{array}{c} x \\ y \\ z \end{array}\right] =\left[\begin{array}{c} b_{1} \\ b_{2} \\ b_{3} \end{array}\right]
$$


向量$x$起到对矩阵$A$的列向量进行线性组合的作用,那么想要$Ax = b$有解，当且仅当向量$b$在矩阵$A$的列空间中。





### 1.2 列向量的独立性

------------------

矩阵的列向量并非都对构成矩阵的列空间有作用，设矩阵$A = \left[ \begin{array}{cccc} 1&1&2\\ 2& 1&3 \\ 3& 1&4\\ 4&1&5 \end{array} \right]$ ，可以发现三个列向量存在如下关系
$$
\left[ \begin{array}{c} 1 \\ 2 \\ 3 \\ 4 \end{array}\right] +
\left[ \begin{array}{c} 1 \\ 1 \\ 1  \\ 1\end{array}\right] = 
\left[ \begin{array}{c} 2 \\ 3 \\ 4 \\ 5 \end{array}\right]
$$
在构成矩阵$A$的列空间时向量$\left[ \begin{array}{c} 2 \\ 3 \\ 4 \\ 5 \end{array}\right]$并没有起到作用，矩阵$A$的列空间由向量$\left[ \begin{array}{c} 1 \\ 2 \\ 3 \\ 4 \end{array}\right]$和向量$\left[ \begin{array}{c} 1 \\ 1 \\ 1  \\ 1\end{array}\right]$的线性组合构成，这时候列向量$\left[ \begin{array}{c} 1 \\ 2 \\ 3 \\ 4 \end{array}\right]$和$\left[ \begin{array}{c} 1 \\ 1 \\ 1  \\ 1\end{array}\right]$为矩阵$A$的**主列**并且互相独立的。




<br></br>


## 2. 矩阵的零空间(Null Space)

------------------

设$A = \left[ \begin{array}{cccc} 1&1&2\\ 2& 1&3 \\ 3& 1&4\\ 4&1&5 \end{array} \right]$ ,x = $\left[ \begin{array}{c} x \\ y \\ z \end{array}\right]，b = \left[ \begin{array}{c} 0 \\ 0 \\ 0\\0 \end{array}\right]$

矩阵$A$的零空间表示为使方程$Ax = 0$成立时，向量$x$ 组成的向量空间，记作$N(A)$。
$$
\left[ \begin{array}{cccc} 1&1&2\\ 2& 1&3 \\ 3& 1&4\\ 4&1&5 \end{array} \right]\left[ \begin{array}{c} x \\ y \\ z \end{array}\right] = \left[ \begin{array}{c} 0 \\ 0 \\ 0\\0 \end{array}\right]
$$


此处要让方程成立只需要让$x = c\left[ \begin{array}{c} 1 \\ 1 \\ -1 \end{array}\right]$,c为任意实数。很明显向量$c\left[ \begin{array}{c} 1 \\ 1 \\ -1 \end{array}\right]$可以构成三维空间$R^{3}$中一条过原点的直线，很明显这条直线为 向量空间$R^{3}$的一个子空间。







<br></br>

## 3.矩阵的行空间(Row Space)

-----------------

矩阵的行空间为矩阵中的行向量组成的向量空间，矩阵的行空间等价于矩阵转置后的列空间。

设存在$mxn$矩阵$A$，则矩阵$A$的行空间等于$C(A^{T})$





<br></br>


## 4.矩阵的左零空间(Left Null Space)

----------

设存在$mxn$矩阵$A$，行向量$x$，矩阵$A$的左零空间为让方程 $xA = 0$ 成立的所有向量$x$组成的空间。

矩阵的左零空间等价于矩阵转置后的零空间记作 $N(A^{T})$。

对于所有在左零空间中的向量$x$ 有如下关系
$$
A^Tx = 0
$$





### 4.1 左零空间的求解

------------

求解矩阵的左零空间，可以将矩阵转置，然后求解矩阵$A^T$的零空间。但是也可以将矩阵转化为简化行阶梯矩阵的形式来求解。

设矩阵$A = \left[\begin{array}{cccc} 1&2&3&1 \\ 1&1&2&1 \\1&2&3&1 \\ \end{array}\right]$ ,对矩阵$A$进行消元转变为简化 行阶梯矩阵$R = \left[\begin{array}{cccc} 1&0&1&1 \\ 0&1&1&0 \\ 0&0&0&0 \end{array}\right]$ ，**消元的过程实际上是进行行变换，行变换并不会改变矩阵的行空间**，可以看到矩阵$R$ 中某些行变成了零向量，这些零向量都是由其他行变量进行线性组合得到的，这其实就是方程$yA = 0$的一个解，那么怎么知道这些线性组合是什么呢？其实这些线性组合就在消元矩阵$E$，通过Gauss-jordan  消元法可以获得矩阵$E$ ，如下所示。


$$
\left[\begin{array}{c} A&I \end{array}\right] \rightarrow 
\left[\begin{array}{c} R&E \end{array}\right]
$$


最终可以得到矩阵$E= \left[\begin{array}{cccc} -1&2&0 \\ 1&-1&0 \\ -1&0&1 \end{array}\right]$ ,矩阵$E$ 的第三个行向量既为方程$yA = 0$ 的一个解，并且是矩阵$A$ 左零空间的一个特解，通过这种方式就可以找到矩阵$A$ 左零空间的所有特解。**但一般还是将矩阵进行转置后然后求其零空间**










<br></br>


## 5.矩阵四个子空间的特性

------------

### 5.1 四个基本空间的维数

----------------

设存在$mxn$矩阵$A$，该矩阵的秩为$r$。

- 对于列空间 $C(A)$	
	-  列空间存在于 $R^m$ 空间中
	-  列空间为 $r$ 维空间



- 对于行空间 $C(A^T)$	

  - 行空间存在于 $R^n$ 空间中

  - 行空间为 $r$ 维空间



- 对于零空间$N (A)$	

  - 零空间存在于 $R^n$ 空间中

  - 零空间为 $n- r$ 维空间



- 对于左零空间$N (A^T)$	
  -  列空间存在于 $R^m$ 空间中
  -  列空间为 $m -r$ 维空间





### 5.2 矩阵变换后基本子空间的改变

------------

- **行变换可能改变矩阵的列空间，但是不会改变矩阵的行空间**
- **列变换可能改变矩阵的行空间，但是不会改变矩阵的列空间**

一个矩阵经过行变换后，矩阵的基本空间可能会发生改变。设存在矩阵$A = \left[\begin{array}{cccc} 1&2&3&1 \\1&1&2&1 \\1&2&3&1\\ \end{array}\right]$

将矩阵$A$ 变换为简化行阶梯矩阵$R$ 后
$$
R = \left[\begin{array}{cccc}
1&0&1&1 \\ 
0&1&1&0 \\
0&0&0&0
\end{array}\right]
$$
可以发现向量$\left[\begin{array}{c} 1\\1\\1\end{array}\right]$ 存在于矩阵$A$ 的列空间中，但是却不存在于矩阵$R$ 的列空间中, 矩阵 $R$ 中的所有列向量的线性组合是不可能得到向量$\left[\begin{array}{c} 1\\1\\1\end{array}\right]$。因此可以得出
$$
C(R) !=C(A)
$$

**行变换改变了矩阵的列空间**

那么对于行空间，行变换是否会改变矩阵的行空间呢？

可以很容易的看出矩阵$R$ 行空间的基为$\left[\begin{array}{c} 1&0&1&1 \end{array}\right] ,\left[\begin{array}{c} 0&1&1&0 \end{array}\right]$ ,矩阵$A$ 行空间的基为$\left[\begin{array}{c} 1&2&3&1 \end{array}\right] ,\left[\begin{array}{c} 1&1&2&1 \end{array}\right]$ .它们之间存在如下关系
$$
\left[\begin{array}{c} 1&0&1&1 \end{array}\right] +
2\left[\begin{array}{c} 0&1&1&0 \end{array}\right] =
\left[\begin{array}{c} 1&2&3&1 \end{array}\right] \\
\left[\begin{array}{c} 1&0&1&1 \end{array}\right] +
\left[\begin{array}{c} 0&1&1&0 \end{array}\right] =
\left[\begin{array}{c} 1&1&2&1 \end{array}\right]
$$
矩阵$A$ 的行空间等于矩阵$R$ 的行空间，可以看出

**行变换不改变矩阵的行空间,行变换实际上是矩阵中各个行向量的线性组合，所以行变换并不会改变矩阵的行空间**