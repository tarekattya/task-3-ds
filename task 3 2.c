
#include <stdio.h>
#include <stdlib.h>


struct sNode {
	int data;
	struct sNode* next;
};


struct queue {
	struct sNode* stack1;
};


void push(struct sNode** top_ref, int new_data);


int pop(struct sNode** top_ref);

void enQueue(struct queue* q, int x)
{
	push(&q->stack1, x);
}

int deQueue(struct queue* q)
{
	int x, res;


	if (q->stack1 == NULL) {
		printf("Q is empty");
		getchar();
		exit(0);
	}
	else if (q->stack1->next == NULL) {
		return pop(&q->stack1);
	}
	else {
		
		x = pop(&q->stack1);

	
		res = deQueue(q);

	
		push(&q->stack1, x);
		return res;
	}
}


void push(struct sNode** top_ref, int new_data)
{
	/* allocate node */
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

	if (new_node == NULL) {
		printf("Stack overflow \n");
		getchar();
		exit(0);
	}

	
	new_node->data = new_data;


	new_node->next = (*top_ref);


	(*top_ref) = new_node;
}


int pop(struct sNode** top_ref)
{
	int res;
	struct sNode* top;


	if (*top_ref == NULL) {
		printf("Stack underflow \n");
		getchar();
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}


int main()
{
	
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;

	enQueue(q,11);
	enQueue(q, 12);
	enQueue(q, 13);

	
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));

	return 0;
}


