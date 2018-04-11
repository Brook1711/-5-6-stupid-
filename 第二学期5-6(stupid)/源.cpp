#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T> * next;
};

template<class T>
class LinkList
{
private:
	Node<T> * front;
public:
	LinkList(int sum);
	~LinkList();
	Node<T> * Getfront();
};

template<class T>
LinkList<T>::LinkList(int sum)
{
	front = new Node<T>;
	front->data = sum;
	Node<T> * r = front;
	for (int i = 0; i < sum; i++)
	{
		T temp;
		cin >> temp;
		r->next = new Node<T>;
		r = r->next;
		r->data = temp;
	}

	r->next = NULL;
	r = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T> *r = front;
	while (r)
	{
		r = front->next;
		delete front;
		front = r;
	}


}

template<class T>
Node<T> * LinkList<T>::Getfront()
{
	return front;
}

template<class T>
bool judgement(LinkList<T> &L,LinkList<T> &CL)
{
	Node<T>* y = L.Getfront();
	Node<T>* w = CL.Getfront();
	y = y->next;
	w = w->next;
	int yWin(0);
	int i(0);

	bool isIt = false;
	while (y)
	{
		int yH = y->data;
		int wH = w->data;
		if (yH > wH)
		{
			yWin++;
		}
		
		y = y->next;
		w = w->next;
		i++;
	}
	if (yWin * 2 > i)
		isIt = true;
	return isIt;
}

template<class T>
void F(LinkList<T> &L,LinkList<T> &CL ,int n, int & count)
{
	if (n == 1)
	{
		if (judgement(L,CL))
		{
			count++;
		}
	}
	else
	{

		for (int i = 0; i < n; i++)
		{

			Node<T> * front = L.Getfront();
			Node<T> * p = L.Getfront();
			Node<T> * r = L.Getfront();
			for (int i = 0; i < n; i++)
			{
				p = p->next;
			}
			for (int i = 0; i < n - 1; i++)
			{
				r = r->next;
			}
			Node<T> * tempFN = front->next;
			front->next = new Node<T>;
			front->next->data = p->data;
			front->next->next = tempFN;
			r->next = p->next;
			delete p;
			F(L, CL, n - 1, count);



		}

	}
}

int main()
{
	int sum = 0;
	while (cin >> sum)
	{
		int Count = 0;
		bool T;
		if (sum == 0)
			break;
		LinkList<int> yuan(sum);
		LinkList<int> wang(sum);
		F(yuan, wang, sum, Count);
		if (Count == 0)
		cout << "NO" << endl;
		else
		cout << "YES" << endl;
	}
	
	//cout << Count;
	//system("pause");
	return 0;
}