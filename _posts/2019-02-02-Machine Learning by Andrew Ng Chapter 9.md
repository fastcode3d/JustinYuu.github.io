---
layout: post
title: "Machine Learning by Andrew Ng Chapter 9"
description: "Notes"
categories: [Machine-Learning-by-Andrew-Ng]
tags: [Octave]
redirect_from:
  - /2019/02/02/
---
# Machine Learning by Andrew Ng Chapter 9
 
## 前言  
本章主要介绍异常检测。[第九章笔记](https://www.coursera.org/learn/machine-learning/resources/szFCa)。从课时数来看这一章貌似内容比较多。  

## Density Estimation  
本章先介绍了一些数学基础，例如高斯分布的公式和图像，这在大学的概率论课程中都有所涉及。然后简要介绍了异常检测的算法，算法内容分为3步：1.选择特征x。2.计算平均值和方差。3.计算每项高斯分布的乘积，然后将结果与度量的单位ε比较确定是否异常。  

## Building an Anomaly Detection System  
本章从细节上来介绍异常检测算法，具体的步骤给我的感觉和监督学习十分相似，通过p和ε的比较来得出是否异常，ε的大小通过交叉验证集来确定，和监督学习一样，异常检测同样要用到训练集，交叉验证集和测试集。同样，由于数据偏斜太大，因此不能用准确率来评判，而是应该用之前提到的Precision/recall来判别。第二节就用一节的篇幅啦区分了异常检测算法和监督学习的区别。  
在我理解看来，异常检测算法和监督学习的最大区别是可供学习的方向不同，举例来说，如果你要检测异常，但是只有大量的正样本可供学习，仅有少量的负样本，即有异常的样本可供异常检测算法学习，那么问题在于如果采用异常检测算法学习，那么可供学习的样本很少，学习效果会很差。同样，反过来讲，如果要监督学习，但是数据集只有大量的负样本和少量的正样本，那么同样可供学习的样本很少，学习效果会很差。因此总结一下，如果正样本数量多、负样本数量少或者正负样本都很多，那么可以用监督学习中的逻辑回归或者神经网络来进行，而若果负样本数量远远大于正样本，那么推荐使用异常检测算法。  

## Multivariate Gaussian Distribution  
本节介绍了异常检测的一种延伸——多元高斯分布。多元高斯分布的公式在官方笔记中有给出，公式中含有两个参数μ（平均值）和Σ（协方差矩阵），根据参数的大小不同多元高斯分布的图像也有很大的不同，Σ改变的是图像的陡峭程度和z轴方向，而μ改变的是分布的中心点（x轴y轴坐标）。多元高斯分布可以自动捕捉特征之间的相关性。   
多元高斯分布适合应用在数据集比特征数量大很多的情况下，而在特征数量大于或约等于数据集数量的时候还是应用普通高斯分布更好。  

## Predicting Movie Ratings  
这一部分的三章应该主要介绍的是推荐系统，本章主要介绍电影评分的预测以及推荐用户相关的电影。  
这一节讲了θ的来源和计算方式，以及整个流程中涉及的公式和计算，以及如何将评分预测与线性回归方程和梯度下降算法联系在一起的，即公式的推导。简单来讲，θx是用户的预测评分，而y是用户的实际评分，θx-y即差值，之后的代价函数公式和梯度下降算法的公式都和线性回归基本一样，再加上正则化即可。我感觉推荐系统本质上来说就是一种监督学习，而theta值是用户的特征向量。如果要求所有用户的θ值，只需要在公式中再加一部分使所有的用户都被计算一遍即可。具体公式在官方笔记中的这一节中有给出。     

## Collaborative Filtering  
这一节主要讲协同过滤。通过协同过滤得到每部电影与各个特点的相关程度。用数学语言来讲，是通过θj和用户对电影的评分反推出x。  
x的值的求法和θ是基本一样的，两种公式见下图：  
![9-1.png](/images/9-1.png)  
不同之处在于在上一节中求θ是通过将x带入方程中通过梯度下降或者其他优化函数不断的最小化θ，而这里是将用户提供的θ带入公式中，通过梯度下降或者其他优化函数不断的最小化x。  
那既然通过给定的θ可以得到x，也可以通过给定的x得到θ，那么究竟先给θ还是先给x呢？吴恩达很幽默的将其比喻成了先有鸡还是先有蛋的问题，并给出了他的回答:"You can also randomly guess the values for theta to guess the features repeatedly. You will actually converge to a good set of features."   
此外，还有一个公式将这两个合为一体，在官方笔记的Collaborative Filtering Algorithm这一节中有详细介绍。要注意的是正则化要同时正则x和θ两项。  
最后总结一下协同过滤的全部步骤：1.随机初始化θ和x向量。2.通过梯度下降或者其他算法来最小化代价函数。  

## Low Rank Matrix Factorization  
考虑到很多同学们没有线性代数基础，本节大体上讲了一下预测评分矩阵的分解，即将矩阵分解成θ向量和x向量，这也就是协同过滤算法的向量化实现。  
在实际应用中，给到电影i和j，通过电影i学习特征x1,x2,...,xn，然后计算电影j和i的最小差值从而得出电影i，j的相似程度。  
此外还介绍了一个预处理步骤：均值均一化。通过这个方法使得未知特征的预测值为电影的平均得分而不是0。  

## Anomaly Detection and Recommender Systems  
本节的内容是对一个网络中故障的服务器进行监测和使用协同过滤来实现一个电影推荐评分系统。一共要完成三个文件的代码，代码如下:  

### estimateGaussian.m  

    mu = (1/m) * sum(X); 
    sigma2 = (1/m)*sum((X - repmat(mu,m,1)).^2);  

### selectThresold.m  

    cvPredictions = (pval<epsilon);
    fp = sum((cvPredictions==1)&(yval==0));
    tp = sum((cvPredictions==1)&(yval==1));
    fn = sum((cvPredictions==0)&(yval==1));
    prec = tp/(tp+fp);
    rec = tp/(tp+fn);
    F1 = (2*prec*rec)/(prec+rec);

### cofiCostFunc.m  

	J = 0.5 * sum(((X * Theta' - Y).^2)(R == 1)) + (lambda/2)*sum(sum(Theta.^2))+(lambda/2)*sum(sum(X.^2));
	X_grad = (X * Theta' - Y) .* R * Theta + lambda*X;
	Theta_grad = ((X * Theta' - Y).* R)' * X + lambda*Theta;

---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。
