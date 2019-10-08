---
layout: post
title: "Daily Paper 01 - Convolutional Neural Network for Speaker Change Detection in Telephone Speaker Diarization System"
description: "Notes"
categories: [Daily Paper]
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

## Experiment  

在这篇paper之前，他们其实已经发过一篇paper了，那一篇paper也用CNN进行了实验，结果显示虽然在BIC指标中表现良好，但是仍然存在缺点，比如只用了512个频率中的256个低频，这是因为他们之前认为高频对于SCD来说并无卵用，但是后续的实验打脸表明还是全谱效果更好。此外，他们之前的实验有识别具体时间的不准确性，这是由于电话交谈的性质导致说话者会频繁的切换所致。那么他们采取了一个新的标注策略，即用模糊标注来代替二分标注，当说话者的切换正好定位在分析窗口的正中央时，取值为1，然后逐渐的向两端线性减少直至0为止。  

此外CNN的结构如下：三层Conv和ReLU的混合，每层之后加一层最大池化和BN层，最后跟两层FC层，FC层采用sigmoid作为分类函数。第一个Conv层filter的尺寸是根据频谱图中的高能量语音谐波的一般矩形决定。（这是说的啥？）他们之前double了filter的尺寸，结果发现表现好了一点。整个CNN作为一个回归器，采用二元交叉熵作为训练的损失函数，使用SGD以64的batch训练，学习率随着训练decay，不过没有说明幅度，估计只改变了一次，最后使用RMSprop调优。  




---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
