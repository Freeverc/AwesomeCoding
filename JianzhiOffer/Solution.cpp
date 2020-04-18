#define _CRT_SECURE_NO_WARNINGS
#include "Solution.h"

bool Solution::Find(int target, vector<vector<int> > array)
{
	if(!array.size() || !array[0].size())
		return 0;
	int m = array.size();
	int n = array[0].size();
	int i = m - 1, j = 0;
	while (i >= 0 && j < n) {
		if (array[i][j] == target)
			return 1;
		else if (array[i][j] > target)
			i--;
		else
			j++;
	}
	return 0;
}

void Solution::replaceSpace(char* str, int length) {
	if (!str)
		return;
	string s = "";
	s.reserve(length * 3);
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			s += "%20";
		else
			s += str[i];
	}
	strcpy(str, s.c_str());
	return;
}

vector<int> Solution::printListFromTailToHead(ListNode* head)
{
	vector<int> result;
	ListNode* curr = head;
	while (curr) {
		result.push_back(curr->val);
		curr = curr->next;
	}
	for (int i = 0; i < result.size() / 2; i++) {
		int t = result[i];
		result[i] = result[result.size() - 1 - i];
		result[result.size() - 1 - i] = t;
	}
	return result;
}

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	TreeNode* root;
	if (pre.size() == 0)
		return NULL;
	root = new TreeNode(pre[0]);
	int i;
	for (i = 0; i < vin.size(); i++)
		if (vin[i] == pre[0])
			break;
	if (i > 0) {
		vector<int> preLeft(pre.begin() + 1, pre.begin() + 1 + i);
		vector<int> vinLeft(vin.begin(), vin.begin() + i);
		root->left = reConstructBinaryTree(preLeft, vinLeft);
	}
	if (i < vin.size() - 1) {
		vector<int> preRight(pre.begin() + i + 1, pre.end());
		vector<int> vinRight(vin.begin() + i + 1, vin.end());
		root->right = reConstructBinaryTree(preRight, vinRight);
	}
	return root;
}

int Solution::minNumberInRotateArray(vector<int> rotateArray)
{
	if (!rotateArray.size())
		return 0;
	int le = 0, ri = rotateArray.size();
	int mi = (le + ri) / 2, find = 0, m = rotateArray[0];
	if (rotateArray[mi] != rotateArray[0]) {
		while (le < ri) {
			mi = (le + ri) / 2;
			if (mi + 1 < rotateArray.size() && rotateArray[mi] > rotateArray[mi + 1])
				return rotateArray[mi + 1];
			else if (rotateArray[mi] >= rotateArray[le])
				le = mi + 1;
			else
				ri = mi;
		}
	}
	else {
		while (le < ri) {
			if (rotateArray[le] < m)
				m = rotateArray[le];
			le++;
		}
	}
	return m;
}

int Solution::Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n < 3)
		return 1;
	int a = 1, b = 1, c;
	n -= 2;
	while (n--) {
		b = a + b;
		a = b - a;
	}
	return b;
}

int Solution::jumpFloor(int number)
{
	if (number < 2)
		return 1;
	int a = 1, b = 1, c;
	number--;
	while (number--) {
		b = a + b;
		a = b - a;
	}
	return b;
}

int Solution::jumpFloorII(int number)
{
	vector<int> dp(number + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= number; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += dp[i - j];
		}
	}
	return dp[number];
}

int Solution::rectCover(int number)
{
	if (number == 0)
		return 0;
	int a = 1, b = 1;
	while(--number) {
		b = a + b;
		a = b - a;
	}
	return b;
}

int Solution::NumberOf1(int n)
{
	//int num = 0;
	//while (n != 0) {
	//	num++;
	//	n = n & (n - 1);
	//}
	int num = 0;
	while (n != 0) {
		num += n & 1;
		n = n >> 1;
	}
	return num;
}

double Solution::Power(double base, int exponent)
{
	double result = 1;
	if (base == 0)
		return 0;
	else {
		if (exponent >= 0) {
			while (exponent--)
				result *= base;
		}
		else {
			exponent = -exponent;
			while (exponent--)
				result *= base;
			result = 1 / result;
		}
	}
	return result;
}

void Solution::reOrderArray(vector<int>& array)
{
	vector<int> array1;
	vector<int> array2;
	for (int i : array) {
		if (i % 2 == 1)
			array1.push_back(i);
		else
			array2.push_back(i);
	}
	int i;
	for (i = 0; i < array1.size(); i++)
		array[i] = array1[i];
	for (int j = 0; j < array2.size(); j++, i++)
		array[i] = array2[j];
	return;
}

ListNode* Solution::FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode* p1 = pListHead;
	ListNode* p2 = pListHead;
	while (p1 && k--)
		p1 = p1->next;
	if (k > 0 && !p1)
		return NULL;
	while (p1) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

