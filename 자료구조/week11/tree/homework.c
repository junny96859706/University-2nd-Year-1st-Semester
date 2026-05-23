#include <stdio.h>
#include <stdlib.h> //동적할당을 위한 헤더

typedef struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

void preorder(TreeNode* root) { //이진트리 전위순회 함수
	if (root != NULL) {
		printf("%d =>",root->data); //노드방문
		preorder(root->left); //왼쪽서브트리 순회
		preorder(root->right); //오른쪽서브트리 순회
	}
}

int Max = INT_MIN; //컴퓨터가 표현할수 있는 가장 작은 음수
int Min = INT_MAX; //컴퓨터가 표현할수 있는 가장 큰 양수

int find_Max(TreeNode* root) {
	if (root != NULL) {
		if (Max < root->data)
			Max = root->data;

		find_Max(root->right);
		find_Max(root->left);
	}
	return Max;
}

int find_Min(TreeNode* root) {
	if (root != NULL) {
		if (Min > root->data)
			Min = root->data;

		find_Min(root->right);
		find_Min(root->left);
	}
	return Min;
}

int main() {
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10; //첫번째 노드 설정
	n1->left = n2;
	n1->right = n3;

	n2->data = 20; //두번째  노드 설정
	n2->left = NULL;
	n2->right = NULL;
	 
	n3->data = 30; //세번째 노드 설정
	n3->left = NULL;
	n3->right = NULL;

	printf("최소값:%d\n", find_Min(n1));
	printf("최댓값:%d", find_Max(n1));

	free(n1); free(n2); free(n3);
	return 0;
}
