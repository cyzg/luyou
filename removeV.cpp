#include"Router.h"
template<class T>
void RemoveV(Router<T> &G)
{
	cout << "������" << endl;
	cout <<endl<< "����ɾ���Ķ��㣨��·������ţ���";
	int v;
	cin >> v;
	if (G.removeVertex(G.getVertexPos(v)) == true)
	{
		cout << "ɾ���ɹ�!" << endl;
		return;
	}
	else cerr << "ɾ��ʧ��!" << endl;
}