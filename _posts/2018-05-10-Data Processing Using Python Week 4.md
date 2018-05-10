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


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
