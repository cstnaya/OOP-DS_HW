#include<bits/stdc++.h>
#include"Link_List.h"
using namespace std;

	Link_List::Link_List(int n){
		size=1;
		
		head = new Int_Node;
		tail = new Int_Node;
		head->pre = NULL;
		tail->next = NULL;
		
		Int_Node *newnode = new Int_Node;
		newnode->value = n;
		head->next = newnode;
		newnode->pre = head;
		newnode->next = tail;
		tail->pre = newnode;
		
	}
	
	Link_List::Link_List(const Link_List &LL){
		*this = LL;
	}
	
	Link_List::~Link_List(){
		this->size = 0;
		Int_Node *tmp = head;
		while(head!=tail){
			head = head->next;
			delete tmp;
			tmp = head;
		}
		delete head;
	}
	
	int Link_List::getSize() const{
		return size;
	}
	
	const Link_List& Link_List:: operator=(const Link_List &LL){
		size = LL.size;
		Int_Node *ptr = LL.head->next;
		
		head = new Int_Node;
		tail = new Int_Node;
		head->pre = NULL;
		tail->next = NULL;
		
		Int_Node *current = head;
		
		for(int i=1; i<=LL.size; i++){
			Int_Node *newnode = new Int_Node;
			newnode->value = ptr->value;
			current->next = newnode;
			newnode->pre = current;
			newnode->next = tail;
			tail->pre = newnode;
			current = current->next;
			ptr = ptr->next;
		}	
	}
	
	bool Link_List::operator==(const Link_List &LL) const{
		if (this->size != LL.size)	return 0;
		else 
		{
			Int_Node *stream = head->next;
			Int_Node *streamLL = LL.head->next;
			
			for(int i=1;i<=size;i++){
				if (stream->value != streamLL->value)
					return 0;
				stream = stream->next;
				streamLL = streamLL->next;
			}
			
			return 1;
		}
	}
				 
	int& Link_List::operator[](int n){
		Int_Node *current = head;
		for (int i=1; i<=n; i++)
			current = current->next;
		return current->value;
	}	
						
	int Link_List::operator[](int n) const{
		Int_Node *current = head;
		for (int i=1; i<=n; i++)
			current = current->next;
		return current->value;
	}
	
	bool Link_List::insert_node(int num){ 
		return insert_node(size, num);
	}
	
	bool Link_List::insert_node(int n, int num){
		Int_Node *current = head;
		for(int i=1;i<=n;i++)
			current = current->next;
		
		Int_Node *newnode = new Int_Node;
		newnode->value = num;
		newnode->next = current->next;
		newnode->pre = current;
		current->next->pre = newnode;
		current->next = newnode;
		size++;
		return 1;
	}
	
	bool Link_List::delete_node(){
		return delete_node(size);
	}
	
	
	bool Link_List::delete_node(int n){
		Int_Node *current = head;
		for (int i=1; i<=n; i++)
			current = current->next;
		
		current->pre->next = current->next;
		current->next->pre = current->pre;
		delete current;
		size--;
		return 1;
	}	
	
	ostream& operator<<(ostream &out, const Link_List &LL){
		Int_Node *current = LL.head->next;
		for (int i=1; i<=LL.size; i++){
			out << current->value << " ";
			current= current->next;
		}
		return out;
	}

	istream& operator>>(istream &in, Link_List &LL){
		Int_Node *current = LL.tail->pre;
		
		int num;
		cin >> num;
		
		Int_Node *newnode = new Int_Node;
		newnode->value = num;
		newnode->next = LL.tail;
		newnode->pre = current;
		LL.tail->pre = newnode;
		current->next = newnode;
		LL.size++;
		
		return in;
	}
	
	
