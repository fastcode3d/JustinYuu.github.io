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

从这章的名称中就可以看出，这一章的内容是大数据集，这里采用了kaggle里面非常著名的大数据集Cats Vs Dogs,这里也是用ImageGenerator进行分类，代码和上一门课最后一周的代码非常相似，这里是这一部分的[练习代码](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Convolutional%20Neural%20Networks%20in%20TensorFlow/Course_2_Part_4_Lesson_2_Notebook.ipynb)。  

在测试的时候，我们发现训练集的正确率很高，但是测试集的正确率很低，即出现了过拟合。此外，我们发现我们的图片会出现一些问题，比如误判，这时候我们就要想办法解决这类问题。这个时候Laurencce演示了一个很神奇的事情，在原有的算法中，一个猫的图片被误判成了狗，但是当Laurencce把图片中猫左右两侧的绿色背景裁减掉，只留下猫本身的时候，算法就能够正确判定其为狗。  

首先要了解这个现象出现的原因，以及解决过拟合问题，我们要具体的了解CNN是如何判定是猫还是狗的，所以我们将其可视化。根据可视化结果，我们发现对于猫，并没有明显的特征可以捕捉到，只看到了CNN检测出了许多条暗线；而对于狗，CNN能够捕捉到狗的鼻子和耳朵，正是这样的特征能够让CNN判定这些图片是否标记成狗。  

接下来，Laurencce把model.fit赋值为history，这样就可以在之后调用history来研究究竟是哪里出了问题。他将每一个epoch后的test acc和validation acc作图表示，之后发现在两个epoch之后交叉验证集的正确率基本上就不再上升了，这是因为我们只用了2000个数据进行训练，而不是整个kaggle提供的数据集，所以数据过少的情况下很容易出现过拟合。我们只需要加大数据量即可在一定程度上解决这个问题。  

## Weekly Exercise  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
