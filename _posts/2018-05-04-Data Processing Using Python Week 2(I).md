---
layout: post
title: "Data Processing Using Python Week 2(I)"
description: "My notes while startiing python"
categories: [Data-Processing-Using-Python]
tags: [Python]
redirect_from:
  - /2018/05/04/
---
# Data Processing Using Python Week 2(I)

第二章主要包括数据的获取与表示，学习爬虫与序列运算等知识

## 2.1 数据获取 Data Acquisition and Representation

### 2.1.1 本地数据获取

文件打开方式为调用Open函数：

		file_obj = open(filename,mode='r',buffering = -1,...)

mode为可选参数，默认值为r，buffering也为可选参数，默认值为-1（0表示不缓冲，1或大于1的值表示缓冲一行或缓冲指定缓冲区大小）  
open函数的mode参数和C语言中的打开模式参数相似，具体表格参见Python具体教程  
Open()函数的返回值返回一个可迭代的file对象，file的函数调用如下  
file_obj.write(str) 可以将一个字符串写入文件

		f=open('firstpro.txt','w')
		f.write('Hello,World!')
		f.close()

但是更为方便的进行文件异常处理，我们常用上节所讲的with语句所代替，其代码为

		with open('firstpro.txt','w')as f:
			f.write('Hello,World!')  

而f.read()为读取文件命令，通过文件指针进行遍历读取  
f.tell()也为查看文件命令，但是与f.read()比没有只读一次的限制。  
f.writelines()和f.readlines()与f.write()和f.read()进行区分。  
file.write(str)的参数是一个字符串，就是你要写入文件的内容；file.writelines(sequence)的参数是序列，比如列表，它会迭代帮你写入文件。而前者不会自动换行，而后者会自动换行。  
file.readlines()自动将文件内容分析成一个行的列表，该列表可以由 Python 的 for... in ... 结构进行处理.  
file_obj.seek(offset,whence=0)函数可以在文件中移动文件指针，从whence（0表示文件头部，1表示当前位置，2表示文件尾部）偏移offset个字节。whence参数可选，默认值为0.  
python中的文件输入输出和C语言有很多相似之处，两者可以进行一定的参考对比。  
python中也存在三种标准文件有效，分别是stdin,stdout,stderr。print函数的具体实现模块也是通过调用sys函数中的stdout方法达成的。  
### 2.1.2 网络数据获取
网络数据的爬取分为两步，即抓取和解析。  
#### 抓取  
抓取的框架基于urllib内建模块、Requests第三方库和Scrapy框架，而解析由BeautyfulSoup库和re模块实现。有时也会由第三方API抓取解析。  
_**Requests库：**由Python官方提供。其用法为re=requests.get('网址')来抓取静态页面内容  
  在爬虫命令之前，可以先去网站的robot.txt文件查看爬虫权限。  
  在抓取动态网站的数据时，可以在get方法结束后根据网站的解码方式来调用不同的解码函数，如re.json(javascript解码)或者re.content(二进制解码)，通过re.encoding函数可以修改解码方式，示例代码如下  

		import requests
		response = requests.get("https://www.baidu.com")
		print(type(response))
		print(response.status_code)
		print(type(response.text))
		print(response.text)
		print(response.cookies)
		print(response.content)
		print(response.content.decode("utf-8"))
	
或者用上文提到的方法，通过response.encoding来实现，源代码如下

		response = requests.get("https://www.baidu.com")
		response.encoding = "utf-8"
		print(response.text)  
		  
为了反爬，有些网站会对headers的User-Agent进行检测，需将headers信息传递给get函数的headers参数，例如知乎，直接访问会返回500，加上headers参数后可正确返回

		re = requests.get('http://www.zhihu.com')
		500
			headers={"user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36"}
		re = requests.get('http://www.zhihu.com',headers = headers)
		re.status_code
		300  
		  
#### 解析  
通过BeautifulSoup从HTML或XML文件中提取数据的Python库
		
		soup.find_all('p',comment-content)
		  
re正则表达式模块进行各类正则表达式处理

	'<span class="user-stars allstar(.*?)rating"'
	  
