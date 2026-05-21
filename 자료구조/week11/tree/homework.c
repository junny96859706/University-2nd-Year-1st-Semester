#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //동적할당을 위한 헤더

//일반 이진 트리에서 최대값과 최소값을 탐색하기 위한 함수를 작성하세요.
// 이진 탐색 트리가 아닙니다!
//(hint: 순환호출을 사용하세요.)

typedef struct {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d =>",root->data); //노드방문
		preorder(root->left); //왼쪽서브트리 순회
		preorder(root->right); //오른쪽서브트리 순회
	}
}

int Max = 0;

int find_Max(TreeNode* root) {
	if (root != NULL) {
		if (Max < root->data)
			Max = root->data;

		find_Max(root->right);
		find_Max(root->left);
	}
	return Max;
}

int find_Low(TreeNode* root) {

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
//---------------------------------------

	printf("전위순회");
	preorder(n1);

	free(n1); free(n2); free(n3);
	return 0;
}
