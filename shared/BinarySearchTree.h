#pragma once

#include <cassert>
#include <iomanip>
#include <iostream>

template <typename K, typename V>
class BinarySearchTree {
   public:
    struct Item  // key와 value의 쌍(pair)
    {
        K key = K();    // first
        V value = V();  // second
    };

    struct Node {
        Item item;

        Node* left = nullptr;
        Node* right = nullptr;
    };

    void Preorder() {
        using namespace std;
        Preorder(root_);
        cout << endl;
    }

    void Preorder(Node* node) {
        using namespace std;
        if (node) {
            cout << node->item.key << " ";
            Preorder(node->left);
            Preorder(node->right);
        }
    }

    void Inorder() {
        using namespace std;
        Inorder(root_);
        cout << endl;
    }

    void Inorder(Node* node) {
        using namespace std;
        if (node) {
            Inorder(node->left);
            cout << node->item.key << " ";
            Inorder(node->right);
        }
    }

    Item* RecurGet(const K& key) { return RecurGet(root_, key); }

    Item* RecurGet(Node* node, const K& key) {
        if (!node) return nullptr;  // <- 동일한 키를 가진 노드를 찾지 못하면 nullptr을 반환하는 기능

        if (key < node->item.key) return RecurGet(node->left, key);
        if (key > node->item.key) return RecurGet(node->right, key);

        return &node->item;  // if (key == node->item.key)
    }

    Item* IterGet(const K& key) {
        // TODO:

        return nullptr;  // No matching
    }

    void Insert(const Item& item) {
        using namespace std;
        cout << "Insert " << item.key << item.value << endl;
        root_ = Insert(root_, item);
    }

    Node* Insert(Node* node, const Item& item) {
        if (!node) return new Node{item, nullptr, nullptr};
        if (node->item.key > item.key) {
            node->left = Insert(node->left, item);
        } else if (node->item.key < item.key) {
            node->right = Insert(node->right, item);
        }
        std::cout << "그냥 리턴" << node->item.value << std::endl;
        return node;
    }

    void IterInsert(const Item& item) {
        // TODO:
        std::cout << item.key << "삽입" << std::endl;
        Node* newNode = new Node{item, nullptr, nullptr};
        if (!root_) {
            root_ = newNode;
            return;
        }
        Node* current = root_;

        while (!IsLeafNode(current)) {
            std::cout << current->item.key << " " << item.key << std::endl;
            if (current->item.key > item.key) {
                if (current->left == nullptr) {
                    break;
                }
                current = current->left;
                continue;
            }
            if (current->item.key < item.key) {
                if (current->right == nullptr) {
                    break;
                }
                current = current->right;
                continue;
            }
        }
        if (current->item.key == item.key) {
            current->item = item;
            delete newNode;
            return;
        }
        if (current->item.key > item.key) {
            current->left = newNode;
            return;
        }
        if (current->item.key < item.key) {
            current->right = newNode;
            return;
        }
    }
    bool IsLeafNode(const Node* node) {
        if (!(node->left) && !(node->right)) return true;
        return false;
    }
    bool IsFullChildrenNode(const Node* node) {
        if ((node->left) && (node->right)) return true;
        return false;
    }

    Node* MinKeyLeft(Node* node) {
        assert(node);
        while (node->left) node = node->left;
        return node;
    }

    void Remove(const K& key) {
        using namespace std;
        cout << "Remove " << key << endl;
        root_ = Remove(root_, key);
    }

    Node* Remove(Node* node, const K& key) {
        if (!node) return node;

        if (key < node->item.key)
            node->left = Remove(node->left, key);
        else if (key > node->item.key)
            node->right = Remove(node->right, key);
        else {  // 타겟을 찾았을때,
            std::cout << "찾았다!" << node->item.key << std::endl;
            // 1.자식이 없을때
            if (IsLeafNode(node)) {
                delete node;
                node = nullptr;
            }
            // 1.자식이 1개일때(자기자신은 삭제하고 부모노드와 연결)
            else if (!IsFullChildrenNode(node)) {
                Node* newNode = node->left ? node->left : node->right;
                delete node;
                return newNode;
            }
            // 2.자식이 2개일때(왼쪽서브트리의 최솟값 혹은 오른쪽서브트리의 최솟값으로 바꾼다.)
            else {
                Node* newNode = node->right;
                Node* parantNode = node;
                while (newNode->left) {
                    parantNode = newNode;
                    newNode = newNode->left;
                }
                parantNode->left = nullptr;
                node->item = newNode->item;
                delete newNode;
            }
        }
        return node;
    }

    int Height() { return Height(root_); }

    int Height(Node* node) {
        if (!node) return 0;
        return 1 + std::max(Height(node->left), Height(node->right));
    }

    void Print2D();
    void PrintLevel(int n);
    void DisplayLevel(Node* p, int lv, int d);

   protected:
    Node* root_ = nullptr;
};

// 디버깅 편의 도구
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template <typename K, typename V>
void BinarySearchTree<K, V>::Print2D() {
    using namespace std;
    cout << "Height = " << Height() << endl;
    int i = 0;
    while (i < Height()) {
        PrintLevel(i);
        i++;
        cout << endl;
    }
    cout << endl;
}

template <typename K, typename V>
void BinarySearchTree<K, V>::PrintLevel(int n) {
    using namespace std;
    Node* temp = root_;
    int val = (int)pow(2.0, Height() - n + 1.0);
    cout << setw(val) << "";
    DisplayLevel(temp, n, val);
}

template <typename K, typename V>
void BinarySearchTree<K, V>::DisplayLevel(Node* p, int lv, int d) {
    using namespace std;
    int disp = 2 * d;
    if (lv == 0) {
        if (p == NULL) {
            cout << "   ";
            cout << setw(disp - 3) << "";
            return;
        } else {
            int result = ((p->item.key <= 1) ? 1 : (int)log10(p->item.key) + 1);
            cout << " " << p->item.key << p->item.value << " ";
            cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
        }
    } else {
        if (p == NULL && lv >= 1) {
            DisplayLevel(NULL, lv - 1, d);
            DisplayLevel(NULL, lv - 1, d);
        } else {
            DisplayLevel(p->left, lv - 1, d);
            DisplayLevel(p->right, lv - 1, d);
        }
    }
}
