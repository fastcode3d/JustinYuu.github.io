---
layout: post
title: "Convolutional Neural Networks Chapter 3"
description: "Notes"
categories: [Convolutional-Neural-Networks]
tags: [Python]
redirect_from:
  - /2019/07/01/
---

# Convolutional Neural Networks Chapter 3  

本周是这门课程的第三周，主要介绍对象检测和自动驾驶领域的一些内容，编程作业也用了这一领域很火的yolo物体检测模型。  

## Detection algorithms  

实现对象检测的前提是能够对对象定位，因此吴恩达在这一章首先讲的算法就是对象定位(classification with localization)。通常来讲，需要定位和识别的有多种物体，因此一般情况下需要通过softmax进行分类识别。定位一般分为单物体定位和多物体定位，本周主要研究前者。  
如果是简单的classfication问题，那么只需要通过softmax分类就可以，但是现在的问题在于要识别物体的边框坐标，那么这时候就要定义三个向量，分别是表示物体是否存在的向量pc，边框的四个参数，分别是bx,by,bh,bw，代表着边框中心的横纵坐标，边框的高度和宽度，以及物体分类的one-hot向量。那么如果要探测物体是否存在，那么上述向量都是需要的，但是如果要探测物体是不是不存在，那么上述向量中只需要研究pc和one-hot中的该物体对应的值，并且事实上，不同的向量可以用不同的损失函数。一般的，可以设立一些特征点（landmark），进行特征点检测，从而识别关键轮廓上的坐标。但是值得注意的是，在所有的样本中，特征点要保持一致。  
完成了这些，就可以进行对象检测了。对于图像的检测，一般通过滑动窗口进行检测，窗口的大小由小到大不断增大，一般需要遍历多次，而且颗粒度不能够太粗，这就导致了对象检测的计算成本会变得很高，这就需要运用卷积的方式来进行滑动窗口。


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
