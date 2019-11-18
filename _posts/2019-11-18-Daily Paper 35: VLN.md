---
layout: post
title: "Daily Paper 35: VLN"
description: "Notes"
categories: [MMML-VLN]
tags: [Paper]
redirect_from:
  - /2019/11/18/
---

# Daily Paper 35 - Vision-and-Language Navigation: Interpreting visually-grounded navigation instructions in real environments  

## Introduction  

这篇paper是VLN的开山之作，看这篇paper主要是想看一下VLN的基准baseline方法以及数据集的形式。这篇paper应该和另一篇提出Matterport3D Simulator的文章一并阅读，因为Matterport3D Simulator是作者实现VLN任务的工具，今天先看这篇。  

作者使用Matterport 3D Simulator——一个基于真实图像的大规模强化学习环境来完成了对真实场景的模拟，提出了视频-语言导航任务并提供了第一个现实场景下的VLN数据集——the Room-to-Room(R2R)dataset。  

VLN问题就不过多赘述了，简单来讲就是给定一串自然语言指令和一个未曾见过的环境，agent将会尝试着根据给定的自然语言指令进行导航，直至最终的目标位置。那么很显然，这个任务和机器人有着千丝万缕的联系，不过让机器人在真实环境下进行操作和导航成本实在是太大了，所以作者就想了一种模拟的替代方法来进行实验和训练。具体来讲，就是使用Matterport3D Simulator进行模拟化，该模拟器是一个大规模的可交互强化学习环境，从Matterport 3D数据集中建立。该数据集是一个含有10800个密集采样的全景RGB-D图像，包含了90个真实世界中的建筑规模的室内环境。和人工合成的RL环境相比，真实世界图像的使用保存了视觉和语言的丰富性，最大化了训练的agent转移到真实世界应用的潜能（增强可移植性）。基于Matterport3D环境，作者收集了21567个平均长度为29词的导航指令，组成了一个Room-to-Room数据集，每一个指令都描述了一个穿越多个房间的轨迹。  

总体来说作者的贡献有3点：提供了Matterport3D Simulator，提供了Room-to-Room dataset，以及应用一个seq2seq模型来建立了一些baseline。  

## Related Work  

一般来说提出一个新任务的Related Work还是比较重要的，因为你提出一个新任务一定要有新的理由。例如这里的语音-视觉导航，和普通的机器人导航问题有什么区别呢？这里作者给出了解释：传统的机器人导航任务中，视频的语义没有那么丰富，一般是将所有可能遇到的导航参照物全部列出来进行标注，或者干脆在一个视觉限制的环境下进行训练和使用，这只需要有限的感知即可做到，那么这种导航的问题在于无法适应复杂多变的真实场景。VLN任务的优势在于通过加入对视觉的语义分析，使得agent可以有效的识别未接触的场景和物体，这更符合在真实场景下的应用。  

此外作者还阐述了VLN和VQA的异同，VLN和VQA都是visually grounded seq2seq transcoding问题，但是VQA并不会使摄像机的视角和位置移动，相较起来也序列也更短。  

## Matterport3D Simulator  

首先介绍Matterport3D Simulator，之前说过该模拟器基于Matterport3D数据集，那么首先介绍一下这个数据集。Matterport3D数据集是一个包含全景视角的当前最大可用的RGB-D研究数据集，含有从90个建筑物级的场景的194400个RGB-D图像中建立的10800个全景视角。


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
