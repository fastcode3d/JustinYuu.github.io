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

第四章介绍的是多任务分类。在之前我们接触的大多都是二元分类，而在很多场景下，我们的分类目标将会超过两个，这时候之前介绍的二元分类就无法使用了，所以这周的内容就致力于解决这个限制。此外，机器合成图片能够快速而有效的增大数据集的规模，从而能够达到更好的训练效果，这一周也同样会接触图像的人工合成。  

这章采取的例子是Laurence自己制作的石头剪刀布数据集，其中包括各个肤色大小的手型，以及一些由他人工制造的一些手型。那么首先我们要做的是将目录里的两项改成三项，这很简单也很好理解。其次就是改进输出项的规模，在二元分类中，输出项的规模为1，只需要输出是0还是1即可，但是现在既然要进行多任务分类，肯定需要用到softmax函数，所以输出的值是一个softmax的结果向量。  

这一章的内容实在是太简单。所有的内容到这里就结束了。这里是课程示例[代码](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Convolutional%20Neural%20Networks%20in%20TensorFlow/rock_paper_scissors.ipynb)  

这一章的练习是来自于kaggle的一个手势表示字母的数据集，通过训练该数据集，得到一个可以正确识别手写数字的神经网络。这里是我的代码[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Convolutional%20Neural%20Networks%20in%20TensorFlow/Exercise_8_Question.ipynb)  

这样第二门课程就学完了，下面就要学习TensorFlow下RNN的使用了。这系列课程的内容不多，剩下的两门课争取在这周，也就是接下来的四天学完。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
