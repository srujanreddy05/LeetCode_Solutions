#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int > map;
     map[0]= 1;
     int prefixSum = 0;
     int count = 0;
     for (int num : nums){
        prefixSum += num;
        if(map.find(prefixSum - k) !=map.end()){
            count += map[prefixSum-k];
        }
        map[prefixSum]++;
     }  
     return count ;
    }
};