#ifndef LINK_LIST
#define LINK_LIST


template <class T>
struct Node
{	
	Node<T> *pre, *next;
	T data;
};

template <class T>
class Link_List
{
	template<class U> friend ostream &operator<<(ostream &, const Link_List<U> &);
	template<class U> friend istream &operator>>(istream &, Link_List<U> &);

public:
	//Link_List(){};
	Link_List(T =0);			//default constructor
	Link_List(const Link_List &);	// copy constructor
	~Link_List();
	int getSize() const;
	
	const Link_List &operator=(const Link_List &);		// assignment operator
	bool operator==(const Link_List &) const;			// equality operator
	bool operator!=(const Link_List &right) const		// inequality operator
	{
		return !(*this == right);
	}

	T &operator[](int);								// subscript operator for non-const objects
	T operator[](int) const;						// subscript operator for const objects

	bool insert_node(T);								// insert an integer at the back of link list
	bool delete_node();									// delete the last node
	bool insert_node(int , T);						// insert an integer after the i_th position
	bool delete_node(int);								// delete the i_th node

private:
	int size;
	Node<T> *head, *tail;								// pointer to the first and the last element of Link_List
};

#include<bits/stdc++.h>
using namespace std;
	template <class T>
	Link_List<T>::Link_List(T n){
		size=1;
		
		head = new Node<T>;
		tail = new Node<T>;
		head->pre = NULL;
		tail->next = NULL;
		
		Node<T> *newnode = new Node<T>;
		newnode->data = n;
		head->next = newnode;
		newnode->pre = head;
		newnode->next = tail;
		tail->pre = newnode;
		
	}
	
	template <class T>
	Link_List<T>::Link_List(const Link_List<T> &LL){
		*this = LL;
	}
	
	template <class T>
	Link_List<T>::~Link_List(){
		this->size = 0;
		Node<T> *tmp = head;
		while(head!=tail){
			head = head->next;
			delete tmp;
			tmp = head;
		}
		delete head;
	}
	
	template <class T>
	int Link_List<T>::getSize() const{
		return size;
	}
	
	template <class T>
	const Link_List<T>& Link_List<T>:: operator=(const Link_List<T> &LL){
		size = LL.size;
		Node<T> *ptr = LL.head->next;
		
		head = new Node<T>;
		tail = new Node<T>;
		head->pre = NULL;
		tail->next = NULL;
		
		Node<T> *current = head;
		
		for(int i=1; i<=LL.size; i++){
			Node<T> *newnode = new Node<T>;
			newnode->data = ptr->data;
			current->next = newnode;
			newnode->pre = current;
			newnode->next = tail;
			tail->pre = newnode;
			current = current->next;
			ptr = ptr->next;
		}	
	}
	
	template <class T>
	bool Link_List<T>::operator==(const Link_List<T> &LL) const{
		if (this->size != LL.size)	return 0;
		else 
		{
			Node<T> *stream = head->next;
			Node<T> *streamLL = LL.head->next;
			
			for(int i=1;i<=size;i++){
				if (stream->data != streamLL->data)
					return 0;
				stream = stream->next;
				streamLL = streamLL->next;
			}
			
			return 1;
		}
	}
	
	template <class T>			 
	T& Link_List<T>::operator[](int n){
		Node<T> *current = head;
		for (int i=1; i<=n; i++)
			current = current->next;
		return current->data;
	}	
		
	template <class T>				
	T Link_List<T>::operator[](int n) const{
		Node<T> *current = head;
		for (int i=1; i<=n; i++)
			current = current->next;
		return current->data;
	}
	
	
	template <class T>
	bool Link_List<T>::insert_node(T num){ 
		return insert_node(size, num);
	}
	
	template <class T>
	bool Link_List<T>::insert_node(int n, T num){
		Node<T> *current = head;
		for(int i=1;i<=n;i++)
			current = current->next;
		
		Node<T> *newnode = new Node<T>;
		newnode->data = num;
		newnode->next = current->next;
		newnode->pre = current;
		current->next->pre = newnode;
		current->next = newnode;
		size++;
		return 1;
	}
	
	template <class T>
	bool Link_List<T>::delete_node(){
		return delete_node(size);
	}
	
	template <class T>
	bool Link_List<T>::delete_node(int n){
		Node<T> *current = head;
		for (int i=1; i<=n; i++)
			current = current->next;
		
		current->pre->next = current->next;
		current->next->pre = current->pre;
		delete current;
		size--;
		return 1;
	}	
	
	template <class T>
	ostream& operator<<(ostream &out, const Link_List<T> &LL){
		Node<T> *current = LL.head->next;
		for (int i=1; i<=LL.size; i++){
			out << current->data << " ";
			current= current->next;
		}
		return out;
	}

	template <class T>
	istream& operator>>(istream &in, Link_List<T> &LL){
		Node<T> *current = LL.tail->pre;
		
		T num;
		in >> num;
		
		Node<T> *newnode = new Node<T>;
		newnode->data = num;
		newnode->next = LL.tail;
		newnode->pre = current;
		LL.tail->pre = newnode;
		current->next = newnode;
		LL.size++;
		
		return in;
	}
	
#endif
