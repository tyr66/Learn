# 树

## 二叉搜索树
- 往一颗空的二叉搜索树随机的插入节点，那么该二叉搜索树有比较高的概率是平衡的。(证明：CS161)

### 二叉搜索树的应用
- 范围搜索(Range Search)
  - 递归的遍历那些可能在目标范围内的子树，如果一个节点在目标范围内，就添加到结果中。
  - 时间复杂度是 $log(h + z)$ ,其中 $h$ 为树的高度，$z$ 为树中在目标范围内的节点的数量。

### 二叉搜索树
- [CS106B 前缀码(prefix-free code),编码树(Coding Tree),霍夫曼编码
(Huff man Coding)](../Course/cs106b_2022winter/Slides/Slides24.pdf)


## 图
- [CS106B 图的表示，遍历](../Course/cs106b_2022winter/Slides/Slides25.pdf)
- [CS106B 最小生成树,Kruskal算法及其应用](../Course/cs106b_2022winter/Slides/Slides26.pdf)