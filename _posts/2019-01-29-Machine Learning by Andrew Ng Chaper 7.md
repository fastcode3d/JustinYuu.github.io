---
layout: post
title: "Machine Learning by Andrew Ng Chapter 7"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/29/
---
# Machine Learning by Andrew Ng Chapter 7
 
## 前言  

本章终于介绍到了紧张刺激的SVM（支持向量机）。
[第七章笔记](https://www.coursera.org/learn/machine-learning/resources/Es9Qo)  

## Large Margin Classification  

这一章主要讲了SVM的定义和应用。  
定义上来讲我认为和逻辑回归还是很像的，不同的是不是用sigmoid函数而是用其他函数来判别y是1还是0，此外m被去掉，λ变成了另外一个参数C放在了前面那一项上，总体来讲形式还是差不多的，具体方程在笔记里有。  
函数的具体形式方面，采用的判别依据是θx的值大于1和小于-1，而不是之前的大于小于0，因此SVM所画出的决策边界是间距(margin)最大的，这样选择出的决策边界更加合适。  
对于优化方式是如何得到大间距的这一问题，Andrew用了一节长达19min的视频来解释。简单来讲，我们想要使θx大于1或小于-1，视频里将θx表达为pθ，那么我们只要使theta尽可能小，那么p就会尽可能大，而在数学层面p代表了间距，所以SVM可以求出间距最大的解，具体的公式和图片都在官方笔记里可以看到。  


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
