#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void combination(vector<vector<int>>& result, vector<int> ans, vector<int>& candidates, int target, int idx){
        if(target == 0){
            result.push_back(ans);
            return;
        }
        if(target < 0) return;

        for(int i = idx; i < candidates.size(); i++){
            ans.push_back(candidates[i]);
            combination(result, ans, candidates, target - candidates[i], i);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        combination(result, ans, candidates, target, 0);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> results = sol.combinationSum(candidates, target);

    cout << "Combinations:\n";
    for(const auto& combination : results){
        cout << "[ ";
        for(int num : combination){
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
