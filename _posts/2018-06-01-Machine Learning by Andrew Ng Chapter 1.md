---
layout: post
title: "Machine Learning by Andrew Ng Chapter 1"
description: "Forewords."
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2018/06/01/
---
# Machine Learning by Andrew Ng Chapter 1

  第一周主要是导论以及需要的数学知识的回顾，内容量还是比较大的
  
## Introduction

  第一节为概论，主要解释机器学习的基本概念，以及监督学习和非监督学习的基本定义。  

### 何为机器学习

  Machine Learning is field of study that gives computers the ability to learn without being explicitly programmed.

### 监督学习（Supervised learning）

  数据集中的每个样本有相应的“正确答案”（训练集），根据这些样本做出预测，分有两类：回归问题和分类问题

  （1）回归问题：预测房价，根据样本集拟合出一条连续曲线

  （2）分类问题：根据肿瘤的大小来判断是恶性还是良性，得到一系列离散的结果。

  对于真正的学习问题，会用到无数的属性、特征和线索进行预测，而不只是上述的一个或者几个特征。
  
### 无监督学习（Unsupervised learning）

  无监督学习会将不同的数据分为几个聚类，然后进行聚类分析，此为聚类算法
  
  Cocktail party problem：在一个小的房间里，进行着一个小型的鸡尾酒聚会，假设只有两个人在发言，分别由两个麦克风放大其音量，A的声音也许在第一个麦克风的声音里会大一点，B的声音在第二个麦克风会大一点，在每个麦克风中都有重叠的部分所在。而所谓的“鸡尾酒会算法”便是找出其中蕴藏的分类，并分出两个重叠在一起的音频源（Holy high）
  
  事实上实现这个功能只需要一行代码，即 [W,s,v] = svd((repmat(sum(x.\*x,1),size(x,1),1).\*x)\*x');

  此课程中的算法均是通过Octave实现，同样也可以通过matlab实现。Octave的运行速度、编译量和学习速度将会远远快于Java和C++等主流编程语言。
  
---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
