# CSAPP

<!-- vim-markdown-toc GFM -->

* [参考资料](#参考资料)

<!-- vim-markdown-toc -->

## 参考资料

- [课程主页](http://www.cs.cmu.edu/afs/cs/academic/class/15213-f22/www/index.html)
- [全英文视频课程](https://www.bilibili.com/video/av40238125/?vd_source=bb33286cda74be54bbcdf853e121e4f7)
- [课程视频](https://www.youtube.com/watch?v=ScMxnXq6fbI&list=PLcQU3vbfgCc9sVAiHf5761UUApjZ3ZD3x)
- [小土刀的博客](https://wdxtub.com/work/)
- [CSAPP重点解读](https://fengmuzi2003.gitbook.io/csapp3e/)
- [CSAPP-深入理解计算机系统](https://www.bilibili.com/video/BV1cD4y1D7uR/?vd_source=bb33286cda74be54bbcdf853e121e4f7)


## 大小端

假设变量 x 的类型为int，位于地址 `0x100` 处并且它的十六进制表示为 `0x01234567` ，那么在小端机器和大端机器上变量x在该地址处的表示如下图所示。

![](pic/1.png)

## 无符号整数数有有符号整数

绝大多数机械都是使用原码来保存无符号整数，使用补码来保存有符号整数. 有些程序语言会强制要求特定的编码形式来保存。

## 移位操作

- 逻辑左移
- 右移
    - 逻辑右移
    - 算术右移

## 位拓展

- 零拓展: 无符号整数使用零拓展
- 符号拓展: 补码整数使用符号拓展

位拓展后数值大小不变。

## 位的截断与拓展

无符号数截断相当于模运算，而有符号数因为使用补码的形式进行存储还要让截断后的最高位为符号位。
