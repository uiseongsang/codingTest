#include <bits/stdc++.h>
using namespace std;  
vector<int> adj[1004];
int visited[1004];

void postOrder(int here) {
    if(visited[here] == 0) {
        if(adj[here].size() == 1) postOrder(adj[here][0]); // 왼쪽 자식
        if(adj[here].size() == 2) { // 오른쪽 자식
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1; // 본인 자신
        cout << here << " ";
    }
}

void preOrder(int here) {
    if(visited[here] == 0) {
        visited[here] = 1;
        cout << here << " ";
        if(adj[here].size() == 1) preOrder(adj[here][0]); // 왼쪽 자식
        if(adj[here].size() == 2) { // 오른쪽 자식
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}

void inOrder(int here) {
    if(visited[here] == 0) {
        if(adj[here].size() == 1) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << " ";
        }
        else if(adj[here].size() == 2) {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << " ";
            inOrder(adj[here][1]);
        }
        else {
            visited[here] = 1;
            cout << here << " ";
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    cout << "postOrder: ";
    postOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n";
    cout << "preOrder: ";
    preOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n";
    cout << "inOrder: "; 
    inOrder(root); memset(visited, 0, sizeof(visited));
    cout << "\n";
    return 0;
}
