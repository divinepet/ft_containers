#pragma once

#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

typedef enum { BLACK, RED } nodeColor;

template <class T, class V>
class Tree;

template <class T, class V>
struct Node_ {
protected:
	friend class Tree<T, V>;
	friend class ft::node_iterator<Node_<T, V>* >;
	bool color;
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
	bool NIL;
public:
	T first;
	V second;
};


template <class T, class V>
class Tree {
public:
	Node_<T, V> sentinel;
	Node_<T, V> *root;
	Node_<T, V> *it;
	Node_<T, V> *begin;
	Node_<T, V> *last;
	Tree() {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
//		sentinel.first = T();
//		sentinel.second = V();
		sentinel.NIL = true;
		last = &sentinel;
		begin = &sentinel;
		root = &sentinel;
	}

//	~Tree() {};

	Tree(const Tree &other) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.NIL = true;
//		sentinel.first = T();
//		sentinel.second = V();
		last = other.last;
		begin = other.begin;
		root = other.root;
		fillTree(other.root);
	}

	void fillTree(Node_<T, V> *t) {
		if (!t->left->NIL)
			fillTree(t->left);
		if (!t->NIL) insertNode(t->first, t->second);
		if (!t->right->NIL)
			fillTree(t->right);
	}

	Tree& operator=(const Tree& other) {
//		cout << "Tree operator==" << endl;
		if (this == &other)
			return *this;
		root = other.root;
		begin = other.begin;
		last = other.last;
		sentinel = other.sentinel;
		it = other.it;
		return *this;
	};

	void rotateLeft(Node_<T, V> *x) {
		Node_<T, V> *y = x->right;
		x->right = y->left;
		if (!y->left->NIL) y->left->parent = x;
		if (!y->NIL) y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
		} else {
			root = y;
		}
		y->left = x;
		if (!x->NIL) x->parent = y;
	}

	void rotateRight(Node_<T, V> *x) {
		Node_<T, V> *y = x->left;

		x->left = y->right;
		if (!y->right->NIL) y->right->parent = x;

		if (!y->NIL) y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		} else {
			root = y;
		}

		y->right = x;
		if (!x->NIL) x->parent = y;
	}

	void insertFixup(Node_<T, V> *x) {
		while (x != root && x->parent->color == RED) {
			if (x->parent == x->parent->parent->left) {
				Node_<T, V> *y = x->parent->parent->right;
				if (y->color == RED) {
					x->parent->color = BLACK;
					y->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				} else {
					if (x == x->parent->right) {
						x = x->parent;
						rotateLeft(x);
					}
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					rotateRight(x->parent->parent);
				}
			} else {
				Node_<T, V> *y = x->parent->parent->left;
				if (y->color == RED) {
					x->parent->color = BLACK;
					y->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				} else {
					if (x == x->parent->left) {
						x = x->parent;
						rotateRight(x);
					}
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					rotateLeft(x->parent->parent);
				}
			}
		}
		root->color = BLACK;
	}

	Node_<T, V> *insertNode(T first, V second) {
		Node_<T, V> *current, *parent, *x;

		current = root;
		parent = 0;
		while (!current->NIL) {
			if (compEQ(first, current->first)) return (current);
			parent = current;
			current = compLT(first, current->first) ?
					current->left : current->right;
		}

		x = new Node_<T, V>();
		x->first = first;
		x->second = second;
		x->parent = parent;
		x->left = &sentinel;
		x->right = &sentinel;
		x->left->parent = x;
		x->right->parent = x;
		x->color = RED;

		if (parent) {
			if(compLT(first, parent->first))
				parent->left = x;
			else
				parent->right = x;
		} else {
			root = x;
		}

		if (last->NIL || last->first < x->first)
			last = x;
		if (begin->NIL || begin->first > x->first) {
			begin = x;
		}

		insertFixup(x);
		return(x);
	}

	void deleteFixup(Node_<T, V> *x) {
		while (x != root && x->color == BLACK) {
			if (x == x->parent->left) {
				Node_<T, V> *w = x->parent->right;
				if (w->color == RED) {
					w->color = BLACK;
					x->parent->color = RED;
					rotateLeft (x->parent);
					w = x->parent->right;
				}
				if (w->left->color == BLACK && w->right->color == BLACK) {
					w->color = RED;
					x = x->parent;
				} else {
					if (w->right->color == BLACK) {
						w->left->color = BLACK;
						w->color = RED;
						rotateRight (w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					rotateLeft (x->parent);
					x = root;
				}
			} else {
				Node_<T, V> *w = x->parent->left;
				if (w->color == RED) {
					w->color = BLACK;
					x->parent->color = RED;
					rotateRight (x->parent);
					w = x->parent->left;
				}
				if (w->right->color == BLACK && w->left->color == BLACK) {
					w->color = RED;
					x = x->parent;
				} else {
					if (w->left->color == BLACK) {
						w->right->color = BLACK;
						w->color = RED;
						rotateLeft (w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					rotateRight (x->parent);
					x = root;
				}
			}
		}
		x->color = BLACK;
	}

	void deleteNode(Node_<T, V> *z) {
		Node_<T, V> *x, *y;
		if (!z || z->NIL) return;

		if (z == last) last = decrement(last);
		if (z == begin) begin = increment(begin);

		if (z->left->NIL || z->right->NIL) {
			y = z;
		} else {
			y = z->right;
			while (!y->left->NIL)
				y = y->left;
		}

		if (!y->left->NIL)
			x = y->left;
		else
			x = y->right;

		x->parent = y->parent;
		if (y->parent)
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		else
			root = x;
		if (y != z) {
			z->first = y->first;
			z->second = y->second;
		}

		if (y->color == BLACK)
			deleteFixup (x);
		free (y);
	}

	Node_<T, V>* findNode(T first) {
		Node_<T, V> *current = root;

		while (!current->NIL) {
			if(compEQ(first, current->first))
				return (current);
			else
				current = compLT (first, current->first) ? current->left : current->right;
		}
		return get_end();
	}

	Node_<T, V>* get_begin() { return begin; }

	Node_<T, V>* get_end() { return last->right; }

	Node_<T, V>* increment(Node_<T, V> *t) {
		if (t == last) { return t->right + 1; }
		if (!t->right->NIL) {
			t = t->right;
			while (!t->left->NIL)
				t = t->left;
			return t;
		}
		T value = t->first;
		while (value >= t->first) {
			t = t->parent;
			if (t->NIL) { break; }
		}
		return t;
	}

	Node_<T, V>* decrement(Node_<T, V> *t) {
		if (t == begin) { return t->left - 1; }
		if (!t->left->NIL) {
			t = t->left;
			while (!t->right->NIL)
				t = t->right;
			return t;
		}
		T value = t->first;
		while (value <= t->first ) {
			t = t->parent;
		}
		return t;
	}
};