---
layout: post
title: "PAT-A 1045"
description: "code solutions"
categories: [PAT-A]
tags: [C++]
redirect_from:
  - /2019/02/28/
---
PAT-A 1045

1045 Favorite Color Stripe （30 分）

Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

## Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (≤200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (≤200) followed by M Eva's favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (≤10^4) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line a separated by a space.
    
## Output Specification:

For each test case, simply print in a line the maximum length of Eva's favorite stripe.

## Sample Input:

    6
	5 2 3 1 5 6
	12 2 2 4 1 5 5 6 3 1 1 5 6
    
## Sample Output:
    
    7
    
## my own thoughts
 
Obviously brute force will be OK but it certainly will not get full grade. Actually,This problem is a typical DP(dynamic planning) problem,and among many types of problem in the large DP fields, it can be solved by two of them,which called LCS and LIS,and I will introduce LCS here and introduce the other in the reflection section.  

Concretly, LCS means longest common subsequence,and the state transition equation is as below  
![DP-LCS](/images/PAT-A/DP-LCS.jpg)  
Then here is the template code:  

    {% highlight ruby %}
    #include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<string>
	using namespace std;

	const int MAXN = 1005;

	int DP[MAXN][MAXN];

	int main()
	{
		string a;
		string b;
		while(cin >> a >> b)
		{
			int l1 = a.size();
			int l2 = b.size();
			memset(DP, 0, sizeof(DP)); 
			for(int i = 1; i <= l1; i++)
				for(int j = 1; j <= l2; j++)
					if(a[i - 1] == b[j - 1])
						DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
					else
						DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			printf("%d\n", DP[l1][l2]);
		}
		return 0;
	}
	{% endhighlight %}

And here is the code of this problem:  

    {% highlight ruby %}
	#include <cstdio>
	#include <algorithm>
	using namespace std;

	const int maxc = 210;
	const int maxn = 10010;
	int A[maxc],B[maxn],dp[maxc][maxn];
	int main()
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
			scanf("%d",&A[i]);
		int L;
		scanf("%d",&L);
		for(int i=1;i<=L;++i)
			scanf("%d",&B[i]);
		for(int i=0;i<=m;++i)
			dp[i][0]=0;
		for(int j=0;j<=L;++j)
			dp[0][j]=0;
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=L;++j)
			{
				int MAX = max(dp[i-1][j],dp[i][j-1]);
				if(A[i]==B[j])
					dp[i][j]=MAX+1;
				else
					dp[i][j]=MAX;
			}
		}
		printf("%d\n",dp[m][L]);
		return 0;
	}
	{% endhighlight %}
---	
## reflection

Another method to solve this problem is LIS , which means longest increasing sequence. This method can find a uncontinual undecreasing sequence of one certian sequence.  
The state transaction equation is dp[i]=max{1,dp[j]+1}(j=1,2,…,i-1&&A[j]<A[i])  
Here is the template:   

	{%highlight ruby%}
	int LIS(int A[],int n)
	{
		int* d = new int[n];
		int len = 1;
		int i,j;
		for(i=0;i<n;i++)
		{
			d[i]=1;
			for(j=0;j<i;j++)
			{
				if(A[j]<=A[i] && (d[j]+1)>=d[i])
					d[i]=d[j]+1;
			}
			if(d[i]>len) len=d[i];
		}
		delete []d;
		return len;
	}
	{%endhighlight%}  
	
But the time complexity will be O(n^2),and it is literally slow for many problem,thus we need to use binary search to optimize this algorithm to O(nlogn). And here is the template:  

	{%highlight ruby%}
	int put(int arr[], int l, int r, int key)//在arr[l...r]中二分查找插入位置
	{
		int mid;
		if (arr[r] <= key)
			return r + 1;
		while (l < r)
		{
			mid = l + (r - l) / 2;
			if (arr[mid] <= key)
				l = mid + 1;
			else
				r = mid;
		}
		return l;
	}

	int LIS(int A[], int n)
	{
		int i = 0, len = 1 ,next;
		int* B = (int *)alloca(sizeof(int) * (n + 1));
		B[1] = A[0]; 
		for (i = 1;i < n;i++)
		{
			int next = put(B, 1, len, A[i]); 
			B[next] = A[i];
			if (len < next)    len = next;
		}
		return len;
	}
	{%endhighlight%}
	
And the code of this problem is as below:  

	{%highlight ruby%}
	#include <cstdio>
	#include <cstring>
	#include <algorithm>

	using namespace std;

	const int maxn=10010;
	const int maxc=210;
	int dp[maxn],HashTable[maxc];
	int A[maxn];

	int main()
	{
		int n,m,x,l;
		int num;

		memset(HashTable,-1,sizeof(HashTable));
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;++i)
		{
			scanf("%d",&x);
			HashTable[x]=i;
		}
		scanf("%d",&l);
		num=0;
		for(int i=0;i<l;++i)
		{
			scanf("%d",&x);
			if(HashTable[x]>=0)
				A[num++]=HashTable[x];
		}

		int ans=-1;
		for(int i=0;i<num;++i)
		{
			dp[i]=1;
			for(int j=0;j<i;++j)
				if(A[j]<=A[i]&&dp[i]<dp[j]+1)
					dp[i]=dp[j]+1;
			ans = max(ans,dp[i]);
		}
		printf("%d\n",ans);
		return 0;
	}
	{%endhighlight%}  
	
LIS and LCS is two sorts of relatively easy problem in the field of dynamic planning, and do some extra exercise will help us to solve this kind of problem faster.  

---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
