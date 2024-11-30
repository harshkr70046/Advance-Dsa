#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        char c;
        cout<<"\nenter the array element = ";
        cin>>c;
        arr.push_back(c);
    }
}
void print_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
//! find the smallest number after removing k element.
vector<char> smallest_number(vector<char>&arr,int n,int k){
    stack<char>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()-'0'>arr[i]-'0'){
            st.pop();
            k=k-1;
        }
        st.push(arr[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty()) return {'0'};
    vector<char>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]=='0') ans.pop_back();
        else break;
    }
    reverse(ans.begin(),ans.end());
    if(ans.empty()) return {'0'};
    return ans;
}
//! online stock span 
//! first of fall we have to take the number of days.
void input_days(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int days;
        cout<<"\nenter the number of days = ";
        cin>>days;
        arr.push_back(days);
    }
}
void print_days(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
int maximum_days(vector<int>&days,int n){
    stack<pair<int,int>>st;
    int max_days = 1;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first<=days[i]){
            st.pop();
        }
        int pgei = (st.empty())?-1:st.top().second;
        max_days = max((i-pgei),max_days);
        st.push({days[i],i});
    }
    return max_days;
}
//! sliding window maximum
vector<int> maximum_in_kLength_window(vector<int>&arr,int n,int k){
    vector<int> v; // Store the results
    deque<int> dq; // Store indices of elements in decreasing order

    for (int i = 0; i < n; i++) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove indices of smaller elements as they will never be the maximum
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the maximum of the current window to the result
        if (i >= k - 1) {
            v.push_back(arr[dq.front()]);
        }
    }

    return v;
}

//! celebraty problem
void input_fan(vector<vector<int>>&arr,int n){
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            int num;
            cout<<"\nenter the fan = ";
            cin>>num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
}
int celebraty_solution(vector<vector<int>>&arr,int n){
    vector<int>Knowme(n);
    vector<int>iKnow(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                Knowme[j]++;
                iKnow[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(Knowme[i]==n-1 && iKnow[i]==0){
            return i;
        }
    }
    return 0;
}
//! optimal code
int optimal_code_for_celebraty(vector<vector<int>>&arr,int n){
    int top = 0;
    int down = n-1;
    while(top<down){
        if(arr[top][down]==1) top++;
        else if(arr[down][top]) down--;
        else{
            top--;
            down--;
        }
    }
    if(top>down) return -1;
    for(int i=0;i<n;i++){
        if(i==top) continue;
        if(arr[top][i]==0 && arr[i][top]==1);
        else return -1; 
    }
    return top;
}
class node{
    public:
    int data;
    node* next;
    node* prev;
    public:
    node(int data1,node* next1,node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the element of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
node* convert_array_to_dll(vector<int>&arr,int n){
    node* head = new node(arr[0]);
    node* mover = head;
    
    for(int i=1;i<n;i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}
void print_dll(node* head){
    node* mover = head;
    node* p = nullptr;
    while(mover!=nullptr){
        cout<<mover->data<<"    ";
        p = mover;
        mover = mover->next;
    }
    cout<<endl;
    while(p!=nullptr){
        cout<<p->data<<"     ";
        p = p->prev;
    }
    cout<<endl;
}
node* delete_node(node* head,int val,int pos){
    node* mover = head;
    int cnt = 1;
    while(mover!=nullptr){
        if(cnt==pos-1) break;
        mover = mover->next;
        cnt++;
    }
    node* value = new node(val);
    node* deltemp = mover->next;
    mover->next = value;
    value->prev = mover;
    value->next = deltemp->next;
    node* front = deltemp->next;
    front->prev = value;
    return head;
}

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};
int main(){
    // int n;
    // cout<<"\nenter the size of the array = ";
    // cin>>n;
    // vector<char>v;
    // input_array(v,n);
    // cout<<endl;
    // print_array(v,n);
    // vector<char>ans = smallest_number(v,n,3);
    // cout<<endl;
    // print_array(ans,ans.size());
    // vector<int>arr;
    // input_days(arr,n);
    // print_days(arr,n);
    // cout<<"\n Maximum consiqutive days = "<<maximum_days(arr,n);
    // vector<int>ans = maximum_in_kLength_window(arr,n,3);
    // cout<<endl;
    // print_days(ans,ans.size());
    // vector<vector<int>>arr;
    // input_fan(arr,n);
    // cout<<"\ncelebraty = "<<optimal_code_for_celebraty(arr,n);
    // vector<int>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    // node* head = convert_array_to_dll(arr,n);
    // print_dll(head);
    // node* upadte = delete_node(head,7,3);
    // print_dll(upadte);

}