############################################################################################################################  Question  #########################################################################################################################

Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104

############################################################################################################################  Solution  #########################################################################################################################//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    vector<vector<int>> findSet(vector<int> arr, int start, int idx){
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        int target = -arr[idx];
        vector<vector<int>> ans;
        vector<int> v;
        
        for (int i = start; i < n; i++){
            int num = target - arr[i];
            if (mp.find(num) != mp.end()){
                for (auto it: mp[num]){
                    ans.push_back({idx, it, i});
                }
            }
            mp[arr[i]].push_back(i); 
        }
        
        return ans;
    }
    vector<vector<int>> findTriplets(vector<int> &arr) {
    int n = arr.size();
        
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            vector<vector<int>> temp = findSet(arr, i + 1, i);
            for (auto it: temp){
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
