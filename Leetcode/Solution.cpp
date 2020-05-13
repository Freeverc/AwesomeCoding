#include "Solution.h"

    
int Solution::testFunc()
{
	num = 12;
	cout << num << endl;
	return 0;
}

vector<int> Solution::twoSum(vector<int>& nums, int target) {
	vector<int> index(2);
	for(int i = 0;i<nums.size();i++)
		for (int j = i+1; j < nums.size(); j++)
		{
			if ((i != j) && (nums[i] + nums[j] == target))
			{
				index[0] = i;
				index[1] = j;
				return index;
			}
		}
	return index;
}

vector<int> Solution::twoSum2(vector<int>& nums, int target) {
	vector<int> index(2);
	unordered_map<int, int> map;
	for (vector<int>::iterator a = nums.begin(); a != nums.end(); a++)
	{
		if (map.find(target - *a) != map.end())
		{
			index[1] = a - nums.begin();
			index[0] = map[target - *a];
			return index;
		}
		else
			map[*a] = a - nums.begin();
	}
	return index;
}

bool Solution::canThreePartsEqualSum(vector<int>& A)
{
	int N = 3;
	int sum = 0;
	for (vector<int>::iterator a = A.begin(); a < A.end(); a++)
		sum += *a;
	//cout << sum << endl;
	if (sum % N != 0)
		return false;
	sum /= N;
	int flag = 0;
	vector<int>::iterator a = A.begin();
	while( a < A.end())
	{
		int sumTemp = *a;
		a++;
		while ((sumTemp != sum)&&(a<A.end()))
		{
			sumTemp += *a;
			a++;
		}
		if (sumTemp == sum)
		{
			flag++;
			while ((a < A.end()) && (*a == 0))
			{
				a++;
				if (sum == 0)
					flag++;
			}
		}
		//cout << sumTemp << endl;
		//cout << a - A.begin() << endl;
		if (a == A.end())
		{
			//cout <<"flag: "<< flag << endl;
			if ((flag >= N)&&((sumTemp == 0)||(sumTemp == sum)))
				return true;
			else
				return false;
		}
	}
	return false;

}

bool Solution::canThreePartsEqualSum2(vector<int>& A)
{
	int N = 3, sum = 0;
	for (vector<int>::iterator a = A.begin(); a < A.end(); a++)
		sum += *a;
	if (sum % N != 0)
		return false;
	sum /= N;
	vector<int>::iterator a = A.begin();
	vector<int>::iterator b = A.end() - 1;
	int sumLeft = *a;
	int sumRight = *b;
	a++;
	b--;
	while ((sumLeft != sum)&&(a < A.end()))
	{
		sumLeft += *a;
		a++;
	}
	while ((sumRight != sum) && (b >= A.begin()))
	{
		sumRight += *b;
		b--;
	}
	if ((a >= A.end()) || (b < A.begin())||(a > b))
	{
		return false;
	}
	else
	{
		return true;
	}
	return false;
}

bool Solution::canThreePartsEqualSum3(vector<int>& A)
{
	int sum = 0;
	for (int i = 0; i < A.size(); i++)
		sum += A[i];
	if (sum % 3 != 0)
		return false;
	sum /= 3;
	int i = 0, j = A.size() - 1;
	int sumLeft = A[i];
	int sumRight = A[j];
	i++;
	j--;
	while ((sumLeft != sum) && (i < A.size()))
	{
		sumLeft += A[i];
		i++;
	}
	while ((sumRight != sum) && (j >= 0)) 
	{
		sumRight += A[j];
		j--;
	}
	if ((i >= A.size()) || (j < 0) || (i > j))
	{
		return false;
	}
	else
	{
		return true;
	}
	return false;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int c = 0;
	ListNode* p = new ListNode(c);
	ListNode* sum = p;
	while (l1 != NULL || l2 != NULL) {
		if (l1 != NULL) {
			p->val += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			p->val += l2->val;
			l2 = l2->next;
		}
		c = p->val / 10;
		p->val %= 10;
		if ((c > 0) || (l1 != NULL || l2 != NULL)) {
			p->next = new ListNode(c);
			p = p->next;
		}
		else {
			break;
		}
	}
	p->next = NULL;
	return sum;
}

int Solution::lengthOfLongestSubstring2(string s)
{
	int maxLenth = 0, i, j;
	unordered_map<char, int> map;
	for (i = 0, j = 0; j < s.length(); j++)
	{
		if (map.find(s[j]) != map.end())
		{
			if (map[s[j]] >= i)
			{
				maxLenth = j - i > maxLenth ? j - i : maxLenth;
				i = map[s[j]]+1;
			}
		}
		map[s[j]] = j;
	}
	if (j - i> maxLenth)
		maxLenth = j - i;
	return maxLenth;
}

int Solution::lengthOfLongestSubstring(string s)
{
	int maxLenth = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int repeat = 0, tempLenth = 0;
		for (int j = i; j < s.length(); j++)
		{
			for (int k = i; k < j; k++)
			{
				if (s[j] == s[k])
				{
					repeat = 1;
					i = k;
				}
			}
			if (repeat == 0)
				tempLenth++;
			else
				break;
		}
		if (tempLenth > maxLenth)
			maxLenth = tempLenth;
	}
	return maxLenth;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m, n, i, j, iMin, iMax, maxLeft, minRight;
	double median = 0;
	if (nums1.size() > nums2.size()) {
		vector<int> temp = nums1;
		nums1 = nums2;
		nums2 = temp;
	}
	m = nums1.size();
	n = nums2.size();
	if (m == 0) {
		if (n % 2 == 0)
			median = (double)(nums2[(n - 1) / 2] + nums2[(n + 1) / 2])/2;
		else
			median = nums2[n / 2];
		return median;
	}
	iMin = 0;
	iMax = m;
	while (iMin <= iMax)
	{
		i = (iMin + iMax) / 2;
		j = (m + n + 1) / 2 - i;
		if ((i > 0) && (j > 0))
			maxLeft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
		else if ((i <= 0) && (j > 0))
			maxLeft = nums2[j - 1];
		else if ((i > 0) && (j <= 0))
			maxLeft = nums1[i - 1];
		else
			break;

		if((i<m)&&(j<n))
			minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
		else if((i>=m)&&(j<n))
			minRight = nums2[j];
		else if((i<m)&&(j>=n))
			minRight = nums1[i];
		else
			break;
		cout <<"irange : "<< iMin << "  " << iMax << endl;
		cout << " i j  : " << i << "  " << j << endl;
		cout << "maxmin: "<< maxLeft << "  " << minRight << endl;

		if (maxLeft <= minRight)
		{
			if ((n + m) % 2 == 0)
				median = (double)(maxLeft + minRight) / 2;
			else
				median = maxLeft;
			break;
		}
		else
		{
			if ((i > 0) && (nums1[i - 1] > nums2[j]))
			{
				iMax = i;
			}
			if ((i < m) && (nums2[j - 1] > nums1[i]))
			{
				iMin = i+1;
			}
		}
	}
	return median;
}

double Solution::findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
	int m, n, i, j, iMin, iMax, maxLeft, minRight;
	double median = 0;
	if (nums1.size() > nums2.size()) {
		vector<int> temp = nums1;
		nums1 = nums2;
		nums2 = temp;
	}
	m = nums1.size();
	n = nums2.size();
	if (m == 0) {
		if (n % 2 == 0)
			median = (double)(nums2[(n - 1) / 2] + nums2[(n + 1) / 2])/2;
		else
			median = nums2[n / 2];
		return median;
	}
	iMin = 0;
	iMax = m;
	while (iMin <= iMax)
	{
		i = (iMin + iMax) / 2;
		j = (m + n + 1) / 2 - i;
		if ((i > 0) && (j > 0))
			maxLeft = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
		else if ((i <= 0) && (j > 0))
			maxLeft = nums2[j - 1];
		else if ((i > 0) && (j <= 0))
			maxLeft = nums1[i - 1];
		else
			break;

		if((i<m)&&(j<n))
			minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
		else if((i>=m)&&(j<n))
			minRight = nums2[j];
		else if((i<m)&&(j>=n))
			minRight = nums1[i];
		else
			break;
		cout <<"irange : "<< iMin << "  " << iMax << endl;
		cout << " i j  : " << i << "  " << j << endl;
		cout << "maxmin: "<< maxLeft << "  " << minRight << endl;

		if (maxLeft <= minRight)
		{
			if ((n + m) % 2 == 0)
				median = (double)(maxLeft + minRight) / 2;
			else
				median = maxLeft;
			break;
		}
		else
		{
			if ((i > 0) && (nums1[i - 1] > nums2[j]))
			{
				iMax = i;
			}
			if ((i < m) && (nums2[j - 1] > nums1[i]))
			{
				iMin = i+1;
			}
		}
	}
	return median;
}

string Solution::longestPalindrome(string s)
{
	int maxLenth = 0;
	string result;
	for(int i = 0;i<s.length();i++)
		for (int j = i+1; j <= s.length(); j++)
		{
			int isPalindrome = true;
			for (int k = i; k < (i+j)/2; k++)
			{
				if (s[k] != s[i + j - 1 - k])
				{
					isPalindrome = false;
				}
			}
			if( isPalindrome)
			{
				if (j - i > maxLenth)
				{
					maxLenth = j - i;
					result = s.substr(i, j-i);
				}
			}
		}
	return result;
}

//5
string Solution::longestPalindrome2(string s)
{
	int p[2004] = { 0 }, i = 0, j = 0, R = 0, C = 0, L = 0, maxLength=-1;
	string sNew("#"); 
	string result, resultNew;
	for (i = 0,j=0; i < s.length(); i++, j += 2) {
		sNew.append(1, s[i]);
		sNew.append(1, '#');
	}

	for (i = 0; i < sNew.length(); i++) {
		int k=0;
		j = 2 * C - i;
		if (i >= R) {
			for (k = 0; ((i + k < sNew.length() && (i - k >= 0)) && (sNew[i + k] == sNew[i - k])); k++)
				;
			p[i] = k;
			if (i + k - 1 > R) {
				R = i + k -1;
				C = i;
				L = 2 * C - R;
			}
		}
		else {
			if (j - p[j] + 1< L) {
				p[i] = R - i + 1;
			}
			else if (j - p[j] + 1> L) {
				p[i] = p[j];
			}
			else {
				for (k = p[j] - 1; ((i + k < sNew.length() && (i - k >= 0)) && (sNew[i + k] == sNew[i - k])); k++)
					;
				p[i] = k;
				if (i + k - 1 > R)
				{
					R = i + k -1;
					C = i;
					L = 2 * C - R;
				}
			}
		}
		if (p[i] > maxLength) {
			maxLength = p[i];
			resultNew = sNew.substr(i - p[i] + 1, 2 * p[i] - 1);
		}
	}
	for (i = 1; i < resultNew.length(); i += 2)
		result.append(1, resultNew[i]);
	return result;
}

//6
string Solution::convert(string s, int numRows)
{
	if (numRows == 1)
		return s;
	int d = 2 * numRows - 2;
	string r = "";
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j + i < s.size(); j += d) {
			r += s[j+i];
			if (i != 0 && i != numRows - 1 && j + d - i < s.size())
				r += s[j + d - i];
		}
	}
	return r;
}

//7
int Solution::reverse(int x)
{
	int n = 0;
	while (x) {
		if (n > INT_MAX / 10 || n == INT_MAX / 10 && x % 10 > 7)
			return 0;
		if (n < INT_MIN / 10 || n == INT_MIN / 10 && x % 10 < -8)
			return 0;
		n = n * 10 + x % 10;
		x /= 10;
	}
	return n;
}

//8
int Solution::myAtoi(string str)
{
	if (!str.size())
		return 0;
	int num = 0;
	int i = 0;
	while (i < str.size() && str[i] == ' ')
		i++;
	int flag = 1;
	if (i < str.size() && str[i] == '+') {
		i++;
	}
	else if (i < str.size() && str[i] == '-') {
		flag = -1;
		i++;
	}
	for(;i<str.size();i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (flag == 1 && (num > INT_MAX / 10 || num == INT_MAX && str[i] - '0' > 7))
				return INT_MAX;
			if (flag == -1 && (num < INT_MIN / 10 || num == INT_MIN && str[i] - '0' > 8))
				return INT_MIN;
			num = num * 10 + (str[i] - '0')*flag;
		}
		else
			return num;
	}
	return num;
}

