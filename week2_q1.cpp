/************************************************************************************************
LINKED LIST


#CommentsMatter : Commenting should be used for every executable statement that does not perform trivial functions to non-CS person. 

Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
	Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.
   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. 
	Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 

****************************************************************************************************************/




#include<iostream>
using namespace std;

//create the members of the list
class node{
	public:
		//data place
		int data;
		//pointer part
		node *next;
		//default constructor
		node(){
			next=NULL;//this makes the pointer to point to null as a default
		}
};
//create the list
class list{
	public:
		//node will be here
		// and the head to point to the nodes must also belong to here.
		//and the head must be a pointer pointing to the next node
		node* head;
		node* tail;
		//default constructor
		list(){
			head=NULL;
			tail=NULL;
		}
		//insert function
		void insert(int i_data){
			node* temp= new node;//creates a temp node with default value
			temp->data=i_data;//inserts the value from i_data inside the data variable of the temp node
			
			//now for input of the value from temp node to list can occur in two ways,
			//when there is only one node, i.e, the head will point to the node containing that value
			if (head==NULL){
				head=temp;
			}
			else
			{
				tail->next=temp;
			}
			tail=temp;
		}
		//insertAt function
		void insertAt(int pos, int i_data){
			node *current=head;
			int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			node* temp=new node;
			temp->data=i_data;
			temp->next=current->next;//this one swaps the values
			current->next=temp;
			
		}
		//Delete function
		void delet(){
			node *current=head;
			int i=1;
			while(current->next!=tail){
				i++;
				current=current->next;
			}
			node *temp=tail;
			current->next=NULL;
			
			
		}
		//deleteAt function
		void deleteAt(int pos){
			node*current=head;
			int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			node* temp=current->next;
			current->next=temp->next;
			temp=NULL;
		}
		//count function
		void count(){
			node*current=head;
			int i=1;
			while(current!=tail){
				i++;
				current=current->next;
			}
			cout<<"the number of node in the list is "<<i<<".\n";
		}
		void display()
		{
			node *current=head;
			while(current != NULL)
			{
			
				cout<<current->data<<"->";
				current=current->next;
			}
			cout<<"NULL"<<endl;
			
		}


};

int main()
{
	list l1;
	l1.display();
	l1.insert(1);
	l1.count();
	l1.display();
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.count();
	l1.display();
	l1.delet();
	l1.count();
	l1.display();
	l1.insertAt(3,51);
	l1.count();
	l1.display();
	l1.deleteAt(3);
	l1.count();
	l1.display();
	
	/*l1.count();
	l1.display();
	*/
	return 0;
}
