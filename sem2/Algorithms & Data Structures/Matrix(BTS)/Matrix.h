#pragma once
typedef int TElem;

class MatrixIterator;

struct Element {
	TElem value;
	int line, column;
};

struct TreeNode
{
	TreeNode *left, *right;
	Element data;
};


class Matrix {

private:

	int lines, cols;
	TreeNode* root;

	TreeNode* initNode(int i, int j, TElem e);

	TreeNode* insertNode(TreeNode ** node, int i, int j, TElem e);
	TreeNode* searchNode(TreeNode* node, int i, int j) const;
	void deleteNode(TreeNode* node);

public:


	//constructor
	//throws exception if nrLines or nrCols is negative or zero
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrLines() const;

	//returns the number of columns
	int nrColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem e);

	MatrixIterator iterator(int line) const;



	~Matrix();

};
