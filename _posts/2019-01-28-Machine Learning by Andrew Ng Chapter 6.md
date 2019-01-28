---
layout: post
title: "Machine Learning by Andrew Ng Chapter 6"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/28/
---
# Machine Learning by Andrew Ng Chapter 6
 
## 前言  

本章的设计很有趣，编程作业放在中间。[第六周笔记](https://www.coursera.org/learn/machine-learning/resources/LIZza)  

## Evaluating a Learning Algorithm  

本节讲了如何评价一个学习算法的性能。通常来讲，一般把数据集分为训练集和测试集，训练集负责优化θ，而测试集负责测试性能，这看起来很合理，但如果涉及到对于多项式的选择（以线性回归为例），那么只能通过测试集来进行选择，因为训练集已经对不同项数的线性方程进行了优化，那么问题在于，用测试集选出的误差最小多项式方程再用测试集去测试，其性能一定会好于其他数据，因为这个方程就是根据测试集误差最小选出来的，换言之，测试的结果无法合理反应这一方程的准确度，因此需要再多加一部分称为交叉验证集的数据集，这一部分的功能就是选项数，而测试集继续发挥测试的作用。这样测试和选项数所用的数据集不同，则对于性能的测试结果比较准确可靠。  

## Bias vs. Variance  

### Diagnosing Bias vs. Variance  

本节一开始讲了方差和偏差的区别，如果欠拟合，那么偏差一般会偏大，不管是交叉验证集还是训练集的误差都很大，而如果过拟合，那么虽然训练集的误差很小，但是由于过拟合，验证集的误差仍然很大，这便是方差大。  

### Regularization and Bias/Variance  

同样，正则化的参数λ也对偏差和方差有影响，不过和多项式的项数相反，如果λ偏小，那么过拟合，方差大，如果λ偏大，那么欠拟合，偏差大。如果容易弄混，那么只需要记住：过拟合一定方差大，欠拟合一定偏差大，其他参数的影响各不相同。  

### Learning Curves

学习曲线可以看出目前的学习函数的一些问题所在。  
比如当高偏差时，增加训练集的数量帮助不大；而当高方差时增加训练集的数量却可能会有一定的帮助。这一结论理解起来也并不困难，高偏差对应的是欠拟合，此时应该做的是更好的拟合函数，一味的增加训练集不改变函数还是无法拟合，而高方差时对应的是过拟合，函数的复杂程度已经足够了，此时应该增加训练集不断的修正θ。   

### Deciding What to Do Next Revisited  

通过上面的介绍，最终回到最初的问题，如何确定接下来应该修改什么以改进算法呢？  
课后的阅读材料对此进行了比较好的总结[阅读材料](https://www.coursera.org/learn/machine-learning/supplement/llc5g/deciding-what-to-do-next-revisited)，在笔记上也有相同的内容，因此这里就不再重复写一遍了。  

## Ex5   

本周的作业按部就班按照提示写，没有什么难度，但是最后一个题调用函数的时候写成另一个函数了，找了半天耽误了一些时间- -。  

### learningCurve.m  

	for i = 1:m
		theta_train = trainLinearReg(X(1:i,:),y(1:i),lambda);
		error_train(i) = linearRegCostFunction(X(1:i,:),y(1:i),theta_train,0);
		error_val(i) = linearRegCostFunction(Xval,yval,theta_train,0);
	endfor

### linearRegCostFunction.m  

	error = X * theta - y;
	tmpTheta = theta;
	tmpTheta(1) = 0;
	J = (1/(2*m)) * (error' * error) + (lambda/(2*m)) * (tmpTheta' * tmpTheta);

	grad = (1/m) * sum(error.*X) + (lambda/m) * tmpTheta';
	
### polyFeatures.m  

	X_poly(:,1) = X;
	for i = 2:p
	  X_poly(:,i)= X.^i;
	endfor

### validationCurve.m   

	for i = 1:length(lambda_vec)
		lambda = lambda_vec(i);
		theta = trainLinearReg(X,y,lambda);
		error_train(i) = linearRegCostFunction(X,y,theta,0);
		error_val(i) = linearRegCostFunction(Xval,yval,theta,0);
	endfor
	
---
## Building a Spam Classifier  

本节介绍了建立一个垃圾邮件过滤器所考虑的特征，Andrew所建议的是先选择一个简单的算法训练一下数据，然后根据最后的结果来找哪里出现了错误和问题，再根据具体的错误和问题来修改自己选择的算法，确定是否需要添加某个特征值。  
在确定是否需要添加特征值时，Andrew建议通过数学分析的方式来确定，而不是通过自己的估计。  

## Handling Skewed Data  

偏斜类问题是指总体样本分布中，一个类的样本量远远大于另一个类的样本量。这使得改动算法后，如果误差率下降并不意味着改进是有效的。存在偏斜类问题时，用分类精确度并不能很好地衡量算法。换言之，如果一个问题中y=0的概率是0.5%，那么即使设置的函数使y一直输出1，准确率还是有99.5%,但是这个函数很明显是非常不合理的。因此采用召回率和查准率来确定，具体的定义公式在官方笔记里给出，如果一个算法具有高召回率和高查准率，那么这个算法就是好的。因此采用参数F1=2PR/(P+R)用来评价算法的性能，值越大性能越好。  

## Using Large Data Sets  

本节的中心思想很简单：数据样本数量够大在能够得到准确的拟合函数，当然也给出了一些与样本数量无关的例子，比如特征数太少。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
