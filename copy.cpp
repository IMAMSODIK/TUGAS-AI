#include <iostream>
using namespace std;

int data[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 1, 0, 0, 0},
	{0, 1, 0, 1, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 1, 1},
	{0, 0, 1, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
};
int visited[8] = {0};
int stack[8];
int top = 0;
string label = "ABCDEFGH";

int main()
{
	visited[0] = 1;
	int i = 0, j = 0;
	stack[top++] = 0;
	bool isLimit = 0;

	while(top > -1){
		while(data[i][j] == 1 && visited[j] = 0 && j < 8){
			j++;
		}
		if(j < 8){
			visited[j] = 1;
			i = j, j = 0;
			stack[top++] = i;
			if(i == 7){
				for(int i = 0; i < top; i++){
					cout<<label[stack[i]]<<' ';
				}
				isLimit = 1;
				break;
			}
		}if(isLimit) break;
	}

	return 0;
}