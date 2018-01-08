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
	cout << "������·����" << endl;
	cin >> vv;
	int v = G.getVertexPos(vv);
	if(v==-1){
		cerr<<"�����ڴ�·����"<<endl;
		return; 
	}
	int n = G.NumberOfVertices();
	int  *path = new int[n];
	int  *dist = new int[n];
	cout << "�������Ϊ:" << G.NumberOfVertices() << endl;
	cout << "�ߵ�����Ϊ:" << G.NunberOfEdges() << endl;
	cout << "��㼯��Ϊ:";
	for (int i = 0; i< G.NumberOfVertices(); i++)
		cout << " R" << G.getValue(i);
	cout << endl;
	G.ShortestPath(v, dist, path);
	for (int i = 0; i < G.NumberOfVertices(); i++)
	{
		if (i != v)
			cout << " Ŀ��·���� �� R" << G.getValue(i) << "      ��һ�� ��R" << G.getValue(path[i])<< endl;
	}
}
template<class T>
void RemoveV(Router<T> &G)
{
	cout << endl << "����ɾ���Ķ��㣨��·������ţ���";
	int v;
	cin >> v;
	if (G.removeVertex(G.getVertexPos(v))==true){
		cout<<"ɾ���ɹ�!" <<endl;
		return;
	}
	else cerr<<"ɾ��ʧ��!"<<endl ;
}
template<class T>
void RemoveE(Router<T> &G)
{
	cout << endl << "����ɾ���ıߣ���������·������ţ��ÿո�ֿ�����";
	int v1, v2;
	cin >> v1 >> v2;
	if (G.removeEdge(G.getVertexPos(v1), G.getVertexPos(v2))==true){
		cout<<"ɾ���ɹ�!" <<endl;
		return;
	}
	else {
	cerr<<"ɾ��ʧ��!"<<endl ;
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
		cout<<" 1.����ָ��·�����ŵ�·�ɱ�"<<endl;
		cout<<" 2.ɾ������" <<endl;
		cout<<" 3.ɾ����" <<endl; 
		cout<<" 4.�˳�"<<endl;
		cout<<"������ѡ�����ţ�"; 
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


