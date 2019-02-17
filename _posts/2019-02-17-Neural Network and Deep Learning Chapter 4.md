---
layout: post
title: "Neural Network and Deep Learning Chapter 4"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/02/17/
---
# Neural Network and Deep Learning Chapter 4  
第四章是本节的最后一章，主要内容是深度神经网络。之前所学习的神经网络都是一层隐藏层或者两层隐藏层，隐藏层层数偏少，便于理解，而这次要学习的神经网络的隐藏层就比较多了。  
这周的课程视频内容比较少，而编程作业的内容比较多，更具有挑战性。  

## Deep Neural Network  
### Deep L-layer neural network  
第一节首先讲了下这章所使用的神经网络的规模，共有三个隐藏层，单元数量是5 5 3，然后讲了一下notation和大致的步骤。  

### Forward Propagation in a Deep Network  
前向传播仍然是z=wx+b/wa+b，其中a的上标要比其他的少一层，因为是前一层的结果，以及a=g(z),这些均和上一章讲的相同。  
在上门课程中我引用过一篇回答[如何直观地解释 backpropagation 算法？ - YE Y的回答 - 知乎](https://www.zhihu.com/question/27239198/answer/43560763)，这个回答中的图片很直观的解释了多层神经网络中的forward prop和back prop。  
再次拿出我上一章推导的图：![4-1](/images/Neural Network and Deep Learning/3-3.jpg)  

### Getting your matrix dimensions right  
这一节教大家如何正确的区分矩阵的维度，我在上门课《machine learning》中神经网络那一节的编程作业中深有体会。我自己采取的方法是将所有矩阵的size全都记在草稿纸上，然后矩阵运算的时候逐一比对。  
![4-1](/images/Neural Network and Deep Learning/4-1.png)  
这个是吴大大总结的size，可以存着以后想不起来时查找用。  

### Why deep representations?  
这一节讲的是为什么需要如此深的神经网络。简单来讲，神经网络可以完成很复杂的工作，比如面部识别，但是还是要将复杂的工作拆分成比较简单的小部分来做，这时通过多层隐藏层的相互配合，就能完成复杂的工作处理。吴大大又举了异或的例子，如果只用一层的隐藏层，那么规模将是指数级的，因此深层的神经网络也可以减少单层的规模。  

### Building blocks of deep neural networks  
这节讲了组建神经网络时需要的模块，在每一个模块中都有前向传播和后向传播的步骤，然后模块与模块之间相互连接，最终组成一个深度神经网络。  

### Forward and Backward Propagation  
这节和上节的不同是把公式又写了一遍。讲这4周的课，吴大大把这些公式少说也得写了5遍，再记不住说不过去啦。  
值得注意的是σ函数在不同的隐藏层上也是不同的，这里他举例用的是第一第二层是ReLU，第三层是sigmoid，具体选择还是看个人。  

### Parameters vs Hyperparameters  
这一节介绍参数和超参数。首先介绍什么是参数：参数包括W和b，即θ。然后介绍什么是超参数:就是其他的参数，比如学习率α，迭代次数，隐藏层的层数，隐藏层的隐藏单元数，选择的激活函数种类等等，这些都需要在设计神经网络时设定。这些参数都会影响最后的W和b，所以称之为超参数。  

### What does this have to do with the brain?  
这节主要针对提问频率比较高的问题进行一个补充回答：深度学习与人类大脑有什么相似性？吴大大的回答是：没啥相似性。  
只不过神经网络的结点和神经元比较相似，都是接受刺激后进行处理，然后通过突触传递给下一个神经元。至今人类神经元如何处理数据仍然无人知晓，因此谈不上处理的相似性，只是有形式的相似性。  

## Programming Aassignments  
最后一周了，有两个编程练习，第一个是建立一个深层的神经网络，第二个是利用建立的深层神经网络来识别猫的图片。  

### Building your Deep Neural Network: Step by Step  
这个编程练习的确比较难，但是跟着提示做应该问题不大，最重要的是理解代码到底在干什么，而不是一味的写。  

#### 3-Initialization  
##### 3.1 -2-layer Neural Network  
      W1 = np.random.randn(n_h,n_x)*0.01
      b1 = np.zeros((n_h,1))
      W2 = np.random.randn(n_y,n_h)*0.01
      b2 = np.zeros((n_y,1))   
	  
##### 3.2 -L-layer Neural Network  
	parameters['W' + str(l)] = np.random.randn(layer_dims[l],layer_dims[l-1])*0.01
    parameters['b' + str(l)] = np.zeros((layer_dims[l] ,1))   
	
#### 4-Forword propagation module  
##### 4.1-Linear Forward  

`Z = np.dot(W,A)+b`  
##### 4.2-Linear-Activation Forward  
	if activation == "sigmoid":
			# Inputs: "A_prev, W, b". Outputs: "A, activation_cache".
			### START CODE HERE ### (≈ 2 lines of code)
			Z, linear_cache = linear_forward(A_prev,W,b)
			A, activation_cache = sigmoid(Z)
			### END CODE HERE ###

		elif activation == "relu":
			# Inputs: "A_prev, W, b". Outputs: "A, activation_cache".
			### START CODE HERE ### (≈ 2 lines of code)
			Z, linear_cache = linear_forward(A_prev,W,b)
			A, activation_cache = relu(Z)
			### END CODE HERE ###  
			
---  

	for l in range(1, L):
        A_prev = A 
        ### START CODE HERE ### (≈ 2 lines of code)
        A, cache = linear_activation_forward(A_prev,parameters['W'+str(l)],parameters['b'+str(l)],"relu")
        caches.append(cache)
        ### END CODE HERE ###
    
    # Implement LINEAR -> SIGMOID. Add "cache" to the "caches" list.
    ### START CODE HERE ### (≈ 2 lines of code)
    AL, cache = linear_activation_forward(A,parameters['W'+str(L)],parameters['b'+str(L)],"sigmoid")
    caches.append(cache)  
	
#### 5-Cost function  
	cost = (-1/m)*np.sum(np.multiply(Y,np.log(AL))+np.multiply((1-Y),np.log(1-AL)))

#### 6 - Backward propagation module
##### 6.1 -Linear backward  
    dW = (1/m)*np.dot(dZ,A_prev.T)
    db = (1/m)*np.sum(dZ,axis=1,keepdims=True)
    dA_prev = np.dot(W.T,dZ)
	
##### 6.2 -Linear-Activation backward  
    if activation == "relu":
        ### START CODE HERE ### (≈ 2 lines of code)
        dZ = relu_backward(dA, activation_cache)
        dA_prev, dW, db = linear_backward(dZ,linear_cache)
        ### END CODE HERE ###
        
    elif activation == "sigmoid":
        ### START CODE HERE ### (≈ 2 lines of code)
        dZ = sigmoid_backward(dA, activation_cache)
        dA_prev, dW, db = linear_backward(dZ,linear_cache)
		
##### 6.3 -L-Model Backward  
	{%highlight ruby%}
	# GRADED FUNCTION: L_model_backward
	def L_model_backward(AL, Y, caches):
		"""
		Implement the backward propagation for the [LINEAR->RELU] * (L-1) -> LINEAR -> SIGMOID group

		Arguments:
		AL -- probability vector, output of the forward propagation (L_model_forward())
		Y -- true "label" vector (containing 0 if non-cat, 1 if cat)
		caches -- list of caches containing:
					every cache of linear_activation_forward() with "relu" (it's caches[l], for l in range(L-1) i.e l = 0...L-2)
					the cache of linear_activation_forward() with "sigmoid" (it's caches[L-1])

		Returns:
		grads -- A dictionary with the gradients
				 grads["dA" + str(l)] = ... 
				 grads["dW" + str(l)] = ...
				 grads["db" + str(l)] = ... 
		"""
		grads = {}
		L = len(caches) # the number of layers
		m = AL.shape[1]
		Y = Y.reshape(AL.shape) # after this line, Y is the same shape as AL

		# Initializing the backpropagation
		### START CODE HERE ### (1 line of code)
		dAL =  - (np.divide(Y, AL) - np.divide(1 - Y, 1 - AL))
		### END CODE HERE ###

		# Lth layer (SIGMOID -> LINEAR) gradients. Inputs: "dAL, current_cache". Outputs: "grads["dAL-1"], grads["dWL"], grads["dbL"]
		### START CODE HERE ### (approx. 2 lines)
		current_cache = caches[L-1]
		grads["dA" + str(L-1)], grads["dW" + str(L)], grads["db" + str(L)] = linear_activation_backward(dAL, current_cache, activation = "sigmoid")
		### END CODE HERE ###

		# Loop from l=L-2 to l=0
		for l in reversed(range(L-1)):
			# lth layer: (RELU -> LINEAR) gradients.
			# Inputs: "grads["dA" + str(l + 1)], current_cache". Outputs: "grads["dA" + str(l)] , grads["dW" + str(l + 1)] , grads["db" + str(l + 1)] 
			### START CODE HERE ### (approx. 5 lines)
			current_cache = caches[l]
			dA_prev_temp, dW_temp, db_temp = linear_activation_backward(grads["dA"+str(L-1)], current_cache, activation = "relu")
			grads["dA" + str(l)] = dA_prev_temp
			grads["dW" + str(l + 1)] = dW_temp
			grads["db" + str(l + 1)] = db_temp
			### END CODE HERE ###
		return grads
	{%endhighlight%}
	
##### 6.4 - Update Parameters  
	 for l in range(L):
			parameters["W" + str(l+1)] = parameters["W"+str(l+1)]-learning_rate*grads["dW"+str(l+1)]
			parameters["b" + str(l+1)] = parameters["b"+str(l+1)]-learning_rate*grads["db"+str(l+1)]

### Deep Neural Network -Application  
这一节是用上一节的神经网络进行猫的识别，识别率比第二章所用的逻辑回归的识别率要高。  

#### 4-Two-layer neural network  

	# GRADED FUNCTION: two_layer_model
	{%highlight ruby%}
	def two_layer_model(X, Y, layers_dims, learning_rate = 0.0075, num_iterations = 3000, print_cost=False):
		"""
		Implements a two-layer neural network: LINEAR->RELU->LINEAR->SIGMOID.

		Arguments:
		X -- input data, of shape (n_x, number of examples)
		Y -- true "label" vector (containing 0 if cat, 1 if non-cat), of shape (1, number of examples)
		layers_dims -- dimensions of the layers (n_x, n_h, n_y)
		num_iterations -- number of iterations of the optimization loop
		learning_rate -- learning rate of the gradient descent update rule
		print_cost -- If set to True, this will print the cost every 100 iterations 

		Returns:
		parameters -- a dictionary containing W1, W2, b1, and b2
		"""

		np.random.seed(1)
		grads = {}
		costs = []                              # to keep track of the cost
		m = X.shape[1]                           # number of examples
		(n_x, n_h, n_y) = layers_dims

		# Initialize parameters dictionary, by calling one of the functions you'd previously implemented
		### START CODE HERE ### (≈ 1 line of code)
		parameters = initialize_parameters(n_x, n_h, n_y)
		### END CODE HERE ###

		# Get W1, b1, W2 and b2 from the dictionary parameters.
		W1 = parameters["W1"]
		b1 = parameters["b1"]
		W2 = parameters["W2"]
		b2 = parameters["b2"]

		# Loop (gradient descent)

		for i in range(0, num_iterations):

			# Forward propagation: LINEAR -> RELU -> LINEAR -> SIGMOID. Inputs: "X, W1, b1, W2, b2". Output: "A1, cache1, A2, cache2".
			### START CODE HERE ### (≈ 2 lines of code)
			A1, cache1 = linear_activation_forward(X, W1, b1, "relu")
			A2, cache2 = linear_activation_forward(A1, W2, b2, "sigmoid")
			### END CODE HERE ###

			# Compute cost
			### START CODE HERE ### (≈ 1 line of code)
			cost = compute_cost(A2, Y)
			### END CODE HERE ###

			# Initializing backward propagation
			dA2 = - (np.divide(Y, A2) - np.divide(1 - Y, 1 - A2))

			# Backward propagation. Inputs: "dA2, cache2, cache1". Outputs: "dA1, dW2, db2; also dA0 (not used), dW1, db1".
			### START CODE HERE ### (≈ 2 lines of code)
			dA1, dW2, db2 = linear_activation_backward(dA2, cache2, "sigmoid")
			dA0, dW1, db1 = linear_activation_backward(dA1, cache1, "relu")
			### END CODE HERE ###

			# Set grads['dWl'] to dW1, grads['db1'] to db1, grads['dW2'] to dW2, grads['db2'] to db2
			grads['dW1'] = dW1
			grads['db1'] = db1
			grads['dW2'] = dW2
			grads['db2'] = db2

			# Update parameters.
			### START CODE HERE ### (approx. 1 line of code)
			parameters = update_parameters(parameters, grads, learning_rate)
			### END CODE HERE ###

			# Retrieve W1, b1, W2, b2 from parameters
			W1 = parameters["W1"]
			b1 = parameters["b1"]
			W2 = parameters["W2"]
			b2 = parameters["b2"]

			# Print the cost every 100 training example
			if print_cost and i % 100 == 0:
				print("Cost after iteration {}: {}".format(i, np.squeeze(cost)))
			if print_cost and i % 100 == 0:
				costs.append(cost)

		# plot the cost

		plt.plot(np.squeeze(costs))
		plt.ylabel('cost')
		plt.xlabel('iterations (per tens)')
		plt.title("Learning rate =" + str(learning_rate))
		plt.show()

		return parameters
	{%endhighlight%}
		
#### 5-L-layer Neural Network  

	{%highlight ruby%}
	# GRADED FUNCTION: L_layer_model
	def L_layer_model(X, Y, layers_dims, learning_rate = 0.0075, num_iterations = 3000, print_cost=False):#lr was 0.009
		"""
		Implements a L-layer neural network: [LINEAR->RELU]*(L-1)->LINEAR->SIGMOID.

		Arguments:
		X -- data, numpy array of shape (number of examples, num_px * num_px * 3)
		Y -- true "label" vector (containing 0 if cat, 1 if non-cat), of shape (1, number of examples)
		layers_dims -- list containing the input size and each layer size, of length (number of layers + 1).
		learning_rate -- learning rate of the gradient descent update rule
		num_iterations -- number of iterations of the optimization loop
		print_cost -- if True, it prints the cost every 100 steps

		Returns:
		parameters -- parameters learnt by the model. They can then be used to predict.
		"""

		np.random.seed(1)
		costs = []                         # keep track of cost

		# Parameters initialization. (≈ 1 line of code)
		### START CODE HERE ###
		parameters = initialize_parameters_deep(layers_dims)
		### END CODE HERE ###

		# Loop (gradient descent)
		for i in range(0, num_iterations):

			# Forward propagation: [LINEAR -> RELU]*(L-1) -> LINEAR -> SIGMOID.
			### START CODE HERE ### (≈ 1 line of code)
			AL, caches = L_model_forward(X, parameters)
			### END CODE HERE ###

			# Compute cost.
			### START CODE HERE ### (≈ 1 line of code)
			cost = compute_cost(AL, Y)
			### END CODE HERE ###

			# Backward propagation.
			### START CODE HERE ### (≈ 1 line of code)
			grads = L_model_backward(AL, Y, caches)
			### END CODE HERE ###

			# Update parameters.
			### START CODE HERE ### (≈ 1 line of code)
			parameters = update_parameters(parameters, grads, learning_rate)
			### END CODE HERE ###

			# Print the cost every 100 training example
			if print_cost and i % 100 == 0:
				print ("Cost after iteration %i: %f" %(i, cost))
			if print_cost and i % 100 == 0:
				costs.append(cost)

		# plot the cost
		plt.plot(np.squeeze(costs))
		plt.ylabel('cost')
		plt.xlabel('iterations (per tens)')
		plt.title("Learning rate =" + str(learning_rate))
		plt.show()

		return parameters
	{%endhighlight%}

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
