[TOC]

# 马尔科夫链和傅里叶级数
--------------


## 1.马尔科夫链
------------





### 1.1 马尔科夫矩阵的性质

-------------------


一个典型的马尔科夫矩阵如下所示
$$
A = \left[\begin{array}{cccc}
0.1&0.01&0.3\\
0.2&0.99&0.3\\
0.7&0&0.4
\end{array}\right]
$$

该马尔科夫矩阵满足以下几个性质
1. 所有元素大于等于0
2. 每一个列向量的分量之和为1
3. $\lambda =1$ 为矩阵的特征值
4. 其它所有特征值的绝对值$|\lambda_i|$小于1




$$
u_k = A^nu_0 = c_1\lambda_1^n x_1+c_2\lambda_2^n x_2+....+c_n\lambda_n^n x_n
$$

设$\lambda_1 = 1$ ，则随着$n$ 增大上述的公式转化为下述公式
$$
A^nu_0 = c_1\lambda_1^n x_1
$$

那么向量$c_1x_1$ 为稳态，$c_1x_1$ 满足以下几个特性
- 特征向量$x_1$ 中的所有元素为正值
- $c_1x_1>0$





**稳态问题就是特征值的特征向量问题**
**马尔科夫矩阵的和概率有关联**



### 1.2 马尔科夫矩阵的应用
---------

设存在一个方程$u_{k+1} = Au_k$，其中矩阵$A$ 为一个马尔科夫矩阵，将该方程转化为两个城市$p_1,P_2$之间的人口数量。这两个城市之间的人会互相迁移。



设$u_0 = \left[ \begin{array}{cccc} 0\\1000 \end{array} \right]$，矩阵$A =\left[\begin{array}{cccc}
0.9&0.2\\
0.1&0.8
\end{array}\right]$ ，$k$ 表示时间，这里设单位为年，那么一年后的两个城市的人数为$u_1 = \left[ \begin{array}{cccc} 200\\800 \end{array} \right]$ 。

求矩阵$A$ 的特征值为
$$
\lambda_1 = 1, \lambda_2 = 0.7 \\
$$

特征向量为
$$
x_1 =\left[ \begin{array}{cccc} 2\\1 \end{array} \right]，
x_2 =\left[ \begin{array}{cccc} -1\\1 \end{array} \right]
$$



可以看出随着$k$ 值越来越大 $\lambda_2$ 的作用越来越小，
$$
u_k = c_1\lambda_1^n x_1+c_2\lambda_2^n x_2
$$



方程$u_{k+1} = Au_k$ 的稳态为
$$
u_k = c_1\lambda_1^n x_1 = c_1x_1 
$$



再来就是求出$c_1$，可以使用$u_0$将其求出
$$
u_0 = \left[ \begin{array}{cccc} 0\\1000 \end{array} \right] = \frac{1000}{3}
\left[ \begin{array}{cccc} 2\\1 \end{array} \right]+\frac{2000}{3} \left[ \begin{array}{cccc} -1\\1 \end{array} \right]
$$





求得$c_1 = \frac{1000}{3}$，因此两个城市人口数量的稳态为
$$
\left[ \begin{array}{cccc} \frac{2000}{3} \\
\frac{1000}{3}
\end{array} \right]
$$







## 2.傅里叶级数
-----------

存在一组$n$ 维空间的标准正交基$q_1 ...........q_n$ ，该空间中的向量为
$$
v = x_1q_1+...............+x_nq_n
$$

如何计算$x_1..............x_n$  ?
$$
q_1^Tv = x_1q_1^Tq_1 \\
q_1^Tv = x_1 \\
x_1 = q_1^Tv
$$

通过上述的方法就可以解出$x_1...........x_n$


现在拓展到函数中，设存在函数$f(x)$，如下所示


$$
f(x) = a_0+a_1\cos(x)+a_2\sin(x)+a_3\cos(2x)+a_4\sin(2x)+..............
$$



如果两个函数$h(x) ,g(x)$正交，则它们有如下性质
$$
\int h(x)g(x) dx= 0
$$



可以找出函数$f(x)$中的一组正交函数
$$
f_1(x) = \cos(x)\\
f_2(x) = \sin(x) \\
f_3(x) = \cos(2x) \\
f_4(x) = \sin(2x) \\
...\\
...\\
...
$$


此时可以将$x_1 = q_1^Tv$ 公式拓展到函数 $f(x)$ ，如下所示
$$
\int f_1(x)f(x)dx = 0+ a_1\int (\cos(x))^2dx+0+... = a_1 \pi
$$




因此$a_1$ 的值可以通过以下公式来计算
$$
a_1 = \frac{1}{\pi}\int \cos(x)f(x)dx
$$


因为$f(x)$ 和$f_1(x).........f_n(x)$ 都是周期为$2\pi$ 的周期函数所以上述不定积分公式可以转为定积分形式
$$
a_1 = \frac{1}{\pi}\int_{0}^{2\pi} \cos(x)f(x)dx
$$


