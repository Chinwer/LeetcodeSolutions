/*
 * 449. Serialize and Deserialize BST
 *
 * Serialization is the process of converting a data structure or object
 * into a sequence of bits so that it can be stored in a file or memory
 * buffer, or transmitted across a network connection link to be
 * reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree.
 *  There is no restriction on how your serialization/deserialization
 * algorithm should work. You just need to ensure that a binary search
 * tree can be serialized to a string and this string can be deserialized to the original tree structure.
 *
 * The encoded string should be as compact as possible.
 * Note: Do not use class member/global/static variables to store states.
 * Your serialize and deserialize algorithms should be stateless.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    private:
        string sep = ",";
        string nul = "#";
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if (!root) {
                return nul + sep;
            }
            string s = to_string(root->val) + sep;
            s += serialize(root->left);
            s += serialize(root->right);
            return s;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            queue<string> nodes = split(data, sep);
            return deserialize(nodes);
        }

        TreeNode* deserialize(queue<string> &nodes) {
            if (nodes.front() == "#") {
                nodes.pop();
                return nullptr;
            }
            TreeNode *root = new TreeNode(stoi(nodes.front()));
            nodes.pop();
            root->left = deserialize(nodes);
            root->right = deserialize(nodes);
            return root;
        }

        queue<string> split(string& data, const string& delim) {
            queue<string> res;
            char* str = strtok((char *) data.c_str(), delim.c_str());
            while (str) {
                res.push(str);
                str = strtok(NULL, ",");
            }
            return res;
        }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
