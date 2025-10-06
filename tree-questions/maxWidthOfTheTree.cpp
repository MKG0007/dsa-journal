// max width of the binary tree 
// width of the tree --> number of nodes on that level + possible nodes in the empty spaces



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        long long ans = 0;
      //using indexing method to know the number of element at every level of the binary tree
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mini = q.front().second; // index of first node in this level

            // variables for the first and last of index of each level 
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                long long curr = q.front().second - mini; // prevent overflow
                TreeNode* node = q.front().first;
                q.pop();

              // storing the values
                if (i == 0) first = curr;
                if (i == size - 1) last = curr;

              // pusing the next and also assigning the index 
                if (node->left)
                    q.push({node->left, curr * 2 + 1});
                if (node->right)
                    q.push({node->right, curr * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};
