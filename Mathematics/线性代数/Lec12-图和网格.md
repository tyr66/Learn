[TOC]



# 图和网格

---------

假设存在一幅图，它有4个顶点，且拥有如下几条边。
$$
Edge_1 = 1 \rightarrow 2 \\
Edge_2 = 1 \rightarrow 3 \\
Edge_3 = 2 \rightarrow 3 \\
Edge_4 = 1 \rightarrow 4 \\
Edge_5 = 3 \rightarrow 4
$$


则可以用矩阵来表示这幅图的，该矩阵称为该图的关联矩阵。矩阵的行表示图的边，矩阵的列表示图的顶点。
$$

\left[\begin{array}{cccc}
-1&1&0&0 \\
0&-1&1&0 \\
-1&0&1&0 \\
-1&0&0&1 \\
0&0&-1&1 
\end{array}\right]
$$
该关联矩阵有一个很有意思的特性就是，若矩阵中的行向量都是线性无关那么该图就是一个棵树。通过观察可以发现该矩阵中的行向量并不是线性无关的，如下所示。
$$
\left[\begin{array}{c} -1&1&0&0 \end{array}\right]+
\left[\begin{array}{c} 0&-1&1&0 \end{array}\right] = 
\left[\begin{array}{c} -1&0&1&0 \end{array}\right]
$$
通过将该图绘制出来也可以很容易的发现该图并不是树。

