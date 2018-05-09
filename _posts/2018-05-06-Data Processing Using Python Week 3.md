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

### 3.2 Python扩展库

#### 3.2.1 扩展库SciPy

SciPy有六大库，分别为NumPy,SciPy Library,Matplotlib,IPython,Sympy,pandas,每一个库都是赫赫有名的扩展库

#### 3.2.2 ndarray

ndarray，即n维数组，是Numpy中最基本的数据结构，别名为array，有丰富的函数，利于节省内存和提高CPU计算时间  
其维度称为轴，轴的个数称为秩。  
ndarray通过一系列函数来创建数组，最常见的函数时.array。此外还有.linspace,.ones,.fromfunction等  
nd.add(a,b)是将a,b两个numpy数组的相同位置的值相加  
ndarray的切片规则为nd.("行","列")  
nd.array(a,b)将array变成a行b列的数组（创建新数组）  
nd.resize(a,b)将array变成a行b列的数组（改变原数组）  
Numpy中含有广播机制，两个数组进行运算时，较小的数组会广播到较大的数组的大小  
ndarray的运算也由函数完成，.sum(axis=x)（按X维度求和），.min（求最小值），.argmin（求最小值的索引），.mean(求平均值),.var(求方差),.std(求标准差)等等  

ndarray在线性代数中有专门的应用，有一系列函数，如.dot(),.linalg.det(),.linalg.inv(),.linalg.solve(),.linalg.eig()等  

ndarray中有很多函数可以对数组的每个元素进行操作，如add,all等，称为ufunc函数。这些函数在C语言级别进行实现，计算速度非常快。  

#### 3.2.3 变长字典Series

Series是类似一位数组的对象，由数据和索引组成，索引会自动创建，也可以自己指定  

Series中有数据对齐功能，可以将索引和数据相对应。  

Series中也有相应的函数来实现一些功能。

#### 3.2.4 DataFrame

DataFrame可以看做共享同一个index的series的集合，根本上是一个表格型的数据结构。  
DataFrame的创建用.DataFrame()创建（注意函数的大写字母）。  

可以通过.index,.columes,.values可以查看其行索引、列索引、值。  
也可以通过.iloc[a,b]来切片。
DataFrame中也含有统计功能。

#### 利用字典进行词频统计

于一个已分词的中文句子：

"我 是 一个 测试 句子，大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧 ， 家 赶快 来 统计 我 吧 ， 重要 事情 说 三遍 ！"

可以用collections模块中的Counter()函数方便地统计词频，例如可用如下代码：

	{%highlight ruby%}		
	import collections
	import copy
	s = "我 是 一个 测试 句子 ， 大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧，大家 赶快 来 统计 我 吧 ， 重要 事情 说 三遍 ！"
	s_list = s.split()
	# 产生一份深拷贝避免remove()方法影响迭代
	s_list_backup = copy.deepcopy(s_list)    
	[s_list.remove(item) for item in s_list_backup if item in '，。！”“']
	print(collections.Counter(s_list))
	{%endhighlight%}
	
这个问题也可以通过字典来解决

	{%highlight ruby%}
	s_dict = {}
	s = "我 是 一个 测试 句子 ， 大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧，重要 事情 说 三遍！"
	s_list=s.split()
	for item in s_list:
		if item.strip() not in "，。！“”":
			if item not in s_dict:
				s_dict[item] = 1
			else:
				s_dict[item] += 1
	print(s_dict)
	{%endhighlight%}

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
