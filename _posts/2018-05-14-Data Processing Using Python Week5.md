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

继承的概念来源于父类（基类）和子类（派生类）。  

子类的定义方法如下：

	class SubClassNmae(ParentClass1[,ParentClass2,...]):
		'optional class documentation string'
		class_suite
	
与JAVA不同，Python支持多继承。

默认情况下，Python类的成员属性和方法都是"public"，此外也提供“访问控制符”来限定成员函数的访问（双下划线和单下划线）。  
双下划线的作用是防止父类与子类的同名冲突。单下划线的作用是在属性名前使用一个单下划线字符，防止模块的属性用"from mymodule import * "来加载  

### 5.2 图形用户界面

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
