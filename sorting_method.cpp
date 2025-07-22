three basic methods to sort the arrary:-

  selection sort:- in this method we find the smallest element of the array in each iteration and place it on left side of the one by one 

    void selectionSort(vector<int> &arr) {
        // code here
        int size = arr.size();
        for(int i = 0 ; i<size-1 ; i++){
            int small_index = i;//crr index of the iteration
          //cosiddering that the crr element is smallest one in the array
            for(int j = i+1 ; j<size ; j++){
                if(arr[small_index] > arr[j]){//updating the small_index 
                    small_index = j;
                }
            }
            swap(arr[small_index] , arr[i]);//after inner loop completes 
          // we have the smallest element of the array of this iteration
          
        }
    }

note:-
  time_complexity for all cases is O(n^2)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------->

bubble sort:- in this method we place the largest element on the right side of the array in every iteration.

      void bubbleSort(vector<int>& arr) {
        int size = arr.size();
        
        for(int i = 0 ; i<size-1 ; i++){
            bool check = true;// check if array is alredy sorted
            for(int j = 1 ; j<size-i ; j++){
                if(arr[j]<arr[j-1]){//placing larger element at the last
                    
                swap(arr[j] , arr[j-1]);
                check = false;
                }
            }
            if(check){
                break;
            }
        }
    }

  note:
  time_complexity in avg , wrost case is O(n^2)
    but in best case O(n)
    
---------------------------------------------------------------------------------------------------------------------------------------------------------------------->

insertion sort:- in this method we take the element and place it into it correct place (by checking the left side of the array every iteration)

    void insertionSort(vector<int>& arr) {
        
        int size = arr.size();
        
        for(int i = 0 ; i<size ; i++){
            
            int j = i;//taken the current iteration element 
            
            while(j>0 && arr[j-1] > arr[j]){// if previous elements are not greater than current element 
            //then shift the element on the right side and place the current element  into its right position
                swap(arr[j-1] , arr[j]);
                j--;
            }
            
        }
    }
note:-
  time_complexity avg , wrost case is O(n^2)
    but in best case O(n)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

  merge Sort:- it is the advanced sorting algorithem in which divide the array and sort the array and then agian combine it (this continues untill all parts become one sized)
  steps for merge sort:
    it considered of tow steps 1->(divide the array) , 2->(combine it in sorted manner)

    void mergeParts(vector<int>&arr , int low , int mid , int high){//step-2(combine the array parts in the sorted manner) 
        vector<int> temp;
        int i = low;
        int j = mid+1;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i = low ; i<=high ; i++){
            arr[i] = temp[i-low];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {//step - 1(dividing the array)
        if(l>=r) return ;
        
        int mid = (l+r)/2;
        
        mergeSort(arr , l , mid);//recursively dividing the array's left part
        mergeSort(arr , mid+1 , r);//recursively dividing the array's right part
        mergeParts(arr , l  , mid , r);//at last combine both parts left and right
    }

time_complexity is O(nlog(n))
space_complexity is O(n)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->


  quick Sort:- it is the another advanced sorting algorithem in which we take any randome element as a pivot and place smaller into it left side or greater element into it right side.
 it considered of three steps-> 
  1)first select the pivot index  
  2)arrange the element around it 
  3)place the pivot into its right place 
  4)call for its left and right parts 

  void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int part_index = partition(arr , low , high);
            
            quickSort(arr , low , part_index-1);
            quickSort(arr , part_index+1 , high);
        }
        
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = low;
        int i = low ;
        int j = high;
        while(i<j){
            while(arr[i]<=arr[pivot] && i<high) i++;
            while(arr[j]>arr[pivot] && j>low) j--;
            
            if(i<j) swap(arr[i] , arr[j]);
        }
        swap(arr[pivot] , arr[j]);
        return j;
    }

  time_complexity is O(nlog(n)) 
  but in wrost case when pivot is selected poorly O(n^2)
  space_complexity is O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
    

    
