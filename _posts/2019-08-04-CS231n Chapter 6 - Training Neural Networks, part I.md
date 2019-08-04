---
layout: post
title: "CS231n Chapter 6 - Training Neural Networks, part I"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/07/31/
---

# CS231n Chapter 6 - Training Neural Networks, part I    

## Introduction  

训练神经网络这一部分将会通过两部分组成，第一部分主要介绍一些激活函数、数据的预处理、权重初始化、批量归一化，以及维护学习的过程和超参数优化。  

## Activation Functions  

常用的激活函数其实就那么几种，再介绍一遍好了。首先就是sigmoid函数，σ(x) = 1/(1+e^(-x))，它将函数值维持在0到1之间。但是这个函数也有一些明确的缺点，比如说输入值过大或过小的时候梯度就会消失，从而不利于反向传播。此外，sigmoid的输出并不是以0为中心的，而是恒为正值，这将会导致w的梯度将会一直是恒正或者一直是恒负，这就会导致梯度更新的低效率，用图像表示出来可以发现它会出现锯齿形的晃动，较为繁琐。我的理解是恒正和恒负相当于限制了具体的更新方向，其实也不仅仅是恒正和恒负，而是恒为某一正值和某一负值，这就导致我们的梯度更新必定会在这两个方向上不断的更新，那么如果这两个方向都不是最优的方向，结果就是锯齿形的zig-zag下降。最后的一点小问题是sigmoid需要进行指数运算，这会导致运算的成本大大增加。  

接下来是tanh函数，这个函数的值域为\[-1,1],所以不会出现上述的那种问题，但是仍然会出现的问题是梯度消失的问题还没有被解决。  

正所谓大道至简，这么多复杂的激活函数没有解决的问题，就让一个小小的RELU来解决了，这货的右半部分压根就是一个线性函数，只是左半轴部分是0，但是它却有独特的优点，比如说右半部分的梯度不会消失，计算相当简单，实际计算中收敛速度极快，甚至更符合神经学原理……在我个人的认知上我还是不太懂为啥这个半线性函数是有用的，不过它就是有用的，anyway。  不过Relu也是有缺点的，比如不是0为中心的输出，以及一个dead ReLU的情况产生：当输入一直是负数或者0的时候，输出也将一直是0，那么这个ReLU函数将一直不会更新，这一部分我很感兴趣，这里是Quora上的一篇讨论，我把链接放到[这里](https://www.quora.com/What-is-the-dying-ReLU-problem-in-neural-networks)，那么这个问题可以用一个ReLU的改进方案Leaky-ReLU来代替，将负半轴的值用一个很小的负值来代替，即可避免这个问题。  

此外，还有另外一种ReLU叫做Parametric Rectifier,其公式是f(x) = max(αx,x)，负坐标的倾斜程度由参数α确定，该参数参与反向传播，这种ReLU简称PReLU。我们还有另一种ELU，负半轴为α(exp(x)-1)，这个ReLU的好处是对于一些噪音有更好的鲁棒性，以及结果更接近于0中心，但是其缺点是需要进行指数操作，从而导致计算负担增加。  

这里还介绍了一个称之为Maxout Neuron的max函数，公式为max(w1x+b1,w2x+b2)，这个函数实质上同时生成了leaky ReLU和ReLU，这个函数不会die，也不会饱和导致梯度消失，但是它用了double的参数，从而导致计算负担增加。  

总结一下，对于激活函数的选用，使用ReLU比较好，但是要注意学习率的选用，也可以使用ReLU的上述变种，如果可以的话也可以试试tanh，但是不要抱太大希望……最后，不要用sigmoid……  

## Data Preprocessing  

接下来是对数据的预处理，比较容易理解的就是均一化和零均值化。回到之前我们学到的那个zig-zag的例子，出现zig-zag的原因就是因为原数据均为正或者均为负，所以零均值化原数据显得格外重要，零均值化在吴恩达Machine Learning MOOC中也称作 feature scaling,具体方式是(原数值-平均值)/标准差，从而将所有的数据都限定在\[-1,1]这个区间内，并将均值设置为0。和其他机器学习方法相比，我们的图像处理领域数据预处理反而不太常用标准化以及更深的预处理，比如PCA。此外，对于训练数据和测试数据我们都需要做相同的预处理，从而保证两者的训练结果可比较。那么零均值化的过程中我们可以减去总的图像均值，比如AlexNet，也可以减去每个channel的均值，比如VGGNet。  

## Weight Initialization  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  