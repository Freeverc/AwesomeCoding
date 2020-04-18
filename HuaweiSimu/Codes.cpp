#include "Codes.h"

int Codes::p1()
{
	int n, r;
	vector<int> nums;
	while (cin >> n && n != 0) {
		nums.push_back(n);
	}
	for (auto n : nums) {
		r = 0;
		while (n >= 3) {
			r += n / 3;
			n = n / 3 + n % 3;
		}
		if (n == 2)
			r += 1;
		cout << r << endl;
	}
	return 0;

}

int Codes::p2()
{
	int n, num;
	vector<int> nums;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> num;
			nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i == nums.size() - 1 || nums[i] < nums[i + 1])
				cout << nums[i] << endl;
		}
		nums.clear();
	};
	return 0;

}

int Codes::p3()
{
	return 0;
}
