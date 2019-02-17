---
layout: post
title: "Neural Network and Deep Learning Chapter 4"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/02/17/
---
# Neural Network and Deep Learning Chapter 4  
第四章是本节的最后一章，主要内容是深度神经网络。之前所学习的神经网络都是一层隐藏层或者两层隐藏层，隐藏层层数偏少，便于理解，而这次要学习的神经网络的隐藏层就比较多了。  
这周的课程视频内容比较少，而编程作业的内容比较多，更具有挑战性。  

## Deep Neural Network  
### Deep L-layer neural network  
第一节首先讲了下这章所使用的神经网络的规模，共有三个隐藏层，单元数量是5 5 3，然后讲了一下notation和大致的步骤。  

### Forward Propagation in a Deep Network  
前向传播仍然是z=wx+b/wa+b，其中a的上标要比其他的少一层，因为是前一层的结果，以及a=g(z),这些均和上一章讲的相同。  
在上门课程中我引用过一篇回答[如何直观地解释 backpropagation 算法？ - YE Y的回答 - 知乎](https://www.zhihu.com/question/27239198/answer/43560763)，这个回答中的图片很直观的解释了多层神经网络中的forward prop和back prop。  
再次拿出我上一章推导的图：![4-1](/images/Neural Network and Deep Learning/3-3.jpg)  

### Getting your matrix dimensions right  
这一章教大家如何正确的区分矩阵的维度，我在上门课《machine learning》中神经网络那一节的编程作业中深有体会。我自己采取的方法是将所有矩阵的size全都记在草稿纸上，然后矩阵运算的时候逐一比对。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
