---
layout: post
title: "CS231n Chapter 5 - Convolutional Neural Networks"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/07/31/
---

# CS231n Chapter 5 - Convolutional Neural Networks  

## Introduction  

这一周终于来到了卷积神经网络CNN，CNN的历史可以追溯到Mark I感知机，那个时候还没有反向传播，只是用一个固定的update rule来更新权重。在1960，Adaline/Madaline被发明了，这是一个多层的感知机网络，但是反向传播还是没有出现，直到1986年，反向传播才得以应用。在2006年，Hinton老爷子发表了一篇论文，证明我们可以发展深层网络并能得到很好的预测效果。在2012年，出现了图像识别领域里程碑性质的论文，是由Geff Hinton实验室的Alex Krizhevsky等人发表的，他们的神经网络可以在ImageNet上有非常好的表现。在神经学领域的发展我就略过不记录了，因为我实在是对这领域不太熟。在1998年，LeCun使用了LeNet-5用于图像识别，特别是数字识别这一领域，2012年，AlexNet发明，从此时候CNN在不断的更新迭代，应用也越来越广泛，下面介绍了一大堆CNN的应用，在此略过不表。  

## Convolution and Pooling  

在之前我们接触过一点点完全连接层，其作用是将原尺寸stretch成一个列向量，然后导入激活函数中进行运算和分类。这里的卷积层，选取一个x×y×z大小的过滤器filter，然后与原数据进行卷积运算。这里是吴恩达MOOC的CNN部分笔记[链接](http://justin-yu.me/blog/2019/06/11/Convolutional-Neural-Networks-Chapter-1/)，这里有stanford的数学大佬提问这里的卷积是否需要将W转置，那么数学上的卷积是需要的，但是这里我们就省了这一步，直接用转置后的W作为W矩阵，为了方便表达，在DL领域也称为卷积运算。  

那么我们目前的卷积网络没有池化层的介入，每一层都是激活函数和过滤器规模不同的卷积层，这里我们可以用可视化工具来明确每一个卷积层究竟在做什么，可视化的结果显示随着层数的不断加深，我们的网络可以识别更为复杂的图像。那么把视角放大，我们发现我们的神经网络是由卷积层、非线性激活层、池化层排列组合而成的。把视野再缩小，我们发现卷积操作之后矩阵的规模发生了变化，具体的变化是减去了过滤器的规模再加1，这是由于卷积操作导致的。  

此外，我们也可以将步幅stride设为大于1的任意值，从而更快速简略的完成卷积操作，但是要注意步幅不要太大，并且必须要完整的fit整个矩阵的规模。此外还需要padding操作，以保持我们的输出不至于太小影响我们操作，一般用0来填充边缘至原尺寸，那么填充完毕的原矩阵大小为n+2p,p为padding的大小。有学生问如果原图片的长宽不相等，那么stride是否也要长宽不同以求达到自适应呢？答案是可以，但没必要，一般情况下我们都会选择长款相同的原数据，那么stride在长宽两方向上自然也就相同了。  

那么总的参数是多少呢？假设有K个过滤器，K'为上一层的过滤器数目或者原图片的通道数，F为图片的尺寸（假设长款一致），那么总的参数大小就是(F×F×K')×K+K，加上一个K是因为有K个biases b需要加在后面，而前面的那部分值就是权重W。此外我们还可以采取1×1卷积，显然1×1卷积并不能起到卷积的效果，它只是将所有的输入数据放大或者缩小了同倍数，但是它还是有别的作用，首先比较好理解的作用便是升维/降维，通过设置不同的过滤器数量，从而将数据的维度变成过滤器数量的大小，也就是缩小了数据的通道数。至此，缩小长宽可以使用池化层，缩小通道数可以使用1×1卷积，数据中所有的部分都可以被缩小/增加了。此外，它还可以利用后接的非线性激活函数来增加非线性，具体来讲，可以使用通道规模相同的1×1过滤器，使得完成一次卷积+非线性整流后可以达到规模不变的效果，那么在这一次操作中，由于平白无故的多进行了一次非线性操作，因此所训练的网络可以学习到更为复杂的函数形式，从而使神经网络更为强大。（这一段来自我之前在吴恩达CNN MOOC中的笔记）  

接下来介绍池化层，池化层的作用就是简单的将尺寸减小，并在此基础上尽量保留原数据的特征。池化分为最大池化和平均池化两种，最大池化是选取区域内最大的值保留，而平均池化是取平均值。这里有同学问既然stride和pooling都是为了减少尺寸，那么可不可以用stride代替pooling呢？我感觉这个问题非常好，Serena的回答是都可以，但是pooling貌似更好一些，我在这里找到了一篇文献，试图分析一下何种效果更好，这里是中文讲解[链接](https://blog.csdn.net/u013010889/article/details/85635926)。  

这里是这一章的笔记[链接](https://cs231n.github.io/convolutional-networks/),其中提到的dilated和FC与Conv层的转换都是很新颖的想法，值得一看。  

## Assignment 1  

到这里本门课程的Assignment终于出现了，cs231n的作业容量和难度远远超出了我的想象，果然Stanford的学生都是大神，很多部分我都参考了网上其他同学的代码，经过了整整两天我才完成所有的编程任务，也就是5个IPython Notebook加上5个py文件，但是不得不说收获也是挺大的，无论是对numpy，还是反向传播，还是整个机器学习的流程都有了一定的认识。这里是我的编程代码[链接](https://github.com/JustinYuu/Deeplearning-study/tree/master/cs231n/Assignment%201)  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  