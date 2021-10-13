

#include <iostream>
using namespace std;
template<typename T>
class RBTree;
enum Coolor{REDDD=0,BBLACK=1};
template<typename T>
class RBnode{
	friend class RBTree<T>;
public:
	typedef RBnode<T>* rb_iterator;
private:
	typedef RBnode<T>* Nodeptr;
public:
	Nodeptr left,right,parent;
	Nodeptr prior,next;
	Coolor color;
public:
	T val;
public: // все новые узлы - красные узлы
	RBnode(T value){left=right=parent=this;val=value;color=REDDD;}
	RBnode(T value, Nodeptr l, Nodeptr r):val(value),left(l),right(r){parent=this,color=REDDD;}
};
template<typename T>
class RBTree{
	friend class RBnode<T>;
private:
	typedef RBnode<T>* Nodeptr;
public:
	typedef RBnode<T>* rb_iterator;
private:
	Nodeptr header;
	Nodeptr root;
	Nodeptr nlnode;
	Nodeptr _prior;
	Nodeptr _next;
public:
	RBTree(){
		header=new RBnode<T>(0);
		nlnode=new RBnode<T>(-1);
		nlnode->color = header->color = BBLACK;
		root=nlnode;
		root->parent=header;
		root->left=root->right=nlnode;
		header->left=nlnode;
		header->right=root;
		nlnode->parent=nlnode;
		header->next = nlnode;
		header->prior = nlnode;
	}
public:
	bool isEmpyty();
	void Insert(T x);
	void Insert(Nodeptr);
	bool remove(T x);
	bool remove(Nodeptr x);
	Nodeptr search(T x);
	T getMax();
	T getMin();
	rb_iterator begin(){return header->next;}
	rb_iterator end(){return header;}
	void inorderWalk(Nodeptr p) const ;
	void LORvisit();
	void Iterator_visit(rb_iterator start, rb_iterator over) {
		rb_iterator temp = start;
		while(temp != over){
			cout << temp->val << ' ';
			temp = temp->next;
		}
	}
private:
	void LOR();
	void LOR(Nodeptr c);
	void LeftRotate(Nodeptr x);
	void RightRotate(Nodeptr x);
	void Fix_up_insert(Nodeptr x);
	void Fix_up_remove(Nodeptr x);
	void Transplante(Nodeptr old, Nodeptr neo);
	Nodeptr BranchMax(Nodeptr x);
	Nodeptr BranchMin(Nodeptr x);
	void LORvisit(Nodeptr c);
};
template<typename T>
void RBTree<T>::LOR(){
	_prior = _next = header;
	LOR(root);
	_next->next=header;
	header->prior=_next;
}
template<typename T>
void RBTree<T>::LORvisit(){
	LORvisit(root);
	cout << endl;
}
template<typename T>
void RBTree<T>::LOR(Nodeptr c){
	if(c->left != nlnode){
		LOR(c->left);
	}
	_prior = _next;
	_next = c;
	_prior->next=_next;
	_next->prior=_prior;
	if(c->right != nlnode){
		LOR(c->right);
	}
}
template<typename T>
void RBTree<T>::LORvisit(Nodeptr c){
	if(c->left != nlnode){
		LORvisit(c->left);
	}
	cout << c->val << ' ';
	if(c->right != nlnode){
		LORvisit(c->right);
	}
}
template<typename T>
bool RBTree<T>::isEmpyty(){
	return root == nlnode;
}
template<typename T>
void RBTree<T>::Insert(T x){
	Nodeptr n=new RBnode<T>(x, nlnode, nlnode);
	Insert(n);
}
template<typename T>
void RBTree<T>::Insert(Nodeptr x){
	Nodeptr first,second;
	first = second = root;
	if(root == nlnode){
		root = x;
		header->right = x;
		x->parent = header;
		x->color = BBLACK;
		return;
	}
	while(first!=nlnode){
		second = first;
		if(first->val > x->val){
			first = first->left;
		}else if(first->val < x->val){
			first = first->right;
		}else{
			return ;
		}
	}
	x->parent = second;
	if(second->val > x->val){
		second->left = x;
	}else{
		second->right = x;
	}
	Fix_up_insert(x);
	LOR();
}
template<typename T>
void RBTree<T>::LeftRotate(Nodeptr x){
	if (x-> right == nlnode) // Правое поддерево не может быть левым, чтобы избежать неправильной операции по очистке дерева
		return;
	Nodeptr x_r=x->right;
	x->right = x_r->left;
	if (x_r-> left != nlnode) // Избегайте разрушения характеристик пустых узлов: родительский узел указывает на себя
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
}
template<typename T>
void RBTree<T>::RightRotate(Nodeptr x){
	if (x-> left == nlnode) // Правое поддерево не может быть левым, чтобы избежать неправильной операции по очистке дерева
		return;
	Nodeptr x_l=x->left;
	x->left = x_l->right;
	if (x_l-> right != nlnode) // Избегайте разрушения характеристик пустых узлов: родительский узел указывает на себя
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
}
template<typename T>
void RBTree<T>::Fix_up_insert(Nodeptr x){
	while (x-> parent-> color == REDDD) {// Сначала убедитесь, что нет непрерывного красного узла
		if(x->parent == x->parent->parent->left){
			if(x->parent->parent->right->color == REDDD){//case 1: son --red,dad&dad's brother --red
				x->parent->parent->right->color = x->parent->color = BBLACK;
				x->parent->parent->color = REDDD;
				x = x->parent->parent;
			}
			else{
				if(x == x->parent->right){//case 2:inner side,son --red,dad --red
					x = x->parent;
					LeftRotate(x);
				}
				x->parent->parent->color = REDDD;//case 3:outer side,son --red,dad --red
				x->parent->color = BBLACK;
				x = x->parent;
				RightRotate(x->parent->parent);
			}
		}
		else{
			if(x->parent->parent->left->color == REDDD){//case 1: son --red,dad&dad's brother --red
				x->parent->parent->left->color = x->parent->color = BBLACK;
				x->parent->parent->color = REDDD;
				x = x->parent->parent;
			}
			else{
				if(x == x->parent->left){//case 2:inner side,son --red,dad --red
					x = x->parent;
					LeftRotate(x);
				}
				x->parent->parent->color = REDDD;//case 3:outer side,son --red,dad --red
				x->parent->color = BBLACK;
				x = x->parent;
				RightRotate(x->parent->parent);
			}
		}
	}
	root->color=BBLACK;
}

