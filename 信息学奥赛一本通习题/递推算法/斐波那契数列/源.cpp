
/*
【题目描述】
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。

给出一个正整数a，要求菲波那契数列中第a个数对1000取模的结果是多少。

【输入】
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 ≤ a ≤ 1000000)。

【输出】
n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数对1000取模得到的结果。

【输入样例】
4
5
2
19
1
【输出样例】
5
1
181
1

*/

#include<iostream>
#include<vector>

using namespace std;

short a[1000000];



int main()
{
	vector<int> re;
	int n,m,count = 2;
	a[0] = 0;
	a[1] = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		
		if(count<=m)
			while (count <= m)
			{
				a[count] = (a[count - 1] + a[count - 2])%1000;

				count++;
			}
		re.push_back(a[m]);
	}


	for (int i = 0; i < re.size(); i++)
		cout << re[i]<<endl;

	//system("pause");
	return 0;
}



