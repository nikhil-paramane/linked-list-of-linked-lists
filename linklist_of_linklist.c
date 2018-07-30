//Dynamic Implementation of linklist(Generalised Linked List)

#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (Node*)malloc(sizeof(Node))
#define NEWTERM (Terminal*)malloc(sizeof(Terminal))

typedef struct Node{
	int data;
	struct Node*next;
}Node;
typedef struct Terminal{
	struct Terminal*next;
	struct Node*list;
}Terminal;

Node*startnode=NULL,*lastnode=NULL;
Terminal*start_term=NULL,*last_term=NULL;

//create node of type Node
Node*createnode(int num){
	Node*temp=NULL;
	temp=NEWNODE;
	temp->data=num;
	temp->next=NULL;
	return temp;
}
//Create node of type Terminal
Terminal*createterm(){
	Terminal*temp;
	temp=NEWTERM;
	temp->next=NULL;
	temp->list=NULL;
	return temp;
}

//createlist

void createlist(int n){
	int i,val;
	Node*temp;
	Terminal*temp_term;
	temp_term=createterm();
	if(start_term==NULL){
		start_term=temp_term;
		last_term=temp_term;
	}else{
		last_term->next=temp_term;
		last_term=temp_term;
	}
	for(i=0; i<n; i++){
		printf("Enter data:\n");
		scanf("%d",&val);
		temp=createnode(val);
		if(temp_term->list==NULL){
			temp_term->list=temp;
			lastnode=temp;
		}else{
			lastnode->next=temp;
			lastnode=temp;
		}
	}
}
void display(int num){
	Terminal*temp_term=start_term;
	Node*temp;
	int count=1;
	while(count!=num){
		count++;
		temp_term=temp_term->next;
	}//end of terminal while
	temp=temp_term->list;
	printf("Data:\n\t");
	while(temp!=NULL){
		if(temp->next==NULL){
			printf("%d",temp->data);
		}else{
			printf("%d---->",temp->data);
		}
		temp=temp->next;
	}//end of list while
	printf("\n\n");
}//end of display

