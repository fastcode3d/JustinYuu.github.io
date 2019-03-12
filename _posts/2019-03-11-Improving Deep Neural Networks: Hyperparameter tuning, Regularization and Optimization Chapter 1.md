---
layout: post
title: "Improving Deep Neural Networks: Hyperparameter tuning, Regularization and Optimization Chapter 1"
description: "Notes"
categories: [Neural-Networks-and-Deep-Learning]
tags: [Python]
redirect_from:
  - /2019/03/11/
---

# Improving Deep Neural Networks: Hyperparameter tuning, Regularization and Optimization Chapter 1  

集中刷了两个星期的题目，水平个人认为有了比较明显的长进，不过还是要继续练习。但是在刷OJ题目的同时，我认为也有必要继续学习一些深度学习的内容。  
deepmind的课程一共有五门课，Neural Networks and Deep Learning是这个系列的第一门课，Improving Deep Neural Networks: Hyperparameter tuning, Regularization and Optimization这门名字巨长无比的课是第二门。这门课程更短，一共有三周，争取用早点把它学习完毕。  
这一篇文章主要是记录第一节的笔记，记录的形式依旧和这个系列的上一门课程形式相同。由于我之前学过吴恩达的Machine-learning这门课程，所以我对于之前已经学过的知识点不会再进行详细的记录，而只是会进行简要的概括便略过。同时，我还会将课后练习的代码放在上面。  

## Setting up your Machine Learning Application    

这一章一共有三节，其中还有几个小节，我就以大节为单位记录笔记，将这一大节的知识点全都记录在这一标题下面。  、
这一节主要介绍如何为自己的机器学习应用做一些准备。首先介绍了训练集、交叉验证集（这个课程中也称之为开发集：dev set）、测试集的比例，一般的比例会在6:2:2，但是在训练规模相当庞大的情况下，训练集的比例也可以扩大。其次讲了可能存在的一些问题，例如用于机器学习的训练集和测试/交叉验证集不匹配的问题。这里吴恩达举了一个例子，例子是判断是不是猫这个问题时，训练集都是网上的一些分辨率高的图片，而测试集和交叉验证集却都是分辨率低的从手机中截取的图片，这就会造成两者性质上的不匹配（高分辨率高质量/低分辨率低质量），这就需要保证测试集和训练集的数据分布相同，从而避免出现这种情况。  

这一章的第二节介绍了方差和偏差的关系，这在machine-learning那门课上已经介绍的极为充分了，所以在这里就简要概括一下即可。  
高偏差指的是不管在训练集还是在测试集上误差都很大的情况，即欠拟合；相反，高方差指的是在训练集上误差很小，但是在测试集上误差很大，即过拟合。我们所需要的训练结果，无疑是低方差低偏差的结果。这里吴恩达教授还介绍了一种理想误差，也叫贝叶斯误差(Bayes error)，指的是理想情况下的最小误差，但这并不一定是现实中能达到的，可以理解为一个误差下限。  

最后，吴大大介绍了一个通用的流程，用来解决方差和偏差问题。首先，判断是否存在高偏差，如果是，尝试换一个更大的神经网络。接着，判断是否是高方差（放到交叉验证集中对比），如果是，那么就需要用一个既能够降低方差，又能够不增加偏差的方式来解决这个问题。这个方法就是**正则化**。  

## Regularing your neural network  

我一直很不解的一点就是，为什么要在这么晚才介绍正则化，要知道在machine-learning那门课程中，几乎是在一开始就引入了正则化，然后在接下来的不同模型中不断的进行正则化。在这门课中，用了一整章的知识来集中介绍强大的正则化及其用法和作用。  

