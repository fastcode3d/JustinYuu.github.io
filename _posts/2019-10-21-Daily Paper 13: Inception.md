---
layout: post
title: "Daily Paper 13: Inception"
description: "Notes"
categories: [CV-classic]
tags: [Paper]
redirect_from:
  - /2019/10/21/
---

# Daily Paper 13 - Going Deeper with Convolutions  

## Introduction  

CV方向的paper一共还有五篇，这周还有六天，所以昨天周日放个假，出去玩了一天嘻嘻。  

这一篇是谷歌提出的Inception网络，还是非常经典的，和上一篇VGG网络分别获得了ILSVRC-2014前两名，而且GoogLeNet获得了分类和检测的双第一。这是通过一种巧妙的设计，从而使得在增加深度的时候能够保持计算开支平衡来实现的。为了提升质量，该架构是基于Hebbian定理和多尺度处理规则设计，其送往ILSVRC14的作品GoogLeNet是一个22层的深层网络，在分类和检测中表现良好。  

inception这个单词来自盗梦空间这部电影，其中有一句经典的台词“We need to go deeper”，作者用inception来代表更深的神经网络。在作者看来，“深”有两层含义，第一层是作者介绍了一种新型的高水平组织方式来构建inception模块；而第二层含义代表较为直接的增加深度。  

相关的研究有很多，但是作者列举的几个基本上在之前都已经看到过了，比如LeNet,NIN,R-CNN等。具体来讲，作者借鉴了Serre等人的思想，创建了类似的inception模块；借鉴了NIN的1×1卷积的思想，将其应用到了inception模块中；使用和R-CNN进行目标检测的pipeline，在对其进行改进的基础上进行目标检测。  

最直接提高深度神经网络性能的方法是增加其规模，包括通过增加层数以增大深度，通过增加每一层的节点数以增加宽度。这是训练高质量模型最简单安全的方法，特别是对于给定的大规模标签数据集。然而这种简单的解决方法有两大缺陷。更大的网络规模往往意味着更多的参数，这使得扩大后的网络更易过拟合，特别是当训练集中的标签样例有限的时候。这能够变成一个主要的瓶颈，因为制作高质量的训练集是要技巧的，也是很昂贵的。另一个统一增加网络大小的缺陷是计算资源需求的暴增。例如，在一个深度视觉网络，如果两个卷积层相连，任何增加过滤器数量的改动都会导致增加二次方倍数的计算量。如果增加的计算力没有被有效使用（比如大部分的权值趋于0），那么大量的计算会被浪费。实际应用中可用的计算力是有限的，即使是以提高模型质量为主要目标，高效分布计算资源，其实也比盲目增加网络体积更加有效。  

解决这两个问题的基本方法最终一般是把全连接改成稀疏连接的结构，甚至包括在卷积中也这么做。这是借鉴了Arora等人的研究结果得出的，他们调查的结果显示如果数据集的概率分布是一个十分稀疏的大型神经网络所能表达的，那么最合适的网络拓扑结构可以通过分析每一步的最后一层激活函数的统计关联性，并将具有高相关性输出的神经元进行聚类，而将网络一层一层地搭建起来。这种情况符合著名的赫布原则——神经元如果激活条件相同，它们会彼此互联。  

另一方面，当涉及到大量的非统一的稀疏数据结构的计算时，当今的计算设施是很低效的，计算需求和计算资源的鸿沟甚至可能被进一步放大。目前大部分面向机器学习的系统都利用卷积的优势在空间域中使用稀疏性。然而，卷积是通过一系列与前层区块的密集连接来实现的。所以作者在想，是不是存在一个中间步骤，如同理论上所显示的，能够让整个结构即使在过滤器层面上都能使用额外的稀疏性，但依旧是利用现有硬件进行密集矩阵计算。Inception的体系结构始于第一作者研究的一个例子——评估复杂拓扑结构的网络算法的假设输出，尝试近似地用一个密集的可获得的组件表示一个视觉网络的稀疏结构的假设输出。最终作者成功地建立了Inception的体系结构，使之能够在局部化和物体检测的上下文环境中非常好用。  

## System  

Inception的体系结构的主要设计思路是要在一个卷积视觉网络中寻找一个局部最优的稀疏结构，这个结构需要能够被可获得的密集组件覆盖和近似表达。假定转义的不变性意味着作者想要建立的网络将利用卷积块建立。我们所需要做的只是寻找局部最优化结构并在空间上对其进行重复。  

Arora等人在文献中提出，一个逐层搭建的结构，需要分析其每一步的最后一层的统计关联性，并将高度相关的神经单元聚类为簇。这些簇组成了下一层的单元并与前一层的各个单元相连。作者假设前面一层的每个单元都对应输入图像的某些区域，而这些单元被分组分配给过滤器。在较低的层次（更靠近输入端），相关的单元聚焦于局部区域。这意味着我们能够得到大量聚焦于同一区域的簇，它们会被下一层的1×1卷积覆盖。  

