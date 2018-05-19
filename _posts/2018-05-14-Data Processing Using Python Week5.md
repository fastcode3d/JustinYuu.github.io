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

#### 5.2.1 GUI的基本框架

本章通过wxPython来介绍GUI

首先是创建wxPython的示例代码

	{%highlight ruby%}
	firstwxPython.py
	import wx
	app = wx.App()
	frame = wx.Frame(None,title="Hello,World!")
	frame.Show(True)
	app.MainLoop()
	{%endhighlight%}

演示后发现，程序运行的结果只有一个frame窗口和一个title，这就是最简单的GUI界面程序。

其他的功能需要通过添加组件来完成，如组件容器（	Containers），动态组件（Dynamic Widgets），静态组件(Static Widgets)和其他组件。

上文中的示例可进行进一步的改进，示例代码如下：

	{%highlight ruby%}
	helloworld.py
	import wx
	class Frame1(wx.Frame):
		def __init__(self,parent,title):
			wx.Frame.__init__(self,parent,title = title,pos=(100,200),size=(200,100))
			panel = wx.Panel(self)
			text1 = wx.TextCtrl(panel,value = "Hello,World!",size = (200,100))
			self.Show(True)
	if __name__ == '__main__':
		app = wx.App()
		frame = Frame1(None,"Example")
		app.MainLoop()
	{%endhighlight%}

GUI程序工作的基本机制之一为事件处理机制。Python的时间处理机制和Java中的基本相同，示例代码如下

	{%highlight ruby%}
	mouse.py
	import wx
	class Frame1(wx.Frame):
		def __init__(self,superior):
		... ...
		self.panel.Bind(wx.EVT_LEFT_UP,self.OnClick)
	def OnClick(self,event):
		posm = event.GetPosition()
		wx.StaticText(parent = self.panel,label = "Hello,World!",pos = (posm.x,posm.y))
		... ...
	{%endhighlight%}

运行过程中如果报错，需先在console中输入del app  

本段代码的作用是将鼠标抬起绑定在OnClick事件上

#### 5.2.2 GUI常用组件

本节介绍了几个比较常用的组件

__按钮__ 的功能是接受用户的点击事件，常用的按钮为wx.Button(文本按钮),wx.BitmapButton(位图按钮),wx.ToggleButton(开关按钮)

__菜单__ 包括菜单栏、菜单、菜单项命令，用于创建上述菜单的类分别是wx.MenuBar,wx.Menu,wx.MenuItem。而菜单的常用事件是wx.EVT_MENU。

__静态文本和文本框__ 是用于接受用户在框内输入的信息，或显示由程序提供的信息。类分别是wx.StaticText和wx.TextCtrl。

__列表__ 用于显示多个条目并且可供用户选择，以下面四种不同模式建造：wx.LC_ICON(图标),wx.LC_SMALL_ICON(小图标),wx.LC_LIST(列表),wx.LC_REPORT(报告)  

此外还有 __单选框和复选框__ 

程序示例如下：

	{%highlight ruby%}
	helloworldbtn.py
	import wx
	class Frame1(wx.Frame):
		def __init__(self,superior):
		wx.Frame.__init__(self,parent = superior,title="Hello World in wxPython")
		panel = wx.Panel(self)
		sizer = wx.BoxSizer(wx.VERTICAL)
		self.text1 = wx.TextCtrl(panel,value = "Hello,World!",size = (200,180),style = wx.TE_MULTILINE)
		sizer.Add(self.text1,0,wx,ALIGN_TOP|wx.EXPAND)
		button = wx.Button(panel,label = "Click Me")
		sizer.Add(button)
		panel.SetSizerAndFit(sizer)
		panel.Layout()
		self.Bind(wx.EVT_BUTTON,self.OnClick,button)
	def OnClick(self,text):
		self.text1.AppendText("\nHello,World!")
	{%endhighlight%}

#### 5.2.3 布局管理

布局管理由sizer实现

sizer本身不是一个容器或一个窗口部件，它只是一个屏幕布局的算法

sizer允许嵌套

常用的sizer有wx.BoxSizer,wx.FlexGridSizer,wx.GridSizer,wx.GridBagSizer,wx.StaticBoxSizer

类似Java中的布局管理器(layout)。

使用sizer的步骤：创建自动调用尺寸的容器，例如panel——创建sizer——创建子窗口——使用sizer的Add()方法将每个子窗口添加给sizer——调用容器的SetSizer(sizer)方法

#### 5.2.4 其他GUI库



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
