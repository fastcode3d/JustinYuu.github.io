---
layout: post
title: "Daily Paper 37: DeepFakes dataset"
description: "Notes"
categories: [MMML-DeepFake]
tags: [Paper]
redirect_from:
  - /2019/11/23/
---

# Daily Paper 37 - DeepFakes: a New Threat to Face Recognition? Assessment and Detection  

## Introduction  

最近要看几篇deepfake虚假视频方向的paper。由于我并没有找到一个deepfake方面的paper list，所以我只能像大海捞针一样从arXiv里面找，那么就无法保证顺序完全符合时间线。此外由于主要是对当前的一些情况做一下分析，所以对于Related works可能会写的比较多，而对于模型写的会粗略一点，而更注重于结果的比较。  

这篇paper是18年底上传在arXiv的，主要介绍了一个用于检测DeepFake视频的数据集，用来应对当前愈发严重的DeepFake现象。作者主要通过使用基于GAN的开源软件创建Deepfakes，然后强调了训练和混合参数可以显著的影响到产生的视频的质量，并用实例说明了这点。作者证明了STOA基于VGG和Facenet的人脸识别系统几乎无法辨别错误的Deepfake视频，这表明检测Deepfake视频这件事情是很有必要的。经过很多baseline方法的比较和考量，作者发现基于嘴唇对齐检测的视听方法并不能检测出DeepFake视频，而表现最好的方法是基于视频质量指标的，该方法经常用在表示攻击检测领域，能够达到8.97%的错误率。作者总体看来基于GAN的DeepFake无论对人脸识别还是虚假视频检测来说都是一项相当困难的任务，并且随着后续换脸技术的不断发展，这一任务的难度会更大。  

作者做的最为重要的工作，还是搞了一套从VidTIMIT中选取的数据集。之后作者用这套数据集和两种人脸检测网络VGG和FaceNet进行了当前人脸识别结果的评估，最后使用audio-visual方法，presentation attack detection attacks方法（PCA、LDA）和基于图像质量指标（IQM）和支持向量机（SVM）的方法进行了虚假视频的检测。  

## Related Work  

换脸的第一人士Bitouk等人在08年发的一篇paper，该paper的主要思想就是从一个数据库中找到一个和原本的人脸非常相似的图像然后进行巧妙的替换，从而达到以假乱真的效果。



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
