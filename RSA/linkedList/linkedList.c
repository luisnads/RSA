#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

node *addNode(long long int item, node *list)
{
	node *newNode = (node*) malloc(sizeof(node));
	newNode->item = item;
	newNode->next = list;
	newNode->previous = NULL;
	if(list != NULL) list->previous = newNode;
	return newNode;
}

void showList(node *list)
{
	if(list->next == NULL)
	{
		printf("%lld\n", list->item);
		return;
	}
	printf("%lld ", list->item);
	showList(list->next);
}