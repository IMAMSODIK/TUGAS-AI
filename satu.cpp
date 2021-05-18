#include <iostream>
#include <vector>
#define length 13

using namespace std;

string listKota[length] = {"Arad", "Zerind", "Oradea", "Timisoara", "Lugoj", "Mehadia","Drobeta","Sibiu","Rimnicu-Vilcea","Craiova","Fagaras","Pitesti","Bucharest"};
vector<int> path;
vector<pair<vector<int>, int>> pathCost;
int visited[length] = {0};
int data[length][length] = {
	{0, 75, -1,118, -1, -1, -1,140, -1, -1, -1, -1, -1 },
	{-1,  0, 71, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1,  0, -1, -1, -1, -1,151, -1, -1, -1, -1, -1},
	{-1, -1, -1,  0,111, -1, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1,  0, 70, -1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1,  0, 75, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1,  0, -1, -1,120, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1,  0, 80, -1, 99, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1,  0,146, -1, 97, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1,138, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, 211},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, 101},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0}
};

void createAdjacencyMatrix(){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length; j++){
			if(data[i][j] != -1){
				data[j][i] = data[i][j];			}
		}
	}
}

int nextOutdegree(int interrupt, int loc){
	for(int i = interrupt + 1; i < length; i++){
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
	while((loc = nextOutdegree(loc, start)) != -1){
		if(loc == end){
			cout<<"jalan : ";
			for(int i = 0; i < path.size(); i++){
				cout<<listKota[path[i]]<<" => ";
				cost = lengthCount();
				pathCost.push_back(pair<vector<int>, int>(path, cost));
			}
			cout<<listKota[end]<<endl<<"panjang : " << cost<<endl;
			break;
		}
		DFS(loc, end);
		path.pop_back();
		visited[loc] = 0;
	}
}

int shorthestPath(vector<pair<vector<int>, int>> pathCost){
	int minIndex = 0, index = 1;

	for(; index < pathCost.size(); index++){
		if(pathCost[minIndex].second >= pathCost[index].second){
			minIndex = index;
		}
	}return minIndex;
}	

int main()
{
	int start = 0, end = 12, index = 0;

	createAdjacencyMatrix();
	DFS(start, end);
	
	index = shorthestPath(pathCost);
	cout<<"min cost : ";
	for(int i = 0; i < pathCost[index].first.size(); i++){
		cout<<listKota[pathCost[index].first[i]]<<" -> ";
	}cout<<listKota[end]<<endl;

	return 0;
}