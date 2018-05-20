#include <stdio.h>
#include <stdlib.h>
//#include <algorithm>
using namespace std;

struct TreeNode
{
	double val; 
	TreeNode *r;
	TreeNode *l;
};

TreeNode *addToTree(TreeNode *root, double a)
{
	if (root == 0)
	{
		root = new TreeNode;
		root->val = a;
		root->l = root->r = 0;
	}
	else
		if (a < root->val)
			root->l = addToTree(root->l, a);
		else 
			root->r = addToTree(root->r, a);
	return root;
	
}
void makeArray(TreeNode *root, double *a)
{
	static int i = 0;
	if (root == 0) return;
	makeArray(root->l, a);
	a[i++] = root->val;
	makeArray(root->r, a);
}

void freeTree(TreeNode *root)
{
	if (root != 0)
	{
		freeTree(root->l);
		freeTree(root->r);
		delete root;
	}
}
void treeSort(double *a, int n) // бинарные деревья
{
	TreeNode *root = 0;
	for (int i = 0; i < n; i++)
		root = addToTree(root, a[i]);
	makeArray(root, a);
	freeTree(root);
}
void quickSort(double *a, int n) // быстрая
{
	int i = 0, j = n - 1;
	double t;
	double p = a[n / 2];

	while (i <= j)
	{
		while (a[i] < p) i++;
		while (a[j] > p) j--;

		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			//swap(a[i], a[j]);
			i++; 
			j--;
		}
	}
	if (j > 0) quickSort(a, j + 1);
	if (i < n) quickSort(a + i, n - i);


}
void merge(double *a, int mid, int n)
{
	int p1 = 0, p2 = mid, p3 = 0;
	
	double *temp = new double[n];

	while (p1 < mid && p2 < n) // пока хотябы в 1ой части массива не кончатся элементы
	{
		temp[p3++] = (a[p1] < a[p2]) ? a[p1++] : a[p2++];
	}

	while (p1 < mid)
		temp[p3++] = a[p1++];
	while (p2 < n)
		temp[p3++] = a[p2++];
	//копируем temp в a 
	for (int i = 0; i < n; i++)
	{
		a[i] = temp[i];
	}
	delete temp;

}
void mergeSort(double *a, int n) // слияние 
{
	if (n > 1)
	{
		int mid = n / 2;

		mergeSort(a, mid);
		mergeSort(a + mid, n - mid);
		merge(a, mid, n);
	}
}

int main()
{
	//double *m = new double[10];
	double m[10] = { 0,5,8,3,52,43,16,18,15,21 };
	treeSort(m, 10);

	//quicksort(m, 10);

	//mergeSort(m, 10);

	getchar();

}
