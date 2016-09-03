#include "DList.h"

#include <sstream>

DList::DList()
	: head(0)
{
	numNodes = 0;
};

DList::~DList()
{
	Node* currNode = head;
	Node* prevNode = currNode;
	while(currNode != 0)
	{
  	currNode = currNode->next;
		delete prevNode -> data;
		delete prevNode;
		prevNode = currNode;
	}
};

int DList::getNumNodes()   { return numNodes;   } //temp

Course* DList::getCourse(int index)
{
	Node* tempNode = head;
  for(int i = 0; i<index; i++){
		tempNode = tempNode -> next;
	}
	return (tempNode -> data);
}

Course* DList::getCourse(string code)
{
	Node* currNode = head;
	Node* prevNode = 0;

	while (currNode != 0) {
		if (currNode->data->getCode() == code)
			break;
		prevNode = currNode;
		currNode = currNode->next;
	}

	if (currNode != 0){
		return currNode->data;
	}
	cout << "No course was found with code " + code + " please try again" << endl;
	return 0;

}

void DList::add(Course* course)
{
	Node* currNode = head;
	Node* prevNode = 0;
	Node* courseNode = new Node;

	courseNode -> data = course;
	courseNode -> next = 0;
	courseNode -> prev = 0;

	while(currNode != 0){
		if (currNode->data->getCode() > courseNode->data->getCode())
			break;
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

void DList::removeCourse(Course* course)
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

	  delete currNode;
		numNodes--;
}

string DList::forward()
{
	stringstream theString;
	Node* currNode = head;
	if (currNode == 0){
		return "No Courses in List.";
	}
  theString << endl;
	theString << "Courses Printed forward:" << endl;
	for (int i=0; i<numNodes; ++i) {
    Course* c = currNode->data;
    theString << "Course:     " << c->getCode()  << "  " << c->getName() << endl;
    theString << "Instructor: " << c->getInstr()  << endl;
    theString << "Enrolment:  " << c->getEnrol() << endl;
    theString << "Textbooks:  ";
    if (c->getNumBooks() == 0) {
      theString << "None" << endl;
    }
    else {
			theString << c->printBooks();
    }
		theString << endl;
		currNode = currNode -> next;
	}
	return theString.str();
}

string DList::backward()
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
	for (int i=0; i<numNodes; ++i) {
    Course* c = currNode->data;
    theString << "Course:     " << c->getCode()  << "  " << c->getName() << endl;
    theString << "Instructor: " << c->getInstr()  << endl;
    theString << "Enrolment:  " << c->getEnrol() << endl;
    theString << "Textbooks:  " << endl;
    if (c->getNumBooks() == 0) {
      theString << "None";
    }
    else {
			theString << c->printBooks();
    }
		theString << endl;
		currNode = currNode -> prev;
	}
	return theString.str();
}

Course* DList::find(string code)
{
	cout<<"ttTest";
	Node* currNode = head;
	while (currNode != 0){
		if(currNode->data->getCode() == code)
			return currNode->data;
		currNode = currNode ->next;
	}
	cout << "TEST";
	return 0;
}
