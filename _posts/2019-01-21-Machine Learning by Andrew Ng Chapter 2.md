---
layout: post
title: "Machine Learning by Andrew Ng Chapter 2"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/21/
---
# Machine Learning by Andrew Ng Chapter 2
 
 ## 前言  
果然不出我所料，我没有坚持下来这门课，而且虽然准备比较充分，考研考的还是不咋样。不过没关系，忙完了考研，忙完了综合实验和开题答辩，放假回家总算有时间补一下这门课了。入坑ML要学的东西有很多，从这门课开始抓紧学咯。  
突然发现coursera的resource栏里有每节课的学习笔记，那以后就不详细记笔记了，markdown语法自己本身也用的不好，强行记笔记还比较耽误时间，这样就在笔记的基础上把重点难点和自己不会的整理一下就好。  
附上笔记链接  
[第一章](https://www.coursera.org/learn/machine-learning/resources/JXWWS)  
[第二章](https://www.coursera.org/learn/machine-learning/resources/QQx8l)  

## 梯度下降算法  
本章的第一节就是介绍多元梯度下降算法，梯度下降算法在第一章有过简要截介绍，但是当时自己没听明白，所以去google补充了一下相关知识。  
简而言之，我所理解的梯度下降算法就是不断的寻求当前函数的梯度，沿着梯度反方向下降（即下降最快的方向），每过一段便寻找当前位置新的梯度，而这一段有多长通过公式中的α（学习率、步长）来确定。  
而梯度的确定则需要对多元函数求微分，由于函数有多个自变量，所以求得的函数微分也有多个自变量，直接用矩阵的形式来表示，然后根据公式迭代即可。
  
---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
