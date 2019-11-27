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

首先看数据集，作者从VidTIMIT数据集中选择视频，选择两个视频特征相似的视频组成一对，一共选了16对，然后用已有的代码使用GAN-based换脸算法对视频进行处理，在每一个对里面生成两个相互换脸的视频。作者针对低质量和高质量的视频分别设计了两个GAN模型，分别称为LQ和HQ。  

作者使用false acceptance rate(FAR), false reject rate(FRR)来评价分类系统的表现。作者将原始视频组和换脸视频组同时测量FAR，当两者之间的结果超过某一阈值θ时，说明人脸识别系统无法准确的识别Deepfake视频中的人脸。当评价Deepfake检测的时候，作者将其视为一个二分类问题，将其分为训练集和测试集进行训练和测试，同样使用ERR(equal error rate)和FRR进行评估。  

## Analysis of Deepfake Videos  

作者测试了基于FaceNet和VGG的人脸识别系统的表现，并用一系列检测换脸虚假视频的baseline方法对GAN-based Deepfake视频进行了测试，结果如下。  

对于人脸识别，Facenet和VGG在有标注的人脸识别上能在LFW数据集上达到99.63%和98.95%的识别率，可以说是非常准确了。在作者的数据集上，在正确的人脸视频中，EER也仅为0.00%和0.03%，再一次表明了这两个人脸识别系统的优秀。但是在Deepfake视频上，Facenet识别LQ和HQ的FAR分别是94.38%和95.00%，而VGG分别是88.75%和85.62%。这基本上说明了主流的人脸识别系统无法对Deepfake视频进行原本正确人脸的识别，Facenet作为识别率更好的网络，居然识别Deepfake的错误率更高，可以看出主流的人脸识别完全被Deepfake“骗”了。  

对于虚假视频检测，作者首先采用了跨模态的视听对齐方法。具体操作是使用MFCC处理音频特征，使用嘴部标记的距离作为视觉特征，使用PCA来将视听特征合在一起并降维，LSTM网络用来训练模型使其能够分离修改过的和没修改过的视频，作为分类器使用。接着作者又使用了基于图像的系统，主要有以下三种：Pixels+PCA+LDA,IQM+PCA+LDA,IQM+SVM，其中pixels就是原始像素，IQM为视觉特征，PCA+LDA和SVM是两种不同的分类器。  

最后的比较显示，在LQ Deepfake上，视听嘴唇对齐的方法EER和FRR最高，为41.8%和81.67%，表示跨模态方法几乎无法检测Deepfake，但是IQM+SVM方法可以达到3.33%和0.95%，表示其对虚假视频的检测有很好的的效果，在HQ Deepfake上，IQM+SVM的EER和FRR也只有8.97%和9.05%，错误率高了一些，但是仍然在10%以内。  

## Conclusion  

本文得出的结论主要如下：作者提供了一套GAN-based Deepfake的数据集。目前主流的人脸识别系统无法正确识别GAN-based Deepfake视频中的人脸。视听对齐无法正确检测GAN-based Deepfake视频，因为GAN可以自动生成匹配的面部表情，而IQM+SVM能够很好的进行判别，不过作者仍然认为，随着新的换脸算法的不断提出，检测Deepfake虚假视频将会越来越难，投入到这一领域的研究也就显得愈发重要。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
