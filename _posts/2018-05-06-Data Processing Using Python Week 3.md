---
layout: post
title: "Data Processing Using Python Week 3"
description: "My notes while startiing python"
categories: [Data-Processing-Using-Python]
tags: [Python]
redirect_from:
  - /2018/05/06/
---
# Data Processing Using Python Week 3

### 3.1 强大的数据结构

#### 3.1.1 为什么需要字典

字典是一种映射类型，由键（key），值（value)和key-value对组成。  
创建字典可以直接创建，也可以使用dict函数创建。

使用dict函数时，可用zip函数使两个列表打包成一个元组。

#### 3.1.2 字典的使用

字典的基本操作有插入、删除、判断是否存在等，而dict2=dict1操作是将两个dict关联到同一个字典，字典的地理位置始终是一个。  

也可以通过字典的内建函数，如dict(),len(),hash()（判断是否可哈希）等进行操作  

字典也有很多方法，如.keys(),.values(),.items()等，前面几个方法用作字典的遍历。  
update()方法用作字典的更新。  
get()方法可以实现字典内容的查找。
clear()方法可以实现清空字典内容（包括物理地址上的值） 

字典输出的值为可变长关键字参数，用**来表示。  

字典使用案例：JSON格式和搜索引擎关键词查询等  

#### 3.1.3 集合  

集合是一个无序不重复的元素的组合，分为可变集合(set)和不可变集合(frozenset)  

集合的比较可以直接用Python中的符号in,not in ,==,!=,<,<=,>,>=来判定，其意义分别为：属于、不属于、等于、不等于、子集、真子集、超集、真超集。

集合的关系运算也可以直接用Python符号表示，如&,|,-,^分别表示交集、并集、差集、对称差集。此外，运算符可复合。

集合也存在内建函数，分为两类。第一类面向所有集合，第二类面向可变集合。  
面向所有集合的函数有.issubset(),isuoerset(),union(),copy()等  
面向可变集合的集合有.update(),.add(),.remove(),.pop()(删除函数中的一个元素)。

有一道练习题是区分set.remove()和set.discard()，set.remove(obj)和set.discard(obj)的区别在于，当obj存在于set中时，都将其删除；但当obj不存在于set中时，remove()会报错，discard()不会。

---
本博客采用disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
