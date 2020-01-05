#include "TreeGraphSolution.h"
#include <limits>
#include <iostream>
#include <queue>
using namespace std;

namespace Phoenix
{
    void TreeSolution::RunTestCase(TreeGraphSolutionEnum solutionType)
    {
        switch (solutionType)
        {
            case TreeGraphSolutionEnum::ValidBST:
            {
                TreeNode *root = new TreeNode(1);
                root->left = new TreeNode(-1);
                root->right = new TreeNode(3);
                root->right->left = new TreeNode(0);
                root->right->right = new TreeNode(4);
                cout << isValidBST(root) << endl;
                break;
            }
            case TreeGraphSolutionEnum::BSTLowestComAnc:
            {
                TreeNode *root = new TreeNode(6);
                root->left = new TreeNode(2);
                root->right = new TreeNode(8);
                root->left->left = new TreeNode(0);
                root->left->right = new TreeNode(4);
                root->left->right->left = new TreeNode(3);
                root->left->right->right = new TreeNode(5);
                root->right->left = new TreeNode(7);
                root->right->right = new TreeNode(9);
                TreeNode *p = root->left->left;
                TreeNode *q = root->left->right->right;
                cout << BSTLowestCommonAncestor(root, p, q)->val << endl;
                break;
            }
            case TreeGraphSolutionEnum::NormalLowestComAc:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(5);
                root->right = new TreeNode(1);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(0);
                root->right->right = new TreeNode(8);
                TreeNode *p = root->left;
                TreeNode *q = root->left->right->right;
                cout << NoramlTreeLowestCommonAncestor(root, p, q)->val << endl;
                break;
            }
            case TreeGraphSolutionEnum::LevelOrder:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(9);
                root->right = new TreeNode(20);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(15);
                root->right->right = new TreeNode(7);
                vector<vector<int>> result = levelOrder(root);
                for (int i = 0; i < result.size(); i++)
                {
                    cout << "[";
                    for (int j = 0; j < result[i].size(); j++)
                    {
                        cout << result[i][j] << ",";
                    }
                    cout << "]" << endl;
                }
                break;
            }
            case TreeGraphSolutionEnum::MaxDepth:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(9);
                root->right = new TreeNode(20);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(15);
                root->right->right = new TreeNode(7);
                int result = maxDepth(root);
                cout << result << endl;
                break;
            }
            case TreeGraphSolutionEnum::MinDepth:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(9);
                root->right = new TreeNode(20);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(15);
                root->right->right = new TreeNode(7);
                int result = minDepth(root);
                cout << result << endl;
                break;
            }
            case TreeGraphSolutionEnum::TreeTrie:
            {
                Trie *trie = new Trie();
                trie->insert("apple");
                cout << trie->search("apple") << endl;
                cout << trie->search("app") << endl;
                cout << trie->startsWith("app") << endl;
                trie->insert("app");
                cout << trie->search("appl") << endl;
                break;
            }
            case TreeGraphSolutionEnum::WordSearch1:
            {
                vector<vector<char>> board = {
                    {'A','B','C','E'},
                    {'S','F','C','S'},
                    {'A','D','E','E'}
                    };
                cout << exist(board, "DFSA") << endl;
                cout << exist(board, "SEC") << endl;
                cout << exist(board, "ECFC") << endl;
                break;
            }
            case TreeGraphSolutionEnum::WordSearch2:
            {
                vector<vector<char>> board = {
                    {'o','a','a','n'},
                    {'e','t','a','e'},
                    {'i','h','k','r'},
                    {'i','f','l','v'}
                    };
                vector<string> words = {"oaa","oaan","eat","rain"};
                auto result = findWords(board, words);
                cout << "size=" << result.size() << endl;
                for (auto word : result)
                {
                    cout << word << endl;
                }
                break;
            }
            default:
                break;
        }
    }

    bool TreeSolution::isValidBST(TreeNode* root)
    {
        validBstPreNode = NULL;
        // return validBSTHelper(root);
        return validBSTHelper2(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }

    bool TreeSolution::validBSTHelper(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (validBSTHelper(root->left) == false)
        {
            return false;
        }
        // 二叉搜索树要严格小于/大于才行，不能等于
        if (validBstPreNode != NULL && validBstPreNode->val >= root->val)
        {
            return false;
        }
        validBstPreNode = root;
        return validBSTHelper(root->right);
    }

    bool TreeSolution::validBSTHelper2(TreeNode* root, long min, long max)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val <= min || root->val >= max) 
        {
            return false;
        }

        return validBSTHelper2(root->left, min, root->val) && validBSTHelper2(root->right, root->val, max);
    }

    TreeNode* TreeSolution::BSTLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (root)
        {
            // 由于是二叉搜索树，那么最近公共祖先的值一定是介于p.val和q.val之间
            // 要注意p或q本身就是最近公共祖先的情况
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return root;
    }

    TreeNode* TreeSolution::NoramlTreeLowestCommonAncestorMethod2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode* left = NoramlTreeLowestCommonAncestorMethod2(root->left, p, q);
        TreeNode* right = NoramlTreeLowestCommonAncestorMethod2(root->right, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }

    TreeNode* TreeSolution::NoramlTreeLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (root)
        {
            // 要注意p或q本身就是最近公共祖先的情况
            if (root == p || root == q)
            {
                return root;
            }
            TreeNode *leftResult = FindPorQ(root->left, p, q);
            TreeNode *rightResult = FindPorQ(root->right, p, q);
            // 只有最近公共祖先才能在左右子树同时返回不为null  
            if (leftResult != NULL && rightResult != NULL)
            {
                return root;
            }

            if (leftResult == NULL)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return root;
    }
    // 找寻root下面的子树是否包含P或Q，如果找到则返回最先找到的那个
    TreeNode* TreeSolution::FindPorQ(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        // 先找左边，如果左边找到了就可以直接返回了
        TreeNode *leftResult = FindPorQ(root->left, p, q);
        if (leftResult != NULL)
        {
            return leftResult;
        }
        else
        {
            return FindPorQ(root->right, p, q);
        }

    }

    // 使用BFS计算结果，还有另一种方法是使用DFS（纵向填充result数组）
    vector<vector<int>> TreeSolution::levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        while (!helpQueue.empty())
        {
            int size = helpQueue.size();
            vector<int> temp;
            // 这里可以通过当前队列的数量来判断这一层有多少个节点
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = helpQueue.front();
                temp.push_back(curNode->val);
                helpQueue.pop();
                // 子节点入队
                if (curNode->left != nullptr)
                {
                    helpQueue.push(curNode->left);
                }
                if (curNode->right != nullptr)
                {
                    helpQueue.push(curNode->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }

    int TreeSolution::maxDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int maxDepth = 0;
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        // BFS遍历完整，找到最深的一层
        while (!helpQueue.empty())
        {
            maxDepth++;
            int size = helpQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = helpQueue.front();
                helpQueue.pop();
                // 子节点入队
                if (curNode->left != nullptr)
                {
                    helpQueue.push(curNode->left);
                }
                if (curNode->right != nullptr)
                {
                    helpQueue.push(curNode->right);
                }
            }
        }
        return maxDepth;
    }

    int TreeSolution::minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int minDepth = 0;
        queue<TreeNode*> bfsQue;
        bfsQue.push(root);
        // BFS遍历，找到最早的叶子节点返回就可以了
        while (!bfsQue.empty())
        {
            minDepth++;
            int size = bfsQue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = bfsQue.front();
                if (curNode->left == nullptr && curNode->right == nullptr)
                {
                    return minDepth;
                }
                bfsQue.pop();
                // 子节点入队
                if (curNode->left != nullptr)
                {
                    bfsQue.push(curNode->left);
                }
                if (curNode->right != nullptr)
                {
                    bfsQue.push(curNode->right);
                }
            }
           
        }
        return minDepth;
    }
    #pragma region 字典树

    /** Initialize your data structure here. */
    Trie::Trie() 
    {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void Trie::insert(string word) 
    {
        TrieNode* currentNode = root;
        // 这样写高效一些
        for (char c : word)
        {
            int index = (int)(c - 'a');
            if ((currentNode->children)[c - 'a'] == nullptr)
            {
                (currentNode->children)[c - 'a'] = new TrieNode();
            }
            currentNode = (currentNode->children)[c - 'a'];
        }
        currentNode->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool Trie::search(string word)
    {
        TrieNode* currentNode = root;
        // 这样写高效一些
        for (char c : word)
        {
            int index = (int)(c - 'a');
            if (currentNode->children[index] == nullptr)
            {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool Trie::startsWith(string prefix) 
    {
        TrieNode* currentNode = root;
        for (char c : prefix)
        {
            int index = (int)(c-'a');
            if (currentNode->children[index] == nullptr)
            {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return true;
    }
    #pragma endregion

    bool TreeSolution::exist(vector<vector<char>>& board, string word) 
    {
        if (board.size() <= 0)
        {
            return false;
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (wordSearchDfs(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool TreeSolution::wordSearchDfs(vector<vector<char>>& board, int i, int j, const string &word, int index)
    {
        if (index == word.size())
        {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
        {
            return false;
        }

        if (board[i][j] != word[index])
        {
            return false;
        }

        char tmp = board[i][j];
        board[i][j] = '@';
        if (wordSearchDfs(board, i-1, j, word, index+1) ||
            wordSearchDfs(board, i+1, j, word, index+1) ||
            wordSearchDfs(board, i, j-1, word, index+1) ||
            wordSearchDfs(board, i, j+1, word, index+1))
        {
            board[i][j] = tmp;
            return true;
        }
        else
        {
            board[i][j] = tmp;
            return false;
        }
    }

    vector<string> TreeSolution::findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Trie *root = new Trie();
        // 首先构造一个字典树, 用于在一次dfs中就找到结果
        for (auto word : words)
        {
            root->insert(word);
        }
        set<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                wordSearch2Dfs(board, i, j, root->root, result, "");
            }
        }
        vector<string> res;
        for (auto word : result)
        {
            res.push_back(word);
        }
        return res;
    }    

    void TreeSolution::wordSearch2Dfs(vector<vector<char>>& board, int i, int j, TrieNode *curNode, set<string> &result, string curString)
    {
        // 还有个更优的方法，就是TrieNode在构建的时候保存是第几个单词，这样就不用curString了，只需要从原words数组读就行
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
        {
            return;
        }

        if (board[i][j] == '@')
        {
            return;
        }

        char tmp = board[i][j];
        curString = curString + tmp;
        int index = tmp - 'a';
        if (curNode->children[index] == nullptr)
        {
            return;
        }

        if (curNode->children[index]->isWord)
        {
            result.insert(curString);
        }
        
        board[i][j] = '@';
        wordSearch2Dfs(board, i-1, j, curNode->children[index], result, curString);
        wordSearch2Dfs(board, i+1, j, curNode->children[index], result, curString);
        wordSearch2Dfs(board, i, j-1, curNode->children[index], result, curString);
        wordSearch2Dfs(board, i, j+1, curNode->children[index], result, curString);
        board[i][j] = tmp;
    }
}