//10
bool Solution::isMatch(string s, string p)
{
	string sNew, pNew;
	if ((p.length() == 0) && s.length() == 0)
		return true;
	else if ((p.length() == 0) && s.length() != 0)
		return false;
	else if ((p.length() != 0) && s.length() == 0)
	{
		if (p.length() >= 2 && p[1] == '*')
		{
			pNew = p.length() > 2 ? p.substr(2) : "";
			return isMatch(s, pNew);
		}
		else
			return false;
	}
	else
	{
		int firstMatch = 0;
		if (p[0] == s[0] || p[0] == '.')
			firstMatch = 1;
		if (p.length() >= 2 && p[1] == '*')
		{
			pNew = p.length() > 2 ? p.substr(2) : "";
			sNew = s.length() > 1 ? s.substr(1) : "";
			//cout << s <<"  "<< sNew << endl;
			//cout << p<<" "<< pNew<< endl;
			return (firstMatch && isMatch(sNew, pNew)) || isMatch(s, pNew) || (firstMatch && isMatch(sNew, p));
		}
		else
		{
			pNew = p.length() > 1 ? p.substr(1) : "";
			sNew = s.length() > 1 ? s.substr(1) : "";
			//cout << s <<"  "<< sNew << endl;
			//cout << p<<" "<< pNew<< endl;
			return firstMatch && isMatch(sNew, pNew);
		}
	}
	return false;
}

//int Solution::num = 0;
//vector<vector<int>> Solution::mem;

bool Solution::isMatch2(string s, string p)
{
	string sNew, pNew;
	mem = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
	return dp(s, 0, p, 0);
}

bool Solution::dp(const string s, int sIndex, const string p, int pIndex)
{
	vector<vector<int>> &m = mem;
	if (m[sIndex][pIndex] != -1)
		return m[sIndex][pIndex];
	bool res;
	if (pIndex >= p.size())
		res = (sIndex >= s.size());
	else {
		bool currentMatch = (sIndex < s.size() && (s[sIndex] == p[pIndex] || p[pIndex] == '.'));
		if (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {
			res = dp(s, sIndex, p, pIndex + 2) || // 忽略x*
				currentMatch && dp(s, sIndex + 1, p, pIndex); // 如果*前的字符匹配，则将s前进一位
		}
		else {
			res = currentMatch && dp(s, sIndex + 1, p, pIndex + 1);
		}
	}
	m[sIndex][pIndex] = res;
	return res;
}

int Solution::maxArea(vector<int>& height)
{
	int maxCapasity = 0;
	for(int i = 0;i<height.size();i++)
		for (int j = i+1; j < height.size(); j++)
		{
			int h = height[i] < height[j] ? height[i] : height[j];
			if (h * (j - i) > maxCapasity)
			{
				maxCapasity = h * (j - i);
			}
		}
	return maxCapasity;

}

int Solution::maxArea2(vector<int>& height)
{
	int maxCapasity = 0;
	int L = 0, R = height.size()-1;
	while (L < R)
	{
		if (height[L] < height[R])
		{
			maxCapasity = maxCapasity > height[L]*(R-L) ? maxCapasity : height[L]*(R-L);
			L++;
		}
		else
		{
			maxCapasity = maxCapasity > height[R]*(R-L) ? maxCapasity : height[R]*(R-L);
			R--;
		}
	}
	return maxCapasity;
}

//12
string Solution::intToRoman(int num)
{
	string r = "";
	if (num == 0)
		return r;
	vector<int> symbol = { 'I', 'V','X','L','C','D','M' };
	vector<int> value = {1, 5, 10, 50, 100, 500, 1000};
	int i;
	for (i = 0; i < 7 && num >= value[i]; i++)
		;
	//cout << num << " " << i << endl;
	if (i < 7) {
		if (i % 2 == 0) {
			if (num / (value[i] / 10) == 9) {
				r += symbol[i - 2];
				r += symbol[i];
				num %= (value[i] / 10);
			}
			else {
				r += symbol[i - 1];
				num -= value[i - 1];
			}
		}
		else {
			if (num / (value[i] / 5) == 4) {
				r += symbol[i - 1];
				r += symbol[i];
				num %= (value[i] / 5);
			}
			else {
				r += symbol[i - 1];
				num -= value[i - 1];
			}
		}
	}
	else {
		int n = num / value[6];
		num %= value[6];
		while (n--)
			r += 'M';
	}
	r += intToRoman(num);
	return r;
}
int Solution::romanToInt(string s) {
	if (s.empty())
		return 0;
	vector<int> symbol = { 'I', 'V','X','L','C','D','M' };
	vector<int> value = {1, 5, 10, 50, 100, 500, 1000};
	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		int j;
		for (j = 0; j < 7 && symbol[j] != s[i]; j++)
			;
		if (j % 2 == 0) {
			if (i + 1 < s.size() && j + 1 < 7 && s[i + 1] == symbol[j + 1]) {
				num += value[j + 1] - value[j];
				i++;
			}
			else if (i + 1 < s.size() && j + 2 < 7 && s[i + 1] == symbol[j + 2]) {
				num += value[j + 2] - value[j];
				i++;
			}
			else
				num += value[j];
		}
		else
			num += value[j];
	}
	return num;
}

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	vector<vector<int>> result;	
	for(int i=0;i< nums.size();i++)
		for(int j=i+1;j< nums.size();j++)
			for (int k = j+1; k < nums.size(); k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					vector<int> e = vector<int>(3);
					e[0] = nums[i];
					e[1] = nums[j];
					e[2] = nums[k];
					result.push_back(e);
				}
			}
	return result;
}

vector<vector<int>> Solution::threeSum2(vector<int>& nums)
{
	vector<vector<int>> result;
	unordered_map<int,int> mp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (mp.find(nums[i]) == mp.end())
			mp[nums[i]] = 1;
		else
			mp[nums[i]] ++;
	}
	unordered_map<int, int>::iterator iter1;
	unordered_map<int, int>::iterator iter2;
	vector<vector<int>>::iterator iter3;
	for (iter1 = mp.begin(); iter1 != mp.end();iter1++)
	{
		//cout << iter1->first <<" " <<iter1->second << endl;
		if (iter1->second >= 2)
		{
			int c = 0 - iter1->first - iter1->first;
			if (mp.find(c) != mp.end()&& (c != iter1->first) || ( c==iter1->first && iter1->second >= 3))
			{
				vector<int> e = vector<int>(3);
				e[0] = iter1->first;
				e[1] = iter1->first;
				e[2] = mp.find(c)->first;
				sort(e.begin(), e.end());
				int find = 0;
				for(int k =0;k<result.size();k++)
				{
					if (e[0] == result[k][0] && e[1] == result[k][1])
						find = 1;
				}
				if (find == 0)
					result.push_back(e);
			}
		}
		iter2 = iter1;
		iter2++;
		for (; iter2 != mp.end();iter2++)
		{
			int c = 0 - iter1->first - iter2->first;
			if ((c == iter1->first && iter1->second < 2) ||(c == iter2->first && iter2->second < 2))
				continue;
			if (mp.find(c) != mp.end())
			{
				vector<int> e = vector<int>(3);
				e[0] = iter1->first;
				e[1] = iter2->first;
				e[2] = mp.find(c)->first;
				sort(e.begin(), e.end());
				int find = 0;
				for(int k =0;k<result.size();k++)
				{
					if (e[0] == result[k][0] && e[1] == result[k][1])
						find = 1;
				}
				if (find == 0)
					result.push_back(e);
			}
		}
	}
	return result;
}

vector<vector<int>> Solution::threeSum3(vector<int>& nums)
{
	vector<vector<int>> results;
	int lp, rp;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size();i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		lp = i + 1;
		rp = nums.size() - 1;
		while (lp < rp)
		{
			if (nums[i] + nums[lp] + nums[rp] < 0)
				lp++;
			else if (nums[i] + nums[lp] + nums[rp] > 0)
				rp--;
			else
			{
				vector<int> r = { nums[i], nums[lp], nums[rp] };
				if (rp +1 >= nums.size()||(rp + 1 < nums.size() && nums[rp] != nums[rp + 1]))
					results.push_back(r);
				lp++;
				rp--;
			}
		}
	}
	return results;
}

//16
int Solution::threeSumClosest(vector<int>& nums, int target)
{
	if (nums.size() < 3)
		return 0;
	sort(nums.begin(), nums.end());
	int sum = nums[0] + nums[1] + nums[2];
	int d = sum - target;
	if (d < 0)
		d = -d;
	for (int i = 0; i + 2 < nums.size(); i++) {
		int lp = i + 1, rp = nums.size() - 1;
		while (lp < rp) {
			int currSum = nums[i] + nums[lp] + nums[rp];
			if (currSum == target)
				return currSum;
			else if (currSum < target) {
				if (target - currSum < d) {
					d = target - currSum;
					sum = currSum;
				}
				lp++;
			}
			else {
				if (currSum - target < d) {
					d = currSum - target;
					sum = currSum;
				}
				rp--;
			}
		}
	}
	return sum;
}
//17
vector<string> Solution::letterCombinations(string digits)
{
	vector<string> results;
	if (digits.size() == 0)
		return results;
	else
	{
		vector<string> r1 = letterDict(digits);
		if (digits.size() == 1)
			return r1;
		else
		{
			string digitsNew = digits.substr(1);
			vector<string> r2 = letterCombinations(digitsNew);
			for (int i = 0; i < r1.size(); i++)
				for (int j = 0; j < r2.size(); j++)
					results.push_back(r1[i] + r2[j]);
		}
	}
	return results;
}

vector<string> Solution::letterDict(string digits)
{
	vector<string> results;
	switch (digits[0])
	{
	case '2':
		results = {"a", "b", "c"};
		break;
	case '3':
		results = {"d", "e", "f"};
		break;
	case '4':
		results = {"g", "h", "i"};
		break;
	case '5':
		results = {"j", "k", "l"};
		break;
	case '6':
		results = {"m", "n", "o"};
		break;
	case '7':
		results = {"p", "q", "r", "s"};
		break;
	case '8':
		results = {"t", "u", "v"};
		break;
	case '9':
		results = {"w", "x", "y", "z"};
		break;
	default:
		break;
	}
	return results;
}
//18
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	if (!nums.size())
		return result;
	for (int k = 0; k < nums.size(); k++) {
		if (k > 0 && nums[k] == nums[k - 1])
			continue;
		for (int i = k+1; i < nums.size(); i++) {
			if (i > k+1 && nums[i] == nums[i - 1])
				continue;
			int lp = i + 1;
			int rp = nums.size() - 1;
			while (lp < rp) {
				if (nums[k] + nums[i] + nums[lp] + nums[rp] < target)
					lp++;
				else if (nums[k] + nums[i] + nums[lp] + nums[rp] > target)
					rp--;
				else {
					vector<int> r = { nums[k], nums[i], nums[lp], nums[rp] };
					if (rp + 1 >= nums.size() || (rp + 1 < nums.size() && nums[rp] != nums[rp + 1]))
						result.push_back(r);
					lp++;
					rp--;
				}
			}
		}
	}
	return result;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
	ListNode* p = head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	if (len == n)
	{
		if (head != NULL)
			head = head->next;
	}
	else
	{
		p = head;
		while (p != NULL)
		{
			if(len == n+1)
				p->next = p->next->next;
			p = p->next;
			len--;
		}
	}
	return head;
}

ListNode* Solution::removeNthFromEnd1(ListNode* head, int n) {
	vector<ListNode*> pList;
	ListNode* p = head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		pList.push_back(p);
		p = p->next;
	}
	if (len == n)
	{
		if (len > 1)
			return pList[1];
		else
			return NULL;
	}
	else
	{
		pList[len - n - 1]->next = pList[len - n]->next;
	}
	return head;
}
ListNode* Solution::removeNthFromEnd2(ListNode* head, int n) {
	if (!head)
		return NULL;
	ListNode* p1 = head;
	ListNode* p2 = head;
	while (p1 && n--)
		p1 = p1->next;
	if (p1 == NULL)
			return head->next;
	else {
		p1 = p1->next;
		while (p1 != NULL) {
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = p2->next->next;
	}
	return head;
}

string Solution::gcdOfStrings(string str1, string str2)
{
	string s="";
	if (str1.length() > str2.length())
	{
		s = str1;
		str1 = str2;
		str2 = s;
	}
	while (str1.length() != 0)
	{
		if (str2.compare(0, str1.length(),str1) != 0)
			break;
		else 
		{
			str2 = str2.substr(str1.length());
			if (str1.length() > str2.length())
			{
				s = str1;
				str1 = str2;
				str2 = s;
			}
		}
	}
	if (str1.length() == 0)
		s = str2;
	else
		s = "";
	return s;
}
bool Solution::isValid(string s)
{
	stack<char> st;
	string pattern = "([{)]}";
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '(':
		case '[':
		case '{':
			st.push(s[i]);
			break;
		case ')':
		case ']':
		case '}':
		{
			int j = pattern.find(s[i]);
			if (!st.empty() && st.top() == pattern[j - 3])
				st.pop();
			else
				return false;
		}
		default:
			break;
		}
	}
	if(st.empty())
		return true;
	return false;
}

