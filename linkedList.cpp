#include <iostream>
#include <string.h>
using namespace std;
class Node{
	private:
		char elem;
		Node* next;
		friend class LinkedList;
};
class LinkedList{
	public:
		LinkedList();
		~LinkedList();
		bool empty() const;
		void addFront(const char& e);
		void removeFront();
		void print();
	private:	
		Node* head;
};
LinkedList::LinkedList()
	:head(NULL){}
LinkedList::~LinkedList(){
	while(!empty()) removeFront();
}
bool LinkedList::empty() const{
	return head==NULL;
}
void LinkedList::addFront(const char& e){
	Node* v= new Node;
	v->elem=e;
	v->next=head;
	head=v;
}
void LinkedList::removeFront(){
	Node* old=head;
	head=old->next;
	delete old;
}
void LinkedList::print(){
	for(Node* temp=head; temp!=NULL;temp=temp->next){
		cout<<temp->elem<<" ";
	}
	cout<<endl;
}
int main(){
	LinkedList* ll= new LinkedList;
	char s;
	while(1){
	cout<<"Enter the command(a(addFront)/r(removeFront)/p(print)) : ";
	cin>>s;
	switch(s){
		case 'a' :
			cout<<"Enter the character : ";
			char e;
			cin>>e;
			ll->addFront(e);
			break;
		case 'r' : 
			ll->removeFront();
			break;
		case 'p' :
			ll->print();
			break;
		}
	}
	return 0;
}
