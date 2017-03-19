#include "list.h"

//put the implementation of your assigned functions here
int countEven(node * head)
{
  node * curr;
  int numEven = 0;
  curr = head;
  while(curr)
	{
	  if(curr->data%2 == 0)
		{
		  numEven++;
		}
	  curr = curr->next;
	}

  return numEven;
}
int removeEven(node *& head)
{
  bool firstOdd = true;
  int numRemoved = 0;
  node * curr, * lastOddNode, * temp;
  curr = head;
  while(curr)
	{
	  if(curr->data%2 != 0)        // current node has odd number
		{
		  if(firstOdd)
			{
			  firstOdd = false;
			  head = curr;         // head points to first odd number
			  lastOddNode = curr;  // save address of last odd node...
			}
		  else
			{
			  lastOddNode->next = curr;
			  lastOddNode = curr;  // update address of last odd node...
			}
		  curr = curr->next;       // traverse the list
		}
	  else
		{
		  numRemoved++;
		  temp = curr;             // save pointer to node to be removed
		  curr = curr->next;       // traverse the list
		  delete temp;          // release memory for removed node
		}
	}
  lastOddNode->next = NULL;        // close out the list
  return numRemoved;
}
