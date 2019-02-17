---
layout: post
title: "Neural Network and Deep Learning Chapter 3"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/02/16/
---
# Neural Network and Deep Learning Chapter 3  
第三章的内容比较重要，主要是深入探讨神经网络的细节，并实现一个神经网络。  

## Shallow Neural Network  
### Neural Network Overview  
首先讲了有一层隐藏层的神经网络是什么样子，以及在这种神经网络下的反向/正向传播，这在我之前的博客中都有提到，之前也都学过，就不重复写笔记了。

### Neural Network Representation  
接来来讲了具体的表示方法，在神经网络的每一个结点中都包含两个步骤，第一个是计算z=wTx+b，也就是θx，第二个是计算a=σ(z),之后令yhat=a。这里吃过上次学习的亏，一定要把上标和下标搞清楚，上标指的是层数，下标指的是层内的结点数。  

### Computing a Neural Network's Output && Vectorizing accross multiple examples    
在接下来是计算输出和向量化，由于一组数据可能包含多个数据，所以在上标的层数[i]后面再加一个数据号(j)，代表这组数据中的第j个数据。然后还是按照层的顺序进行z和a的计算。这样很自然的就想到了向量化，首先是将每一层的每一批结点向量化，然后是将每一批结点内的数据向量化，说白了就是将矩阵的横竖两个方向都向量化。事实上，参数z，a，还有x都是一个矩阵，a矩阵的列代表不同的隐藏层，行代表不同的训练数据，同理z矩阵也是，而x的行是不同的训练实例，而列是不同的特征。  

### Explanation for Vectorized Implementation  
紧接着吴大大证明了向量化的正确性，证明方式是将行列数写清楚然后乘起来，从而得到数学运算的正确性，值得注意的一点是先将b设置为0，也就是计算不含b的部分，然后通过python的广播机制来加上b。  
![3-1](/images/Neural Network and Deep Learning/3-1.png)  
上图是目前的总结，我觉得这页PPT很好，就放到了这里。  

