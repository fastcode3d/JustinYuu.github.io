---
layout: post
title: "CS231n Chapter 7 - Training Neural Networks, part II"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/08/05/
---

# CS231n Chapter 7 - Training Neural Networks, part II    

## Introduction  

在开始这节课内容之前，Justin带我们回忆了一下上节课的内容，有一点我没有记录到，就是在超参数的搜索方面，如果超参数数量比较多，那么与其网格化的搜索，不如进行随机搜索，这样得到的效果反而会好一些，也更为省时、节省计算开支，这一点在吴恩达MOOC中也有讲到([链接](http://justin-yu.me/blog/2019/04/08/Improving-Deep-Neural-Networks-Hyperparameter-tuning,-Regularization-and-Optimization-Chapter-3/))，不过具体的随机搜索方法没有讲清楚，这里是一篇知乎回答[链接](https://www.zhihu.com/question/57394983)可供参考，简单来讲，grid search的每一步搜索并不能保证是有效的，而random search的每一步都采样在超参数的分布空间中，因此每一步都是有效的，所以效率更高。  

这一周将会沿着上一周的内容，进一步学习一些更为有效的优化方法，以及介绍正则化和迁移学习这两个非常重要的trick。  

## Fancier optimiaztion  

首先看一看SGD随机梯度下降的缺点，首先可以想到的就是优化过程中的当前下降方向不稳定，从而导致曲折下降的zig-zag状况。这还不是最致命的，最严重的问题在于如果损失函数遇到了一个局部最优值或者一个鞍点，那么导数就会变成0，那么梯度下降就会停止。事实上局部最优其实很难达到，因为在高维空间中，局部最优点需要在所有的维度都达到最优，那这是很难发生的，但是鞍点不同，鞍点可能在某些方向上升，但在某些方向是下降的，和局部最优点的相同点是它在所有维度的梯度也都等于0，用数学语言表示，局部最优点的Hessian矩阵是正定的(行列式等于0)，但是鞍点的Hessian矩阵是非正定的。在高维空间中，鞍点通常被相同误差值的平面Plateau所包围，这个平面上的梯度都接近于0，所以梯度下降的过程中会长时间卡在这个区域无法动弹。那么我们可以比较容易理解到，鞍点存在的情况比局部最优点多得多，并且局部最优点其实已经很好了，很多时候都可以满足我们的需要，鞍点众多也正是牛顿法整体效率低于梯度下降法的原因。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
