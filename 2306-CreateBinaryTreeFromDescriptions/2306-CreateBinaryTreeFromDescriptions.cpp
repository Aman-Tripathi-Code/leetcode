// Last updated: 6/8/2026, 2:08:19 AM
/**
 * Definition for a binary tree node.
  * struct TreeNode {
   *     int val;
    *     TreeNode *left;
     *     TreeNode *right;
      *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
       *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
         * };
          */
          class Solution {
          public:
              TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
                      unordered_map<int,TreeNode*> mp;
                              unordered_set<int> children;
                                      for(auto &it: descriptions){
                                                  int par = it[0], child = it[1], isLeft = it[2];
                                                              if(mp.find(par) == mp.end()){
                                                                              TreeNode* parNode = new TreeNode(par);
                                                                                              mp[par] = parNode;
                                                                                                          }
                                                                                                                      if(mp.find(child) == mp.end()){
                                                                                                                                      TreeNode* childNode = new TreeNode(child);
                                                                                                                                                      mp[child] = childNode;
                                                                                                                                                                  }

                                                                                                                                                                              if(isLeft){
                                                                                                                                                                                              mp[par]->left = mp[child];
                                                                                                                                                                                                          }else{
                                                                                                                                                                                                                          mp[par]->right = mp[child];
                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                  children.insert(child);
                                                                                                                                                                                                                                                          }
                                                                                                                                                                                                                                                                  for(auto &it: mp){
                                                                                                                                                                                                                                                                              if(children.count(it.first) == 0){
                                                                                                                                                                                                                                                                                              return it.second;
                                                                                                                                                                                                                                                                                                          }
                                                                                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                                                                                          return nullptr;
                                                                                                                                                                                                                                                                                                                              }
                                                                                                                                                                                                                                                                                                                              };