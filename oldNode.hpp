#pragma once

#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

typedef enum { BLACK, RED } nodeColor;


template <class T, class V>
class Tree {
public:
	struct Node_ {
	private:
		struct Node_ *left;
		struct Node_ *right;
		struct Node_ *parent;
		bool color;
		friend class Tree<T, V>;
	public:
		T first;
		V second;
	};
	Node_ sentinel;
	Node_ *root;
	Node_ *iterator;
	Node_ *begin;
	Node_ *last;
	Tree() {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.first = T();
		sentinel.second = V();
		last = &sentinel;
		begin = &sentinel;
		root = &sentinel;
	}

	void rotateLeft(Node_ *x) {
		Node_ *y = x->right;
		x->right = y->left;
		if (y->left != &sentinel) y->left->parent = x;
		if (y != &sentinel) y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
		} else {
			root = y;
		}
		y->left = x;
		if (x != &sentinel) x->parent = y;
	}

	void rotateRight(Node_ *x) {
		Node_ *y = x->left;

		x->left = y->right;
		if (y->right != &sentinel) y->right->parent = x;

		if (y != &sentinel) y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		} else {
			root = y;
		}

		y->right = x;
		if (x != &sentinel) x->parent = y;
	}

	void insertFixup(Node_ *x) {
		while (x != root && x->parent->color == RED) {
			if (x->parent == x->parent->parent->left) {
				Node_ *y = x->parent->parent->right;
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
				Node_ *y = x->parent->parent->left;
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

	Node_ *insertNode(T first, V second) {
		Node_ *current, *parent, *x;

		current = root;
		parent = 0;
		while (current != &sentinel) {
			if (compEQ(first, current->first)) return (current);
			parent = current;
			current = compLT(first, current->first) ?
					current->left : current->right;
		}

		x = new Node_();
		x->first = first;
		x->second = second;
		x->parent = parent;
		x->left = &sentinel;
		x->right = &sentinel;
		x->color = RED;

		if (parent) {
			if(compLT(first, parent->first))
				parent->left = x;
			else
				parent->right = x;
		} else {
			root = x;
		}

		if (last->first < x->first) last = x;
		if (begin->first > x->first) begin = x;
		insertFixup(x);
		return(x);
	}

	void deleteFixup(Node_ *x) {
		while (x != root && x->color == BLACK) {
			if (x == x->parent->left) {
				Node_ *w = x->parent->right;
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
				Node_ *w = x->parent->left;
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

	void deleteNode(Node_ *z) {
		Node_ *x, *y;
		if (!z || z == &sentinel) return;

		if (z == last) last = decrement(last);
		if (z == begin) begin = increment(begin);

		if (z->left == &sentinel || z->right == &sentinel) {
			y = z;
		} else {
			y = z->right;
			while (y->left != &sentinel)
				y = y->left;
		}

		if (y->left != &sentinel)
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

	Node_ *findNode(T first) {
		Node_ *current = root;

		while (current != &sentinel) {
			if(compEQ(first, current->first))
				return (current);
			else
				current = compLT (first, current->first) ? current->left : current->right;
		}
		return &sentinel;
	}

	void printElem(Node_ *t) {
		if (t->left != &sentinel)
			printElem(t->left);
		cout << t->first << endl;
		if (t->right != &sentinel)
			printElem(t->right);
	}

	Node_* get_begin() { return begin; }

	Node_* get_end() { return last->right + 1; }

	Node_* increment(Node_ *t) {
		if (t == last)
			return last->right + 1;
		if (t->right != &sentinel) {
			t = t->right;
			while (t->left != &sentinel)
				t = t->left;
			return t;
		}
		T value = t->first;
		while (value >= t->first) {
			t = t->parent;
			if (t == NULL) break;
		}
		return t;
	}

	Node_* decrement(Node_ *t) {
		if (t == begin) return begin->left - 1;
		if (t->left != &sentinel) {
			t = t->left;
			while (t->right != &sentinel)
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
