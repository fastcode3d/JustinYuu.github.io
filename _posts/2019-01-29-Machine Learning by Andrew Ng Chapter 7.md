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

## Kernels  

对于Kernels我理解了很久，我所理解的Gaussian Kernel是一个函数，其作用是简便计算，计算的对象是高维空间的内积，而之所以要算高维空间的内积，是因为函数f将低维空间的内积映射到了高维，而之所以函数f将低维映射到高维，是因为为了更好的实现线性可分。  
为了更好的理解，我又去程序员最喜欢的网站之一知乎找了一篇不错的回答贴在这里：[机器学习里的 kernel 是指什么？ - 郭鸿渐的回答 - 知乎]
(https://www.zhihu.com/question/30371867/answer/73428260)  
最后讲了方差偏差与Kernels的参数的关系，C越大方差越大，C越小偏差越大，σ越大f变化更平滑，偏差越大，反之f变化更不平滑，方差越大。  

## SVMs in Practice  

本节讲了SVM，神经网络和逻辑回归三种方法之间的选择，具体的选择策略在官方笔记里写的很详细，就不再重复写在这里了，看了一遍自己的感触还是不太深，以后真正用到的时候再看下应该会有更深的感触。  

## Ex6  

### gaussianKernel.m  

	sim = exp(-sum((x1-x2).^2)/(2*sigma^2));  
	
### dataset3Params.m  

	values = [0.01 0.03 0.1 0.3 1 3 10 30];
	min_err = 1;
	for i = 1:8
	  for j = 1:8
		  C_test = values(i);
		  sigma_test = values(j);
		  model = svmTrain(X,y,C_test,@(x1,x2) gaussianKernel(x1,x2,sigma_test));
		  predictions = svmPredict(model,Xval);
		  err= mean(double(predictions ~= yval));
		  if err< min_err
			  C = C_test;
			  sigma = sigma_test;
			  min_err = err;
		  endif
	  endfor
	endfor

### processEmail.m  

    for i = 1:length(vocabList)
        if(strcmp(str,vocabList(i))==1)
            word_indices = [word_indices ; i];
            break;
          end;
    endfor  
	
### emailFeatures.m  

	for i = 1:length(word_indices)
	  if(word_indices(i))
		  x(word_indices(i))=1;
	  end
	endfor

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