ListNode* Solution::ReverseList(ListNode* pHead)
{
	if (!pHead)
		return NULL;
	ListNode* p1 = pHead->next;
	ListNode* p2 = pHead;
	ListNode* p3 = NULL;
	while (p1) {
		p2->next = p3;
		p3 = p2;
		p2 = p1;
		p1 = p1->next;
	}
	p2->next = p3;
	return p2;
}

ListNode* Solution::Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (!pHead1)
		return pHead2;
	if (!pHead2)
		return pHead1;
	ListNode* pHead;
	if (pHead1->val < pHead2->val) {
		pHead = pHead1;
		pHead1 = pHead1->next;
	}
	else {
		pHead = pHead2;
		pHead2 = pHead2->next;
	}
	ListNode* curr = pHead;
	while (pHead1 && pHead2) {
		if (pHead1->val < pHead2->val) {
			curr->next = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			curr->next = pHead2;
			pHead2 = pHead2->next;
		}
		curr = curr->next;
	}
	if (pHead1)
		curr->next = pHead1;
	if (pHead2)
		curr->next = pHead2;
	return pHead;
}

bool Solution::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1 || !pRoot2)
		return false;
	return HasSubtreeHelper(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

bool Solution::HasSubtreeHelper(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;
	if (!pRoot2->left && !pRoot2->right)
		return true;
	else if (pRoot2->left && !pRoot2->right)
		return HasSubtreeHelper(pRoot1->left, pRoot2->left);
	else if (!pRoot2->left && pRoot2->right)
		return HasSubtreeHelper(pRoot1->right, pRoot2->right);
	else if (pRoot2->left && pRoot2->right)
		return HasSubtreeHelper(pRoot1->left, pRoot2->left) && HasSubtreeHelper(pRoot1->right, pRoot2->right);
}

void Solution::Mirror(TreeNode* pRoot)
{
	if(!pRoot)
		return;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
	TreeNode* temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	return;
}

vector<int> Solution::printMatrix(vector<vector<int> > matrix)
{
	vector<int> result;
	if (!matrix.size() || !matrix[0].size())
		return result;
	int m = matrix.size(), n = matrix[0].size();
	int i = 0, j = 0, x = n - 1, y = m - 1;
	while (x >= (n + 1) / 2 && y >= (m + 1) / 2) {
		for (; j < x; j++)
			result.push_back(matrix[i][j]);
		for (; i < y; i++)
			result.push_back(matrix[i][j]);
		for (; j > n - 1 - x; j--)
			result.push_back(matrix[i][j]);
		for (; i > m - 1 - y; i--)
			result.push_back(matrix[i][j]);
		x--;
		y--;
		i++; 
		j++;
	}
	if (x < (n + 1) / 2 && n % 2 == 1) {
		for (; i <= y; i++)
			result.push_back(matrix[i][j]);
	}
	else if (y < (m + 1) / 2 && m % 2 == 1) {
		for (; j <= x; j++)
			result.push_back(matrix[i][j]);
	}
	return result;
}

bool Solution::IsPopOrder(vector<int> pushV, vector<int> popV)
{
	stack<int> st;
	int find;
	for (int i = 0, j = 0; i < popV.size(); i++) {
		if (!st.empty() && st.top() == popV[i])
			st.pop();
		else {
			find = 0;
			for (; j < pushV.size(); j++)
			{
				if (pushV[j] == popV[i]) {
					find = 1;
					st.push(pushV[j]);
					j++;
					break;
				}
				else {
					st.push(pushV[j]);
				}
			}
			if (!find)
				return false;
			st.pop();
		}
	}
	return true;
}

vector<int> Solution::PrintFromTopToBottom(TreeNode* root)
{
	vector<int> result;
	if (!root)
		return result;
	vector<TreeNode*> nodes1(1, root);
	vector<TreeNode*> nodes2;
	while (nodes1.size()) {
		for (auto node : nodes1) {
			result.push_back(node->val);
			if (node->left)
				nodes2.push_back(node->left);
			if (node->right)
				nodes2.push_back(node->right);
		}
		nodes1 = nodes2;
		nodes2.clear();
	}
	return result;
}

bool Solution::VerifySquenceOfBST(vector<int> sequence)
{
	if (!sequence.size())
		return false;
	int n = sequence.size(), i;
	for (i = 0; i < n - 1; i++)
		if (sequence[i] > sequence[n - 1])
			break;
	for (int j = i; j < n - 1; j++)
		if (sequence[j] < sequence[n - 1])
			return false;
	vector<int> s1(sequence.begin(), sequence.begin() + i);
	vector<int> s2(sequence.begin() + i, sequence.end() - 1);
	if (s1.size() && s2.size())
		return VerifySquenceOfBST(s1) && VerifySquenceOfBST(s2);
	else if (!s1.size() && s2.size())
		return VerifySquenceOfBST(s2);
	else if (s1.size() && !s2.size())
		return VerifySquenceOfBST(s1);
	else
		return true;
}

vector<vector<int> > Solution::FindPath(TreeNode* root, int expectNumber)
{
	vector<vector<int>> result;
	if (!root)
		return result;
	vector<vector<int>> resultLeft;
	vector<vector<int>> resultRight;
	int i, j;
	if (!root->left && !root->right) {
		if (root->val == expectNumber)
			result.push_back(vector<int>(1, root->val));
		return result;
	}
	else if (root->left && !root->right) {
		resultLeft = FindPath(root->left, expectNumber - root->val);
		for (auto vec : resultLeft) {
			vector<int> v(1, root->val);
			v.insert(v.end(), vec.begin(), vec.end());
			result.push_back(v);
		}
	}
	else if (!root->left && root->right) {
		resultRight = FindPath(root->right, expectNumber - root->val);
		for (auto vec : resultRight) {
			vector<int> v(1, root->val);
			v.insert(v.end(), vec.begin(), vec.end());
			result.push_back(v);
		}
	}
	else if (root->left && root->right) {
		resultLeft = FindPath(root->left, expectNumber - root->val);
		resultRight = FindPath(root->right, expectNumber - root->val);
		for (i = 0, j = 0; i < resultLeft.size() && j < resultRight.size(); ) {
			if (resultLeft[i].size() >= resultRight[j].size()) {
				vector<int> v(1, root->val);
				v.insert(v.end(), resultLeft[i].begin(), resultLeft[i].end());
				result.push_back(v);
				i++;
			}
			else {
				vector<int> v(1, root->val);
				v.insert(v.end(), resultRight[j].begin(), resultRight[j].end());
				result.push_back(v);
				j++;
			}
		}
		if (i < resultLeft.size()) {
			for (; i < resultLeft.size(); i++) {
				vector<int> v(1, root->val);
				v.insert(v.end(), resultLeft[i].begin(), resultLeft[i].end());
				result.push_back(v);
			}
		}
		if (j < resultRight.size()) {
			for (; j < resultRight.size(); j++) {
				vector<int> v(1, root->val);
				v.insert(v.end(), resultRight[j].begin(), resultRight[j].end());
				result.push_back(v);
			}
		}
	}
	return result;
}

RandomListNode* Solution::Clone(RandomListNode* pHead)
{
	if (!pHead)
		return NULL;
	RandomListNode* newHead = new RandomListNode(pHead->label);
	RandomListNode* curr = pHead;
	RandomListNode* newCurr = newHead;
	unordered_map<RandomListNode*, RandomListNode*> mp;
	mp[pHead] = newHead;
	while (curr->next) {
		curr = curr->next;
		RandomListNode* node = new RandomListNode(curr->label);
		newCurr->next = node;
		newCurr = newCurr->next;
		mp[curr] = newCurr;
	}
	curr = pHead;
	newCurr = newHead;
	while (curr) {
		newCurr->random = mp[curr->random];
		curr = curr->next;
		newCurr = newCurr->next;
	}
	return newHead;
}

TreeNode* Solution::Convert(TreeNode* pRootOfTree)
{
	if (!pRootOfTree)
		return NULL;
	TreeNode* root = pRootOfTree;
	TreeNode* curr;
	if (pRootOfTree->right) {
		curr = Convert(pRootOfTree->right);
		curr->left = pRootOfTree;
		pRootOfTree->right = curr;
	}
	if (pRootOfTree->left) {
		curr = Convert(pRootOfTree->left);
		root = curr;
		while (curr->right)
			curr = curr->right;
		curr->right = pRootOfTree;
		pRootOfTree->left = curr;
	}
	return root;
}

vector<string> Solution::Permutation(string str)
{
	vector<string> result;
	if (!str.size())
		return result;
	if (str.size() == 1) {
		result.push_back(str);
		return result;
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++) {
		if (i == 0 || str[i] != str[i - 1]) {
			string newStr(str);
			newStr.erase(newStr.begin() + i);
			vector<string> newResult = Permutation(newStr);
			for (int j = 0; j < newResult.size(); j++) {
				string r = "";
				r += str[i];
				r += newResult[j];
				result.push_back(r);
			}
		}
	}
	return result;
}

int Solution::MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (!numbers.size())
		return 0;
	int m = numbers[0], count = 0;
	for (auto num : numbers) {
		if (num == m)
			count++;
		else if (--count < 0)
			count = 1, m = num;
	}
	count = 0;
	for (auto num : numbers) {
		if (num == m)
			count++;
	}
	if (count * 2 > numbers.size())
		return m;
	else
		return 0;
}