//21
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* l0;
	ListNode* p0;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	if (l1 == NULL) {
		l0 = l2;
		return l0;
	}
	else if (l2 == NULL) {
		l0 = l1;
		return l0;
	}
	else {
		if (l1->val < l2->val)
		{
			l0 = l1;
			p1 = l1->next;
		}
		else
		{
			l0=l2;
			p2 = l2->next;
		}
		l0->next = NULL;
	}
	p0 = l0;
	while (p1 != NULL && p2 != NULL) {
		if (p1->val < p2->val) {
			p0->next = p1;
			p1 = p1->next;
		}
		else {
			p0->next = p2;
			p2 = p2->next;
		}
		p0 = p0->next;
	}
	while (p1 != NULL) {
		p0->next = p1;
		p1 = p1->next;
		p0 = p0->next;
	}
	while (p2!=NULL) {
		p0->next = p2;
		p2 = p2->next;
		p0 = p0->next;
	}
	return l0;
}

//22
vector<string> Solution::generateParenthesis(int n)
{
	vector<int> maxNum(n);
	vector<int> num(n, 0);
	num[n - 1] = n;
	vector<string> results;
	string s;
	bool finish = false;
	int sum;
	while (1) {
		// generate string
		s = "";
		for (int i = 0; i <n; i++) {
			s += '(';
			for (int j = 0; j < num[i]; j++) {
				s += ')';
			}
		}
		results.push_back(s);

		// generate next
		if (num[n - 1] > 1) {
			num[n - 1] --;
			num[n - 2] ++;
		}
		else {
			sum = 0;
			for (int i = 0; i < n; i++) {
				maxNum[i] = i + 1 - sum;
				sum += num[i];
			}
			int addIndex = -1;
			for (int i = n - 2; i >= 0; i--) {
				if (num[i] < maxNum[i]) {
					num[i]++;
					addIndex = i;
					break;
				}
			}
			if (addIndex < 0) {
				finish = 1;
				break;
			}
			for (int i = addIndex + 1; i < n - 1; i++)
				num[i] = 0;
			num[n - 1] =n - (addIndex + 1 - maxNum[addIndex] + num[addIndex]);

		}
		if (finish)
			break;
	}
	return results;
}


ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
	ListNode* l0 = NULL;
	int minIndex = -1;
	for (int i = 0; i < lists.size(); i++)
	{
		if ((lists[i] != NULL)&& (minIndex == -1 || lists[i]->val < lists[minIndex]->val))
				minIndex = i;
	}
	if (minIndex != -1)
	{
		l0 = lists[minIndex];
		lists[minIndex] = lists[minIndex]->next;
		l0->next = NULL;
	}
	ListNode* p0 = l0;
	while(minIndex != -1)
	{
		minIndex = -1;
		for (int i = 0; i < lists.size(); i++)
		{
			if ((lists[i] != NULL)&& (minIndex == -1 || lists[i]->val < lists[minIndex]->val))
					minIndex = i;
		}
		if (minIndex != -1)
		{
			p0->next = lists[minIndex];
			lists[minIndex] = lists[minIndex]->next;
			p0 = p0->next;
			p0->next = NULL;
		}
	}
	return l0;
}

ListNode* Solution::mergeKLists2(vector<ListNode*>& lists)
{
	ListNode* l0 = NULL;
	pair<int, int> p;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pr;
	for (int i = 0; i < lists.size(); i++)
	{
		if (lists[i] != NULL)
		{
			p = {lists[i]->val, i};
			pr.push(p);
		}
	}
	if (! pr.empty())
	{
		p = pr.top();
		pr.pop();
		int i = p.second;
		l0 = lists[i];
		lists[i] = lists[i]->next;
		l0->next = NULL;
		if (lists[i] != NULL)
		{
			p = {lists[i]->val, i};
			pr.push(p);
		}
	}
	ListNode* p0 = l0;
	while(! pr.empty())
	{
		p = pr.top();
		pr.pop();
		int i = p.second;
		p0->next = lists[i];
		lists[i] = lists[i]->next;
		p0 = p0->next;
		p0->next = NULL;
		if (lists[i] != NULL)
		{
			p = {lists[i]->val, i};
			pr.push(p);
		}
	}
	return l0;
}

//24
ListNode* Solution::swapPairs(ListNode* head)
{
	if (!head)
		return NULL;
	if (!head->next)
		return head;
	ListNode* p = head;
	head = head->next;
	p->next = swapPairs(head->next);
	head->next = p;
	return head;
}

//25
ListNode* Solution::reverseKGroup(ListNode* head, int k)
{
	ListNode* pSlow = NULL, * pMid = NULL, * pFast = NULL, * pEnd = head;
	for(int i = 1;i<k && pEnd;i++ ) {
		pEnd = pEnd->next;
	}
	if (!pEnd)
		return head;
	pSlow = reverseKGroup(pEnd->next, k);
	pMid = head;
	while(pMid != pEnd) {
		pFast = pMid->next;
		pMid->next = pSlow;
		pSlow = pMid;
		pMid = pFast;
	}
	pMid->next = pSlow;
	return pEnd;
}

//26
int Solution::removeDuplicates(vector<int>& nums)
{
	if (nums.size() <= 1)
		return nums.size();
	int le = 1, ri;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != nums[i - 1]) {
			nums[le] = nums[i];
			le++;
		}
	}
	return le;
}

//27
int Solution::removeElement(vector<int>& nums, int val)
{
	if (!nums.size())
		return nums.size();
	int i, j;
	for(i = 0, j = 0; i < nums.size(); i++) {
		if (nums[i] != val) {
			nums[j] = nums[i];
			j++;
		}
	}
	return j;
}

//28
int Solution::strStr(string haystack, string needle)
{
	//if (!needle.size())
	//	return 0;
	//for (int i = 0; i < haystack.size(); i++) {
	//	if (haystack[i] == needle[0]) {
	//		int match = 1;
	//		for (int j = 0; j < needle.size(); j++) {
	//			if (i + j >= haystack.size() || needle[j] != haystack[i + j]) {
	//				match = 0;
	//				break;
	//			}
	//		}
	//		if (match)
	//			return i;
	//	}
	//}
	//return -1;
	if (!needle.size())
		return 0;
	vector<int> mem;
	for (int i = 0; i < haystack.size(); i++) {
		if (haystack[i] == needle[0]) {
			int match = 1;
			for (int j = 0; j < needle.size(); j++) {
				if (i + j >= haystack.size() || needle[j] != haystack[i + j]) {
					match = 0;
					break;
				}
			}
			if (match)
				return i;
		}
	}
	return -1;
}

//29
int Solution::divide(int dividend, int divisor)
{
	int n = 0;
	int flag = 1;
	if (divisor < 0) {
		flag = -flag;
		divisor = -divisor;
	}
	else if (divisor == 0)
		return 0;
	if (dividend < 0) {
		flag = -flag;
		dividend = -dividend;
	}
	while (dividend >= divisor) {
		n++;
		dividend -= divisor;
	}
	return flag > 0 ? n : -n;

}

//31
void Solution::nextPermutation(vector<int>& nums)
{
	int i, le = -1, mi = nums.size() - 1;
	for (i = nums.size() - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			le = i - 1;
			break;
		}
	}
	ks.push_back(le);
	if (le >= 0)
	{
		for (i = nums.size() - 1; i >= 0; i--)
		{
			if(nums[i] > nums[le])
				break;
		}
		mi = i;
		i = nums[le];
		nums[le] = nums[mi];
		nums[mi] = i;
	}

	for (i = nums.size() - 1, ++le; i > le; i--, le++)
	{
		mi = nums[i];
		nums[i] = nums[le];
		nums[le] = mi;
	}
	return ;
}

//33
int Solution::search(vector<int>& nums, int target)
{
	if (nums.size() == 0)
		return -1;
	int le = 0, ri = nums.size(), mi = 0;
	while (le < ri) {
		mi = (le + ri) / 2;
		if (mi + 1 < nums.size() && nums[mi] > nums[mi + 1])
			break;
		else {
			if (nums[mi] >= nums[0])
				le = mi + 1;
			else
				ri = mi;
		}
	}
	if (target >= nums[0]) {
		le = 0;
		ri = mi + 1;
	}
	else {
		le = mi + 1;
		ri = nums.size();
	}
	while (le < ri) {
		mi = (le + ri) / 2;
		if (nums[mi] == target)
			return mi;
		else if (nums[mi] < target)
			le = mi + 1;
		else
			ri = mi;
	}
	return -1;
}

int Solution::biSearch(vector<int>& nums, int i, int j, int target)
{
	if (nums[i] < target)
		;
	return 0;


}
int singleNumber(vector<int>& nums)
{
	int n = nums[0];
	for(int i = 1;i<nums.size();i++)
		n ^= nums[i];
	return n;
}
int Solution::longestConsecutive(vector<int>& nums)
{
	unordered_map<int, int> mp;
	vector<int> back(nums.size(), -1);
	vector<int> front(nums.size(), -1);
	int maxLen = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (mp.find(nums[i]) == mp.end())
			mp[nums[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (mp.find(nums[i] + 1) != mp.end())
			front[i] = mp[nums[i] + 1];
		if (mp.find(nums[i] - 1) != mp.end())
			back[i] = mp[nums[i] - 1];
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (back[i] < 0)
		{
			int len = 1;
			for (int j = front[i]; j >= 0;)
			{
				len++;
				j = front[j];
			}
			if (len > maxLen)
				maxLen = len;
		}
	}
	return maxLen;
}

bool Solution::hasCycle(ListNode* head)
{
	ListNode* p1 = head;
	ListNode* p2 = head;
	unordered_map<ListNode*, int> mp;
	while (p1 != NULL and p1->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if (p1 == p2)
			return true;
	}
	return false;

}

bool Solution::hasCycle2(ListNode* head)
{
	ListNode* p = head;
	unordered_map<ListNode*, int> mp;
	while (p != NULL)
	{
		if (mp.find(p) != mp.end())
			return true;
		else
			mp[p] = 1;

		p = p->next;
	}
	return false;

}

bool Solution::wordBreak0(string s, vector<string>& wordDict)
{
	string sSub;
	int find;
	for (int i = 1; i <= s.size(); i++)
	{
		sSub = s.substr(0, i);
		find = 0;
		for (int j = 0; j < wordDict.size(); j++)
		{
			if (sSub.compare(wordDict[j]) == 0)
			{
				find = 1;
				break;
			}
		}
		if (!find)
		{
			continue;
		}
		else
		{
			if (i >= s.size())
				return true;
			else
			{
				sSub = s.substr(i);
				if(! wordBreak(sSub, wordDict))
					continue;
				else
					return true;
			}
		}
	}
	return false;
}

bool Solution::wordBreak(string s, vector<string>& wordDict)
{
	string sSub;
	int find;
	for (int i = 1; i <= s.size(); i++)
	{
		sSub = s.substr(0, i);
		if (mp139.find(sSub) == mp139.end())
		{
			mp139[sSub] = 0;
			for (int j = 0; j < wordDict.size(); j++)
			{
				if (sSub.compare(wordDict[j]) == 0)
				{
					mp139[sSub] = 1;
					break;
				}
			}
		}
		if(mp139[sSub] == 0)
		{
			continue;
		}
		else
		{
			if (i >= s.size())
				return true;
			else
			{
				sSub = s.substr(i);
				if (mp139.find(sSub) == mp139.end())
				{
					mp139[sSub] = wordBreak(sSub, wordDict);
				}
				if (mp139[sSub] == 0)
				{
					continue;
				}
				else
					return true;

			}
		}
	}
	return false;
}

void Solution::sortColors(vector<int>& nums)
{
	int l = 0, r = nums.size() - 1, temp;
	while (l < nums.size() && nums[l] == 0)
		l++;
	while (r >= 0 && nums[r] == 2)
		r--;
	for (int i = l; i <= r;)
	{
		if (nums[i] == 2)
		{
			temp = nums[i];
			nums[i] = nums[r];
			nums[r] = temp;
			r--;
			while (r >= 0 && nums[r] == 2)
				r--;
		}
		if (nums[i] == 0)
		{
			if (i > l)
			{
				temp = nums[i];
				nums[i] = nums[l];
				nums[l] = temp;
				l++;
			}
			while (l < nums.size() && nums[l] == 0) 
				l++;
		}
		if (i < l)
			i = l;
		else
			i++;
	}
	return;
}

vector<vector<int>> Solution::permute(vector<int>& nums)
{
	vector<int> nums0(nums);
	vector<vector<int>> results;
	results.push_back(nums);
	nextPermutation(nums);
	while (nums0 != nums)
	{
		results.push_back(nums);
		nextPermutation(nums);
	}
	return results;

}

vector<vector<int>> Solution::permute2(vector<int>& nums)
{
	vector<vector<int>> results;
	if (nums.size() <= 1)
		results.push_back(nums);
	else
	{
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> numsSub;
			for (int j = 0; j < nums.size(); j++)
			{
				if (j != i)
					numsSub.push_back(nums[j]);
			}
			vector<vector<int>> resultsSub = permute(numsSub);
			vector<int> r;
			for (int k = 0; k < resultsSub.size(); k++)
			{
				r.push_back(nums[i]);
				r.insert(r.end(), resultsSub[k].begin(), resultsSub[k].end());
				results.push_back(r);
				r.clear();
			}
		}
	}
	return results;
}

