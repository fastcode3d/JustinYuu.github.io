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
局部最优是存在问题的，如果初始位置选的不合适则会使效率变低，因此要对该算法进行优化，即优化代价函数J，我觉得Andrew这一节将的不是很清晰，所以找了另外一篇文章来解释一下[十大经典数据挖掘算法——k-means](http://www.cnblogs.com/en-heng/p/5173704.html)  

1月30晚上更：我有罪，我检讨，我玩了一天，今天的任务没做完，只看了三个视频，明天要好好干。  


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
