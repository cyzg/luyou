#include"Router.h"
template<class T>
void Print(Router<T> &G)
{
	cout << "ylq" << endl;
	int  vv;
	cout << "������·����" << endl;
	cin >> vv;
	int v = G.getVertexPos(vv);
	if (v == -1) {
		cerr << "�����ڴ�·����" << endl;
		return;
	}
	int n = G.NumberOfVertices();
	int  *path = new int[n];
	int  *dist = new int[n];
	int i;
	cout << "�������Ϊ:" << G.NumberOfVertices() << endl;
	cout << "�ߵ�����Ϊ:" << G.NunberOfEdges() << endl;
	cout << "��㼯��Ϊ:";
	for (i = 0; i< G.NumberOfVertices(); i++)
		cout << " R" << G.getValue(i);
	cout << endl;
	G.ShortestPath(v, dist, path);
	for (i = 0; i < G.NumberOfVertices(); i++)
	{
		if (i != v)
			cout << " Ŀ��·���� �� R" << G.getValue(i) << "      ��һ�� ��R" << G.getValue(path[i]) << endl;
	}
	
}