#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
#include <time.h>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public: 
	vector<vector<int>> mem;
	int num;
    int testFunc();
    //1
    vector<int> twoSum(vector<int>& nums, int target);
    vector<int> twoSum2(vector<int>& nums, int target);
    bool canThreePartsEqualSum(vector<int>& A);
    bool canThreePartsEqualSum2(vector<int>& A);
    bool canThreePartsEqualSum3(vector<int>& A);
    //2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    //3
    int lengthOfLongestSubstring(string s);
    int lengthOfLongestSubstring2(string s);
    //4
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2);
    //5
    string longestPalindrome(string s);
    string longestPalindrome2(string s);
    //6
    string convert(string s, int numRows);
    //7
    int reverse(int x);
    //8
    int myAtoi(string str);
    //9
    bool isPalindrome(int x);
    //10
    bool isMatch(string s, string p);
    bool dp(const string s, int m, const string p, int n);
    bool isMatch2(string s, string p);
    //11
    int maxArea(vector<int>& height);
    int maxArea2(vector<int>& height);
    //12
    string intToRoman(int num);
    //13
    int romanToInt(string s);
    //14
    string longestCommonPrefix(vector<string>& strs);
    //15
    vector<vector<int>> threeSum(vector<int>& nums);
    vector<vector<int>> threeSum2(vector<int>& nums);
    vector<vector<int>> threeSum3(vector<int>& nums);

    //16
    int threeSumClosest(vector<int>& nums, int target);
    //17
    vector<string> letterCombinations(string digits);
    vector<string> letterDict(string digits);
    //18
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    //19
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* removeNthFromEnd1(ListNode* head, int n);
    ListNode* removeNthFromEnd2(ListNode* head, int n);
    //20
    bool isValid(string s);
    //21
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    //22
    vector<string> generateParenthesis(int n);
    //23
    ListNode* mergeKLists(vector<ListNode*>& lists);
    ListNode* mergeKLists2(vector<ListNode*>& lists);
    //24
    ListNode* swapPairs(ListNode* head);
    //25
    ListNode* reverseKGroup(ListNode* head, int k);
    string gcdOfStrings(string str1, string str2);
    //26
    int removeDuplicates(vector<int>& nums);
    //27
    int removeElement(vector<int>& nums, int val);
    //28
    int strStr(string haystack, string needle);
    //29
    int divide(int dividend, int divisor);
    //31 
    vector<int> ks;
    void nextPermutation(vector<int>& nums);
    //32
    int longestValidParentheses(string s);
    int longestValidParentheses1(string s);
    //33
    int search(vector<int>& nums, int target);
    int biSearch(vector<int>& nums, int i, int j, int target);
    int singleNumber(vector<int>& nums);
    int longestConsecutive(vector<int>& nums);
    bool hasCycle(ListNode* head);
    bool hasCycle2(ListNode* head);
    //34
    vector<int> searchRange(vector<int>& nums, int target);
    //int searchMiddle(vector<int>& nums, int target, int le, int ri);
    //int searchLeft(vector<int>& nums, int target, int le, int ri);
    //int searchRight(vector<int>& nums, int target, int le, int ri);
    //39
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    //42
    int trap(vector<int>& height);
    //46
    vector<vector<int>> permute(vector<int>& nums);
    vector<vector<int>> permute2(vector<int>& nums);
    //48
    void rotate(vector<vector<int>>& matrix);
    //49
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    //53
    int maxSubArray(vector<int>& nums);
    int maxSubArray0(vector<int>& nums);
    //55
    bool canJump(vector<int>& nums);
    //56
    vector<vector<int>> merge(vector<vector<int>>& intervals);
    //59
    vector<vector<int>> generateMatrix(int n);
    //62
    int uniquePaths(int m, int n);
    //64
    int minPathSum(vector<vector<int>>& grid);
    //70
    int climbStairs(int n);
    //72
    int minDistance(string word1, string word2);
    //75
    void sortColors(vector<int>& nums);
    //76
    string minWindow(string s, string t);
    string minWindow1(string s, string t);
    //78
    vector<vector<int>> subsets(vector<int>& nums);
    //79
    bool exist(vector<vector<char>>& board, string word);
    bool existHelper(vector<vector<char>>& board, string word, vector<vector<bool>>& mem, int i, int j);
    bool exist1(vector<vector<char>>& board, string word);
    //84
    int largestRectangleArea(vector<int>& heights);
    int dc(vector<int>& heights, int le, int ri);
    // 85
    int maximalRectangle(vector<vector<char>>& matrix);
    //88
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    //94
    vector<int> inorderTraversal(TreeNode* root);
    vector<int> inorderTraversal1(TreeNode* root);
    //96
    int numTrees(int n);
    //98
    bool isValidBST(TreeNode* root);
    //101
    bool isSymmetric(TreeNode* root);
    bool isSymmetricHelper(TreeNode* root1, TreeNode* root2);
    bool isSymmetric1(TreeNode* root);
    //102
    vector<vector<int>> levelOrder(TreeNode* root);
    //104
    int maxDepth(TreeNode* root);
    //105
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    //114
    void flatten(TreeNode* root);
    //121
    int maxProfit(vector<int>& prices);
    //122
    int maxProfit2(vector<int>& prices);
    //124
    int maxPathSum(TreeNode* root);
    int maxPathSumHelper(TreeNode* root);
    // 139
    unordered_map<string, bool> mp139;
    bool wordBreak0(string s, vector<string>& wordDict);
    bool wordBreak(string s, vector<string>& wordDict);
    //142
    ListNode* detectCycle(ListNode* head);
    //148
    ListNode* sortList(ListNode* head);
    //152
    int maxProduct(vector<int>& nums);
    //160
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
    //169
    int majorityElement(vector<int>& nums);
    //198
    int rob(vector<int>& nums);
    //200
    int numIslands(vector<vector<char>>& grid);
    void numIslandsHelper(vector<vector<char>>& grid, vector<vector<int>>& mem, int i, int j);
    //206
    ListNode* reverseList(ListNode* head);
    ListNode* reverseList1(ListNode* head);
    //215
    int findKthLargest(vector<int>& nums, int k);
    //217
    bool containsDuplicate(vector<int>& nums);
    //221
    int maximalSquare(vector<vector<char>>& matrix);
    //226
    TreeNode* invertTree(TreeNode* root);
    //231
    bool isPowerOfTwo(int n);
    //234
    bool isPalindrome(ListNode* head);
    //235
    TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q);
    //236
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    bool lowestCommonAncestorHelper(TreeNode* root, TreeNode* p);
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q);
    bool lowestCommonAncestor1Helper(TreeNode* root, TreeNode* p);
    //237
    void deleteNode(ListNode* node);
    //238
    vector<int> productExceptSelf(vector<int>& nums);
    //239
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
    //240
    bool searchMatrix(vector<vector<int>>& matrix, int target);
    bool searchMatrixHelper(vector<vector<int>>& matrix, int target, int, int, int, int);
    //279
    int numSquares(int n);
    //283
    void moveZeroes(vector<int>& nums);
    //287
    int findDuplicate(vector<int>& nums);
    //292
    bool canWinNim(int n);
    //297
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);
    //300
    int lengthOfLIS(vector<int>& nums);
    int lengthOfLIS1(vector<int>& nums);
    //309
    int maxProfit5(vector<int>& prices);
    //322
    int coinChange(vector<int>& coins, int amount);
    //337
    int rob(TreeNode* root);
    int robRoot(TreeNode* root);
    int robNoRoot(TreeNode* root);
    //344
    void reverseString(vector<char>& s);
    //347
    vector<int> topKFrequent(vector<int>& nums, int k);
    //338
    vector<int> countBits(int num);
    //394
    string decodeString(string s);
    //399
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
    //406
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people);
    //bool reconstructQueueSortKey(vector<int> person1, vector<int> person2)
    //416
    bool canPartition(vector<int>& nums);
    //437
    int pathSum(TreeNode* root, int sum);
    int pathSumHelper(TreeNode* root, int sum);
    //438
    vector<int> findAnagrams(string s, string p);
    //448
    vector<int> findDisappearedNumbers(vector<int>& nums);
    //461
    int hammingDistance(int x, int y);
    //494
    int findTargetSumWays(vector<int>& nums, int S);
    int findTargetSumWaysHelper(vector<int>& nums, int S, int i);
    //538 1038
    TreeNode* convertBST(TreeNode* root);
    int convertBSTHelper(TreeNode* root, int sum);
    //543
    int diameterOfBinaryTree(TreeNode* root);
    int diameterOfBinaryTreeHelper(TreeNode* root);
    //557
    string reverseWords(string s);
    //560
    int subarraySum(vector<int>& nums, int k);
    int subarraySumHelper(vector<int>& nums, int k);
    int subarraySum1(vector<int>& nums, int k);
    //581
    int findUnsortedSubarray(vector<int>& nums);
    //617
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
    //647
    int countSubstrings(string s);
    int countSubstrings1(string s);
    //739
    vector<int> dailyTemperatures(vector<int>& T);
    vector<int> dailyTemperatures1(vector<int>& T);


};


bool reconstructQueueSortKey(vector<int> person1, vector<int> person2);