void Solution::rotate(vector<vector<int>>& matrix)
{
	int temp;
	int n = matrix.size();
	for (int i = 0; i < (n+1)/2; i++)
		for (int j = 0; j < n/2; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = temp;
		}
	return;
}

bool Solution::canJump(vector<int>& nums)
{
	int left = nums.size()-1;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		if (i + nums[i] >= left)
		{
			left = i;
		}
	}
	if (left <= 0)
		return true;
	else
		return false;
}

int Solution::maximalRectangle(vector<vector<char>>& matrix)
{
	int m = matrix.size(), n = 0;
	if (m > 0)
		n = matrix[0].size();
	vector<vector<int>> right(m, vector<int>(n, 0));
	vector<vector<int>> area(m, vector<int>(n, 0));
	for(int i = 0;i < m;i++)
		for (int j = n - 1;j >= 0; j--)
		{
			if (matrix[i][j] != '0')
			{
				if (j + 1 < n)
					right[i][j] = right[i][j + 1] + 1;
				else
					right[i][j] = 1;
			}
		}
	int h, w, s;
	for(int i = 0;i < m;i++)
		for (int j = n - 1; j >= 0; j--)
		{
			h = 0;
			w = right[i][j];
			s = 0;
			for (int k = 0; w > 0 && i+k < m; k++)
			{
				h = k+1;
				if (right[i + k][j] < w)
					w = right[i + k][j];
				if (s < h * w)
					s = h * w;
			}
			area[i][j] = s;
		}
	s = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (area[i][j] > s)
				s = area[i][j];
			cout << matrix[i][j] << " " << right[i][j] << " " << area[i][j] << "  ";
		}
		cout << endl;
	}
	return s;
}

int Solution::maxSubArray0(vector<int>& nums)
{
	int maxSum;
	if (nums.size() <= 0)
		maxSum = 0;
	else
	{
		maxSum = nums[0];
		for (int i = 0; i < nums.size();i++)
		{
			if ( nums[i] > 0)
			{
				int s = 0;
				while (i < nums.size() && s>=0)
				{
					s += nums[i];
					if (s > maxSum)
						maxSum = s;
					i ++;
				}
				i--;
			}
			else
			{
				if (maxSum < 0 && nums[i]>maxSum)
				{
					maxSum = nums[i];
				}
			}
		}
	}
	return maxSum;
}

int Solution::maxSubArray(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	else
	{
		int n = nums.size();
		int m1, m2;
		vector<int> nums1(nums.begin(), nums.begin() + n/2);
		vector<int> nums2(nums.begin() + n/2, nums.end());
		m1 = maxSubArray(nums1);
		m2 = maxSubArray(nums2);
		if (m1 > 0 && m2 > 0)
			return m1 + m2;
		else
			return m1 > m2 ? m1 : m2;
	}
	return 0;
}

int Solution::climbStairs(int n)
{
	int m, l=1,r=2;
	if (n == 1)
		return l;
	if (n == 2)
		return r;
	for (int i = 3; i <= n; i++)
	{
		m = l + r;
		l = r;
		r = m;
	}
	return m;
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs)
{
	vector < vector<string> > results;
	//vector <string> pattern;
	unordered_map<string, int> pattern;
	for (int i = 0, j = 0; i < strs.size(); i++)
	{
		string sPat(strs[i]);
		sort(sPat.begin(), sPat.end());
		//int find = 0;
		//for (int j = 0; j < results.size(); j++)
		//{
		//	if (sPat.compare(pattern[j]) == 0)
		//	{
		//		results[j].push_back(strs[i]);
		//		find = 1;
		//		break;
		//	}
		//}
		if (pattern.find(sPat) == pattern.end())
		{
			vector<string> sRes;
			sRes.push_back(strs[i]);
			results.push_back(sRes);
			pattern[sPat] = j;
			j++;
		}
		else
			results[pattern[sPat]].push_back(strs[i]);
	}
	return results;
}

int Solution::majorityElement(vector<int>& nums)
{
	unordered_map<int, int> mp;
	int i;
	for (i = 0; i < nums.size(); i++)
	{
		if (mp.find(nums[i]) == mp.end())
			mp[nums[i]] = 1;
		else
			mp[nums[i]] ++;
		if (mp[nums[i]] >= (nums.size() + 1) / 2)
			break;
	}
	return nums[i];
}

int Solution::hammingDistance(int x, int y)
{
	int z = x ^ y, n = 0;
	while (z != 0)
	{
		n += z & 1;
		z = z >> 1;
	}
	return n;

}

vector<int> Solution::countBits(int num)
{
	vector<int> result(num+1, 0);
	for(int i = 0;i <= num;i++)
	{
		int n = i;
		while (n != 0)
		{
			result[i] += n & 1;
			n = n >> 1;
		}
	}
	return result;
}

void Solution::moveZeroes(vector<int>& nums)
{
	int left = 0, temp;
	while (left < nums.size() && nums[left] != 0)
		left++;
	for (int i = left; i < nums.size(); i++)
	{
		if (i>left && nums[i] != 0)
		{
			temp = nums[i];
			nums[i] = nums[left];
			nums[left] = temp;
			left++;
		}
	}
	return;
}

vector<int> Solution::topKFrequent(vector<int>& nums, int k)
{
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (mp.find(nums[i]) == mp.end())
			mp[nums[i]] = 1;
		else
			mp[nums[i]] ++;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int,int> > > pr;
	for (unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
	{
		pair<int, int> p = {iter->second, iter->first};
		pr.push(p);
	}
	vector<int> results;
	for (int i = 0; i < k; i++)
	{
		pair<int, int> p = pr.top();
		results.push_back(p.second);
		pr.pop();
	}
	return results;
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals)
{
	sort(intervals.begin(), intervals.end());
	vector<vector<int> > results;
	for (int i = 0, j = -1; i < intervals.size(); i++)
	{
		if (j < 0 || intervals[i][0] > results[j][1])
		{
			results.push_back(intervals[i]);
			j++;
		}
		else if (intervals[i][0] <= results[j][1] && intervals[i][1] > results[j][1])
			results[j][1] = intervals[i][1];
	}
	return results;
}

int Solution::uniquePaths(int m, int n)
{
	//vector<vector<int> > dp(m, vector<int>(n, 0));
	//for(int i = m-1;i>=0;i--)
	//	for (int j = n-1; j >= 0; j--)
	//	{
	//		if (i == m - 1 || j == n - 1)
	//			dp[i][j] = 1;
	//		else
	//			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
	//		
	//	}
	//return dp[0][0];


	//vector<int> down(n-1, 1);
	//int right = 1;
	//for (int i = m - 2; i >= 0; i--)
	//{
	//	right = 1;
	//	for (int j = n - 2; j >= 0; j--)
	//	{
	//		right += down[j];
	//		down[j] = right;
	//	}
	//}
	//return right;
	double result = 1;
	while (--m)
	{
		result *= (m + n -1);
		result /= m;
		
	}
	return (int)result;

}

int Solution::minPathSum(vector<vector<int>>& grid)
{
	int n, m = grid.size();
	if (m > 0)
		n = grid[0].size();
	vector<vector<int> > dp(grid);
	for(int i = m-1;i>=0;i--)
		for (int j = n-1; j >= 0; j--)
		{
			if (i == m - 1 && j == n - 1)
				dp[i][j] = grid[i][j];
			else if (i == m - 1 && j != n - 1)
				dp[i][j] = grid[i][j] + dp[i][j + 1];
			else if (i != m - 1 && j == n - 1)
				dp[i][j] = grid[i][j] + dp[i + 1][j];
			else
				dp[i][j] = grid[i][j] + (dp[i + 1][j] < dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1]);
		}
	return dp[0][0];
}

int Solution::minDistance(string word1, string word2)
{
	int m = word1.size(), n = word2.size();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for(int i = m;i>=0;i--)
		for (int j = n; j >= 0; j--)
		{
			if (i == m)
				dp[i][j] = n - j;
			else if (j == n)
				dp[i][j] = m - i;
			else
			{
				if (word1[i] == word2[j])
					dp[i][j] = dp[i + 1][j + 1];
				else
				{
					dp[i][j] = min(dp[i + 1][j + 1] + 1, dp[i + 1][j] + 1);
					dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
				}
			}
		}
	return dp[0][0];
}

int Solution::largestRectangleArea(vector<int>& heights)
{
//int Solution::largestRectangleArea(vector<int>& heights)
//{
//	return dc(heights, 0, heights.size());
//}
//
//int Solution::dc(vector<int>& heights, int le, int ri)
//{
//	if (ri == 0)
//		return 0;
//	if (le >= ri - 1)
//		return heights[le];
//	int area,  mi = le;
//	for (int i = le; i < ri; i++)
//		if (heights[i] < heights[mi])
//			mi = i;
//	area = heights[mi] * (ri - le);
//	if (mi > le)
//		area = max(area, dc(heights, le, mi));
//	if (mi < ri - 1)
//		area = max(area, dc(heights, mi +1, ri));
//	return area;
//}
	int area = 0;
	if (heights.size() == 0)
		return area;
	vector<int> areas(heights.size(), 0);
	stack<int> st;
	int i, j;
	st.push(-1);
	st.push(0);
	for (i = 1; i < heights.size(); i++)
	{
		if (heights[i-1] <= heights[i])
		{
			st.push(i);
		}
		else
		{
			j = st.top();
			while (j!=-1 && heights[j] > heights[i])
			{
				st.pop();
				areas[j] = (i - 1 - st.top()) * heights[j];
				j = st.top();
			}
			st.push(i);
		}
	}
	while (st.top() != -1)
	{
		j = st.top();
		st.pop();
		areas[j] = (heights.size()-1 - st.top()) * heights[j];
	}
	for (int i = 0; i < areas.size(); i++)
		if (areas[i] > area)
			area = areas[i];
	return area;
}

int Solution::trap(vector<int>& height)
{
	if (height.size() == 0)
		return 0;
	int result = 0;
	int maxIndex = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (height[i] > height[maxIndex])
			maxIndex = i;
	}
	int currentMax=0;
	for (int i = 0; i < maxIndex; i++)
	{
		if (height[i] > currentMax)
			currentMax = height[i];
		result += currentMax - height[i];
	}
	currentMax = 0;
	for (int i = height.size() - 1; i > maxIndex; i--)
	{
		if (height[i] > currentMax)
			currentMax = height[i];
		result += currentMax - height[i];
	}
	return result;
}

vector<int> Solution::searchRange(vector<int>& nums, int target)
{
	vector<int> result = {-1, -1};
	int le = 0, ri = nums.size(), mi = -1;
	while (le < ri)
	{
		mi = (le + ri) / 2;
		if (nums[mi] == target)
			break;
		else if (nums[mi] < target)
			le = mi + 1;
		else if (nums[mi] > target)
			ri = mi;
	}
	if (mi>=0 && nums[mi] == target)
	{
		le = -1;
		ri = mi;
		while (le < ri)
		{
			mi = (le + ri + 1) / 2;
			if (nums[mi] == target && (mi-1<0 || nums[mi-1]!=target))
				break;
			else if (nums[mi] < target)
				le = mi;
			else
				ri = mi-1;
		}
		result[0] = mi;
		le = mi;
		ri = nums.size();
		while (le < ri)
		{
			mi = (le + ri) / 2;
			if (nums[mi] == target && (mi+1 >= nums.size() || nums[mi+1]!=target))
				break;
			else if (nums[mi] > target)
				ri = mi;
			else
				le = mi+1;
		}
		result[1] = mi;
	}
	return result;
}

