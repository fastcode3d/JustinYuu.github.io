---
layout: post
title: "Introduction to Tensorflow Chapter 2&3"
description: "Notes"
categories: [Introduction-to-Tensorflow]
tags: [Python]
redirect_from:
  - /2019/07/21/
---

# Introduction to Tensorflow Chapter 2&3  

第二周主要介绍计算机视觉和CNN，这里用著名的MINST数据集的升级版Fashion-MINST进行识别和运算。值得一提的是MINST的确是非常著名的数据集，在Udacity的MOOC中用的也是其升级版not-MINST进行学习的。  

在标注数据时，用数值标注是最好的选择，用人类的其他语言进行标注可能会导致大偏差，以及不同语言下识别的不便利。在CNN的体系中，输入的数据将会导入到一个flatten层中，将多维的数据压缩扁平化，使其参数规模变小方面后续操作。接下来通过一系列全连接层、卷积层、池化层的组合，最终得到结果。  

这里用了一个非常不错的小练习来了解CNN，我把链接放在[这里](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Course_1_Part_4_Lesson_2_Notebook.ipynb)，这个练习中介绍了一个很重要的东西：callback。通过callback，你可以不必等到神经网络计算到最后，而是在达到需要的准确率后就停止计算。callback需要重写callback类里的on_epoch_end函数实现，重写完之后，建立callback实例并在fit中增加callback参数即可。  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