vector<int> Solution::GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> result;
	if (k == 0 || input.size() < k)
		return result;
	priority_queue<int> q;
	for (int i : input) {
		if (q.size() < k)
			q.push(i);
		else if(q.top() > i) {
			q.pop();
			q.push(i);
		}
	}
	while (!q.empty()) {
		result.push_back(q.top());
		q.pop();
	}
	return result;
}

int Solution::FindGreatestSumOfSubArray(vector<int> array)
{
	if (!array.size())
		return 0;
	int maxSum = array[0], sum = 0;
	for (int i : array) {
		if (sum + i >= 0) {
			sum += i;
			if (sum > maxSum)
				maxSum = sum;
		}
		else {
			sum = 0;
			if (i > maxSum)
				maxSum = i;
		}
	}
	return maxSum;
}

int Solution::NumberOf1Between1AndN_Solution(int n)
{
	if (n == 0)
		return 0;
	int nNew = n / 10, digit = 1, subSum = 0;
	int sum = 0;
	while (nNew) {
		subSum = digit + 10 * subSum;
		digit *= 10;
		nNew /= 10;
	}
	sum += (n / digit) * subSum;
	if (n / digit > 1)
		sum += digit;
	else
		sum += (n % digit + 1);
	sum += NumberOf1Between1AndN_Solution(n % digit);
	return sum;
}

