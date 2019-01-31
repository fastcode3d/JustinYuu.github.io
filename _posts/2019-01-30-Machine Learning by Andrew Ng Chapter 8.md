---
layout: post
title: "Machine Learning by Andrew Ng Chapter 8"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/30/
---
# Machine Learning by Andrew Ng Chapter 8
 
## 前言  
本章主要介绍无监督学习，与监督学习相比，无监督学习输入的数据没有标签，所以需要机器自己区分类别进行分类。  
[第八章笔记](https://www.coursera.org/learn/machine-learning/resources/kGWsY)  

## Clustering  
本节主要介绍聚类分析，K-means聚类分析我个人感觉有些局部最优的意思，不断的加入新的结点然后更新新的质心，新的节点继续加入到距离其最近的质心内，这样不断的更新质心，直到质心不再变化为止。  
局部最优是存在问题的，如果初始位置选的不合适则会使效率变低，因此要对该算法进行优化，即优化代价函数J，在一开始的随机初始化操作时，随机选取K个位置，循环100次，找到J最小的那个结果作为初始化的结果，以尽力达到平衡。  
对于K值的选择，Andrew建议用作图的方式，绘制出J随着K的变化图线，这里应用了一个“肘部法则”，即拐点处是最合适的K值，这里笔记里没有图片，我把视频截图放在这里![avatar](JustinYuu.github.io/images/QQ截图20190131093252.png "Elbow method")。
Andrew介绍的K-means很简单，优化算法也是简单略过，所以我找了另外一篇文章来解释一下[十大经典数据挖掘算法——k-means](http://www.cnblogs.com/en-heng/p/5173704.html)  
此外还有[K-means的几种改进算法](https://www.cnblogs.com/yixuan-xu/p/6272208.html)  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
