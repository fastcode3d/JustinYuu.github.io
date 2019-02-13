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
接下来就是之前学过的内容，包括梯度下降法求出θ矩阵，也就是w和b，从而使代价函数J最小。还用一节介绍了求导的方法，以及求偏导和链式求导法则，这是反向传播算法的数学基础，主要是针对没有微积分基础的同学，就不把具体内容放到这里了。  
看了整个目录，我无奈的发现整篇课程讲的全是神经网络的内容，而且前两周连神经网络的名字都没有听到，换言之这门课程的内容充其量只是machine-learning那门课程的2章的内容，所以如果有读者读到这里，我强烈建议参考我在上一节课中记的笔记[Machine Learning by Andrew Ng Chapter 4](http://justin-yu.me/blog/2019/01/25/Machine-Learning-by-Andrew-Ng-Chapter-4/),以及[Machine Learning by Andrew Ng Chapter 5](http://justin-yu.me/blog/2019/01/27/Machine-Learning-by-Andrew-Ng-Chapter-5/),因为以前已经学过，所以这门课程的笔记只记录上门课程没有讲到的知识。但是值得庆幸的是这门课程所用的语言是python而不是Octave，这样我可以用另一种语言来实现神经网络，也算是有所收获。  
在介绍反向传播算法的细节的那一节，介绍求偏导过程中有一个bug，吴大大把dL/dz等价成了dz，甚至写出了公式:dL/dz=dz,同理dL/dw=dw，我把这理解成对dz,dw的一种解释，但是实际上来讲偏微分的表示是不能只用自变量表示的，想想如果一个二元函数z(x,y),那么dz/dx=z'(x)dx，z对x的偏导数当然不能用dx来表示。不过这可能只是我们国内教材的习惯，但总归不太适应。  
最后一节吴大大又推了一遍梯度下降，下一大节就来介绍python的向量化了。  

## Python and Vectorization  
这一节讲的是python的向量化，向量化在之前Octave中已经很熟悉了，通过向量化可以大幅减少代码的长度和复杂程度，也可以大量的减少for循环的数量，吴大大还亲自写了两种不同版本的相同代码，输出所用时间，发现向量化可以大幅减少运行计算时间，所以向量化是非常快速且方便的。举个栗子，在python中，用`np.dot(w,x)`可以快速计算w向量的转置乘x的结果，接下来还会讲更多的向量化命令。  
在第二节的开头，吴大大上来就说，whenever possible, avoid explicit for-loops。其实整个算法的内容十分简单，但是如果用for循环来写的话会非常复杂，因此向量化便是比较重要的一步，首先对于z=wx+b这一步，可以用下列代码来向量化： `z = np.dot(w.T,X)+b` ，由于python的广播(broadcasting)机制，b本来是一个实数，加到一个向量上后会自动扩充为一个同尺寸的向量。通过这一行代码，即可实现所有z向量的向量化，然后通过下列代码 `A = [a1,a2,a3,...,am] = σ(z)` 来将所有的z放到sigmoid函数中统一求值。  
接下来对梯度下降进行向量化，
 

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