vector<vector<int>> Solution::subsets(vector<int>& nums)
{
	vector<vector<int>> results;
	if (nums.size() <= 0)
		results.push_back(nums);
	else
	{
		vector<int> numsNew(nums.begin()+1, nums.end());
		vector<vector<int>> resultsNew = subsets(numsNew);
		results = resultsNew;
		vector<int> currentResult = { nums[0] };
		//results.push_back(currentResult);
		for (int i = 0; i < resultsNew.size(); i++)
		{
			currentResult = { nums[0] };
			currentResult.insert(currentResult.end(), resultsNew[i].begin(), resultsNew[i].end());
			results.push_back(currentResult);
		}
	}
	return results;
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int> > results,  currentResults;
	vector<int> front, currentCandidates, currentResult;
	int sum = 0, currentTarget;
	for (int i = 0; i < candidates.size(); i++)
	{
		currentCandidates = vector<int>(candidates.begin() + i + 1, candidates.end());
		front = {candidates[i]};
		sum = candidates[i];
		while (sum <= target)
		{
			currentTarget = target - sum;
			if (currentTarget == 0)
			{
				results.push_back(front);
				break;
			}
			else
			{
				currentResults = combinationSum(currentCandidates, currentTarget);
				if (currentResults.size() > 0)
				{
					for (int j = 0; j < currentResults.size(); j++)
					{
						currentResult = front;
						currentResult.insert(currentResult.end(), currentResults[j].begin(), currentResults[j].end());
						results.push_back(currentResult);
					}
				}
			}
			front.push_back(candidates[i]);
			sum += candidates[i];
		}
	}
	return results;
}

string Solution::minWindow(string s, string t)
//string minWindow(string s, string t)
//{
//	unordered_map<char, int> mp;
//	for (int j = 0; j < t.size(); j++)
//	{
//		if (mp.find(t[j]) == mp.end())
//			mp[t[j]] = -1;
//	}
//	string result = "";
//	int left, find = 0;
//	char leftChar;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (mp.find(s[i]) != mp.end())
//		{
//			mp[s[i]] = i;
//			leftChar = s[i];
//			left = i;
//			for (unordered_map<char, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
//			{
//				if (iter->second <= left)
//				{
//					leftChar = iter->first;
//					left = iter->second;
//				}
//			}
//			if (left > -1)
//			{
//				if (find == 0 || (i - left + 1 < result.size()))
//				{
//					result = s.substr(left, i - left + 1);
//					find = 1;
//				}
//				mp[leftChar] = -1;
//			}
//		}
//	}
//	return result;
//}
{
	struct tItem{
		int n;
		queue<int> q;
	};
	unordered_map<char, tItem> mp;
	for (int j = 0; j < t.size(); j++)
	{
		if (mp.find(t[j]) == mp.end())
		{
			mp[t[j]].n = 1;
			mp[t[j]].q = queue<int>();
		}
		else
		{
			mp[t[j]].n++;
		}
	}
	string result = "";
	int left, find = 0;
	char leftChar;

	for (int i = 0; i < s.size(); i++)
	{
		if (mp.find(s[i]) != mp.end())
		{
			mp[s[i]].q.push(i);
			if (mp[s[i]].q.size() > mp[s[i]].n)
			{
				mp[s[i]].q.pop();
			}
			leftChar = s[i];
			left = i;
			for (unordered_map<char, tItem>::iterator iter = mp.begin(); iter != mp.end(); iter++)
			{
				if (iter->second.q.size() < iter->second.n)
				{
					left = -1;
					break;
				}
				if (iter->second.q.front() <= left)
				{
					leftChar = iter->first;
					left = iter->second.q.front();
				}
			}
			if (left > -1)
			{
				if (find == 0 || i - left + 1 < result.size())
				{
					result = s.substr(left, i - left + 1);
					find = 1;
				}
				mp[leftChar].q.pop();
			}
		}
	}
	return result;
}

string Solution::minWindow1(string s, string t) {
	unordered_map<char, int> mp;
	for (auto c : t) mp[c]++;
	int left = 0, cnt = 0, maxlen = s.size() + 1, start = left;
	for (int i = 0; i < s.size(); ++i) {
		if (mp.find(s[i]) != mp.end()) {
			mp[s[i]]--;
			if (mp[s[i]] >= 0)
				++cnt;
		}
		while (cnt == t.size()) {
			if (maxlen > i - left + 1) {
				maxlen = i - left + 1;
				start = left;
			}
			if (mp.find(s[left]) != mp.end())
				cnt--;
			left++;

		}
	}
	return maxlen == s.size() + 1 ? "" : s.substr(start, maxlen);
}

bool Solution::exist(vector<vector<char>>& board, string word)
{
	if (word.size() == 0 || board.size() == 0)
		return false;
	bool r = false;
	vector<vector<bool>> mem = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), 0));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			// mem = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), 0));
			r = existHelper(board, word, mem, i, j);
			if (r)
				return r;
		}
	}
	return r;
}

bool Solution::existHelper(vector<vector<char>>& board, string word, vector < vector<bool>> &mem, int i, int j)
{
	if (word.size() == 0)
		return true;
	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
		return false;
	bool r = false;
	if (mem[i][j] == 0 && board[i][j] == word[0])
	{
		mem[i][j] = 1;
		r = existHelper(board, word.substr(1), mem, i + 1, j) ||
		 existHelper(board, word.substr(1), mem, i - 1, j) ||
		 existHelper(board, word.substr(1), mem, i, j - 1) ||
		 existHelper(board, word.substr(1), mem, i, j + 1);
		mem[i][j] = 0;
	}
	return r;
}

//可重复使用的情况
bool Solution::exist1(vector<vector<char>>& board, string word)
{
	if (word.size() == 0 || board.size() == 0)
		return false;
	vector<vector<int>> mem0 = vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
	vector<vector<int>> mem1 = vector<vector<int>>(board.size(), vector<int>(board[0].size(), -1));
	for (int k = 0; k < word.size(); k++)
	{
		cout << k << endl;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if ((board[i][j] == word[k]) && ((i - 1 >= 0 && mem0[i - 1][j] == k - 1) ||
					(i + 1 < board.size() && mem0[i + 1][j] == k - 1) ||
					(j - 1 >= 0 && mem0[i][j - 1] == k - 1) ||
					(j + 1 < board[0].size() && mem0[i][j + 1] == k - 1)))
				{
					mem1[i][j] = k;
					if (mem1[i][j] == word.size() - 1)
						return true;
				}
				cout << mem0[i][j] << " " << mem1[i][j] << "  ";
			}
			cout << endl;
		}
		mem0 = mem1;
	}
	return false;
}

int Solution::longestValidParentheses(string s)
{
	stack<int> leftSt;
	leftSt.push(-1);
	int maxLen = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			leftSt.push(i);
		else {
			leftSt.pop();
			if (leftSt.empty())
				leftSt.push(i);
			else
				maxLen = i - leftSt.top() > maxLen ? i - leftSt.top() : maxLen;
		}
	}
	return maxLen;
}

int Solution::longestValidParentheses1(string s)
{
	stack<int> leftSt;
	stack<pair<int, int>> regionSt;
	pair<int, int> currentRegion, lastRegion;
	int start, end, maxLen = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			leftSt.push(i);
		else {
			if (leftSt.empty())
				continue;
			else {
				currentRegion = pair<int, int>(leftSt.top(), i);
				leftSt.pop();
				while (1) {
					if(regionSt.empty())
						break;
					lastRegion = regionSt.top();
					if (currentRegion.first < lastRegion.first) {
						regionSt.pop();
					}
					else if (lastRegion.second + 1 == currentRegion.first) {
						currentRegion.first = lastRegion.first;
						regionSt.pop();
					}
					else
						break;
				}
				regionSt.push(currentRegion);

				if (currentRegion.second - currentRegion.first + 1 > maxLen) {
					maxLen = currentRegion.second - currentRegion.first + 1;
				}
			}
		}
	}
	return maxLen;
}

vector<int> Solution::inorderTraversal1(TreeNode* root)
{
	vector<int> results, subResults;
	if (root == NULL)
		return results;
	TreeNode* currNode = root;
	stack<TreeNode *> nodeStack;
	stack<int> stateStack;
	nodeStack.push(root);
	stateStack.push(0);
	while (!nodeStack.empty())
	{
		if (stateStack.top() == 0)
		{
			stateStack.top() = 1;
			if (nodeStack.top()->left)
			{
				nodeStack.push(nodeStack.top()->left);
				stateStack.push(0);
			}
		}
		else if (stateStack.top() == 1)
		{
			results.push_back(nodeStack.top()->val);
			stateStack.top() = 2;
			if (nodeStack.top()->right)
			{
				nodeStack.push(nodeStack.top()->right);
				stateStack.push(0);
			}
		}
		else if (stateStack.top() == 2)
		{
			nodeStack.pop();
			stateStack.pop();
		}
	}
	return results;
}

vector<int> Solution::inorderTraversal(TreeNode* root)
{
	vector<int> results, subResults;
	if (root == NULL)
		return results;
	if (root->left != NULL)
	{
		subResults = inorderTraversal(root->left);
		results.insert(results.end(), subResults.begin(), subResults.end());
	}
	results.push_back(root->val);
	if (root->right!= NULL)
	{
		subResults = inorderTraversal(root->right);
		results.insert(results.end(), subResults.begin(), subResults.end());
	}
	return results;
}

bool Solution::isValidBST(TreeNode* root)
{
	if (!root)
		return true;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	bool result = true;
	if(left)
	{
		result = result && isValidBST(left);
		while (left->right)
			left = left->right;
		result = result && left->val < root->val;
	}
	if(right)
	{
		result = result && isValidBST(right);
		while (right->left)
			right = right->left;
		result = result && right->val > root->val;
	}
	return result;
}

int numTrees(int n)
{
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			dp[i] += dp[j - 1] * dp[i - j];
	}
	return dp[n];

	//if (n == 0)
	//	return 1;
	//int sum = 0;
	//for (int i = 1; i <= n; i++)
	//{
	//	sum += numTrees(i - 1) * numTrees(n - i);
	//}
	//return sum;
}

void Solution::flatten(TreeNode* root)
{
	if (!root)
		return;
	TreeNode* right = root->right;
	TreeNode* left = root->left;
	if (root->right)
	{
		flatten(root->right);
	}
	if (root->left)
	{
		flatten(root->left);
		root->right = left;
		root->left = NULL;
		while (left->right)
			left = left->right;
		left->right = right;
	}
	return;
}

int Solution::maxProfit(vector<int>& prices)
{
	int profit = 0, buyIndex = 0;
	for (int i = 0; i < prices.size(); i++) {
		if(prices[i] < prices[buyIndex])
			buyIndex = i;
		profit = prices[i] - prices[buyIndex] > profit ? prices[i] - prices[buyIndex] : profit;
	}
	return profit;
	//int profit = 0, buyIndex = -1;
	//for (int i = 0; i < prices.size(); i++) {
	//	if (buyIndex == -1 && i+1 < prices.size() && prices[i] < prices[i + 1]) {
	//		buyIndex = i;
	//	}
	//	if (buyIndex > -1)
	//	{
	//		if(prices[i] < prices[buyIndex])
	//			buyIndex = i;
	//		profit = prices[i] - prices[buyIndex] > profit ? prices[i] - prices[buyIndex] : profit;
	//	}
	//}
	//return profit;
}

bool Solution::isSymmetric(TreeNode* root)
{
	if (!root)
		return true;
	else
		return isSymmetricHelper(root->left, root->right);
	return false;
}
    
bool Solution::isSymmetricHelper(TreeNode* root1, TreeNode* root2)
{
	if (!root1 && !root2)
		return true;
	else if (root1 && root2)
	{
		return root1->val == root2->val &&
			isSymmetricHelper(root1->left, root2->right) &&
			isSymmetricHelper(root1->right, root2->left);
	}
	else
		return false;
}

bool Solution::isSymmetric1(TreeNode* root)
{
	if (!root)
		return true;
	return false;
}