template<typename T>
RBnode<T>* RBTree<T>::search(T x){
	Nodeptr temp = root;
	while(temp!=nlnode){
		if(temp->val > x){
			temp = temp->left;
		}else if(temp->val < x){
			temp = temp->right;
		}else{
			return temp;
		}
	}
	return nlnode;
}
template<typename T>
bool RBTree<T>::remove(T x){
	Nodeptr target = search(x);
	if(target == nlnode){
		LOR();
		return false;}
	return remove(target);
}
template<typename T>
bool RBTree<T>::remove(Nodeptr x){
	Nodeptr a = x;
	Nodeptr b = nlnode;
	Coolor a_OriCo = a->color;
	if(x->left==nlnode){//case 1:with one kid or no one
		b = x->right;
		Transplante(x, x->right);
	}else if(x->right==nlnode){
		b = x->left;
		Transplante(x, x->left);
	}else{
		Nodeptr a=BranchMin(x->right);
		a_OriCo = a->color;
		b = a->right;
		if(a->parent == x){//case 2:replace node is son of x
			b->parent = a;//case nlnode
		}else{
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
	if (a_OriCo == BBLACK) {// case 3: Нарушение правил красного и черного, количество черных узлов на пути разное
		Fix_up_remove(b);
	}
	LOR();
}
template<typename T>
void RBTree<T>::Transplante(Nodeptr old, Nodeptr neo){
	if(old->parent == header){
		header->right = neo;
		root = neo;
	}else if(old->parent->left == old){
		old->parent->left = neo;
	}else if(old->parent->right == old){
		old->parent->right = neo;
	}
	neo->parent = old->parent;
}
template<typename T>
RBnode<T>* RBTree<T>::BranchMax(Nodeptr x){
	if(x == nlnode)
		return x;
	Nodeptr temp=x;
	while(temp->right!=nlnode){
		temp=temp->right;
	}
	return temp;
}
template<typename T>
RBnode<T>* RBTree<T>::BranchMin(Nodeptr x){
	if(x == nlnode)
		return x;
	Nodeptr temp=x;
	while(temp->left!=nlnode){
		temp=temp->left;
	}
	return temp;
}
template<typename T>
void RBTree<T>::Fix_up_remove(Nodeptr x){
	Nodeptr z = nlnode;
	while(x!=root&&x->color==BBLACK){
		if(x == x->parent->left){
			z=x->parent->right;
			if(z->color == REDDD){//case 1:x's brather --red
				z->color=BBLACK;
				x->parent->color = REDDD;
				LeftRotate (x-> parent); // Используем красный, чтобы черный оставался последовательным
				z = x->parent->right;//update x's brother
			}//case 2:x&x's brother sons color same
			if(z->left->color==BBLACK && z->right->color==BBLACK){
				z-> color = REDDD; // Сохраняем тот же цвет, что и x, потому что это родственный узел
				x = x-> parent; // Регулировка вверх
			}
			else {
				if(z->right->color==BBLACK) {//z:x's brother
					z->color = REDDD;//case 3:z left--red,right--black
					z->left->color = BBLACK;
					RightRotate(z);
					z = x->parent->right;
				}
				//case 4:adjust x and z
				// Дерево уравновешивает высоту, сохраняя цвет исходной позиции родительского узла
				z->color = x->parent->color;
				x->parent->color = BBLACK;
				z->right->color = BBLACK;
				LeftRotate(x->parent);
				break;
			}
		}
		else {
			z=x->parent->left;
			if(z->color == REDDD){//case 1:x's brather --red
				z->color=BBLACK;
				x->parent->color = REDDD;
				this-> RightRotate (x-> parent); // Используйте красный, чтобы сохранить однородность черного
				z = x->parent->left;//update x's brother
			}//case 2:x&x's brother sons color same
			if(z->right->color==BBLACK && z->left->color==BBLACK){
				z-> color = REDDD; // Сохраняем тот же цвет, что и x, потому что это родственный узел
				x = x-> parent; // Регулировка вверх
			}
			else {
				if(z->left->color==BBLACK) {//z:x's brother
					z->color = REDDD;//case 3:z left--red,right--black
					z->right->color = BBLACK;
					LeftRotate(z);
					z = x->parent->left;
				}
				//case 4:adjust x and z
				// Дерево уравновешивает высоту, сохраняя цвет исходной позиции родительского узла
				z->color = x->parent->color;
				x->parent->color = BBLACK;
				z->left->color = BBLACK;
				RightRotate(x->parent);
				break;
			}
		}
	}
	root-> color = BBLACK; // Сохраняем корень черным
}
template<typename T>
T RBTree<T>::getMax(){
	return header->prior->val;
}
template<typename T>
T RBTree<T>::getMin(){
	return header->next->val;
}
