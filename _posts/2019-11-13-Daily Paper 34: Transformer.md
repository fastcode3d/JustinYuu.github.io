---
layout: post
title: "Daily Paper 34: Transformer"
description: "Notes"
categories: [NLP]
tags: [Paper]
redirect_from:
  - /2019/11/13/
---

# Daily Paper 34 - Attention is all you need  

## Introduction  

由于这几天在看一些自注意力机制在跨模态领域的应用，有很多方法是将经典的NLP模型搬到了CV领域进行图像或者视频的识别，那么为了理解它们所用的模型，我就势必需要去了解一些NLP领域中比较著名的模型，以及一些注意力机制的paper。  

今天看的这篇paper是Transformer，看之前把李宏毅讲Transformer的视频看了一遍，感觉讲的很清楚，所以更想要看一下原来的文献长啥样了，所以就简单的看一下。Transformer的应用大多还是在经典的NLP问题中，所以我把这篇paper分类到了NLP的领域。  

这篇paper是Google发表在NIPS2017上的，属于比较老的文献了。在这篇paper发表之前，主流的序列模型都是基于RNN或者CNN网络的encoder-decoder模型，此外注意力机制也被应用在了基于上述网络的模型中从而得到了更好的表现，但是这篇paper的厉害之处在于他们摒弃了大家都使用的基准CNN和RNN网络，而是完全使用注意力机制模块组成的新网络架构。作者的实验表明这一模型的质量更高，网络架构更加平行化适合并行处理，训练的时间更少。作者的模型在2014的WMT英德翻译中取得了28.4的BLEU，提高了现有的最好表现，在WMT2014的英法翻译中取得了SOTA的BLEU分数，此外，作者还证明了Transformer有良好的泛化性能。  

## System  

这篇文章出奇的废话少，和其他paper不同，introduction非常简短，只有几段，这和其他paper惯用的把文章梗概复述一遍的套路截然相反，所以直接进入正文。  

### Architectures  

整个网络架构采用模块堆叠的方式，基础的模块是自注意力机制和逐点相乘的全连接层。该架构仍然使用了encoder-decoder模型，下面分别介绍。  

Encoder模型使用的是6层堆叠，每一个层有两个子层，第一个是多头自注意力机制(multi-head self-attention)，另一个是简单的前向全连接层。在每层内，也就是两个子层中间使用残差链接，后缀层归一层(Layer Normalization),这可以记作LayerNorm(x+Sublayer(x))。所有层的输出维度都是512。  

Decoder使用的也是6层的堆叠层，但是每一个层有三个子层，除了Encoder的两个之外，还有一个称为Masked Multi-Head Attention的第三子层，其主要目的是在encoder的输出上方进行multi-head attention,用来帮助解码器关注输入句子的相关部分。此外，在encoder和decoder的输入时，input embedding和output embedding都要经过一个positional encoding添加位置信息。  

### Attention  

接下来看attention。我们都知道一个attention可以被看做是一个query和一系列的key-value对与一个输出的对应关系，这里大家都是向量的形式。输出是value的加权和，而权重由query和value对应的key计算产生。作者将其特殊的注意力模块称作“Scaled Dot-Product Attention”，输入是由d<sub>k</sub>维的queries，keys和d<sub>v</sub>维的values组成。作者将query和所有的keys点乘，然后scaled，就是除以d<sub>k</sub>的平方根，然后对其softmax，给每一个value带个帽子作为权重值。  

