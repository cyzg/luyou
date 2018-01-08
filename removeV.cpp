#include"Router.h"
template<class T>
void RemoveV(Router<T> &G)
{
	cout << "ÁõÓîÇç" << endl;
	cout <<endl<< "ÊäÈëÉ¾³ýµÄ¶¥µã£¨¼´Â·ÓÉÆ÷ÐòºÅ£©£º";
	int v;
	cin >> v;
	if (G.removeVertex(G.getVertexPos(v)) == true)
	{
		cout << "É¾³ý³É¹¦!" << endl;
		return;
	}
	else cerr << "É¾³ýÊ§°Ü!" << endl;
}