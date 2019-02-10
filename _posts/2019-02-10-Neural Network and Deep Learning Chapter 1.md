---
layout: post
title: "Neural Network and Deep Learning Chapter 1"
description: "Forewords."
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/02/10/
---
# Neural Network and Deep Learning Chapter 1  
第一周是对深度学习的简介。  

## Welcome to the Deep Learning Specialization  
第一个视频当然是介绍deeplearning和AI了，吴大大第一句话就说，AI is the new Electricity.而AI中最受欢迎的部分就是深度学习。这个视频主要介绍了这整个系列课程中所要学到的东西，他讲了一系列专业名词，但是我只看得懂Machine learning这门课中提及到的那部分，剩下的还是要在学习中逐渐掌握。  

## Introduction to Deep Learning  
这一章一共就这一大节，其中又分为多个小节，每个小节我就不逐一写小标题了，都放在这一节里一起记笔记。  

这门课的名称就是neural network，所以首先要对神经网络进行介绍。果然，吴大大又举了房价预测那个栗子，由于在之前已经学过神经网络，所以就简要记录一下，详细的推导和公式在上一门课的官方笔记中都有，这是链接:[Week 4 Lecture Notes](https://www.coursera.org/learn/machine-learning/resources/RmTEz)  
其中吴大大提到了ReLU函数，其中文名称是**线性整流函数**，维基链接在这里[线性整流函数](https://zh.wikipedia.org/wiki/%E7%BA%BF%E6%80%A7%E6%95%B4%E6%B5%81%E5%87%BD%E6%95%B0)，它的作用是代替了之前的sigmoid函数，在上一门课程中神经网络还是用的sigmoid函数，而现在已经被ReLU代替了。sigmoid的主要问题是当梯度几乎为0时，学习速率将会非常慢，这些内容目前只需要了解一下，后面的课程中会再次介绍。  

数据可被划分为结构化数据和非结构化数据，对结构化数据的训练和识别是比较容易的，但是对非结构化数据的训练和识别是比较困难的，而神经网络对于这两种数据都能找到应用点。  
在其他常用的监督学习算法中，当数据到达一定规模后，随着数据的规模变大，算法的性能不会变大。而在神经网络中，如果神经网络本身的规模足够大，那么它所需要的数据规模则更大，如果有更大的数据集，更大的神经网络规模，那么性能将会更好。因此我把它理解为“潜力更大”，或者“上限更高”。  

这样这周的内容就结束了。。这周居然只有三个真正教东西的视频，别说三天，一个小时都不到这周就完成了- -。  

最后有一个选修视频，是Andrew对一位深度学习大牛的采访，有空的话值得一看，即使不学这门课程，链接在这里：[Heroes of Deep Learning](https://www.coursera.org/learn/neural-networks-deep-learning/lecture/dcm5r/geoffrey-hinton-interview)  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
