typedef struct node node;
struct node
{
	long long int item;
	node *next;
	node *previous;
};

extern node *addNode(long long int item, node *list);
extern void showList(node *list);