这里把之前课程中学习正则化的笔记贴在这里[Machine-Learning第三章笔记](http://justin-yu.me/blog/2019/01/24/Machine-Learning-by-Andrew-Ng-Chapter-3/)
正则化分为L1正则化和L2正则化，区别主要是范数是1还是2，通常都是用L2正则化。正则化可以应用在逻辑回归、线性回归和神经网络等模型中，其形式基本为(λ/(2* m))* Σ||w||²，其中||w||即为w的范数2或者弗罗贝尼乌斯(F-)范数。  
接下来就是核心问题了：为什么正则化可以过拟合？这是一个在之前就困扰我的问题，并且一直没有完全弄懂。这里贴两篇我觉得不错的文章：[文章1](https://charlesliuyx.github.io/2017/10/03/%E3%80%90%E7%9B%B4%E8%A7%82%E8%AF%A6%E8%A7%A3%E3%80%91%E4%BB%80%E4%B9%88%E6%98%AF%E6%AD%A3%E5%88%99%E5%8C%96/),[文章2](https://www.cnblogs.com/alexanderkun/p/6922428.html)，其中文章1还将范数介绍的很详细，值得一看。  

用我自己的语言总结一下，核心就是，在L2正则化中，λ越大，w越小。而这是因为在w的更新时，w含λ的那一项的系数是负的，也就是说加入λ之后w的更新会减小的更快，即权重衰减。w越小，w进入激活函数后取值将会更靠近原点，这样变化会更小。如果λ非常大，那么w就会非常小，以至于进入激活函数后的值接近于0，这就使得隐藏层作用无限减小直至为0，用数学语言说就是作用相对线性。  

接下来介绍的是dropout正则化。之前的文章2中将L1,L2,dropout都囊括了进去，可以看一看。dropout的方式和其名字一样，将神经网络中的某些隐藏单元随机去掉，然后不断更新得到的权值。这在python中可以通过乘以一个布尔型数组来实现。这里提到了一种叫做inverted dropout的方式，我觉得以我自己的语言去解释，不如直接放一篇足够有说服力的文章来的实在、简单：[Analysis of Dropout-P.Galeone](https://pgaleone.eu/deep-learning/regularization/2017/01/10/anaysis-of-dropout/).

介绍了什么是dropout，接下来该讲为什么dropout管用了。由于每一个隐藏节点都有可能会被dropout,因此最终的权重结果不会依赖任何一个结点。接着设置一个称为“留存率（keep-prop）”的概念，这决定了有多少神经元将会被留下。显然，每层都有自己的留存率，我们也通常对每个不同的层设计不同的留存率。  
dropout在CV领域使用非常频繁，因为在CV领域经常会出现训练集不够导致过拟合的例子，而要记住dropout的作用正是为了避免过拟合，这也是为什么把这项技术归为正则化的原因。  

最后一节介绍了其他的正则化方法，比如将图片扭曲、旋转、缩放、变形等。虽然这看起来只是一些小的trick，但是实际上这是一种减少过拟合的方式，通过对同一种结果的数据进行多种不同形状的训练，从而使训练结果脱离掉对于一些过拟合性质的依赖。例如，旋转图片可以使神经网络摆脱对于角度的依赖，这相当于告诉计算机，不要试图通过判断是否是“正的”来判断最终的结果，从而达到消除过拟合的结果，其他的方式也是同理。  

## Setting up your optimization problem  

这章主要讲的是对数据的一些优化处理，首先就是数据的均一化，将所有数据全部均一化到相同尺寸，可以使不同组的数据更为均匀的分布。  
其次是梯度的爆炸和消失问题，名字听起来很吓人，但其实就是在深层神经网络中，梯度随着不断的递推而指数型增大或者缩小，从而达到很大或者很小的状态。这种状态下很难对结果进行分析和操作，因此我们需要尽量避免这种情况。解决这个问题的方法很多，吴大大举了一个例子，是用tanh函数时的一种初始化方法，叫做Xavier初始化，来自这篇文章[Understanding the difficulty of training deep feedforward neural networks])(http://proceedings.mlr.press/v9/glorot10a/glorot10a.pdf),还有类似的方法可以应用在ReLU和sigmoid函数上，其目的都是让初始权重有一个默认值，从而确保在这个默认值下不会出现激活值的饱和或者0的现象。  
接下来介绍了一种叫做梯度检验的方法，用来检查自己的梯度是否正确，方法就是微积分里学的取相邻两点求斜率（……），然后对于损失函数里的每一个θ都进行一次这个操作，从而获得一个向量θapprox，然后与自己得到的梯度θ相比。比较方法是测量两个矢量之差的欧氏距离，再除以两个矢量欧氏距离之和，如果结果小于1e-7，那么就说明得到的梯度是正确的。但是梯度检验只能在debug的时候使用，而不能在训练时用，这样会拖慢程序运行的速度。此外，进行dropout时不要进行梯度检验，因为dropout的时候不断的随机删除节点，所以很难计算J

## Programming Assignment  
本次编程作业分为三部分，分别来实现本章所讲的功能。 

### Initialization  
第一个编程作业主要实现不同的初始化权重会导致不同的结果，示例是进行红蓝点的分类，不同的初始化方式会导致不同的识别率。代码统一且简单，但是重点不是实现，而是体会到不同的初始化方式对结果产生的显著影响。    
以下是需要编写的代码部分：  
#### Zero Initialization  

	    parameters['W' + str(l)] = np.zeros((layers_dims[l],layers_dims[l-1]))
        parameters['b' + str(l)] = np.zeros((layers_dims[l],1))  
		
#### Random Initialization  

        parameters['W' + str(l)] = np.random.randn(layers_dims[l],layers_dims[l-1]) * 10
        parameters['b' + str(l)] = np.zeros((layers_dims[l],1))  
		
#### He Initialization  

        parameters['W' + str(l)] = np.random.randn(layers_dims[l],layers_dims[l-1])*np.sqrt(2/layers_dims[l-1])
        parameters['b' + str(l)] = np.zeros((layers_dims[l],1))  
		
### Regularization  
第二个编程作业是实现不同的正则化,主要是L2和dropout，代码也非常简单，主要是为了对正则化的效果和dropout在forward prob和back prop中的应用方式有了更清晰和直观的认识和感受，需要编写的代码如下：  

#### L2 Regularization  

`L2_regularization_cost = (lambd/(2*m)) * (np.sum(np.square(W1))+np.sum(np.square(W2))+np.sum(np.square(W3)))`  
`dW3 = 1./m * np.dot(dZ3, A2.T) + (lambd/m) * W3`  
`dW2 = 1./m * np.dot(dZ2, A1.T) + (lambd/m) * W2`  
`dW1 = 1./m * np.dot(dZ1, X.T) + (lambd/m) * W1`  

#### Dropout  

    D1 = np.random.rand(A1.shape[0],A1.shape[1]) 
    D1 = (D1 < keep_prob)   
    A1 = A1 * D1  
    A1 = A1 / keep_prob 
	
---

    D2 = np.random.rand(A2.shape[0],A2.shape[1])                                        
    D2 = (D2 < keep_prob)                                     
    A2 = A2 * D2     
    A2 = A2 / keep_prob  
	
---

	dA2 = dA2 * D2
	dA2 = dA2 / keep_prob
	
---

	dA1 = dA1 * D1 
	dA1 = dA1 / keep_prob

### Gradient Checking  
第三个编程作业毫无疑问是梯度检测的部分，作业分为1层和n层两种，这样可以循序渐进的完成单个数字到向量的梯度检测学习，以下是需要自行完成的代码部分。  

#### 1-dimensional gradient checking  

` J = theta * x`  
`dtheta = x`

---

    thetaplus = theta + epsilon                               # Step 1
    thetaminus = theta - epsilon                              # Step 2
    J_plus =  thetaplus * x                             # Step 3
    J_minus = thetaminus * x                                 # Step 4
    gradapprox = (J_plus - J_minus)/(2*epsilon)                              # Step 5

    grad = backward_propagation(x,theta)
    
    numerator = np.linalg.norm(grad-gradapprox)                               # Step 1'
    denominator = np.linalg.norm(grad)+np.linalg.norm(gradapprox)                             # Step 2'
    difference = numerator/denominator  

#### n-dimensional gradient checking  

	thetaplus = np.copy(parameters_values)                                      # Step 1
	thetaplus[i][0] = thetaplus[i][0]+epsilon                                # Step 2
	J_plus[i], _ = forward_propagation_n(X,Y,vector_to_dictionary(thetaplus))  #Step 3

	thetaminus = np.copy(parameters_values)                                     # Step 1
	thetaminus[i][0] = thetaminus[i][0]-epsilon                               # Step 2        
	J_minus[i], _ = forward_propagation_n(X,Y,vector_to_dictionary(thetaminus)) # Step 3

	gradapprox[i] = (J_plus[i] - J_minus[i])/(2*epsilon)

	numerator = np.linalg.norm(grad-gradapprox)               # Step 1'
	denominator = np.linalg.norm(grad)+np.linalg.norm(gradapprox)  # Step 2'
	difference = numerator/denominator  
至此本周所有的代码部分已经完成完毕。  
## Heroes of Deep Learning  
我很高兴的发现这个系列的上一门课程中的这个环节被保留了下来，在这个环节中，吴恩达会采访一位深度学习的大牛，大牛分享他们的故事，并对初学者给出他们自己的建议，我觉得这是接触到深度学习领域很多著名专家的很好的途径。此外，通过这个环节，加上我自己google一些相关资料，可以让我对这一领域的一些里程碑性的进展有更深的了解。  
本节要采访的大牛是Yoshua Bengio，随着我对深度学习的逐渐入门，我也开始了解了这一领域的一系列专家，Yoshua Bengio就是一位我经常在论文和博客文章中看到的大牛，本章的采访就是采访他。  
Yoshua从1985年就接触了深度学习，可以说是非常早了，在当时普遍研究专家系统的时代，他发现了一条研究人脑的新道路，并阅读了Hinton的论文，做了一系列神经网络的研究。接下来，作为神经网络的专家，Yoshua讲了神经网络的演进史，并分享了自己在开发神经网络时犯的错误，他认为ReLU的表现会比sigmoid很差，在零导数时会更容易过饱和，但是后来事实证明ReLU的效果更好。然后Yoshua说了一些以我的水平无法理解的东西，我捕捉到的名词是“维数灾难”、“长期依赖”、“学习词向量”，以及“栈式的自编码器”、“栈式的RBM”……除此之外我能听懂的是ReLU和GAN，这是他最骄傲的成果之一。  
接下来谈到了大脑和深度神经网络的关系。众所周知吴恩达在上次课程的最后总结中提到过，大脑和神经网络并没有什么关系，但是Yoshua似乎有着不同的见解，他似乎认为大脑也会做类似反向传播的事情，但是又解释不太清楚，讲的相当抽象，我也很难理解。  
接下来是Yoshua对于无监督学习的看法，在这方面，他与Andrew的意见似乎非常相似，都认为无监督学习非常重要，但我发现他对于一些东西的解释非常抽象化，比如quote一句“构建一个心灵的建构，通过观察来解释世界的工作方式”，“与世界互动，理解世界”等等，再后来的东西就更加抽象了，总结来说他打算用神经网络和深度学习来理解“更高层次的抽象”，也就是在抽象之上的抽象，通过对目前所采用的研究方法的深入研究，将可研究的问题不断的扩大。目前可能只能研究一些简单的“玩具问题”，但后来就可以研究更为复杂更为困难的问题，就像“分治法”。  
最后是建议部分。Yoshua认为，对于研究和开发两种不同的类型，所做的事情是不同的，但是共同需要的是多读书和多编程。此外，在使用软件或者库时，不能浮于表面，要深层次的了解底层的原理，甚至建议从底层的基本原理来重新建立一次，从而达到更深的理解。  
此外，Yoshua给了读论文的建议，只要阅读最近几期的ICLR汇刊，就能够接触到很多好论文，并真正的了解这个领域。Yoshua还建议大家学习数学，并且不要害怕数学，“其实没那么难”。并不需要长年累月的学习就可以了解机器学习中所需要的数学知识，Yoshua认为真正了解只需要六个月的微积分、线代、概率论、优化的学习。  

这样第一周的内容就学习完毕了，这一章的内容说多也不多，但说少也真不少，用了我6-7个小时才全部学习完毕，我们第二周见啦。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
