﻿
/*
1195：判断整除

时间限制: 1000 ms         内存限制: 65536 KB
提交数: 4835     通过数: 1956

【题目描述】
一个给定的正整数序列，在每个数之前都插入++号或−−号后计算它们的和。比如序列：1、2、41、2、4共有88种可能的序列：


(+1) + (+2) + (+4) = 7
(+1) + (+2) + (-4) = -1
(+1) + (-2) + (+4) = 3
(+1) + (-2) + (-4) = -5
(-1) + (+2) + (+4) = 5
(-1) + (+2) + (-4) = -3
(-1) + (-2) + (+4) = 1
(-1) + (-2) + (-4) = -7
所有结果中至少有一个可被整数kk整除，我们则称此正整数序列可被kk整除。例如上述序列可以被3、5、73、5、7整除，而不能被2、4、6、8……2、4、6、8……整除。注意：0、−3、−6、−9……0、−3、−6、−9……都可以认为是3的倍数。

【输入】
输入的第一行包含两个数：N(2<N<10000)N(2<N<10000)和k(2<k<100)k(2<k<100)，其中NN代表一共有N个数，kk代表被除数。第二行给出序列中的NN个整数，这些整数的取值范围都00到1000010000之间（可能重复）。

【输出】
如果此正整数序列可被kk整除，则输出YESYES，否则输出NONO。（注意：都是大写字母）

【输入样例】
3 2
1 2 4
【输出样例】
NO


[算法分析]

这是一个状态压缩动态规划的问题


设dp[i][j]:=前i个数整除k的余数是否为j，0为不是，1为是

递推方程是：dp[i][j]=dp[i-1][(k+j-a[i]%k)%k]||dp[i-1][(j+a[i]%k)%k];

设输入的数是a，b

我们判断到第二个数（也就是b的时候），b可以为b也可以为-b，即判断(a+b)%k和(a-b)%k是否等于j，这要有一个等于那么就dp[2][j]就等于1

（1）对于(a+b)%k是否为j

若成立则a%k+b%k=j

a%k=j-b%k为了防止数组小标为负数的情况，把j-b%k变成(j-b%k+k)%k

即a%k=(j-b%k+k)%k

（2）对于(a-b)%k是否等于j

若成立则a%k=(j+b%k)%k
*/

#include<iostream>

using namespace std;


bool dp[10001][101];

int a[10001];

int main()
{
	int N, k;

	cin >> N >> k;

	for (int i = 1; i <= N; i++) cin>>a[i];

	dp[1][a[1] % k] = 1;
	dp[1][(-a[1] % k + k) % k] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < k; j++)
			dp[i][j] = dp[i-1][(k + j - a[i] % k)%k]||dp[i-1][(j + a[i] % k)%k];

	}

	if (dp[N][0]) cout << "YES"<<endl;
	else cout << "NO"<<endl;


	return 0;
}


