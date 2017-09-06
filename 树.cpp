#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

class ListNode {
public:
	int val;
	class ListNode * next;
	ListNode(int x) :val(x), next(NULL) {}
};

//Definition for binary tree
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) {
		val = x;
	}
};

class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL || pRoot1 == NULL)
			return false;
		return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}

	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL)
			return false;
		return pRoot1->val == pRoot2->val && isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
	}
};

void Mirror(TreeNode* root) {
	if (root == NULL || root->left == NULL || root->right == NULL)
		return;
	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	if (root->left)
		Mirror(root->left);
	if (root->right)
		Mirror(root->right);
}

void Print(TreeNode* root) {
	if (root == NULL)
		return;
	cout << root->val << endl;
	Print(root->left);
	Print(root->right);
}

bool isSymmertrical(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL&&root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;
	if (root1->val != root2->val)
		return false;

	return isSymmertrical(root1->left, root2->right) && isSymmertrical(root1->right, root2->left);
}

void PrintBFS(TreeNode* root) {
	if (root == NULL)
		return;
	deque<TreeNode*> mydeq;
	mydeq.push_back(root);

	while (mydeq.size() != 0) {
		TreeNode* tmp = mydeq.front();
		cout << tmp->val << " ";
		mydeq.pop_front();

		if (tmp->left)
			mydeq.push_back(tmp->left);
		if (tmp->right)
			mydeq.push_back(tmp->right);
	}
}

//5,7,6,9,11,10,8
bool VertifySequencyOfBSF(int ary[], int len) {
	if (ary == NULL || len <= 0)
		return 0;
	int root = ary[len - 1];
	int i=0, j;
	for (; i < len; i++) {
		if (ary[i] > len) {
			break;
		}
	}
	//左子树是0...i-1
	for (j = i; j < len; j++) {
		if (ary[j] < len) {
			return false;
		}
	}
	//右子树是i...len-1
	bool left = true;
	if (i > 0)
		left = VertifySequencyOfBSF(ary, i);
	bool right = true;
	if (j < len - 1)
		right = VertifySequencyOfBSF(ary + i, len - i - i);

	return left&&right;
}

void FindPath(TreeNode* root, int SumExpect, vector<TreeNode*> path, int SumCur) {
	SumCur += root->val;
	path.push_back(root);
	if (SumExpect == SumCur && root->left == NULL && root->right == NULL) {
		//print
		for (vector<TreeNode*>::iterator it = path.begin(); it != path.end(); it++) {
			cout << (*it)->val << " ";
		}
		cout << endl;
	}
	if (root->left)
		FindPath(root->left, SumExpect, path, SumCur);
	if (root->right)
		FindPath(root->right, SumExpect, path, SumCur);

	path.pop_back();
}

void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList)
{
	if (pNode == nullptr)
		return;

	TreeNode *pCurrent = pNode;

	if (pCurrent->left != nullptr)
		ConvertNode(pCurrent->left, pLastNodeInList);

	pCurrent->left = *pLastNodeInList;
	if (*pLastNodeInList != nullptr)
		(*pLastNodeInList)->right = pCurrent;

	*pLastNodeInList = pCurrent;

	if (pCurrent->right != nullptr)
		ConvertNode(pCurrent->right, pLastNodeInList);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode *pLastNodeInList = nullptr;
	ConvertNode(pRootOfTree, &pLastNodeInList);

	// pLastNodeInList指向双向链表的尾结点，
	// 我们需要返回头结点
	TreeNode *pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->left != nullptr)
		pHeadOfList = pHeadOfList->left;

	return pHeadOfList;
}

void PrintList(TreeNode* head) {
	while (head != NULL && head->right != NULL)
	{
		head = head->right;
		cout << head->val << " ";
	}
	cout << endl;
}


int main()
{
	TreeNode* Aroot = new TreeNode(8);
	TreeNode* Anode1 = new TreeNode(8);
	TreeNode* Anode2 = new TreeNode(7);
	TreeNode* Anode3 = new TreeNode(9);
	TreeNode* Anode4 = new TreeNode(2);
	TreeNode* Anode5 = new TreeNode(4);
	TreeNode* Anode6 = new TreeNode(7);
	Aroot->left = Anode1;
	Aroot->right = Anode2;
	Anode1->left = Anode3;
	Anode1->right = Anode4;
	Anode4->left = Anode5;
	Anode4->right = Anode6;

	TreeNode* Broot = new TreeNode(8);
	TreeNode* Bnode1 = new TreeNode(7);
	TreeNode* Bnode2 = new TreeNode(9);
	Broot->left = Bnode1;
	Broot->right = Bnode2;
	
	//cout << "Mirror" << endl;
	//Print(Aroot);
	//cout << endl;
	//Mirror(Aroot);
	//Print(Aroot);
	//cout << endl << "Mirror" << endl;

	//cout << endl << "Symmertrical" << endl;
	//if (isSymmertrical(Broot, Broot))
	//	cout << "Yes" << endl;
	//else
	//	cout << "No" << endl;
	//cout << endl << "Symmertrical" << endl;

	//cout << endl << "BSF" << endl;
	//PrintBFS(Aroot);
	//cout << endl << "BSF" << endl;

	//cout <<endl<< "VertifySequencyOfBSF" << endl;
	//int ary[] = { 5,7,6,9,11,10,8 };
	//int len = sizeof(ary) / sizeof(ary[0]);
	//if (VertifySequencyOfBSF(ary, len))
	//	cout << "Yes" << endl;
	//else
	//	cout << "No" << endl;
	//cout << endl << "VertifySequencyOfBSF" << endl;

	//cout << endl << "FindPath" << endl;
	//vector<TreeNode*> path;
	//FindPath(Aroot, 22, path, 0);
	//cout << endl << "FindPath" << endl;

	cout << endl << "Convert" << endl;
	PrintList(Convert(Broot));
	cout << endl << "Convert" << endl;

	getchar();
	return 0;
}
