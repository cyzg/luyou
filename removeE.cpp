#include"Router.h"
template<class T>
void RemoveE(Router<T> &G)
{
	cout << "ÁõÓîÇç" ;
	cout <<endl<< "ÊäÈëÉ¾³ýµÄ±ß£¨¼´ÄÄÁ½¸öÂ·ÓÉÆ÷ÐòºÅ£¬ÓÃ¿Õ¸ñ·Ö¿ª£©£º";
	int v1, v2;
	cin >> v1 >> v2;
	if (G.removeEdge(G.getVertexPos(v1), G.getVertexPos(v2)) == true) {
		cout << "É¾³ý³É¹¦!" << endl;
		return;
	}
	else {
		cerr << "É¾³ýÊ§°Ü!" << endl;
	}
}