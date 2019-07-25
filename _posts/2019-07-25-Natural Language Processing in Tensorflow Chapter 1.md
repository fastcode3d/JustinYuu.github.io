---
layout: post
title: "Natural Language Processing in TensorFlow Chapter 1"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/25/
---

# Natural Language Processing in TensorFlow Chapter 1  

## Introduction  

这一门课程主要学习Tensorflow在NLP领域的应用，虽然暂时和我的领域没啥关系，但是谁也说不准以后会不会用到。第一周的主要学习内容是加载文本和预处理数据，虽然看起来是微不足道的工作，但是其实还是挺耗费时间的，特别是预处理的时候会用到很多python语句，很有必要学习一下。  

## Sentiment in text  

对于单词的编码，问题在于如何用一个独一无二的编码来表示输入的句子。如果用ASCII码，将每个字母用ASCII码表示，那么相同字母组成的不同含义的单词，比如SILENCE和LISTEN，就会使我们的神经网络很难区分；如果用一个独特的编码来表示一个单词呢？这看起来可行。  

那么具体的表示方式是什么呢？在这里Laurence用了keras.prepocessing.text的Tokenizer模块来实现。这里具体的用法是首先将其实例化并用num_words参数指定容器大小，然后利用fit_on_texts方法来将我们的文本导入进去，最后用word_index方法获取单词的index。这个模块的好处之一在于他可以自动识别大小写、空格、标点符号等一系列迷惑性的符号，从而让相同单词的不同形式都归为一类里面。  

接下来介绍一些常用的API，首先使用tokenizers.texts_to_sequences()方法可以将一个句子变成一个编码序列。这里还提到了一个OOV(Out of Vocalbulary)问题，这里在Tokenizer实例化的语句里加一个oov_token="<OOV>"参数，从而将所有没有存在于词汇表里的词语全部替换成OOV这个词，这里类似吴恩达课程里的<UNK>。  

接下来是padding，CV中需要padding，NLP中也需要，这里采取import preprocessing.sequence中的pad_sequences，并将pad_sequences(sequences,maxlen=10)赋值为padded，从而让所有的编码长度等于最大值10。  

接下来进入一个实例，讽刺检测。这里仍然是用了kaggle中的一个数据集，主要从twitter中收集数据。这里将数据以json的格式导入到python中，具体的代码和之前介绍的基本相同，就不再赘述了。  

## Weekly Exercise  




---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
