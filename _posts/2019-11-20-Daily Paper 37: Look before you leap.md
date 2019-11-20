---
layout: post
title: "Daily Paper 37: Look before you leap"
description: "Notes"
categories: [MMML-VLN]
tags: [Paper]
redirect_from:
  - /2019/11/20/
---

# Daily Paper 37 - Look before you leap: bridging model-free and model-based reinforcement learning for planned-ahead vision-and-language navigation  

## Introduction  

今天的paper是VLN领域的一篇baseline文献，作者是UCSB王威廉组的Xin,Wang。该paper的结果被广泛的用作VLN领域的baseline，发表在ECCV2018上。  

在强化学习领域，model-free和model-based是两大基础方法，VLN问题用强化学习方法解决的话，一般都是用actor-critic或者policy gradient这种model-free方法学习到的。这里作者将两者结合起来，创新性的提出了一个hybrid模型。作者在引言中的介绍说到他们将一个look-ahead policy模型和一个环境模型合在一起预测下一个状态和奖励，我其实很好奇这为什么不叫model-based模型而非得叫混合模型。  

作者考虑使用model-based这一方法，主要是因为他考虑到人类在进行自然语言导航的时候，所考虑的并不只是当前看到的，还会考虑到后续如果做出某种动作时带来的后果，而作者又转头一想，要是让机器也学会这种方法的话，那应该能够效果更好一些，而这种方式正是典型的model-based对环境建模的方法。  

VLN的介绍和related works略过，直接进入system。  

## System  

作者给他的宝贝模型起名为Reinforced Planning Ahead(RPA)模型。对环境进行建模一直是一个不太容易的问题，在棋盘类游戏中千变万化的方式都很难建模，在真实世界里我个人是想不通如何对环境建模，更何况在一个完全未知的环境中，走完这一步能看到什么压根就不知道，这根本就没有进一步建模推理的空间，就算强行进行建模，所建立的模型和真实世界的模型也很难完全匹配，因为机器完全是通过自己的想象来进行建模的，这是一个复杂度奇高但是效果又不好的想法。作者在related work中稍微提了一句，他们的model-based指的是在进行动作中考虑到了未来的prediction，接下来看看具体怎么弄的。  

看不了了，因为我要回家了，昨天的还没看完，今天的也没看完，PPT做的时间太长了，明天要补三个坑，我可太难了。


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