作者更想要做到的是在更少的在空间上传播更多的簇（这些簇会被区块更大的卷积所覆盖），这样的话，覆盖大型区域的区块数量就会减少。为了避免区块对齐问题，现有的Inception结构将过滤器大小限制为1×1，3×3 和 5×5，然而这种设定更多是为了方便而不是必要的。这也意味着合理的网络结构应该是将层次的输出过滤器结合起来，并将其合并为单一向量作为输出以及下一层的输入。  

另外，因为池化操作对于现有水平的卷积网络是很重要的，建议最好在每一步增加一条并行池化通路，这样应该也会有一些额外的好处。不过Inception模块是一层一层往上栈式堆叠的，所以它们输出的关联性统计会产生变化：更高层抽象的特征会由更高层次所捕获，而它们的空间聚集度会随之降低，因为随着层次的升高，3×3和5×5的卷积的比例也会随之升高。一个大问题是，上述模型，至少是朴素形式（naive form）的模型，即使只有很有限个数的5×5卷积，其最上层卷积层的巨量过滤器的开支都会让人望而却步。一旦把池化层加进来，这个问题会变得更加严重：它们的输出过滤器个数与前面过程的过滤器个数相等。池化层输出与卷积层输出的合并会导致无法避免的每步输出暴增。即使是当这种结构覆盖了最优的稀疏结构，它可能依然还是很低效，从而导致少数几步的计算量就会爆炸式增长。  

这种情况导致作者提出了第二种设想：审慎地把降维和投影使用到所有计算量可能急剧增加的地方。这是基于嵌入的成功来设计的：相对于一个大型的图像区块，即使是低维的嵌入也可能包含大量的信息。然而，嵌入会把信息以一种致密的，压缩的方式展现出来，而压缩信息是很难被建模的。作者还是想在大部分位置保持稀疏性，而只在信号需要被聚合的时候压缩它们。也就是说，1×1卷积被用于在昂贵的3×3和5×5卷积之前降维。除了用于降维，它们也被用于数据线性修正激活，这使之具有双重使命。  

一般而言，一个Inception网络是由一系列上述结构栈式堆叠而成，有时候步长为2的最大池化层会把网络一分为二。出于技术原因（更高效的训练），只在高层使用Inception结构而把低层保留为传统的卷积模式似乎是有利的。这并不一定是必要的，只是反映了有些基础设施对于我们的设计而言很低效。这一结构一个有利的方面是它允许每一步的神经元大量增加，而不会导致计算复杂度的暴增。 降维的普遍存在能够阻挡大量来自上一层的数据涌入下一层的过滤器，在大区块上对其进行卷积之前就对其进行降维。该设计另一个在实践中很有用的方面是，它与"视觉信息应该被多层次处理，然后被汇集到下面层次汇总，同时抽取多尺度特征"的特性相一致。计算资源的优化利用允许我们增加每层网络的宽度以及层数，而无需面对增加的计算困难。  

另一种使用Inception架构的方法是开发一种质量稍差，但计算起来更便宜的版本。作者已经发现，用于平衡计算资源的控制因素 可以使得我们的网络比表现相同而不使用Inception结构的网络快2~3倍，只是这需要极为精细的人工调整。  

这里就引出了GoogLeNet,作者参加ILSVRC14比赛所用的网络，这个名字很明显为了致敬LeNet，在该网络中，所有的非线性函数都是ReLU，有参数的权重层共有22层，加上池化层共有27层，独立的网络块有接近100个。此外，作者采用了一个附加网络，在训练过程中其偏差会被乘以0.3加到总偏差中，预测过程中不适用。附加网络的结构，包括附加分类器的结构如下：一个平均池化层，过滤器为5×5，步长为3；一个1x1卷积，有128个过滤器，用于降维和规范化线性激活；一个拥有1024个单元和规范化线性激活的全连接层；一个0.7输出的DROPOUT层；一个softmax分类器。  

模型的训练使用动量（momentum）为0.9的异步随机梯度下降，并将学习速率固定为每八次迭代减少0.04。使用Polyak均值建立在推理过程中使用的最终模型。  

## Experiment  

ILSVRC14分类挑战一共有120万张图片用于训练，5万张图片用于验证，10万张图片用于测试，采用top-1和top-5误差作为评价指标，作者独立训练了七个版本的相同的GoogLeNet模型，然后进行联合预测，不同的模型采取相同的参数初始化和学习策略，只不过是采样方法和图片的输入顺序不同。作者将图片重设为四种不同的尺度（高和宽），分别是256，288，320和352，包括左中右三块，对于每一块，我们取其四角和中心，裁切出5个224x224的区块，同时取其镜像。结果每张图就得到了4×3×6×2 = 144个区块。  

结果显示，最后提交的挑战赛作品将TOP-5错误在验证集和测试集上都降到了6.67%，在参赛者中排名第一。与2012年的SuperVision方法相比，降低了56.5%，与去年获得第一的Clarifai方法相比降低了40%，而且这些方法都使用了外部数据来训练分类器。  

ILSVRC14识别挑战采用mAP作为评价指标，将多边界预测和选择性搜索相结合，改进了区域提取的步骤，并将超像素的大小扩大了两倍以减少假证错误率。结果显示mAP为43.9%，排名第一，且比前一年的第一名准确率增加了一倍，还是很不错的。  


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
