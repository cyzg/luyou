#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include"removeE.cpp"
#include"removeV.cpp"
#include"print.cpp"

using namespace std;
#include "Router.h"
const int MaxVertices = 100;
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