int Solution::maxDepth(TreeNode* root)
{
	return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
}

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
	vector<vector<int>> results;
	if (!root)
		return results;
	vector<TreeNode*> list;
	list.push_back(root);
	int le = 0, ri = 1, i, j, k = 0;
	while (le < ri)
	{
		results.push_back(vector<int>());
		j = 0;
		for (i = le; i < ri; i++)
		{
			results[k].push_back(list[i]->val);
			if (list[i]->left)
			{
				list.push_back(list[i]->left);
				j++;
			}
			if (list[i]->right)
			{
				list.push_back(list[i]->right);
				j++;
			}
		}
		le = ri;
		ri += j;
		k++;
	}
	return results;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	TreeNode * root = NULL;
	if(!preorder.size())
		return root;
	int i, rootVal = preorder[0];
	for (i = 0; i < inorder.size(); i++)
		if (inorder[i] == rootVal)
			break;
	vector<int> leftPre;
	vector<int> leftIno;
	vector<int> rightPre;
	vector<int> rightIno;
	if (i > 0)
	{
		leftPre.insert(leftPre.begin(), preorder.begin() + 1, preorder.begin() + i + 1);
		leftIno.insert(leftIno.begin(), inorder.begin(), inorder.begin() + i);
	}
	if (i < preorder.size() - 1)
	{
		rightPre.insert(rightPre.begin(), preorder.begin() + i + 1, preorder.end());
		rightIno.insert(rightIno.begin(), inorder.begin() + i + 1, inorder.end());
	}
	root = new TreeNode(rootVal);
	root->left = buildTree(leftPre, leftIno);
	root->right = buildTree(rightPre, rightIno);
	return root;
}

int Solution::maxPathSum(TreeNode* root)
{
	if (!root)
		return 0;
	int path = root->val;
	if(maxPathSumHelper(root->left) > 0)
		path += maxPathSumHelper(root->left);
	if(maxPathSumHelper(root->right) > 0)
		path += maxPathSumHelper(root->right);
	if(root->left)
		path = max(maxPathSum(root->left),path);
	if(root->right)
		path = max(maxPathSum(root->right),path);
	return path;
}

int Solution::maxPathSumHelper(TreeNode* root)
{
	if (!root)
		return 0;
	int len = root->val;
	if(maxPathSumHelper(root->left) > 0 || maxPathSumHelper(root->right)>0)
		len = root->val + max(maxPathSumHelper(root->left), maxPathSumHelper(root->right));
	return len;
}

ListNode* Solution::detectCycle(ListNode* head)
{
	ListNode* start = NULL;
	ListNode* curr = head;
	unordered_map<ListNode*, int> mp;
	while (curr) {
		if (mp.find(curr) == mp.end()) {
			mp[curr] = 1;
			curr = curr->next;
		}
		else {
			start = curr;
			break;
		}
	}
	return start;
}

//160
ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB)
{
	//ListNode* common = NULL;
	//if (!headA || !headB)
	//	return NULL;
	//if (headA == headB)
	//	return headA;
	//common = getIntersectionNode(headA->next, headB);
	//if (!common)
	//	common = getIntersectionNode(headB->next, headA);
	//return common;
	ListNode* pA = headA;
	ListNode* pB = headB;
	ListNode* p = NULL;
	while (pA && pB) {
		pA = pA->next;
		pB = pB->next;
	}
	if (pA) {
		p = headA;
		pB = headB;
		while (pA) {
			pA = pA->next;
			p = p->next;
		}
		while (pB != p) {
			pB = pB->next;
			p = p->next;
		}
	}
	else if (pB) {
		p = headB;
		pA = headA;
		while (pB) {
			pB = pB->next;
			p = p->next;
		}
		while (pA != p) {
			pA = pA->next;
			p = p->next;
		}
	}
	else {
		pA = headA;
		pB = headB;
		while (pA != pB) {
			pA = pA->next;
			pB = pB->next;
		}
		p = pA;
	}
	return p;
}

int Solution::maxProduct(vector<int>& nums)
{
	if (!nums.size())
		return 0;
	int currMax= nums[0], currMin = nums[0], maxPr = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == 0) {
			currMax = 0;
			currMin = 0;
		}
		else if(nums[i] > 0) {
			if (currMax > 0 && currMin > 0) {
				currMax = currMax * nums[i];
				currMin = nums[i];
			}
			else if (currMax > 0 && currMin <= 0) {
				currMax = currMax * nums[i];
				currMin = currMin * nums[i];
			}
			else {
				currMin = currMin * nums[i];
				currMax = nums[i];
			}

		}
		else {
			if (currMax <= 0) {
				currMax = currMin * nums[i];
				currMin = nums[i];
			}
			else if (currMax > 0 && currMin > 0) {
				currMin = currMax * nums[i];
				currMax = nums[i];
			}
			else {
				int t = currMax;
				currMax = currMin * nums[i];
				currMin = t * nums[i];
			}
		}
		// cout << currMax << " " << currMin << "   ";
		if (currMax > maxPr)
			maxPr = currMax;
	}
	return maxPr;
}

int Solution::numSquares(int n)
{
	//if (n <= 0)
	//	return 0;
	//int num = n, maxIndex = 0, curr;
	//while (maxIndex * maxIndex <= n)
	//	maxIndex++;
	//while (--maxIndex) {
	//	if (n - maxIndex * maxIndex > 0) {
	//		curr = 1 + numSquares(n - maxIndex * maxIndex);
	//		if (curr < num)
	//			num = curr;
	//	}
	//	else {
	//		num = 1;
	//		break;
	//	}
	//}
	//return num;

	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	int num = n, minNum = n, maxIndex = 0, currNum;
	for (int i = 1; i <= n; i++)
	{
		maxIndex = 0;
		while (maxIndex * maxIndex <= i)
			maxIndex++;
		dp[i] = i;
		while (--maxIndex)
			dp[i] = (1 + dp[i - maxIndex * maxIndex]) < dp[i] ? (1 + dp[i - maxIndex * maxIndex]): dp[i];
	}
	return dp[n];
}

int Solution::rob(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); i++)
		dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
	return dp[nums.size() - 1];
}

int Solution::numIslands(vector<vector<char>>& grid)
{
	if (!grid.size() || !grid[0].size())
		return 0;
	int m = grid.size(), n = grid[0].size(), num = 0;
	vector<vector<int>> mem(m, vector<int>(n, -1));
	for(int i = 0;i < m;i++)
		for (int j = 0; j < n; j++) {
			if (mem[i][j] == -1 and grid[i][j] == 1) {
				num++;
				numIslandsHelper(grid, mem, i, j);
			}
		}
	return num;
}

void Solution::numIslandsHelper(vector<vector<char>>& grid, vector<vector<int>>& mem, int i, int j)
{
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || mem[i][j] == 1 || grid[i][j] == '0')
		return;
	mem[i][j] = 1;
	numIslandsHelper(grid, mem, i - 1, j);
	numIslandsHelper(grid, mem, i + 1, j);
	numIslandsHelper(grid, mem, i, j - 1);
	numIslandsHelper(grid, mem, i, j + 1);
	return;
}

ListNode* Solution::reverseList(ListNode* head)
{
	ListNode* curr = head;
	ListNode* newHead = NULL;
	ListNode* last;
	while (curr) {
		last = curr;
		curr = curr->next;
		last->next = newHead;
		newHead = last;
	}
	return newHead;
}

ListNode* Solution::reverseList1(ListNode* head)
{
	if (!head)
		return NULL;
	if (!head->next)
		return head;
	ListNode* curr = head;
	ListNode* tail = head->next;
	ListNode* newHead = reverseList1(tail);
	tail->next = curr;
	curr->next = NULL;
	return newHead;
}

//215
int Solution::findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < nums.size(); i++) {
		if (q.size() < k)
			q.push(nums[i]);
		else if (nums[i] > q.top()) {
			q.pop();
			q.push(nums[i]);
		}
	}
	return q.top();
}

int Solution::coinChange(vector<int>& coins, int amount)
{
	if (!coins.size())
		return -1;
	vector<int> dp(amount+1, -1);
	dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < coins.size(); j++) {
			if(i >= coins[j] && dp[i-coins[j]] >= 0 && 
				(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1))
				dp[i] = dp[i - coins[j]] + 1;
		}
	}
	return dp[amount];

}

vector<int> Solution::findDisappearedNumbers(vector<int>& nums)
{
	vector<int> results;
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] > 0)
			nums[nums[i] - 1] = nums[nums[i] - 1] < 0 ? nums[nums[i] - 1] : -nums[nums[i] - 1];
		else
			nums[-nums[i] - 1] = nums[-nums[i] - 1] < 0 ? nums[-nums[i] - 1] : -nums[-nums[i] - 1];
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] > 0)
			results.push_back(i+1);
	return results;
}

//234
bool Solution::isPalindrome(ListNode* head)
{
	vector<int> nums;
	while (head){
		nums.push_back(head->val);
		head = head->next;
	}
	int n = nums.size();;
	for (int i = 0; i < n / 2; i++)
	{
		if (nums[i] != nums[n - 1 - i])
			return false;
	}
	return true;
}

int Solution::findUnsortedSubarray(vector<int>& nums)
{
	if (!nums.size())
		return 0;
	int n = nums.size();
	int left, right;
	for (left = 1; left < n && nums[left] >= nums[left - 1]; left++)
		;
	for (right = n - 2; right >= 0 && nums[right] <= nums[right + 1]; right--)
		;
	for (int i = left-1; i <= right+1&&i<n; i++) {
		if (left-1 >= 0 && nums[i] < nums[left - 1]) {
			while (left - 1 >= 0 && nums[left - 1] > nums[i])
				left--;
		}
		if (right + 1 < n && nums[right + 1] < nums[i]) {
			while (right + 1 < n && nums[right + 1] < nums[i])
				right++;
		}
	}
	return max(right - left + 1, 0);
}

//394
string Solution::decodeString(string s)
{
	stack<int> numStack;
	stack<int> indexStack;
	string result = "";
	int num = 0;
	for (int i = 0, j = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			num = num * 10 + s[i] - '0';
		}
		else if (s[i] == '[') {
			numStack.push(num);
			indexStack.push(j);
			num = 0;
		}
		else if (s[i] == ']') {
			int n = numStack.top();
			int index = indexStack.top();
			int end = j;
			numStack.pop();
			indexStack.pop();
			n--;
			while (n>0)
			{
				result += result.substr(index, end - index);
				j += end - index;
				n--;
			}
		}
		else {
			result.insert(result.end(), s[i]);
			j++;
		}
	}
	return result;
}

//437
int Solution::pathSum(TreeNode* root, int sum)
{
	if (!root)
		return 0;
	return pathSum(root->left, sum) + pathSum(root->right, sum)
		+ pathSumHelper(root, sum);
}

int Solution::pathSumHelper(TreeNode* root, int sum)
{
	int num = 0;
	if (sum == root->val)
		num++;
	if (root->left)
		num += pathSumHelper(root->left, sum - root->val);
	if (root->right)
		num += pathSumHelper(root->right, sum - root->val);
	return num;
}

int Solution::diameterOfBinaryTree(TreeNode* root)
{
	if (!root)
		return 0;
	int d = 0;
	d = max(diameterOfBinaryTree(root->left), d);
	d = max(diameterOfBinaryTree(root->right), d);
	if(root->left && root->right)
		d = max(1+ diameterOfBinaryTreeHelper(root->left) + 1 + diameterOfBinaryTreeHelper(root->right), d);
	else if(root->left && !root->right)
		d = max(1 + diameterOfBinaryTreeHelper(root->left), d);
	else if(!root->left && root->right)
		d = max(1 + diameterOfBinaryTreeHelper(root->right), d);
	return d;
}

int Solution::diameterOfBinaryTreeHelper(TreeNode* root)
{
	if (!root)
		return 0;
	int dep = 0;
	if(root->left)
		dep = max(diameterOfBinaryTreeHelper(root->left) + 1, dep);
	if(root->right)
		dep = max(diameterOfBinaryTreeHelper(root->right) + 1, dep);
	return dep;
}

int Solution::lengthOfLIS(vector<int>& nums)
{
	if (!nums.size())
		return 0;
	vector<int> leftIndex(nums.size());
	vector<int> maxLength(nums.size());
	int result = 0;
	for (int i = 0; i < nums.size(); i++) {
		leftIndex[i] = i;
		maxLength[i] = 1;
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j] && maxLength[j] + 1 > maxLength[i]) {
				leftIndex[i] = leftIndex[j];
				maxLength[i] = maxLength[j] + 1;
			}
		}
		cout << leftIndex[i]<<" "<<maxLength[i]<<"  ";
		result = max(result, maxLength[i]);
	}
	return result;

}

