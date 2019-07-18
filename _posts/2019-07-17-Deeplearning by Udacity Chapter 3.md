---
layout: post
title: "Deeplearning by Udacity Chapter 3"
description: "Notes"
categories: [Deeplearning-by-Udacity]
tags: [Python]
redirect_from:
  - /2019/07/17/
---

# Deeplearning by Udacity Chapter 3  

第三章开始介绍深度学习和神经网络。  

## 神经网络  

这章秉承着这门课一贯的风格，简单的介绍了隐藏层和relu函数之后，就让你自己实现一遍用relu函数和隐藏层将简单的逻辑回归改成有隐藏层的非线性激活函数。此外还介绍了参数的数量，假设输入的数据X有N个参数，输出有K个参数，那么总共需要训练的参数为(N+1)*K个。  

介绍了RELU之后，Vincent开始介绍为什么需要引入非线性函数。吴恩达之前也讲过，目的当然是为了更好的进行分类，用更为复杂的函数更好的完成分类的任务。  

到了这章视频的中间部分，终于开始令人兴奋的数学内容环节了。我就知道他肯定逃不过讲链式求导，不然反向传播没法讲。果然不出我所料，他的反向传播过程没有任何的数学内容，我不明白他讲解链式求导的意义何在。全文只是在将我们需要正向传播+反向传播来得到更新的权重，但是这些只需要通过框架帮我们完成就可以了，并没有讲到原理。这个速成班的水分是真的大- -，不过我是为了实践来听的这门课，理论部分复习一下吴恩达大大的MOOC笔记就好~  

紧接着就来到了这门课丰富的实践环节，有了上一个笔记做基础，我有了一定的经验，并且这次编程任务需要用到TensorFlow了。这周的任务是建立一个全连接层，主要是练习内部隐藏层和relu的用法。这里我总结了一下TensorFlow的用法，一般情况下都是：  
1.先实例化图 with tf.Graph().as_default():  
2.load训练集，用tf.constant()将其赋值为新的tf数据集变量。  
3.确定需要训练的参数并赋初始值，用tf.Variable()赋值。  
4.propagation，一般用softmax和cross_entropy来得到损失函数值。  
5.back prop,用著名的optimizer语句，当然这里还没有优化方法，我估计很快就会加入Adam优化等一系列优化。  
6.predict，仍然是用softmax作为输出。  
至此已经定义完需要的操作，之后用session进行训练。  
7.with tf.Session() as sess:  
8.tf.global_variables_initializer().run()  
9.开始循环, _ , loss, predictions = sess.run(\[optimizer,loss,train_prediction])  
此外，如果用小批量或者批量梯度下降的话还需要用placeholder来将一批数据放进去从而进行训练，形式为tf.placeholder(tf.float32,shape=(batch_size,dataset_size))。  
通过一个实例，让我对整个TensorFlow的过程有了一个基本的了解。从这方面来讲，这的确是这门MOOC优秀的地方，至少吴恩达MOOC的编程作业的一大堆文字说明把我绕的头晕眼花，这里一步步增加内容的方法反而让我非常适应。  

比较惨的是作为勇敢下载TensorFlow2.0的人，很多1.13里面的函数在2.0里面都没有或者改名字了，这里我找到了一篇官方文档，个人觉得非常好用，可以查找对应的函数变成了什么:(神器)[https://docs.google.com/spreadsheets/d/1FLFJLzg7WNP6JHODX5q8BDgptKafq_slHpnHVbJIteQ/edit#gid=0].  

这次我终于可以自行完成任务了，这里是我的源码[地址](https://github.com/JustinYuu/Deeplearning-study/blob/master/Deeplearning-Udacity/2_fullyconnected.ipynb)  

## 神经网络的优化  

本章的第二部分介绍神经网络的优化，目前的优化非常基础，只有正则化和dropout两种，最后用一个编程作业做结尾。  

正则化介绍的就是常见的L2正则化，通过在尾部增加一个权重矩阵的L2范数，再乘以一个常数，从而减少损失函数对结果的影响，从而防止过拟合并提高泛化能力。当然这里还是啥有用的都没讲到，我把我之前分享的一篇博客再分享一遍:[正则化为什么能防止过拟合](https://www.cnblogs.com/alexanderkun/p/6922428.html)。 在我分享的博客里顺便把dropout也讲了，一块看了我就不再写一遍了。  

这里的编程作业很奇怪，我充分体会到了调参的不易，正则化还好，加上dropout反而准确率降低了，此外最后的深层神经网络的准确率表现也很差，找了半天不知道错误在哪里。[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Deeplearning-Udacity/3_regularization.ipynb)  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
