#include <iostream>
#define l 8

using namespace std;

int nodes[l][l] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 1, 1, 1, 0},
};
int s[l];
int top = 0;
string label = "ABCDEFGH";

void makeZero(int index){
	for(int i = 0; i < l; i++){
		nodes[i][index] = 0;
	}
}

int main()
{
	cout<<label[0]<<" ";
	makeZero(0);
	s[top++] = 0;

	int i = 0;
	while(top > -1){
		int j = 0;

		while(nodes[i][j] != 1 && j < l) j++;
		if(j < l){
			s[top++] = j;
			cout<<label[j]<<" ";
			makeZero(j);
			i = j, j = 0;
		}else{
			i = s[--top];
		}
	}

	return 0;
}
