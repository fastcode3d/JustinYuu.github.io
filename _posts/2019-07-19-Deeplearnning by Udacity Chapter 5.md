---
layout: post
title: "Deeplearning by Udacity Chapter 5"
description: "Notes"
categories: [Deeplearning-by-Udacity]
tags: [Python]
redirect_from:
  - /2019/07/19/
---

# Deeplearning by Udacity Chapter 5  

这一章是这门课的最后一章，主要介绍RNN。  

对于文字识别领域来说，我们会遇到两大问题：首先，一些很不常见的单词，可能我们平时都没怎么见过，要让机器能够正确识别，有一定的难度；其次，有些近义词或者同义词长得很不一样，这就需要在神经网络中建立某种联系从而解决这个问题。  

这时候我们就要借鉴无监督学习的思想，具体做法是采用“词嵌入”，将不同的词语嵌入到多维的向量空间中，让语义相近的单词靠的尽可能近一点，语义相反的单词远一些。那么词嵌入的模型就是word2vec，那么如果想让三维的向量变成二维的，那么用机器学习中的PCA会丢掉太多的信息，并且效果也不好，所以可以用t-SNE来保持向量的相对距离不变。此外这里还介绍了一个比较有用的方法，叫做sample softmax，与普通的softmax相比，它将结果为0的一部分结果舍去，只采样一部分，并保留结果为1的所有值，从而降低输出向量的规模。  

这里有一个编程练习，练习里给出了Word2vec的skip-gram的实现细节，让自己仿照其写一个CBOW的实现细节，CBOW和skip-gram基本上是反着的，所以基本上不需要什么修改，只需要多写一个函数，把两者反过来就好了。这里是源码[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Deeplearning-Udacity/5_word2vec.ipynb)  

这里的介绍顺序有点不一样，从word2vec介绍到RNN，简要的介绍了一下seq2seq序列，从而能够处理输入长度不同的序列。在RNN中，反向传播是对时间步进行反向传播，当然在不同的层上也要进行反向传播。那么反向传播的过程中会出现梯度消失和梯度爆炸的情况，我们可以采取梯度裁剪来处理梯度爆炸的情况，利用LSTM来解决长距离依赖导致的梯度消失问题。LSTM中通过设定write门，read门和forget门来对每一单元进行输入输出控制，此外，LSTM也需要用正则化，L2正则化和dropout表现都很好，但是要记住dropout不要用在递归连接层，而是用在输入层和输出层上比较好。  

Beam Search可以减少搜索的时间复杂度，通过在每一个时间步只保留超参数B个概率最大的选项，可以让搜索的规模始终保持在B以内。  

接下来讲了一些seq2seq的应用，比如应用在实时翻译和实时字幕上，也可以用在演讲识别中。  

最后一个编程任务是实现LSTM。


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
