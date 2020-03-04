#pragma once
#include<iostream>
enum class Color{Red,Black};
std::ostream& operator<<(std::ostream& out, const Color& color);
template <class P, class T=int>
struct BSTnode
{
	BSTnode* parent = nullptr;
	BSTnode* leftchild = nullptr;
	BSTnode* rightchild = nullptr;
	Color color= Color::Red;
	T key=T();
	P data=P();
};
template <class P, class T=int>
class BST
{
protected:
	BSTnode<P, T>* null;
	BSTnode<P,T>* root;
	BSTnode<P,T>* Minimum(BSTnode<P,T>* x);
	BSTnode<P,T>* Maxmum(BSTnode<P,T>* x);
	BSTnode<P,T>* Successor(BSTnode<P,T>* x);
	void DeleteTree(BSTnode<P, T>* x);
	void TransPlant(BSTnode<P, T>* u, BSTnode<P, T>* v);
public:
	BST();
	~BST();
	void InorderTreeWalk();
	void InorderTreeWalk(BSTnode<P,T>* x);
	virtual void Insert(const T& key, const P& data);
	BSTnode<P,T>* Search(const T& k);
	virtual void Remove(const T& k);
	P& operator[](const T& k);
};

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Minimum(BSTnode<P, T>* x)
{
	if (x == null)
	{
		return null;
	}
	else
	{
		while (x->leftchild != null)
		{
			x = x->leftchild;
		}
		return x;
	}
}

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Maxmum(BSTnode<P, T>* x)
{
	if (x == null)
	{
		return null;
	}
	else
	{
		while (x->rightchild != null)
		{
			x = x->rightchild;
		}
		return x;
	}
}

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Successor(BSTnode<P, T>* x)
{
	const auto y = x;
	if (x != null)
	{
		if (x->rightchild != null)
		{
			return Minimum(x->rightchild);
		}
		else
		{
			while (x->parent!=null&&x->parent->rightchild==x)
			{
				x = x->parent;
			}
			return x->parent;
		}
	}
	return null;
}

template<class P, class T>
inline void BST<P, T>::DeleteTree(BSTnode<P, T>* x)
{
	if (x == null)
	{
		DeleteTree(x->leftchild);
		DeleteTree(x->rightchild);
		delete x;
	}
}

template<class P, class T>
inline void BST<P, T>::TransPlant(BSTnode<P, T>* u, BSTnode<P, T>* v)
{
	if (u == root)
	{
		root = v;
	}
	else
	{
		if (u->parent->leftchild == u)
		{
			u->parent->leftchild = v;
		}
		else
		{
			u->parent->rightchild = v;
		}
	}
	v->parent = u->parent;
}

template<class P, class T>
inline BST<P, T>::BST()
{
	null = new BSTnode<P, T>;
	null->color = Color::Black;
	root = null;
}

template<class P, class T>
inline BST<P, T>::~BST()
{
	DeleteTree(root);
	delete null;
}

template<class P, class T>
inline void BST<P, T>::InorderTreeWalk()
{
	InorderTreeWalk(root);
}

template<class P, class T>
inline void BST<P, T>::InorderTreeWalk(BSTnode<P, T>* x)
{
	if (x != null)
	{
		InorderTreeWalk(x->leftchild);
		std::cout << x->key << ":" << x->data <<"<"<< x->color;
		int i = 0;
		BSTnode<P, T>* y = x;
		if (y->leftchild == null && y->rightchild == null)
		{
			while (y != null)
			{
				if (y->color == Color::Black)
				{
					i = i + 1;
				}
				y = y->parent;
			}
			std::cout << "<" << i << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}
		if (y->color == Color::Red && y->parent->color == Color::Red)
		{
			for (int i = 0; i < 10; i++)
			{
				std::cout << "Error£¡";
			}
			std::cout << std::endl;
		}
		InorderTreeWalk(x->rightchild);
	}
}

template<class P, class T>
inline void BST<P, T>::Insert(const T& key, const P& data)
{
	BSTnode<P, T>* x = root;
	BSTnode<P, T>* node = new BSTnode<P, T>;
	node->key = key;
	node->data = data;
	node->leftchild = null;
	node->rightchild = null;
	node->parent = null;
	if (x == null)
	{
		root = node;
	}
	else
	{
		while (x != null)
		{
			if (x->key > key)
			{
				if (x->leftchild != null)
				{
					x = x->leftchild;
				}
				else
				{
					x->leftchild = node;
					node->parent = x;
					break;
				}
			}
			else
			{
				if (x->rightchild != null)
				{
					x = x->rightchild;
				}
				else
				{
					x->rightchild = node;
					node->parent = x;
					break;
				}
			}
		}
	}
}

template<class P, class T>
inline BSTnode<P, T>* BST<P, T>::Search(const T& k)
{
	BSTnode<P, T>* x = root;
	while (x != null && x->key != k)
	{
		if (x->key > k)
		{
			x = x->leftchild;
		}
		else
		{
			x = x->rightchild;
		}
	}
	return x;
}

template<class P, class T>
inline void BST<P, T>::Remove(const T& k)
{
	BSTnode<P, T>* x = Search(k);
	if (x != null)
	{
		if (x->leftchild == null)
		{
			TransPlant(x, x->rightchild);
		}
		else if (x->rightchild == null)
		{
			TransPlant(x, x->leftchild);
		}
		else
		{
			BSTnode<P, T>* y = Successor(x);
			if (y->parent == x)
			{
				TransPlant(x, y);
				y->leftchild = x->leftchild;
				y->leftchild->parent = y;
			}
			else
			{
				TransPlant(y, y->rightchild);
				TransPlant(x, y);
				y->rightchild = x->rightchild;
				y->rightchild->parent = y;
				y->leftchild = x->leftchild;
				y->leftchild->parent = y;
			}
		}
		delete x;
	}
}

template<class P, class T>
inline P& BST<P, T>::operator[](const T& k)
{
	BSTnode<P, T>* x = Search(k);
	return x->data;
}
