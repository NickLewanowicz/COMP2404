//This template requires the object type has:
//	Function: getInfo(), "string getInfo(); " to return info of the object.


#ifndef DLIST_H
#define DLIST_H


#include <sstream>
#include <string>
#include "Course.h"

template <class T>
class DList
{
	template<class V>
	friend ostream& operator<<(ostream&, DList<V>&);
	class Node
  {
    friend class DList;
    private:
      T* data;
      Node* next;
			Node* prev;
  };
	public:
		DList();
		~DList();
		void	add(T*);
		void  removeCourse(T*);
		//string forward();
		//string backward();
		T* find(int);
		int		getNumNodes();
		T*	getCourse(int);
		T* getCourse(string);
    stringstream operator<<(DList<T>*);
    DList<T>& operator+=(T*);
    DList<T>& operator+=(T&);
		DList<T>& operator+=(DList<T>*);
    DList<T>& operator+=(DList<T>&);
    DList<T>& operator-=(T*);
    DList<T>& operator-=(T&);
    DList<T>& operator-=(DList<T>*);
    DList<T>& operator-=(DList<T>&);
	private:
		int		numNodes;
		Node* head;
};

template <class T>
DList<T>::DList()
	: head(0)
{
};

template <class T>
DList<T>::~DList()
{
	Node* currNode = head;
	Node* nextNode;
	while(currNode != 0)
	{
		nextNode = currNode->next;
		delete currNode -> data;
		delete currNode;
		currNode = nextNode;
	}
	head = 0;
};

template <class T>
int DList<T>::getNumNodes()
{
	int num = 0;
	Node* currNode = head;
	while(currNode != 0){
		currNode = currNode->next;
		num++;
	}

	return num;
} //temp

template <class T>
ostream& operator<<(ostream& theString, DList<T>& arr){
	//theString << "Printed using the '<<' operator: " << endl;
	if (arr.getNumNodes() == 0){
		theString << "No items.";
	}
	theString << endl;
	for (int i=0; i<arr.getNumNodes(); ++i) {
		T* c = arr.find(i);
		theString << c->getInfo();
		}
		theString << endl;
	return theString;
}

template <class T>
DList<T>& DList<T>::operator+=(T* course){
    add(course);
    return (*this);
}

template <class T>
DList<T>& DList<T>::operator+=(T& course){
    add(&course);
    return (*this);
}

template <class T>
DList<T>& DList<T>::operator+=(DList<T>* list){
	Node* currNode = list->head;
	while(currNode != 0){
		add(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
  return (*this);
}

template <class T>
DList<T>& DList<T>::operator+=(DList<T>& list){
	Node* currNode = list.head;
	while(currNode != 0){
		add(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
	return (*this);
}

template <class T>
DList<T>& DList<T>::operator-=(T* course){
    removeCourse(course);
    return (*this);
}

template <class T>
DList<T>& DList<T>::operator-=(T& course){
    removeCourse(&course);
    return (*this);
}

template <class T>
DList<T>& DList<T>::operator-=(DList<T>* list){
	Node* currNode = list->head;
	while(currNode != 0){
		removeCourse(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
  return (*this);
}

template <class T>
DList<T>& DList<T>::operator-=(DList<T>& list){
	Node* currNode = list.head;
	while(currNode != 0){
		removeCourse(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
	return (*this);
}

template <class T>
T* DList<T>::getCourse(int index)
{
	Node* tempNode = head;
  for(int i = 0; i<index; i++){
		tempNode = tempNode -> next;
	}
	return (tempNode -> data);
}

template <class T>
T* DList<T>::getCourse(string code)
{
	Node* currNode = head;
	Node* prevNode = 0;

	while (currNode != 0) {
		if (currNode->data->getCode() == code)
			return currNode->data;

		prevNode = currNode;
		currNode = currNode->next;
	}
	return 0;
}

template <class T>
void DList<T>::add(T* course)
{
	Node* currNode = head;
	Node* prevNode = 0;
	Node* courseNode = new Node;

	courseNode -> data = course;
	courseNode -> next = 0;
	courseNode -> prev = 0;

	while(currNode != 0){
		//if ((courseNode->data)->isLess(currNode->data))
		//	break;
		prevNode = currNode;
		currNode = currNode -> next;
		}
	//If the list is empty
	if (head == 0){
		head = courseNode;
	//If your adding to the head
	}else if(prevNode == 0){
		currNode->prev = courseNode;
		courseNode->next = currNode;
		head = courseNode;
	//if your adding to the end
	}else if(currNode == 0){
		prevNode -> next = courseNode;
		courseNode -> prev = prevNode;
	//if your adding to the middle
	}else{
		courseNode -> next = currNode;
		courseNode -> prev = currNode->prev;
		currNode -> prev -> next = courseNode;
		currNode -> prev = courseNode;
	}
	//increase numNodes
	numNodes++;
}

template <class T>
void DList<T>::removeCourse(T* course)
{
	  Node* currNode = head;
	  Node* prevNode = 0;

	  while (currNode != 0) {
	    if (currNode->data == course)
	      break;
	    prevNode = currNode;
	    currNode = currNode->next;
	  }

	// we are here

	// we didn't find the student
	  if (currNode == 0) {
	    return;
	  }

	  if (prevNode == 0)
	    head = currNode->next;
	  else
	    prevNode->next = currNode->next;

		delete currNode->data;
	  delete currNode;
		numNodes--;
}

/*
template <class T>
string DList<T>::forward()
{
	stringstream theString;
	Node* currNode = head;
	if (currNode == 0){
		return "No Courses in List.";
	}
  theString << endl;
	theString << "Courses Printed forward:" << endl;
	while (currNode != 0) {
    Course* c = currNode->data;
    theString << c->getInfo();
		theString << endl;
		currNode = currNode -> next;
	}
	return theString.str();
}

template <class T>
string DList<T>::backward()
{
	stringstream theString;
	Node* currNode = head;

	if (currNode == 0){
		return "No Courses in List.";
	}

	for(int j=1; j<numNodes; ++j){
		currNode = currNode->next;
	}

  theString << endl;
	theString << "Courses Printed backward:" << endl;
	while (currNode != 0) {
    T* c = currNode->data;
    theString << c->getInfo();
		theString << endl;
		currNode = currNode -> prev;
	}
	return theString.str();
}
*/

template <class T>
T* DList<T>::find(int num)
{
	int i = 0;
	Node* currNode = head;
	while (i<num){
		currNode = currNode ->next;
		i++;
	}
	return currNode->data;
}

#endif