int Solution::lengthOfLIS1(vector<int>& nums)
{
	if (!nums.size())
		return 0;
	unordered_map<int, int> leftIndex;
	unordered_map<int, int> maxLength;
	int result = 0;
	for (int i = 0; i < nums.size(); i++) {
		leftIndex[i] = i;
		maxLength[i] = 1;
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j] && maxLength[j] + 1 > maxLength[i]) {
				leftIndex[i] = leftIndex[j];
				maxLength[i] = maxLength[j] + 1;
			}
		}
		result = max(result, maxLength[i]);
	}
	return result;
}

TreeNode* Solution::convertBST(TreeNode* root)
{
	int sum = convertBSTHelper(root, 0);
	return root;
}

int Solution::convertBSTHelper(TreeNode* root, int sum)
{
	if (!root)
		return 0;
	if (root->right)
		sum = convertBSTHelper(root->right, sum);
	root->val += sum;
	sum = root->val;
	if (root->left)
		sum = convertBSTHelper(root->left, sum);
	return sum;
}

//617
TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2)
{
	if (!t1)
		return t2;
	if (!t2)
		return t1;
	t1->val += t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;
}

TreeNode* Solution::invertTree(TreeNode* root)
{
	if (!root)
		return root;
	TreeNode* left = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(left);
	return root;
}

vector<int> Solution::productExceptSelf(vector<int>& nums)
{
	vector<int> result(nums.size(), 1);
	int product = 1;
	for (int i = 1; i < nums.size(); i++) {
		product *= nums[i - 1];
		result[i] *= product;
	}
	product = 1;
	for (int i = nums.size() - 2; i >= 0;i--) {
		product *= nums[i + 1];
		result[i] *= product;
	}
	return result;
}

int Solution::findDuplicate(vector<int>& nums)
{
	if (!nums.size())
		return -1;
	for (auto num : nums) {
		num = num > 0 ? num : -num;
		if (nums[num] < 0)
			return num;
		nums[num] *= -1;
	}
	return -1;
}

//739
vector<int> Solution::dailyTemperatures(vector<int>& T)
{
	vector <int> result(T.size(), 0);
	if (!T.size())
		return result;
	stack<int> st;
	for (int i = 0;i < T.size();i++) {
		while (!st.empty() && T[i] > T[st.top()]) {
			result[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	return result;
}

vector<int> Solution::dailyTemperatures1(vector<int>& T)
{
	vector <int> result(T.size(), 0);
	if (!T.size())
		return result;
	int left, right;
	//for (int i = 0; i < T.size(); i++)
	//{
	//	if()
	//}
	return result;
}

//236
TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root)
		return root;
	if (lowestCommonAncestorHelper(root->left, p) && lowestCommonAncestorHelper(root->left, q))
		return lowestCommonAncestor(root->left, p, q);
	else if (lowestCommonAncestorHelper(root->right, p) && lowestCommonAncestorHelper(root->right, q))
		return lowestCommonAncestor(root->right, p, q);
	else
		return root;
}

bool Solution::lowestCommonAncestorHelper(TreeNode* root, TreeNode* p)
{
	if (!root)
		return false;
	if (!p)
		return false;
	if (root->val == p->val)
		return true;
	return lowestCommonAncestorHelper(root->left, p) || lowestCommonAncestorHelper(root->right, p);
}

TreeNode* Solution::lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root)
		return root;
	vector<TreeNode*> nodes;
	vector<int> nodeIndex;
	nodes.push_back(root);
	nodeIndex.push_back(1);
	int le = 0, ri = 1;
	int findP = 0, findQ = 0;
	while(le<ri)
	{
		if (nodes[le]->val == p->val)
			findP = nodeIndex[le];
		if (nodes[le]->val == q->val)
			findQ = nodeIndex[le];
		if (findP && findQ)
			break;
		if (nodes[le]->left)
		{
			nodes.push_back(nodes[le]->left);
			nodeIndex.push_back(nodeIndex[le] * 2);
			ri++;
		}
		if (nodes[le]->right)
		{
			nodes.push_back(nodes[le]->right);
			nodeIndex.push_back(nodeIndex[le] * 2 + 1);
			ri++;
		}
		le++;
	}
	cout<<"i : " << findP << "  " << findQ << endl;
	if (!findP || !findQ)
		return NULL;
	int id = 1;
	le = 1;
	while (findP > id) {
		id = id * 2 + 1;
		le++;
	}
	id = 1;
	ri = 1;
	while (findQ > id) {
		id = id * 2 + 1;
		ri++;
	}
	cout<<"c : " << le << "  " << ri << endl;

	while (le > ri)
	{
		le --;
		findP /= 2;
	}
	while (le < ri)
	{
		ri--;
		findQ /= 2;
	}
	cout<<"i same : " << findP << "  " << findQ << endl;
	cout <<"c same : " << le << "  " << ri << endl;
	while (findP != findQ)
	{
		findP /= 2;
		findQ /= 2;
	}
	cout<<"i end: " << findP << "  " << findQ << endl;
	for (le = 0; le < nodeIndex.size(); le++)
		if (nodeIndex[le] == findP)
			break;
	return nodes[le];
}

bool Solution::lowestCommonAncestor1Helper(TreeNode* root, TreeNode* p)
{
	if (!root)
		return false;
	if (!p)
		return false;
	int n = 1;
	if (root->val == p->val)
		return true;
	return lowestCommonAncestorHelper(root->left, p) || lowestCommonAncestorHelper(root->right, p);
}

//235
TreeNode* Solution::lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root)
		return root;
	if (root->val == p->val || root->val == q->val)
		return root;
	if (root->val < p->val && root->val > q->val)
		return root;
	if (root->val > p->val && root->val < q->val)
		return root;
	if (root->val > p->val && root->val > q->val)
		return lowestCommonAncestor0(root->right, p, q);
	if (root->val < p->val && root->val < q->val)
		return lowestCommonAncestor0(root->left, p, q);
}

int Solution::countSubstrings(string s)
{
	if (!s.size())
		return 0;
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	for (int len = 0; len < s.size(); len++)
		for (int i = 0; i + len < s.size(); i++)
		{
			if(len == 0)
				dp[i][i + len] = 1;
			else
			{
				if (s[i] == s[i + len] &&(len == 1 || dp[i + len - 1][i + 1] == 1))
					dp[i + len][i] = 1;
				dp[i][i + len] = 2 + dp[i + 1][i + len - 1] + dp[i + len][i];
			}
		}
	return dp[0][s.size() - 1];
}

int Solution::countSubstrings1(string s)
{
	int i = 0, j = 0, R = 0, C = 0, L = 0, maxLength = -1;
	vector<int> p(2*s.size()+2, 0);
	string sNew("#");
	int result = 0;
	for (i = 0, j = 0; i < s.length(); i++, j+=2) {
		sNew.append(1, s[i]);
		sNew.append(1, '#');
	}
	for (i = 0; i < sNew.length(); i++)
	{
		int k = 0;
		j = 2 * C - i;
		if (i >= R)
		{
			for (k = 0; ((i + k < sNew.length() && (i - k >= 0)) && (sNew[i + k] == sNew[i - k])); k++)
				;
			p[i] = k;
			if (i + k - 1 > R)
			{
				R = i + k - 1;
				C = i;
				L = 2 * C - R;
			}
		}
		else
		{
			if (j - p[j] + 1 < L)
			{
				p[i] = R - i + 1;
			}
			else if (j - p[j] + 1 > L)
			{
				p[i] = p[j];
			}
			else
			{
				for (k = p[j] - 1; ((i + k < sNew.length() && (i - k >= 0)) && (sNew[i + k] == sNew[i - k])); k++)
					;
				p[i] = k;
				if (i + k - 1 > R) {
					R = i + k - 1;
					C = i;
					L = 2 * C - R;
				}
			}
		}
		result += (p[i]+1)/2;
	}
	return result;
}

ListNode* Solution::sortList(ListNode* head)
{
	ListNode* curr = head;
	vector<int> values;
	while (curr) {
		values.push_back(curr->val);
		curr = curr->next;
	}
	sort(values.begin(), values.end());
	curr = head;
	for (auto val : values)
	{
		curr->val = val;
		curr = curr->next;
	}
	return head;
}

//399
vector<double> Solution::calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	vector<double> results;
	for (int i = 0; i < queries.size(); i++)
	{
		for (int j = 0; j < equations.size(); j++)
		{
			if (queries[i][0] == equations[j][0] && queries[i][1] == equations[j][1])
				results.push_back(values[j]);
			else if (queries[i][0] == equations[j][1] && queries[i][1] == equations[j][0])
				results.push_back(1.0 / values[j]);
			else if (queries[i][0] == equations[j][0] && queries[i][1] == equations[j][0])
				results.push_back(1);
			else if (queries[i][0] == equations[j][1] && queries[i][1] == equations[j][1])
				results.push_back(1);
		}
		results.push_back(-1);
	}
	return results;
}

//239
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> results;
	if (!nums.size() || k == 0)
		return results;
	if (k == 1)
		return nums;

	vector<int> left(nums);
	int curMax;
	for (int i = 0; i < nums.size(); i++) {
		if (i % k == 0) {
			curMax = nums[i];
		}
		else {
			curMax = curMax > nums[i] ? curMax : nums[i];
		}
		left[i] = curMax;
		cout << curMax << " ";
	}
	cout << endl;

	vector<int> right(nums);
	for (int i = nums.size() - 1; i >= 0; i--){
		if (i == nums.size() - 1 || (i + 1) % k == 0) {
			curMax = nums[i];
		}
		else {
			curMax = curMax > nums[i] ? curMax : nums[i];
		}
		right[i] = curMax;
		cout << curMax << " ";
	}
	cout << endl;

	for (int i = k - 1; i < nums.size(); i++) {
		if (i == nums.size() - 1 || (i + 1) % k == 0) {
			results.push_back(left[i]);
		}
		else {
			results.push_back(right[i - k + 1] > left[i] ? right[i - k + 1] : left[i]);
		}
	}
	return results;
}

int Solution::maxProfit2(vector<int>& prices)
{
	int lastBuy = 0, lastSell = 0, maxPr= 0;
	for (int i = 1; i < prices.size(); i++) {
		maxPr += max(0, prices[i] - prices[i - 1]);
		//if (prices[i] > prices[lastSell]) {
		//	maxPr += prices[i] - prices[lastSell];
		//	lastSell = i;
		//}
		//else {
		//	lastBuy = i;
		//	lastSell = i;
		//}
	}
	return maxPr;
}

int Solution::maxProfit5(vector<int>& prices)
{
	if (!prices.size())
		return 0;
	vector<int> dpStart(prices.size(), 0);
	vector<int> dpMax(prices.size(), 0);
	for (int i = prices.size() - 2; i >= 0; i--) {
		for (int j = i + 1; j < prices.size(); j++) {
			dpStart[i] = max(dpStart[i], prices[j] - prices[i] + (j + 2 < prices.size() ? dpMax[j + 2] : 0));
		}
		dpMax[i] = max(dpMax[i + 1], dpStart[i]);
		cout << prices[i]<< " " << dpStart[i] << "  ";
	}
	return dpMax[0];
}

vector<vector<int>> Solution::reconstructQueue(vector<vector<int>>& people)
{
	list<vector<int>> results;
	list<vector<int>>::iterator it;
	vector<vector<int>> result;
	int i;
	if (!people.size())
		return result;
	sort(people.begin(), people.end(), reconstructQueueSortKey);
	for (auto person : people)
	{
		cout << person[0] << " " << person[1] << "  ";
		for (i = 0, it = results.begin(); it != results.end() && i < person[1]; it++, i++)
			;
		results.insert(it, 1, person);
	}
	for (auto item : results)
		result.push_back(item);
	return result;
}

bool reconstructQueueSortKey(vector<int> person1, vector<int> person2)
{
	return person1[0] > person2[0] || (person1[0] == person2[0] && person1[1] <= person2[1]);
}

unordered_map<TreeNode *, int> noRootMax;
unordered_map<TreeNode *, int> rootMax;
unordered_map<TreeNode *, int> allMax;
int Solution::rob(TreeNode* root)
{
	if (!root)
		return 0;
	if (allMax.find(root) != allMax.end())
		return allMax[root];
	allMax[root] = max(robNoRoot(root), robRoot(root));
	return allMax[root];
}

int Solution::robRoot(TreeNode* root)
{
	if (!root)
		return 0;
	if (rootMax.find(root) != rootMax.end())
		return rootMax[root];
	rootMax[root] = root->val + robNoRoot(root->left) + robNoRoot(root->right);
	return rootMax[root];
}

