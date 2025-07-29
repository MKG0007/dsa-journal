permutation:- all possible way of arranging the given structure

in the question they have given the permutation of the array and we have to find its next closest permutation 

broot force --->
first we generate all possible permutation of the given array in sorted order and try to find the given array in it by using linear search and its next one going to be the answer
if the array at the last position himself then first permutation is the answer.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

  better approach---> we can use stl library function present in the cpp
code -> next_permutation(arr.begin() , arr.end());

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

  optimize approach--->
  as we know in the dictionary the order of the word depend on the common priffix
large common preffix word comes before the small common priffix word 

so , according to this we have to find the common priffix size large as musch as possible but priffix should be selected that  after arrangement of the elements the number must slightly large then the present number.

  code-->
  class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        // step-1 find the largest priffix with similar value
        int index = -1;
        for(int i = n-2 ; i>=0 ; i--){//finding the preffix break point
            if(arr[i] < arr[i+1]){
                index = i;
                break;
            }
        }
        
        if(index == -1) {// if there is no break point then that means array is on the last of the sequences
            reverse(arr.begin() , arr.end());
            return ;
        }
        
        for(int i = n-1 ; i>index ; i--){//after finding the break point we have to place the sloghtly smaller element
            if(arr[index]<arr[i]){
                swap(arr[index] , arr[i]);
                break;
            }
        }
        
        reverse(arr.begin()+index+1, arr.end());//after all the previous steps sort the remaining part


        
    }
};