int Solution::GetUglyNumber_Solution(int index)
{
	if (index == 0)
		return 0;
	vector<int> result(index);
	int i2 = 0, i3 = 0, i5 = 0;
	int minIndex;
	result[0] = 1;
	for (int i = 1; i < index; i++) {
		result[i] = min(min(result[i2] * 2, result[i3] * 3), result[i5] * 5);
		if (result[i2] * 2 == result[i])
			i2++;
		if (result[i3] * 3 == result[i])
			i3++;
		if (result[i5] * 5 == result[i])
			i5++;
	}
	return result[index - 1];
	//int num = 0;
	//while(index > 0) {
	//	num++;
	//	int i = num;
	//	while (i > 1 && i % 2 == 0)
	//		i /= 2;
	//	while (i > 1 && i % 3 == 0)
	//		i /= 3;
	//	while (i > 1 && i % 5 == 0)
	//		i /= 5;
	//	if (i == 1)
	//		index--;
	//}
	//return num;
}

int Solution::FirstNotRepeatingChar(string str)
{
	if (!str.size())
		return -1;
	unordered_map<char, int> mp;
	for (char c : str) {
		if (mp.find(c) == mp.end())
			mp[c] = 1;
		else
			mp[c]++;
	}
	for (int i = 0; i < str.size(); i++) {
		if (mp[str[i]] == 1)
			return i;
	}
	return -1;
}

int Solution::InversePairs1(vector<int> data)
{
	if (!data.size())
		return 0;
	vector<int> dp(data.size(), 0);
	int count = 0;
	for (int i = 0; i < data.size(); i++) {
		for (int j = i + 1; j < data.size(); j++) {
			if (data[i] > data[j])
				count++;
			count %= 1000000007;
		}
	}
	return count;
}

int Solution::InversePairsHelper(vector<int> data)
{
	return 0;
}

int Solution::InversePairs(vector<int>& data)
{
	if (!data.size())
		return 0;
	if (data.size() == 1)
		return 0;
	int count = 0;
	vector<int> data1(data.begin(), data.begin() + data.size() / 2);
	vector<int> data2(data.begin() + data.size() / 2, data.end());
	count += InversePairs(data1);
	count += InversePairs(data2);
	int i, j, k;
	for (i = 0, j = 0, k = 0; k < data.size();k++) {
		if (i >= data1.size()) {
			data[k] = data2[j];
			j++;
		}
		else if (j >= data2.size() || data1[i] <= data2[j]) {
			data[k] = data1[i];
			i++;
		}
		else if (data1[i] > data2[j]) {
			data[k] = data2[j];
			count+=data1.size() - i;
			count %= 1000000007;
			j++;
		}
	}
	return count;
}
ListNode* Solution::FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	int len1 = 0, len2 = 0;
	ListNode* curr = pHead1;
	while (curr) {
		len1++;
		curr = curr->next;
	}
	curr = pHead2;
	while (curr) {
		len2++;
		curr = curr->next;
	}
	while (len1 > len2) {
		pHead1 = pHead1->next;
		len1--;
	}
	while (len1 < len2) {
		pHead2 = pHead2->next;
		len2--;
	}
	if (!pHead1 || !pHead2)
		return NULL;
	while (pHead1 && pHead1 != pHead2) {
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	return pHead1;
}

