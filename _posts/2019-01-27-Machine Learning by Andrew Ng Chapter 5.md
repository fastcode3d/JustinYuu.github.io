---
layout: post
title: "Machine Learning by Andrew Ng Chapter 5"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/01/27/
---
# Machine Learning by Andrew Ng Chapter 5
 
## 前言  

这几天快点看，争取年前看完这一课程，年后看229和231n。[第五章笔记](https://www.coursera.org/learn/machine-learning/resources/EcbzQ)  
第五章主要介绍的是神经网络的细节。  

## CostFunction and Backpropagation  

本节主要介绍神经网络的代价函数和反向传播算法，如果说之前的逻辑回归所用到的是向量，那么神经网络用到的就是矩阵，因为由上章的知识可知神经网络不同于逻辑回归，只有输入层和输出层，而是有若干个中间的隐藏层，因此不管是代价函数还是其他，都需要考虑到各个层的值，即各个组成的一个矩阵，而不是简单的输出层这一层的向量。  
代价函数在官方笔记里有给出，具体的参数也有说明，和逻辑回归的最大的区别就是求和变成了一个双重求和和三重求和，其目的分别是计算输出层中每个单元逻辑回归代价和将所有网络中的theta值平方求和以供正规化。  
显然如此复杂的神经网络的难点在于求导，课程里介绍的求偏导的方式叫做反向传播算法。  

### Backpropagation  

反向传播算法应该算是本章的难点之一，由于本章的笔记都是文字段落没有图片作为支撑，所以参考了知乎的一个问题里的第一和第二个回答[如何直观地解释backpropagation算法?](https://www.zhihu.com/question/27239198)，这样看的明白了一些。  
简而言之，反向传播算法的最终目的在于求导，而求偏导的方式即高数里学到的多元函数链式求导法则，而链式求导如果采用从上至下的方式，则会有大量的冗余值被多次求导，这在非常复杂的神经网络中代价非常大，因此采取了反向传播这一方式，逐层求出上层到该层的偏导数存放在该节点位置，等一层的偏导数都算完后，再依照下一层需要的次序“分发”给下层。我觉得这很像数据结构里面的DFS和BFS，如果用普通的链式求导法则，比较像DFS的一次循环，从一条路走到底，然后再进行完整的一次DFS循环，而反向传播比较像BFS，或者说层序遍历，将每一层的值全都得出，然后根据下一层的需要将值传递给下一层，这样可以解决冗余值的问题。吴大大的课程里只讲到了怎么做，但没讲（或是我没听明白）为什么这样做，参考知乎的回答可以进行一些补充，此外，另一个回答的一系列图片我认为非常好，可以更好的理解forward-propagation、error backward-propagation和back prop这一整套流程。  

## Backpropagation in practice  

本节继续介绍back prop，讲了如何展开矩阵用于参数处理以及梯度检验，以及将所有θ值初始化为在一个对称范围内的不同值的方法,最后介绍了神经网络从建立到运行的全部流程。  
本节的笔记最后介绍的从图片中读取数字并识别的功能挺有趣的。   

## Application of Neural Networks  

本节介绍了用神经网络实现自动驾驶汽车的一个小视频 

## Ex4  

个人认为这周的编程作业是4周以来最复杂最难的一周，向量的行列老是弄混，还要反复的增加减少行和列，我的做法是把每个矩阵或者向量的size都记录在草稿纸上，然后逐个比对，感觉这样不太容易弄混。  
下面是代码，由于基本都是在nnCostFunction里面弄的，所以把这个文件的代码一次性放上来了。

### nnCostFunction.m

	{%highlight ruby%}
    function [J grad] = nnCostFunction(nn_params, ...
                                       input_layer_size, ...
                                       hidden_layer_size, ...
                                       num_labels, ...
                                       X, y, lambda)
    %NNCOSTFUNCTION Implements the neural network cost function for a two layer
    %neural network which performs classification
    %   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
    %   X, y, lambda) computes the cost and gradient of the neural network. The
    %   parameters for the neural network are "unrolled" into the vector
    %   nn_params and need to be converted back into the weight matrices. 
    % 
    %   The returned parameter grad should be a "unrolled" vector of the
    %   partial derivatives of the neural network.
    %
    47856
    % Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
    % for our 2 layer neural network
    Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                     hidden_layer_size, (input_layer_size + 1));

    Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                     num_labels, (hidden_layer_size + 1));

    % Setup some useful variables
    m = size(X, 1);
             
    % You need to return the following variables correctly 
    J = 0;
    Theta1_grad = zeros(size(Theta1));
    Theta2_grad = zeros(size(Theta2));

    % ====================== YOUR CODE HERE ======================
    % Instructions: You should complete the code by working through the
    %               following parts.
    %
    % Part 1: Feedforward the neural network and return the cost in the
    %         variable J. After implementing Part 1, you can verify that your
    %         cost function computation is correct by verifying the cost
    %         computed in ex4.m
    %
    % Part 2: Implement the backpropagation algorithm to compute the gradients
    %         Theta1_grad and Theta2_grad. You should return the partial derivatives of
    %         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
    %         Theta2_grad, respectively. After implementing Part 2, you can check
    %         that your implementation is correct by running checkNNGradients
    %
    %         Note: The vector y passed into the function is a vector of labels
    %               containing values from 1..K. You need to map this vector into a 
    %               binary vector of 1's and 0's to be used with the neural network
    %               cost function.
    %
    %         Hint: We recommend implementing backpropagation using a for-loop
    %               over the training examples if you are implementing it for the 
    %               first time.
    %
    % Part 3: Implement regularization with the cost function and gradients.
    %
    %         Hint: You can implement this around the code for
    %               backpropagation. That is, you can compute the gradients for
    %               the regularization separately and then add them to Theta1_grad
    %               and Theta2_grad from Part 2.
    %

    a1 = [ones(m,1) X];

    z2 = a1 * Theta1';
    a2 = sigmoid(z2);
    a2 = [ones(size(a2,1),1) a2];

    z3 = a2 * Theta2';
    a3 = sigmoid(z3);
    hThetaX = a3;

    yVec = zeros(m,num_labels);
    for i = 1:m
      yVec(i,y(i)) = 1;
    endfor

      J = (1/m) * sum(sum(-yVec.*log(hThetaX)-(1-yVec).*log(1-hThetaX)));
      tmpTheta1 = Theta1(:,2:end);
      tmpTheta2 = Theta2(:,2:end);
      J = J + (lambda/(2*m)) * (sum(sum(tmpTheta1.^2))+sum(sum(tmpTheta2.^2)));

    for t =1:m
      a_1 = [1; X(t,:)'];
      z_2 = Theta1 * a_1;
      a_2 = [1;sigmoid(z_2)];
      z_3 = Theta2 * a_2;
      a_3 = sigmoid(z_3);
      y1 = ([1:num_labels]==y(t))';
      delta_3 = a_3-y1;
      delta_2 = (Theta2' * delta_3) .* [1;sigmoidGradient(z_2)];
      delta_2 = delta_2(2:end);
      Theta1_grad = Theta1_grad + delta_2 * a_1';
      Theta2_grad = Theta2_grad + delta_3 * a_2';  
    endfor

    Theta1_grad = Theta1_grad/m + (lambda/m)*[zeros(size(Theta1,1),1) Theta1(:,2:end)];
    Theta2_grad = Theta2_grad/m + (lambda/m)*[zeros(size(Theta2,1),1) Theta2(:,2:end)];

    % -------------------------------------------------------------

    % =========================================================================

    % Unroll gradients
    grad = [Theta1_grad(:) ; Theta2_grad(:)];


    end
	{%endhighlight%}
	
---		
### sigmoidGradient.m

	g = sigmoid(z).*(1-sigmoid(z));

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
