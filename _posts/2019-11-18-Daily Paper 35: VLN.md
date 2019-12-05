---
layout: post
title: "Daily Paper 35: VLN"
description: "Notes"
categories: [MMML-VLN]
tags: [Paper]
redirect_from:
  - /2019/11/18/
---

# Daily Paper 35 - Vision-and-Language Navigation: Interpreting visually-grounded navigation instructions in real environments  

## Introduction  

这篇paper是VLN的开山之作，看这篇paper主要是想看一下VLN的基准baseline方法以及数据集的形式。这篇paper应该和另一篇提出Matterport3D Simulator的文章一并阅读，因为Matterport3D Simulator是作者实现VLN任务的工具，今天先看这篇。  

作者使用Matterport 3D Simulator——一个基于真实图像的大规模强化学习环境来完成了对真实场景的模拟，提出了视频-语言导航任务并提供了第一个现实场景下的VLN数据集——the Room-to-Room(R2R)dataset。  

VLN问题就不过多赘述了，简单来讲就是给定一串自然语言指令和一个未曾见过的环境，agent将会尝试着根据给定的自然语言指令进行导航，直至最终的目标位置。那么很显然，这个任务和机器人有着千丝万缕的联系，不过让机器人在真实环境下进行操作和导航成本实在是太大了，所以作者就想了一种模拟的替代方法来进行实验和训练。具体来讲，就是使用Matterport3D Simulator进行模拟化，该模拟器是一个大规模的可交互强化学习环境，从Matterport 3D数据集中建立。该数据集是一个含有10800个密集采样的全景RGB-D图像，包含了90个真实世界中的建筑规模的室内环境。和人工合成的RL环境相比，真实世界图像的使用保存了视觉和语言的丰富性，最大化了训练的agent转移到真实世界应用的潜能（增强可移植性）。基于Matterport3D环境，作者收集了21567个平均长度为29词的导航指令，组成了一个Room-to-Room数据集，每一个指令都描述了一个穿越多个房间的轨迹。  

总体来说作者的贡献有3点：提供了Matterport3D Simulator，提供了Room-to-Room dataset，以及应用一个seq2seq模型来建立了一些baseline。  

## Related Work  

一般来说提出一个新任务的Related Work还是比较重要的，因为你提出一个新任务一定要有新的理由。例如这里的语音-视觉导航，和普通的机器人导航问题有什么区别呢？这里作者给出了解释：传统的机器人导航任务中，视频的语义没有那么丰富，一般是将所有可能遇到的导航参照物全部列出来进行标注，或者干脆在一个视觉限制的环境下进行训练和使用，这只需要有限的感知即可做到，那么这种导航的问题在于无法适应复杂多变的真实场景。VLN任务的优势在于通过加入对视觉的语义分析，使得agent可以有效的识别未接触的场景和物体，这更符合在真实场景下的应用。  

此外作者还阐述了VLN和VQA的异同，VLN和VQA都是visually grounded seq2seq transcoding问题，但是VQA并不会使摄像机的视角和位置移动，相较起来也序列也更短。  

## Matterport3D Simulator  

首先介绍Matterport3D Simulator，之前说过该模拟器基于Matterport3D数据集，那么首先介绍一下这个数据集。Matterport3D数据集是一个包含全景视角的当前最大可用的RGB-D研究数据集，含有从90个建筑物级的场景的194400个RGB-D图像中建立的10800个全景视角。每一个全景视角都由一个和人类高度相似的3D位置下的18个RGB-D图像组成。  

比较困难的是Simulator，作者定义了一个embodied agent，给定位置v，朝向可以取任意值，相机的高度在上下90°之间，完全模拟人类的视角。在每一个时间步t，模拟器输出一个第一视角照相机下的RGB观察图像。但是问题在于这个图像不是可直接获得的，因为agent本身是虚拟化的，所以我们需要找到该位置下的第一人称图像，这就需要通过各个视角下的预计算立方体映射的图像的特征投影来得到。  

