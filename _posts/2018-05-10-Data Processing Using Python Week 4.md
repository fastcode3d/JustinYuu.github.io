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

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
