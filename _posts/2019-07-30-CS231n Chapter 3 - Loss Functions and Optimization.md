---
layout: post
title: "CS231n Chapter 3 - Loss Functions and Optimization"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/07/30/
---

# CS231n Chapter 3 - Loss Functions and Optimization      

## Introduction  

在上节课中，我们已经引入了损失函数的概念，在课程给出的笔记2中也明确的说了损失函数即为我们的算法给出的预测值和正确值之间的差距大小，而我们的目标就是要尽可能的降低损失函数值的大小。那么这堂课的主要内容就是探究一下损失函数的不同形式以及损失函数的一些优化方法。  

## Linear classification II  

上周的线性分类准确的讲还没有完全讲完，这里将上节课的例子缩小了一下，将识别的10个类别变成了3个，这里Justin试图用这个例子向我们展示最后的损失函数的样子，即将每一个小的损失函数加起来取平均值，不仅仅是线性分类，这也是几乎所有损失函数的格式。如果看了上周给出的第二个笔记，我们会发现在第二个笔记的后半部分多了一些关于SVM的内容，这些内容就是这里所要将的线性分类的第二部分。  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
