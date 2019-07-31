---
layout: post
title: "CS231n Chapter 4 - Introduction to Neural Networks"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/07/31/
---

# CS231n Chapter 4 - Introduction to Neural Networks      

## Introduction  

这一课的讲师是Serena Yeung，这周就进入到了神经网络的具体细节，研究反向传播的机制,并用计算图来表示任意复杂程度的神经网络。  

## Backpropagation  

反向传播实质上就是链式求导，由于我已经学了无数次反向传播了，所以这里就一笔带过求导环节的介绍了，这里把我之前MOOC里的笔记抬上来:[链接](http://justin-yu.me/blog/2019/02/16/Neural-Network-and-Deep-Learning-Chapter-3/)。值得注意的是max()函数其实就是一个分段函数，所以其导数也是分段函数各自求导，即为1和0.    

到目前为止，我们只是学到了如何用链式求导的法则来求得梯度，这里Serena在回答学生的问题的时候，在黑板上写了一个公式，即L对x的偏导等于L对所有参数的偏导的加和，我认为这其实是不准确的，错误的地方在于对于同一层的参数，的确是加和，但是对于不同层的参数来说却是乘积，Serena这里可能是想着重解释一些同一层面上的偏导处理。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
