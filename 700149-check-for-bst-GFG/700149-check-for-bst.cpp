/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool valid(Node* node, long minimum, long maximum) {
        if(node==NULL) return true;
        if(node->data <= minimum || node->data >= maximum) return false;
        return valid(node->left, minimum, node->data) && valid(node->right, node->data, maximum);
    } 
    bool isBST(Node* root) {
        return valid(root, LONG_MIN, LONG_MAX);        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna