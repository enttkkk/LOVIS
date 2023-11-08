#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<vector>

using namespace std;

// ��������� ��� ������������� ���� �������� ������
struct Node {
int value;
Node* next;
};

// ����� ��� ���������� ������� �� ������� ������
class LinkedQueue {
private:
Node* head;
Node* tip;

public:
LinkedQueue() {
        head = nullptr;
tip = nullptr;
    }
// ���������� �������� � ����� �������
void insert(int x) {
Node* newNode = new Node({ x, nullptr });
// ���� ������� �� �����, ��������� � ��������� ���������
if (tip != nullptr) {
            tip->next = newNode;
}
// ��������� ��������� �� ����� �������
tip = newNode;
// ���� ������� ���� �����, head ���� ��������� �� ����������� �������
if (head == nullptr) {
            head = newNode;
}
    }

// �������� �������� �� ������ �������
int del() {
if (head == nullptr) {
return -1;
        }
Node* temp = head;
int result = temp->value;
        head = head->next;
if (head == nullptr) {
            tip = nullptr;
        }
delete temp;
return result;
    }
bool isEmpty() {
return head == nullptr;
    }
};

void breadthFirstTraversal(vector<vector<int>>&Matr, int n) {
vector<bool>entered(n, false);
vector<int> result;

LinkedQueue q;

for (int i = 0; i<n; i++) {
if(!entered[i]) {

bool isolated = true;
for (int j = 0; j <n; j++) {
if (Matr[i][j] == 1) {
                    isolated = false;
break;
                }
            }
if(!isolated) {
q.insert(i);
                entered[i]=true;
while(!q.isEmpty()) {
int v = q.del();
result.push_back(v);
for (int j = 0; j <n; j++) {
if (Matr[v][j] == 1 && !entered[j]) {
q.insert(j);
                            entered[j]=true;
}
                    }
                }
            }
        }
    }

// �����
cout<<"\n����� ������� � ������\n";
for (int v : result) {
cout<< v + 1 <<" ";
    }
cout<<endl;
}

int main() {
setlocale(LC_ALL, "Russian");
srand(time(nullptr));
int n;
cout<<"������� ���-�� ������: ";
cin>> n;

vector<vector<int>>Matr(n, vector<int>(n));
vector<vector<int>> list(n);

// ������� 1
cout<<"������� ��������� "<<endl;

for (int i = 0; i< n; i++) {
for (int j = i; j < n; j++) {
if (i == j) {
Matr[i][j] = 0;
            }
else {
Matr[i][j] = rand() % 2;
Matr[j][i] = Matr[i][j];
            }
        }
    }

// ������������ 1
for (int i = 0; i< n; i++) {
for (int j = 0; j < n; j++) {
cout<<Matr[i][j]<<" ";
        }
cout<<endl;
    }
cout<<"\n";

vector<bool>entered(n, false);

cout<<"\n����� ������� � ������:\n";

clock_t start, end;
    start = clock();

// �������������������
for (int i = 0; i< n; i++) {
if(!entered[i]) {
bool isolated = true;
for (int j = 0; j < n; j++) {
if (Matr[i][j] == 1) {
                    isolated = false;
break;
                }
            }
if(!isolated) {
queue<int> q;
q.push(i);
                entered[i]=true;
while(!q.empty()) {
int v = q.front();
q.pop();

cout<< v + 1 <<" ";

for (int j = 0; j < n; j++) {
if (Matr[v][j] == 1 && !entered[j]) {
q.push(j);
                            entered[j]=true;
                        }
                    }
                }
            }
        }
    }

    end = clock();
double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
cout<<"\n����� ���������� ��� ������ ������� � ������: "<<cpu_time_used<<" ������."<<endl;

// ����� ������� � ������ �� ������ ������ �� �й3
start = clock();
breadthFirstTraversal(Matr, n);
    end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
cout<<"����� ���������� ��� ������ ������� � ������ (������): "<<cpu_time_used<<" ������."<<endl;

// ���������� ������ ��������� �� ������ �������
for (int i = 0; i < n; ++i) {
for (int j = 0; j < n; ++j) {
if (Matr[i][j] == 1) {
                list[i].push_back(j);
//list[j].push_back(i); // ��������� �������� �����
            }
        }
    }

// ����� ������ ���������
cout<<"\n";
cout<<"\n���������������:\n";

for (int i = 0; i< n; ++i) {
cout<<"����. � "<<i + 1 <<": ";

for (int j = 0; j < list[i].size(); ++j) {
cout<< list[i][j] + 1 <<" ";
        }

cout<<"\n";
}

cout<<"\n����� ������ � ������:\n";

vector<bool> entered2(n, false);

// ����� ������� � ������ ������ ���������
start = clock();
for (int i = 0; i< n; i++) {
if(!entered2[i]) {
bool isolated = list[i].empty();
if(!isolated) {
queue<int> q;
q.push(i);
                entered2[i]=true;
while(!q.empty()) {
int v = q.front();
q.pop();

cout<< v + 1 <<" ";

for (int j = 0; j < list[v].size(); j++) {
int u = list[v][j];
if(!entered2[u]) {
q.push(u);
                            entered2[u]=true;
                        }
                    }
                }
            }
        }
    }
    end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
cout<<"����� ���������� ��� ������ ������ � ������: "<<cpu_time_used<<" ������."<<endl;

return 0;

}
