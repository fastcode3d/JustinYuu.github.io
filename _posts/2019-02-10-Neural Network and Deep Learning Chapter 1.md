---
layout: post
title: "Neural Network and Deep Learning Chapter 1"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/02/10/
---
# Neural Network and Deep Learning Chapter 1  
第一周是对深度学习的简介。  

## Welcome to the Deep Learning Specialization  
第一个视频当然是介绍deeplearning和AI了，吴大大第一句话就说，AI is the new Electricity.而AI中最受欢迎的部分就是深度学习。这个视频主要介绍了这整个系列课程中所要学到的东西，他讲了一系列专业名词，但是我只看得懂Machine learning这门课中提及到的那部分，剩下的还是要在学习中逐渐掌握。  

## Introduction to Deep Learning  
这一章一共就这一大节，其中又分为多个小节，每个小节我就不逐一写小标题了，都放在这一节里一起记笔记。  

这门课的名称就是neural network，所以首先要对神经网络进行介绍。果然，吴大大又举了房价预测那个栗子，由于在之前已经学过神经网络，所以就简要记录一下，详细的推导和公式在上一门课的官方笔记中都有，这是链接:[Week 4 Lecture Notes](https://www.coursera.org/learn/machine-learning/resources/RmTEz)  
其中吴大大提到了ReLU函数，其中文名称是**线性整流函数**，维基链接在这里[线性整流函数](https://zh.wikipedia.org/wiki/%E7%BA%BF%E6%80%A7%E6%95%B4%E6%B5%81%E5%87%BD%E6%95%B0)，它的作用是代替了之前的sigmoid函数，在上一门课程中神经网络还是用的sigmoid函数，而现在已经被ReLU代替了。sigmoid的主要问题是当梯度几乎为0时，学习速率将会非常慢，这些内容目前只需要了解一下，后面的课程中会再次介绍。  

数据可被划分为结构化数据和非结构化数据，对结构化数据的训练和识别是比较容易的，但是对非结构化数据的训练和识别是比较困难的，而神经网络对于这两种数据都能找到应用点。  
在其他常用的监督学习算法中，当数据到达一定规模后，随着数据的规模变大，算法的性能不会变大。而在神经网络中，如果神经网络本身的规模足够大，那么它所需要的数据规模则更大，如果有更大的数据集，更大的神经网络规模，那么性能将会更好。因此我把它理解为“潜力更大”，或者“上限更高”。  

这样这周的内容就结束了。。这周居然只有三个真正教东西的视频，别说三天，一个小时都不到这周就完成了- -。  

最后有一个选修视频，是Andrew对一位深度学习大牛的采访，有空的话值得一看，即使不学这门课程，链接在这里：[Heroes of Deep Learning](https://www.coursera.org/learn/neural-networks-deep-learning/lecture/dcm5r/geoffrey-hinton-interview)  
我对这个视频印象很深刻，采访的是Geoffrey Hinton，说实话我之前根本不认识他，但是通过这篇采访我才知道他是之前所学的反向传播算法的发明者，也是其余很多著名的算法，如ReLU的发明者，更是被誉为神经网络之父。他在接受采访时的一开始就说他在当时研究神经网络的时候，神经网络被当成“愚蠢的东西”，之后他又继续做了一系列研究，并取得了丰富的研究成果。虽然他在采访中介绍的一些术语我并不能完全听懂，但是我能感受到他在讲述自己发现这些算法过程时的欣喜。在采访的后期他提到了一些他自己的想法，如“胶囊网络”，这些我就更无法理解了，给我的感觉就是：不明觉厉。除此之外，Hinton对无监督学习充满了信心，虽然监督学习目前的效果很好，前景也很广阔，但是他仍然认为无监督学习有着更为广阔的前景和更好的未来。我感觉无监督学习的功能会更强大，但是实现起来会更困难、更复杂，而监督学习由于需要标签和分类，所以应用有限而比较简单。从这种角度来看，无监督学习的确有更为广阔的前景和应用。  
当问到对于深度学习初学者有什么建议时，Hinton说要读文献，但不要读太多，直到产生自己的直觉，即找到他们做的“不对”的地方然后进行研究，然后相信你的直觉。然后吴大大也分享了他的经验，可以在读文献的同时复现论文，我觉得当我有一定基础的时候我可以尝试着这样做。我觉得这些建议还是挺有帮助的，也算是对坚持下这40分钟采访的同学的bonus吧:)   
看完这篇采访后我对Geoffrey Everest Hinton非常感兴趣，有时间我要去看看他的文章，听听他的MOOC，再次感慨一下，有MOOC实在是太好了，可以听到这些大名鼎鼎的大牛的课程。  
去Google了一下胶囊网络，发现这篇论文已经成功发表了，好像还引起了很大的轰动- -，原文链接在此[Dynamic Routing Between Capsules](https://arxiv.org/abs/1710.09829)，一篇知乎回答很详细的介绍了这篇论文[Capsule network--《Dynamic Routing Between Capsules》 - mountain blue的文章 - 知乎](https://zhuanlan.zhihu.com/p/31491520)，还有一篇硕士研究生复现了这篇论文，并给出了自己的解释[如何看待Hinton的论文《Dynamic Routing Between Capsules》？ - 云梦居客的回答 - 知乎](https://www.zhihu.com/question/67287444/answer/251460831)，我觉得讲的都很详细，但是以我的水平只能看懂一部分。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
