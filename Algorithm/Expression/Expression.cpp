//
//  main.cpp
//  Expression
//
//  Created by Freeverc on 2020/5/11.
//  Copyright © 2020 Freeverc. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//定义二叉树节点，可以放整数和字符
struct TreeNode {
    int val;
    char ch;
    TreeNode* left, * right;
    TreeNode(int num, char c)
    {
        val = num;
        ch = c;
        left = nullptr;
        right = nullptr;
    }
};

// 计算运算符的优先级
bool op_prior(char a, char b)
{
    if (a == '(')
        return false;
    else if (a == '*' || a == '/')
        return true;
    else if (b == '*' || b == '/')
        return false;
    else
        return true;
}

//计算二叉树的值
int calcu_btree(TreeNode* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->val;
    else {
        int leftValue = calcu_btree(root->left);
        int rightValue = calcu_btree(root->right);
        if (root->ch == '+')
            return leftValue + rightValue;
        else if (root->ch == '-')
            return leftValue - rightValue;
        else if (root->ch == '*')
            return leftValue * rightValue;
        else if (root->ch == '/')
            return leftValue / rightValue;
    }
    return 0;
}

//转化为后缀表达式
string to_rpn(string& s)
{
    if (s.empty())
        return "";
    stack<char> op_s;
    string rpn = "";
    int state = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            state = 1;
            rpn += s[i];
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '-' && state == 0)
            {
                rpn += s[i];
                state = 2;
                continue;
            }
            else if (s[i] == '+' && state == 0)
            {
                state = 2;
                continue;
            }
            else if (state != 1)
                return "";
            rpn += ' ';
            state = 2;
            while (!op_s.empty() && op_prior(op_s.top(), s[i]))
            {
                rpn += op_s.top();
                rpn += ' ';
                op_s.pop();
            }
            op_s.push(s[i]);
        }
        else if (s[i] == ' ' || s[i] == '\t')
        {
            continue;
        }
        else if (s[i] == '(')
        {
            if (state == 1)
                return "";
            state = 0;
            op_s.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (state != 1)
                return "";
            rpn += ' ';
            while (!op_s.empty() && op_s.top() != '(')
            {
                rpn += op_s.top();
                rpn += ' ';
                op_s.pop();
            }
            if (op_s.empty())
                return "";
            else
                op_s.pop();
        }
        else {
            return "";
        }
        //        cout << i << " : " << rpn <<endl;
    }
    if (op_s.empty())
        return "";
    rpn += ' ';
    while (!op_s.empty())
    {
        if (op_s.top() == '(')
            return "";
        rpn += op_s.top();
        rpn += ' ';
        op_s.pop();
    }
    return rpn;
}

//转化为二叉树，输入后缀表达式
TreeNode* to_btree(string& s)
{
    if (s.empty())
        return nullptr;
    stack<TreeNode* > node_st;
    int num = 0;
    char ch = 0;
    int flag = 1;
    int state = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-' && s[i + 1] != ' ')
        {
            flag = -1;
            state = 1;
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            state = 1;
            num = num * 10 + s[i] - '0';
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            ch = s[i];
            state = 2;
            TreeNode* node = new TreeNode(0, ch);
            node->right = node_st.top();
            node_st.pop();
            node->left = node_st.top();
            node_st.pop();
            node_st.push(node);
        }
        else if (s[i] == ' ')
        {
            if (state == 1)
            {
                num *= flag;
                TreeNode* leaf = new TreeNode(num, 0);
                node_st.push(leaf);
                num = 0;
                flag = 1;
                state = 0;
            }
            else
                continue;
        }
        //        if(!st.empty())
        //            cout << calcu_btree(st.top()) << endl;
    }
    return node_st.top();
}


int main(int argc, const char* argv[]) {
    // insert code here...
//    string initStr = "20 + (3 * (4 + 46) - 6)/2-134";
    string initStr = "-332 + (+456) * (678 -  789 *  (-712 + 987) ) + 64 / 16 * 36 + 20";
    cout << "中缀表达式为:" << initStr << endl;
    string rpnStr = to_rpn(initStr);
    if (rpnStr.size())
        cout << "后缀表达式为:" << rpnStr << endl;
    else
        cout << "中缀表达式不合法" << endl;
    TreeNode* root = to_btree(rpnStr);
    int r = -332 + (+456) * (678 - 789 * (-712 + 987)) + 64 / 16 * 36 + 20;
    cout << "用系统编译器求结果： " << r << endl;
    cout << "构造二叉树再求结果： " << calcu_btree(root) << endl;
    return 0;
}
