#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char data;
  struct node * left;
  struct node * right;
}node;

// 재귀 형태로 각각 구현하기 

// 포인터를 사용하여 구현하는 것이 헷갈리는 거 같다...

//전위 순회
int preorder(node * n){
  if (n == NULL)
    return 0;
  printf("%c",n->data);
  preorder(n->left);
  preorder(n->right);
  return 0;
}

//중위순회
int inorder(node * n){
  if (n == NULL)
    return 0;
  inorder(n->left);
  printf("%c",n->data);
  inorder(n->right);
  return 0;
}

//후위 순회
int postorder(node* n){
  if (n == NULL)
    return 0;
  postorder(n->left);
  postorder(n->right);
  printf("%c",n->data);
  return 0;
}

int main(){
  int k;
  scanf("%d",&k);
  getchar();
  
  node * n = (node*)malloc(sizeof(node)*100);

  for(int i = 0; i < k; i++)
    {
      n[i].data = i + 'A'; // 일단 문자를 저장
      n[i].left = NULL;
      n[i].right = NULL;
    }
  
  for (int i = 0; i < k; i++){
    char input[3];
    scanf("%c %c %c",&input[0],&input[1],&input[2]);
    getchar();
    if (input[1] != '.')
      n[input[0]-'A'].left = &n[input[1]-'A'];
    else
      n[input[0]-'A'].left = NULL;
    if(input[2] != '.')
      n[input[0]-'A'].right = &n[input[2]-'A'];
    else
      n[input[0]-'A'].right = NULL;
  }
  
  preorder(&n[0]);
  printf("\n");
  inorder(&n[0]);
  printf("\n");
  postorder(&n[0]);

  free(n);
}