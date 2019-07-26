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

lesson 2延续了上周课程中的讽刺检测，上周仅仅对其进行了预处理，这里进行接下来的进一步操作。这里和以前略有不同的是将Tokenizer里面所用到的所有的参数值都用变量代替，而不是直接上数值(hard code)，这样在调参的时候就会方便许多，直接在固定的位置调整即可。这里Laurence演示了几张调整不同参数后的loss和acc图像，向我们展示了不同的参数值带来的不同影响。  

## lesson 3  

lesson 3继续讨论IMDB数据集我们之前导入IMDB的数据集的时候，是将原数据集导入后再进行标注分类的，但是有很多情况下导入的原数据集已经被预处理了，我们只需导入进来即可使用。这里提一下，我们使用TensorFlow2.0版本，从而避免了1.x版本中那些繁琐的固定流程。我们导入了一个预先训练好的sub_word tokenizer，名字叫做subword8k，这里的内容都是已经编码好的数字而不是原有的字符，我们可以用decode命令来查看这些编码的原貌，也就是对应的单词。这里我们将GlobalAveragePooling1D放在Embedding层后面来池化，其他的和之前的代码基本相同。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
