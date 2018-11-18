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
	int add_node(int, int);
        int delete_node(int);
	void print_node(void);

	while(1) {
		printf("Enter Choice[1-(Add) 2-(Del) 3-(Pnt) 4-(Quit)] : ");
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

int add_node(int val, int pos) {
	int flag=0,i;
	struct node *new;
	current = start;

	new = malloc(sizeof(struct node));

	if(pos == 1) {
		current = start = new;
		current->data = val;
		current->next = NULL;
	}
	else {	
		for(i=1;i<pos;i++) {
			/* Checking if reached Last Element */
			if((current->next == NULL) && (i != pos - 1)) {		//Need to Check Logic
				printf("Error: Given Position out of last element");
				flag = 1;
				break;
			}
			current = current->next;
		}
		if(flag != 1) {
			current->next = new;
			new->data = val;
		}
	}
	
return 0;
}

/* Delete node from Linked List */
int delete_node(int pos) {
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
	return 0;
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
	return;
}
						












