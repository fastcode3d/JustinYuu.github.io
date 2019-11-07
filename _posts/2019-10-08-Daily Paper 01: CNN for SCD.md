---
layout: post
title: "Daily Paper 01: CNN for SCD"
description: "Notes"
categories: [SR-SCD]
tags: [Paper]
redirect_from:
  - /2019/10/08/
---

# Daily Paper 01 - Convolutional Neural Network for Speaker Change Detection in Telephone Speaker Diarization System    

## Foreword  

由于没有DDL的时候实在是太过自由散漫，因此强行规定自己每天看一篇文章，然后或多或少的写一点总结和思考，以后翻起来的时候也能迅速的get到论文的点。最近还没有接到导师具体的任务安排，就先看看师姐安排的speaker change detection这系列的文章吧。我的笔记不会按照论文里面的部分一样详细的展开，而是简要的分为几个部分进行summary。  

## Introduction  

speaker change detection(SCD)其实可以算作是语音识别方向的问题，简而言之就是检测一下说话者是否有所改变，以及探测到改变的具体位置。那么评价SCD性能的指标有Bayesian Information Citerion(BIC)和Generalized Likelihood Ratio(GLR),以及Kullback-Leibler divergence。这篇论文的主要贡献是应用了CNN来解决SCD问题，在电话扬声器区分系统这一实际应用中表现良好，具体的表现是相对降低了GLR的Equal Error Rate 46%，相对提升了diarization error rate 28%.  

Introduction部分大讲特讲CNN……比较有价值的是Speaker Diarization的处理流程介绍，首先是把输入的信号切分，然后按照说话的人来将切分的片段聚类，也可以把这两部分合成一步作为一个独立的循环过程，分割的片段至少要长到可以提取出能够识别到说话人的特征。这里没有介绍GLR，GLR是数理统计里面的名词，即广义似然比检验，详细的我也看不懂，就先了解下名词好了。  

## System  

在这篇paper之前，他们其实已经发过一篇paper了，那一篇paper也用CNN进行了实验，结果显示虽然在BIC指标中表现良好，但是仍然存在缺点，比如只用了512个频率中的256个低频，这是因为他们之前认为高频对于SCD来说并无卵用，但是后续的实验打脸表明还是全谱效果更好。此外，他们之前的实验有识别具体时间的不准确性，这是由于电话交谈的性质导致说话者会频繁的切换所致。那么他们采取了一个新的标注策略，即用模糊标注来代替二分标注，当说话者的切换正好定位在分析窗口的正中央时，取值为1，然后逐渐的向两端线性减少直至0为止。  

此外CNN的结构如下：三层Conv和ReLU的混合，每层之后加一层最大池化和BN层，最后跟两层FC层，FC层采用sigmoid作为分类函数。第一个Conv层filter的尺寸是根据频谱图中的高能量语音谐波的一般矩形决定。（这是说的啥？）他们之前double了filter的尺寸，结果发现表现好了一点。整个CNN作为一个回归器，采用二元交叉熵作为训练的损失函数，使用SGD以64的batch训练，学习率随着训练decay，不过没有说明幅度，估计只改变了一次，最后使用RMSprop调优。  

i-vector是声纹识别中一个重要的模型，这里是一篇介绍:[链接](https://www.jianshu.com/p/e730e70de7f8)，i-vector通过主成分分析(PCA)，从大规模的原始数据中获得，i-vector的尺寸很大程度上是由conversation-dependent PCA降低的。那么具体的分类流程如下：首先从对话中提取声学特征，然后将对话分成小的片段，从每一个小片段中提取出一个i-vector，然后利用k-means算法通过余弦距离来进行聚类，从而决定信号的哪些部分是由同一个说话者说的。接下来反复地重新聚类，从每一个类里面选取所有的数据，计算出新的i-vectors,然后把这些片段的i-vectors分配到(余弦距离)最近的i-vector类中。最后，用GMM(Gaussian Mixture Models)训练每一个类里的数据，重新分割优化，从而得到最终的结果。

## Experiments  

这里采用了CallHome语料库的英语部分的双人对话内容，一共选取了109段对话，32段用作CNN训练，77段用作测试，所有的对话都在10分钟左右，在8kHz的单一电话频道采样。实验的具体细节就不复述了，结果是通过fuzzy labeling，binary labeling和GLR metric三者对比得出的，EER对比显示fuzzy<binary<GLR，fuzzy的EER是17.47%。此外，用Diarization Error Rate(DER)来描述Speaker Diaration Result，用CNN fuzzy，GLR和恒定窗口三者进行对比，结果显示SDR的大小constWin<CNN fuzzy<GLR.  

## Conclusion  

总结一下，这篇paper主要对比了两种不同的SCD检测方法：GLR和CNN，结果显示CNN方法的准确率高于GLR方法。此外，作者还探究了GLR和CNN在i-vector基础的说话人区分系统中的表现，结果显示CNN的表现明显的优于GLR，与传统的固定窗口方法表现类似，这是由于充足的训练数据在GMM上训练，导致了重分割的可能性。在该系统中，CNN网络做出判断的依据只是1.4秒的窗口，并不需要其他信息的支撑，可以给出一个介于0到1之间的似然值，从而能够使用先验阈值。  

这篇论文的问题在于他并没有事先说明要实现的功能究竟是什么，我们读完可以发现其实是进行了两方面的对比，即SCD问题和SD问题，那么一开始并没有明确的说出，所以在看到介绍系统的时候我一脸懵逼，以及在experiment环节我并不明白为什么要进行两方面实验的介绍，直到看到最后的结果分析才看明白，另外论文里面居然有一些明显的typo，比如把than写成then，我不知道ICASSP的文章怎么会有这么低级的错误。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
