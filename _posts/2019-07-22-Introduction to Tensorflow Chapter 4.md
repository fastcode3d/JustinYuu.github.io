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

本周将目光聚焦于一些真实场景的应用领域。首先从非洲木薯的灾害防治与检测入手，介绍机器学习和神经网络是如何通过TensorFlow这一框架应用到实际场景中的。  

首先介绍了一个很有用的功能：预处理图像生成器(ImageGenerator)，通过调用API，可以轻松的将未标注的图像进行预处理，以供后续训练和测试使用。具体的预处理方式是import tensorflow.keras.preprocessing.iamge之后，import ImageDataGenerator。具体的代码如下：  

	train_datagen = ImageDataGenerator(rescale=1./255)  
	train_generator = train_datagen.flow_from_directory(
		train_dir,
		target_size=(300,300),
		batch_size = 128,
		class_mode = 'binary')  
是

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
