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

选择行、列可以使用标签label(loc)，如DataFrame.loc[1:5,],DataFrame.loc[:,['列名','列名']]，选择一个值时，可以用at。

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

	{%highlight ruby%}
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

具体应用（课后小练习）代码如下
	
	{%highlight ruby%}
	sum_score.py
	import pandas as pd
	data = pd.DataFrame(pd.read_excel('data1.xlsx'))
	a = data.loc[0,['Python','Math']].sum()
	b = data.loc[1,['Python','Math']].sum()
	c = data.loc[2,['Python','Math']].sum()
	listA = [a,b,c]
	data['sum']=listA
	data.to_excel('data1.xlsx',sheet_name='Sum_score')
	{%endhighlight%}

#### 4.2.6 Python的理工类应用

Python可以进行一系列数学处理，如scipy.fft()函数可以用于快速傅里叶变换。

Python还有很强大的图像处理库，常用的Python图像处理库有Pillow(PIL),OpenCV,Skimage。

基本图像处理库的代码示例：

	{%highlight ruby%}
	#Filename:pasteimg.py
	from PIL import Image
	im1 = Image.open('1.jpg')
	print(im1.size,im1.format,im1.mode)
	Image.open('1.jpg').save('2.png')
	Im2 = Image.open('2.png')
	size = (288,180)
	im2.thumbnail(size)
	out = im2.rotate(45)
	im1.paste(out,(50,50))
	{%endhighlight%}

_Biopython_ 是一个用于开发计算分子生物学的工具，可以用于制作序列、字母表和染色体图    

	from Bio.Seq import Seq
	my_seq = Seq("AGTACACTGGT")
	my_seq.alphabet
	print(my_seq)

#### 4.2.7 Python的人文社科类应用

古腾堡项目（Gutenberg）由志愿者参与，致力于文本著作的电子化、归档以及发布。该工程肇始于1971年，是最早的数字图书馆。其中的大部分书籍都是公有领域书籍的原本，古腾堡工程确保这些原本自由流通、格式开放，有利于长期保存，并可在各种计算机上阅读。  

Python中可以通过NLTK库引入古腾堡语料库，并进行一些简单的计算。

	{%highlight ruby%}
	freqG20.py
	from nltk.corpus import gutenberg
	from nltk.probability import*
	fd2 = FreqDist([sx.lower() for sx in allwords if sx.isalpha()])
	print(fd2.B())
	print(fd2.N())
	fd2.tabulate(20)
	fd2.plot(20)
	fd2.plot(20,cumulative = True)
	{%endhighlight%}

此外还有就职演说语料库等语料库可以用来统计。

### 扩展知识

在教学网页的架构中，此内容位于4.2节视频后，但由于其内容综合了第四节两小节的知识，故将其摘出单独成为一节。这一节的主要内容为一些扩展库的用法和一些编程示例及源代码

#### 1 股票数据对比分析编程

	{%highlight ruby%}
	import requests
	import re
	import json
	import pandas as pd
	import matplotlib.pyplot as plt
	from datetime import date
	import time

	def retrieve_quotes_historical(stock_code):
		quotes = []
		url = 'http://finace.yahoo.com/quotes/%s/history?p=%s' % (stock_code,stock_code)
		r = requests.get(url)
		m = re.findall('"HistoricalPriceStore":{"prices":(.*?),"isPending"',r.text)
		if m:
			quotes = json.loads(m[0])
			quotes = quotes[::-1]
		return [item for item in quotes if not 'type' in item]

	def create_aveg_open(stock_code):
		quotes = retrieve_quotes_historical(stock_code)
		list1 = []
		for i in range(len(quotes)):
			x = date.fromtimestamp(quotes[i]['date'])
			y = date.strftime(x,'%Y-%m-%d')
			list1.append(y)
		quotesdf_ori = pd.DataFrame(quotes,index = list1)
		listtemp = []
		for i in range(len(quotesdf_ori)):
			temp = time.strptime(quotesdf_ori.index[i],'%Y-%m-%d')
			listtemp.append(temp.tm_mon)
		tempdf = quotesdf_ori.copy()
		tempdf['month'] = listtemp
		meanopen = tempdf.groupby('month').open.mean()
		return meanopen

	open1 = create_aveg_open('INTC')
	open2 = create_aveg_open('IBM')
	plt.subplot(211)
	plt.plot(open1.index,open1.values,color='r',marker='o')
	plt.subplot(212)
	plt.plot(open2.index,open2.values,color='green',marker='o')
	{%endhighlight%}
	
