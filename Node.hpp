#pragma once

typedef enum { BLACK, RED } nodeColor;

template <class T, class V>
class Tree;

template <class T, class V>
struct Node_ {
public:
	friend class Tree<T, V>;
	friend class ft::node_iterator<Node_<T, V>*>;
	bool color;
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
	bool NIL;
//	Node_() {}
//	Node_<T, V>(const Node_<T, V> &other) {
////		cout << "wow its copy" << endl;
//		left = other.left;
//		right = other.right;
//		parent = other.parent;
//		NIL = other.NIL;
//		color = other.color;
//		first = other.first;
//		second = other.second;
//	}
//	Node_& operator=(const Node_& other) {
//		cout << "wow its assign" << endl;
//		if (this == &other)
//			return *this;
//		return *this;
//	}
public:
	T first;
	V second;
};

template <class T, class V>
class Tree : public Node_<T, V> {
public:
	Node_<T, V> sentinel;
	Node_<T, V> *root;
	size_t		m_size;
	Tree() : m_size(0) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.NIL = true;
		root = &sentinel;
	}

	~Tree() { deleteAll(root); };

	Tree(Tree<T, V> &other) : m_size(0) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.NIL = true;
		root = &sentinel;
	}

	template <class Compare>
	void fillTree(Node_<T, V> *t, Compare comp) {
		if (!t->left->NIL)
			fillTree(t->left, comp);
		if (!t->NIL) insertNode(t->first, t->second, comp);
		if (!t->right->NIL)
			fillTree(t->right, comp);
	}

	void deleteAll(Node_<T, V> *tmp) {
		if (tmp->NIL) return;
		if (!tmp->left->NIL) deleteAll(tmp->left);
		if (!tmp->right->NIL) deleteAll(tmp->right);
		delete tmp;
	}

	Tree& operator=(const Tree<T, V>& other) {
		if (this == &other)
			return *this;
		deleteAll(root);
		root = other.root;
		sentinel = other.sentinel;
		m_size = other.m_size;
		return *this;
	};

	void rotateLeft(Node_<T, V> *x) {
		Node_<T, V> *y = x->right;

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

//	template <class Compare>
//	Node_<T, V> *insertWithHint(Node_<T, V> *hint, T first, V second, Compare comp) {
//		Node_<T, V> *current_hint = hint;
//		Node_<T, V> *tmp = hint;
//
//		while (hint->parent) {
//			hint = hint->parent;
//			if (comp(first, hint->first)) {
//				if (hint->left == current_hint) {
//					continue;
//				} else
//					return;
//			} else {
//				if (hint->right == current_hint) {
//					continue; // здесь мы понимаем, что подсказка правильная
//				} else {
//					return;
//				}
//			}
//
//		}
//	}


	template <class Compare>
	ft::pair<Node_<T, V> *, bool> insertNode(T first, V second, Compare comp) {
		Node_<T, V> *current, *parent, *x;

		current = root;
		parent = 0;
		while (!current->NIL) {
			if (first == current->first) return ft::make_pair(current, false);
			parent = current;
			current = comp(first, current->first) ?
					current->left : current->right;
		}

		x = new Node_<T, V>();
		x->first = first;
		x->second = second;
		x->parent = parent;
		x->left = &sentinel;
		x->right = &sentinel;
		x->color = RED;

		if (parent) {
			if (comp(first, parent->first))
				parent->left = x;
			else
				parent->right = x;
		} else {
			root = x;
		}

		insertFixup(x);

		if (x == get_last()) { sentinel.parent = x; }
		m_size++;
		return ft::make_pair(x, true);
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

	int deleteNode(Node_<T, V> *z) {
		Node_<T, V> *x, *y;
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
			z->first = y->first;
			z->second = y->second;
		}

		if (y->color == BLACK)
			deleteFixup (x);
		sentinel.parent = get_last();
		m_size--;
		// todo delete free
		free (y);
//		delete y;
		return 1;
	}

	template <class Compare>
	Node_<T, V>* findNode(T first, Compare comp) {
		Node_<T, V> *current = root;

		while (!current->NIL) {
			if(first == current->first)
				return (current);
			else
				current = comp (first, current->first) ? current->left : current->right;
		}
		return get_end();
	}

	Node_<T, V>* get_begin() {
		Node_<T, V>* tmp = root;
		while (!tmp->left->NIL) {
			tmp = tmp->left;
		}
		return tmp;
	}

	Node_<T, V>* get_last() {
		Node_<T, V>* tmp = root;
		while (!tmp->right->NIL) {
			tmp = tmp->right;
		}
		return tmp;
	}

	Node_<T, V>* get_end() {
		Node_<T, V>* tmp = root;
		while (!tmp->right->NIL) {
			tmp = tmp->right;
		}
		return tmp->right;
	}

//	Node_<T, V>* increment(Node_<T, V> *t) {
//		if (t == get_end()->parent)
//			return t->right;
//		if (!t->right->NIL) {
//			t = t->right;
//			while (!t->left->NIL)
//				t = t->left;
//			return t;
//		}
//		T value = t->first;
//		while (value >= t->first) {
//			t = t->parent;
//		}
//		return t;
//	}
//
//	Node_<T, V>* decrement(Node_<T, V> *t) {
//		if (t->NIL) return t->parent;
//		if (!t->left->NIL) {
//			t = t->left;
//			while (!t->right->NIL)
//				t = t->right;
//			return t;
//		}
//		T value = t->first;
//		while (value <= t->first ) {
//			if (!t->parent) { return t->right; }
//			t = t->parent;
//		}
//		return t;
//	}
};