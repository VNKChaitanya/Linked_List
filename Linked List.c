#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int data;
	node *next;
};

// declaring Head, tail globally.
node *head= NULL;
node *tail= NULL;

node* create(int val){
	//creating a newnode.
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data= val;
	newnode->next= NULL;
	return newnode;
}

void insertat_head(int val){
	node *newnode = create(val);
	if(head==NULL){
		head= newnode;
		tail= newnode;
		return;
	}
	// current node is head here, as we want to access the address of head.
	node *current_node = head;
	newnode->next = current_node;
	head = newnode;
	// now our newnode is our new head.
}

void insertat_tail(int val){
	node *newnode = create(val);
	if(head==NULL){
		head= newnode;
		tail= newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
}

void insertat_mid(int val, int pos){
	node *current_node = head;
	if(pos==1) {
		insertat_head(val);
		return;
	}
	node *newnode = create(val);
	int i=1;
	while(i<pos){
		if(current_node->next==tail) {
			insertat_tail(val);
			return;
		}
		current_node=current_node->next;
		i++;
	}
	// temp stores the address of the node present after the current.
	node *temp = current_node->next;
	// the address of the newnode is stored in the current node.
	current_node->next= newnode;
	// the address of the node present after the current(temp) is stored in the newnode
	newnode->next= temp;
}

void delat_head(){
	if(head==NULL){
		printf("Please create a Linked List First");
		return;
	}
	if(head->next==NULL){
		free(head);
		head=NULL;
		tail= NULL;
		return;
	}
	node *temp = head;
	head = head->next;
	free(temp);
}

void delat_tail(){
	if(head==NULL){
		printf("Please create a Linked List First");
		return;
	}
	if(head->next==NULL){
		free(head);
		head=NULL;
		tail= NULL;
		return;
	}
	node *current_node = head;
	while(current_node->next!=tail){
		current_node= current_node->next;
	}
	node *temp= tail;
	current_node->next= NULL;
	tail = current_node;
	free(temp);
}

void delat_mid(int pos){
	if(pos==1) {
		delat_head();
		return;
	}
	int i=1;
	node *current_node= head;
	while(i<pos){
		if(current_node->next==tail) {
			delat_tail();
			return;
		}
		current_node=current_node->next;
		i++;
	}
	node *temp= current_node->next;
	current_node->next = temp->next; 
	free(temp);
}

void display(){
	node *temp= head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
int printandscan(){
	int uc;
		printf("\nTo Insert at Head enter 1\nTo insert at tail enter 2\nTo insert in middle enter 3\n");
		printf("To Delete at Head enter 4\nTo Delete at tail enter 5\nTo Delete in middle enter 6\n");
		printf("To display the data enter 7\nTo end entering data enter 8\n");
		scanf("%d", &uc);
		return uc;
}
int main(){
	int cnt=0;
	int val,pos,uc;
		while(1){
		uc=printandscan();
		//1
		if(uc==1) {
				printf("\nEnter the value to be entered\n");
				scanf("%d", &val);
				insertat_head(val);
				//printf("%d", head->data);	
		}
		//2
		else if(uc==2) {
				printf("\nEnter the value to be entered\n");
					scanf("%d", &val);
					insertat_tail(val);
		}
		//3
		else if(uc==3){
				printf("\nEnter the value and position\n");
				scanf("%d %d", &val,&pos);
				insertat_mid(val,pos-1);
		} 
		//4
		else if(uc==4){
			if(cnt==0) printf("\nYou haven't created a Linked List Yet\n");
			else delat_head();
		} 
		//5
		else if(uc==5){
			if(cnt==0)printf("\nYou haven't created a Linked List Yet\n");
			else delat_tail(cnt+1);
		} 
		//6
		else if(uc==6){
			if(cnt==0) printf("\nYou haven't created a Linked List Yet\n");
				else {
						printf("\nEnter the position\n");
						scanf("%d", &pos);
						delat_mid(pos-1);
				}
		}
		//7
		else if(uc==7){
				display();	
		} 
		// default
		else printf("\nYou can only enter 1-8\n");
		cnt++;
	}
}
