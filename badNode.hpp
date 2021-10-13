#pragma once

typedef int T;                  /* type of item to be stored */
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

/* Red-Black tree description */
typedef enum { BLACK, RED } nodeColor;

typedef struct Node_ {
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
	nodeColor color;
	T data;
} Node;

#define NIL &sentinel           /* all leafs are sentinels */
Node sentinel = { NIL, NIL, 0, BLACK, 0};

Node *root = NIL;               /* root of Red-Black tree */

void rotateLeft(Node *x) {

	/**************************
	 *  rotate node x to left *
	 **************************/

	Node *y = x->right;

	/* establish x->right link */
	x->right = y->left;
	if (y->left != NIL) y->left->parent = x;

	/* establish y->parent link */
	if (y != NIL) y->parent = x->parent;
	if (x->parent) {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	} else {
		root = y;
	}

	/* link x and y */
	y->left = x;
	if (x != NIL) x->parent = y;
}

void rotateRight(Node *x) {

	/****************************
	 *  rotate node x to right  *
	 ****************************/

	Node *y = x->left;

	/* establish x->left link */
	x->left = y->right;
	if (y->right != NIL) y->right->parent = x;

	/* establish y->parent link */
	if (y != NIL) y->parent = x->parent;
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
	if (x != NIL) x->parent = y;
}

void insertFixup(Node *x) {

	/*************************************
	 *  maintain Red-Black tree balance  *
	 *  after inserting node x           *
	 *************************************/

	/* check Red-Black properties */
	while (x != root && x->parent->color == RED) {
		/* we have a violation */
		if (x->parent == x->parent->parent->left) {
			Node *y = x->parent->parent->right;
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
			Node *y = x->parent->parent->left;
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

Node *insertNode(T data) {
	Node *current, *parent, *x;

	/***********************************************
	 *  allocate node for data and insert in tree  *
	 ***********************************************/

	/* find where node belongs */
	current = root;
	parent = 0;
	while (current != NIL) {
		if (compEQ(data, current->data)) return (current);
		parent = current;
		current = compLT(data, current->data) ?
				current->left : current->right;
	}

	/* setup new node */
	x = new Node();
	x->data = data;
	x->parent = parent;
	x->left = NIL;
	x->right = NIL;
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

void deleteFixup(Node *x) {

	/*************************************
	 *  maintain Red-Black tree balance  *
	 *  after deleting node x            *
	 *************************************/

	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			Node *w = x->parent->right;
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
			Node *w = x->parent->left;
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

void deleteNode(Node *z) {
	Node *x, *y;
	if (!z || z == NIL) return;

	if (z->left == NIL || z->right == NIL) {
		/* y has a NIL node as a child */
		y = z;
	} else {
		/* find tree successor with a NIL node as a child */
		y = z->right;
		while (y->left != NIL) y = y->left;
	}

	/* x is y's only child */
	if (y->left != NIL)
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

Node *findNode(T data) {
	Node *current = root;
	while(current != NIL)
		if(compEQ(data, current->data))
			return (current);
		else
			current = compLT (data, current->data) ?
					current->left : current->right;
		return(0);
}

void printElem(Node *t) {
	if (t->left != NIL)
		printElem(t->left);
	cout << t->data << endl;
	if (t->right != NIL)
		printElem(t->right);
}

Node* begin;

Node* get_begin(Node *t) {
	if (t->left != NIL)
		get_begin(t->left);
	else
		begin = t;
	return NIL;
}

Node* increment(Node *t) {
	if (t->right != NIL) {
		t = t->right;
		while (t->left != NIL)
			t = t->left;
		return t;
	}
	T value = t->data;
	t = t->parent;
	while (value > t->data) {
		t = t->parent;
	}
	return t;
}