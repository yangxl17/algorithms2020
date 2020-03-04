#pragma once
#include "BST.h"
template <class P,class T=int>
class RedBlackTree:public BST<P,T>
{
private:
	using BST<P, T>::root;
	using BST<P, T>::null;
	void LeftRotate(BSTnode<P,T>* x);
	void RightRotate(BSTnode<P, T>* x);
	void RBInsertFixUp(BSTnode<P, T>* x);
	void RBRemoveFixUp(BSTnode<P, T>* x);
public:
	void Insert(const T& key, const P& data);
	void Remove(const T& k);
};

template<class P, class T>
inline void RedBlackTree<P, T>::LeftRotate(BSTnode<P,T>* x)
{
	BSTnode<P, T>* y = x->rightchild;
	y->parent = x->parent;
	if (x == root)
	{
		root = y;
	}
	else if (x->parent->leftchild == x)
	{
		x->parent->leftchild = y;
	}
	else
	{
		x->parent->rightchild = y;
	}
	x->rightchild = y->leftchild;
	if (y->leftchild != null)
	{
		y->leftchild->parent = x;
	}
	y->leftchild = x;
	x->parent = y;
}

template<class P, class T>
inline void RedBlackTree<P, T>::RightRotate(BSTnode<P, T>* y)
{
	BSTnode<P, T>* x = y->leftchild;
	x->parent = y->parent;
	if (y == root)
	{
		root = x;
	}
	else if (y == y->parent->leftchild)
	{
		y->parent->leftchild = x;
	}
	else
	{
		y->parent->rightchild = x;
	}
	y->leftchild = x->rightchild;
	if (x->rightchild != null)
	{
		x->rightchild->parent = y;
	}
	y->parent = x;
	x->rightchild = y;
}

template<class P, class T>
inline void RedBlackTree<P, T>::RBInsertFixUp(BSTnode<P, T>* x)
{
	while (x->parent->color == Color::Red)
	{
		if (x->parent == x->parent->parent->leftchild)
		{
			if (x->parent->parent->rightchild->color == Color::Red)
			{
				BSTnode<P, T>* y = x->parent;
				y->color = Color::Black;
				y->parent->rightchild->color = Color::Black;
				y->parent->color = Color::Red;
				x = y->parent;
			 }
			else if (x == x->parent->rightchild)
			{
				x = x->parent;
				LeftRotate(x);
			}
			else
			{
				x->parent->color = Color::Black;
				x->parent->parent->color = Color::Red;
				RightRotate(x->parent->parent);
			}
		}
		else
		{
			if (x->parent->parent->leftchild->color == Color::Red)
			{
				BSTnode<P, T>* y = x->parent;
				y->color = Color::Black;
				y->parent->leftchild->color = Color::Black;
				y->parent->color = Color::Red;
				x = y->parent;
			}
			else if (x == x->parent->leftchild)
			{
				x = x->parent;
				RightRotate(x);
			}
			else
			{
				x->parent->color = Color::Black;
				x->parent->parent->color = Color::Red;
				LeftRotate(x->parent->parent);
			}
		}
	}
	root->color = Color::Black;
}

template<class P, class T>
inline void RedBlackTree<P, T>::RBRemoveFixUp(BSTnode<P, T>* x)
{
	while (x->color == Color::Black && x != root)
	{
		if (x == x->parent->leftchild)
		{
			BSTnode<P, T>* y = x->parent->rightchild;
			if (y->color == Color::Red)
			{
				y->color = Color::Black;
				x->parent->color = Color::Red;
				LeftRotate(y->parent);
				y = x->parent->rightchild;
			}
			if(y->leftchild->color==Color::Black&&y->rightchild->color==Color::Black)
			{
				y->color = Color::Red;
				x = x->parent;
			}
			else 
			{
				if (y->rightchild->color == Color::Black)
				{
					y->leftchild->color = Color::Black;
					y->color = Color::Red;
					RightRotate(y);
					y = x->parent->rightchild;
				}
				y->rightchild->color = Color::Black;
				y->color = y->parent->color;
				y->parent->color = Color::Black;
				LeftRotate(y->parent);
				x = root;
			}
		}
		else
		{
			BSTnode<P, T>* y = x->parent->leftchild;
			if (y->color == Color::Red)
			{
				y->color = Color::Black;
				x->parent->color = Color::Red;
				LeftRotate(y->parent);
				y = x->parent->leftchild;
			}
			if (y->leftchild->color == Color::Black && y->rightchild->color == Color::Black)
			{
				y->color = Color::Red;
				x = x->parent;
			}
			else
			{
				if (y->leftchild->color == Color::Black)
				{
					y->rightchild->color = Color::Black;
					y->color = Color::Red;
					LeftRotate(y);
					y = x->parent->leftchild;
				}
				y->leftchild->color = Color::Black;
				y->color = y->parent->color;
				y->parent->color = Color::Black;
				RightRotate(y->parent);
				x = root;
			}
		}
	}
	x->color = Color::Black;
}

template<class P, class T>
inline void RedBlackTree<P, T>::Insert(const T& key, const P& data)
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
	RBInsertFixUp(node);
}

template<class P, class T>
inline void RedBlackTree<P, T>::Remove(const T& k)
{
	BSTnode<P,T>* z = BST<P,T>::Search(k);
	if (z != null)
	{
		BSTnode<P, T>* y = z;
		Color yOriginalColor = y->color;
		BSTnode<P, T>* x = null;
		if (z->leftchild == null)
		{
			BST<P, T>::TransPlant(z, z->rightchild);
			x = z->rightchild;
		}
		else if (z->rightchild == null)
		{
			BST<P, T>::TransPlant(z, z->leftchild);
			x = z->leftchild;
		}
		else
		{
			y = BST<P, T>::Minimum(z->rightchild);
			yOriginalColor = y->color;
			x = y->rightchild;
			if (y == z->rightchild)
			{
				x->parent = y;
			}
			else
			{
				BST<P, T>::TransPlant(y, y->rightchild);
				y->rightchild = z->rightchild;
				y->rightchild->parent = y;
			}
			BST<P, T>::TransPlant(z, y);
			y->leftchild = z->leftchild;
			y->leftchild->parent = y;
			y->color = z->color;
			delete z;
		}
		if (yOriginalColor == Color::Black)
		{
			RBRemoveFixUp(x);
		}
	}
}



