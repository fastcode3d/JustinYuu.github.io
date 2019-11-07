---
layout: post
title: "Daily Paper 29: SoundNet"
description: "Notes"
categories: [MMML-Self_Supervised]
tags: [Paper]
redirect_from:
  - /2019/11/07/
---

# Daily Paper 29 - SoundNet: Learning Sound Representations from Unlabeled Video  

## Introduction  

这篇paper是nips2016上的，主要通过利用野外收集的大量未标记声音数据来学习丰富的自然声音表示。利用视觉和声音之间的自然同步来学习使用200万个未标记视频的声学表示。未标记的视频具有以下优点：它可以在大规模上经济地获取，但包含关于自然声音的有用信号。作者提出了一种学生-教师培训程序，它使用未标记的视频作为桥梁，将辨别的视觉知识从完善的视觉识别模型转换为声音模态。与声学场景/对象分类的标准基准测试相比，我们的声音表现相较于最先进的结果具有显着的性能改进。可视化表明声音网络中会自动出现一些高级语义，即使它是在没有标注的情况下进行训练的。  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
