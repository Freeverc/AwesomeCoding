#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		  val(x), next(NULL) {
	}
 };

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 struct RandomListNode {
     int label;
     struct RandomListNode *next, *random;
     RandomListNode(int x) :
             label(x), next(NULL), random(NULL) {
     }
 };

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
 

class Solution
{
public:
	bool Find(int target, vector<vector<int> > array);
	void replaceSpace(char* str, int length);
	vector<int> printListFromTailToHead(ListNode* head);
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
    int minNumberInRotateArray(vector<int> rotateArray);
    int Fibonacci(int n);
    int jumpFloor(int number);
    int jumpFloorII(int number);
    int rectCover(int number);
    int  NumberOf1(int n);
    double Power(double base, int exponent);
    void reOrderArray(vector<int>& array);
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
    ListNode* ReverseList(ListNode* pHead);
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    bool HasSubtreeHelper(TreeNode* pRoot1, TreeNode* pRoot2);
    void Mirror(TreeNode* pRoot);
    vector<int> printMatrix(vector<vector<int> > matrix);
    bool IsPopOrder(vector<int> pushV, vector<int> popV);
    vector<int> PrintFromTopToBottom(TreeNode* root);
    bool VerifySquenceOfBST(vector<int> sequence);
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber);
    RandomListNode* Clone(RandomListNode* pHead);
    TreeNode* Convert(TreeNode* pRootOfTree);
    vector<string> Permutation(string str);
    int MoreThanHalfNum_Solution(vector<int> numbers);
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
    int FindGreatestSumOfSubArray(vector<int> array);
    int NumberOf1Between1AndN_Solution(int n);
    string PrintMinNumber(vector<int> numbers);
    int GetUglyNumber_Solution(int index);
    int FirstNotRepeatingChar(string str);
    int InversePairs(vector<int>& data);
    int InversePairsHelper(vector<int> data);
    int InversePairs1(vector<int> data);
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);
    int GetNumberOfK(vector<int> data, int k);
    int TreeDepth(TreeNode* pRoot);
    bool IsBalanced_Solution(TreeNode* pRoot);
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2);
    vector<vector<int> > FindContinuousSequence(int sum);
    vector<int> FindNumbersWithSum(vector<int> array, int sum);
    string LeftRotateString(string str, int n);
    string ReverseSentence(string str);
    bool IsContinuous(vector<int> numbers);
    int LastRemaining_Solution(int n, int m);
    int Sum_Solution(int n);
    int Add(int num1, int num2);
    int StrToInt(string str);
    bool duplicate(int numbers[], int length, int* duplication);
    vector<int> multiply(const vector<int>& A);
    bool match(char* str, char* pattern);
    bool isNumeric(char* string);
    int cutRope(int number);
    void Insert(char ch);
    char FirstAppearingOnce();
    ListNode* EntryNodeOfLoop(ListNode* pHead);
    ListNode* deleteDuplication(ListNode* pHead);
    TreeLinkNode* GetNext(TreeLinkNode* pNode);
    bool isSymmetrical(TreeNode* pRoot);
    bool isSymmetricalHelper(TreeNode* pRoot1, TreeNode* pRoot2);
    vector<vector<int> > Print(TreeNode* pRoot);
    vector<vector<int> > Print2(TreeNode* pRoot);
    void Insert1(int num);
    double GetMedian();
    vector<int> maxInWindows(const vector<int>& num, unsigned int size);
    bool hasPath(char* matrix, int rows, int cols, char* str);
    bool hasPathHelper(char* matrix, int i, int j, char* str, vector<vector<int>>& mem);
    int movingCount(int threshold, int rows, int cols);
    int movingCountHelper(int threshold, int i, int j, vector<vector<int>>& mem);
    TreeNode* KthNode(TreeNode* pRoot, int k);
    void KthNodeHelper(TreeNode* pRoot, int k);
    char* Serialize(TreeNode* root);
    TreeNode* Deserialize(char* str);
    void PrintTree(TreeNode* root);
    static bool sortKey(int s1, int s2);
    void push(int node) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }
    int pop() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int t = stack2.top();
        stack2.pop();
        return t;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

