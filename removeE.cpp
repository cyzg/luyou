#include"Router.h"
template<class T>
void RemoveE(Router<T> &G)
{
	cout << "������" ;
	cout <<endl<< "����ɾ���ıߣ���������·������ţ��ÿո�ֿ�����";
	int v1, v2;
	cin >> v1 >> v2;
	if (G.removeEdge(G.getVertexPos(v1), G.getVertexPos(v2)) == true) {
		cout << "ɾ���ɹ�!" << endl;
		return;
	}
	else {
		cerr << "ɾ��ʧ��!" << endl;
	}
}