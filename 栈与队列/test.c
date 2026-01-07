#include"Stack.h"
#include"Queue.h"

int main() {

	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q)) {
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	return 0;
}