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

## Method  

作者给他的宝贝模型起名为Reinforced Planning Ahead(RPA)模型。对环境进行建模一直是一个不太容易的问题，在棋盘类游戏中千变万化的方式都很难建模，在真实世界里我个人是想不通如何对环境建模，更何况在一个完全未知的环境中，走完这一步能看到什么压根就不知道，这根本就没有进一步建模推理的空间，就算强行进行建模，所建立的模型和真实世界的模型也很难完全匹配，因为机器完全是通过自己的想象来进行建模的，这是一个复杂度奇高但是效果又不好的想法。作者在related work中稍微提了一句，他们的model-based指的是在进行动作中考虑到了未来的prediction，接下来看看具体怎么弄的。  

作者把这个问题看成了一个强化学习问题，使用语言编码器和图像编码器来进行编码，用一个recurrent policy network来解码动作并更新状态，之后作者还添加了一个model-based的功能，给agent装备一个look-ahead模块，对环境建模，将未来的预测结果考虑在内。look-ahead模块和recurrent policy network并行，组成了作者所谓的hybrid模型。这个模型还是很好理解的，在每一个时间步t，RPA架构的model-free模块接受到语言编码器的输出和当前的状态s，然后经过处理生成它对最终的预测结果产生的分析信息。而与此同时，model-based模块内部有多个look-ahead模型，共同作用得到未来可能存在的轨迹，那么多个模型的信息整合起来就得到了model-based模块产生的最终信息，两者结合起来就可以得到输入到最终的动作预测器中得到最终的结果。  

在这个模型中，model-based模块是重中之重，这个模块对环境建模，内部隐含着环境模型。Look-ahead module的内部其实很有意思，一个model-based path里面有多个这种模块，而一个模块里面又有多个层，初始的状态s和语言指令{w}输入进去以后，首先导入的是第一层，顺序依次是Look-Ahead Policy,Env Model, Encoder，其中状态同时输入到Policy和Env Model里面，就类似一个残差，那么这个时候Env Model就可以通过Policy产出的想象动作a<sub>t</sub>'和输入的状态s<sub>t</sub>，得到一个对应的reward r<sub>t</sub>'和下一个时间步的状态s<sub>t+1</sub>'。那么这个时候这一层的任务已经完毕了，将最终的结果导入最后的Encoder即可，同时s<sub>t+1</sub>'也被传到下一层的Look-Ahead Policy中进行预测，得出t+1时间步的动作和奖励，以及进而得到t+2时间步的状态。这样一直持续下去，一共走m层，m是预设轨迹的长度，作者使用LSTM来实现Encoder，将预测的reward和最终的轨迹都进行编码，输出一个最终的预测表示。我们之前提到过，一个model-based path里面有多个module，我们把数量记为J，那么最终我们获得J个轨迹的表示，然后通过concatenation将他们整合到一起，得到该模型的最终结果。  

## Model  

接下来看比较头疼的数学问题。首先来看环境模型，环境模型特指look-ahead模块中每层的第二部分Env Model，其任务是根据Look-Ahead policy产出的想象动作和输入的状态s<sub>t</sub>得到reward和下一个时间步的状态s<sub>t+1</sub>。实现方式是通过一个投影函数f<sub>proj</sub>联合s<sub>t</sub>和a<sub>t</sub>（先concat，再投影到同一个特征空间中），然后将其feed到一个过渡函数f<sub>transition</sub>和一个奖励函数f<sub>reward</sub>中，得到状态和奖励。这三个f全部都是可学习的神经网络，f<sub>proj</sub>是一个线性投影层，f<sub>transition</sub>是一个sigmoid输出的多层感知机MLP，f<sub>reward</sub>是一个直接输出标量reward的MLP。  

之后再来看model-free的部分，这一部分的名字叫做recurrent policy model，它是一个基于注意力的LSTM解码网络。这个LSTM中规中矩，基本上和baseline差不多，也是用了注意力机制来处理输入的instruction。最后两者结合的action predictor就是一个多层感知机MLP，最后一层是Softmax，它接受两个模型的输入，输出一个在特征空间A上的概率分布。

## Learning  

整个系统的训练分为两步，先学习环境模型，再学习加强的策略模型，两者采用不同的语言encoder，独立的进行训练。我很好奇这种训练方式的模型泛化性能如何，在我个人看来先熟悉环境再进行训练简直等同于作弊。  

在预训练环境模型的时候，作者首先使用随机教师策略来预训练agent，在该策略下，agent将会决定是采取人类要求的动作还是在伯努利元策略上随机选一个。由于随着训练的不断进行，agent的策略会不断的朝着人类要求的最优策略靠拢，因此通过demonstration策略训练的环境模型将会在后续应用中更好的预测更类似最优的策略。此外，在强化学习方法中，agent的策略在训练过程中一般是随机的，那么定义一个伯努利元策略概率p<sub>human</sub>=0.95就能够模拟这一随机的训练过程。作者在环境模型中同时定义两个损失函数l<sub>transition</sub>和l<sub>reward</sub>，用一套参数来最小化这两个损失。  

在后续的模型训练中，作者提出了两种方法，一个是用监督学习的方法来尽量让模型按照人类标注的方式走，这种方法训练效果很好，但是由于完全是监督学习，因此在新环境的泛化性能很差。所以作者提出了第二种方法，即学习奖励函数，根据每一个时间步的状态和目标点之间的距离来设置新的奖励函数，并将之前时间步的结果累积考虑在内，这其实就是和前几天该作者Best Paper的那篇文章一模一样的方法，就不赘述了，可以看[这篇博客](http://justin-yu.me/blog/2019/11/11/Daily-Paper-33-RCM+SIL-for-VLN/)。这里有两种方法，一种是先用SL来warmup，另一种是两者共同训练，这里作者用到是共同训练，因为收敛的比较快，但是作者之后的那篇文章用的是先用SL warmup，那个方法的表现比较好。这里为了联合训练policy model和look-ahead model，在训练的时候freeze了预训练的环境模型，之后在每一个时间步，都使用环境模型进行了模拟的深度限制的roll-outs。这里我感觉作者说的不太清楚，看起来有点糊涂，感觉还是用了预训练的环境模型来进行roll-outs，看起来还是像是作弊了。  

## Experiment  

细节就不赘述了，都是一样的，直接看结果，作者的RPA模型刷了unseen val和test的NE、SR和OSR，不过unseen的性能不出所料的差，SR只有25%。好玩的是作者的Total Length都比较短，明显的小于10m，作者并未作出说明。作者还进行了一系列的隔离实验，就不多赘述了。  

## Conclusion  

总结一下，作者搞了一个含有model-based的hybrid模型，得到了比较好的效果，我是真的特别想复现一下，看看他这个泛化性能刚好比STOA高2%是不是巧合，因为我看完了他整体的研究思路后仍然觉得他这个方式应用在seen val上比较好，进入一个新环境中怎么学习环境模型呢？  
 
---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
