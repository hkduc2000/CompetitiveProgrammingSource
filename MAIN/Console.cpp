#include <bits/stdc++.h>
using namespace std;

//define---------------
struct node
{
	int data;
	struct node *left, *right;
};
typedef node* KimDuc;
vector <node*> roots;
int n, k;
int ans;
//---------------------

//function-------------
node* newNode(int data)
{
	node* Node = new node;
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return(Node);
}

node* insert(struct node* node, int data)
{
	//insert
	if (node == NULL) return newNode(data);

	if (data < node->data) {
		node->left = insert(node->left, data);
	}
	else if (data > node->data) {
		node->right = insert(node->right, data);
	}
	//unchanged
	return node;
}

bool isSame(node* a, node* b)
{
	//both empty -> true
	if (a == NULL && b == NULL) {
		return true;
	}

	//both not empty -> go deeper
	if (a != NULL && b != NULL)
	{
		return	(isSame(a->left, b->left) && isSame(a->right, b->right));
	}

	//different -> false
	return false;
}


//---------------------

void input()
{
	cin >> n >> k;
	roots.resize(n);
	int inpNode;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> inpNode;
			if (j == 0) {
				roots[i] = insert(roots[i], inpNode);
			}
			else {
				insert(roots[i], inpNode);
			}

		}
	}
}

void solve()
{
	//except number of same struct tree
	ans = n;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			ans -= isSame(roots[i], roots[j]);
		}
	}

}

void output()
{
	cout << ans;
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef HKD
   freopen("E:/C++/input.txt", "r", stdin);
   freopen("E:/C++/output.txt", "w", stdout);
   auto start = chrono::steady_clock::now();
   {
      input();
      solve();
      output();
   }
   auto end = chrono::steady_clock::now();
   chrono::duration<double> diff = end - start;
   cout << endl
        << "Time: " << diff.count() << " s\n";
   return 0;

#endif // DEBUG
	{
		input();
		solve();
		output();
	}
   return 0;
}