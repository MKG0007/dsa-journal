class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        vector<int> preorder, inorder, postorder;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto node = st.top();
            st.pop();

            // State 1 → Preorder
          //push into the preorder and increase the count
          //to make it ready for next order traversal
          //and check for the left node if present push it
          // to start process for that code too
            if (node.second == 1) {
                preorder.push_back(node.first->data);
                node.second++;
                st.push(node); // push back with incremented state
                if (node.first->left != nullptr)
                    st.push({node.first->left, 1});
            }

            // State 2 → Inorder
          //push into the inorder and increase the count
          //to make it ready for next order traversal
          //and check for the left node if present push it
          // to start process for that code too
            else if (node.second == 2) {
                inorder.push_back(node.first->data);
                node.second++;
                st.push(node);
                if (node.first->right != nullptr)
                    st.push({node.first->right, 1});
            }

            // State 3 → Postorder
              // don't need to do anything as its the last step
              //so, there is not traversal after this
            else {
                postorder.push_back(node.first->data);
            }
        }

        ans.push_back(preorder);
        ans.push_back(inorder);
        ans.push_back(postorder);
        return ans;
    }
};

