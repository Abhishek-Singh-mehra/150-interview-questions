/*Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.*/

/*******************************approach 1 ************************ */
/* the intution is  that we will lok if the node have the left child if yes the nwe have to connect that eft child right most node to the
 curr node right child we will connect it to the right child and and break the relation of right child and move make it wit hte left child
 as right child  and move to right child   then same precoedure as follows .with the left child if it have left child to .*/
/* time complexity O(n)
   space compleixty O(1)
   leetcdoe link = https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150 */
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
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                TreeNode *temp = curr->left;
                while (temp->right != nullptr)
                {
                    temp = temp->right; // finding right most child of left child .
                }
                temp->right = curr->right;//making new connection.
                curr->right = curr->left;//new right child.
                curr->left = nullptr; //breaking he connection.
            }
            curr = curr->right;
        }
    }
};
