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

int DList::getNumNodes()   { return numNodes;   } //temp

ostream& operator<<(ostream& theString, DList& arr){
	theString << "Printed using the '<<' operator: " << endl;
	if (arr.getNumNodes() == 0){
		theString << "No Courses in List.";
	}
	theString << endl;
	for (int i=1; i<=arr.getNumNodes(); ++i) {
		Course* c = arr.find(i);
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
	}
	return theString;
}

DList& DList::operator+=(Course* course){
    add(course);
    return (*this);
}

DList& DList::operator+=(Course& course){
    add(&course);
    return (*this);
}

DList& DList::operator+=(DList* list){
	Node* currNode = list->head;
	while(currNode != 0){
		add(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
  return (*this);
}

DList& DList::operator+=(DList& list){
	Node* currNode = list.head;
	while(currNode != 0){
		add(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
	return (*this);
}

DList& DList::operator-=(Course* course){
    removeCourse(course);
    return (*this);
}

DList& DList::operator-=(Course& course){
    removeCourse(&course);
    return (*this);
}

DList& DList::operator-=(DList* list){
	Node* currNode = list->head;
	while(currNode != 0){
		removeCourse(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
  return (*this);
}

DList& DList::operator-=(DList& list){
	Node* currNode = list.head;
	while(currNode != 0){
		removeCourse(currNode-> data);
		currNode->data = 0;
		currNode = currNode -> next;
	}
	return (*this);
}

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
			return currNode->data;

		prevNode = currNode;
		currNode = currNode->next;
	}
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

		delete currNode->data;
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

Course* DList::find(int num)
{
	int i = 1;
	Node* currNode = head;
	while (i<num){
		currNode = currNode ->next;
		i++;
	}
	return currNode->data;
}