#### 2 代码分析

	{%highlight ruby%}
	kmeansDJI.py
    import requests
    import re
    import json
    import pandas as pd
    from sklearn.cluster import KMeans 
    import numpy as np
    
    def retrieve_quotes_historical(stock_code):
    quotes = []
    url = 'https://finance.yahoo.com/quote/%s/history?p=%s' % (stock_code, stock_code)
    r = requests.get(url)
    m = re.findall('"HistoricalPriceStore":{"prices":(.*?),"isPending"', r.text)
    if m:
        quotes = json.loads(m[0])
        quotes = quotes[::-1]
    return  [item for item in quotes if not 'type' in item]
    
    def create_df(stock_code):
    quotes = retrieve_quotes_historical(stock_code)
    list1 = ['close','date','high','low','open','volume']
    df_totalvolume = pd.DataFrame(quotes,columns=list1)
    df_totalvolume = df_totalvolume.fillna(df_totalvolume.mean())
    return df_totalvolume
    
    listDji = ['MMM','AXP','AAPL','BA','CAT','CVX','CSCO','KO','DIS','DD']
    listTemp = [0] * len(listDji)
    for i in range(len(listTemp)):
    listTemp[i] = create_df(listDji[i]).close
    status = [0] * len(listDji)
    for i in range(len(status)):
    status[i] = np.sign(np.diff(listTemp[i]))
    for i in range(len(status)):
    if len(status[i]) == 0:
    		     status.pop(i)
    		     break
    kmeans = KMeans(n_clusters = 3).fit(status)
    pred=kmeans.predict(status)
    print(pred)
	{%endhighlight%}
	
---

	{%highlight ruby%}
	plotKO.py
    import requests
    import re
    import json
    import pandas as pd
    from datetime import date
    import time
    import matplotlib.pyplot as plt
    
    def retrieve_quotes_historical(stock_code):
        quotes = []
        url = 'https://finance.yahoo.com/quote/%s/history?p=%s' % (stock_code, stock_code)
        r = requests.get(url)
        m = re.findall('"HistoricalPriceStore":{"prices":(.*?),"isPending"', r.text)
        if m:
            quotes = json.loads(m[0])
            quotes = quotes[::-1]
        return  [item for item in quotes if not 'type' in item]
    
    quotes = retrieve_quotes_historical('KO')
    list1 = []
    for i in range(len(quotes)):
        x = date.fromtimestamp(quotes[i]['date'])
        y = date.strftime(x,'%Y-%m-%d')
        list1.append(y)
    quotesdf_ori = pd.DataFrame(quotes, index = list1)
    quotesdf = quotesdf_ori.drop(['date'], axis = 1)
    listtemp = []
    for i in range(len(quotesdf)):
        temp = time.strptime(quotesdf.index[i],"%Y-%m-%d")
        listtemp.append(temp.tm_mon)
    tempdf = quotesdf.copy()
    tempdf['month'] = listtemp
    closeMeansKO = tempdf.groupby('month').close.mean()
    x = closeMeansKO.index
    y = closeMeansKO.values
    plt.plot(x, y)
    plt.savefig('1.jpg')
	{%endhighlight%}
	
---

	{%highlight ruby%}
	plot_volumes.py
    import requests
    import re
    import json
    import pandas as pd
    from datetime import date
    import time
    from pylab import * 
    
    
    def retrieve_quotes_historical(stock_code):
        quotes = []
        url = 'https://finance.yahoo.com/quote/%s/history?p=%s' % (stock_code, stock_code)
        r = requests.get(url)
        m = re.findall('"HistoricalPriceStore":{"prices":(.*?),"isPending"', r.text)
        if m:
            quotes = json.loads(m[0])
            quotes = quotes[::-1]
        return  [item for item in quotes if not 'type' in item]
    
    def create_volumes(stock_code):
        quotes = retrieve_quotes_historical(stock_code)
        list1 = []
        for i in range(len(quotes)):
            x = date.fromtimestamp(quotes[i]['date'])
            y = date.strftime(x,'%Y-%m-%d')   
            list1.append(y)
        quotesdf_ori = pd.DataFrame(quotes, index = list1)
        listtemp = []
        for i in range(len(quotesdf_ori)):
            temp = time.strptime(quotesdf_ori.index[i],"%Y-%m-%d")
            listtemp.append(temp.tm_mon)
        tempdf = quotesdf_ori.copy()
        tempdf['month'] = listtemp
        totalvolume = tempdf.groupby('month').volume.sum()
        return totalvolume
                      
    INTC_volumes = create_volumes('INTC')
    IBM_volumes = create_volumes('IBM')
    quotesIIdf = pd.DataFrame()
    quotesIIdf['INTC'] = INTC_volumes
    quotesIIdf['IBM'] = IBM_volumes
    quotesIIdf.plot(kind = 'bar')
	{%endhighlight%}
	
