#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define E '\n'
#define sp <<" "<<

using namespace std;

typedef struct Node {
    ll data;
    Node* left = NULL;
    Node* right = NULL;
} Node;

Node* newNode(ll data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void PreorderTraversal(Node* node){
    if(node == NULL) return;
    cout << node->data << " ";
    PreorderTraversal(node->left);
    PreorderTraversal(node->right);
}

void InorderTraversal(Node* node){
    if(node == NULL) return;
    InorderTraversal(node->left);
    cout << node->data << " ";
    InorderTraversal(node->right);
}

void PostorderTraversal(Node* node){
    if(node == NULL) return;
    PostorderTraversal(node->left);
    PostorderTraversal(node->right);
    cout << node->data << " ";
}

void InsertNode(Node* &root, ll data){
    if(root == NULL){
        root = newNode(data);
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            temp->left = newNode(data);
            return;
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = newNode(data);
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, rt;
    cin >> n;
    cin >> rt;
    Node* root = newNode(rt);
    for(ll i = 1; i<n; i++){
        cin >> rt;
        InsertNode(root, rt);
    }
    PreorderTraversal(root);
    cout << E;
    PostorderTraversal(root);
    cout << E;
    InorderTraversal(root);
    cout << E;
    return 0;

}