int Solution::GetNumberOfK(vector<int> data, int k)
{
	if (!data.size())
		return 0;
	int le = 0, ri = data.size(), mi, find;
	int leftFind = -1, rightFind = -1;
	if (data[0] < data[data.size() - 1]) {
		find = -1;
		while (le < ri) {
			mi = (le + ri) / 2;
			if (data[mi] == k) {
				find = mi;
				break;
			}
			else if (data[mi] > k)
				ri = mi;
			else
				le = mi + 1;
		}
		if (find >= 0) {
			le = -1, ri = find;
			while (le < ri - 1) {
				mi = (le + ri + 1) / 2;
				if (data[mi] < k)
					le = mi;
				else
					ri = mi;
			}
			leftFind = ri;
			le = find, ri = data.size();
			while (le < ri - 1) {
				mi = (le + ri) / 2;
				if (data[mi] > k)
					ri = mi;
				else
					le = mi;
			}
			rightFind = le;
			return rightFind - leftFind + 1;
		}
		else
			return 0;
	}
	else if (data[0] > data[data.size() - 1]) {
		find = -1;
		while (le < ri) {
			mi = (le + ri) / 2;
			if (data[mi] == k) {
				find = mi;
				break;
			}
			else if (data[mi] < k)
				ri = mi;
			else
				le = mi + 1;
		}
		if (find >= 0) {
			le = -1, ri = find;
			while (le < ri - 1) {
				mi = (le + ri + 1) / 2;
				if (data[mi] > k)
					le = mi;
				else
					ri = mi;
			}
			leftFind = ri;
			le = find, ri = data.size();
			while (le < ri - 1) {
				mi = (le + ri) / 2;
				if (data[mi] < k)
					ri = mi;
				else
					le = mi;
			}
			rightFind = le;
			return rightFind - leftFind + 1;
		}
		else
			return 0;
	}
	else {
		if (k == data[0])
			return data.size();
		else
			return 0;
	}
	return 0;
}

int Solution::TreeDepth(TreeNode* pRoot)
{
	if (!pRoot)
		return 0;
	return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
}

bool Solution::IsBalanced_Solution(TreeNode* pRoot)
{
	if (!pRoot)
		return true;
	int d1 = TreeDepth(pRoot->left), d2 = TreeDepth(pRoot->right);
	return (d1 - d2 <= 1 && d2 - d1 <= 1) && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

void Solution::FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
{
	if (!data.size())
		return;
	unordered_map<int, int> mp;
	int i;
	for (i = 0; i < data.size(); i++) {
		if (mp.find(data[i]) != mp.end())
			mp[data[i]]++;
		else
			mp[data[i]] = 1;
	}
	for (i = 0; i < data.size(); i++) {
		if (mp[data[i]] == 1) {
			*num1 = data[i];
			break;
		}
	}
	for (i++; i < data.size(); i++) {
		if (mp[data[i]] == 1) {
			*num2 = data[i];
			break;
		}
	}
	return;
}

vector<vector<int> > Solution::FindContinuousSequence(int sum)
{
	vector<vector<int>> result;
	if (sum <= 2)
		return result;
	for (int num = 2;; ++num) {
		if (sum % num == (num % 2 == 0 ? num / 2 : 0)) {
			if (sum / num - (num - 1) / 2 > 0) {
				vector<int> r;
				for (int i = 0; i < num; i++) {
					r.push_back(sum / num - (num - 1) / 2 + i);
				}
				result.insert(result.begin(), r);
			}
			else
				break;
		}
	}
	return result;
}

vector<int> Solution::FindNumbersWithSum(vector<int> array, int sum)
{
	vector<int> result;
	if (!array.size())
		return result;
	int le = 0, ri = array.size() - 1;
	int l, r, m;
	int t;
	while (le < ri - 1) {
		if (array[le] + array[ri] == sum) {
			result = {array[le], array[ri]};
			return result;
		}
		else if (array[le] + array[ri] > sum) {
			t = sum - array[le];
			l = le + 1;
			r = ri;
			while (l < r) {
				m = (l + r) / 2;
				if (array[m] == t) {
					result = {array[le], array[m]};
					return result;
				}
				else if (array[m] > t)
					r = m;
				else
					l = m;
				if (l >= r - 1)
					break;
			}
			ri = l;
		}
		else {
			t = sum - array[ri];
			l = le;
			r = ri - 1;
			while (l < r) {
				m = (l + r + 1) / 2;
				if (array[m] == t) {
					result = {array[m], array[ri]};
					return result;
				}
				else if (array[m] > t)
					r = m;
				else
					l = m;
				if (l >= r - 1)
					break;
			}
			le = r;
		}
	}
	return result;
}

string Solution::LeftRotateString(string str, int n)
{
	string s = "";
	if (!str.size())
		return s;
	n %= str.size();
	s += str.substr(n);
	s += str.substr(0, n);
	return s;
}

string Solution::ReverseSentence(string str)
{
	string s = "";
	if (!str.size())
		return s;
	int i, end;
	for (i = str.size() - 1, end = str.size(); i >= 0; i--) {
		if (str[i] == ' ') {
			s += str.substr(i+1, end - i - 1);
			s += " ";
			end = i;
		}
	}
	s += str.substr(i+1, end - i - 1);
	return s;
}

bool Solution::IsContinuous(vector<int> numbers)
{
	if (numbers.size() != 5)
		return false;
	sort(numbers.begin(), numbers.end());
	int wang = 0;
	int i = -1;
	while (numbers[++i] == 0)
		wang++;
	while(++i < numbers.size()) {
		if (numbers[i] == numbers[i - 1])
			return false;
		wang -= numbers[i] - numbers[i - 1] - 1;
	}
	if (wang >= 0)
		return true;
	return false;
}

int Solution::LastRemaining_Solution(int n, int m)
{
	if (m <= 0 || n <= 0)
		return -1;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		nums[i] = i;
	int i, count = -1;
	while (n > 1) {
		for (i = 0; i < nums.size();i++) {
			if (nums[i] >= 0) {
				count++;
				if (count == m - 1) {
					nums[i] = -1;
					count = -1;
					n--;
					if (n <= 1)
						break;
				}
			}
		}
	}
	for (i = 0; i < nums.size(); i++)
		if (nums[i] >= 0)
			return nums[i];
}

int Solution::Sum_Solution(int n)
{
	int sum = n;
	sum && (sum = n + Sum_Solution(n - 1));
	return sum;
}

int Solution::Add(int num1, int num2)
{
	int a = num1 ^ num2;
	int b = num1 & num2;
	b = b << 1;
	return b? Add(a, b):a;
}

int Solution::StrToInt(string str)
{
	if (!str.size())
		return 0;
	int i = 0, zhengfu = 1;
	int num = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+') {
		zhengfu = 1;
		i++;
	}
	else if (str[i] == '-') {
		zhengfu = -1;
		i++;
	}
	for (; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (zhengfu > 0) {
				if (num > INT_MAX / 10 || (num == INT_MAX / 10 && INT_MAX % 10 < str[i] - '0'))
					return 0;
				num = num * 10 + str[i] - '0';
			}
			else {
				if (num < INT_MIN / 10 || (num == INT_MIN / 10 && str[i] == '9'))
					return 0;
				num = num * 10 - str[i] + '0';
			}
		}
		else
			return 0;
	}
	return num;
}

