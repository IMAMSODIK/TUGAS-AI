#include <iostream>
#include <vector>
#define length 13

using namespace std;

string listKota[length] = {"Arad", "Zerind", "Oradea", "Timisoara", "Lugoj", "Mehadia","Drobeta","Sibiu","Rimnicu-Vilcea","Craiova","Fagaras","Pitesti","Bucharest"};
vector<int> path;
vector<pair<vector<int>, int>> panjangJalan;
int visited[length] = {0};

//jalan dari kota a ke kota b diilustrasikan sebagai adjacency matrix sebagai berikut
int data[length][length] = {
	{0, 75, -1, 118, -1, -1, -1, 140, -1, -1, -1, -1, -1},
	{75, 0, 71, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, 71, 0, -1, -1, -1, -1, 151, -1, -1, -1, -1, -1},
	{118, -1, -1, 0, 111, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, 111, 0, 70, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, 70, 0, 75, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 75, 0, -1, -1, 120, -1, -1, -1},
	{140, -1, 151, -1, -1, -1, -1, 0, 80, -1, 99, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, 80, 0, 146, -1, 97, -1},
	{-1, -1, -1, -1, -1, -1, 120, -1, 146, 0, -1, 138, -1},
	{-1, -1, -1, -1, -1, -1, -1, 99, -1, -1, 0, -1, 211},
	{-1, -1, -1, -1, -1, -1, -1, -1, 97, 138, -1, 0, 101},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 211, 101, 0},
};

int nextNode(int x, int loc){
	for(int i = x + 1; i < length; i++){
		if(data[loc][i] > 0 && visited[i] == 0){
			return i;
		}
	}return -1;
}

int lengthCount(){
	int cost = 0, index = 0;

	for(; index < path.size() - 1; index++){
		cost += data[path[index]][path[index + 1]];
	}cost += data[path[index]][length-1];
	return cost;
}

void DFS(int start, int end){
	int loc = 0, cost = 0;

	visited[start] = 1;
	path.push_back(start);
	while((loc = nextNode(loc, start)) != -1){
		if(loc == end){
			cout<<"jalan : ";
			for(int i = 0; i < path.size(); i++){
				cout<<listKota[path[i]]<<" => ";
				cost = lengthCount();
				panjangJalan.push_back(pair<vector<int>, int>(path, cost));
			}
			cout<<listKota[end]<<endl<<"panjang : " << cost<<endl;
			break;
		}
		DFS(loc, end);
		path.pop_back();
		visited[loc] = 0;
	}
}

int shorthestPath(vector<pair<vector<int>, int>> panjangJalan){
	int minIndex = 0, index = 1;

	for(; index < panjangJalan.size(); index++){
		if(panjangJalan[minIndex].second >= panjangJalan[index].second){
			minIndex = index;
		}
	}return minIndex;
}	

int main()
{
	int start = 0, end = 12, index = 0;

	DFS(start, end);
	index = shorthestPath(panjangJalan);
	cout<<"Jalan Terpendek : ";
	for(int i = 0; i < panjangJalan[index].first.size(); i++){
		cout<<listKota[panjangJalan[index].first[i]]<<" -> ";
	}cout<<listKota[end]<<endl;

	return 0;
}
