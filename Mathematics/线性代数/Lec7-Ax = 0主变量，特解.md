[TOC]

# Ax = 0的求解

-----------------



- **阶梯矩阵**
- **矩阵的秩**
- **自由列，主列**
- **简化行阶梯矩阵**
- **零空间矩阵**





## 1.零空间的求解

-------------

设矩阵$A = \left[\begin{array}{cccc} 1&2&2&2 \\ 2&4&6&8 \\ 3&6&8&10 \end{array} \right]$  ,如何求解$Ax = 0$，即求解矩阵$A$的零空间。



**算法步骤**

- **进行消元，将矩阵变为阶梯矩阵或者是简化行阶梯矩阵**
- **找到矩阵的主列和自由列**
- **找出零空间的所有特解**
- **所有特解的线性组合即为零空间**



### 1.1 进行消元

------------

$$
\begin{array}{r}
    
A =\left[\begin{array}{cccc} 1&2&2&2 \\ 2&4&6&8 \\ 3&6&8&10 \end{array} \right] \\\\
E_{1}A = \left[\begin{array}{cccc} 1&2&2&2 \\ 0&0&2&4 \\ 0&0&2&4 \end{array} \right] \\\\
U = E_{2}E_{1}A = \left[\begin{array}{cccc} 1&2&2&2 \\ 0&0&2&4 \\ 0&0&0&0 \end{array} \right] \\

\end{array}    

$$



此时矩阵$A$经过消元处理后，变成 了一个阶梯矩阵记作$U$

继续进行消元法可得,简化行阶梯矩阵记作$R$
$$
R =\left[\begin{array}{cccc} 
1&2&0&-2 \\ 
0&0&1&2 \\ 
0&0&0&0 
\end{array} \right]
$$
此时方程变为了$Ux = 0$ 或者是$Rx = 0$。



### 1.2 找出矩阵的主列和自由列

---------------

通过观察矩阵$U$，可以看出它的主元的有两个，一个为1，一个为2。**矩阵中主元的个数被称为秩。**
$$
U =  \left[\begin{array}{cccc} \textcolor{red}{1}&2&2&2 \\ 0&0&\textcolor{red}{2}&4 \\ 0&0&0&0 \end{array} \right] \\
$$
而秩所对应的列被称为主列，其他的列被称为自由列，如下标注红色的列为主列，标注蓝色的列为自由列。
$$
U =  \left[\begin{array}{cccc} 
\textcolor{red}{1}&\textcolor{blue}2&\textcolor{red}2&\textcolor{blue}2 \\
\textcolor{red}0&\textcolor{blue}0&\textcolor{red}{2}&\textcolor{blue}4 \\
\textcolor{red}0&\textcolor{blue}0&\textcolor{red}0&\textcolor{blue}0 
\end{array} \right] \\
$$
观察上图可知，第1，3个列向量为主列，第2，4个列向量为自由列。自由列对应的向量在形成矩阵的列空间中没有作用。





### 1.3 找出所有的特解

------------

方程转化为$Ux = 0$  或者$Rx = 0$后需要找出特解。特解本质上是矩阵零空间中那些互相独立的向量。

根据$Rx = 0$，可以进行方程的求解
$$
Rx = 0 = \left[\begin{array}{cccc} 
1&2&0&-2 \\ 
0&0&1&2 \\ 
0&0&0&0 
\end{array} \right]
\left[\begin{array}{c} 
x \\ y\\ z\\w
\end{array} \right] = 
\left[\begin{array}{c} 
0 \\ 0\\ 0\\ 0
\end{array} \right]
$$

$$
x+2y-2w = 0 \\
z+w = 0
$$


因为第1，3个列向量为主列，第2，4个列向量为自由列。向量$x$中y,w分量对应矩阵中的自由列，它们可以取任意实数。这里分为$y = 1,w = 0$和$y = 0,w = 1$两种情况，这样就可以求出两个解,如下所示。
$$
x_1 = \left[
\begin{array}{c}
-2 \\1 \\0 \\0
\end{array}
\right]，
x_2 = \left[
\begin{array}{c}
2 \\0 \\-2 \\1
\end{array}
\right]
$$


这两个解被称为特解。





### 1.4 特解的线性组合即为零空间

-------------

找到所有特解后，方程$Ax = 0$的解为所有特解的线性组合，所有的解都可以由特解的线性组合得出，该线性组合构成了矩阵$A$的零空间$N(A)$
$$
x = cx_1+dx_2 =
c\left[
\begin{array}{c}
-2 \\1 \\0 \\0
\end{array}
\right] +d\left[
\begin{array}{c}
2 \\0 \\-2 \\1
\end{array}
\right]
$$









---------------------











## 2.为何特解的线性组合即为方程组的解呢？



思考一下，我们想要解$Ax = 0$ 本质上就是要让主列的向量线性组合出和自由列向量方向相反的向量，这样所有列向量加起来就是一个零向量。这样就可以根据特解的数量，来分为各种情况。例如所有的主列向量线性组合为第一个自由列向量，或者是所有的主列向量线性组合为第二个自由列向量，而这些所有情况中得出的解就组成了零空间中所有线性无关的向量。

