---
layout: post
title: "Neural Network and Deep Learning Chapter 2"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/02/10/
---
# Neural Network and Deep Learning Chapter 2  
第二章主要复习神经网络的知识，这章的内容都比较熟悉了，较快略过。  

## Logistic Regression as a Neural Network  
首先介绍了逻辑回归，包括θ向量、sigmoid函数、逻辑回归公式等，具体内容可以参考上一门课的[第三节笔记](https://www.coursera.org/learn/machine-learning/resources/Zi29t)。  
这门课程中逻辑回归模型所用的参数是W和B，w是θ向量的除第一项以外的其他项组成的向量，b是第一项。损失函数用L表示，代价函数用J表示。在第三节笔记中没有详细解释代价函数的来源，这里贴一篇博客来证明代价函数是怎么来的：[Logistc回归损失函数证明](https://blog.csdn.net/chaipp0607/article/details/78082154)，还有一篇[Logistic回归原理及公式推导](https://blog.csdn.net/pql925/article/details/79021464)。可以看到最关键的一步是用**极大似然估计**来推导的，可是我不知道什么是极大似然估计- -，于是我又去补了下课，看接下来三篇博客就差不多明白了，首先是引导篇：[逻辑回归的损失函数是怎么来的？](http://sofasofa.io/forum_main_post.php?postid=1000352)，接下来是深入篇：[极大似然估计详解](https://blog.csdn.net/zengxiantao1994/article/details/72787849)，最后是官方篇:[最大似然估计-维基百科](https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E4%BC%BC%E7%84%B6%E4%BC%B0%E8%AE%A1)，[](https://en.wikipedia.org/wiki/Maximum_likelihood_estimation)  
接下来就是之前学过的内容，包括梯度下降法求出θ矩阵，也就是w和b，从而使代价函数J最小。还用一节介绍了求导的方法，这主要是针对没有微积分基础的同学，就不把具体内容放到这里了。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
