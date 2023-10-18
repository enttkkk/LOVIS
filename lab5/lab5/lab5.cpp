#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

#define MAX_VERTICES 10

int main() {
setlocale(LC_ALL, "RUS");
srand(time(NULL));

int num_vertices;
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

printf("������� ���������� ������ (�� ����� %d): ",MAX_VERTICES);
scanf("%d", &num_vertices);

if (num_vertices <= 0 || num_vertices >MAX_VERTICES) {
printf("�������� ���������� ������.���������� ���������.\n");
return 1;
    }

for (int i = 0; i < num_vertices; i++) {
for (int j = 0; j < num_vertices; j++) {
if (i == j) {
                adjacency_matrix[i][j] = 0;
            }
else {
                adjacency_matrix[i][j] = rand() % 2 - 0;
                adjacency_matrix[j][i] = adjacency_matrix[i][j];
}
        }
    }

printf("������� ��������� ����� G:\n");
for (int i = 0; i < num_vertices; i++) {
for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

int num_edges = 0;

for (int i = 0; i < num_vertices; i++) {
for (int j = i + 1; j < num_vertices; j++) {
if (adjacency_matrix[i][j] == 1) {
                num_edges++;
            }
        }
    }

printf("����������� G:\n");
printf("���������� ������: %d\n", num_vertices);
printf("���������� ����: %d\n", num_edges);

printf("\n");

// ����������� �������������, �������� � ������������ �����
int isolated_rows = 0;
int leaf_rows = 0;
int dominating_rows = 0;

for (int i = 0; i < num_vertices; i++) {
int degree = 0;
for (int j = 0; j < num_vertices; j++) {
            degree += adjacency_matrix[i][j];
        }

if (degree == 0) {
printf("�������������������: %d\n", i + 1);
            isolated_rows++;
        }
if (degree == 1) {
printf("��������������: %d\n", i + 1);
            leaf_rows++;
        }
if (degree >= num_vertices - 1) {
printf("������������ ������: %d\n", i + 1);
dominating_rows++;
        }
    }

printf("���������� ������������� �����: %d\n", isolated_rows);
printf("\n");
printf("���������� �������� �����: %d\n", leaf_rows);
printf("\n");
printf("���������� ������������ �����: %d\n", dominating_rows);

int incidence_matrix[MAX_VERTICES][MAX_VERTICES];
for (int i = 0; i < num_vertices; i++) {
for (int j = 0; j < num_edges; j++) {
            incidence_matrix[i][j] = 0;
        }
    }

int edge_count = 0;
for (int i = 0; i < num_vertices; i++) {
for (int j = i + 1; j < num_vertices; j++) {
if (adjacency_matrix[i][j] == 1) {
                incidence_matrix[i][edge_count] = 1;
                incidence_matrix[j][edge_count] = 1;
                edge_count++;
            }
        }
    }

printf("������������������������� G:\n");
for (int i = 0; i < num_vertices; i++) {
for (int j = 0; j < num_edges; j++) {
            printf("%d ", incidence_matrix[i][j]);
}
printf("\n");
    }


// ����������� �������������, �������� � ������������ �����
int isolated_rows2 = 0;
int leaf_rows2 = 0;
int dominating_rows2 = 0;

for (int i = 0; i < num_vertices; i++) {
int degree = 0;
for (int j = 0; j < num_vertices; j++) {
            degree += adjacency_matrix[i][j];
        }

if (degree == 0) {
printf("�������������������: %d\n", i + 1);
            isolated_rows2++;
        }
else if (degree == 1) {
printf("��������������: %d\n", i + 1);
            leaf_rows2++;
        }
else if (degree >= num_vertices - 1) {
printf("������������ ������: %d\n", i + 1);
            dominating_rows2++;
        }
    }

printf("���������� ������������� �����: %d\n", isolated_rows2);
printf("\n");
printf("���������� �������� �����: %d\n", leaf_rows2);
printf("\n");
printf("���������� ������������ �����: %d\n", dominating_rows2);

system( "pause");
}
