---
layout: post
title: "Convolutional Neural Networks in TensorFlow Chapter 1"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/23/
---

# Convolutional Neural Networks in TensorFlow Chapter 1  

## Introduction  

第二门MOOC继续对TensorFlow的卷积神经网络应用进行学习。第一个视频主要介绍了这一门课程的四周主要学习的内容，包括大数据集的使用，data augmentation，以及迁移学习和multiclass，在这个视频里Andrew还送了Laurence心心念念的在AI for everyone这门课程里出现的马克杯……  

此外，这里还明确的说明了这门课程所教授的Tensorflow的版本：1.x和2.0都支持。在colab中，默认的版本是1.x，所以我们需要添加一行代码`!pip install tensorflow==2.0.0-alpha0 `来把版本更新到TensorFlow2.0 alpha版本。那我个人而言安装的版本就是tf2.0，所以当然要学习2.0了，因此以后的代码都将会按照2.0版本的语法来写。  

## Large Dataset  

从这章的名称中就可以看出，这一章的内容是大数据集，这里采用了kaggle里面非常著名的大数据集Cats Vs Dogs,这里也是用ImageGenerator进行分类，代码和上一门课最后一周的代码非常相似。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
