#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    std::string key;
    Node* left;
    Node* right;

    Node(const std::string& value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insertRecursive(Node*& node, const std::string& key) {
        if (node == nullptr) {
            node = new Node(key);
        } else {
            if (key < node->key) {
                insertRecursive(node->left, key);
            } else {
                insertRecursive(node->right, key);
            }
        }
    }

    void printBranchesAtLevelRecursive(Node* node, int level) {
        if (node == nullptr) {
            return;
        }

        if (level == 0) {
            std::cout << node->key << " ";
        } else {
            printBranchesAtLevelRecursive(node->left, level - 1);
            printBranchesAtLevelRecursive(node->right, level - 1);
        }
    }

    int countBranchesAtLevelRecursive(Node* node, int level) {
        if (node == nullptr) {
            return 0;
        }

        if (level == 0) {
            return 1;
        }

        int leftCount = countBranchesAtLevelRecursive(node->left, level - 1);
        int rightCount = countBranchesAtLevelRecursive(node->right, level - 1);
        return leftCount + rightCount;
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const std::string& key) {
        insertRecursive(root, key);
    }

    void printBranchesAtLevel(int level) {
        printBranchesAtLevelRecursive(root, level);
        std::cout << std::endl;
    }

    int countBranchesAtLevel(int level) {
        return countBranchesAtLevelRecursive(root, level);
    }
};

int main() {
    srand(time(nullptr));

    BinaryTree tree;
    for (int i = 0; i < 10; ++i) {
        int key = rand() % 100 + 1;
        tree.insert(std::to_string(key));
    }

    int level = 2;
    std::cout << "Branches at level " << level << ": ";
    tree.printBranchesAtLevel(level);

    int branchCount = tree.countBranchesAtLevel(level);
    std::cout << "Number of branches at level " << level << ": " << branchCount << std::endl;

    return 0;
}
