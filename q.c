#include <stdio.h>
#include <stdlib.h>

struct QNode {
	int key;
	struct QNode* next;
};

struct Queue {
	struct QNode *front, *rear;
};

struct QNode* newNode(int k) {
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue* createQueue() {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void enQueue(struct Queue* q, int k) {
	struct QNode* temp = newNode(k);
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

int deQueue(struct Queue* q) {
	if (q->front == NULL)
		return -1; // Return a special value to indicate an empty queue
	struct QNode* temp = q->front;
	int value = temp->key;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
	return value;
}

int main() {
	struct Queue* q = createQueue();
	int choice, value;

	do {
		printf("Queue Operations:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter a value to enqueue: ");
				scanf("%d", &value);
				enQueue(q, value);
				break;
			case 2: {
				int dequeuedValue = deQueue(q);
				if (dequeuedValue != -1) {
					printf("Dequeued value: %d\n", dequeuedValue);
				} else {
					printf("Queue is empty. Cannot dequeue.\n");
				}
				break;
			}
			case 3:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 3);

	return 0;
}
