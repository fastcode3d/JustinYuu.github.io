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
对于K值的选择，Andrew建议用作图的方式，绘制出J随着K的变化图线，这里应用了一个“肘部法则”，即拐点处是最合适的K值，这里笔记里没有图片，我把视频截图放在这里。  
![avatar-w120](/images/QQ截图20190131093252.png "Elbow method")  
Andrew介绍的K-means很简单，优化算法也是简单略过，所以我找了另外一篇文章来解释一下[十大经典数据挖掘算法——k-means](http://www.cnblogs.com/en-heng/p/5173704.html)  
此外还有[K-means的几种改进算法](https://www.cnblogs.com/yixuan-xu/p/6272208.html)  

## Motivation  
本节开始介绍维数约简的两步，第一步是数据压缩，其方式类似于将两个不同的维度分别为xy轴然后坐一条直线，然后将该直线作为新的坐标轴，以此进行维数约简。第二步是绘图，将约简的低维图像绘制出来从而直观的观察其联系。这一节只是概述一下，具体的介绍应该后面还会讲。  

## Principal Component Analysis  
PCA中文为主成分分析法，是很流行的维数约简算法。  
Andrew介绍完之后我瞬间感觉到这就是线性回归，然后他的下一页PPT的title上赫然写着：PCA is not linear regression - -。具体来讲，虽然2维PCA和线性回归都是用一条直线来表示二维数据，但线性回归是最小化Y值，而PCA是最小化点到这条直线的距离。  
关于具体步骤，首先进行均一化和特征缩放处理原始数据，然后要计算出协方差矩阵，然后用奇异值分解计算特征向量。吴恩达大大只是提了一下这两个名字，然后用OCTAVE里面自带的函数进行，所以我找了几篇讲的不错的博客分享在这里，我越来越觉得需要学一下高代和数分了：  
[机器学习中的数学(5)-强大的矩阵奇异值分解(SVD)及其应用](http://www.cnblogs.com/LeftNotEasy/archive/2011/01/19/svd-and-applications.html)   
[奇异值分解(SVD)原理与在降维中的应用](https://www.cnblogs.com/pinard/p/6251584.html)  
[详解协方差与协方差矩阵](https://blog.csdn.net/ybdesire/article/details/6270328)  
通过调用SVD函数，得到了特征向量矩阵U，截取降维后的维数k个特征向量，组成矩阵z，至此PCA算法的所有操作就结束了。但是没有提及的是具体的数学证明，我将一篇博客中的数学证明放在这里：[PCA的数学原理及推导证明](https://zhuanlan.zhihu.com/p/26951643)  

## Applying PCA  
顾名思义这节主要介绍PCA的应用，主要是将PCA的过程过了一遍，这节提到了USV矩阵中的S矩阵，这是一个对角矩阵，对角元素为奇异值，通过该矩阵对角元素的前k个和与所有和的比值来确定保留的差异值，从而得出压缩维数的结果反应原始数据的准确程度，并确定所选择的主成分数量k。  
Andrew特意强调不要用PCA来避免过拟合，这是因为PCA是无监督的，它的主要操作是忽略y标签，不考虑目标变量的过滤数据，这样有可能导致一些方差很小但是很关键的数据被过滤掉，所以一般用正则化来处理过拟合问题。  
这里引用一篇知乎回答，更为详细的解释了这个问题：[为什么PCA不被推荐用来避免过拟合？ - 戴玮的回答 - 知乎]
(https://www.zhihu.com/question/47121788/answer/121838673)  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
