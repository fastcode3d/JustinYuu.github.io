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

换脸的第一人士Bitouk等人在08年发的一篇paper，该paper的主要思想就是从一个数据库中找到一个和原本的人脸非常相似的图像然后进行巧妙的替换，从而达到以假乱真的效果。不过这篇paper的局限性在于其无法完成任意两个图片的无缝替换，只能替换原本比较相似的图像。在神经网络风靡之前，大多传统方法都是靠的是人脸之间的相似度寻找来实现的。  

第一个使用GAN来进行换脸的是Korshunova等人，这篇paper稍后会进行分析。此外通过LSTM架构的神经网络来从音频演讲中合成嘴部特征也是一个相关的工作，例子是合成奥巴马演讲那篇paper，稍后也会阅读。那么随着这些paper的发表，这些换脸视频的应用随之出现，造成了Deepfake现象。  

那么随着Deepfake现象的不断升温，针对Deepfake视频的检测也就变得越来越需要，但是目前对于基于GAN的Deepfake视频的检测手段仍然非常少，可用于训练的数据集也几乎没有，Zhang等人提出了一个基于SURF描述器和SVM分类器的方法，用于分辨经过色彩调整和基于高斯模糊的smoothing换脸图像，Agarwal等人也用了一个基于LBP形式的特征和SVM分类器的方法，用来分辨通过Snapchat进行的换脸图像。Rossler等人提出了最全面的非Deepfake换脸数据集，共有来此超过1000个视频的500000张图片，作者还评价了STOA的伪造分类和分割的方法。作者使用Face2Face方法来生成的数据集，该方法主要基于表情转换，使用3D面部模型和预训练口腔内部的数据集实现。此外还有一个最新的方法表明使用眨眼检测可以有助于帮助Deepfake视频的检测。  

经过以上的related work介绍，基本上可以看出没有明显针对GAN-Deepfake方法的Deepfake数据集，那么如果没有数据集，也就没法评判上述方法究竟在识别GAN-Deepfake视频的时候管不管用。事实上作者认为当前基于GAN的Deepfake模型可以很好的模拟面部表情，嘴唇移动和眨眼，那么现在基于这些而进行分类的算法很有可能无法使用，所以作者认为探究一下GAN-Deepfake模型的表现是非常有必要的。  

## Deepfake dataset  

首先看数据集，作者从VidTIMIT数据集中选择视频，然后用已有的代码使用GAN-based换脸算法对视频进行处理，然后将每一



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
