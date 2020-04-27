#include <iostream>
#include <cstdlib> // srand, rand 
#include <ctime> // time 
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *next;
};
	
class IntList { // a singly int list
	Node *head, *p;
	int size;
public:
    
	IntList(int n) { // Fill Constructor
		srand (time(NULL));
		if(n<=0) return;
		p = new Node; 
		bool first = true;
		while(n--) {
			p->data = rand() % 10003; // 10X next prime
			if(first) { // first item, set up head
			    first = false; 
			    head = p; 
			}

			if(n<1) break;
		    p->next = new Node;
		    p = p->next;
		}
	}
	
	// Iterative Traversal Reader
	Node *getHead() {return head;}
	bool travIter(vector<int> &inOrder) { // To move through the list
		if (!head) return true;
		else {
			Node *p = head;
			while (p) {
			    inOrder.push_back(p->data);
				p = p->next;
			}
		}
		return true;
	}
	
	// Public Recursive Traversal Reader
	bool travRecr(vector<int> &inOrder){ 
		travRecr(head, inOrder);
		return true;
	}
private:
    // Internal Recursive Traversal Reader
	bool travRecr(Node *p, vector<int> &inOrder){
		if (p){
		    p->data;
			inOrder.push_back(p->data);
			travRecr(p->next, inOrder);
		}
		return true;
	}
};
 
int main() {
	IntList alist(10);
	// the original traversal iteration
	Node *p = alist.getHead();
	while(p) {
	    cout << p->data<< ' ';
	    p = p->next;
	}
	
	vector<int> record;
	
	cout << "\nIterative traversal\n";
    alist.travIter(record);
	for(auto x:record) cout << x << ' ';
	
	cout << "\nRecursive traversal\n";
	record.clear();
	alist.travRecr(record);
	for(auto x:record) cout << x << ' ';
}
	