Simulator中最大的挑战是如何让agent确定状态依赖的动作空间，用人话来表示就是说怎么样让agent学会自己不可以飞檐走壁穿过墙壁，以及不进入那些无法导航的区域。这也相当于制定一个游戏规则，与其规定agent不能走哪些路径，不如直接规定可以走哪些路径，无允许皆为禁止，这样就可以提高其鲁棒性，那么在时间步t，模拟器会同时生成一系列下一步可以达到的视角，在下一个时间步模拟器就会位移到该视角下，调整自身的摄像头朝向和角度。  

为了确定接下来的选择集，simulator在每一个场景下都会包含一个全景视角的加权无环图，G=<V,E>，V代表整个场景下位置v可取的所有值，图的边表示agent能够进行位移的路径，边的权重代表该条路径的距离。作者通过在Matterport3D场景网格下的视角之间进行光线追踪来检测障碍，从而建立该加权无环图。此外将长度大于5m的边去掉，从而保证运动本身本地化。检测完毕后作者还手动确认了每一个导航图内部没有没有检测到的障碍，比如窗户和镜子等。那么给定一个导航图G，下一个时间步的位置只能是当前时间步的位置（保持不动），或者其他位置中与当前位置联通且在一定距离内的位置。这种方式给我的感觉像是DFS和BFS，又像是Dijkstra和SFPA。  

在Matterport3D中，每一个图都包含了117个视角点，顶点的平均度是4.1。用图的方式来进行导航，标志着整个位置的选择都是离散化的，这也是降低复杂度和提高可行性的无奈之举，正如作者所说，就算是真实场景的机器人也无法完全线性的实时规划路径。整个模拟器并没有定义或者放置任何形式的约束，该RL环境是完全独立于任务和数据集之外的独立环境。  

Matterport3D Simulator是用OpenGL和C++写的，此外还提供Python接口，可以被Caffe、TensorFlow等深度学习框架和ParlAI、OpenAI Gym等强化学习平台所调用。此外作者还开发了一个基于浏览器的独立于simulator之外的可视化库WebGL，该库使用Amazon Mechanical Turk收集导航路径的语言标注，以供其他研究者使用。  

作者还很诚实的介绍了该数据集和模拟器的bias，首先所有的空间都相当整洁，一般来说building内部都比较奢华……其次数据集里面的人和动物很少，这可能和其他以人和动物作为主体的数据集有很大的不同。最后作者发现一些捕获偏差，因为选定的视点通常可以提供环境的命令性视图，比如站在高处俯瞰整个房间，因此机器人不一定非要位于发现自己的位置。作者认为可以通过使simulator收集更多的building scans来缓解这一问题。  

## Room-to-Room Navigation  

接下来介绍R2R数据集，R2R数据集是服务于R2R任务而产生的，R2R任务是指让一个embodied agent跟随自然语言指令，从Matterport3D Simulator的一个起始点走到目标点。一般情况下，在每一轮的一开始，agent都会得到一个自然语言指令序列x作为input，agent在起始点能够获得一个初始的RGB图像o<sub>0</sub>，该图像是由agent的初始位置、朝向和视角高度三者组成的tuple s<sub>0</sub> = <v<sub>0</sub>,φ<sub>0</sub>,θ<sub>0</sub>>决定的。之后agent每做出一个决定，都会更新一个新的pose，也就是一个新的tuple s<sub>t+1</sub>，从而决定一个新的观察图像o<sub>t+1</sub>。这里要注意的是每一步获得的图像都是第一视角的，而不是Matterport3D里面的全景图像。当agent选择了stop操作的时候一轮结束，这时候可以判定agent是否找到了最终的目的地。  

