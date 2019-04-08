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
本周首先介绍的是一些调参技巧，参指的是超参数。吴恩达建议不要用网格划分的方式来寻找参数，这样虽然分的比较平均，但是代价很高，如果参数大于2，那么维度将会大大增加。吴恩达建议用从粗到细的选择方式，首先随机选取一些点，找出效果最好的一部分，然后在这一部分中选取更多的点，循环往复几次就可以将区域缩小到一个很小的范围。至于缩小范围的方式，吴恩达建议用Log来代替linear，在对数尺寸上随机的取样，这样可以将有限的资源合理分配。


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  
