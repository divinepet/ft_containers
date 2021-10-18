#include <iostream>
using std::cout;
using std::endl;
#include <map>
#include "Map.hpp"
#include "ft_containers_tests/general.hpp"

#define compMT(a,b) (a > b)

//template <class T, class V>
//void print(std::map<T, V> map) {
//	typename std::map<T, V>::iterator it = map.begin();
//	for (; it != map.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}
//}
//
//template <class T, class V>
//void print(ft::Map<T, V> map) {
//	typename ft::Map<T, V>::iterator it = map.begin();
//	for (; it != map.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}
//}

void t(ft::Map<int, int> mp) {
	mp.insert(ft::make_pair(1, 1));
	ft::Map<int, int>::iterator it = mp.begin();
	cout << it->first << endl;
}

int main(int argc, char **argv) {
//	start_tests();

//	ft::Map<int, int, std::greater<int> > mp;
//
//	mp.insert(ft::make_pair(13, 3));
//	mp.insert(ft::make_pair(5, 3));
//	mp.insert(ft::make_pair(9, 3));
//	mp.insert(ft::make_pair(7, 3));
//
//	ft::Map<int, int>::iterator it = mp.begin();
//
//	cout << it->first << endl;

	//todo doesnt work iterator
	ft::Map<int ,int> mp;
	mp.insert(ft::make_pair(3, 3));
//	mp.insert(ft::make_pair(7, 3));
//	mp.insert(ft::make_pair(13, 3));
//	mp.insert(ft::make_pair(5, 5));
//	mp.insert(ft::make_pair(8, 5));
//	mp.insert(ft::make_pair(9, 5));
//	mp.erase(13);
//
	ft::Map<int, int>::iterator it = mp.begin();
	it--;
//	cout << it->first << endl;

//	while (true) {};

//	mp.insert(ft::make_pair(9, 9));
//
//	ft::pair<ft::Map<int, int>::iterator , bool> pair = mp.insert(ft::make_pair(9, 9));
//	cout << pair.second << endl;

//	std::map<int, int> mp2;
//	mp2.insert(std::make_pair(9, 9));
//
//	std::pair<std::map<int, int>::iterator , bool> pair2 = mp2.insert(std::make_pair(9, 9));
//	cout << pair2.second << endl;



//	ft::Map<int, int> mp;
//	ft::Map<int, int >::iterator it = mp.find(4);
//	if (it != mp.end())
//		cout << "yea" << endl;
//	else
//		cout << "no" << endl;


//	tree.it = tree.last;
//	cout << tree.it->first << endl;


//	Tree<int, int> tree;
//
//	tree.insertNode(4, 4);
//
//	cout << tree.begin->first << endl;



//	start_tests();

//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(3, 3));
//	foo(mp);









//	ft::Map<int, int> mp;
//
//	mp.insert(ft::make_pair(7, 7));
//	mp.insert(ft::make_pair(3, 3));
//	mp.insert(ft::make_pair(13, 3));
//	mp.insert(ft::make_pair(6, 3));
//	mp.insert(ft::make_pair(5, 3));
//	ft::Map<int, int>::iterator it = mp.begin();
//
//	it++;
//	it++;
//
//	cout << it->first << endl;

//	Tree<int, int> tree;
//
//	tree.insertNode(7, 7);
//	tree.insertNode(11, 11);
//	tree.insertNode(4, 4);
//
//	tree.iterator = tree.findNode(4);
//	tree.iterator = tree.increment(tree.iterator);
//
//	cout << tree.iterator->first << endl;



















//	Tree<int, int > tree;
//	tree.insertNode(4, 4);
//	tree.insertNode(5, 5);
//	tree.iterator = tree.increment(tree.begin);
//	cout << tree.iterator->first << endl;

//	ft::pair<int, int > a;
//	ft::pair<int, int > b;
//	cout << (a == b) << endl;
//	Tree<int, int> tree;
//	tree.insertNode(4, 4);
//	tree.insertNode(5, 5);
//	tree.iterator = tree.get_begin();
//	tree.iterator = tree.increment(tree.iterator);
//	cout << tree.iterator->first << endl;

//	mp.insert(ft::make_pair(7, 5));
//	mp.insert(ft::make_pair(9, 5));
//	mp.insert(ft::make_pair(11, 5));
//	mp.insert(ft::make_pair(5, 5));
//	mp.insert(ft::make_pair(1, 1));
//	ft::Map<int, int>::iterator it = mp.begin();
//	it++;
//	ft::Map<int, int>::iterator it2 = mp.begin();
//	cout << (*it == *it2) << endl;
//	cout << it->operator==(it2) << endl;
//	cout << it->first << endl;



//	cout << it->first << endl;



//
//	tree.insertNode(3, 3);
//	tree.insertNode(5, 5);
//	tree.iterator = tree.get_begin();
//
//	cout << tree.iterator->first << endl;
//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(3, 3));
//	mp.insert(ft::make_pair(5, 5));
//
//	ft::Map<int, int>::iterator it = mp.begin();
//
//	cout << it->first << endl;
//	cout << it->second << endl;

//	ft::Map<int, int> mp;
//	ft::Map<int, int>::const_iterator it = mp.begin();


//
//	Tree<int, int> tree;
////
//	tree.insertNode(3, 3);
//	tree.insertNode(11, 11);
//	tree.insertNode(1, 1);
////
//	tree.iterator = tree.get_begin();
////
////
//	tree.iterator = tree.decrement(tree.iterator);
//	tree.iterator = tree.increment(tree.iterator);
//	tree.iterator = tree.increment(tree.iterator);
//	tree.iterator = tree.get_end(); // 3

//	tree.iterator = tree.decrement(tree.iterator);
//
//	cout << tree.iterator->first << endl;




//	std::map<int, int> m;
//
//	m.insert(std::make_pair(3, 3));
//	m.insert(std::make_pair(5, 5));
//	std::map<int, int>::iterator it = m.begin();
//	it++;
//	it++;
//	it++;
//	cout << it->first << endl;





//	cout << m.max_size() << endl;
//	cout << m[0] << endl;











//	ft::node_iterator<Tree<int, int>::Node_*> it;
//	it = tree.get_begin();
//
//	cout << it->first << endl;

//	t = insertNode(2);
//	t = insertNode(13);
//	t = insertNode(15);
//	t = insertNode(11);
//	t = insertNode(6);
//	t = insertNode(12);
//	t = insertNode(1) ;
//	t = insertNode(17);
//	t = insertNode(7) ;
//	t = insertNode(18);
//	t = insertNode(8) ;
//	t = insertNode(19);
//
//
//



//	cout << root->right->left->data << endl;
//	cout << root->right->right->data << endl;



//	ft::Map<int, int > mp;
//	mp.insert(ft::make_pair(12, 3));
//	mp.insert(ft::make_pair(18, 3));
//	mp.insert(ft::make_pair(6, 3));
//	mp.insert(ft::make_pair(13, 3));
//	mp.insert(ft::make_pair(19, 3));
//	mp.insert(ft::make_pair(15, 3));
//	mp.insert(ft::make_pair(17, 3));
//	mp.insert(ft::make_pair(11, 3));
//	mp.insert(ft::make_pair(8, 3));
//	mp.insert(ft::make_pair(2, 3));
//	mp.insert(ft::make_pair(7, 3));
//	mp.insert(ft::make_pair(1, 3));




//	RBTree<int> rb;
//	g_start1 = timer();
//	for(int i = 0; i < 15000; ++i)
//		rb.Insert(i);
//	g_end1 = timer();

//	cout << g_end1 - g_start1 << "ms" << endl;




//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(3, 3));
//	mp.insert(ft::make_pair(2, 2));
//
//	ft::Map<int, int> mp2;
//	mp2.insert(ft::make_pair(333, 333));
//	mp2.insert(ft::make_pair(777, 777));
//
//	ft::Map<int, int> mp3(mp2);
////	print(mp3);
//
//	mp = mp2;
//
//	print(mp);

//	mp.insert(ft::make_pair(35, 1));
//	mp.insert(ft::make_pair(44, 1));
//	mp.insert(ft::make_pair(89, 1));
//	mp.insert(ft::make_pair(127, 1));
//	mp.insert(ft::make_pair(444, 1));
//
//
//
//	ft::Map<int, int>::iterator it = mp.begin();
//	it++;
//	it++;
//	it++;
//	it++;
//	it--;
//	it--;
//	it--;
//	it--;
//	cout << it->first << endl;

//	std::map<int, int > m;
//	m.insert(std::make_pair(3, 3));
//	m.insert(std::make_pair(4, 4));
//	m.insert(std::make_pair(5, 5));
//
//	std::map<int, int >::iterator i = m.begin();
//
//	while (i++ != m.end()) {
//		cout << i->first << endl;
//	}


//	std::map<int, int > mp;
//	mp.insert(std::make_pair(3, 4));
//	mp.insert(std::make_pair(7, 7));
//	mp.insert(std::make_pair(9, 9));
//	std::pair<std::map<int, int>::iterator , bool> pair = mp.insert(std::make_pair(9, 9));
//
//	std::map<int, int>::iterator it = pair.first;

//	cout << it->first << endl;

//	ft::Map<int, int> mp;
//	mp.insert(ft::make_pair(3, 3));


//	mp.insert(ft::make_pair(3, 3));

//	std::map<int, int>::iterator it = mp.begin();
//	for (; it != mp.end(); ++it) {
//		cout << "key: " << it->first << ", value: " << it->second << endl;
//	}

//	Node<int, int> t;
//	t.insertNode(6, 6);
//	t.insertNode(5, 5);
//
//
//	Node<int, int>::node_iterator it = t.begin();
//
//
//	cout << it->first << endl;

//	ft::Map<int, int> mp;
//	ft::pair<ft::Map<int, int>::iterator, bool> pair;
//	pair = mp.insert(ft::make_pair(5, 22));
//	cout << "key: " << pair.first->first << ", value: " << pair.first->second << endl;
//	cout << mp.at(7) << endl;
//	cout << mp[17] << endl;
//	ft::Map<int, int>::iterator it = mp.begin();
//	cout << it->first << endl;

//
//	std::map<int,int > mp;
//	std::pair<std::map<int, int>::iterator, bool> pair;
//	pair = mp.insert(std::make_pair(0, 22));
//	cout << "key: " << pair.first->first << ", value: " << pair.first->second << endl;
//	cout << mp.at(0) << endl;
//	cout << mp[17] << endl;



//	Node_Base<int, char>::iterator it;
//	Node_Base<int, char>::iterator it2;

//	cout << (it == it2) << endl;


//	it->
//	cout << *it << endl;
//	Node<int> t;
//	t.insertNode(3);
//	cout << "create Tree: ";
//	t.printElements();
//	std::map<int, int>::iterator  it;
//	it->
//	std::map<int, int>::iterator ittt;
//	ittt.
//	std::vector<int>::iterator  itt;
//	itt


//std::vector<int>::iterator itvec;
//itvec.
//	Node<int, char>::iterator it = t.begin();
//	it++;
//	Node<int, char>::iterator it2 = t.begin();
//	cout << (it == it2) << endl;
//	std::map<int, char>::iterator::
//	itmap.
//	cout << it->first << endl;
//	cout << it->val << endl;
//	t.Iterator_visit(it, t.end());
//	cout << endl;
//	cout << "the max of tree: " << t.getMax() << endl;
//	cout << "the min of tree: " << t.getMin() << endl;
//	t.deleteNode(13);
//	t.printElements();
//	cout << "the max of tree: " << rb.getMax() << endl;
//	cout << "the min of tree: " << rb.getMin() << endl;
//	itr=rb.begin();
//	cout << "visit tree by iterator: " << endl;
//	rb.Iterator_visit(itr, rb.end());

//	Node *t;




//	t = insertNode(27);
//	t = insertNode(13);
//	t = insertNode(1);
//	t = insertNode(22);
//	t = insertNode(17);
//	t = insertNode(25);
//	t = insertNode(11);
//	t = insertNode(6);
//	t = insertNode(15);
//	t = insertNode(8);

//	printElem(root);
//	get_begin(root);
//	Node* x = increment(findNode(6));
//	cout << x->data << endl; // 8
//	Node* xx = increment(x);
//	cout << xx->data << endl; // 11
//	Node* xxx = increment(xx);
//	cout << xxx->data << endl; // 13
//	Node* xxxx = increment(xxx);
//	cout << xxxx->data << endl; // 13
//	Node* xxxxx = increment(xxxx);
//	cout << xxxxx->data << endl; // 13
//	Node* xxxxxx = increment(xxxxx);
//	cout << xxxxxx->data << endl; // 13
//	Node* xxxxxxx = increment(xxxxxx);
//	cout << xxxxxxx->data << endl; // 13
//	Node* xxxxxxxx = increment(xxxxxxx);
//	cout << xxxxxxxx->data << endl; // 13



//	std::map<int, char> mp;
//	mp.insert(std::make_pair(13, 'e'));
//	mp.insert(std::make_pair(6, 'e'));
//	mp.insert(std::make_pair(3, 'e'));
//	mp.insert(std::make_pair(5, 'e'));
//	mp.insert(std::make_pair(36, 'e'));
//	mp.insert(std::make_pair(35, 'e'));
//	mp.insert(std::make_pair(23, 'e'));
//	mp.insert(std::make_pair(11, 'e'));
//
//	std::map<int, char>::iterator it;
//
//	for (it=mp.begin(); it != mp.end(); it++)
//		std::cout << "key: " << it->first << " value: " << it->second << "\n";

}