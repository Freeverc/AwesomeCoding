// Kuaishou.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int K, n;
	cin >> K >> n;
	if (n < K) {
		cout << 1 << endl;
		return 0;
	}
	long long int a;
	a = (K - 1) * pow(2, n - K) + 1;
	int r = a % 397;
	cout << r << endl;
	return 0;
}
//2
//int main()
//{
//    vector<vector<int>> dict = { {-1, 8,9},{-1, 7, -1}, {-1, -1,3},{-1, 9, 5}, { -1,-1,-1} ,
//                                   {-1, 9, 3}, {-1, 8, 9}, {1, -1,-1}, {9,-1,-1},{5, 8, 6} };
//    int n, m, find = 0;
//    cin >> n;
//    vector<int> nums;
//    while (n > 0) {
//        nums.push_back(n%10);
//        n /= 10;
//        //cout << nums.back() << " ";
//    }
//    int minusIndexRight = -1, minusIndexLeft = -1, addIndexLeft = -1, addIndexRight = -1;
//    int selfIndexLeft = -1, selfIndexRight = -1;
//    for (int i = 0; i < nums.size(); i++) {
//        if (dict[nums[i]][0] > nums[i])
//            minusIndexLeft = i;
//        if (dict[nums[i]][1] > nums[i])
//            addIndexLeft = i;
//        if (dict[nums[i]][2] > nums[i])
//            selfIndexLeft = i;
//    }
//    for (int i = nums.size() - 1; i >= 0; i--) {
//        if (dict[nums[i]][0] >= 0)
//            minusIndexRight = i;
//        if (dict[nums[i]][1] >= 0)
//            addIndexRight = i;
//        if (dict[nums[i]][2] >= 0)
//            selfIndexRight = i;
//    }
//
//    if (minusIndexLeft > addIndexLeft && minusIndexLeft > selfIndexLeft) {
//        if (addIndexRight > -1 && minusIndexLeft > addIndexRight) {
//            find = 1;
//            nums[minusIndexLeft] = dict[nums[minusIndexLeft]][0];
//            nums[addIndexRight] = dict[nums[addIndexRight]][1];
//        }
//    }
//    if (!find && addIndexLeft > minusIndexLeft && addIndexLeft > selfIndexLeft) {
//        if (minusIndexRight > -1 && addIndexLeft > minusIndexRight) {
//            find = 1;
//            nums[addIndexLeft] = dict[nums[addIndexLeft]][1];
//            nums[minusIndexRight] = dict[nums[minusIndexRight]][0];
//        }
//    }
//    if (!find && selfIndexLeft > minusIndexLeft && selfIndexLeft > addIndexLeft ) {
//		find = 1;
//		nums[selfIndexLeft] = dict[nums[selfIndexLeft]][2];
//    }
//    if (!find)
//        m = -1;
//    else {
//        m = 0;
//        for (int i = nums.size() - 1; i>=0;i--) {
//            m = m * 10 + nums[i];
//        }
//    }
//    cout << m << endl;
//    return 0;
//}
//1
//string s, r;
//int find;
//cin >> s;
//while (1) {
//    find = 0;
//    for (int i = 0; i < s.size(); i++) {
//        if (i < s.size() - 2 && s[i] == s[i + 1] && s[i] == s[i + 2]) {
//            find = 1;
//            int j = i;
//            while (j < s.size() && s[j] == s[i]) {
//                j++;
//            }
//            i = j - 1;
//        }
//        else
//            r += s[i];
//    }
//    s = r;
//    r = "";
//    if (!find)
//        break;
//}
//cout << s << endl;
//
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
