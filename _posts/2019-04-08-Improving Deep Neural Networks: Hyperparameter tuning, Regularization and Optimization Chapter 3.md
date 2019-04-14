---
layout: post
title: "Improving Deep Neural Networks: Hyperparameter tuning, Regularization and Optimization Chapter 3"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/04/08/
---

# Improving Deep Neural Networks: Hyperparameter tuning, Regularization and Optimization Chapter 3  

失踪人口回归。  
最后一周啦，本周将继续介绍一些神经网络的优化方法，此外，将会介绍tensorflow，我终于可以接触到TensorFlow啦。  

## Hyperparameter tuning  

本周首先介绍的是一些调参技巧，参指的是超参数。吴恩达建议不要用网格划分的方式来寻找参数，这样虽然分的比较平均，但是代价很高，如果参数大于2，那么维度将会大大增加。吴恩达建议用从粗到细的选择方式，首先随机选取一些点，找出效果最好的一部分，然后在这一部分中选取更多的点，循环往复几次就可以将区域缩小到一个很小的范围。至于缩小范围的方式，吴恩达建议用Log来代替linear，在对数尺寸上随机的取样，这样可以将有限的资源合理分配。那么将视角放远来看，调参本身就有两种方式，一种被Andrew称之为“熊猫”方式，即一次只聚焦于一个模型；另一种被Andrew称为“鱼子酱”方式，即一次性平行调参多个模型。这时候的选择就应该要看机器配置和训练规模了，听Andrew的意思是如果不复杂还是尽量上多线程。  

## Batch Normalization  

本节介绍的是一种称之为“批量均一化”的方法。这种方法可以超参搜索变得很简单，使神经网络变得更加具有鲁棒性，并使神经网络对于超参数的选择上不再那么敏感，而且可以更容易地训练非常深的网络。简单来讲，他的做法是在每一个隐藏层上都进行一步均一化，从而使得每次进入激活函数的梯度都比较大，从而避免位置在激活函数的边缘从而导致梯度消失的情况。我感觉自己理解并记录下来的内容还是有些空洞，于是找了一篇我觉得写得很好的博客放在这里：[深入理解Batch Normalization批标准化](https://www.cnblogs.com/guoyaohua/p/8724433.html)  
放到实例中来讲，在每一层神经网络中的z值都进行一步BN操作，然后将BN后的z'来代替原有的z进入激活函数即可。值得注意的是，如果明知道计算的z要进行BN操作，那么wx+b可以进行简化，这是因为由于均一化的效果，加上任何一个常数都会被均一化均掉，因此没有意义再加上一个常数b，一般都用另外一个控制最终偏移量的参数β来代替。  
此外，由于在小批量梯度下降中，BN操作所除的平均值和方差都是小批量的平均值和方差，而不是整个数据集的，因此每一个隐藏层的激活层上都会有一些噪音。而由于BN操作使得后续的隐藏单元没有那么依赖之前的隐藏单元，因此它还有轻微的正则化的效果。  
在BN操作中，缩放比例需要除以标准差和平均值，但是如果在某个小批量中没有64或者128组数据，甚至只有一种实例，那么就无法通过计算的方式来得到标准差和平均值。这时吴恩达建议用指数加权平均的方式来解决，这样即使最后一个小批量无法得到有效的标准差和平均值，还是可以通过之前求得的加权平均值来得到近似正确的结果。  

## Multi-class classification  

本节介绍了一种类似于逻辑回归的二分但不局限于二分的适用于多种分类的预测方式，称之为softmax regression，实现方式是通过n个输出单元来完成，n即分类的数量，输出层的结果是每个单元的概率，n个概率加和为1。具体做法是在激活函数输出值后，均一化到以1为单位即可。  

## Introduction to programming frameworks  

终于到了介绍框架的时候，我激动的开始学习TensorFlow的使用方法了。本节只是简要介绍了一下，并举了一个梯度下降的训练例子来解释，我感觉还是不太懂，因此准备在编程练习时在认真看一下。  

## Programming Assignment   

本周的任务分为两部分，第一部分是熟悉TensorFlow，也就是tensor和session。第二部分是用TensorFlow实现简单的浅层神经网络。总体来说不难，目的本身就是熟悉TensorFlow。  

### 1.1  

    X = tf.constant(np.random.randn(3,1),name = "X")
    W = tf.constant(np.random.randn(4,3),name = "W")
    b = tf.constant(np.random.randn(4,1),name = "b")
    Y = tf.add(tf.matmul(W,X),b)  
    
### 1.2  

    x = tf.placeholder(tf.float32,name = "x")
    sigmoid = tf.sigmoid(x)
    with tf.Session() as sess:
        result = sess.run(sigmoid,feed_dict = {x:z})  
        
### 1.3  

    z = tf.placeholder(tf.float32,name = "z")
    y = tf.placeholder(tf.float32,name = "y")
        cost = tf.nn.sigmoid_cross_entropy_with_logits(logits = z,labels = y)
    sess = tf.Session()
    cost = sess.run(cost,feed_dict = {z:logits,y:labels})
    sess.close()  
    
### 1.4  

    C = tf.constant(C,name = "C")
    one_hot_matrix = tf.one_hot(labels,C,axis = 0)
    sess = tf.Session()
    one_hot = sess.run(one_hot_matrix)
    sess.close()
    
### 1.5

    ones = tf.ones(shape)
    sess = tf.Session()
    ones = sess.run(ones)
    sess.close()
    
### 2.1  

    X = tf.placeholder(tf.float32,[n_x,None])
    Y = tf.placeholder(tf.float32,[n_y,None])
    
### 2.2  

    W1 = tf.get_variable("W1",[25,12288],initializer = tf.contrib.layers.xavier_initializer(seed = 1))
    b1 = tf.get_variable("b1",[25,1],initializer = tf.zeros_initializer())
    W2 = tf.get_variable("W2",[12,25],initializer = tf.contrib.layers.xavier_initializer(seed = 1))
    b2 = tf.get_variable("b2",[12,1],initializer = tf.zeros_initializer())
    W3 = tf.get_variable("W3",[6,12],initializer = tf.contrib.layers.xavier_initializer(seed = 1))
    b3 = tf.get_variable("b3",[6,1],initializer = tf.zeros_initializer())
    
### 2.3  

    Z1 = tf.add(tf.matmul(W1,X),b1)
    A1 = tf.nn.relu(Z1)
    Z2 = tf.add(tf.matmul(W2,A1),b2)
    A2 = tf.nn.relu(Z2)
    Z3 = tf.add(tf.matmul(W3,A2),b3)

### 2.4  

    cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=logits,labels =labels))
    
### 2.6  

    X, Y = create_placeholders(n_x,n_y)
    parameters = initialize_parameters()
    Z3 = forward_propagation(X,parameters)
    cost = compute_cost(Z3,Y)
    optimizer = tf.train.AdamOptimizer(learning_rate = learning_rate).minimize(cost)
    
    _ , minibatch_cost = sess.run([optimizer, cost], feed_dict={X: minibatch_X, Y: minibatch_Y})  
    
至此这门课程就结束啦，这门课只有三周，但是由于中间松懈了三周左右，所以用了一个多月才完成，要赶快学习下一门课程啦。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