### Activation functions  
接下来是介绍了激活函数，吴大大介绍了另一个函数tanh，他认为这个函数严格优于sigmoid，数据中心化后平均值更接近0，因为其原始范围是-1到-1，而在二元分类的时候sigmoid会更好一点，其范围是0到1，因为在二元分类时我们只需要0和1，不需要负数。但是我想起了第一章采访时介绍的ReLU（线性整流）函数，我感觉ReLU函数好像比这两个都要好一点。果然后面就介绍了ReLU，ReLU函数的图像很简单，x负半轴上值为0，x正半轴上导数为1。  
这样吴大大最终确定了使用规则：当二元分类问题时用sigmoid，其他神经元上用ReLU，tanh刚刚闪亮登场就被无情抛弃，不过后来吴大大又提了一句有时候也会用tanh，但是没有说明具体情形。那我就很好奇了，于是我去Google了一下，发现了一篇足够新的文章，发表于19年2月11号[也谈激活函数Sigmoid,Tanh,ReLu,softplus,softmax - weibo248的文章 - 知乎](https://zhuanlan.zhihu.com/p/48776056)，假设他说的对，那么tanh好像的确用处不大，还有一个回答：[神经网络激励函数的作用是什么？有没有形象的解释？ - 论智的回答 - 知乎](https://www.zhihu.com/question/22334626/answer/465380541)。我又看了几个不同的回答，都没有提到太多tanh的用处，只是说比sigmoid要好，结合ReLU的缺点是learning rate过大会导致太多神经元失效，我只能理解当无法确定Learning rate的具体值的时候可以尝试一下tanh？此处存疑。  

### Why do you need non-linear activation functions?  
学了这么久，我突然发现我好像没有彻底弄懂激活函数的作用，为什么没有激活函数就没法非线性分类呢？于是我找了一篇知乎回答[神经网络激励函数的作用是什么？有没有形象的解释？ - 颜沁睿的回答 - 知乎](https://www.zhihu.com/question/22334626/answer/103835591)，还有这一篇[神经网络激励函数的作用是什么？有没有形象的解释？ - 非理的回答 - 知乎](https://www.zhihu.com/question/22334626/answer/21036590)。  
吴大大还介绍了一个函数Leaky ReLU,该函数的特点为x负半轴上斜率很小，但不为0，这个函数的效果比ReLU要好，但是使用较少。吴大大说当你们以后用的时候，可以大胆的去尝试这个函数，那么我如果以后有机会做这方面的项目时，就大胆的用这个函数好了，看看效果咋样。  
吴大大好像知道我在想什么，下一节介绍的就是激活函数的作用，正是我上上段的内容，有了PPT的动态演示更好理解了一点，简单来讲如果没有非线性函数，那么无论怎么在隐藏层内变换，始终是线性变换，只不过是参数不同罢了，那么变了和不变是一样的，如果线性函数无法将数据集所在的空间分开，那么无论隐藏层内如何变换都无法分开，所以就需要变化更为强大的非线性激活函数。  

### Derivatives of activation functions  
这一节主要是教大家求导，但是具体的求导并没有解释，而是直接给出了结果，所以更像是把导数公式列出来，不过求导本身也很简单，因此简单带过。  

### Gradient descent for Neural Network  
本节介绍了神经网络中的梯度下降以及反向传播的整个流程，一共是4+6=10个方程，这用一页PPT来表示最合适不过
![3-2](/images/Neural Network and Deep Learning/3-2.png)  

### Backpropagation intuition  
这节的内容是推导反向传播算法，我认为与其把视频上的推导过程抄一遍，不如自己推导一遍，我会在本章学完后把推导的图片上传到这里。  
来了，自己推导一遍后的确理解的更深了。  
![3-3](/images/Neural Network and Deep Learning/3-3.jpg)  

### Random Initialization  
在Machine Learning这门课里，已经学过了要随机初始变量，这里在不同的课程当然要再次强调一遍。假设将所有的初始值设置为0，无论使用什么样的样本进行训练 a[1]1与a[1]2始终是相同的，这样第一个激活函数和这第二个激活函数将是完全一致的，因为这些隐藏神经元在进行完全相同的计算工作。如果你在神经网络中，将所有权重参数矩阵w的值初始化为零，由于两个隐藏单元肩负着相同的计算功能，并且也将同样的影响作用在输出神经元上，经过一次迭代后，仍然会得到相同的结果。这两个隐藏神经元依然是“对称”的，同样推导下去，经过两次迭代、三次迭代、以及更多次迭代，无论你将这个神经网络训练多久，这两个隐藏单元仍然在使用同样的功能进行运算。在这个例子中，由于隐藏单元实现的都是相同的功能，所以我们使用一个就够了。如果有多个输入特征值仍然都是对称的，因此我们需要随机初始化来打破这种对称。     
## Programming Assignment(Planar data classification with a hidden layer)  
本周的编程作业是做一个有一层隐藏层的神经网络并识别分类红点和蓝点，要求很详细，按照要求做就可以。  

### 2-Dataset  
    shape_X = X.shape
    shape_Y = Y.shape
    m = X.shape[1]  
	
### 4-Neural Network model  

#### 4.1 - Defining the neural network structure  
	n_x = X.shape[0] # size of input layer
    n_h = 4
    n_y = Y.shape[0]

#### 4.2 - Initialize the model's parameters 
	W1 = np.random.randn(n_h,n_x) * 0.01
    b1 = np.zeros((n_h,1))
    W2 = np.random.randn(n_y,n_h) * 0.01
    b2 = np.zeros((n_y,1))  
	
#### 4.3 - The Loop  
	W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]  
	Z1 = np.dot(W1,X)+b1
    A1 = np.tanh(Z1)
    Z2 = np.dot(W2,A1)+ b2
    A2 = sigmoid(Z2)
---  

	logprobs = np.multiply(np.log(A2),Y)+np.multiply(np.log(1-A2),(1-Y))
    cost = -(1/m) * np.sum(logprobs)  

---  

	W1 = parameters["W1"]
    W2 = parameters["W2"]
	A1 = cache["A1"]
    A2 = cache["A2"]
	dZ2 = A2 - Y
    dW2 = (1/m)*np.dot(dZ2,A1.T)
    db2 = (1/m)*np.sum(dZ2,axis=1,keepdims = True)
    dZ1 = np.multiply(np.dot(W2.T,dZ2),(1 - np.power(A1, 2)))
    dW1 = (1/m)*np.dot(dZ1,X.T)
    db1 = (1/m)*np.sum(dZ1,axis=1,keepdims = True)
	
---

	W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
	dW1 = grads["dW1"]
    db1 = grads["db1"]
    dW2 = grads["dW2"]
    db2 = grads["db2"]
	W1 = W1 - learning_rate * dW1
    b1 = b1 - learning_rate * db1
    W2 = W2 - learning_rate * dW2
    b2 = b2 - learning_rate * db2
	
####  4.4 - Integrate parts 4.1, 4.2 and 4.3 in nn_model()  

	parameters = initialize_parameters(n_x, n_h, n_y)
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
	for i in range(0, num_iterations):     
        A2, cache = forward_propagation(X, parameters)
        cost = compute_cost(A2, Y, parameters)
        grads = backward_propagation(parameters, cache, X, Y)
        parameters = update_parameters(parameters, grads, learning_rate = 1.2)
        if print_cost and i % 1000 == 0:
            print ("Cost after iteration %i: %f" %(i, cost))
    return parameters  
	
#### 4.5 Predictions  
	
	A2, cache = forward_propagation(X, parameters)
    predictions = (A2 > 0.5)

## Heroes of Deep Learning  
本章介绍的大佬是Ian Goodfellow,这位著名的深度学习专家最大的贡献是发明了[生成对抗网络（GANs）](https://en.wikipedia.org/wiki/Generative_adversarial_network)。  
这位大佬晚上和朋友喝完酒后回到家，然后用了一个晚上写出了第一版的GANs，并且运行成功没有错误。他有一次健康情况不容乐观，可能会有死亡的风险，这时候他首先想的是赶紧把研究方向和思路给朋友说，让他们继续研究下去，从而不让这个研究思路断掉，这境界也太高了- -。  
讲完了他的故事，接下来就是他的专业方向，正如维基百科所说，生成对抗网络是非监督式学习的一种方法，通过让两个神经网络相互博弈的方式进行学习。GANs由一个生成网络与一个判别网络组成，判别网络的输入则为真实样本或生成网络的输出，其目的是将生成网络的输出从真实样本中尽可能分辨出来。而生成网络则要尽可能地欺骗判别网络。两个网络相互对抗、不断调整参数，最终目的是使判别网络无法判断生成网络的输出结果是否真实。那显然，GANs可用于生成大量的数据用于训练其他模型。  
Goodfellow提到的一点我认为很正确，大家看到机器学习算法都会很激动，但是一个优秀的从业者（我个人认为是一个合格的从业者），都要掌握概率论和线性代数的基础知识，这样才可以更好的理解算法。想想自己考研学过线代和高数，但是大二学习的概率论已经忘得差不多了，而且高等代数也没有学过，因此还需要抓紧继续学习。  
最后一部分是回归过去十年人工智能和机器学习领域的发展，那无疑是发展的越来越好，研究问题的规模越来越大，所要考虑的问题也越来越多。但是我最喜欢的对学习者的建议环节这个视频好像没有，还是有点小失望的。  

第三周的笔记到这里就结束啦，第四周见~  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
