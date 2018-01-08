#pragma once

#include <iomanip>
#ifndef Router_H
#define Router_H
using namespace std;
const int maxWeight = INT_MAX;
const int DeafultVertices = 30;			//������󶥵���
template<class T>
struct Edge
{
	int dest;			//�ߵ���һ������λ��
	int cost;				//���ϵ�Ȩֵ
	Edge<T> * link;	//��һ������ָ��
	Edge() {}
	Edge(int num, int weight) : dest(num), cost(weight), link(NULL) {}
	bool operator != (Edge<T>& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};
template<class T>
struct Vertex
{
	T data;
	Edge<T> *adj;			//�������ͷָ��
	Vertex() :adj(NULL) { }
};


template<class T>
class Router // public Graph<T>
{
public:
	Router(int sz = DeafultVertices);
	~Router();
	T getValue(int i)					//ȡλ��Ϊi�Ķ����е�ֵ
	{
		return (i >= 0 && i< numVertices) ? NodeTable[i].data : 0;
	}
	int getWeight(int v1, int v2);			//���ر�(v1,v2)��Ȩֵ
	int NumberOfVertices() { return numVertices; }		//���ص�ǰ������
	int NunberOfEdges() { return numEdges; }			//���ص�ǰ����
	bool insertVertex(const T vertex);			//����һ������vertex	
	bool removeVertex(int v);//ɾȥ����v��������v��صı�
	bool insertEdge(int v1, int v2, int cost);//�����(v1,v2),ȨΪcost
	bool removeEdge(int v1, int v2);//ɾȥ��(v1,v2)
	void ShortestPath(int v, int *dist, int *path);//����һ��
	int getVertexPos(const T vertex)
	{
		for (int i = 0; i< numVertices; i++)
			if (NodeTable[i].data == vertex)
				return i;
		return -1;
	}
private:
	int maxVertices;
	int numEdges;
	int numVertices;
	Vertex<T> * NodeTable;
};
template<class T>
Router<T>::Router(int sz /* = DeafultVertices */)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = NULL;

	try
	{
		NodeTable = new Vertex<T>[maxVertices];
	}
	catch (bad_alloc & memExp)
	{
		cerr << memExp.what() << endl;
	}

	for (int i = 0; i<maxVertices; i++)
		NodeTable[i].adj = NULL;
}
template<class T>
Router<T>::~Router()
{
	for (int i = 0; i<maxVertices; i++)
	{
		Edge<T> * p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[] NodeTable;
}
template<class T>
int Router<T>::getWeight(int v1, int v2)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices && v1 != v2)
	{
		Edge<T> *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
			return p->cost;
		else
			return maxWeight;
	}
	else
		if (v1 == v2)
			return 0;
		else return -1;
}
template<class T>
bool Router<T>::insertVertex(const T vertex)
{
	if (getVertexPos(vertex) >= 0) return false;
	if (numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}
template<class T>
bool Router<T>::removeVertex(int v)
{
	if (numVertices == 1 || v<0 || v >= numVertices)return false;
	Edge<T> *p, *s, *t;
	int k;
	while (NodeTable[v].adj != NULL)
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		while (s != NULL && s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL) NodeTable[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	NodeTable[v].data = NodeTable[numVertices].data;
	p = NodeTable[v].adj = NodeTable[numVertices].adj;
	while (p != NULL)
	{
		s = NodeTable[p->dest].adj;
		while (s != NULL)
			if (s->dest == numVertices) {
				s->dest = v;
				break;
			}
			else s = s->link;
			p = p->link;
	}
	return true;
}
template<class T>
bool Router<T>::insertEdge(int v1, int v2, int cost)
{
	if (v1 >= 0 && v1< numVertices && v2 >= 0 && v2<numVertices && v1 != v2)
	{
		Edge<T> *q, *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
		{
			p->cost = cost;
			return true;
		}
		p = new Edge<T>;
		q = new Edge<T>;
		p->dest = v2;
		p->cost = cost;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1;
		q->cost = cost;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return false;
}
template<class T>
bool Router<T>::removeEdge(int v1, int v2)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices && v1 != v2)
	{
		Edge<T> *p = NodeTable[v1].adj, *q = NULL, *s = p;
		while (p != NULL && p->dest != v2)
		{
			q = p;
			p = p->link;
		}
		if (p != NULL)
		{
			if (p == s)
				NodeTable[v1].adj = p->link;
			else
			{
				q->link = p->link;
			}
			delete p;
		}
		else
		{
			return false;
		}
		p = NodeTable[v2].adj;
		q = NULL;
		s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			NodeTable[v2].adj = p->link;
		else
		{
			q->link = p->link;
		}
		delete p;
		return true;
	}
	return false;
}


template<class T>
void Router<T>::ShortestPath(int v, int *dist, int *path)
{
	int n = numVertices;
	bool *S = new bool[n];          //���·�����㼯
	int w, min;
	int i;
	for ( i = 0; i<n; i++)
	{
		dist[i] = getWeight(v, i);   //�����ʼ��
		S[i] = false;
		if (i != v && dist[i] < maxWeight)
			path[i] = i;
		else path[i] = -1;
	}
	S[v] = true; dist[v] = 0;           //����v���붥�㼯�� 
	for (i = 0; i<n - 1; i++)
	{
		min = maxWeight; int u = v;      //ѡ����S�о������·���Ķ���u��ѡ����̵��Ǹ� 
		for (int j = 0; j<n; j++)
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		S[u] = true;               //������u���뼯��S
		for (int k = 0; k<n; k++)          //�޸� 
		{
			w = getWeight(u, k);
			if (S[k] == false && w < maxWeight && dist[u] + w<dist[k])//����kδ����S�����ƹ�u��������·�� 
			{
				dist[k] = dist[u] + w;
				path[k] = path[u];             //�޸ĵ�k�����·�� 
			}
		}
	}
}
#endif
