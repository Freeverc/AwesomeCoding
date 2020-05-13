//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include <algorithm>
//
//using namespace std;
//
//
///*请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
//******************************开始写代码******************************/
//vector<vector<int>> func(vector < int > nums, int m) {
//    vector<vector<int>> results;
//    if (nums.size() < m)
//        return results;
//    else if (nums.size() == m) {
//        results.push_back(nums);
//    }
//    else {
//        int sum = 0;
//        for (int i = 0; i + m - 1 < nums.size(); i++) {
//            sum += nums[i];
//            vector<int> base = { sum };
//            vector<int> numsNew;
//            numsNew.insert(numsNew.end(), nums.begin() + i + 1, nums.end());
//            vector<vector<int>> resultsNew = func(numsNew, m - 1);
//            for (int j = 0; j < resultsNew.size(); j++) {
//                vector<int> r;
//                r.insert(r.end(), base.begin(), base.end());
//                r.insert(r.end(), resultsNew[j].begin(), resultsNew[j].end());
//                results.push_back(r);
//            }
//        }
//    }
//    return results;
//}
//int calc(vector < int > nums, int m) {
//    vector<vector<int>> results = func(nums, m);
//    int num = 0;
//    for (int i = 0; i < results.size(); i++)
//    {
//        sort(results[i].begin(), results[i].end());
//        int repeat = 0;
//        for (int j = 0; j < results[i].size(); j++) {
//            if (j > 0 && results[i][j] == results[i][j - 1]) {
//                repeat++;
//                break;
//            }
//        }
//        if (repeat == 0)
//            num++;
//    }
//    return num;
//}
///******************************结束写代码******************************/
//
//
//int main() {
//    int res;
//
//    int _nums_size = 0;
//    cin >> _nums_size;
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//    vector<int> _nums;
//    int _nums_item;
//    for (int _nums_i = 0; _nums_i < _nums_size; _nums_i++) {
//        cin >> _nums_item;
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        _nums.push_back(_nums_item);
//    }
//
//
//    int _m;
//    cin >> _m;
//    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//
//
//    res = calc(_nums, _m);
//    cout << res << endl;
//
//    return 0;
//
//}
