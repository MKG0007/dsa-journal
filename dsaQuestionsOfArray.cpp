Spirally traversing a matrix(traverse the array into spiral form)
this is the implementation quesiton so there no broot approach for it. it is just to test that how effecienly you can do the it(without any messy code)

so , as we observed in any matrix we have to store all sides traversal one by one untill we get to the middle because at the middle we don't have to treverse through to left column
let's see how we can code

solution

fn(vector<vector<int>> &arr){
  int row = arr.size();
  int col = arr[0].size();

  int top = 0 ,  btm = row-1 , left = 0 , right = col-1;
  while(top<=btm && left<=right){
    for(int i = left ; i<=right ; i++){
      //edges case--> if there are only one row this loop will treverse it
      ans.push_back(arr[top][i]); // top is constant | col is variable
    }
    top++;
    //and for the top to bottum treverse (when top>buttom it will treverse)
    //no need for any checks

    for(int i = top ; i<=btm ; i++){
      ans.push_back(arr[i][right]);
    }
    right--;
    
    if(top<=buttom){//if top exceeds the bottum  then don't have to print right to left in the bottum
      for(int i = right ; i>=left ; i--){
        and.push_back(arr[btm][i]);
      }
    }
    btm--;
    if(left<=right){//if left exceeds the right then don't have to print bottum to top from the left side
      for(int i = btm ; i>=top ; i--){
        ans.push_back(arr[i][left]);
      }
    }
    left++;

  }

  return ans;
}
