//// KuaishouC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

////

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> mem(n, vector<int>(n+1, -1));
	for (int i = 1; 2*i < n+1; i++) {
		mem[i][2 * i] = 0;
		mem[2 * i][i] = 0;
		if (2 * i + 1 < n) {
			mem[i][2 * i + 1] = 0;
			mem[2 * i + 1][i] = 0;
		}
	}
	int num, u, v, w;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 1) {
			cin >> u >> v >> w;
			mem[u][v] += w;
			mem[v][u] += w;
		}
		if (num == 2) {
			cin >> u >> v;
			if (mem[u][v] >= 0)
				cout << mem[u][v];
			else
				cout << 0;
		}
	}
}

//void find(vector<vector<int> >& data, vector<vector<int> >& mem, int i, int j)
//{
//	if (i < 0 || i >= data.size || j<0 || j>data[0].size() || mem[i][j] > 0)
//		return;
//	
//	mem[i][j] = r;
//	if (i - 1 >= 0 && data[i - 1][j] == 1)
//		find(data, mem, i - 1, j);
//
//
//
//
//}

int main4()
{
	int x, y;
	cin >> x >> y;
	vector<vector<int> > data(x, vector<int>(y));
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> data [i][j];
	int num;
	vector<vector<int> > mem(x, vector<int>(y, 0));
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			if (data[i][j] == 1 && mem[i][j] == 0)
			{

			}
		}
	return 0;
}

//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <set>
//#include <queue>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n = 0, k = 0, index;
//	cin >> n;
//	string url, base, path;
//	unordered_map<string, set<string>> mp;
//	vector<int> typ(n, -1);
//	for (int i = 0; i < n; i++) {
//		cin >> url;
//		for (index = 7; index < url.size(); index++) {
//			if (url[index] == '/')
//				break;
//		}
//		base = url.substr(0, index);
//		path = 'p' + url.substr(index);
//		mp[base].insert(path);
//	}
//
//	vector<string> vec;
//	int m = 0;
//	for (unordered_map < string, set<string>> ::iterator it = mp.begin(); it != mp.end(); it++) {
//		vec.push_back(it->first);
//		m++;
//	}
//	for (int i = 0; i < m; i++) {
//		if (typ[i] < 0) {
//			for (int j = i + 1; j < m; j++) {
//				if (typ[j] < 0 && mp[vec[i]] == mp[vec[j]])
//				{
//					typ[i] = i;
//					typ[j] = i;
//				}
//			}
//		}
//		//cout <<vec[i]<<"  "<< typ[i] << endl;
//	}
//	unordered_map<int, vector<string> > typMp;
//	vector<vector<string>> result;
//	for (int i = 0; i < m; i++) {
//		if (typ[i] >= 0 && typMp.find(typ[i]) == typMp.end()) {
//			k++;
//			typMp[typ[i]].push_back(vec[i]);
//		}
//		else if (typ[i] >= 0 && typMp.find(typ[i]) != typMp.end()) {
//			typMp[typ[i]].push_back(vec[i]);
//		}
//	}
//	cout << k << endl;
//	for ( unordered_map<int, vector<string> >::iterator it = typMp.begin(); it != typMp.end(); it++) {
//		for (int j = 0; j < it->second.size(); j++)
//			cout << it->second[j] << " ";
//		cout << endl;
//	}
//	return 0;
//
//}
