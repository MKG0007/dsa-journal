
//find the paths of the given node from the root

// by using inorder travesal
bool paths(TreeNode* root vector<int> &temp , int leaf){
        // finds instead of given node
        //return false;
        if(root == nullptr) return false;

        temp.push_back(root->val);
        // if we findout the given node there is no need to go further
        if(root->val == leaf) return true;

        // in any case the 
        // if the given node is findout then return with true
        if(paths(root->left , temp , leaf) || paths(root->right , temp , leaf)){
            return true;
        }

        // the path is invalid so to removing the element at the time of back tracking
        temp.pop_back();
        return false;


    }
