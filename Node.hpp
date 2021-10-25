#pragma once

typedef enum { BLACK, RED } nodeColor;

template <class value_type>
struct Node_ {
public:
	bool color;
	struct Node_ *left;
	struct Node_ *right;
	struct Node_ *parent;
	struct Node_ *preBegin;
	bool NIL;
	value_type pair;
};

template <class value_type>
class Tree {
public:
	Node_<value_type> sentinel;
	Node_<value_type> *root;
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

	Tree(Tree<value_type> &other) : m_size(0) {
		sentinel.left = &sentinel;
		sentinel.right = &sentinel;
		sentinel.parent = 0;
		sentinel.color = BLACK;
		sentinel.NIL = true;
		root = &sentinel;
	}

	template <class Compare>
	void fillTree(Node_<value_type> *t, Compare comp) {
		if (!t->left->NIL)
			fillTree(t->left, comp);
		if (!t->NIL) insertNode(t->pair, comp);
		if (!t->right->NIL)
			fillTree(t->right, comp);
	}

	void deleteAll(Node_<value_type> *tmp) {
		if (tmp->NIL) return;
		if (!tmp->left->NIL) deleteAll(tmp->left);
		if (!tmp->right->NIL) deleteAll(tmp->right);
		delete tmp;
	}

	Tree& operator=(const Tree<value_type>& other) {
		if (this == &other)
			return *this;
		deleteAll(root);
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
		while (x != root && x->parent->color == RED) {
			if (x->parent == x->parent->parent->left) {
				Node_<value_type> *y = x->parent->parent->right;
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
				Node_<value_type> *y = x->parent->parent->left;
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
	ft::pair<Node_<value_type>*, bool> insertNode(value_type pair, Compare comp) {
		Node_<value_type> *current, *parent, *x;

		current = root;
		parent = 0;
		while (!current->NIL) {
			if (pair.first == current->pair.first) return ft::make_pair(current, false);
			parent = current;
			current = comp(pair.first, current->pair.first) ?
					current->left : current->right;
		}

		x = new Node_<value_type>();
		x->pair.first = pair.first;
		x->pair.second = pair.second;
		x->parent = parent;
		x->left = &sentinel;
		x->right = &sentinel;
		x->color = RED;

		if (parent) {
			if (comp(pair.first, parent->pair.first))
				parent->left = x;
			else
				parent->right = x;
		} else {
			root = x;
		}

		insertFixup(x);

		if (x == get_last()) { sentinel.parent = x; }
//		if (x == get_begin()) { sentinel.left = x; }
		m_size++;
		return ft::make_pair(x, true);
	}


	void deleteFixup(Node_<value_type> *x) {
		while (x != root && x->color == BLACK) {
			if (x == x->parent->left) {
				Node_<value_type> *w = x->parent->right;
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
				Node_<value_type> *w = x->parent->left;
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
			z->pair.first = y->pair.first;
			z->pair.second = y->pair.second;
		}

		if (y->color == BLACK)
			deleteFixup (x);
		sentinel.parent = get_last();
//		sentinel.left = get_begin();
		m_size--;
		// todo delete free
		free (y);
		return 1;
	}

	template <class Key, class Compare>
	Node_<value_type>* findNode(Key key, Compare comp) {
		Node_<value_type> *current = root;

		while (!current->NIL) {
			if(key == current->pair.first)
				return (current);
			else
				current = comp (key, current->pair.first) ? current->left : current->right;
		}
		return get_end();
	}

	Node_<value_type>* get_begin() {
		Node_<value_type>* tmp = root;
		while (!tmp->left->NIL) {
			tmp = tmp->left;
		}
		return tmp;
	}

	Node_<value_type>* get_last() {
		Node_<value_type>* tmp = root;
		while (!tmp->right->NIL) {
			tmp = tmp->right;
		}
		return tmp;
	}

	Node_<value_type>* get_end() {
		Node_<value_type>* tmp = root;
		while (!tmp->right->NIL) {
			tmp = tmp->right;
		}
		return tmp->right;
	}
};