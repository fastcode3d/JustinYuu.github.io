---
layout: post
title: "Introduction to Tensorflow Chapter 2&3"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/21/
---

# Introduction to Tensorflow Chapter 2&3  

第二周主要介绍计算机视觉和DNN，这里用著名的MINST数据集的升级版Fashion-MINST进行识别和运算。值得一提的是MINST的确是非常著名的数据集，在Udacity的MOOC中用的也是其升级版not-MINST进行学习的。  

在标注数据时，用数值标注是最好的选择，用人类的其他语言进行标注可能会导致大偏差，以及不同语言下识别的不便利。在CNN的体系中，输入的数据将会导入到一个flatten层中，将多维的数据压缩扁平化，使其参数规模变小方面后续操作。接下来通过一系列全连接层、卷积层、池化层的组合，最终得到结果。  

这里用了一个非常不错的小练习来了解DNN，我把链接放在[这里](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Course_1_Part_4_Lesson_2_Notebook.ipynb)，这个练习中介绍了一个很重要的东西：callback。通过callback，你可以不必等到神经网络计算到最后，而是在达到需要的准确率后就停止计算。callback需要重写callback类里的on_epoch_end函数实现，重写完之后，建立callback实例并在fit中增加callback参数即可。  

这一周的编程作业也很简单，和练习中的最后一个基本相同，只不过callback停止的准确率变成了99%，这里是[源码](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Exercise2_Question.ipynb)  

由于这门课程的内容实在是太少了，所以我把第三周和第二周的内容合并在一个博客里写了，接下来是第三周的内容。  

第二周的时候口口声声的说要介绍CNN，结果到了最后连卷积都没接触过，第三周总算要接触一下了，结果只是简单的介绍了一下CNN的卷积层，推荐的视频还就是刚学完的吴恩达MOOC里的视频……  

接下来用了一个视频简单的介绍了一下具体的代码，简而言之，DNN到CNN的转变只是在原有的Flatten层前面加上若干层卷积层和池化层。接着用一个具体的练习示例来演示了卷积层是如何检测到图像的特征的，以及不同的卷积层带来的不同影响。这里是练习的[笔记](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Course_1_Part_6_Lesson_2_Notebook.ipynb)  

接下来又用了一个练习笔记来详细的做了一遍卷积，并探究了卷积带来的具体作用以及不同卷积核对卷积效果的影响。从整篇练习的结果中可以明确的看出，不同的卷积核所探测的目标不同，有垂直检测，也有水平检测，也有其他特征检测。这里是练习的[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Convolutions_Sidebar.ipynb)  

本周的课程作业是实现一个Fashion-MINST的改进版，这里是[源码链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Exercise_3_Question.ipynb)  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
