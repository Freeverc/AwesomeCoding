#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> func(vector < vector<int>>& data, int m, int index)
{
    vector<vector<int>> results;
    vector<int> result;
	int maxValue = 0;
	cout << "index:   " << index << endl;
    for (int i = index; i < data.size(); i++) {
		cout << "i:   " << i<< endl;
		if (data[i][1] > m)
			continue;
		vector<int> result1 = func(data, m - data[i][1], i + 1);
		result1.insert(result1.begin(), data[i][0]);
		vector<int> result2 = func(data, m, i + 1);
		int value1 = 0, value2 = 0;
		cout << "result1: ";
		for (int i = 0; i < result1.size(); i++)
		{
			cout << result1[i] << " ";
			value1 += data[result1[i]-1][2];
		}
		cout << "\nresult2: ";
		for (int i = 0; i < result2.size(); i++)
		{
			cout << result2[i] << " ";
			value2 += data[result2[i]-1][2];
		}
		cout << endl;
		if (value1 > value2)
			result = result1;
		else
			result = result2;
    }
    return result;
}

int main()
{
	int n, m;
	cin >> m;
	cin >> n;
	vector<vector<int>> data(n, vector<int>(3));
	vector<int> value(n);
	for (int i = 0; i < n; i++) {
		data[i][0] = i + 1;
		cin >> data[i][1];
	}
	for (int i = 0; i < n;i++)
		cin >> data[i][2];
	vector<int> result = func(data, m, 0);
	sort(result.begin(), result.end());
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
	return 0;
}