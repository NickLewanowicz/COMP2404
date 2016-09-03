#ifndef DLIST_H
#define DLIST_H

#include <string>
#include "Course.h"

class DList
{
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
		Course* find(string);
		int		getNumNodes();
		Course*	getCourse(int);
		Course* getCourse(string);


	private:
		int		numNodes;
		Node* head;
};

#endif
