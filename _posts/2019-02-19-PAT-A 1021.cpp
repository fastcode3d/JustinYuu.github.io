---
layout: post
title: "PAT-A 1021"
description: "code solutions"
categories: [PAT-A]
tags: [C++]
redirect_from:
  - /2019/02/19/
---
1021 Deepest Root （25 分）  

A graph which is connected and acyclic can be considered a tree. The hight of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

## Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤10^4) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
    
## Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print Error: K components where K is the number of connected components in the graph.

## Sample Input1:

	5
	1 2
	1 3
	1 4
	2 5
    
## Sample Output2:
    
	3
	4
	5
    
## Sample Input1:

	5
	1 3
	1 4
	2 5
	3 4
    
## Sample Output2:
    
	Error: 2 components  

## my own thoughts
 
Use BFS to calculate depth of each nodes, and choose the largest as the result.  
The time complex will be n square, since we need to calculate every node's depth.  
Here are the codes:
  
    {% highlight ruby %}
    #include <iostream>
	#include <vector>
	#include <algorithm>
	#include <queue>
	using namespace std;
	const int maxn=10010;
	vector<int> arc[maxn];
	bool vis[maxn];
	int N,depth[maxn],maxdepth=-1,layer[maxn];
	int BFS(int root){
		queue<int> q;
		fill(layer,layer+maxn,0);
		q.push(root);
		vis[root]=true;
		layer[root]=1;
		int tdepth=0,count=0;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			count++;
			int len=arc[t].size();
			tdepth=max(tdepth,layer[t]);
			for(int i=0;i<len;i++){
				if(vis[arc[t][i]]==false){
					q.push(arc[t][i]);
					layer[arc[t][i]]=layer[t]+1;
					vis[arc[t][i]]=true;
				}
			}
		}
		if(count<N) return -1;
		else return tdepth;
	}
	int calcomponent(int root){
		fill(vis,vis+maxn,0);
		int count=0;
		for(int i=1;i<=N;i++){
			if(vis[i]==false){
				BFS(i);
				count++;
			}
		}
		return count;
	}
	int main(){
		scanf("%d",&N);
		for(int i=1;i<N;i++){
			int v1,v2;
			scanf("%d%d",&v1,&v2);
			arc[v1].push_back(v2);
			arc[v2].push_back(v1);
		}
		for(int i=1;i<=N;i++){
			fill(vis,vis+maxn,0);
			depth[i]=BFS(i);
			if(depth[i]==-1){
				printf("Error: %d components",calcomponent(i));
				return 0;
			}
			maxdepth=max(depth[i],maxdepth);
		}
		for(int i=1;i<=N;i++){
			if(depth[i]==maxdepth){
				printf("%d\n",i);
			}
		}
		return 0;
	}
	{% endhighlight %}
---	
## reflection

This problem is as same as a algorithm question in the 2018 postgraduate entrance examination of Fudan University.I will skip the prove here but it is crystal clear that this method is right.  
Firstly choose a random node in the graph, and use DFS or BFS to find the farest node of it,and that farest node is one of the two end points of the deepest of longest path.Then, use DFS or BFS to find the farest node of this node, which is another end point of the deepest/farest path. And that path is the longest.  
It need to be cautious that there might be more than 1 longest path,which means we shoule output all nodes appearing in these pathes together. Besides, we need to judge if this graph is connected or not.Since the problem already tells us that there are n-1 edges and n nodes, so if the graph is connected, the graph must be a tree and acyclic.  

---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
