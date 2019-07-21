class kings {
private:
	int childs;
	kings** childs;
public:
	void init();
	int insert(char* king);
	void treeprint();
	void getChild(char* king);

	
};