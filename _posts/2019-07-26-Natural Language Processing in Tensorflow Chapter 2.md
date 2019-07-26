---
layout: post
title: "Natural Language Processing in TensorFlow Chapter 2"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/26/
---

# Natural Language Processing in TensorFlow Chapter 2  

这周的学习任务是词嵌入，将所有单词都嵌入到一个n维空间向量中，并将语义相近的单词嵌入的位置尽可能的相近。  

## lesson 1

lesson 1采用的数据集是IMDB的评分数据，将大规模的电影评分分为积极和消极两类。具体的做法是用tf.datasets导入IMDB数据集，然后导入tensor中用tensor表示。之后再用上周学过的Tokenizer来预处理并padding，最后用keras.layers添加构造我们的神经网络层，其中包括这周的重点层Embedding层。最后经过训练得到最后的结果，并将向量结果写入一个新tsv文件中，并将元文件写到另一个tsv文件中，用这两个文件，我们可以用Emebedding Projector将其可视化。这里是这个练习的ipynb[代码](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Natural%20Language%20Processing%20in%20Tensorflow/Course_3_Week_2_Lesson_1.ipynb)  

## lesson 2



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