bool Solution::duplicate(int numbers[], int length, int* duplication)
{
	if (length == 0)
		return false;
	unordered_map<int, int> mp;
	for (int i = 0; i < length; i++) {
		if (mp.find(numbers[i]) == mp.end())
			mp[numbers[i]] = 1;
		else {
			*duplication = numbers[i];
			return true;
		}
	}
	return false;
}

vector<int> Solution::multiply(const vector<int>& A)
{
	vector<int> B(A.size(), 1);
	if (!A.size())
		return B;
	int accu = 1;
	for (int i = 0; i < A.size(); i++) {
		B[i] *= accu;
		accu *= A[i];
	}
	accu = 1;
	for (int i = A.size() - 1;i>=0; i--) {
		B[i] *= accu;
		accu *= A[i];
	}
	return B;
}


bool Solution::match(char* str, char* pattern)
{
	string s(str);
	string p(pattern);
	vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
	dp[s.size()][p.size()] = 1;
	for (int i = s.size(), j = p.size() - 1; j >= 0; j--) {
		if (j + 1 < p.size() && p[j + 1] == '*' && dp[i][j + 2] == 1)
			dp[i][j] = 1;
		cout << dp[i][j] << " ";
	}
	cout << endl;
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = p.size() - 1; j >= 0; j--) {
			if (p[j] != '*') {
				if ((p[j] == '.' || p[j] == s[i])&&
					((dp[i+1][j+1] == 1) 
						|| (j + 1 < p.size() && p[j + 1] == '*' && (dp[i + 1][j] == 1 || dp[i][j + 2] == 1))))
						dp[i][j] = 1;
				else if (j + 1 < p.size() && p[j + 1] == '*' && dp[i][j + 2] == 1)
						dp[i][j] = 1;
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[0][0];
}

bool Solution::isNumeric(char* string)
{
	int s = 0, e = 0, d = 0, n = 0;
	while (*string) {
		if (*string == '+' || *string == '-') {
			if (s == 0 && n == 0)
				s = 1;
			else
				return false;
		}
		else if (*string == '.') {
			if (d == 0 && e == 0)
				d = 1;
			else
				return false;
		}
		else if (*string >= '0' && *string <= '9') {
			n ++;
		}
		else if (*string == 'e' || *string == 'E') {
			if (e == 0 && n > 0) {
				e = 1;
				s = 0;
				d = 0;
				n = 0;
			}
			else
				return false;
		}
		else
			return false;
		string++;
	}
	if (n == 0)
		return false;
	return true;
}

int Solution::cutRope(int number)
{
	vector<int> dp(number + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= number; i++) {
		dp[i] = 0;
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] * j);
			dp[i] = max(dp[i], (i - j) * j);
		}
		cout << i << ": " << dp[i] << endl;
	}
	return dp[number];
}

unordered_map<char, int> mp;
queue<char> qu;
void Solution::Insert(char ch)
{
	if (mp.find(ch) == mp.end()) {
		mp[ch] = 1;
		qu.push(ch);
	}
	else
		mp[ch]++;
	return;
}

//return the first appearence once char in current stringstream
char Solution::FirstAppearingOnce()
{
	while (!qu.empty() && mp[qu.front()] > 1)
		qu.pop();
	return qu.empty() ? '#' : qu.front();
}

