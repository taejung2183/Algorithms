#include <iostream>

using namespace std;

class Node {
private:
	int val;
public:
	Node left, right, parent;
	Node(int val) {
		this.val = val;
		left = right = parent = NULL;
	}
	int getVal() { return val; }
};

// Find Inorder successor of an inputNode
Node findInorderSuccessor(Node inputNode) {
	if (inputNode == NULL) return NULL;
	
	// input node has right child
	Node rightChild = inputNode.right;
	if (rightChild != NULL) {
		// If right child has left child, get into left until you meet null
		Node node = rightChild;
		while (node.left != NULL) {
			node = node.left;
		}
		// If there's no left child, right child itself is returned
		return node;
	}

	// input node has parent
	Node inputParent = inputNode.parent;
	if (inputParent != NULL) {
		// If input node is left child, its parent is greater
		if (inputNode == inputParent.left) return inputParent;

		// If input node is right child, find the first ancestor who's left child
		Node parent = inputParent;
		Node child = inputNode;
		while (parent.parent != NULL) {
			child = parent;
			parent = parent.parent;
			if (child = parent.left) break;
		}
		// If there's no ancestor who's left child, parent will be null
		// If you found the one, its parent will be the in-order successor
		return parent;
	}
	
	// input node has no parent and left child
	return NULL;
}

int main() {
	Node n1(5);
	Node n2(9);
	Node n3(20);
	Node n4(25);
	Node n5(12);
	Node n6(11);
	Node n7(14);

	n1.parent = n2;
	n2.left = n1;
	n2.right = n5;
	n2.parent = n3;
	n3.left = n2;
	n3.right = n4;
	n4.parent = n3;
	n5.left = n6;
	n5.right = n7;
	n5.parent = n2;
	n6.parent = n5;
	n7.parent = n5;

	Node input = n2;
	Node ans = NULL;
	if ((ans = findInorderSuccessor(n2)) != NULL) {
		cout << "in-order succossor of " <<  input.getVal() << " is " << ans.getVal() << '\n';
	} else {
		cout << input.getVal() << " has no in-order successor" << '\n';
	}

	return 0;
}
