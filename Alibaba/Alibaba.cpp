#include <iostream>  
#include <vector>

using namespace std;

int findRoad(vector<vector<int>>&  road, int c, int x)
{
	int n = road.size();
	int s = 0;
	int find = 1;
	vector<int> reach(n, 200000);
	reach[c] = 0;
	while (find == 1) {
		find = 0;
		for (int i = 0; i < n; i++)
		{
			if (reach[i] < 200000)
			{
				for (int j = 0; j < n; j++) {
					if (reach[i] + road[i][j] < reach[j]) {
						reach[j] = road[c][i] + road[i][j];
						find = 1;
					}
				}
			}
		}
	}
	return reach[x];
}

int main()
{
	int n, m, x, s;
	int a, b, len;
	while (cin >> n >> m >> x)
	{
		vector<vector<int> > road(n, vector<int>(n, 200000));
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> len;
			road[a - 1][b - 1] = len;
		}
		s = 0;
		for (int i = 0; i < n; i++)
		{
			s += findRoad(road, i, x - 1);
			s += findRoad(road, x - 1, i);
		}
		cout << s << endl;
	}
	return 0;
}

//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> nums(n + 1, 0);
//    vector<int> votes(n + 1, 1);
//    for (int i = 1; i <= n; i++) {
//        cin >> nums[i];
//    }
//    for (int i = n; i >= 0; i--) {
//		int b = nums[i];
//		if(b>0) {
//			votes[b]+=votes[i];
//		}
//    }
//    for (int i = 1; i <= n; i++) {
//        cout << votes[i] << endl;
//    }
//    return 0;
//}
