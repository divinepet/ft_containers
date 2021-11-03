#pragma once

template <class value_type>
struct Node_ {
public:
	Node_() : color(0), begin(NULL), left(this), right(this), parent(0), NIL(1), pair(new value_type()) {}
	Node_(const value_type& p) : color(0), begin(NULL), left(this), right(this), parent(0), NIL(0), pair(new value_type(p)) {}
	~Node_() { delete pair; }
	bool color;
	struct Node_ *begin;
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
	bool NIL;
	value_type *pair;
};

template <class value_type>
class Tree {
public:
	Node_<value_type> sentinel;
	Node_<value_type> *root;
	size_t m_size;
	Tree() : m_size(0) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.begin = &sentinel;
		sentinel.parent = 0;
		sentinel.color = 0;
		sentinel.NIL = true;
		root = &sentinel;
	}

	Tree(Tree<value_type> &other) : m_size(0) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.begin = &sentinel;
		sentinel.parent = 0;
		sentinel.color = 0;
		sentinel.NIL = (&other == &other);
		root = &sentinel;
	}

	Tree& operator=(const Tree<value_type>& other) {
		if (this == &other)
			return *this;
		root = other.root;
		sentinel = other.sentinel;
		m_size = other.m_size;
		return *this;
	};

	void rotateLeft(Node_<value_type> *x) {
		Node_<value_type> *y = x->right;

		x->right = y->left;
		if (!y->left->NIL)  y->left->parent = x;
		if (!y->NIL) y->parent = x->parent;
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
	}

	void rotateRight(Node_<value_type> *x) {
		Node_<value_type> *y = x->left;

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

	void insertFixup(Node_<value_type> *x) {
		while (x != root && x->parent->color == 1) {
			if (x->parent == x->parent->parent->left) {
				Node_<value_type> *y = x->parent->parent->right;
				if (y->color == 1) {
					x->parent->color = 0;
					y->color = 0;
					x->parent->parent->color = 1;
					x = x->parent->parent;
				} else {
					if (x == x->parent->right) {
						x = x->parent;
						rotateLeft(x);
					}
					x->parent->color = 0;
					x->parent->parent->color = 1;
					rotateRight(x->parent->parent);
				}
			} else {
				Node_<value_type> *y = x->parent->parent->left;
				if (y->color == 1) {
					x->parent->color = 0;
					y->color = 0;
					x->parent->parent->color = 1;
					x = x->parent->parent;
				} else {
					if (x == x->parent->left) {
						x = x->parent;
						rotateRight(x);
					}
					x->parent->color = 0;
					x->parent->parent->color = 1;
					rotateLeft(x->parent->parent);
				}
			}
		}
		root->color = 0;
	}

	void deleteFixup(Node_<value_type> *x) {
		while (x != root && x->color == 0) {
			if (x == x->parent->left) {
				Node_<value_type> *w = x->parent->right;
				if (w->color == 1) {
					w->color = 0;
					x->parent->color = 1;
					rotateLeft (x->parent);
					w = x->parent->right;
				}
				if (w->left->color == 0 && w->right->color == 0) {
					w->color = 1;
					x = x->parent;
				} else {
					if (w->right->color == 0) {
						w->left->color = 0;
						w->color = 1;
						rotateRight (w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 0;
					w->right->color = 0;
					rotateLeft (x->parent);
					x = root;
				}
			} else {
				Node_<value_type> *w = x->parent->left;
				if (w->color == 1) {
					w->color = 0;
					x->parent->color = 1;
					rotateRight (x->parent);
					w = x->parent->left;
				}
				if (w->right->color == 0 && w->left->color == 0) {
					w->color = 1;
					x = x->parent;
				} else {
					if (w->left->color == 0) {
						w->right->color = 0;
						w->color = 1;
						rotateLeft (w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 0;
					w->left->color = 0;
					rotateRight (x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}

	int deleteNode(Node_<value_type> *z) {
		Node_<value_type> *x, *y;

		if (!z || z->NIL) return 0;

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
			delete z->pair;
			value_type *p = new value_type(*y->pair);
			z->pair = p;
		}

		if (y->color == 0)
			deleteFixup (x);
		sentinel.parent = getLast();
		sentinel.begin = getBegin();
		m_size--;
		delete y;
		return 1;
	}

	Node_<value_type>* getBegin() {
		Node_<value_type>* tmp = root;
		while (!tmp->left->NIL) {
			tmp = tmp->left;
		}
		return tmp;
	}

	Node_<value_type>* getLast() {
		Node_<value_type>* tmp = root;
		while (!tmp->right->NIL) {
			tmp = tmp->right;
		}
		return tmp;
	}

	Node_<value_type>* getEnd() {
		Node_<value_type>* tmp = root;
		while (!tmp->right->NIL) {
			tmp = tmp->right;
		}
		return tmp->right;
	}
};