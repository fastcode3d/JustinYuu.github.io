---
layout: post
title: "Structuring Machine Learning Projects Chapter 2"
description: "Notes"
categories: [Structuring Machine Learning Projects]
tags: [Python]
redirect_from:
  - /2019/04/17/
---

# Structuring Machine Learning Projects Chapter 2    

这门简短的课程只有2章，这是第二章，也就是最后一章。虽然内容比较少，但是每一章内的内容饱和度还是有的。  

## Error Analysis  
本章的第一节学习的是误差分析。误差分析是项目过程中很重要的一步，那么显然第一步是找出误差存在的原因。这里Andrew给的建议是通过列表将错误的数据分类，然后得到每个错误类型在所有的错误例子中所占有的比例，进而进行校正误差。  
发现误差之后要进行校正，值得注意的是，深度学习对于随机误差来说是robust的，但是对系统误差不是。因此我们主要的目的就是尽可能降低系统误差。这个时候要进行一个二次分类，将误差中的由于数据标签标注错误而导致的误差挑选出来。这一部分是系统误差中很重要的一种，因此我们要花时间通过重新分组标注来解决掉这部分误差。  

## Mismatched training and dev/test set  


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
