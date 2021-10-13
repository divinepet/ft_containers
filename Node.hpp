#pragma once

#include <iostream>
#include "Iterator.hpp"
using std::cout;
using std::endl;

template <class T, class V>
class Node;
enum Color { RED = 0, BLACK = 1};

template <class T, class V>
class Node_Base {
	typedef Node_Base<T, V> *node_ptr;
	friend class Node<T, V>;
	friend class ft::node_iterator<Node_Base<T, V> >;
public:
	node_ptr left, right, parent, prior, next;
	Color color;
	T first;
	V second;

	explicit Node_Base(T first, V second) : left(this), right(this), parent(this), first(first), second(second), color(RED) {}
	Node_Base(T first, V second, node_ptr l, node_ptr r) : first(first), second(second), left(l), right(r), parent(this), color(RED) {}

};

template <class T, class V>
class Node {
	friend class Node_Base<T, V>;
	typedef Node_Base<T, V>* node_ptr;
	friend class ft::node_iterator<Node_Base<T, V> >;
public:
	node_ptr header;
	node_ptr root;
	node_ptr _prior;
	node_ptr _next;
	node_ptr NIL;
//	typedef ft::node_iterator< Node_Base<T, V> > node_iterator;
	Node() {
		header = new Node_Base<T, V>(0, 0);
		NIL = new Node_Base<T, V>(0, 0);
		NIL->color = header->color = BLACK;
		root = NIL;
		root->parent = header;
		root->left = root->right = NIL;
		header->left = NIL;
		header->right = root;
		NIL->parent = NIL;
		header->next = NIL;
		header->prior = NIL;
	}

	bool isEmptyNode() 		{ return root == NIL; };
	T getMax() 				{ return header->prior->first; };
	T getMin() 				{ return header->next->first; };
//	node_iterator begin() 	{ return (header->next == NIL) ? root : header->next; }
//	node_iterator end() 	{ return header; }

	node_ptr insertNode(T x, V v) {
		node_ptr n = new Node_Base<T, V>(x, v, NIL, NIL);
		return insertNode(n);
	};

	node_ptr insertNode(node_ptr x) {
		node_ptr one, two;
		one = two = root;
		if(root == NIL) {
			root = x;
			header->right = x;
			x->parent = header;
			x->color = BLACK;
			return x;
		}
		while (one != NIL) {
			two = one;
			if (one->first > x->first)
				one = one->left;
			else if (one->first < x->first)
				one = one->right;
			else
				return x;
		}
		x->parent = two;
		if (two->first > x->first) {
			two->left = x;
		} else {
			two->right = x;
		}
		insertFix(x);
		leftOrRight();
		return x;
	};

	bool deleteNode(T x) {
		node_ptr target = searchNode(x);
		if (target == NIL) {
			leftOrRight();
			return false;
		}
		return deleteNode(target);
	};

	bool deleteNode(node_ptr x) {
		node_ptr a = x;
		node_ptr b = NIL;
		Color a_color = a->color;
		if(x->left == NIL) { // case 1: with one kid or no one
			b = x->right;
			Transplante(x, x->right);
		} else if (x->right == NIL){
			b = x->left;
			Transplante(x, x->left);
		} else {
			node_ptr a = BranchMin(x->right);
			a_color = a->color;
			b = a->right;
			if (a->parent == x) { // case 2: replace node is son of x
				b->parent = a; // case NIL
			} else {
				Transplante(a, a->right); // a break away from there
				a->right = x->right;
				a->right->parent = a;
			}
			Transplante (x, a); // replace old node for new node
			a->left = x->left;
			a->left->parent = a;
			a->color = x->color;
		}
		delete x;
		if (a_color == BLACK) // case 3: black-red rule break
			deleteFix(b);
		leftOrRight();
		return true;
	};

	node_ptr searchNode(T x) {
		node_ptr temp = root;
		while (temp != NIL) {
			if (temp->first > x)
				temp = temp->left;
			else if (temp->first < x)
				temp = temp->right;
			else
				return temp;
		}
		return NIL;
	};

	void printElements() {
		printElements(root);
		cout << endl;
	};

//	size_t sizeNode() {
//		node_iterator temp = begin();
//		size_t count = 0;
//		while (temp != end()) {
//			count++;
//			temp = temp->next;
//		}
//		return count;
//	}

private:

	void leftOrRight() {
		_prior = _next = header;
		leftOrRight(root);
		_next->next=header;
		header->prior=_next;
	};

	void leftOrRight(node_ptr c) {
		if(c->left != NIL){
			leftOrRight(c->left);
		}
		_prior = _next;
		_next = c;
		_prior->next=_next;
		_next->prior=_prior;
		if(c->right != NIL){
			leftOrRight(c->right);
		}
	};

	void printElements(node_ptr c) {
		if(c->left != NIL){
			printElements(c->left);
		}
		cout << "key: " << c->first << ", value: " << c->second << endl;
		if(c->right != NIL){
			printElements(c->right);
		}
	};

