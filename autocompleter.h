// Node structure for the Binary Search Tree
struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

class Autocompleter {
private:
    Node* root;
    
// Helper function to insert a node into the BST
    Node* insert(Node* root, string val) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val < root->data) {
            root->left = insert(root->left, val);
        } else if (val > root->data) {
            root->right = insert(root->right, val);
        }

        return root;
    }

// Helper function to perform in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr)
            return;

        inOrderTraversal(node->left);
        cout << node->data << ", ";
        inOrderTraversal(node->right);
    }

public:
    Autocompleter() : root(nullptr) {}

// Function to insert values into the Autocompleter
    void insert(const vector<string>& values) {
       for (int i = 0; i < values.size(); i++) {
          root = insert(root, values[i]);
      }
    }

// Function to display the whole tree in order
    void displayInOrder() {
        cout << "Tree in order: ";
        inOrderTraversal(root);
        cout << endl;
    }

// Function to return the size of the tree
    int size() {
        return size(root);
    }

// Function to return the height of the tree
    int height() {
        return height(root);
    }

// Function to print all completions of a given prefix
    void completions(string prefix) {
        completionsUtil(root, prefix);
        cout << endl;
    }
    
//Function to print all completions that start with a given prefix 
    void completionsStart(string prefix) {
        completionsStartUtil(root, prefix);
        cout << endl;
    }

// Helper function to calculate the size of the BST
    int size(Node* node) {
        if (node == nullptr)
            return 0;
        else
            return size(node->left) + 1 + size(node->right);
    }

// Helper function to calculate the height of the BST
    int height(Node* node) {
        if (node == nullptr)
            return 0;
        else {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);

            if (leftHeight > rightHeight)
                return leftHeight + 1;
            else
                return rightHeight + 1;
        }
    }

// Helper function to print all completions of a given prefix
    void completionsUtil(Node* root, string prefix) {
        if (root == nullptr)
            return;

// If the current node's data has the prefix, print it
        for ( int i = 0; i <= root->data.length(); i++){//as long as i is not larger than the length of the current node keep going
            
        if (root->data.substr(i, prefix.length()) == prefix) {//uses the loop to check every possible index of every word
                cout << root->data << ", ";
                
                break; //stops reprints of words with recurring prefixes
                
            }
            
        }
// Recursively call completionsUtil on left and right subtrees
        completionsUtil(root->left, prefix);
        completionsUtil(root->right, prefix);
    }
    
// Helper function to print all completions that start with a given prefix
 void completionsStartUtil(Node* root, string prefix){
     if (root == nullptr)
        return;
        
     if (root->data.substr(0, prefix.length()) == prefix) {
                cout << root->data << ", ";
     }
     
      completionsStartUtil(root->left, prefix);
      completionsStartUtil(root->right, prefix);
    }  
};