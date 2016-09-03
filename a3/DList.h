#ifndef DLIST_H
#define DLIST_H

#include <string>
#include "Course.h"

class DList
{
	friend ostream& operator<<(ostream&, DList&);
	class Node
  {
    friend class DList;
    private:
      Course* data;
      Node* next;
			Node* prev;
  };
	public:
		DList();
		~DList();
		void	add(Course*);
		void  removeCourse(Course*);
		string forward();
		string backward();
		Course* find(int);
		int		getNumNodes();
		Course*	getCourse(int);
		Course* getCourse(string);
    //stringstream operator<<(DList*);
    DList& operator+=(Course*);
    DList& operator+=(Course&);
		DList& operator+=(DList*);
    DList& operator+=(DList&);
    DList& operator-=(Course*);
    DList& operator-=(Course&);
    DList& operator-=(DList*);
    DList& operator-=(DList&);
	private:
		int		numNodes;
		Node* head;
};

#endif