#### 3.Scikit-learn 经典机器学习入门项目开发

scikit-learn是基于NumPy、SciPy和Matplotlib的著名的Python机器学习包，里面包含了大量经典机器学习的数据集和算法实现，请基于经典的鸢尾花数据集iris实现简单的分类和聚类功能。

	{%highlight ruby%}
	iris.py
	from sklearn import datasets
	iris = datasets.load_iris()
	print(iris.data)
	print(iris.data.shape)
	print(iris.target)
	{%endhighlight%}
	
---

	{%highlight ruby%}
	iris_KMeans.py
	from sklearn import cluster,datasets
	iris = datasets.load_iris()
	kmeans = cluster.KMeans(n_clusters = 3).fit(iris.data)
	pred = kmeans.predict(iris.data)
	for label in pred:
		print(label,end = ' ')
	print('\n')
	for label in iris.target:
		print(label, end = ' ')
	{%endhighlight%}
	
---

	{%highlight ruby%}
	iris_KNN.py
    from sklearn import datasets,neighbors
    iris = datasets.load_iris()
    knn = neighbors.KNeighborsClassifier()
    knn.fit(iris.data,iris.target)
    print(knn.predict([[5.0,3.0,5.0,2.0]]))
	{%endhighlight%}
	
---

	{%highlight ruby%}
	iris_SVM.py
    from sklearn import svm,datasets    
    iris = datasets.load_iris()
    svc = svm.LinearSVC()
    svc.fit(iris.data,iris.target)
    print(svc.predict([[5.0,3.0,5.0,2.0]]))
	{%endhighlight%}

#### 4 用箱型图分析数据

	{%highlight ruby%}
	boxplot.py
    import pandas as pd
    scores = pd.read_excel('score.xlsx')
    scores.boxplot()
	{%endhighlight%}

scores.xlsx:
Maths	English	Python	Music	Physics	Chemistry	PE
Wang	88	64	96	85	90	81	95
Ma	92	99	95	94	92	94	90
Liu	91	87	99	95	95	92	70
Qian	78	99	75	81	83	88	92
Meng	88	78	98	84	70	95	98
Song	100	95	100	92	98	95	65

分析结果：
（1）Maths、Python和Chemistry分布比较集中，而English和PE的分布则比较分散，从箱子的长度可以获得这些信息；

（2）在7门课程中，Python的成绩分布最为均匀，PE的成绩分布最不均匀，从中位数到上四分位和下四分位的距离比较可以获得这些信息；

（3）Python的总体情况最好，Maths、English和Music的总体情况不太理想，从中位数的位置可以获得这些信息，分析数据可以发现这3门课程中各有3个同学没有达到90分，PE虽然从图中看平均值应该不高，但其总体情况较好，分析数据可以发现有2个同学考了低分但90以上的有4个同学；

（4）Maths、Python和Physics中分别有2个、1个、1个异常值（离群点），箱形图中会将这些异常值单独列出，一是为了一目了然地表明数据中的异常，二是为了不因为这些少数的异常数据导致整体特征的偏移。

#### 5 WAV音频处理入门研究

Python在许多领域有重要的应用。例如，本实验的主要目的是学习使用Python对音频信号进行简单的处理。

实验的主要步骤如下：

1. 网络数据读取与保存

2. 使用scipy中的wavfile模块对音频信号进行简单的幅度处理

3. 使用matplotlib中的pylab模块对音频信号进行简单的频谱分析

1. 网络数据读取与保存

主要使用urllib.request模块

此处选择位于http://www.nch.com.au/acm/11k16bitpcm.wav的音频作为数据源，使用urllib.request.urlopen()函数取得该文件，并以‘english.wav’的文件名保存在本地的程序所在路径。

2. 简单幅度处理

使用wavfile模块可以比较简单地从wav格式的文件中读取出相应的采样率、数据等信息，而不必关心文件的格式细节。python的wave模块也有相应的操作，示例详见代码。读取后使用pyplot模块，可以绘制出音频文件的波形图。