	void rotateLeft(node_ptr x) {
		if (x-> right == NIL) // right subtree cant be left, so return to avoid a wrong tree-clean
			return;
		node_ptr x_r=x->right;
		x->right = x_r->left;
		if (x_r-> left != NIL) // avoid a destruct empty nodes: parent point to himself
			x_r->left->parent = x;
		x_r->parent = x->parent;
		if (x_r-> parent == header) {// root node
			root = x_r;
		} else if (x-> parent-> left == x) { // update parent node
			x->parent->left = x_r;
		}else if(x->parent->right == x){
			x->parent->right = x_r;
		}
		x_r->left = x;
		x->parent = x_r;
	};

	void rotateRight(node_ptr x) {
		if (x-> left == NIL) // Правое поддерево не может быть левым, чтобы избежать неправильной операции по очистке дерева
			return;
		node_ptr x_l=x->left;
		x->left = x_l->right;
		if (x_l-> right != NIL) // Избегайте разрушения характеристик пустых узлов: родительский узел указывает на себя
			x_l->right->parent = x;
		x_l->parent = x->parent;
		if (x_l-> parent == header) {// корневой узел
			root = x_l;
		} else if (x-> parent-> right == x) {// Обновляем родительский узел
			x->parent->right = x_l;
		}else if(x->parent->left == x){
			x->parent->left = x_l;
		}
		x_l->right = x;
		x->parent = x_l;
	};

	void insertFix(node_ptr x) {
		while (x-> parent-> color == RED) {// Сначала убедитесь, что нет непрерывного красного узла
			if(x->parent == x->parent->parent->left){
				if(x->parent->parent->right->color == RED){//case 1: son --red,dad&dad's brother --red
					x->parent->parent->right->color = x->parent->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				}
				else{
					if(x == x->parent->right){//case 2:inner side,son --red,dad --red
						x = x->parent;
						rotateLeft(x);
					}
					x->parent->parent->color = RED;//case 3:outer side,son --red,dad --red
					x->parent->color = BLACK;
					x = x->parent;
					rotateRight(x->parent->parent);
				}
			}
			else{
				if(x->parent->parent->left->color == RED){//case 1: son --red,dad&dad's brother --red
					x->parent->parent->left->color = x->parent->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				}
				else{
					if(x == x->parent->left){//case 2:inner side,son --red,dad --red
						x = x->parent;
						rotateLeft(x);
					}
					x->parent->parent->color = RED;//case 3:outer side,son --red,dad --red
					x->parent->color = BLACK;
					x = x->parent;
					rotateRight(x->parent->parent);
				}
			}
		}
		root->color=BLACK;
	};

	void deleteFix(node_ptr x) {
		node_ptr z = NIL;
		while(x!=root&&x->color==BLACK){
			if(x == x->parent->left){
				z=x->parent->right;
				if(z->color == RED){//case 1:x's brather --red
					z->color=BLACK;
					x->parent->color = RED;
					rotateLeft(x-> parent); // Используем красный, чтобы черный оставался последовательным
					z = x->parent->right;//update x's brother
				}//case 2:x&x's brother sons color same
				if(z->left->color==BLACK && z->right->color==BLACK){
					z-> color = RED; // Сохраняем тот же цвет, что и x, потому что это родственный узел
					x = x-> parent; // Регулировка вверх
				}
				else {
					if(z->right->color==BLACK) {//z:x's brother
						z->color = RED;//case 3:z left--red,right--black
						z->left->color = BLACK;
						rotateRight(z);
						z = x->parent->right;
					}
					//case 4:adjust x and z
					// Дерево уравновешивает высоту, сохраняя цвет исходной позиции родительского узла
					z->color = x->parent->color;
					x->parent->color = BLACK;
					z->right->color = BLACK;
					rotateLeft(x->parent);
					break;
				}
			}
			else {
				z=x->parent->left;
				if(z->color == RED){//case 1:x's brather --red
					z->color=BLACK;
					x->parent->color = RED;
					this-> rotateRight(x-> parent); // Используйте красный, чтобы сохранить однородность черного
					z = x->parent->left;//update x's brother
				}//case 2:x&x's brother sons color same
				if(z->right->color==BLACK && z->left->color==BLACK){
					z-> color = RED; // Сохраняем тот же цвет, что и x, потому что это родственный узел
					x = x-> parent; // Регулировка вверх
				}
				else {
					if(z->left->color==BLACK) {//z:x's brother
						z->color = RED;//case 3:z left--red,right--black
						z->right->color = BLACK;
						rotateLeft(z);
						z = x->parent->left;
					}
					//case 4:adjust x and z
					// Дерево уравновешивает высоту, сохраняя цвет исходной позиции родительского узла
					z->color = x->parent->color;
					x->parent->color = BLACK;
					z->left->color = BLACK;
					rotateRight(x->parent);
					break;
				}
			}
		}
		root-> color = BLACK; // Сохраняем корень черным
	};

	void Transplante(node_ptr old, node_ptr neo) {
		if(old->parent == header){
			header->right = neo;
			root = neo;
		}else if(old->parent->left == old){
			old->parent->left = neo;
		}else if(old->parent->right == old){
			old->parent->right = neo;
		}
		neo->parent = old->parent;
	};

	node_ptr BranchMin(node_ptr x) {
		if(x == NIL)
			return x;
		node_ptr temp = x;
		while (temp->left != NIL) {
			temp=temp->left;
		}
		return temp;
	};
};
