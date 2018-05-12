---
layout: post
title: "Data Processing Using Python Week 4"
description: "My notes while startiing python"
categories: [Data-Processing-Using-Python]
tags: [Python]
redirect_from:
  - /2018/05/10/
---
# Data Processing Using Python Week 4

本章讲的相当笼统，可能是由于介绍的函数太多，每个函数在课程中都是一带而过，并没有具体的实例演示和分析，教学效果不是很好。

### 4.1 Python基本数据统计

#### 4.1.1 便捷数据获取
  
从很多网站上可以下载.csv数据文件，.csv文件默认可以用excel默认打开，也可以用pandas下的.read_csv()方法打开  
也可以用Web API获取直接的数据（而不是通过html文件中自己选取）。用requests库下的get方法实现，得到JSON格式的数据  

此外还可以从语料库中获得，如NLTK语料库，方法为nltk.download打开NLTK下载器，选择要下载的语料。

#### 4.2.2 数据准备

用DataFrame可以对原始数据进行一系列的预处理。  

用DataFrame.coloums可以给原始数据添加列名。用DataFrame.index增加行索引名。  

用Dataframe.Fillna方法填充NaN值，用其Method参数指定缺失值的填充方向，如.fillna(method = 'ffill',inplace = True)  
其中ffill表示用后一个数据代替NaN填充，bfill表示用前一个数据代替NaN填充。

用datetime中的date.fromtimestamp()处理timestamp格式的时间，使其变为普通日期形式。用.strftime(x,'%Y-%m-%d')可以使其转换为具体格式。  

用datetime.now()或者datetime.utcnow()来得到当前时间。  

创建时间序列可以用pandas.date_range('20180511',periods=7)创建，然后numpy下的DataFrame创建列表。下面为示例代码  
 	
	{%highlight ruby%}	
	import numpy as np
	import pandas as pd
	date = pd.date_range('20171001',periods=10)
	listA=['value']
	result = pd.DataFrame(np.arange(1,11),index = date,columns = listA)
	print(result)
	{%endhighlight%}
	
#### 4.2.3 数据显示

数据显示方式有很多，如显示行和显示列，可以通过切片和专用方式。  

行显示的切片方法为list[:5]或者list[-5:]，专用方式为.head(5)或者.tail(5)

#### 4.2.4 数据选择

DataFrame中的数据选择相对来讲非常自由，可以选择行、选择列、选择区域、条件选择。

具体的选择方式如下

选择列/行可以直接输入列/行名，如DataFrame.列名或者DataFrame['列名']。  

选择行、列可以使用标签label(loc)，如DataFrame.loc[1:5,],DataFrame.loc[:['列名','列名']]，选择一个值时，可以用at。

选择行、列和区域可以用iloc，取某个值可以用iat，loc和iloc的区别在于loc中的1:5指的是第一行到第五行，iloc中的1:5指的是第一行到第四行，行同理。  
因为iloc实质上是用索引来表示，loc实质上使用名称来表示，我理解中这也是为什么要多出一个i(index)的原因  

此外pandas中还有一种数据选择方式ix，是loc和iloc的混合，既可以用索引，也可以用名称来表示。

DataFrame中的条件选择也非常方便，可以用条件表达式来进行。

#### 4.2.5 简单统计与处理

DataFrame中有很多数据处理函数，比如DataFrame.describe()可以获得数据的个数、均值、标准差。DataFrame.corr()默认使用Pearson相关系数进行线性相关分析。

DataFrame中可以使用sort函数进行排序，如sort_index可以按行索引排序。  

DataFrame.len()可以实现计数统计功能

#### 4.2.6 Grouping

DataFrame.groupby()可以按行、列分组。也可以插入求和等函数，如df.groupby('month').volume.sum()。  

#### 4.2.7 Merge

Python中的的merge是一种很常用的连接方式，它有三种形式，append追加，concat连接，join连接。

append追加的用法为p.append(q)（将p和q连接）  
concat连接的方法为pd.concat(pieces)。concat可以连接两个不同逻辑结构的对象，也可以用pd.concat([df1,df2])。  
join可以将有共同字段的两张表合并

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