通过BeautifulSoup与正则表达式配合，可以完成大多数网站数据的解析工作。  
### 正则表达式基本知识和在线测试工具  
介绍了正则表达式中元字符的用法，值得注意的是当正则表达式中包含重复的限定符如“\*”时，通常会匹配尽可能多的字符，例如对于正则表达式“a.\*b”，它会匹配以a开头以b结尾的最长字符串，如果用它来搜索aabbab时，它会匹配整个字符串aabbab，这种方式称为贪婪匹配。如果想匹配尽可能少的字符，即进行懒惰匹配，则只要在“.*”后加上“?”构成“.\*?”，例如用懒惰匹配来搜索aabbab时，会匹配aab和ab。  
### 迷你爬虫编程小练习  
要求：请在豆瓣任意找一本图书，抓取它某一页的短评并进行页面解析将短评文字抽取后输出，再对其中的评分进行抽取计算其总分。  


		{%highlight ruby%}
		# -*- coding: utf-8 -*-
		"""
		Created on Tue Apr 24 21:20:55 2018
		
		@author: Justin
		"""
		
		import requests
		import re
		from bs4  import BeautifulSoup
		
		sum= 0
		r = requests.get('https://book.douban.com/subject/30170113/comments/')
		soup = BeautifulSoup(r.text,'lxml')
		pattern_c = soup.find_all('p','comment-content')
		for item in pattern_c:
		    print(item.string)
		pattern_s = re.compile('<span class="user-stars allstar(.*?) rating" ')
		p = re.findall(pattern_s,r.text)
		for star in p:
		    sum+=int(star)
		print('sum=',sum)
		{%endhighlight%}  
		  
### 爬虫进阶实战  
1.	“迷你爬虫编程小练习”进阶：抽取某本书的前50条短评内容并计算评分的平均值。  

2.	在“http://money.cnn.com/data/dow30/”上抓取道指成分股数据并将30家公司的代码、公司名称和最近一次成交价放到一个列表中输出。

3. 请爬取网页（http://italy2014.fivb.org/en/competition/results_and_statistics）上的数据  
1.  
---
		{%highlight ruby%}
		bookcrawler pro.py
 		# -*- coding: utf-8 -*-
		"""
		Created on Tue Apr 24 21:38:35 2018

		@author: Justin
		"""

		import requests
		import re
		import time
		from bs4  import BeautifulSoup

		count = 0
		count_star = 0
		sum= 0
		i=0;
		while(count < 50):
			try:       
				r = requests.get('https://book.douban.com/subject/1083762/comments/hot?p=' + str(i+1))
			except Exception as err:
				print(err)
				break
			soup = BeautifulSoup(r.text,'lxml')
			comment = soup.find_all('p','comment-content')
			for item in comment:
				count = count + 1
				print(count, item.string)
				if count == 50:
					break
			pattern = re.compile('<span class="user-stars allstar(.*?) rating" ')
			p = re.findall(pattern,r.text)
			for star in p:
				count_star = count_star + 1
				sum += int(star)
			time.sleep(5)
			i += 1
		if count == 50:
			print(sum / count_star /10)
		{%endhighlight%}  
---  
2.  
		{%highlight ruby%}
		dowcrawler.py
		import requests
		import re
		
		r = requests.get('http://money.cnn.com/data/dow30/')
		search_pattern = re.compile('class="wsod_symbol">(.*?)<\/a>.*?<span.*?">(.*?)<\/span>.*?\n.*?class="wsod_stream">(.*?)<\/span>')
		dowresult = re.findall(search_pattern, r.text)
		print(dowresult)
		{%endhighlight%}  
---
3.  
		{%highlight ruby%}
		fivb2014crawler.py
		import requests
		import re

		count = 1;
		r = requests.get('http://italy2014.fivb.org/en/competition/results_and_statistics')
		pattern = re.compile('<td><a id="wcbody_0_wcgridpade50e7ca82ec64ee2b91ea4cc6c4e00c6_1_PlayerStatisticsTable_BestScorers_Name_.*?" href="/en/competition/teams/.*?/players/.*?id=.*?">(.*?)</a></td>\s+<td id="wcbody_0_wcgridpade50e7ca82ec64ee2b91ea4cc6c4e00c6_1_PlayerStatisticsTable_BestScorers_TeamCell_.*?"><a id="wcbody_0_wcgridpade50e7ca82ec64ee2b91ea4cc6c4e00c6_1_PlayerStatisticsTable_BestScorers_Team_.*?" href="/en/competition/teams/.*?">(.*?)</a></td>\s+<td>(.*?)</td>\s+<td>(.*?)</td>\s+<td>(.*?)</td>\s+<td>(.*?)</td>')
		fivb2014result = re.findall(pattern, r.text)
		print(fivb2014result)
		{%endhighlight%}
		
---  
本博客采用disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
