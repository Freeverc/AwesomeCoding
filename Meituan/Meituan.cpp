// Meituan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> result(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++) {
		if (result[i] == -1) {
			for (int j = i+1; j < n; j++) {
				if ((nums[i] & nums[j]) == 0) {
					result[i] = 1;
					result[j] = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}

int main3()
{
	int n;
	cin >> n;
	int a;
	vector<int> r(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		int num = -1;
		for (int j = 0; ; j++) {
			if (j == n)
				j = 0;
			if (r[j] == 0) {
				num++;
				if (num == a) {
					r[j] = n - i;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << endl;
	return 0;
}
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		int dotIndex = s.size();
//		for (int j = 0; j < s.size(); j++) {
//			if (s[j] == '.') {
//				dotIndex = j;
//				break;
//			}
//		}
//		if (dotIndex == s.size())
//			s += ".00";
//		else if (dotIndex == s.size()-1)
//			s += "00";
//		else if (dotIndex == s.size()-2)
//			s += "0";
//		else if (dotIndex < s.size() - 3)
//			s = s.substr(0, dotIndex + 3);
//		for (int j = dotIndex - 3; j > 0; j-= 3) {
//			if (j > 1 || s[0] != '-') {
//				s.insert(s.begin() + j, ',');
//				dotIndex++;
//			}
//		}
//		if (s[0] == '-') {
//			s[0] = '$';
//			s.insert(s.begin(), '(');
//			s.push_back(')');
//		}
//		else
//			s.insert(s.begin(), '$');
//		cout << s << endl;
//	}
//}
//bool sortKeyX(vector<int> a, vector<int> b)
//{
//	return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
//}
//bool sortKeyY(vector<int> a, vector<int> b)
//{
//	return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<int>> stars(n, vector<int>(3, 0));
//	for (int i = 0; i < n; i++) {
//		cin >> stars[i][0] >> stars[i][1];
//	}
//	int count = 0;
//	sort(stars.begin(), stars.end(), sortKeyX);
//	for (int i = 0; i < n; i++) {
//		if (i - 1 >= 0 && stars[i][0] == stars[i - 1][0])
//			stars[i][2]++;
//		if (i + 1 < n && stars[i][0] == stars[i + 1][0])
//			stars[i][2]++;
//	}
//	sort(stars.begin(), stars.end(), sortKeyY);
//	for (int i = 0; i < n; i++) {
//		if (i - 1 >= 0 && stars[i][1] == stars[i - 1][1])
//			stars[i][2]++;
//		if (i + 1 < n && stars[i][1] == stars[i + 1][1])
//			stars[i][2]++;
//		if (stars[i][2] == 4)
//			count++;
//	}
//	cout << count << endl;
//}
