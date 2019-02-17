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
这一节教大家如何正确的区分矩阵的维度，我在上门课《machine learning》中神经网络那一节的编程作业中深有体会。我自己采取的方法是将所有矩阵的size全都记在草稿纸上，然后矩阵运算的时候逐一比对。  

### Why deep representations?  
这一节讲的是为什么需要如此深的神经网络。简单来讲，神经网络可以完成很复杂的工作，比如面部识别，但是还是要将复杂的工作拆分成比较简单的小部分来做，这时通过多层隐藏层的相互配合，就能完成复杂的工作处理。吴大大又举了异或的例子，如果只用一层的隐藏层，那么规模将是指数级的，因此深层的神经网络也可以减少单层的规模。  

### Building blocks of deep neural networks  
这节讲了组建神经网络时需要的模块，在每一个模块中都有前向传播和后向传播的步骤，然后模块与模块之间相互连接，最终组成一个深度神经网络。  

### Forward and Backward Propagation  
这节和上节的不同是把公式又写了一遍。讲这4周的课，吴大大把这些公式少说也得写了5遍，再记不住说不过去啦。  
值得注意的是σ函数在不同的隐藏层上也是不同的，这里他举例用的是第一第二层是ReLU，第三层是sigmoid，具体选择还是看个人。  

### Parameters vs Hyperparameters  
这一节介绍参数和超参数。首先介绍什么是参数：参数包括W和b，即θ。然后介绍什么是超参数:就是其他的参数，比如学习率α，迭代次数，隐藏层的层数，隐藏层的隐藏单元数，选择的激活函数种类等等，这些都需要在设计神经网络时设定。这些参数都会影响最后的W和b，所以称之为超参数。  

### What does this have to do with the brain?  
这节主要针对提问频率比较高的问题进行一个补充回答：深度学习与人类大脑有什么相似性？吴大大的回答是：没啥相似性。  
只不过神经网络的结点和神经元比较相似，都是接受刺激后进行处理，然后通过突触传递给下一个神经元。至今人类神经元如何处理数据仍然无人知晓，因此谈不上处理的相似性，只是有形式的相似性。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
