---
layout: post
title: "CS231n Chapter 8 - Deep Learning Software"
description: "Notes"
categories: [CS231n]
tags: [Python]
redirect_from:
  - /2019/08/07/
---

# CS231n Chapter 8 - Deep Learning Software      

## Introduction  

这节课我们主要研究一下深度学习所使用的软件和框架，包括CPU和GPU之间的区别，以及不同的框架之间的联系和异同。  

## CPU vs GPU  

这一部分更像是一节硬件课，这里Justin直接把他的机箱图片放了上来。CPU就是central processing unit中央处理器，它放置在风扇下面，只使用了一小部分空间。但是GPU不同，graphic processing unit图像处理器，俗称显卡，空间巨大，占据了机箱的很大一部分空间。那么对于显卡的介绍，首先要引入一场世纪大辩论：NVIDIA VS AMD,可能在打游戏和性价比方面两者各有优劣，但是在深度学习方面，NVIDIA有得天独厚的优势，可以说占据主导地位。  

接下来介绍了一下当前（2017）的顶级CPU和GPU，当然当时Titan和1070时代和现在RTX的天下已经有很大的不同了，不过相同的是GPU和CPU的核心区别是巨大的，CPU的核一般都在20以内，但是GPU的核心能够达到上千级别。核心的数量差距导致了计算性能存在巨大差距，此外，CPU和GPU的强项也有所不同，CPU适合进行具有复杂的计算步骤和复杂的数据依赖的任务，而GPU适合进行大规模的并行计算，而我们深度学习恰好需要大规模的并行简单计算，所以GPU更适合深度学习。  

要想进行GPU编程,我们需要学习一些GPU编程的语言或者框架，CUDA是一个NVIDIA平台的GPU编程语言，通过写类C语言的代码，可以直接在GPU上运行，此外CUDA还有一些高级API，比如cuDNN,cuFFT,cuBLAS等，但是值得一提的是CUDA代码非常复杂和困难，所以我们一般不会直接进行CUDA代码的编写，而是直接调用一些NVIDIA的官方包来直接使用。此外OpenCL是一个类似CUDA的支持多平台的GPU编译器，但是其速度偏慢。  

接下来就用一些主流的深层网络进行CPU和GPU速度的对比，显然这是全方位吊打，速度差距一般在60-70倍左右。值得注意的是，我们在用GPU训练的时候要注意，由于GPU的训练速度很快，所以很容易出现CPU和GPU之间的通信速度限制导致训练速度出现瓶颈，所以我们一般的做法是尽量将所有数据读在内存里，并尽量用固态硬盘来代替机械硬盘，此外用多CPU线程来预先获取训练数据。  

## Deep Learning Frameworks  

深度学习的框架在我看来，就和泼了大粪的庄稼，几天就出来一大堆，主流的框架也是一年一变，所以这里2017年的课程做的对比我感觉其实在现在看来意义不大，不过简单来讲，这两年pytorch和TensorFlow基本上占据了框架的主流，pytorch在近两年发展的越来越好，但是TensorFlow在2019年发布了2.0版本，配合高级框架keras，使用的人也越来越多。  

简单来讲，深度学习的框架作用有三点：方便的建立我们的大型计算图，简单的计算/更新梯度，在GPU上能够方便的运行。所谓的计算图，就类似于一个流程图，该流程图描述了具体的操作步骤和细节，然后我们可以用代码来实现这个计算图。其实我们完全可以用numpy完成前向传播的过程，但是numpy的局限性在于，无法进行反向传播，也无法进行GPU编程，所以我们需要用Tensorflow等框架来辅助我们完成这些操作。一般情况下，我们的操作就是自己完成前向传播和网络结构搭建，然后让框架来进行反向传播和训练预测。  

接下来以TensorFlow 1.x为例进行了一个两层神经网络的运算。这里2.0版本的TensorFlow已经丢弃了placeholder和session，所以学习的意义不大，我就不再纪录具体操作了。这里还介绍了一下Keras，Keras的语法和现在基本上是相同的，当时keras才刚刚崭露头角，现在已经成为TensorFlow不可或缺的一部分了。关于Tensorflow1.x的操作，可以参考我之前的MOOC Deeplearning by Udacity笔记，对于2.0版本的Tensorflow，可以参考我之前Tensorflow in practice系列MOOC的博客笔记。  

介绍完Tensorflow，接下来介绍pytorch，这也是我马上将要使用的深度学习框架。在pytorch中，有三个等级的抽象类，分别是tensor，等价于Tensorflow的numpy数组；variable，等价于TensorFlow的tensor，variable和placeholder；以及module，等价于一个神经网络层，储存有权重和状态。PyTorch的tensor和variable拥有完全相同的API，因此其代码可以无缝转换和衔接。在Pytorch中，一个非常重要的概念是AutoGrad自动求导机制，它是按运行方式定义的框架，即backprop的方式是按照代码的运行方式定义的。PyTorch中拥有和Keras类似的API nn，nn是一个PyTorch支持的模块Module，我们可以通过这个API来简单快速的构建我们的神经网络。我们以可以自己定义新的Module，然后应用我们自己的Model来训练模型。PyTorch还有自己的数据加载器DataLoaders，提供minibatch，shuffling和多线程服务，返回Tensor类型的返回值。torchvision可以让你使用一些预处理的数据和权重，visdom类似tensorboard，可以使整个编程过程可视化。PyTorch其实来源于Torch，Torch是用小巧的lua语言编译的，但是随着PyTorch的不断发展和Python的火爆，Pytorch基本上代替了Lua Torch。  

我们知道计算图是神经网络最为基础和概略的表现形式，但是计算图可以分为动态和静态计算图两种，Tensorflow 1.x版本默认使用的是静态计算图，我们需要实现确定好图的顺序，然后按照该顺序添加变量和数据进行计算。而PyTorch默认使用的是动态计算图，框架自动按照代码编写的顺序进行编译，那么这就有了更高的灵活性和便捷性，在我看来动态计算图比静态计算图更为简单便捷，而Tensorflow 1.x也有动态计算Eager Execution功能，并且在2.0版本中将其设置为默认方式，正式将Tensorflow也代入了动态计算图这一阵营中。  

最后介绍了一下Caffe框架，这是一个内核由C++编写的，拥有python和matlab集成的，有利于训练和调参的框架，在caffe中我们经常没有必要去写代码……我们只需要调用一些二进制文件，编辑一些配置文件，不过该框架在研究领域使用的已经不多了，而在模型部署中还有比较多的应用。在现在的2019，应用看起来是越来越少了- -。  Caffe的使用步骤的第一步，就是转换数据，最好是从LMDB或者HDF5之类的数据转换过来，之后我们需要定义我们的网络结构，在caffe中，我们需要在prototxt文件中定义这些，所以定义的文件在深层网络中可能会相当长，现在一些人甚至会用python来生成prototxt文件……之后我们还需要通过prototxt来定义我们的solver，定义一些常见的超参数，最后第四步就是进行训练了，那么这就是Caffe的一般使用流程。  

Caffe2是Caffe的进阶版，由于Caffe2在课程录制的一周前才发布……所以并没有什么细致的讲解，在2019年caffe2的应用似乎也就那样，我也就不在这里专门找材料了解一下了，以后需要用到的时候再学习好了。  

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
