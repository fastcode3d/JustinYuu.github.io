---
layout: post
title: "Machine Learning by Andrew Ng Chapter 2"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/22/
---
# Machine Learning by Andrew Ng Chapter 2
 
## 前言  
果然不出我所料，我没有坚持下来这门课，而且虽然准备比较充分，考研考的还是不咋样。不过没关系，忙完了考研，忙完了综合实验和开题答辩，放假回家总算有时间补一下这门课了。入坑ML要学的东西有很多，从这门课开始抓紧学咯。  
突然发现coursera的resource栏里有每节课的学习笔记，那以后就不详细记笔记了，markdown语法自己本身也用的不好，强行记笔记还比较耽误时间，这样就在笔记的基础上把重点难点和自己不会的整理一下就好。  
附上笔记链接  
[第一章](https://www.coursera.org/learn/machine-learning/resources/JXWWS)  
[第二章](https://www.coursera.org/learn/machine-learning/resources/QQx8l)  

## 梯度下降算法  
本章的第一节就是介绍多元梯度下降算法，梯度下降算法在第一章有过简要介绍，但是当时自己没听明白，所以去google补充了一下相关知识。  
简而言之，我所理解的梯度下降算法就是不断的寻求当前函数的梯度，沿着梯度反方向下降（即下降最快的方向），每过一段便寻找当前位置新的梯度，而这一段有多长通过公式中的α（学习率、步长）来确定。  
而梯度的确定则需要对多元函数求微分，由于函数有多个自变量，所以求得的函数微分也有多个自变量，直接用矩阵的形式来表示，然后根据公式迭代即可。

### feature scaling  
我理解feature scaling为一种特征值的缩放，即不管要分析的数据值是多少，都把他们缩放为-1<x<1这一数量级内，缩放的方式为（原值-平均值）/标准差，标准差也可以换成极值差，这样更方便。  
### learning rate  
正如上文所说，学习率的选择也是有讲究的。学习率太大可能会导致随着迭代次数而增加，而迭代次数太小可能导致变化不明显，选择学习率的时候可以以三倍为单位进行测试选择    
PS:这一节的中文字幕实在太烂了，三句话也就翻译一句:(

## 正规方程法  

正规方程法分为可逆和不可逆两种  
### 可逆  
可逆的正规方程法主要通过一个公式来推导θ，公式推导引用了知乎专栏的一篇文章[公式推导](https://zhuanlan.zhihu.com/p/22474562)

### 非可逆   
我所理解的非可逆矩阵即为奇异方阵或者非方阵，视频中给出了两个原因：1.冗余特征，即两个不同的特征其实是相关连的，我所理解的是这在线性代数中表现为两个列矩阵线性相关，即秩小于方阵行列数，导致特征值为0，即为奇异矩阵。2.特征太多，这在线性代数中表现为非方阵，当然也是不可逆的。  
而处理方法给出两个，即减少冗余特征或者正则化，正则化只是简单一提，估计后面会有更加深入的介绍。  

## Octave

用了一章的篇幅来介绍了Octave的基本使用，大二的时候学过一学期的matlab，当时认为最没用的课万万没想到现在排上了用场，Octave的操作和语法和MATLAB基本相同，所以并没有什么难度，再想想当时学了一大堆以为会很重要的化学，现在却毫无用处了 :(

## Ex1

第一次作业放在了第二章，作业内容还是相当简单的，不是princeton的MOOC的那种写全部代码，而是类似计算机等级考试那种的代码填空，而且有长达12页的pdf文档给予详细的指导，此外还有专门的一篇指导材料[Programming Ex.1](https://www.coursera.org/learn/machine-learning/resources/O756o)。如此简单的题目加上如此详细的推导，一会便完成了所有题目和附加题目。  
把代码放上来:

### computeCost.m

	h = X * theta;
	error = h - y;
	error_sqr = error.^2;
	J = 0.5 / m * sum(error_sqr);
	
### computeCostMulti.m

	h = X * theta;
	error = h - y;
	error_sqr = error' * error;
	J = 0.5 / m * error_sqr;
	
### gradientDescent.m/gradientDescentMulti.m

    h = X * theta;
    error = h - y;
    gradient = X' * error;
    theta_change = (alpha / m) * gradient;
    theta = theta - theta_change;

### plotData.m

	plot(x,y,'rx','MarkerSize',10);
	ylabel('Profit in $10,000s');
	xlabel('Population of City in 10,000s');

### featureNormalize.m

	mu = mean(X);
	sigma = std(X);
	X_norm = (X-mu)./sigma;

### normalEqn.m

	theta  = pinv(X' * X)* X' * y;

---

至此第二周内容全部结束，第三周笔记讲放在下一篇文章中。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
