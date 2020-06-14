# linked list

#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;
node(int d){
data=d;
next=NULL;
}
};
void Inseratfront(node * &head,node * &tail,int data){
if(head==NULL){
    head=tail=new node (data);
}
else{
    node *n=new node(data);
    n->next=head;
    head=n;
}
}
void Inseratend(node * &head,node * &tail,int data)
{
if(head==NULL){
    head=tail=new node (data);
}
else{
    node *n=new node(data);
    tail->next=n;
    tail=n;
}
}
int len(node *head){
int count=0;
while(head){
    count++;
    head=head->next;
}
return count;
}
void Inseratmid(node * &head,node * &tail,int post,int data)
{
if(post == 0){
    Inseratfront(head,tail,data);
}
else if(post >= len(head)-1){
    Inseratend(head,tail,data);
}
else{
    node *temp;//want to save my linked list somewhere
    temp=head;
    int count=1;
    while(count<=post-1){
        temp=temp->next;
        count++;
    }
    node *n=new node(data);
    n->next=temp->next;
    temp->next=n;
}
}
void deleteatfront(node * &head,node * &tail){
if(head==NULL){
    return;
}
else if(head->next==NULL){
    delete head;
    head=tail=NULL;
}
else{
    node *temp=head;
    head=head->next;
    delete temp;
}
}
void deleteatend(node * &head,node * &tail){
if(head==NULL){
    return;
}
else if(head->next==NULL){
    delete head;
    head=tail=NULL;
}
else{
    node *temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    delete tail;
    tail=temp;
    temp->next=NULL;
}
}
void deleteatmid(node * &head,node * &tail,int post){
if(post ==0){
    deleteatfront(head,tail);
}
else if(post >= len(head)-1){
    deleteatend(head,tail);
}
else{
    node*temp=head;
    int count=1;
    while(count <= post-1){
        temp=temp->next;
        count++;
    }
    node *n=temp->next;
    temp->next=n->next;
    delete n;
}
}
void Print(node* head){
	while(head){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}

int main(){
node *head=NULL;
node *tail=NULL;
Inseratfront(head,tail,1);
Inseratfront(head,tail,2);
Inseratfront(head,tail,3);
Inseratfront(head,tail,4);
Inseratfront(head,tail,5);
Print(head);
Inseratend(head,tail,6);
Print(head);
Inseratmid(head,tail,3,7);
Print(head);
deleteatfront(head,tail);
Print(head);
deleteatmid(head,tail,2);
Print(head);
}

