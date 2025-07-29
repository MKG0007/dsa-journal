leaders of the array--->elemets on its right side there is no greater element from that element.

broot force--> use nested loop and check on its right that is there any greater element is present or not if present then element is not the leader ele.

  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>

  optimize approach---> we have to traverse the array form the back side and maintain the maxi ele which contain the max element at current time
and if the element is greater than maxi element than it is off course greater then the other elements from its right side.

  class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int size = arr.size();
        vector<int> ans;
        int crr = INT_MIN;
        for(int i = size-1 ; i>=0 ; i--){
            if(arr[i]>=crr){/// condition to check the leader
                ans.push_back(arr[i]);
            }
            
            crr = max(crr , arr[i]);//maintianing the crr greatest element
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
