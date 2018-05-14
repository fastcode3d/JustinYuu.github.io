---
layout: post
title: "Data Processing Using Python Week 5"
description: "My notes while startiing python"
categories: [Data-Processing-Using-Python]
tags: [Python]
redirect_from:
  - /2018/05/14/
---
# Data Processing Using Python Week 5

### 5.1 面向对象

#### 5.1.1 GUI与面向对象

Python可以创建GUI（图形用户界面），也可以依靠面向对象的思想进行程序设计。

#### 5.1.2 抽象

面向对象思想在多种面向对象编程语言中都有应用。  

对象（实例）是由数据及能对其实施的操作所构成的封装体。而类描述了对象的特征（数据和操作）  

抽象思想是将不同点抛弃，只保留相同点，将对象的共同点总结为类的思想，是面向对象编程中的重要思想。

类的定义： 

	class ClassName(object:):  
	'define ClassName class'  
	class_suite  
	
类的方法定义：
	
	class Dog(object):  
		def greet(self):  
		print('Hi!')  
		
而通过实例来使用类方法。而实例的创建要通过调用类对象。具体方法为：定义类——创建一个实例——通过实例使用属性或方法。  

	dog = Dog()  
	dog.greet()  

创建实例时除了调用内存，必须调用 __init()__ 方法  

#### 5.1.3 继承



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
