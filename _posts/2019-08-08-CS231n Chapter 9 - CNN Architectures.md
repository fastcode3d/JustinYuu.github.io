---
layout: post
title: "CS231n Chapter 9 - CNN Architectures"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/08/05/
---

# CS231n Chapter 9 - CNN Architectures  

## Introduction  

这周将会学习一大堆CNN的架构，课程将使用AlexNet、VGG、GoogLeNet、ResNet作为案例进行讲解学习，并同时介绍一些其他的CNN架构，比如NiN,Wide ResNet,ResNeXT,Stochastic Depth,DenseNet,FractalNet,SqueezeNet等等。  

## AlexNet  

首先是AlexNet，这是2012年Hinton老爷子的高徒Krizhevsky等人建立的，一举多得当年ImageNet的分类冠军。AlexNet的输入规模是227×227×3，第一层是第一卷积层CONV1,11×11的过滤层，步幅为4，数量为96，卷积运算后输出的规模为55×55×96（(227-11)/4+1），该层的总参数数量为(11*11*3)*96 = 35K个。第二层是第一池化层POOL1，池化filter的size是3×3，步幅为2，输出的体积为27×27×96，这一层的参数为0.以后的层和这两个大同小异，就不具体计算了，最后经过全连接层后输出的最后尺寸是1000neurons，也就是1000×1的One-hot向量。  

AlexNet第一次采用ReLU，并使用了归一化层，其使用了大量的data augmentation，其dropout的参数为0.5，batch size为128，动量参数为0.9，learning rate为0.01，当验证集准确率趋于平缓时减少10%，这些都是超参数的细节，就不多赘述了。值得一提的是，AlexNet当时是在GTX580 gpu上训练的，当时的显卡只有3G的显存，他们将所有的网络分布在两个GPU上，神经元平均分布在两个GPU中间。  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
