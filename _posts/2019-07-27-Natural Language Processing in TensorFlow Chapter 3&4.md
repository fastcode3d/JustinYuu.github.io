---
layout: post
title: "Natural Language Processing in TensorFlow Chapter 3&4"
description: "Notes"
categories: [Tensorflow-Specialization]
tags: [Python]
redirect_from:
  - /2019/07/27/
---

# Natural Language Processing in TensorFlow Chapter 3&4  

## Chapter 3  

第三周介绍序列模型和一个RNN模型LSTM，RNN的原理并没有介绍太多，而是直接放了吴恩达Sequence Model这一门课程的链接，而我的博客中也有对应的笔记，可以直接查阅。  

这里要实现的RNN网络是LSTM，简单来讲，LSTM通过三个门来对输入和输出进行控制。这里是LSTM那一节的[笔记](http://justin-yu.me/blog/2019/07/05/Sequence-Model-Chapter-1/)。那么在代码的实现过程中，只需在Embedding后面加n层LSTM层就可以，这里应用了双向RNN，所以代码是`tf.keras.layers.Bidirectional(tf.keras.layers.LSTM(64,return_sequence = True))`，在这里如果下一层还是RNN层的话，要把return_sequence参数设为true。    

值得注意的是，Laurence用图像指出，有LSTM的网络更容易过拟合，虽然在训练集表现非常好，但是在验证集的表现并不稳定。这里其实也可以用1维卷积+池化层来代替LSTM，最后的效果也不错。  

这周的编程作业利用了kaggle里面的数据集进行迁移学习，研究不同的层，不同的参数对过拟合的影响，这里是我的编程[代码](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Natural%20Language%20Processing%20in%20Tensorflow/NLP_Course_Week_3_Exercise_Question.ipynb)  

## Chapter 4  

这一周的任务是用序列模型来生成文学作品。这里把句子编码后作为输入，而将one-hot向量作为输出。这里我们使用了Embedding层和LSTM层作为隐藏层，之后又将LSTM层改成了双向LSTM层，结果显示双向LSTM层的收敛速度更快。这里由于我们需要不断生成新词汇，所以我们要将生成的token实时转变为输入的sequence，所以我们需要写一个for-loop来将除最后一个以外的生成值全部转变为sequence。由于这个非常重要，所以我把完整代码摘抄在这里：  

    for _ in range(next_words):
      token_list = tokenizer.texts_to_sequences([seed_text])[0]  
      token_list = pad_sequence([token_list], maxlen = max_sequence_len - 1, padding = 'pre')
      predicted = model.predict_classes(token_list, verbose=0)
      output_word = ""
      for word,index in tokenizer.word_index.items():
        if index == predicted:
          output_word = word
          Break
      seed_text += " " + output_word  
    print(seed_text)

这里Laurence拿着他训练的模型做了一下测试，将星球大战著名的名言help me obi-wan kenobi输入进去，结果得到了一堆看起来花里花哨但又不知所云的诗……  

最后的编程作业出奇的简单，这是我意想不到的，我以为会把所学的所有内容混合起来，结果最后只是填了个sequence和compile方法，这里是我的代码[链接](https://github.com/JustinYuu/Deeplearning-study/blob/master/Tensorflow%20in%20Practice/Natural%20Language%20Processing%20in%20Tensorflow/NLP_Week4_Exercise_Shakespeare_Question.ipynb)。这样这门课就全部结束了，明天开始第四门课程，也是这个系列的最后一门课程。    

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
