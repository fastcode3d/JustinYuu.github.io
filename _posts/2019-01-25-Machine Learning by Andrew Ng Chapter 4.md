---
layout: post
title: "Machine Learning by Andrew Ng Chapter 4"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/25/
---
# Machine Learning by Andrew Ng Chapter 4
 
## 前言  

第四章终于到了神经网络，这门课从目录看来应该会用两章来讲神经网络，估计是简要介绍
[第四章笔记](https://www.coursera.org/learn/machine-learning/resources/RmTEz)

## Motivation

本节有两小节，第一节讲了如果用线性回归处理复杂feature的规模，在笔记中补充了公式的推导，第二节讲了神经网络的应用，看到了吴大大一脸的激动- -。

## Model Representation

这一章的的确确把我给搞糊涂了，再看了一遍课后笔记，我大体上理解为假如整个流程有3层，即中间有1层隐藏层，那么隐藏层的值是通过输入的特征值计算得出的，而隐藏层的值又作为下一层的特征值，通过逻辑回归计算出最后的结果，具体的公式其实并不复杂，在官方笔记里都有，但是我感觉把我绕晕的就是向量的运算和一大堆奇怪的标号，特别是又有上标又有下标的参数，希望如Andrew所说看完下一节的应用之后可以有更好的理解。  

## Applications  

大体上和我的理解差不多，从输入特征值到隐藏值的转换要通过与隐藏层个数相同数量的转换，然后隐藏层那一层的个数加上+1即可得到最终的结果。  
用了一个异或运算作为例子，一条直线无法划分开，所以要用两条直线来划分，具体来说将异或运算分为与和或非两个运算，然后通过一个或运算来完成整个异或运算。  
PS：杨大大的视频配乐好喜感啊~

## Ex3  

我惊讶的发现ex3的pdf文档中用了大量的篇幅介绍向量运算，以及这样为什么可以大幅减少代码量。可我之前一直都是用这种向量运算做的。。。难怪之前的两次练习的代码量如此之少- -。  
本章的代码和上一章的基本相同，只是加了一个for循环，弄明白行列的值之后保证矩阵乘法不出错即可

### lrCostFuntion.m  

	tmptheta = theta;
	tmptheta(1)=0;
	h = sigmoid(X*theta);
	J =  (1/m) * sum(-y.*log(h)-(1-y).*log(1-h)) + (lambda/(2*m)) * tmptheta' * tmptheta;
	error = h-y; 
	grad = (1/m) * X' * (h-y) + (lambda/m) * tmptheta;

### oneVsAll.m  

	for c=1:num_labels,
		initial_theta = zeros(n+1,1);
		options = optimset('GradObj','on','MaxIter',50);
		[theta] = fmincg(@(t)(lrCostFunction(t,X,(y==c),lambda)),initial_theta,options);
		all_theta(c,:)=theta';

### predictOneVsAll.m  

	C = sigmoid(X*all_theta');
	[v,p] = max(C,[],2);

### predict.m  

	a1 = [ones(m,1) X];
	a2 = sigmoid(a1*Theta1');
	a2 = [ones(m,1) a2];
	a3 = sigmoid(a2*Theta2');
	[v,p]=max(a3,[],2);

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
