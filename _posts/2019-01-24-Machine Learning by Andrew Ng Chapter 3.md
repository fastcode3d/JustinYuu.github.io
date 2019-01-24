---
layout: post
title: "Machine Learning by Andrew Ng Chapter 3"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/24/
---
# Machine Learning by Andrew Ng Chapter 3
 
## 前言  

学习任务还很重啊，争取年前刷完三分之二的课程，还要兼顾PAT的刷题。
[第三节笔记](https://www.coursera.org/learn/machine-learning/resources/Zi29t)

### Classification and Representation

本大节主要讲的是逻辑回归和决策边界，我之前看知乎的一篇文章简单讲了一下SVM，感觉SVM的超平面和决策边界有相似之处，等到后面学SVM的时候再看一下。

### Logistic Regression Model

本节主要介绍了逻辑回归的代价函数和对应的梯度下降算法，有了之前线性回归的学习，学习这一节的难度并不大。 
主要复杂之处是公式的推导，课程自带的笔记中已经较为详细的推导过了，就不放在上面了，自己能看懂还没有推一下，有时间自己推一下感觉会比较好。  
本章还介绍了其他一些改进的算法，比如介绍了一种optimset()函数，用fminunc()来返回得到的优化θ值

### Multiclass Classification

多元分类的方式在我理解下是逐个击破的战略，将每一个与其他剩余的分开，一共k个class可以得到k个不同的分类，然后找出值最高的一组h当做预测值

### Solving the Problem of Overfitting

本节介绍拟合过程中的一些问题。  

首先介绍了overfit和underfit。overfit就是说函数的拟合效果相当好，但是函数过于庞大复杂，underfit与其相反，函数过于简单导致其拟合效果差。  
接下来介绍了正则化及其代价函数  
我理解的正则化就是将目标项变小，不管是线性回归中的梯度下降还是正规方程，都可以进行正则化，此外正规方程的正则化中由于加上了一个第一个对角元素为0其余为λ的对角矩阵，导致原本不可逆的矩阵特征值不为0，即变得可逆，也解决了正规方程的不可逆问题。具体的方法见官方笔记。对于逻辑回归的梯度下降也是同理

## Programming Ex2  

本节的题目依然比较简单，同样是代码填空，值得一提的是本节的[指导笔记]<https://www.coursera.org/learn/machine-learning/resources/fz4AU>更像是一个讨论帖子，主要讨论一些额外的代码解释，而不是像第一章一样手把手教你写代码，我觉得这样很好，将有限的学习资源放到更加深入的层面上去，可以学到更多东西。  
fminunc所有的要求和建议都在PDF中说的很清楚了，整体也没有什么困难，感觉比较有趣的地方就是fminunc()函数了，使用这个函数就不用自定义α和迭代梯度了，感觉还是挺不错的，基本的参数和作用都讲到了，美中不足的是没有作为一道题目出现，感觉这样印象会更深刻。  
下面是我的代码  

### sigmoid.m

	g = 1 ./ ( 1 + exp(-z) ); 
	
### costFunction.m

	h = sigmoid(X*theta);
	error = -y .* log(h) - (1-y) .* log(1-h); 
	J = (1 / m) * sum(error);
	grad = (1/m) * (X' *(h-y));
	
### costFunctionReg.m

	h = sigmoid(X*theta);
	tmpTheta = theta;
	tmpTheta(1)=0;
	J = (1/m)*sum((-y.*log(h))-(1-y).*log(1-h))+(lambda/(2*m))*(tmpTheta' * tmpTheta);
	grad = (1/m)*(X'*(h-y))+ (lambda/m)*tmpTheta;

### plotData.m

	pos = find(y==1);
	neg = find(y==0);
	plot(X(pos,1),X(pos,2),'k+','LineWidth',2,'MarkerSize',7);
	plot(X(neg,1),X(neg,2),'ko','MarkerFaceColor','y','MarkerSize',7);
	
### predict.m

	p = round(sigmoid(X*theta));

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
