#include<stdio.h>
#define INF 100000
#define true 1
// ����� ����
int number = 6;
// ���, ������ ����
int a[6][6] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0},
};

int visited[6] = { 0,0,0 };
int dist[6] = {0, 0, 0};

/*
1. �湮���� �ʴ� ��� �� ���� ª�� �Ÿ��� ��带 �߰��Ѵ�.
2. �ش� ��带 �������� �ش� ��忡 ����� �ٸ� �������� �ִܰŸ��� �ֽ�ȭ @
*/

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (dist[i] < min && !visited[i]) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		dist[i] = a[start][i];
	}
	visited[start] = true;
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		visited[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!visited[j]) {
				if (dist[current] + a[current][j] < dist[j]) {
					dist[j] = dist[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", dist[i]);
	}
}