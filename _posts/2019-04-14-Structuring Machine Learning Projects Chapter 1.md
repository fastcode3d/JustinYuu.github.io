---
layout: post
title: "Structuring Machine Learning Projects Chapter 1"
description: "Notes"
categories: [Structuring Machine Learning Projects]
tags: [Python]
redirect_from:
  - /2019/04/14/
---

# Structuring Machine Learning Projects Chapter 1    

第三门课程的名字叫做Structuring Machine Learning Projects，这门课的目的是为了给深度学习的学习者做自己的项目时可能会遇到的问题提供一些解决方法，以及整体的一些策略。整门课程的内容并不多，我个人感觉学习之后可以开展自己简单的深度学习项目了。  
第一周并没有编程练习，因此将会学的快一点，争取一天搞定。  

## Introduction to ML Strategy  

第一章是导论，主要介绍这门课的意义和内容。正如吴恩达所说，正确的机器学习策略可以使工作事倍功半，而错误的机器学习策略只会使工作变得漫长而又复杂，效果还不好。正交化指的是调整合适的参数从而使效果更为合理的方法。那么正交化，也就是调参的目标就是在测试集->开发集（交叉验证集）->测试集->实际应用中都有很好的表现，那么正如箭头的顺序所致，目标的难度和重要性都是依次增加的。  

## Setting up your goal  

这一节首先介绍了一些量化的方式，正如之前讲过的一样，用查准率、召回率和F1指数来评判性能的好坏。

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
