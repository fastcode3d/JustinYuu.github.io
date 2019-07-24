---
layout: post
title: "Convolutional Neural Networks in TensorFlow Chapter 3&4"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/24/
---

# Convolutional Neural Networks in TensorFlow Chapter 3%4  

## Chapter 3  Transfer Learning  

第三章介绍迁移学习，迁移学习是一种很重要的技能，他可以大幅度减小我们训练的复杂度和时间，并且可以通过迁移学习的原数据集中学习到某些我们的数据集无法学习到的特征，从而弥补我们的数据集中的缺陷。此外，我们的训练集囿于计算能力，经常不够大，通过迁移学习可以使我们扩充我们的数据集，从而避免过拟合。通过迁移学习，一些无法进行神经网络训练的人们都可以参与到机器学习中来。  

这里用了一个inception网络作为迁移学习的例子，inception网络是一个非常深的网络，在这里将其赋值为pre_train_model，这样就可以用其调用方法查看其细节，或者从中提取某些层。用一个for循环将inception里所有的层设置为不可训练，即锁定这些层，具体方式是将layer.trainable参数设定为false。用last_output提取我们需要的所有层的最后输出，然后将其作为我们新的网络的输入。这里是课程所用的[DEMO](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Convolutional%20Neural%20Networks%20in%20TensorFlow/Transfer_Learning.ipynb)  

接下来介绍的是dropout，dropout作为一种很有用的trick，可以有效的减轻神经元之间的依赖性，有效的增加训练的准确率，减少过拟合现象，是一种优秀的正则化方法。Dropout的实现非常简单，只需要在Dense层之间加一行 ` x = layers.Dropout(0.2)(x)` 即可。  

这一章的练习是用迁移学习来更好的分辨人和马。这一次的练习将前面的内容都整合了起来，有迁移学习，有data augmentation，也有callbacks，也有ImageDataGenerator，是一个很好的练习材料，这里是我的代码[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Convolutional%20Neural%20Networks%20in%20TensorFlow/Exercise_7_Question.ipynb)。  

## Chapter 4 Multiclass Classification  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
