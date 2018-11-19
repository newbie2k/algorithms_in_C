#include<stdio.h>
#include<stdlib.h>

/* Globle Variables */

struct node {
                int data;
                struct node *next;
        };
struct node *start = NULL, *current = NULL;

/* Main */

int main() {
	int val,pos, inp;
	void add_node(int, int);
        void delete_node(int);
	void print_node(void);

	while(1) {
		printf("Enter Choice[1-(Add) 2-(Del) 3-(Print) 4-(Quit)] : ");
		scanf("%d",&inp);

		switch(inp) {
			case 1: printf("Enter Data : ");
				  scanf("%d",&val);
				  printf("Enter Position : ");
				  scanf("%d",&pos);
				  add_node(val,pos);
				  break;
			
			case 2: printf("Enter Position : ");
                                  scanf("%d",&pos);
                                  delete_node(pos);
				  break;

			case 3: print_node();
				  break;

			case 4: printf("Exiting Program ...\n");
					    return 0;

			default : printf("Please Enter Valid Option.\n");
				  break;
		}
	}
}

/* Add node to Linked List */

void add_node(int val, int pos) {
	int flag=0,i;
	struct node *new;
	current = start;					//One every call setting current to start

	new = malloc(sizeof(struct node));

	if((start == NULL) && (pos > 1)) {			//Checking if provide first input is Out of bound
		printf("Error: Position is out of bound\n");
		free(new);
		return;
	}
	
	if(pos == 1) {						//This might look different because here our current is after new
		start = new;
		new->next = current;
		new->data = val;
	}
	else {							//Here we will assume current is just before new
		for(i=2;i<pos;i++) {
			current = current->next;
			if(current == NULL) {			//if previous node(just) is null then how we can put element after that
				printf("Error: Position is out of bound\n");
				free(new);
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			new->next = current->next;
			current->next = new;
			new->data = val;
		}
	}
}



/* Delete node from Linked List */
void delete_node(int pos) {
	int flag = 0,i;
	struct node *del;
	current = start;

	for(i=1;i<=pos-1;i++) {
		/* Checking if reached Last Element */
			if((current->next == NULL) && (i != pos - 1)) {		//Need to Check Logic
				printf("Error: Given Position out of last element");
				flag = 1;
				break;
			}
			current = current->next;
	}
	
	if(flag != 1) {
		if(pos == 1) {
			start = current->next;
			free(current);
		}
		else {
			del = current->next;
			current->next = del->next;
			free(del);
		}
	}
}
/* Linked List Print Nodes */
void print_node() {
	int i=1;
	current = start;

	while(current != NULL) {
		printf("Data : %d   ",current->data);
		printf("Node : %d\n",i);
		current=current->next;
		i++;
	}
}