接下来说明一下数据的选择。作者选择Matterport3D场景中不同房间的地点作为起始和终点位置，然后通过导航图G找到最短的路径。找到一大堆路径之后，删除掉总长度小于5的路径和四条边以内或者六条边以外的路径，这样保证了整体的路径不太短也不太长，难度都处于适中且相似的位置。作者最终取样了7189个路径，平均长度是10m。对于每个路径，作者使用AMT收集了三个相关联的导航指令，让AMT劳工通过作者开发的3D WebGL来熟悉轨迹并编写指令。作者只选择美国的有经验劳工，该任务由400个劳工标注了1600个小时完成。  

最后说一下评价指标。VLN任务的特性决定了是否导航成功可以非常明显和方便的判别。作者设置了一个阈值3m，当终点在3m以内的时候可视为导航成功。此外作者为了将是否在终点处停下作为一种量化指标，新建了一种新的评价方式，只有agent在轨迹中距离目标点最近的位置停下且距离小于3m才可视为成功。此外作者还计算了路径的长度作为评价指标之一。  

作者的数据集区分方式和Matterport3D数据集一样，采取了标准的训练集/验证集/测试集的划分策略，测试集有18个场景下的4173个指令，测试集分为两种，一个是11场景2349指令的val unseen，另一种val seen有1020个指令，场景数和训练集合在一起，为61场景，训练集有14025指令。测试集不公开发表，用于Leaderboard的性能排序。  

## VLN Agents  

最后就是作者的baseline了，由于作者的baseline在现在已经被秒成渣渣，所以简单看一下就好。  

作者使用一个基于LSTM的带有注意力机制的seq2seq架构，每一个时间步t，decoder都将当前图像o<sub>t</sub>的图像表示和前一个动作a<sub>t-1</sub>作为输入，并在语言encoder的隐藏层中应用注意力机制，预测下一个动作a<sub>t</sub>。语言指令通过LSTM encoder处理为词嵌入，在注意力机制中使用。作者使用ImageNet上预训练的ResNet-152作为图像特征提取器，此外上一个时间步的动作也类似词语embedding一样，获得一个动作embedding，和编码的图像concat在一起形成一个单独的向量q<sub>t</sub>，decoder LSTM的整体操作公式为h'<sub>t</sub> = LSTM<sub>dec</sub>(q<sub>t</sub>,h'<sub>t-1</sub>)。  

作者还使用了注意力机制来寻找当前时间步下最相关的导航指令，这是通过使用全局的general alignment函数实现的，这里只是使用了语言的注意力机制，并没有使用视觉注意力机制。  

在训练的过程中作者使用了两种训练策略：teacher-forcing和student-forcing，两者都使用了交叉熵损失作为损失函数，并最大化给定状态-行动对序列下ground-truth目标行动的似然，ground-truth一般是agent当前位置距离目标地点最短路径序列的下一个动作。在teacher-forcing方法下，在训练过程中的每一个时间步下ground-truth行动都会被选择以作为下一个输出预测值，但是这会导致agent只会得到最短路径下的action，不利于agent更好的探索，这有可能进一步导致训练和测试之间输入分布的改变。为了强调这个限制，作者对比了student-forcing，该方法每一个时间步的下一个动作都从agent的输出分布中采样。  

作者还添加了两个额外的baseline，一个是人类表现，一个是learning-free。learning-free又分为两种，一个是random，agent每次都随机选取自己的朝向进行前进，一共前进5次，而shortest-path每次都选择最短的路径。也就是说第一种是随机状态，第二种是理想状态。  

最后的结果是student-forcing方法的泛化性能更好，在测试集的表现也更好，具体的表现为总长度8.13m，导航错误距离7.85m，SR20.4%，oracle SR 26.6%。在我当前阅读的2019年11月18日，VLN Leaderboard的第一名Self-Supervised Auxiliary Reasoning Tasks (Beam Search)已经能达到71%的SR，Self-Supervised Auxiliary Reasoning Tasks（无Beam Search版本）能够在68%SR的同时达到10.43的总距离，可以说和一开始的差距相当大了。  


---
本博客支持disqus实时评论功能，如有错误或者建议，欢迎在下方评论区提出，共同探讨。  