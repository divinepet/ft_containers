#include "Node.hpp"

int main(int argc, char **argv) {

	Node<int, int> t;
	t.insertNode(6, 6);
	t.insertNode(5, 5);
//	t.insertNode(7, 7);

	cout << t.header->next->first << endl;
	cout << t.header->first << endl;
	cout << t.root->first << endl;


//	Node<int, int>::node_iterator it = t.begin();


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

//	start_tests();
}