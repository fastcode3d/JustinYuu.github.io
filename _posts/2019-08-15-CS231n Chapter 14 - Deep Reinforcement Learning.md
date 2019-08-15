---
layout: post
title: "CS231n Chapter 14 - Deep Reinforcement Learning"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/08/15/
---

# CS231n Chapter 14 - Deep Reinforcement Learning    

## Introduction  

这周主要介绍强化学习。至此为止我们主要学习的是监督学习，给定特定的标签x和y，对模型进行训练，此外在上节课我们还学习了非监督学习，通过多种方法可以生成新的模型。那么这里我们要学习叫做强化学习，用于描述和解决智能体（agent）在与环境的交互过程中通过学习策略以达成回报最大化或实现特定目标的问题。  

那么今天主要有四个部分，首先介绍什么是强化学习，其次介绍马尔科夫决策过程，再接下来介绍两个算法，Q-Learning和Policy Gradients。  

## What is Reinforcement Learning?  

强化学习有很多典型的例子，比如车竿问题，如何在一辆运动的车上平衡一个杆子，那么角度、角速度、位置、纵向的速度都是要考虑的状态。另外一种经典的RL例子叫做robot locomotion机器人运动，其目的就是让机器人向前走，还有一个Atari game的游戏例子，通过强化学习来赢得该游戏的最高分。最著名的强化学习的例子就是alphago了，在2016年alphago战胜了李世石，这是强化学习的一个非常成功的应用。  

## Markov Decision Process  

接下来进入数学领域的知识：马尔科夫决策过程。所谓的马尔科夫属性，就是当前的状态完全表征了当前的世界，那么这个属性由(S,A,R,P,γ)五个参数定义，S代表可能的状态集，A代表可能的操作集，R代表奖励给定对(state,pair)的分布，P代表过渡概率，即在下一个状态给定对上的分布，γ是一个参数，代表对奖励的重视系数。MDP是一个比较复杂的概念，这里是维基百科[链接](https://en.wikipedia.org/wiki/Markov_decision_process)，可以详细的看一下。  

这里介绍一个简单的MDP任务：Grid World，在一个网格中，根据我们的状态，决定下一步是向哪个方向走，直到走到我们提前设定的终点。那么我们可以对每一个过渡设定一个负奖励，我们可以在每一个状态下采取行动，即向四个方向之一随机走一步。我们可以用随机方法和我们的优化政策作对比，我们的action数量明显的要小于随机方法。  

那么我们要做的就是最大化reward的总和，这种政策就是我们的优化政策π<sup>*</sup>，那么我们如何处理初始状态和转移概率等随机性呢？我们的方案就是使用数学期望来平均这些随机性，我们可以定义一个价值函数，用来代表特定状态的好坏，并同时定义一个Q-value函数来表示状态-动作对的好坏，我们将MDP的五个参数按照样本轨迹/路径进行初始化。  

我们可以尝试用Bellman equation来定义并求解Q-value函数，Q<sup>*</sup>是给定的状态-动作能实现的最大期望累计奖励，Q<sup>*</sup>(s,a) = max E\[sigma γ<sup>t</sup>r<sub>t</sub>\|s<sub>0</sub> = s,a<sub>0</sub>=a,π]，同时Q<sup>*</sup>满足Bellman equation。我们将使用Bellman方程作为迭代更新，第i次更新都会求得一个新的Qi值，然后当i趋向于无穷大时Qi将会收敛到Q<sup>*</sup>，但是这会有一个问题，我们要计算每一个状态-行动对的Q(s,a)，计算量在某些情况下将会非常大，大到我们无法遍历整个状态空间来求最大值，所以这个方案实质上不可行。那么我们的想法就是和之前的VAE一样对Q进行估计，这里我们使用的是神经网络。  

## Q-learning  

Q-learning就是用于解决优化政策的神经网络及其对应算法的总称。Q-learning简单来讲，就是使用了一个函数逼近器来估计动作值函数Q-value function，我们可以记为Q(s,a;θ)≈Q<sup>*</sup>(s,a)，θ就是使用的神经网络的权重，如果函数逼近器是一个深度神经网络，那么我们称这个算法为deep q-learning。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
