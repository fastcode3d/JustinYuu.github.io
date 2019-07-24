---
layout: post
title: "Convolutional Neural Networks in TensorFlow Chapter 2"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/23/
---

# Convolutional Neural Networks in TensorFlow Chapter 2  

第一周结束的时候留下了一个问题：数据集太小会导致过拟合问题。可数据从哪里获取呢，这又是另外一个问题，所以这周的任务致力于解决数据不够的问题，即采用data augmentation技术来扩充我们的训练集，从而通过增加训练集数据规模的方式来解决过拟合问题。  

TensorFlow的数据增强功能可以让自己在不覆盖原有图片，不改变原有数据规模的前提下，在内存里增加数据集完成数据增强。TensorFlow的数据增强效果很好且很快速，所以这已经成为了当今数据增强的主要手段。  

具体的代码实现方式是通过ImageDataGenerator这个方法实现，通过增加一些参数，比如rotation_range,shear_range,width/height_shift_range,zoom_range,horizontal_flip等等进行data augmentation。在代码中的反映非常明显，在进行数据增强之前，验证集正确率和训练集正确率差距十分明显，而进行数据增强之后两者正确率基本持平且接近于100%。猫和狗的例子是这样，之前建立的分辨人和马的模型也是一样。  

本周的作业是应用data augmentation来增加验证集的准确度，并能够分辨一些更为复杂的图片，这里是练习[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Convolutional%20Neural%20Networks%20in%20TensorFlow/Exercise_6_Question.ipynb)


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
