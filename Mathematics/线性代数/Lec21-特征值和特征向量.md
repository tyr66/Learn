[TOC]

# 特征值和特征向量

----------



设矩阵$A$ 为一个$nxn$ 方阵，存在方程$Ax = b$，向量$b$ 为任意向量，向量$x$ 也为任意向量，当向量$b$ 和向量$x$ 平行时有如下方程。
$$
A \boldsymbol{x}=\lambda \boldsymbol{x}
$$


其中$\lambda$ 为**特征值**，向量$x$ 为**特征向量**。




<br></br>
### 1.1 投影矩阵的特征值和特征向量

----------------

对于投影矩阵来说，有如下方程，矩阵$P$ 为某一个投影矩阵，向量$x$ 为需要投影的向量，向量$p$ 为投影之后的向量。
$$
Px = p
$$



那么当向量$x$ 已经位于投影空间的时候，$Px = x$ 此时特征值为1，特征向量为$x$。

当向量$x$ 和投影空间相正交的时候，$Px = 0$ ，此时特征值为0，特征向量为$x$。



**投影矩阵的特征向量有两类，一类是所有位于投影空间中的向量。一类是所有和该投影空间正交的向量。这两类特征向量的特征值分别为1和0**

<br></br>
### 1.2 矩阵的特征值有可能为虚数

-----------

设存在一个旋转矩阵$Q = \left[\begin{array}{cccc}
  0&-1\\1&0
\end{array}\right]$ ，矩阵特征值，特征向量的求解公式，如下所示。

$$
Qx = \lambda x
$$

从上述公式得几何意义思考矩阵$Q$的作用是旋转$90$度，旋转矩阵$Q$乘以一个向量后得到得结果向量是不可能和原向量平行的。求解它的特征值和特征向量如下所示。

$$
det{(Q - \lambda I)} = \left| \begin{array}{cccc}
-\lambda &-1\\ 1&-\lambda
\end{array}  \right| \\

\lambda ^2 = -1\\
\lambda_1 = i,\lambda_2 = -i
$$

由此可知矩阵$Q$ 的特征值为$i,-i$ ，为虚数。由此可知**矩阵的特征值有可能为虚数**

<br></br>

### 1.3 矩阵的特征值和特征向量的求法

-------------------
设存在一个方阵$A$,它有如下矩阵方程

$$
\begin{array}{c}
Ax = \lambda x \\\\
(A -\lambda I)x = 0
\end{array}
$$

**如果$x$ 有非零解，那么矩阵$(A-\lambda I)$一定为奇异矩阵**，也即是$det{(A-\lambda I)} = 0$



求矩阵$A = \left[\begin{array}{cccc}
3&1\\1&3
\end{array}\right]$的特征值和特征向量
$$
\begin{array}{c}
(A-\lambda I) = \left[\begin{array}{cccc}
3-\lambda&1\\
1&3-\lambda
\end{array}\right] \\\\
det{(A-\lambda I)} = (3-\lambda)^2-1 = 0 \\\\
(3-\lambda)^2-1  = \lambda^2-6\lambda+8 =(\lambda -4)(\lambda-2) = 0
\end{array}
$$
算得矩阵的$A$ 的特征值如下所示
$$
\lambda_1 = 4 \\
\lambda_2 = 2
$$
当$\lambda = 4$ 时，矩阵$(A-\lambda I) = \left[\begin{array}{cccc}-1&1\\1&-1\end{array}\right]$，因为有$\left(A- \lambda I \right)x = 0$ ，通过观察可以知道矩阵$\left(A - \lambda I\right)$的零空间为一条直线。只需要取其中的一个向量即可，这里取零空间中的向量 
$\left[ \begin{array}{cccc} 1\\1 \end{array} \right]$

当$\lambda = 2$ 时，矩阵$(A - \lambda I) = \left[\begin{array}{cccc}1&1\\1&1\end{array}\right]$ ,解得其零空间中得其中一个解为 $\left[\begin{array}{cccc} -1\\1\end{array}\right]$

因此矩阵$A$ 得特征向量为：
$$
\left[\begin{array}{cccc} 1\\1\end{array}\right],\left[\begin{array}{cccc} -1\\1\end{array}\right]
$$




## 2.特征值和特征向量的性质

-------------------

- 当矩阵$A$ 为一个奇异矩阵的时候，特征值为0

- $nxn$矩阵一定有$n$ 个特征值

- 矩阵特征值之和等于矩阵对角线元素之和，它们被称为**迹**

- 矩阵特征值之积等于矩阵的行列式

- 特征值不同的特征向量一定是互相独立的

  

 **为什么不同特征值对应的特征向量线性无关？**

- 代数上解答：首先我们对于矩阵A的特征值 $\lambda_{1}$, 有等式满足 $A x_{1}=\lambda_{1} x_{1}$, 特征向量为 $x_{1}$.
  对于特征值 $\lambda_{2}$, 有等式满足 $A x_{2}=\lambda_{2} x_{2}$ 。
  下面用反证法进行证明! 首先假设不同特征值对应的特征向量线性相关
  如果对于不同的 $\lambda_{1}, \quad \lambda_{2}$ 所对应的特征向量线性相关的话, 那么满足下面等式:
  $k_{1} x_{1}+k_{2} x_{2}=0$,那么等式两边同时乘以矩阵A, 得到 $A k_{1} x_{1}+A k_{2} x_{2}=0$,化简为:
  $\lambda_{1} k_{1} x_{1}+\lambda_{2} k_{2} x_{2}=0$, 又因为根据等式 $k_{1} x_{1}+k_{2} x_{2}=0$ 可以得到,
  $k_{2} x_{2}=-k_{1} x_{1}$, 带入到 $\lambda_{1} k_{1} x_{1}+\lambda_{2} k_{2} x_{2}=0$, 得到 $k_{1} x_{1}\left(\lambda_{1}-\lambda_{2}\right)=0$,又因头
  $\lambda_{1}, \quad \lambda_{2}$ 不相同, 则造成矛盾。
  所以不同特征值对应的特征向量线性相关是错误的。
- 几何上：从几何的角度出发，其实对理解更加有帮助。特征向量表示的是矩阵变换中只有伸缩变换没有旋转变换的方向向量，特征值是这个方向的伸缩系数，一个方向当然只有一个伸缩系数。