ListNode* Solution::EntryNodeOfLoop(ListNode* pHead)
{
	unordered_map<ListNode*, int> mp;
	while (pHead) {
		if (mp.find(pHead) != mp.end())
			return pHead;
		mp[pHead] = 1;
		pHead = pHead->next;
	}
	return pHead;
}

ListNode* Solution::deleteDuplication(ListNode* pHead)
{
	ListNode* last = NULL;
	ListNode* curr = pHead;
	while (curr ) {
		if (curr->next && curr->val == curr->next->val) {
			while(curr->next && curr->val == curr->next->val)
				curr = curr->next;
			if (last == NULL)
				pHead = curr->next;
			else
				last->next = curr->next;
			curr = curr->next;
		}
		else {
			last = curr;
			curr = last->next;
		}
	}
	return pHead;
}

TreeLinkNode* Solution::GetNext(TreeLinkNode* pNode)
{
	if (!pNode)
		return NULL;
	if (pNode->right) {
		pNode = pNode->right;
		while (pNode->left)
			pNode = pNode->left;
	}
	else if (pNode->next) {
		while (pNode->next && pNode->next->right == pNode)
			pNode = pNode->next;
		pNode = pNode->next;
	}
	else
		pNode = NULL;
	return pNode;
}

bool Solution::isSymmetrical(TreeNode* pRoot)
{
	if (!pRoot)
		return true;
	return isSymmetricalHelper(pRoot->left, pRoot->right);
}

bool Solution::isSymmetricalHelper(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (!pRoot1 && !pRoot2)
		return true;
	else if (pRoot1 && pRoot2) {
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetricalHelper(pRoot1->left, pRoot2->right) &&
			isSymmetricalHelper(pRoot1->right, pRoot2->left);
	}
	return false;
}

vector<vector<int> > Solution::Print(TreeNode* pRoot)
{
	vector<vector<int>> result;
	if (!pRoot)
		return result;
	vector<TreeNode*> nodes1(1, pRoot);
	vector<TreeNode*> nodes2;
	vector<int> curr;
	while (nodes1.size() || nodes2.size()) {
		if (nodes1.size()) {
			for (int i = 0; i < nodes1.size();i++) {
				curr.push_back(nodes1[i]->val);
				if (nodes1[i]->left)
					nodes2.push_back(nodes1[i]->left);
				if (nodes1[i]->right)
					nodes2.push_back(nodes1[i]->right);
			}
			result.push_back(curr);
			nodes1.clear();
			curr.clear();
		}
		else {
			for (int i = 0; i < nodes2.size();i++) {
				if (nodes2[i]->left)
					nodes1.push_back(nodes2[i]->left);
				if (nodes2[i]->right)
					nodes1.push_back(nodes2[i]->right);
			}
			for (int i = nodes2.size() - 1; i >= 0;i--)
				curr.push_back(nodes2[i]->val);
			result.push_back(curr);
			nodes2.clear();
			curr.clear();
		}
	}
	return result;
}

vector<vector<int> > Solution::Print2(TreeNode* pRoot)
{
	vector<vector<int>> result;
	if (!pRoot)
		return result;
	vector<TreeNode*> nodes1(1, pRoot);
	vector<TreeNode*> nodes2;
	vector<int> curr;
	while (nodes1.size()) {
		for (int i = 0; i < nodes1.size();i++) {
			curr.push_back(nodes1[i]->val);
			if (nodes1[i]->left)
				nodes2.push_back(nodes1[i]->left);
			if (nodes1[i]->right)
				nodes2.push_back(nodes1[i]->right);
		}
		result.push_back(curr);
		nodes1 = nodes2;
		nodes2.clear();
		curr.clear();
	}
	return result;
}

priority_queue <int, vector<int>, less<int> > q1;
priority_queue <int, vector<int>, greater<int> > q2;
int n = 0;
void Solution::Insert1(int num)
{
	n++;
	if (n % 2 == 1) {
		if (!q2.empty() && num > q2.top()) {
			q2.push(num);
			num = q2.top();
			q2.pop();
		}
		q1.push(num);
	}
	else
	{
		if (!q1.empty() && num < q1.top()) {
			q1.push(num);
			num = q1.top();
			q1.pop();
		}
		q2.push(num);
	}
	return;
}
double Solution::GetMedian()
{
	if (n % 2 == 1)
		return q1.top();
	else
		return double(q2.top() + q1.top()) / 2;
}

vector<TreeNode*> result;
TreeNode* Solution::KthNode(TreeNode* pRoot, int k)
{
	if (!pRoot || k == 0)
		return NULL;
	KthNodeHelper(pRoot, k);
	if(k > result.size())
		return NULL;
	return result[k - 1];
}
void Solution::KthNodeHelper(TreeNode* pRoot, int k)
{
	if (!pRoot)
		return;
	KthNodeHelper(pRoot->left, k);
	result.push_back(pRoot);
	if(result.size() < k)
		KthNodeHelper(pRoot->right, k);
	return;
}