在本例中，将信号幅值按比例减小，表现出来的效果就是声音强度减小。使用numpy模块，将原始数据与常数相乘，得到一个值减小的新数组。这里利用了numpy的广播机制，如果两个相乘的对象长度不等，numpy会根据一定的规则将对象扩展为相同的类型，再做运算。

计算完成后，使用wavfile.write()函数将修改后的音频信号写入一个新的文件中，命名为’silent.wav’，采样率未修改，与原音频相同。

最后使用matplotlib.pyplot绘制波形图对比。

3. 简单时频分析

音频信号是一种常见的非平稳信号，频域特性随时间变化。时频图是分析音频信号的常用工具，在一幅图中表示出信号的频率、幅度随时间的变化。pylab模块提供了specgram函数，可以简单地通过配置相应参数进行短时傅里叶变换，并输出时频图。

	{%highlight ruby%}
	wavfiles.py
    import scipy.io.wavfile
    import wave
    import matplotlib.pyplot
    import matplotlib.pylab
    import urllib.request
    import numpy
    
    response = urllib.request.urlopen('http://www.nch.com.au/acm/11k16bitpcm.wav')
    WAV_FILE = 'english.wav'
    file = open(WAV_FILE, 'wb+')
    file.write(response.read())
    file.close()
    wavefile = wave.open(WAV_FILE,'r')
    params = wavefile.getparams()
    nchannels, sample_width, framerate, numframes = params[:4]
    sample_rate, data = scipy.io.wavfile.read(WAV_FILE)
    matplotlib.pyplot.subplot(2,1,1)
    matplotlib.pyplot.title('Original')
    matplotlib.pyplot.plot(data)
    newdata = data * 0.2
    newdata = newdata.astype(numpy.int16)
    scipy.io.wavfile.write('silent.wav', sample_rate, newdata)
    matplotlib.pyplot.subplot(2,1,2)
    matplotlib.pyplot.title('Quiet')
    matplotlib.pyplot.plot(newdata)
    matplotlib.pyplot.show()
    result = matplotlib.pylab.specgram(newdata, NFFT=1024, Fs = sample_rate, noverlap=900)
    matplotlib.pylab.show()
	{%endhighlight%}
	
#### 编程作业：男女电影评分差异编程

##### 说明：

计算MovieLens 100k数据集中男性女性用户评分的标准差并输出。

数据集下载http://files.grouplens.org/datasets/movielens/ml-100k.zip

其中u.data 表示100k条评分记录，每一列的数值含义是：

user id | item id | rating | timestamp

u.user表示用户的信息，每一列的数值含义是：

user id | age | gender | occupation | zip code

u.item文件表示电影的相关信息，每一列的数值含义是：

movie id | movie title | release date | video release date |IMDb URL | unknown | Action | Adventure | Animation | Children's | Comedy | Crime | Documentary | Drama | Fantasy |Film-Noir | Horror | Musical | Mystery | Romance | Sci-Fi |Thriller | War | Western |

可能会用到的相关函数：

pandas.read_table(filepath_or_buffer, sep='\t', names=None)

pandas.pivot_table(data, values=None, columns=None, aggfunc='mean')

pandas.merge(left, right, how='inner')

更详尽的API文档请参考http://pandas.pydata.org/pandas-docs/stable/。

输出结果：

Gender

M *

F	*

结论：标准差高的评分差异大

注意：先分别计算每个人电影评分的平均分再按性别求标准差

请将男女评分（保留2位小数）组合后放到一个txt文件中通过网络提交，例如：如果两者评分的标准差分别是

男：0.32

女：0.35

则提交：

3235

##### 解决方法

说明中提到可能会用到相关函数有read_table(),pivot_table(),merge()三个，但是在实际编程中发现，虽然透视表的功能十分强大，但是其aggfunc参数无法从大的范围内求标准差，自身水平有限，故采用groupby函数直接求值。  

故基本操作顺序为：打开两个文件——合并两张表——用groupby划分区域并求标准差。  

##### 源代码

	{%highlight ruby%}
	moviestd.py
    import pandas as pd   
    df1 = pd.read_table('u.data',sep = '\t',names=['userid','rating'],usecols=[0,2])
    df2 = pd.read_table('u.user',sep = '|',names = ['userid','gender'],usecols=[0,2])
    df = pd.merge(df1,df2)
    std_male = df[df.gender=='M'].groupby('userid').rating.mean().std()
    std_female = df[df.gender == 'F'].groupby('userid').rating.mean().std()
    print(std_male)
    print(std_female)
	{%endhighlight%}

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
