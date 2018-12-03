#include<iostream>
#include<queue>
#include<stack>
using namespace std;
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextRight;
} node;

int maxDepth = 0, maxVal = 0;

void deepestLeft(node *root, int left, int level ){
	if(!root)
		return;
	if(!root->left && !root->right && left == -1)
		maxVal = root->data;
	if(level>=maxDepth&&left==1&&root->data>maxVal)
		maxVal = root->data;
	deepestLeft(root->left,1,level+1);
	deepestLeft(root->right,0,level+1);
}

void connect(node *root)
{
   queue<node *> q;
   q.push(root);
   q.push(NULL);
   node *prev = NULL;
   while(1){
       node *temp = q.front();
       if(temp == NULL){
           q.pop();
           prev = NULL;
           if(q.empty()){
               break;
           }
           else{
               q.push(NULL);
               cout<<"\n";
               temp = q.front();
           }
       }
    	if(!prev)
    	{
    		cout<<"NULL ";
		}
		else{
			cout<<prev->data<<" ";
		}
        if(prev)
            prev->nextRight = temp;
       if(temp->left)
        q.push(temp->left);
       if(temp->right)
        q.push(temp->right);
        prev = temp;
       q.pop();
   }
}
void bottomUpLevelOrder(node *root){
    queue<node *> q;
    stack<int> s;
    s.push(-1);
    q.push(root);
    q.push(NULL);
    int level = 0;
    while(1){
        node *temp=q.front();
        if(temp==NULL){
            level++;
            q.pop();
            if(q.empty()){
				break;
            }
            else{
                q.push(NULL);
                s.push(-1);
                temp=q.front();
            }
        }
        s.push(temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
    }
    bool zig = level&1 == 0;
    while(!s.empty()){
    	stack<int> temp;
        while(s.top()!=-1){
        	if(zig)
            	temp.push(s.top());
            else
            	cout<<s.top()<<" ";
            s.pop();
        }
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        s.pop();
        zig=!zig;
        level--;
    }
}
void mirror(node *root){
	if(!root)
		return;
	node *temp=root->left;
	root->left = temp;
	root->right = temp;
	mirror(root->left);
	mirror(root->right);
}

int leafToNodeSum(node *root, long long int value){
    if(root==NULL)
        return 0;
    if(root->left==NULL & root->right==NULL)
    	return value;
    return leafToNodeSum(root->left, value*10+root->data)+leafToNodeSum(root->right, value*10+root->data);
}

int treePathsSumUtil(struct node *root, int val)
{   

    if (root == NULL)  return 0;
    val = (val*10 + root->data);
    if (root->left==NULL && root->right==NULL)
       return val; 
    return treePathsSumUtil(root->left, val) +
           treePathsSumUtil(root->right, val);
}

node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

node *insert(int data, node *root){
	if(root==NULL)
		return newNode(data);
	else{
		if(data>root->data)
		{
			root->right = insert(data,root->right);
		}
		else{
			root->left = insert(data,root->left);
		}
	}
	return root;
}

void inorder(node *root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void preorder(node *root){
	if(root){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

bool search(node *root, int data){
	bool flag=false;
	if(root){
		if(root->data==data)
				flag=true;
		else if(data<root->data)
			flag=search(root->left,data);
		else
			flag=search(root->right,data);
	}	
	return flag;
}

void insert2(int data, node *parent, node *current){
	if(current==NULL){
		if(parent==NULL){
			current = newNode(data);
		}
		else{
			if(parent->data>data){
				parent->left = newNode(data);
			}
			else{
				parent->right = newNode(data);
			}
		}
	}
	else if(data>current->data){
		insert2(data, current, current->right);
	}
	else{
		insert2(data, current, current->left);
	}
}

void insert2(int data, node *parent, node *current,int level){
	if(current==NULL){
		if(parent->data>data){
			parent->left = newNode(data);
		}
		else{
			parent->right = newNode(data);
		}
		cout<<level<<" \n";
	}
	else if(data>current->data){
		insert2(data, current, current->right, level+1);
	}
	else{
		insert2(data, current, current->left, level+1);
	}
}

bool same(node *root, node *root2){
	bool flag = true;
	if((root&&!root2)||(!root&&root2))
		return false;
	if(!root&&!root2)
		return true;
	flag = same(root->left, root2->left);
	if(root->data != root2->data){
		flag = false;
	}
	flag = same(root->right, root2->right);
	return flag;
}

int height(node *root){
    int h;
    if(!root)
        return -1;
    return h=1+max(height(root->left),height(root->right));
}

bool isBST(node *root, int min, int max){
	if(!root)
		return true;
	if(root->data>min&&root->data<max&&isBST(root->left,min, root->data)&&isBST(root->right, root->data, max))
		return true;
	else
		return false;
}

bool isBalanced(node *root){
	int h;
    if(!root)
        return true;
    h=height(root->left)-height(root->right);
//    cout<<h<<" is dif\n";
	if((h==1||h==-1||h==0)&&(isBalanced(root->left)&&isBalanced(root->right)))
		return true;
	else
		return false;
}

void levelOrder(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(1){
        node *temp=q.front();
        if(temp==NULL){
            q.pop();
            if(q.empty()){
				break;
            }
            else{
                q.push(NULL);
                cout<<"\n";
                temp=q.front();
            }
        }
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
    }
}

void zigZagLevelOrder(node *root){
	queue<node *> q;
    q.push(root);
    bool zig= true;
    q.push(NULL);
    stack<int> stk;
    while(1){
        node *temp=q.front();
        if(temp==NULL){
            q.pop();
            if(q.empty()){
            	while(!stk.empty()){
             		cout<<stk.top()<<" ";
             		stk.pop();
				 }
				break;
            }
            else{
                q.push(NULL);
             	while(zig&&!stk.empty()){
             		cout<<stk.top()<<" ";
             		stk.pop();
				 }
				 zig=!zig;
                temp=q.front();
            }
        }
        if(!zig)
        	cout<<temp->data<<" ";
        else
        {
        	stk.push(temp->data);
		}
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        q.pop();
	}
}

int searchPostOrder(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
    return -1;
}

void printPostOrder(int in[], int pre[], int n)
{
    int root = searchPostOrder(in, pre[0], n);
    if (root != 0)
       printPostOrder(in, pre+1, root);
    if (root != n-1)
       printPostOrder(in+root+1, pre+root+1, n-root-1);
    cout << pre[0] << " ";
}
 
void BLL(node *root){
	if(root){
		BLL(root->left);
		cout<<root->data<<" ";
//		if(prev)
//			cout<<"NULL ";
//		else
//			cout<<prev->data<<"\n";
		BLL(root->right);
	}
} 
 
int kthLargest(node *root, int k){
	stack<node *> s;
	node *temp = root;
	int count=0;
	do{
		while(temp){
			s.push(temp);
			temp=temp->left;
		}
		count++;
		node *cur = s.top();
		cout<<cur->data<<" "<<count<<"\n";
		if(count==k)
		{
			return cur->data;
		}
		s.pop();
		temp = cur->right;
	}while(!s.empty()||temp);
}

void inorderStack(node *root, int *arr){
	if(root){
		inorderStack(root->left,arr);
		*arr=root->data;
		arr++;
		inorderStack(root->right,arr);
	}
}
 
int InorderWORec(node *root){
	stack<node *> s;
	node *temp = root;
	do{
		while(temp){
			s.push(temp);
			temp=temp->left;
		}
		node *cur = s.top();
		cout<<cur->data<<" ";
		s.pop();
		temp = cur->right;
	}while(!s.empty()||temp);
} 
 
int main()
{
	int n;
    cin>>n;
    node *root=newNode(n);
    cin>>n;
    while(n!=-1){
        insert2(n,NULL,root);
        cin>>n;
    }	
}