int countnode(int num){
	Terminal*temp_term=start_term;
	Node*temp;
	int count=1,count_node=0;
	while(count!=num){
		count++;
		temp_term=temp_term->next;
	}//end of terminal while
	temp=temp_term->list;
	while(temp!=NULL){
		count_node++;
		temp=temp->next;
	}//end of list while
	return count_node;
}
int countlist(){
	Terminal*temp=start_term;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
void addnode(int num,int position){
	Terminal*temp_term=start_term;
	Node*tempnode,*temp=NULL;
	int count=1,val,count1=1;
	while(count!=num){
		count++;
		temp_term=temp_term->next;
	}//end of terminal while
	tempnode=temp_term->list;
		
	if(position>countnode(num)+1){
		printf("Out of range\n");
		return;
	}
	printf("Enter data to add:\n");
	scanf("%d",&val);
	temp=createnode(val);
	//check for starting position
	if(position==1){
		temp->next=temp_term->list;
		temp_term->list=temp;
		return;
	}
	//checking if it is last node
	if(position==countnode(num)){
		while(tempnode->next!=NULL){
			tempnode=tempnode->next;
		}
		tempnode->next=temp;
		return;
	}
	//traversing nodes untill expected position is not found
	while(count1!=position-1){
		count1++;
		tempnode=tempnode->next;
	}
	temp->next=tempnode->next;
	tempnode->next=temp;
}//End of add node

void deletenode(int num,int position){
	Terminal*temp_term=start_term;
	Node*tempnode,*temp=NULL;
	int count=1,val,count1=1;
	
	//traversing through terminal
	while(count!=num){
		count++;
		temp_term=temp_term->next;
	}//end of terminal while
	tempnode=temp_term->list;
		
	if(position>countnode(num)+1){
		printf("Out of range\n");
		return;
	}
	if(position==1){
		temp=temp_term->list;
		temp_term->list=temp_term->list->next;
		free(temp);
		return;
	}
	while(count1!=(position-1)){
		count1++;
		tempnode=tempnode->next;
	}
	temp=tempnode->next;
	tempnode->next=temp->next;
	free(temp);
	return;
}//End of deletenode

void deletelist(int position){
	if(position>countlist()){
		printf("Out of range\n");
		return;
	}
	Terminal*temp_term=start_term,*term_before;
	Node*temp,*t;
	int count=1;
	if(position==1){
		temp=t=start_term->list;
		while(temp!=NULL){
			t=temp;
			temp=temp->next;
			free(t);
		}
		term_before=start_term;
		start_term=start_term->next;
		free(term_before);
		return;
	}
	//deleting last list
	if(position==countlist()){
		Terminal*temp1;
		while(count!=position){// traversing through terminal;
		count++;
		term_before=temp_term;
		temp_term=temp_term->next;
	}//end of if
		temp=t=temp_term->list;
	while(temp!=NULL){//deleting list
		t=temp;
		temp=temp->next;
		free(t);
		}//end of while
		temp1=temp_term;
		free(temp1);
		term_before->next=NULL;
		return;
	}//end of if
	//deleting any but first and last list
	while(count!=position){
		count++;
		term_before=temp_term;
		temp_term=temp_term->next;
	}
	temp=t=temp_term->list;
	while(temp!=NULL){
		t=temp;
		temp=temp->next;
		free(t);
	}
	term_before->next=temp_term->next;
	free(temp_term);
}
void searchdata(int data,int position){
	if(position>countlist()){
		printf("Out of range\n");
		return;
	}
	Terminal*temp_term=start_term;
	Node*temp,*tempnode;
	int count=1;
	while(count!=position){
		count++;
		temp_term=temp_term->next;
	}
	count=1;
	int record=0;
	tempnode=temp_term->list;
	while(tempnode!=NULL){
		if(tempnode->data==data){
			printf("Data found in Node %d of list %d\n",count,position);
			record++;
		}
			tempnode=tempnode->next;
			count++;
	}
	if(record==0){
		printf("Data not found\n");
		return;
	}
}//End of Search Data

void maxelement(int position){
	if(position>countlist()){
		printf("Out of range\n");
		return;
	}
	Terminal*temp_term=start_term;
	Node*temp,*tempnode;
	int count=1,elem,i;
	while(count!=position){
		count++;
		temp_term=temp_term->next;
	}
	tempnode=temp_term->list;
	if(tempnode->data<=tempnode->next->data){
		elem=tempnode->next->data;
	}else{
			elem=tempnode->data;
		}
		count=countnode(position);
		tempnode=tempnode->next;
	for(i=2; i<=count; i++){
				if(elem<=tempnode->data){
					elem=tempnode->data;
				}else{
					elem=elem;		
				}
				tempnode=tempnode->next;
			}
	printf("max element: %d\n",elem);
}//End of maxelement


void minelement(int position){
	if(position>countlist()){
		printf("Out of range\n");
		return;
	}
	Terminal*temp_term=start_term;
	Node*temp,*tempnode;
	int count=1,elem,i;
	while(count!=position){
		count++;
		temp_term=temp_term->next;
	}
	tempnode=temp_term->list;
	if(tempnode->data>=tempnode->next->data){
		elem=tempnode->next->data;
	}else{
			elem=tempnode->data;
		}
		count=countnode(position);
		tempnode=tempnode->next;
	for(i=2; i<=count; i++){
				if(elem>=tempnode->data){
					elem=tempnode->data;
				}else{
					elem=elem;		
				}
				tempnode=tempnode->next;
			}
	printf("minimum element: %d\n",elem);
}//End of minimum element

void sort(int position){
	if(position>countlist()){
		printf("Out of range\n");
		return;
	}
	Terminal*temp_term=start_term;
	Node*temp,*tempnode;
	int count=1,ch,p;
	while(count!=position){
		count++;
		temp_term=temp_term->next;
	}
	tempnode=temp_term->list;
	printf("\t1:Ascending\n\t2:Descending\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
				while(tempnode!=NULL){
					temp=tempnode->next;
					while(temp!=NULL){
						if(tempnode->data>=temp->data){
							p=tempnode->data;
							tempnode->data=temp->data;
							temp->data=p;
						}
						temp=temp->next;
					}
					tempnode=tempnode->next;
				}
				printf("List Sorted in ascending order\n");
				break;
		case 2:
				while(tempnode!=NULL){
					temp=tempnode->next;
					while(temp!=NULL){
						if(tempnode->data<=temp->data){
							p=tempnode->data;
							tempnode->data=temp->data;
							temp->data=p;
						}
						temp=temp->next;
					}
					tempnode=tempnode->next;
				}
				printf("List Sorted in descending order\n");
				break;
		default: printf("Invalid choice\n");
	}//End of switch
}//End of sort

int main(){
	int choice, ans,n,num,list,node;
	do{
		printf("Enter:\n\t1:Create Linked List\n\t2:Display\n\t3:Count Nodes in List\n\t4:Count Linked Lists\n\t5:Add Node\n\t6:delete\n\t7:delete list\n\t8:Search data\n\t9:Maximum element\n\t10:Minimum element\n\t11:Sort\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf("How many nodes:\n");
					scanf("%d",&num);
					createlist(num);
					break;
			case 2:
					printf("Enter List Index:\n");
					scanf("%d",&n);
					if(n>countlist()){
						printf("Out of range\n");
						break;
					}
					display(n);
					break;
			case 3:
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					printf("Enter List Index:\n");
					scanf("%d",&n);
					if(n>countlist()){
						printf("Out of range\n");
						break;
					}
					printf("Number of Nodes:%d\n",countnode(n));
					break;
			case 4: 
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}		
					 printf("Number of Lists:%d\n",countlist());
					break;
			case 5: if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					printf("Enter List Index:\n");
					scanf("%d",&list);
					if(list>countlist()){
						printf("Out of range\n");
						break;
					}
					printf("Enter Node Index:\n");
					scanf("%d",&node);
					addnode(list,node);			
					break;		
			case 6:
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					int list,node;
					printf("Enter List Index:\n");
					scanf("%d",&list);
					if(list>countlist()){
						printf("Out of range\n");
						break;
					}
					printf("Enter Node Index:\n");
					scanf("%d",&node);
					deletenode(list,node);
					break;
			case 7:
			 		if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					printf("Enter List Index:\n");
					scanf("%d",&list);
					deletelist(list);
					break;
			case 8:
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					int val;
					printf("Enter data to search:\n");
					scanf("%d",&val);
					printf("Enter List Index:\n");
					scanf("%d",&list);
					searchdata(val,list);
					break;
			case 9: 
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					printf("Enter List Index:\n");
					scanf("%d",&list);
					maxelement(list);
					break;
			case 10:
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}
					printf("Enter List Index:\n");
					scanf("%d",&list);
					minelement(list);
					break;
			case 11:
					if(start_term==NULL){
						printf("No list is present\n");	
						break;
					}printf("Enter List Index:\n");
					scanf("%d",&list);
					sort(list);
					break;		
			default:printf("Invalid choice\n");
		}
			printf("Continue:\n\t1:Yes\n\t0:No\n");
			scanf("%d",&ans);
	}while(ans);
	return 0;
}
