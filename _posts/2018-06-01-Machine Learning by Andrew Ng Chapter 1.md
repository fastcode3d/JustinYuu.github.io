---
layout: post
title: "Machine Learning by Andrew Ng Chapter 1"
description: "Forewords."
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2018/06/01/
---
# Machine Learning by Andrew Ng Chapter 1

  第一周主要是导论以及需要的数学知识的回顾，内容量还是比较大的
  
## Introduction

  第一节为概论，主要解释机器学习的基本概念，以及监督学习和非监督学习的基本定义。  

### 何为机器学习

  Machine Learning is field of study that gives computers the ability to learn without being explicitly programmed.

### 监督学习（Supervised learning）

  数据集中的每个样本有相应的“正确答案”（训练集），根据这些样本做出预测，分有两类：回归问题和分类问题

  （1）回归问题：预测房价，根据样本集拟合出一条连续曲线

  （2）分类问题：根据肿瘤的大小来判断是恶性还是良性，得到一系列离散的结果。

  对于真正的学习问题，会用到无数的属性、特征和线索进行预测，而不只是上述的一个或者几个特征。
  
### 无监督学习（Unsupervised learning）

  无监督学习会将不同的数据分为几个聚类，然后进行聚类分析，此为聚类算法
  
  Cocktail party problem：在一个小的房间里，进行着一个小型的鸡尾酒聚会，假设只有两个人在发言，分别由两个麦克风放大其音量，A的声音也许在第一个麦克风的声音里会大一点，B的声音在第二个麦克风会大一点，在每个麦克风中都有重叠的部分所在。而所谓的“鸡尾酒会算法”便是找出其中蕴藏的分类，并分出两个重叠在一起的音频源（Holy high）
  
  事实上实现这个功能只需要一行代码，即 [W,s,v] = svd((repmat(sum(x.\*x,1),size(x,1),1).\*x)\*x');

  此课程中的算法均是通过Octave实现，同样也可以通过matlab实现。Octave的运行速度、编译量和学习速度将会远远快于Java和C++等主流编程语言。
  
## Model and Cost Function

  本节主要通过一个计算房价的模型来介绍线性回归分析的基本内容。

### Model Representation

  线性回归的最显而易见的应用便是监督学习中的回归分析和分类离散分析。用训练集里的数据喂给学习算法，从而得出一个hypothesis（假说），然后h(hypothesis)通过输入的x值得出最终的值，可以将h理解为一个x到y的映射。例如在求房价的算法中，输入房屋面积x,得出期望值。
  
  这个模型被称为线性回归(linear regression)模型，上述例子是关于单变量x的线性回归。
  
### Cost Function

  本节主要介绍如何将数据与映射h相拟合。在本例中，h<sub>θ</sub>(x)=θ<sub>0</sub>+θ<sub>1</sub>x。
  
  因此我们需要选择合适的θ<sub>0</sub>和θ<sub>1</sub>来使得h<sub>θ</sub>(x)更接近y，从而达到拟合的目的。用数学语言描述，即使h<sub>θ</sub>(x)-y的值最小，用平均误差平方和来表示，即(h<sub>θ</sub>(x<sup>i</sup>)-y<sup>i</sup>)<sup>2</sup>的和，此代价函数也被称为平方误差函数，有时也被称为平方误差代价函数。
  
 ![Cost Function](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/R2YF5Lj3EeajLxLfjQiSjg_110c901f58043f995a35b31431935290_Screen-Shot-2016-12-02-at-5.23.31-PM.png?expiry=1527984000000&hmac=EV3ub54ksxfh10WoGmfjLodS_tim7ONyvjXx3gbomS0)

### Cost Function -Intuition I

  本节主要介绍如何将上节的J(θ<sub>1</sub>,θ<sub>2</sub>)最小化，在这节中我们将θ<sub>0</sub>设为0，即J函数只是J(θ<sub>1</sub>)，即只与θ<sub>1</sub>有关的函数。选择合适的方程y=h<sub>θ</sub>(x)，从而使h(x)-y为0，进而使J(θ)接近0。
  
  通过取不同的θ<sub>1</sub>，可以作J(θ<sub>1</sub>)-θ<sub>1</sub>曲线，从而得出θ<sub>1</sub>为何值时更适合J函数，从而使J(θ<sub>1</sub>)最小，从而优化得到最佳拟合直线，即y=θ<sub>1</sub>x。这就是如何通过最小化J(θ<sub>1</sub>)来选择合适的函数曲线的示例，也是J的意义所在。  
  
![Cost FunctionI](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/_B8TJZtREea33w76dwnDIg_3e3d4433e32478f8df446d0b6da26c27_Screenshot-2016-10-26-00.57.56.png?expiry=1527984000000&hmac=aE_ypu_zSXpQ47ytjp-h1cern8aiejLb-oHQaulXPDI)

### Cost Function -Intuition II

  本节将会进一步介绍回归分析，将会用到轮廓图(Contour figure)的相关知识，需要提前补充相关知识。本节所用的4个重要公式还是之前提及到的4个：假设h，参数θ，代价函数J以及优化目标Goal，不过与上节不同的是，θ<sub>2</sub>将不为0，以便更好的可视化。
  
  做一个J-θ<sub>1</sub>-θ<sub>0</sub>的三维（弓形）曲面图，通过改变θ<sub>1</sub>，θ<sub>0</sub>的值来改变曲面图的结构。然后作出轮廓图，每一圈轮廓上的点都是J相同的时候的θ<sub>1</sub>、θ<sub>0</sub>的取值，从而更加直观的观察J(θ)的取值。
  
  而我们的算法致力于主动寻找合适的θ<sub>1</sub>和θ<sub>0</sub>，从而自动最小化J(θ<sub>0</sub>,θ<sub>1</sub>)，这将在接下来的视频中介绍。  
![Cost FunctionII](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/N2oKYp2wEeaVChLw2Vaaug_d4d1c5b1c90578b32a6672e3b7e4b3a4_Screenshot-2016-10-29-01.14.37.png?expiry=1527984000000&hmac=1cU2NZl35dcAJEI0fyJrngzp4vti1bjwm8z6pO-msYo)

## Parameter Learning

### Gradient Descent

  本节主要介绍梯度下降算法，该算法可用于线性回归分析和很多机器学习领域。本节将用梯度下降算法来解决J函数的最小化问题。
  
  具体实现思想是：预先选取θ<sub>1</sub>、θ<sub>0</sub>的取值，我们一般均取为0，然后一直改变θ<sub>1</sub>、θ<sub>0</sub>的取值，不断的减小J函数的值，直到J函数降到最小。  
  用此算法取得新值，新的值便是新的θ<sub>1</sub>、θ<sub>0</sub>，而更新时要注意同步更新，在θ<sub>1</sub>、θ<sub>0</sub>均更新后再进行下一步赋值，从而实现在梯度下降中的进一步更新。  
![Gradient Descent]
(https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/yr-D1aDMEeai9RKvXdDYag_627e5ab52d5ff941c0fcc741c2b162a0_Screenshot-2016-11-02-00.19.56.png?expiry=1528156800000&hmac=KFESK7fOGrYobc6YNvBzl4R2McwS4INS1LzTLem965o)

  不同起始点的梯度算法得到的结果截然不同，即使差距很小，梯度下降算法的每一步也会产生不同的结果。

### Gradient Descent Intuition

  梯度下降算法的主要内容为：重复，直到收敛(repeat until convergence)，重复的公式为θ<sub>j</sub>:=θ<sub>j</sub>-α∂J(θ<sub>0</sub>,θ<sub>1</sub>)/∂<sub>j</sub>,其中j的取值为0和1。
  
  在上面的公式中，α被称为学习速率，它决定了我们以多大的幅度来更新参数θ<sub>j</sub>，后面是导数项，随着J的增加或者降低而取正值/负值。学习速率影响了代价函数的梯度下降速率，α值过小有可能导致收敛的速度过慢，而α的值过大有可能导致无法收敛，甚至导致发散，因此需要选择合适大小的学习速率。
  
![Gradient Descent Intuition1](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/UJpiD6GWEeai9RKvXdDYag_3c3ad6625a2a4ec8456f421a2f4daf2e_Screenshot-2016-11-03-00.05.27.png?expiry=1528156800000&hmac=FvvbAcd5rNBmgju6QEKdxcOeePfLOjvi0FvDuAIZd5E)
  
  最后θ<sub>1</sub>总会停留在局部最优点上，即斜率为0的点，因为此时根据梯度下降算法，θ<sub>1</sub>在斜率为0的地方始终不变。同时，由于J的导数不断变小，因此就没有必要实时改变α。
  
  本节主要介绍了最简单的导数数学问题，可能是为了使未接触过导数概念的同学更好理解该算法公式的真正作用。

### Gradient Descent For Linear Regression

  将代价函数和梯度下降算法结合运用，从而得出最终的梯度下降法进行线性拟合的回归模型。本节将会将梯度下降算法实际应用到最小化平方误差代价函数的模型上。
  
  将最小化平方误差代价函数和梯度下降算法的公式合到一起，将偏导数项用最小平方和函数表示，得到公式
  
$$
\begin{align*} \text{repeat until convergence: } \lbrace & \newline \theta_0 := & \theta_0 - \alpha \frac{1}{m} \sum\limits_{i=1}^{m}(h_\theta(x_{i}) - y_{i}) \newline \theta_1 := & \theta_1 - \alpha \frac{1}{m} \sum\limits_{i=1}^{m}\left((h_\theta(x_{i}) - y_{i}) x_{i}\right) \newline \rbrace& \end{align*}
$$  



---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
