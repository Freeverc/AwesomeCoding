
/*每两个元素视为一组，则可以证明每一组即[a[2k-1], a[2k]]和[b[2k-1], b[2k]]所对应的最小权值就是|a[2k]-a[2k+1]|，当且仅当

		min(a[2k-1], a[2k])<=b[2k-1], b[2k]<=max(a[2k-1], a[2k])且|b[2k-1]-b[2k]|<=1

则当n为偶数时，整个序列的最小权值即为Σ|a[2k-1]-a[2k]|+min(Σ(b[2l]-b[2l+1])^2)，其中k为1到n/2，l为1到n/2-1，且k,l均为正整数

而当n为奇数时，则Σ[n]=Σ[n-1]+|a[n]-a[n-1]|

根据上述描述，只须再解决minΣ(b[2l]-b[2l+1])^2即可，由于min(a[2k-1], a[2k])<=b[2k-1], b[2k]<=max(a[2k-1], a[2k])，而这分为两种情况：
一、两个区间[a[2l-1],a[2l]]和[a[2l+1],a[2l+2]]交集非空，则可令b[2l]=b[2l+1]，即该项为0；
二、若上述两个区间交集为空集，则可以写一个函数来表示
min(|a[2l-1]-a[2l+1]|,|a[2l-1]-a[2l+2]|,|a[2l]-a[2l+1]|,|a[2l]-a[2l+2]|)，这一项对应着min(b[2l]-b[2l+1])^2，再从遍历l并求和即可*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn = 100000;
int a[maxn];

int minofsquare(int a1, int a2, int a3, int a4) {
	int s[4];
	s[0] = abs(a1 - a3);
	s[1] = abs(a1 - a4);
	s[2] = abs(a2 - a3);
	s[3] = abs(a2 - a4);
	int minimum = 9;
	for (int i = 0; i < 4; i++)
		minimum = min(minimum, s[i]);
	return minimum*minimum;
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int sum = 0;
		for (int k = 1; k <= n / 2; k++)
			sum += abs(a[2 * k - 1] - a[2 * k]);
		for (int l = 1; l <= n / 2 - 1; l++) {
			if(max(a[2*l-1],a[2*l])<min(a[2*l+1],a[2*l+2])|| min(a[2 * l - 1], a[2 * l]) > max(a[2 * l + 1], a[2 * l + 2]))
				sum += minofsquare(a[2 * l - 1], a[2 * l], a[2 * l + 1], a[2 * l + 2]);
		}
		if (n % 2 == 1)
			sum += abs(a[n] - a[n - 1]);
		cout << sum << endl;
	}
	return 0;
}