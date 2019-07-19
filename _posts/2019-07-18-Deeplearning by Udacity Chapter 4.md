---
layout: post
title: "Deeplearning by Udacity Chapter 4"
description: "Notes"
categories: [Deeplearning-by-Udacity]
tags: [Python]
redirect_from:
  - /2019/07/18/
---

# Deeplearning by Udacity Chapter 4  

第四章介绍CNN，视频仍然是以1分钟-两分钟为一个单位，简单的介绍了卷积操作。虽然介绍的比较简略，但是基本上覆盖的比较全面了，特别是用了一张非常形象的图片来阐述卷积的作用，即逐渐挤压前两个维度，并扩充第三个维度，这种卷积操作比较像squeeze。  

此外，卷积的时候需要确定步幅stride，以及对于边界的填充padding。padding有两种，valid和same，不超过边界的padding叫做valid padding，超过原尺寸填充为0使之和输入尺寸相等的叫做same padding,也就是说valid padding就是不padding咯。  

当然除了卷积层以外还有池化层，包括max-pooling和avg-pooling，在这两分钟的视频中居然都提到了LeNet和AlexNet，足以见得这两个CNN网络的重要性。  

接下来介绍了1×1卷积，不过他既没有讲清楚细节，也没讲明白存在的意义，只是讲了它的作用是让整个网络变的更加简洁。紧接着介绍了inception网络，非常简要的说明了一下inception的组成，这里讲的实在太简单，我都没有可以记录的，就把吴恩达MOOC的这一节笔记放在这里8:[Here](http://justin-yu.me/blog/2019/06/29/Convolutional-Nueral-Networks-Chapter-2/)  

从这门偏工程的MOOC中就可以看出，现在的工程岗位对于理论知识并不需要多深的理解，只要对整体的框架有所理解，能够了解总体的流程和实现的方法，会调库完成需求就可以了，这让我越来越觉得自己不应该局限于这种较为低端的工作，还是尽量往更底层的原理入手，争取开发出效果更好的库。  

不管要干什么，先练熟coding再说，这周的重点是构建一个CNN网络。以后我的研究方向就是CV，所以相应的也要重视一下这方面。不过这周的编程作业并不能进行下去，课程提供的代码我的环境就跑不通，一直显示CUDNN无法运行，我不知道这是因为TensorFlow与cuda版本的问题还是因为TensorFlow2.0代码不兼容的问题，总之我还是尽快把视频内容看完，然后赶紧上一门学习TensorFlow2.0的课程把。    

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
