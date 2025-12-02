#include <iostream>
#include <vector>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
    
    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    
    // Node y = Node(arr[0], nullptr);
    // cout << y.data<<endl;
    // cout<<&y;

    Node* y = new Node(arr[0], nullptr);
    cout << y->data<<endl;
    cout << (*y).data<<endl;
    cout<<y;

    return 0;
}
