#pragma once

#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

typedef enum { BLACK, RED } nodeColor;


template <class T>
class Tree {
public:
	struct Node_ {
		struct Node_ *left;
		struct Node_ *right;
		struct Node_ *parent;
		nodeColor color;
		T data;
	};
	Node_ sentinel;
	Node_ *root;
	Node_ *begin;
	Node_ *iterator;
	Tree() {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.data = 0;
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

		/****************************
		 *  rotate node x to right  *
		 ****************************/

		Node_ *y = x->left;

		/* establish x->left link */
		x->left = y->right;
		if (y->right != &sentinel) y->right->parent = x;

		/* establish y->parent link */
		if (y != &sentinel) y->parent = x->parent;
		if (x->parent) {
			if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		} else {
			root = y;
		}

		/* link x and y */
		y->right = x;
		if (x != &sentinel) x->parent = y;
	}

	void insertFixup(Node_ *x) {

		/*************************************
		 *  maintain Red-Black tree balance  *
		 *  after inserting node x           *
		 *************************************/

		/* check Red-Black properties */
		while (x != root && x->parent->color == RED) {
			/* we have a violation */
			if (x->parent == x->parent->parent->left) {
				Node_ *y = x->parent->parent->right;
				if (y->color == RED) {

					/* uncle is RED */
					x->parent->color = BLACK;
					y->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				} else {

					/* uncle is BLACK */
					if (x == x->parent->right) {
						/* make x a left child */
						x = x->parent;
						rotateLeft(x);
					}

					/* recolor and rotate */
					x->parent->color = BLACK;
					x->parent->parent->color = RED;
					rotateRight(x->parent->parent);
				}
			} else {

				/* mirror image of above code */
				Node_ *y = x->parent->parent->left;
				if (y->color == RED) {

					/* uncle is RED */
					x->parent->color = BLACK;
					y->color = BLACK;
					x->parent->parent->color = RED;
					x = x->parent->parent;
				} else {

					/* uncle is BLACK */
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

	Node_ *insertNode(T data) {
		Node_ *current, *parent, *x;

		/***********************************************
		 *  allocate node for data and insert in tree  *
		 ***********************************************/

		/* find where node belongs */
		current = root;
		parent = 0;
		while (current != &sentinel) {
			if (compEQ(data, current->data)) return (current);
			parent = current;
			current = compLT(data, current->data) ?
					current->left : current->right;
		}

		/* setup new node */
		x = new Node_();
		x->data = data;
		x->parent = parent;
		x->left = &sentinel;
		x->right = &sentinel;
		x->color = RED;

		/* insert node in tree */
		if(parent) {
			if(compLT(data, parent->data))
				parent->left = x;
			else
				parent->right = x;
		} else {
			root = x;
		}

		insertFixup(x);
		return(x);
	}

	void deleteFixup(Node_ *x) {

		/*************************************
		 *  maintain Red-Black tree balance  *
		 *  after deleting node x            *
		 *************************************/

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

		if (z->left == &sentinel || z->right == &sentinel) {
			/* y has a &sentinel node as a child */
			y = z;
		} else {
			/* find tree successor with a &sentinel node as a child */
			y = z->right;
			while (y->left != &sentinel) y = y->left;
		}

		/* x is y's only child */
		if (y->left != &sentinel)
			x = y->left;
		else
			x = y->right;

		/* remove y from the parent chain */
		x->parent = y->parent;
		if (y->parent)
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
			else
				root = x;

			if (y != z) z->data = y->data;


			if (y->color == BLACK)
				deleteFixup (x);

			free (y);
	}

	Node_ *findNode(T data) {
		Node_ *current = root;
		while (current != &sentinel)
			if(compEQ(data, current->data))
				return (current);
			else
				current = compLT (data, current->data) ?
						current->left : current->right;
			return(0);
	}

	void printElem(Node_ *t) {
		if (t->left != &sentinel)
			printElem(t->left);
		cout << t->data << endl;
		if (t->right != &sentinel)
			printElem(t->right);
	}

	Node_* get_begin() {
		Node_* tmp = root;
		return tmp;
	}

	Node_* increment(Node_ *t) {
		if (t->right != &sentinel) {
			t = t->right;
			while (t->left != &sentinel)
				t = t->left;
			return t;
		}
		T value = t->data;
		while (value >= t->data) {
			t = t->parent;
		}
		return t;
	}

	Node_* decrement(Node_ *t) {
		if (t->left != &sentinel) {
			t = t->left;
			while (t->right != &sentinel)
				t = t->right;
			return t;
		}
		T value = t->data;
		while (value <= t->data) {
			t = t->parent;
		}
		return t;
	}
};
