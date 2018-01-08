#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include   <fstream>
using namespace std;
#include "Router.h"
const int MaxVertices = 100;

template<class T>
void Print(Router<T> &G)
{
	int  vv;
	cout << "请输入路由器" << endl;
	cin >> vv;
	int v = G.getVertexPos(vv);
	if(v==-1){
		cerr<<"不存在此路由器"<<endl;
		return; 
	}
	int n = G.NumberOfVertices();
	int  *path = new int[n];
	int  *dist = new int[n];
	cout << "顶点个数为:" << G.NumberOfVertices() << endl;
	cout << "边的条数为:" << G.NunberOfEdges() << endl;
	cout << "结点集合为:";
	for (int i = 0; i< G.NumberOfVertices(); i++)
		cout << " R" << G.getValue(i);
	cout << endl;
	G.ShortestPath(v, dist, path);
	for (int i = 0; i < G.NumberOfVertices(); i++)
	{
		if (i != v)
			cout << " 目的路由器 ： R" << G.getValue(i) << "      下一跳 ：R" << G.getValue(path[i])<< endl;
	}
}
template<class T>
void RemoveV(Router<T> &G)
{
	cout << endl << "输入删除的顶点（即路由器序号）：";
	int v;
	cin >> v;
	if (G.removeVertex(G.getVertexPos(v))==true){
		cout<<"删除成功!" <<endl;
		return;
	}
	else cerr<<"删除失败!"<<endl ;
}
template<class T>
void RemoveE(Router<T> &G)
{
	cout << endl << "输入删除的边（即哪两个路由器序号，用空格分开）：";
	int v1, v2;
	cin >> v1 >> v2;
	if (G.removeEdge(G.getVertexPos(v1), G.getVertexPos(v2))==true){
		cout<<"删除成功!" <<endl;
		return;
	}
	else {
	cerr<<"删除失败!"<<endl ;
	}
}


int main() {
	Router<int> g1;
	ifstream fin1("D:\\vertex.txt");
	int v;
	while (!fin1.eof()) {
		fin1 >> v;
		g1.insertVertex(v);
	}
	fin1.clear();
	fin1.close();
	ifstream fin2("D:\\edge.txt");
	int v1, v2, e;
	while (!fin2.eof())
	{
		fin2 >> v1;
		fin2 >> v2;
		fin2 >> e;
		g1.insertEdge(v1, v2, e);
	}
	fin2.clear();
	fin2.close();
	while(1){
		cout<<" 1.生成指定路由器号的路由表"<<endl;
		cout<<" 2.删除顶点" <<endl;
		cout<<" 3.删除边" <<endl; 
		cout<<" 4.退出"<<endl;
		cout<<"请输入选择的序号："; 
		int i;
		cin>>i; 
		if (i==1)
			Print(g1);
		else if(i==2)
			RemoveV(g1);
		else if(i==3)
			RemoveE(g1);
		else break;
		system("pause");
	}

	return 0;
}


