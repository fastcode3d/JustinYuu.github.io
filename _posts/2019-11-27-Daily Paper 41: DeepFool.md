---
layout: post
title: "Daily Paper 41: DeepFool"
description: "Notes"
categories: [CV-GAN]
tags: [Paper]
redirect_from:
  - /2019/12/24/
---

# Daily Paper 41 - DeepFool: a simple and accurate method to fool deep neural networks  

## Introduction  

这个月一直在写代码和准备考试，写的代码过两天会集中汇总传在github的[deeplearning-study](https://github.com/JustinYuu/Deeplearning-study)这个repo上，主要是把官方的几个tutorial跑了一遍，学了下一些官方的trick，感觉还是挺有收获的。此外之前用了一周的时间总结了一下deepfake的研究进展，链接总结在我的[Awesome-DeepFake](https://github.com/JustinYuu/Awesome-DeepFake)repo里面，还做了个PPT就当是简略版的literature review了，有时间也传在这个repo里面。deepfake的paper我略读了大几十篇，有时间再挑点好的精度+复现一遍。  

这里突然看一篇paper是因为有门课的大作业要求看一篇paper写阅读报告，这正好是我之前每天干的事情，于是就从给定的paper list里面选了一篇写一下。这里看的都是生成性对抗网络GAN方面的文章，我挑的这篇叫做DeepFool，貌似还挺出名的。  

这篇paper是我的dream school epfl的几个人发表在CVPR2016上的，主要介绍了一种简单的欺骗深度神经网络的方法。当下神经网络的发展可谓迅速，在很多图像分类问题上都有着很好的表现，但是这种神经网络架构对于一些精心设计的扰动图像来说分类效果可能并不稳定。在当下，并没有能够有效衡量深度分类器对于这种扰动的鲁棒性程度的方法，在这篇文章中，作者就试图填补该领域的这片空白，提出了一个叫做DeepFool的方法来高效的计算能够骗过深度网络的扰动，并用这种生成的扰动来定量的判断这些分类器的鲁棒性。作者的实验表明其方法在计算对抗性扰动的表现比其他算法都要好，能使得分类器更加鲁棒。  

深度神经网络在很多领域，比如生物信息学、计算机视觉、语音演讲等领域都有着STOA的表现，不过虽然表现很优秀，但正如之前所提到的，这些深度学习分类器对于数据中的对抗性扰动表现并不稳定。事实上，一些很小的扰动就可能会让判别器的输出完全不同，这里作者将引起分类器结果变化的最小扰动值定义为r。


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
