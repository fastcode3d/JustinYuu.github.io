---
layout: post
title: "CS231n Chapter 13 - Generative Models"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/08/14/
---

# CS231n Chapter 13 - Generative Models  

## Introduction  

这一周主要进行生成模型的学习，但是在这之前要先讲一下无监督学习。生成模型主要介绍三个，分别是PixelRNN和PixelCNN、Variational Autoencoders和Generative Adversarial Networks，最后一个也就是大名鼎鼎的生成对抗性网络GAN。  

## Unsupervised Learning  

无监督学习的概念在刚刚接触深度学习的时候就会被提到，无监督学习和监督学习不同，没有明确的目标label y，比如聚类、降维等。在之前吴恩达机器学习MOOC中学习过相关概念，这里是当时的笔记[链接](http://justin-yu.me/blog/2019/01/30/Machine-Learning-by-Andrew-Ng-Chapter-8/)，在这门课程中知识简要的提了一下，具体的内容还是要复习一下当时的笔记。  

## Generative Model  

生成模型的作用是给定一个训练的数据，能够生成同样分布的相似数据，这里为什么是一个非监督学习任务呢？答案在于我们需要用非监督学习来估计训练数据的潜在分布，这其实是非监督学习中的一个核心问题。  

生成模型可以分类成两个主要分支，Explicit dentisy和Implicit density，很多耳熟能详的模型都在里面。在explicit density分支下，又可以分为tractable density和approximate density，前者的模型是完全可见的信息网，比如NADE、MADE和PixelRNN/CNN，后者又可以分为Variational（变分自动编码机）和马尔科夫链（玻尔兹曼机），而在implicit density分支下，可以分为马尔科夫链（GSN）和Direct（GAN）。  

## PixelRNN/CNN  

首先我们介绍显式密度类型中的tractable density，即完全可见信息网。他们明确的模拟了数据分布的密度，使用链式法则去分解可能性，将输入的图像x分解为1维空间的分布，接下来将训练数据的似然最大化。那么我们如何来表示数据在像素上的复杂性分布呢？我们可以考虑使用C深度神经网络来表达这种复杂性。PixelRNN从角落里的像素里生成图像像素，由于每一个像素都与之前的像素有关（分布是整体的），所以我们自然而然的想到可以使用LSTM来完成。但是这个网络的缺点是序列生成速度很慢，所以我们尝试用CNN来代替RNN，仍然是从角落开始扩展，取待生成的像素点周围的像素，将这些像素导入CNN中，用softmax来生成下一个像素，我们通过最大化训练图像的似然来训练模型。  

总结一下，PixelRNN和CNN可以显性的计算似然p(x),显性的似然可以带来好的明确的评价指标，此外这个网络还能产生很好的样品。但是它也有缺点，比如序列生成的速度比较慢。那么自该算法发明以来，就一直被改进，比如给卷积层增加一个门，采用short-cut connection等。  

## Variational Autoencoders（VAE）  

接下来介绍变分自动编码机，首先我们先学习一些背景知识：何为自动编码集？自动编码集并不用来生成新数据，但是是一种无监督学习的方法，用来学习未标注数据的低维特征表示。那么具体是怎么学习的呢？我们首先输入数据x和特征z，然后用一个编码器encoder进行x到z的映射，然后再将特征z通过解码器进行decode成重建的输入数据x，使用L2距离作为损失函数值，同时我们在decoder的时候一般进行降维，从而保留x的重要特征，将不重要的特征剔除。这里encoder和decoder一般是对称的，一开始使用linear+sigmoid，后来使用深度的FC程，最后使用ReLU CNN，当然解码器就是upconv。那么我们可以看到自动编码机能够重建数据并学习特征，因此我们可以用这个来初始化一个监督学习模型，那么我们会进一步想，这些学习的特征z有捕捉训练数据中包含的变化因素的能力，那么我们可以用自动编码机来生成新的数据吗？这就引入了我们要讨论的变分自动编码机。  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