vector<int> Solution::maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (size == 0 || num.size() == 0)
		return result;
	if (size == 1)
		return num;
	vector<int> left(num.size());
	vector<int> right(num.size());
	for (int i = 0; i < num.size(); i++) {
		if (i % size == 0)
			left[i] = num[i];
		else
			left[i] = max(left[i - 1], num[i]);
	}
	for (int i = num.size() - 1;i >= 0; i--) {
		if (i == num.size() - 1 || i % size == size - 1)
			right[i] = num[i];
		else
			right[i] = max(right[i + 1], num[i]);
	}
	for (int i = 0; i < num.size() - size + 1; i++) {
		result.push_back(max(right[i], left[i + size - 1]));
	}
	return result;
}

bool Solution::hasPath(char* matrix, int rows, int cols, char* str)
{
	if (!rows || !cols || !str)
		return false;
	vector<vector<int>> mem(rows, vector<int>(cols, 0));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (hasPathHelper(matrix, i, j, str, mem))
			{
				cout << i<<" "<<j<<"ok  \n";
				return true;
			}
			cout << i<<" "<<j<<"no  \n";
		}
	}
	return false;
}
bool Solution::hasPathHelper(char* matrix, int i, int j, char* str, vector<vector<int>>& mem)
{
	if (i < 0 || i >= mem.size() || j < 0 || j >= mem[0].size())
		return false;
	if (mem[i][j] == 0 && *str == *(matrix + i * mem[0].size() + j) ) {
		cout<< "digui: " << i<<" "<<j<<"ok  ";
		mem[i][j] = 1;
		if (!*(str + 1))
			return true;
		else {
			if(hasPathHelper(matrix, i - 1, j, str+1, mem))
				return true;
			if(hasPathHelper(matrix, i + 1, j, str+1, mem))
				return true;
			if(hasPathHelper(matrix, i, j - 1, str+1, mem))
				return true;
			if(hasPathHelper(matrix, i, j + 1, str+1, mem))
				return true;
		}
		mem[i][j] = 0;
	}
	return false;
}

int Solution::movingCount(int threshold, int rows, int cols)
{
	if(!rows || !cols)
		return 0;
	vector<vector<int>> mem(rows, vector<int>(cols, 0));
	return movingCountHelper(threshold, 0, 0, mem);
}
int Solution::movingCountHelper(int threshold, int i, int j, vector<vector<int>>& mem)
{
	int num = 0;
	if (i < 0 || i >= mem.size() || j < 0 || j >= mem[0].size() || mem[i][j] == 1)
		return 0;
	mem[i][j] = 1;
	int ii = i, jj = j;
	int sum = 0;
	while (ii) {
		sum += ii % 10;
		ii /= 10;
	}
	while (jj) {
		sum += jj % 10;
		jj /= 10;
	}
	if (sum <= threshold)
	{
		num++;
		num += movingCountHelper(threshold, i - 1, j, mem);
		num += movingCountHelper(threshold, i + 1, j, mem);
		num += movingCountHelper(threshold, i, j - 1, mem);
		num += movingCountHelper(threshold, i, j + 1, mem);
		return num;
	}
	return 0;
}

char* Solution::Serialize(TreeNode* root) {
	if (!root) {
		char* result = new char[3];
		strcpy(result, "#!");
		return result;
	}
	char sRoot[16];
	sprintf(sRoot, "%d", root->val);
	char* sLeft = Serialize(root->left);
	char* sRight = Serialize(root->right);
	char* result = new char[strlen(sLeft) + strlen(sRight) + strlen(sRoot)+10];
	strcpy(result, sRoot);
	strcat(result, "!");
	strcat(result, sLeft);
	strcat(result, sRight);
	return result;
}

int po = 0;
TreeNode* Solution::Deserialize(char* str) {

	TreeNode* root = NULL;
	if (!*(str + po))
		return root;
	if (*(str + po) == '#')
	{
		po += 2;
		return root;
	}
	int num = 0;
	while (*(str+po) != '!') {
		num = num * 10 + *(str+po) - '0';
		po++;
	}
	root = new TreeNode(num);
	po++;
	if (!*(str + po))
		return root;
	root->left = Deserialize(str);
	if (!*(str + po))
		return root;
	root->right = Deserialize(str);
	return root;
}
void Solution::PrintTree(TreeNode* root)
{
	if (!root)
		return;
	cout << root->val << " ";
	PrintTree(root->left);
	PrintTree(root->right);
	return;
}

string Solution::PrintMinNumber(vector<int> numbers)
{
	if (!numbers.size())
		return "";
	string s = "";
	sort(numbers.begin(), numbers.end(), sortKey);
	for (int i = 0;i<numbers.size();i++) {
		s += to_string(numbers[i]);
	}
	return s;
}

bool Solution::sortKey(int s1, int s2)
{
	string s12 = to_string(s1) + to_string(s2);
	string s21 = to_string(s2) + to_string(s1);
	return s12 < s21;
}
