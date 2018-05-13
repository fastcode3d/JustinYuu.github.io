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

#### 4.1.2 数据准备

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
	
#### 4.1.3 数据显示

数据显示方式有很多，如显示行和显示列，可以通过切片和专用方式。  

行显示的切片方法为list[:5]或者list[-5:]，专用方式为.head(5)或者.tail(5)

#### 4.1.4 数据选择

DataFrame中的数据选择相对来讲非常自由，可以选择行、选择列、选择区域、条件选择。

具体的选择方式如下

选择列/行可以直接输入列/行名，如DataFrame.列名或者DataFrame['列名']。  

选择行、列可以使用标签label(loc)，如DataFrame.loc[1:5,],DataFrame.loc[:['列名','列名']]，选择一个值时，可以用at。

选择行、列和区域可以用iloc，取某个值可以用iat，loc和iloc的区别在于loc中的1:5指的是第一行到第五行，iloc中的1:5指的是第一行到第四行，行同理。  
因为iloc实质上是用索引来表示，loc实质上使用名称来表示，我理解中这也是为什么要多出一个i(index)的原因  

此外pandas中还有一种数据选择方式ix，是loc和iloc的混合，既可以用索引，也可以用名称来表示。

DataFrame中的条件选择也非常方便，可以用条件表达式来进行。

#### 4.1.5 简单统计与处理

DataFrame中有很多数据处理函数，比如DataFrame.describe()可以获得数据的个数、均值、标准差。DataFrame.corr()默认使用Pearson相关系数进行线性相关分析。

DataFrame中可以使用sort函数进行排序，如sort_index可以按行索引排序。  

DataFrame.len()可以实现计数统计功能

#### 4.1.6 Grouping

DataFrame.groupby()可以按行、列分组。也可以插入求和等函数，如df.groupby('month').volume.sum()。  

#### 4.1.7 Merge

Python中的的merge是一种很常用的连接方式，它有三种形式，append追加，concat连接，join连接。

append追加的用法为p.append(q)（将p和q连接）  
concat连接的方法为pd.concat(pieces)。concat可以连接两个不同逻辑结构的对象，也可以用pd.concat([df1,df2])。  
join可以将有共同字段的两张表合并

### 4.2 Python高级数据处理与可视化

#### 4.2.1 聚类分析

参考代码

	{highlight ruby%}
	kmeansStu1.py
	import numpy as np
	from scipy.cluster.vq import vq,kmeans,whiten
	list1 = [88.0,74.0,96.0,85.0]
	list2 = [92.0,99.0,95.0,94.0]
	list3 = [91.0,87.0,99.0,95.0]
	list4 = [78.0,99.0,97.0,81.0]
	list5 = [88.0,78.0,98.0,84.0]
	list6 = [100.0,95.0,100.0,92.0]
	data = np.array([list1,list2,list3,list4,list5,list6])
	whiten = whiten(data)
	centroids,_ = kmeans(whiten,2)
	result,_=vq(whiten,centroids)
	print(result)
	{%endhighlight%}
	
用k-means算法获得局部最优解，得到同学中的学霸名单。  

k-means算法可以用于机器学习的聚类功能。

用专业工具scikit learn也可以解决聚类功能 代码为  
	
	{%highlight ruby%}
	kmeansStu2.py
	import numpy as np
	from sklearn.cluster import KMeans
	list1 = [88.0,74.0,96.0,85.0]
	list2 = [92.0,99.0,95.0,94.0]
	list3 = [91.0,87.0,99.0,95.0]
	list4 = [78.0,99.0,97.0,81.0]
	list5 = [88.0,78.0,98.0,84.0]
	list6 = [100.0,95.0,100.0,92.0]	
	X = np.array([list1,list2,list3,list4,list5,list6])
	kmeans = KMeans(n_clusters = 2).fit(X)
	pred = kmeans.predict(X)
	print(pred)
	{%endhighlight%}

KMeans.predict()可以根据得到的类进行预测。

#### 4.2.2 Matplotlib绘图基础

Matplotlib是最著名的Python绘图库，主要用于二位绘图。其包含方便快捷的绘图模块：绘图API--pyplot模块和集成库--pylab模块（包含Numpy和pyplot中的常用函数）。

##### pyplot绘图  

作图命令如下：  
折线图：plt.plot(x,y)（x,y也可以为numpy数组）。  
散点图：plt.plot(x,y,'o')。
柱状图：plt.bar(x,y)

作图保存命令：plt.savefig('PATH')。

作图示例如下：  
	
	{%highlight ruby%}
	import numpy as np
	import matplotlib.pyplot as plt
	x = np.linspace(0,1)
	y = np.sin(4 * np.pi * x) * np.exp(-5 * x)
	plt.plot(x,y)
	{%endhighlight%}

##### pylab绘图

作图示例如下

	{%highlight ruby%}
	import numpy as np
	import pylab as pl
	t=np.arange(0.,4.,0.1)
	pl.plot(t,t,t,t+2,t,t**2)
	{%endhighlight%}

此外NumPy数组也可以作为Matplotlib的参数  

#### 4.2.3 Matplotlib图像属性控制

Matplotlib可以改变图线的色彩和样式。  
例如 plt.plot(x,y,'g--'):用绿色的短横线  
具体的命令可以通过matplotlib官网查询或者通过help(plt.plot)函数得到。

Matplotlib可以加标题：图、横轴和纵轴:plt.title(),plt.xlabel(),plt.ylabel()  

此外Matplotlib还有figsize,color,linestyle,marker,label,legend（图例）等参数

Matplotlib可以用subplot(a,b,c)参数来进行多子图绘图。a代表行数，b代表列数

axes([left,bottom,width,height])函数也可以进行子图绘制，其参数范围为(0,1)

#### 4.2.4 pandas作图

pandas作图可以和plot作图结合使用，通过创建DataFrame对象来进行作图。

此外用kind参数可以生成不同的图形，autopct参数用来设置图像内数字的格式，subplots参数用来控制子图。

boxplot()方法可以绘制一种特殊的图形：箱型图。箱型图由五条线组成，第一条线表示最大值，第二条线表示25%处的位置，第三条线表示中位数，第四条线表示75%处的位置，而最后一条线表示最小值。箱型图越长，表示数据离散程度越大。

#### 4.2.5 数据存取

txt格式的数据存取相对简单，使用文件的写入方法即可。  

csv格式的数据存取也很简单，由to_csv函数即可实现，实例如下：

	{%highlight ruby%}
	to_csv.py
	import pandas as pd
	...
	quotes = retrieve_quotes_historical('AXP')
	df = pd.DataFrame(quotes)
	df.to_csv('stockAXP.csv')
	{%endhighlight%}

csv格式文件的默认打开方式为excel，也可以用记事本打开，以纯文本格式存储，数据之间由','隔开。csv文件之所以称为csv，也是由于','的英文缩写为csv。

csv格式的阅读函数为.read_csv('PATH')

此外python也支持excel的读取和写入，函数名为.read_excel('PATH')和.to_excel('PATH')

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
