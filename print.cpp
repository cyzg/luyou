#include"Router.h"
template<class T>
void Print(Router<T> &G)
{
	int  vv;
	cout << "请输入路由器" << endl;
	cin >> vv;
	int v = G.getVertexPos(vv);
	if (v == -1) {
		cerr << "不存在此路由器" << endl;
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
			cout << " 目的路由器 ： R" << G.getValue(i) << "      下一跳 ：R" << G.getValue(path[i]) << endl;
	}
}