int Solution::robNoRoot(TreeNode* root)
{
	if (!root)
		return 0;
	if (noRootMax.find(root) != noRootMax.end())
		return noRootMax[root];
	noRootMax[root] = rob(root->left) + rob(root->right);
	return noRootMax[root];
}

//倾斜对角线
bool Solution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (!matrix.size() || !matrix[0].size())
		return false;
	return searchMatrixHelper(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
}

bool Solution::searchMatrixHelper(vector<vector<int>>& matrix, int target,  int up0, int down0, int left0, int right0)
{
	//cout << "diedai: " << up0 <<" "<<down0<<" " <<left0 <<" "<< right0<< endl;
	if (down0 < up0 || right0 < left0)
		return false;
	if (matrix[up0][left0] > target || matrix[down0][right0] < target)
		return false;
	if (matrix[down0][right0] == target)
		return true;
	if (left0 == right0 && up0 == down0) {
		return matrix[up0][left0] == target;
	}
	int left = left0, right = right0, up = up0, down = down0;
	int middleHorizontal, middleVertical, mid;
	while (left< right || up < down) {
		middleHorizontal = (left + right) / 2;
		middleVertical = (up + down) / 2;
	//	cout << "in: "<<middleVertical << " " << middleHorizontal << endl;
		if (matrix[middleVertical][middleHorizontal] == target)
			return true;
		else if (matrix[middleVertical][middleHorizontal] > target) {
			right = middleHorizontal;
			down = middleVertical;
		}
		else {
			if(left < right)
				left = middleHorizontal + 1;
			if(up < down)
				up = middleVertical + 1;
		}
	};
	if (matrix[middleVertical][middleHorizontal] < target)
		return searchMatrixHelper(matrix, target, middleVertical + 1, down0 , left0, middleHorizontal)||
			searchMatrixHelper(matrix, target, up0, middleVertical, middleHorizontal + 1, right0);
	else
		return searchMatrixHelper(matrix, target, middleVertical, down0 , left0, middleHorizontal - 1)||
			searchMatrixHelper(matrix, target, up0, middleVertical - 1, middleHorizontal, right0);
	return false;
			//left = 0;
			//right = middleHorizontal;
			//while (left < right) {
			//	mid = (left + right) / 2;
			//	if (matrix[middleVertical][mid] == target)
			//		return true;
			//	else if (matrix[middleVertical][mid] > target)
			//		right = mid;
			//	else
			//		left = mid + 1;
			//}
			//up = 0;
			//down = middleVertical;
			//while (up < down) {
			//	mid = (up + down) / 2;
			//	if (matrix[mid][middleHorizontal] == target)
			//		return true;
			//	else if (matrix[mid][middleHorizontal] > target)
			//		down = mid;
			//	else
			//		up = mid + 1;
			//}
}

bool Solution::canPartition(vector<int>& nums)
{
	if (!nums.size())
		return 0;
	int sum = 0;
	for (auto i : nums)
		sum += i;
	if (sum % 2 == 1)
		return 0;
	sum /= 2;
	vector<vector<int>> dp(nums.size(), vector<int>(sum+1, 0));
	int target = 0;
	while (target <= sum) {
		for (int i = 0; i < nums.size(); i++) {
			if (0 == target|| target == nums[i] ||(i>0 && dp[i-1][target] == 1) || (i>0 && target >= nums[i] && dp[i-1][target - nums[i]])){
				dp[i][target] = 1;
			}
		}
		target++;
	}
	return dp[nums.size()-1][sum];
}

int Solution::subarraySum(vector<int>& nums, int k)
{
	if (!nums.size())
		return 0;
	if (nums.size() == 1)
		return nums[0] == k;
	vector<int> numsNew(nums.begin()+1, nums.end());
	int sum = subarraySum(numsNew, k);
	sum += subarraySumHelper(numsNew, k - nums[0]);
	if (nums[0] == k)
		sum += 1;
	if (nums[0] == 0)
		sum += subarraySumHelper(numsNew, k);
	cout<<"main: "<<nums.size()<<" "<<k<<" " << sum << endl;
	return sum;
}

int Solution::subarraySumHelper(vector<int>& nums, int k)
{
	if (nums.size() == 1)
		return nums[0] == k;
	vector<int> numsNew(nums.begin()+1, nums.end());
	int sum = 0;
	if(nums[0] == k)
		sum = 1 + subarraySumHelper(numsNew, 0);
	else
		sum = subarraySumHelper(numsNew, k - nums[0]);
	cout<<"help :"<<nums.size()<<" "<<k<<" " << sum << endl;
	return sum;
}

int Solution::subarraySum1(vector<int>& nums, int k)
{
	if (!nums.size())
		return 0;
	unordered_map<int, int> dpSum;
	int sum = 0, result = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			sum = nums[0];
			dpSum[sum] = 1;
			if (k  == sum)
				result++;
		}
		else {
			sum += nums[i];
			if (sum == k)
				result++;
			if (dpSum.find(sum - k) != dpSum.end())
				result += dpSum[sum - k];
			if (dpSum.find(sum) != dpSum.end())
				dpSum[sum] ++;
			else
				dpSum[sum] = 1;
		}
	}
	return result;
}

//494
int Solution::findTargetSumWays(vector<int>& nums, int S)
{
	if (!nums.size())
		return 0;
	if (nums.size() == 1)
		return S == nums[0] + S == -nums[0];
	else
		return findTargetSumWaysHelper(nums, S, nums.size());

}
int Solution::findTargetSumWaysHelper(vector<int>& nums, int S, int i)
{
	if (i == 1)
		return S == nums[0] + S == -nums[0];
	return findTargetSumWaysHelper(nums, S - nums[i - 1], i-1) + 
		findTargetSumWaysHelper(nums, S + nums[i - 1], i-1);
}

vector<int> Solution::findAnagrams(string s, string p)
{
	vector<int> result;
	if (!s.size() || !p.size())
		return result;
	unordered_map<char, int> mp;
	for (int i = 0; i < p.size(); i++) {
		if (mp.find(p[i]) == mp.end())
			mp[p[i]] = 1;
		else
			mp[p[i]] ++;
	}

	unordered_map<char, int> currMp(mp);
	int left = 0, n = p.size();
	for (int i = 0; i < s.size(); i++) {
		if (currMp.find(s[i]) == currMp.end()) {
			currMp = mp;
			n = p.size();
			left = i+1;
		}
		else if (currMp[s[i]] == 0) {
			while (s[left] != s[i]) {
				currMp[s[left]] ++;
				n++;
				left++;
			}
			left++;
		}
		else {
			currMp[s[i]] --;
			n--;
			if (n == 0) {
				result.push_back(left);
				currMp[s[left]] ++;
				n++;
				left++;
			}
		}
	}
	return result;
}

//221
int Solution::maximalSquare(vector<vector<char>>& matrix)
{
	if (!matrix.size() || !matrix[0].size())
		return 0;
	int maxL = 0, m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	for(int i = 0;i < m;i++)
		for (int j = 0; j < n;j++) {
			if (matrix[i][j] != '0') {
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
					dp[i][j] += 1;
				}
				if (maxL < dp[i][j])
					maxL = dp[i][j];
			}
		}
	return maxL*maxL;
}

//297
string Solution::serialize(TreeNode* root) {
	if (!root)
		return "[]";
	string s = "[", temp;
	stringstream ss;
	vector<TreeNode*> nodes0;
	vector<TreeNode*> nodes1;
	nodes0.push_back(root);
	int size = 1, find = 0, lastFind;
	while (find >= 0) {
		lastFind = find;
		find = -1;
		cout << lastFind << " " << size << " " << nodes0.size() << endl;
		for (int i = 0; i < size; i++) {
			if (!nodes0[i]) {
				if(i < lastFind || 0 <= find)
					s += "null,";
				nodes1.push_back(NULL);
				nodes1.push_back(NULL);
			}
			else {
				if(nodes0[i]->left)
					find = i*2;
				if(nodes0[i]->right)
					find = i*2+1;
				ss.clear();
				ss << nodes0[i]->val;
				ss >> temp;
				s += temp;
				s += ",";
				nodes1.push_back(nodes0[i]->left);
				nodes1.push_back(nodes0[i]->right);
			}
		}
		size = 2 * size;
		nodes0 = nodes1;
		nodes1.clear();
	}
	s[s.size() - 1] = ']';
	cout << s << endl;
	return s;
}

TreeNode* Solution::deserialize(string data)
{
	if (data.size() < 3)
		return NULL;
	TreeNode* root;
	stringstream ss;
	vector<TreeNode*> nodes;
	string s;
	int num, sign = 1;
	ss << data;
	for(int i = 0;i<data.size();i++)
	{
		if (data[i] == '-')
			sign = -1;
		else if (data[i] == '+')
			sign = 1;
		else if (data[i] >= '0' && data[i] <= '9') {
			num = 0;
			while (data[i] != ',' && data[i] != ']') {
				num  += num * 10 + data[i] - '0';
				i++;
			}
			num *= sign;
			cout << num <<" ";
			TreeNode* node = new TreeNode(num);
			nodes.push_back(node);
			num = 0;
			sign = 1;
		}
		else if (data[i] == 'n')
		{
			nodes.push_back(NULL);
			while (data[i] != ',')
				i++;
		}
		else if (data[i] == ' ' || data[i] == '[')
			continue;
		else 
			break;
		if (nodes[nodes.size() - 1])
			cout << nodes[nodes.size() - 1]->val << " " << endl;
		else
			cout << "null " << endl;
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		if (i > 0 && i % 2 == 1 && nodes[(i-1) / 2])
			nodes[(i - 1) / 2]->left = nodes[i];
		else if (i > 0 && i % 2 == 0 && nodes[(i - 2) / 2])
			nodes[(i - 2) / 2]->right= nodes[i];
	}
	root = nodes[0];
	return root;
}

void Solution::deleteNode(ListNode* node)
{
	node->val = node->next->val;
	node->next = node->next->next;
	return;
}

void Solution::reverseString(vector<char>& s)
{

	for (int i = 0; i < s.size() / 2; i++) {
		char c = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = c;
	}
	return;

}

string Solution::reverseWords(string s)
{
	int le = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == ' ') {
			for (int j = le; j < (i + le) / 2; j++) {
				char c = s[j];
				s[j] = s[i + le - 1- j];
				s[i + le - 1 - j] = c;
			}
			le = i + 1;
		}
	}
	return s;
}

bool Solution::canWinNim(int n)
{
	return n % 4 != 0;

}

bool Solution::isPalindrome(int x)
{
	if (x < 0)
		return false;
	long int m = x, n = 0;
	while (m != 0) {
		n = n * 10 + m % 10;
		m /= 10;
	}
	return n == x;
}

bool Solution::containsDuplicate(vector<int>& nums)
{
	if (!nums.size())
		return false;
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++)
	{
		if (mp.find(nums[i]) != mp.end())
			return false;
		mp[nums[i]] = 1;
	}
	return true;
}

bool Solution::isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;
	while (n > 0) {
		if (n == 1 || n % 2 == 0)
			n /= 2;
		else
			return false;
	}
	return true;

}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for (int i = m + n - 1, j = m - 1, k = n - 1; i >= 0; i--) {
		if (k < 0 || (j>=0 && nums1[j] >= nums2[k])) {
			nums1[i] = nums1[j];
			j--;
		}
		else {
			nums1[i] = nums2[k];
			k--;
		}
	}
	return;
}

string Solution::longestCommonPrefix(vector<string>& strs)
{
	string s = "";
	if (!strs.size())
		return s;
	for (int i = 0; i < strs[0].size(); i++) {
		char c = strs[0][i];
		int find = 1;
		for (int j = 0; j < strs.size(); j++) {
			if (strs[j][i] != c)
				find = 0;
		}
		if (find == 0)
			break;
		else
			s += c;
	}
	return s;
}


vector<vector<int>> Solution::generateMatrix(int n)
{
	vector<vector<int>> result(n, vector<int>(n, 0));
	int i = 0, j = 0, num = 1;
	for (int m = n; m > 0; m -= 1, j++) {
		if (m == n) {
			result[i][j] = num;
			break;
		}
		for (; j < m; j++, num++)
			result[i][j] = num;
		for (; i < m; i++, num++)
			result[i][j] = num;
		for (; j >= 0; j--, num++)
			result[i][j] = num;
		for (; i >= 0; i--, num++)
			result[i][j] = num;
	}
	return result;
}