在实际运算中为了进一步的向量化，将所有的query一起计算，打包成一个矩阵Q，把keys和values也打包成矩阵K和V，那么向量的运算就升维成为了矩阵的运算，公式如下：Attention(Q,K,V) = softmax(QK<sup>T</sup>/√d<sub>k</sub>)V.这种打包成矩阵进行运算的点乘注意力相对于传统的加性注意力模型而言，虽然复杂度一样，但是由于向量化更高，使得效率更高，空间复杂度也更少。这里是注意力机制的一篇[博客](https://blog.csdn.net/mpk_no1/article/details/72862348)，里面讲的比较清楚，但是要注意他对注意力机制的分类其实看成演化过程更好一点，并不是严格的并列关系。  

以上是一个Key-value点乘注意力模型的架构，但是如果需要d<sub>model</sub>次这种操作，除了容易想到的一个attention做d<sub>model</sub>此for循环，我们其实还可以用多个注意力模型组合起来进行并行矩阵运算。假设一共有h个注意力模型，那么之前的矩阵QKV也分别有h个，处理之后得到了h个注意力模型的output，再将其concat起来，额外经过一次Linear全连接层的处理，得到最终的结果，这样的实现就更为快捷和方便，因为QKV本身自身内部的维度得到了下降，具体的下降值是从d<sub>model</sub>个下降成了d<sub>model</sub>/h个，并且模块的向量化程度更高。具体的公式如下：
MultiHead(Q,K,V) = Concat(head1,...,headn)W<sup>O</sup>  
  where head<sub>i</sub> = Attention(QW<sub>i</sub><sup>Q</sup>,KW<sub>i</sub><sup>K</sup>,VW<sub>i</sub><sup>V</sup>)  

这里总结一下维度，W<sub>i</sub><sup>Q</sup>矩阵的维度是d<sub>model</sub>乘d<sub>k</sub>，W<sub>i</sub><sup>K</sup>矩阵的维度是d<sub>model</sub>乘d<sub>k</sub>，W<sub>i</sub><sup>V</sup>矩阵的维度是d<sub>model</sub>乘d<sub>v</sub>。至此，单头key-value点乘自注意力模型就转变成为了多头的自注意力模型。  

多头注意力在Transformer中有三大应用。第一是应用在了encoder-decoder注意力层中，queries来自前一个decoder层，keys和values来自encoder层的输出，这种设置可以使得decoder的每一个位置都可以在输入序列中的所有位置中发挥作用。第二是应用在了encoder内部的自注意力层，在自注意力层中所有的key、value、query都来自encoder的前一层的输出，那么encoder中的任意位置都可以参加到该位置的前一个encoder层中的所有位置。第三是应用在了decoder内部的自注意力层，它使得decoder中的每个位置都可以参加到包括该位置的所以之前的decoder中的位置。在decoder中，需要防止向左流动信息，以保留自动回归的属性，所以作者通过屏蔽（设置为-∞）softmax输入中与非法连接相对应的所有值来实现。  

### Others  

剩下的并在一起说了。首先是前向传播的Position-wise实现，encoder-decoder中的每一层都有一个前向全连接层网络，在每一个position独立和相同的运行，主要通过两个线性变换和一个ReLU完成的，公式太简单就不写了。这里虽然不同的position中的线性变换都是相同的，但是层间的参数完全不同，并不共享。FFN的输入和输出是512维，中间层2048维。  

此外之前提到过会在embedding后面添加一个Positional Encoding，这使得模型可以考虑到序列的位置信息，主要的做法是采用相同尺寸的embedding然后将两者加在一起，这里使用的方法是PE<sub>(pos,2i)</sub> = sin(pos/10000<sup>2i/d<sub>model</sub></sup>)，i代表维度。  

## Why Self-Attention  

这里作者没有急着说训练和实验的事情，而是先分析了一下为什么使用自注意力机制。作者主要将多种自注意力层和RNN和CNN层进行了比较，比较的方式是将一个可变长度的符号表示序列映射到另一个等长的序列中。作者主要使用自注意力机制模型有三点考虑，第一是每一层的整体计算复杂度，第二点是并行处理减少的计算量，这也是需要进行的序列操作的最小数量。最后是网络long-range依赖性的路径长度，这也是很多序列transduction任务的关键问题。  

作者分析了一下，一个自注意力层只需要恒等数量的序列操作来将所有的位置连接在一起，而RNN需要O(n)个序列操作。自注意力层的计算复杂度为O(n²·d)，RNN是O(n·d²)，所以当序列长度n比表示的维度d更小的时候复杂度更小，事实上n一般都小于d，因为表示都越来越复杂了。不过自注意力机制还可以进一步优化，给出一个距离r，限制自注意力机制只能在输出位置视角下的中心位置r范围内操作，忽略更远的信息（影响非常小），可以将复杂度降到O(r·n·d)，不过这会将最大距离长度从O(1)提升到O(n/r)，虽然这仍然小于RNN的O(n)。  

接下来和CNN进行对比，记CNN的卷积核宽度为k，k一般比n小，那么一个军机和肯定无法连接所有的输入和输出，所以需要O(n/k)个卷积层堆叠，或者需要O(log<sub>k</sub>(n))个空间卷积，这就增加了最长路径的长度。CNN的代价一般来讲比RNN更大，虽然分离卷积相当程度上减少了复杂度到O(k·n·d+n·d²)，但是就算在k=n的情况下还是只和作者的模型相等。  

## Experiment  

接下来看一下训练和结果。作者在WMT 2014英德翻译和英法翻译数据集中进行了训练，采用Adam进行优化，使用0.1的label smoothing以提高准确率和BLEU值。作者训练了一个基准的Transformer和一个大的Transformer进行测试。结果显示作者在英德和英法翻译两个任务上都取得了STOA的效果，并显著的降低了FLOPS数。  

作者还测试了一下不同参数带来的影响，这里不做介绍。最后作者测试了Transformer的泛化性能，在English constituency parsing任务上进行了测试，这个任务RNN已经取得了不错的效果，但是在小样本学习上仍然无法取得STOA表现，结果显示在小样本训练下取得了接近STOA的成果，在半监督学习下效果超越了所有baseline。  

## Conclusion  

总结一下，作者第一个提出了完全由自监督注意力机制组成的神经网络架构，并在机器翻译领域取得了STOA的表现。此外，作者还分析了该架构的时间和空间复杂度，通过比较证明了其高效性。最后，作者还证明了该模型良好的泛化性能，作者也期待能将该模型应用到更多任务中。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
