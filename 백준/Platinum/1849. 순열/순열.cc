#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int tree[MAX*4];
int result[MAX];

int init(int node, int start, int end){
  if(start == end)
    return tree[node] = arr[start];
  int mid = (start + end) / 2;
  return tree[node] = init(node * 2, start, mid) +
    init(node * 2 + 1, mid + 1, end);
}

int find(int node, int start, int end, int num){
  if(start == end)
    return end;
  int mid = (start + end) / 2;
  int left = tree[node * 2]; 

  if(left > num )
    return find(node* 2, start, mid, num);
  else{
    return find(node * 2 + 1, mid + 1, end, num - left);
  }
}

void update(int node, int start, int end, int index){
  if (index < start || index > end)
    return;
  
  tree[node] -= 1;
  if(start != end){
    int mid = (start + end)/2;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);
  }
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++){
    arr[i] = 1;
  }
  init(1,1,n);
  for(int i = 1; i <= n; i++){
    int v;
    scanf("%d",&v);
    int index = find(1,1,n,v);
    //cout << index;
    result[index] = i;
    update(1,1,n,index);
  }
  for(int i = 1; i <= n; i++){
    printf("%d\n",result[i]);
  }
}