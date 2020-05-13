// Pinduoduo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n, num = 0;
//	cin >> n;
//	vector<int> data(n);
//	for (int i = 0; i < n; i++)
//		cin >> data[i];
//	sort(data.begin(), data.end());
//	for (int i = 1; i < n; i++) {
//		if(data[i] <= data[i - 1]) {
//			num += data[i - 1] - data[i] + 1;
//			data[i] = data[i - 1] + 1;
//		}
//	}
//	cout << num << endl;
//}

#include <iostream>

using namespace std;

int main(){
	int t, a, b, n;
	bool r;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> n;
		if (n == 0)
			r = (a % 3 == 0);
		else if (n == 1)
			r = (b % 3 == 0);
		else
		{
			for (int j = 1; j < n; j++)
			{
				b = a + b;
				a = b - a;
				b %= 3;
				a %= 3;
			}
			r = (b % 3 == 0);
		}
		if (r)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& data, vector<int>& mem, int len, int j)
{
	bool find = 0;
	if (data[j] == len) {
		mem[j] = 1;
		find = 1;
	}
	int currSum = data[j];
	for (int k = j - 1; k >= 0 && !find; k--) {
		if (mem[k] == 1)
			continue;
		if (currSum + data[k] > len)
			continue;
		else
		{
			currSum += data[k];
			if (currSum == len) {
				mem[j] = 1;
				mem[k] = 1;
				find = 1;
				break;
			}
			else {
				mem[k] = 1;
				find = search(data, mem, len - currSum, k);
				if (find)
					break;
				else
					mem[k] = 0;
			}
		}
	}
	return find;
}

int main(){
	int t, n;
	bool r = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> data(n);
		vector<int> mem(n, 0);
		int sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> data[j];
			sum += data[j];
		}
		if (sum % 4 != 0) {
			r = 0;
		}
		else {
			sort(data.begin(), data.end());
			int len = sum / 4;
			if (data[n - 1] > len)
				r = 0;
			else {
				int findNum = 0;
				for (int j = n - 1; j >= 0 && mem[j] == 0; j--) {
					bool find = search(data, mem, len, j);
					if (find)
						findNum++;
					if (findNum == 3) {
						r = 1;
						break;
					}
				}
			}
		}
		if (r)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int gcd(int a, int b) {
//	if (a < b) {
//		int t = a; a = b; b = t;
//	}
//	if (b == 0)
//		return a;
//	else if (a % b == 0)
//		return b;
//	else
//		return gcd(a % b, b);
//}
//
//int main() {
//	int n, m = 0;
//	cin >> n;
//	vector<int> data(n);
//	vector<vector<int>> mem(n, vector<int>(n, 1));
//	for (int i = 0; i < n; i++) {
//		cin >> data[i];
//		mem[i][i] = data[i];
//		if (data[i] > m)
//			m = data[i];
//	}
//	for (int i = 1; i < n; i++) {
//		for (int j = 0; j + i < n; j++) {
//			mem[j][j + i] = gcd(mem[j][j + i - 1], data[j + i]);
//			if ((i + 1) * mem[j][j + i] > m)
//				m = (i + 1) * mem[j][j + i];
//		}
//	}
//	cout << m << endl;
//}
