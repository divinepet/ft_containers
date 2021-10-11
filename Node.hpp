#include <iostream>
#pragma once
using std::cout;
using std::endl;

template <class T, class V>
class Node;
enum Color { RED = 0, BLACK = 1};

template <class T, class V>
class Node_Base {
	typedef Node_Base<T, V> *node_ptr;
	friend class Node<T, V>;
public:
	typedef Node_Base<T, V> *node_iterator;
	node_ptr left, right, parent;
	node_ptr prior, next;
	Color color;
	T val;
	V val2;
	
	explicit Node_Base(T value, V value2) : left(this), right(this), parent(this), val(value), val2(value2), color(RED) {}
	Node_Base(T value, V value2, node_ptr l, node_ptr r) : val(value), val2(value2), left(l), right(r), parent(this), color(RED) {}
};

template <class T, class V>
class Node {
	friend class Node_Base<T, V>;
	typedef Node_Base<T, V>* node_ptr;
	node_ptr header;
	node_ptr root;
	node_ptr NIL;
	node_ptr _prior;
	node_ptr _next;
public:
	typedef Node_Base<T, V>* node_iterator;

	Node() {
		header = new Node_Base<T, V>(0, 0);
		NIL = new Node_Base<T, V>(-1, -1);
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
	T getMax() 				{ return header->prior->val; };
	T getMin() 				{ return header->next->val; };
	node_iterator begin() 	{ return header->next; }
	node_iterator end() 	{ return header; }

	void insertNode(T x, V v) {
		node_ptr n = new Node_Base<T, V>(x, v, NIL, NIL);
		insertNode(n);
	};

	void insertNode(node_ptr x) {
		node_ptr first, second;
		first = second = root;
		if(root == NIL) {
			root = x;
			header->right = x;
			x->parent = header;
			x->color = BLACK;
			return;
		}
		while (first != NIL) {
			second = first;
			if (first->val > x->val)
				first = first->left;
			else if (first->val < x->val)
				first = first->right;
			else
				return ;
		}
		x->parent = second;
		if(second->val > x->val){
			second->left = x;
		}else{
			second->right = x;
		}
		insertFix(x);
		leftOrRight();
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
			if (a->parent == x) { //case 2: replace node is son of x
				b->parent = a; // case NIL
			} else {
				Transplante(a, a->right);//a break away from there
				a->right = x->right;
				a->right->parent = a;
			}
			Transplante (x, a); // Заменить ветвь старого узла новой ветвью узла
			a->left = x->left;
			a->left->parent = a;
			a->color = x->color;
		}
		delete x;
		if (a_color == BLACK) // case 3: Нарушение правил красного и черного, количество черных узлов на пути разное
			deleteFix(b);
		leftOrRight();
		return true;
	};

	node_ptr searchNode(T x) {
		node_ptr temp = root;
		while(temp != NIL) {
			if (temp->val > x)
				temp = temp->left;
			else if (temp->val < x)
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

	void Iterator_visit(node_iterator begin, node_iterator end) {
		node_iterator temp = begin;
		while (temp != end) {
			cout << "key: " << temp->val << ", value: " << temp->val2 << endl;
			temp = temp->next;
		}
	}

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
		cout << "key: " << c->val << ", value: " << c->val2 << endl;
		if(c->right != NIL){
			printElements(c->right);
		}
	};

	void rotateLeft(node_ptr x) {
		if (x-> right == NIL) // Правое поддерево не может быть левым, чтобы избежать неправильной операции по очистке дерева
			return;
		node_ptr x_r=x->right;
		x->right = x_r->left;
		if (x_r-> left != NIL) // Избегайте разрушения характеристик пустых узлов: родительский узел указывает на себя
			x_r->left->parent = x;
		x_r->parent = x->parent;
		if (x_r-> parent == header) {// корневой узел
			root = x_r;
		} else if (x-> parent-> left == x) {// Обновляем родительский узел
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
