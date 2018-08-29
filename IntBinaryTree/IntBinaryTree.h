#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
   // The TreeNode class is used to build the tree.
	class TreeNode
	{
       friend class IntBinaryTree;
       int value;
       TreeNode *left;
	    TreeNode *right;
       TreeNode(int value1, TreeNode *left1 = NULL,
                            TreeNode *right1 = NULL)
       {
          value = value1;
          left = left1;
          right = right1;
       }          
	};
   
	TreeNode *root;     // Pointer to the root of the tree
	
	// Various helper member functions.
    void insert(TreeNode *&, int);
	void destroySubtree(TreeNode *);
	void remove(TreeNode *&, int);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	
public:
   // These member functions are the public interface.
	IntBinaryTree()		// Constructor
		{ root = NULL; }
	~IntBinaryTree()		// Destructor
		{ destroySubtree(root); }
	void insert(int num)
      { insert(root, num); }
	bool search(int) const;
	void remove(int num)
      { remove(root, num);}
	void showInOrder(void) const
		{ displayInOrder(root); }
	void showPreOrder() const
		{ displayPreOrder(root); }
	void showPostOrder() const
		{ displayPostOrder(root); }
};
#endif