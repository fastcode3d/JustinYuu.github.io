#Data Processing Using Python Week 1
本次课程基于coursera平台，由南京大学开设，语言为中文授课，因此在此类中博客以中文来书写

第一周主要介绍一些python基本的语法知识和一些简单的编程练习，本篇文章将按照课程开设顺序记录个人笔记和一些源代码

###1.1
1.1主要介绍Python开发环境的搭建（本MOOC基于Python 3），IDE的下载（本MOOC使用Python自带的IDLE和Anaconda Spyder），Python常用的数据类型、基本运算和函数、模块和包，整体较为基础。

练习用小测试
随堂测试：编写一个输入输出的程序（练习用，不计分）

简单的输入输出：编程实现输入姓、名的提示语并接受用户输入，并单独显示姓、名和全名，执行效果如下所示：

	Input your surname:ZHANG
	
	Input your firstname:Dazhuang
	
	Your surname is:
	
	ZHANG
	
	Your firstname is:
	
	Dazhuang
	
	Your full name is:
	
	ZHANG Dazhuang

源代码如下：

	{% highlight ruby %}
	1.1.py
	surname=input('Input your surname: ')
	firstname=input('Input your firstname: ')
	print('Your surname is:')
	print(surname)
	print('Your firstname is:')
	print(firstname)
	print('Your full name is:')
	print(surname,firstname)
	{%endhighlight%}

###1.2
####1.2.1 条件
主要为if,elif,else的运用，注意python没有花括号，因此用首行缩进代替花括号，因此在一个block中要注意首行缩进对齐，否则会导致程序报错
####1.2.2 range函数
range函数是python中很重要的一个函数，函数语法为

		range(start, stop[, step])
####1.2.3 循环 
python中的while循环和c/Java区别不大，但是for循环有一定区别，语法为

		for iterating_var in sequence:
	    statements(s)
此外，Python允许循环嵌套
####1.2.4 循环中的break,continue和else
break 和continue与C/JAVA大同小异，else语句可以在循环中使用。 如果循环代码从break处终止 就跳出循环 不执行后面else语句中的代码 如果正常结束循环 则会执行else中的代码 这种结构的设计适合于某一些问题 比如说非常典型的就是 判断素数的这样的一个例子 
####1.2.5 自定义函数
格式为

	   def functionname( parameters ):
	   "函数_文档字符串"
	   function_suite
	   return [expression]

####1.2.6 递归
又是经典的斐波那契数列- -
####1.2.7变量作用域
类似于C语言中的文件作用域和局部作用域
####编程小练习
1.编写一个输入分数，输出分数等级的程序

	{% highlight ruby %}
	1.2.1.py
	score=eval(input("Please input your score:  "))
	if 0<=score<=100:
	    if 90<=score<=100:
	        grade="A"
	    elif 70<=score<=89:
	        grade="B"
	    elif 60<=score<=69:
	        grade="C"
	    elif 0<=score<=59:
	        grade="D"
	    print("The grade of {} is {}.".format(score,grade))
	else:
	    print("Invalid score")
		{%endhighlight%}
2.验证命题：如果一个三位整数是37的倍数，则这个整数循环左移后得到的另两个3位数也是37的倍数。（注意验证命题的结果输出方式，只要输出命题为真还是假即可，而非每一个三位数都有一个真假的输出）

	{% highlight ruby %}
	1.2.1.py
	for num in range(100,1000):
	    if num%37==0:
	        num1=num % 100 * 10 + num//100
	        num2=num % 10 * 100 + num//10
	        if num1 % 37 != 0 or num2 % 37 !=0:
	            print("false!")
	            break
	else:
	        print("True!")
			{%endhighlight%}			
			
3.验证哥德巴赫猜想之一：2000以内的正偶数（大于等于4）都能够分解为两个质数之和。每个偶数表达成形如：4=2+2的形式，输出时每行显示6个式子。

	{% highlight ruby %}
	def isPrime(n):
	    i=2
	    while i<n//2+1:
	        if n % i == 0:
	            return False
	        i+=1
	    return True
	
	m=4
	count = 0
	while m<2000:
	    i=2
	    while i<m:
	        if isPrime(i) and isPrime(m-i):
	            count +=1
	            if count % 6 == 0:
	                print("{}={}+{}".format(m,i,m-i))
	            else:
	                print("{}={}+{}".format(m,i,m-i),end = ' ')
	            m+=2
	            break
	        else:
	            i+=1
	{%endhighlight%}
4.编写一个程序，让用户输入苹果个数和单价，然后计算出价格总额。

	while True:
	    try:
	        count = int(input("Enter count:"))
	        price = float(input("Enter price for each one: "))
	        pay = count * price
	        print("Pay : ",pay)
	        break
	    except ValueError:
	        print("Error,please enter another one.")
####补充1：标准库函数
介绍了python的几个标准库函数，如Math和时间函数
####补充2：异常
介绍了try,except 和 with 的用法，其中with函数比较有难度，with基于上下文管理器，语法格式如下

	with context_expression [as target(s)]:
    with-body
这里 context_expression 要返回一个上下文管理器对象，该对象并不赋值给 as 子句中的 target(s) ，如果指定了 as 子句的话，会将上下文管理器的 \__enter\__() 方法的返回值赋值给 target(s)。target(s) 可以是单个变量，或者由“()”括起来的元组（不能是仅仅由“,”分隔的变量列表，必须加“()”）。

Python 对一些内建对象进行改进，加入了对上下文管理器的支持，可以用于 with 语句中，比如可以自动关闭文件、线程锁的自动获取和释放等。假设要对一个文件进行操作，使用 with 语句可以有如下代码

	with open(r'somefileName') as somefile:
    for line in somefile:
        print line
        # ...more code
这里使用了 with 语句，不管在处理文件过程中是否发生异常，都能保证 with 语句执行完毕后已经关闭了打开的文件句柄。如果使用传统的 try/finally 范式，则要使用类似如下代码：

	somefile = open(r'somefileName')
	try:
	    for line in somefile:
	        print line
	        # ...more code
	finally:
	    somefile.close()
比较起来，使用 with 语句可以减少编码量。
####写出递归结果
简单的递归题目，答案-345，可用python验证 
####编程练习 寻找第N个莫尼森数
本章的编程练习相当简单，最终提交的文档居然是将查到莫尼森数的放在txt文档里上传，连代码都不看的，也是够水，不过好在这次编程练习比较简单，主要练习函数的定义和调用、循环的运用以及素数判定法的复习，代码如下：

	{%highlight ruby%}
	def isPrime(n):
    i=2
    while i<n//2+1:
        if n % i == 0:
            return False
        i+=1
    return True

	def monisen(n):
	    i=2
	    count = 0
	    while count!=n:
	        if isPrime(i):
	            m=2**i-1
	            if isPrime(m):
	                count +=1
	        i+=1
	    return m
	
	print("The 6th monisen number is",monisen(6))
	{%endhighlight%}
值得注意的是要在i和m的判定素数时分为两步判定，否则会因为i的不断增加而导致m的值错误（变大）
最终输出的结果是131071。