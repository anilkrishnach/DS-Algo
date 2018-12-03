#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node *next;
}node;
node *newNode(int data){
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void removeLast(node *root){
	
}
int main(){
	node *root = newNode(5);
}
