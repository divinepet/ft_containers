#pragma once

#define compEQ(a,b) (a == b)
#include <vector>

typedef enum { BLACK, RED } nodeColor;

template <class T, class V, class Compare>
class Tree;

template <class T, class V, class Compare>
struct Node_ {
protected:
	friend class Tree<T, V, Compare>;
	friend class ft::node_iterator<Node_<T, V, Compare>* >;
	bool color;
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
	bool NIL;
public:
	T first;
	V second;
};

template <class T, class V, class Compare = std::less<T> >
class Tree {
public:
	Node_<T, V, Compare> sentinel;
	Node_<T, V, Compare> *root;
	Node_<T, V, Compare> *begin;
	Node_<T, V, Compare> *last;
	Compare comp;
	Tree() {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.NIL = true;
		last = &sentinel;
		begin = &sentinel;
		root = &sentinel;
	}

	~Tree() {
		deleteAll(root);
//		deleteAll(begin);
//		deleteAll(last);
	};

	Tree(Tree<T, V, Compare> &other) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.NIL = true;
		last = &sentinel;
		begin = &sentinel;
		root = &sentinel;
//		deleteAll(root);
//		last = other.last;
//		begin = other.begin;
//		root = other.root;
//		cout << other.root->first << endl;
		fillTree(other.root);
	}

	void fillTree(Node_<T, V, Compare> *t) {
		if (!t->left->NIL)
			fillTree(t->left);
		if (!t->NIL) insertNode(t->first, t->second);
		if (!t->right->NIL)
			fillTree(t->right);
	}

	void deleteAll(Node_<T, V, Compare> *tmp) {
		if (tmp->NIL) {
			return;
		}

		if (!tmp->left->NIL) deleteAll(tmp->left);
		if (!tmp->right->NIL) deleteAll(tmp->right);

		deleteNode(tmp);
	}

	Tree& operator=(const Tree<T, V, Compare>& other) {
		cout << "Tree operator==" << endl;
		if (this == &other)
			return *this;
		deleteAll(root);
		deleteAll(last);
		deleteAll(begin);
		root = other.root;
		begin = other.begin;
		last = other.last;
		sentinel = other.sentinel;
		return *this;
	};

	void rotateLeft(Node_<T, V, Compare> *x) {
		Node_<T, V, Compare> *y = x->right;
//		Node_<T, V, Compare> *copy_x_right = y;
		// todo костыль ебаный
//		saveArrayGlobal2<T, V, Compare> = y;
		x->right = y->left;

		if (!y->left->NIL)  y->left->parent = x;
		if (!y->NIL) {
			y->parent = x->parent;
		}   //****
		if (x->parent) {
			if (x == x->parent->left) {
				x->parent->left = y;
			}
			else {
				x->parent->right = y;
			}
		} else {
			root = y;
		}
		y->left = x;
		if (!x->NIL) x->parent = y;
//		deleteAll(copy_x_right);
	}

	void rotateRight(Node_<T, V, Compare> *x) {
		Node_<T, V, Compare> *y = x->left;

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

	void insertFixup(Node_<T, V, Compare> *x) {
		while (x != root && x->parent->color == RED) {
			if (x->parent == x->parent->parent->left) {
				Node_<T, V, Compare> *y = x->parent->parent->right;
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
				Node_<T, V, Compare> *y = x->parent->parent->left;
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

	Node_<T, V, Compare> *insertNode(T first, V second) {
		Node_<T, V, Compare> *current, *parent, *x;

		current = root;
		parent = 0;
		while (!current->NIL) {
			if (compEQ(first, current->first)) return (current);
			parent = current;
			current = comp(first, current->first) ?
					current->left : current->right;
		}

		x = new Node_<T, V, Compare>();
		x->first = first;
		x->second = second;
		x->parent = parent;
		x->left = &sentinel;
		x->right = &sentinel;
		x->left->parent = x;
		x->right->parent = x;
		x->color = RED;

		if (parent) {
			if (comp(first, parent->first))
				parent->left = x;
			else
				parent->right = x;
		} else {
			root = x;
		}

		if (last->NIL || comp(last->first, x->first))
			last = x;
		if (begin->NIL || !comp(begin->first,x->first)) {
			begin = x;
		}

		insertFixup(x);
		return(x);
	}

	void deleteFixup(Node_<T, V, Compare> *x) {
		while (x != root && x->color == BLACK) {
			if (x == x->parent->left) {
				Node_<T, V, Compare> *w = x->parent->right;
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
				Node_<T, V, Compare> *w = x->parent->left;
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

	void deleteNode(Node_<T, V, Compare> *z) {
		Node_<T, V, Compare> *x, *y;
		if (!z || z->NIL) return;

		if (z == begin) {
			if (comp(1, 2))
				begin = increment(begin);
			else
				begin = decrement(begin);
		}
		if (z == last) {
			if (comp(1, 2))
				last = decrement(last);
			else
				last = increment(last);
		}

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

	Node_<T, V, Compare>* findNode(T first) {
		Node_<T, V, Compare> *current = root;

		while (!current->NIL) {
			if(compEQ(first, current->first))
				return (current);
			else
				current = comp (first, current->first) ? current->left : current->right;
		}
		return get_end();
	}

	Node_<T, V, Compare>* get_begin() { return begin; }

	Node_<T, V, Compare>* get_end() { return last->right; }

	Node_<T, V, Compare>* increment(Node_<T, V, Compare> *t) {
		if (t == last)
			return t->right;
		if (!t->right->NIL) {
			t = t->right;
			while (!t->left->NIL)
				t = t->left;
			return t;
		}
		T value = t->first;
		while (value >= t->first) {
			t = t->parent;
		}
		return t;
	}

	Node_<T, V, Compare>* decrement(Node_<T, V, Compare> *t) {
		if (t->NIL) return t->parent;
		// todo check this case: reverse compare can break it
//		if (t == begin) { return t->left - 1; }
		if (!t->left->NIL) {
			t = t->left;
			while (!t->right->NIL)
				t = t->right;
			return t;
		}
		T value = t->first;
		while (value <= t->first ) {
			if (!t->parent) return t->right;
			t = t->parent;
		}
		return t;
	}
};