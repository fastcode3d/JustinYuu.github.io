---
layout: post
title: "Introduction to Tensorflow Chapter 4"
description: "Notes"
categories: [Introduction-to-Tensorflow]
tags: [Python]
redirect_from:
  - /2019/07/22/
---

# Introduction to Tensorflow Chapter 4  

本周将目光聚焦于一些真实场景的应用领域。首先从非洲木薯的灾害防治与检测入手，介绍机器学习和神经网络是如何通过TensorFlow这一框架应用到实际场景中的。接下来通过一个人马分类识别器的搭建来开展这一章的学习。  

首先介绍了一个很有用的功能：预处理图像生成器(ImageGenerator)，在之前的MINST和fashion-MINST中，数据都是已经分类和标注好了的，所以不需要我们提前清洗数据。但是在我们平时的训练中，数据并不一定是标注好了的，所以我们需要对图像进行预处理。通过之前Udacity的MOOC可以了解到，自己手动标注数据是非常繁琐的工作，但是这里我们通过调用API，可以轻松的将未标注的图像进行预处理，以供后续训练和测试使用。具体的预处理方式是import tensorflow.keras.preprocessing.iamge之后，import ImageDataGenerator。具体的代码如下：  

	train_datagen = ImageDataGenerator(rescale=1./255)  
	train_generator = train_datagen.flow_from_directory(
		train_dir,
		target_size=(300,300),
		batch_size = 128,
		class_mode = 'binary')  
		
上述代码中，rescale的作用是均一化数据，train_dir是图像子目录的根目录，target size是目标尺寸，class_mode指的是分类方式，这里由于是一个识别人和马的分类器，所以采取二分分类。这是训练生成器的代码，交叉验证集的验证生成器代码应该与其相同。  

之后就是正常的构建神经网络，在这个例子中，由于是彩色图像，所以图片第三维度的值应该是3（R,G,B），此外卷积层-池化层组合共有3层，其余与上一个神经网络架构相同。model.compile方法的时候，我们采用binary_crossentropy二分交叉熵损失函数和RMSprop均方根传递优化算法。在fit的时候，不用以前使用的model.fit方法，而是采用model.fit_generator方法来对应开头设计的图像生成器。  

损失函数有很多种，[这篇](https://gombru.github.io/2018/05/23/cross_entropy_loss/)文章详细的介绍了不同损失函数的区别以及各自的数学公式，介绍的非常详细，值得一看。  

接下来用一个[colab练习文件](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Introduction%20to%20Tensorflow/Horse_or_Human_NoValidation.ipynb)来实现这个人马分离器。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
