---
layout: post
title: "Introduction to Tensorflow Chapter 1"
description: "Notes"
categories: [Introduction-to-Tensorflow]
tags: [Python]
redirect_from:
  - /2019/07/20/
---

# Introduction to Tensorflow Chapter 1  

本来是要看一下cs231n的，但是由于Udacity MOOC的编程作业把我给打击了一顿，加上TensorFlow 2.0更新后与1.x的差距非常之大，使得我之前一知半解的TensorFlow语法也没啥用了，而刚好TensorFlow 2.0的应用又非常广泛，最最重要的是，我接下来学习的cs231n还是用TensorFlow完成编程作业的，但是我安装的TensorFlow 2.0语法又不兼容课程使用的1.x，所以这使得我势必要学习一下TensorFlow2.0的用法，所以我上了这门系列课程。  

这系列课程共有四门MOOC，我很期待这么大的课程量之后我的水平会到达一个什么程度，希望这可以让我熟练的使用TensorFlow，从而让我可以顺利的学习接下来的pytorch。第一门MOOC的名字叫做Introduction to TensorFlow for Artificial Intelligence, Machine Learning, and Deep Learning，名字实在太长，而且后半部分没啥用，所以我就简称这门MOOC叫做Introduction to Tensorflow好了，以后(包括这篇博客)的名字都用这个来简称。  

那么我们就进入这系列课程中的第一门MOOC的第一章。由于这门MOOC比较新，是今年年初发布的，所以没有对应的中文字幕。虽然可以理解，但是我看着可供选择的南非荷兰语陷入了沉思……为什么南非荷兰语都可以有但就是没有中文呢……  

一开始我就见到了我朝思暮想的Andrew Ng吴恩达大大，特别是我经历了Udacity这门MOOC的简单粗暴而又不知所云的授课后，我对吴恩达大大细致入微的讲课风格极为怀念。不过紧接着Andrew Ng就介绍了另外一位大牛Laurence Moroney，具有丰富的编程经历，是谷歌TensorFlow的开发人员。那么第一个视频就介绍新人物那肯定不是采访，而是这位应该是这门课的老师了。紧接着两位开始了商业互吹模式，一个说另一个写过无数本编程书籍，另一位直接说我是你的粉丝，上过你的课，两个人一唱一和给我听的一愣一愣的。  

在传统的编程任务中，给定数据和编程规则，输出最终的答案，而在机器学习任务中，给定结果和数据，却可以输出编程的规则。在平时的编程任务中，例如进行人物动作识别，如果动作少的话，我们可以用if来实现，但是如果动作多的话，系统就崩了，这时候就需要机器学习出马，让他们学习一种不需要这么复杂的if的范式，从而用这套规则来解决这类问题。  

接下来Laurence给我们演示了一段非常简单的线性回归代码，值得一提的是，在数据很小的时候，最后预测的数值不一定就是最终的正确数值，有可能和数值非常接近但不相等，这一方面是因为训练规模小，另一方面是因为神经网络以概率的形式确定最终结果。  

这门MOOC中，课程用的编程环境是Google Colab，当然文件都是以ipynb的形式存在的，所以完全可以保存到自己的jupyter notebook上跑，课程也提供了官方的ipynb文件，但是第一，免费的GPU不用白不用。第二，多学一个IDE总没坏处，所以在这门课程中，我将使用Google Colab来完成这门MOOC的所有编程作业，而我的所有代码还是和以前一样以ipynb的形式存在我的github上，并在博客上给出链接。  

这里的习题还挺有趣的- - ![1-1](/images/Tensorflow in Specialization/1.png)  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
