
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
	char lastName[100];
} Student;

typedef struct {
	Student* data;
	int front, rear, size, capacity;
} Queue;

typedef struct {
	Student* data;
	int top, capacity;
} Stack;

Queue* createQueue(int capacity) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (Student*)malloc(capacity * sizeof(Student));
	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = capacity;
	return q;
}

void enqueue(Queue* q, Student s) {
	if (q->size == q->capacity) {
		printf("Очередь заполнена!");
		return;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->data[q->rear] = s;
	q->size++;
}

Student dequeue(Queue* q) {
	Student s;
	if (q->size == 0) {
		printf("Очередь пуста!");
	}
	else {
		s = q->data[q->front];
		q->front = (q->front + 1) % q->capacity;
		q->size--;
	}
	return s;
}

Stack* createStack(int capacity) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (Student*)malloc(capacity * sizeof(Student));
	s->top = -1;
	s->capacity = capacity;
	return s;
}

void push(Stack* s, Student student) {
	if (s->top == s->capacity - 1) {
		printf("Стек переполнен!\n");
		return;
	}
	s->top++;
	s->data[s->top] = student;
}

Student pop(Stack* s) {
	if (s->top == -1) {
		printf("Стек пуст!\n");
		Student temp = { "" };
		return temp;
	}
	Student temp = s->data[s->top];
	s->top--;
	return temp;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;

	printf("Выберите структуру данных:\n");
	printf("1 - Приоритетная очередь\n");
	printf("2 - Обычная очередь\n");
	printf("3 - Стек\n");

	scanf("%d", &choice);

	if (choice < 1 || choice > 3) {
		printf("Неверный выбор!\n");
		return 1;
	}

	int numStudents;
	printf("Введите количество студентов: ");
	scanf("%d", &numStudents);

	if (numStudents <= 0) {
		printf("Количество студентов должно быть положительным числом!\n");
		return 1;
	}

	Queue* q = NULL;
	Stack* s = NULL;

	if (choice == 1) {
		// The priority queue remains the same as in the original code.
		// You can add priority if needed.
	}
	else if (choice == 2) {
		q = createQueue(100);

		for (int i = 0; i < numStudents; i++) {
			Student student;
			printf("Введите фамилию для студента %d: ", i + 1);
			scanf("%s", student.lastName);
			enqueue(q, student);
		}

		while (1) {
			printf("Выберите действие:\n");
			printf("1 - Добавить студента\n");
			printf("2 - Удалить студента\n");
			printf("3 - Вывести студентов\n");
			printf("4 - Выход\n");

			scanf("%d", &choice);

			if (choice == 1) {
				Student student;
				printf("Введите фамилию для нового студента: ");
				scanf("%s", student.lastName);
				enqueue(q, student);
			}
			else if (choice == 2) {
				if (q->size > 0) {
					Student removedStudent = dequeue(q);
					printf("Удален студент: %s\n", removedStudent.lastName);
				}
				else {
					printf("Очередь пуста!\n");
				}
			}
			else if (choice == 3) {
				printf("Список студентов в обычной очереди:\n");
				for (int i = q->front, count = 0; count < q->size; i = (i + 1) % q->capacity, count++) {
					printf("%s\n", q->data[i].lastName);
				}
			}
			else if (choice == 4) {
				break;
			}
			else {
				printf("Неверный выбор!\n");
			}
		}

		free(q->data);
		free(q);
	}
	else if (choice == 3) {
		s = createStack(100);

		for (int i = 0; i < numStudents; i++) {
			Student student;
			printf("Введите фамилию для студента %d: ", i + 1);
			scanf("%s", student.lastName);
			push(s, student);
		}

		while (1) {
			printf("Выберите действие:\n");
			printf("1 - Добавить студента\n");
			printf("2 - Удалить студента\n");
			printf("3 - Вывести студентов\n");
			printf("4 - Выход\n");

			scanf("%d", &choice);

			if (choice == 1) {
				Student student;
				printf("Введите фамилию для нового студента: ");
				scanf("%s", student.lastName);
				push(s, student);
			}
			else if (choice == 2) {
				if (s->top != -1) {
					Student removedStudent = pop(s);
					printf("Удален студент: %s\n", removedStudent.lastName);
				}
				else {
					printf("Стек пуст!\n");
				}
			}
			else if (choice == 3) {
				printf("Список студентов в стеке:\n");
				for (int i = 0; i <= s->top; i++) {
					printf("%s\n", s->data[i].lastName);
				}
			}
			else if (choice == 4) {
				break;
			}
			else {
				printf("Неверный выбор!\n");
			}
		}

		free(s->data);
		free(s);
	}

	return 0;
}

