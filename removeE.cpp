#include"Router.h"
template<class T>
void RemoveE(Router<T> &G)
{
	cout << endl << "输入删除的边（即哪两个路由器序号，用空格分开）：";
	int v1, v2;
	cin >> v1 >> v2;
	if (G.removeEdge(G.getVertexPos(v1), G.getVertexPos(v2)) == true) {
		cout << "删除成功!" << endl;
		return;
	}
	else {
		cerr << "删除失败!" << endl;
	}
}