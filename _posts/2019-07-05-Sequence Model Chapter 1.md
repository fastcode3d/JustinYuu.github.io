---
layout: post
title: "Sequence Model Chapter 1"
description: "Notes"
categories: [Sequence-Model]
tags: [Python]
redirect_from:
  - /2019/07/05/
---

# Sequence Model Chapter 1  

Sequence Model这门课程是整个deeplearning.ai系列课程的最后一门，主要介绍循环神经网络(RNN)和自然语言处理(nlp)领域的相关知识。复旦的NLP非常的强，但是很遗憾读研的时候方向是cv。虽然cv也不错，并且以后应该和nlp也没什么联系了，但是简单接触一下nlp和rnn也是有好处的。   
本次MOOC的内容看起来还是很多的，特别是编程作业，第一周就有三个作业，所以一天一章感觉还是不太现实，争取两天一章吧。  

## Recurrrent Neural Network  

课程直接进入正题，介绍循环神经网络RNN，本门课程居然没有中文字幕，只能借此机会练练听力了。所谓Sequence Model，即序列模型，指的是处理以序列形式呈现的数据集，比如演讲识别、音乐生成、DNA序列分析，感知分类，运动识别等等，通过监督学习进行训练。这些例子中有的X是序列数据，有的Y是序列数据，有的XY都是序列数据，应用的形式还是挺多样的。  

首先和其他神经网络一样，先介绍notation，也就是命名方法。这里我必须进行举例： x: Harry Potter and Hermione Granger invented a new spell，这是哈利波特小说中的一句话，即哈利波特和赫敏格兰杰发明了一个新咒语。这个时候，输出的数据就被拆分成了9个序列元素（1个单词视为一个序列元素），用x<sup><1></sup>表示第一个元素，以此类推，用x<sup><t></sup>表示第t个元素，用y<sup><t></sup>表示第y个输出。  

我们会发现，一个输入数据，即一个序列模型会有很多序列元素，那么每次输入可能会有很多个输入数据，也就是多个序列模型。为了更明确的表示第i个输入数据的第t个序列元素，我们用x<sup>(i)<t></sup>来表示。此外，我们用T<sub>x</sub>和T<sub>y</sub>来表示x和y的序列长度，T<sub>x</sub><sup>(i)</sup>表示第i个输入数据的序列长度。  

NLP中将所有的单词建立了一个词汇表，称为Vocabulary，不同的词汇表大小也不同，那么任何词汇都以One-hot向量的形式存在，其大小与词汇表相同，记词汇表中出现该词汇的位置为x，那么在One-hot向量中的x位置将值置为1，其他位置都为0，类似于一个mask。如果词语不存在词汇表中，就用一个自己定义的代表未知单词的符号代替，比如<UNK>。  




---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
