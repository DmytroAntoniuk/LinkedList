#include "LinkedList.h"

enum NodeParts {data, next};

void StringListInit(char*** list)
{
	 *list = NULL;
}

void StringListDestroy(char*** list)
{
	if (!list) return;
	char** nextNode = NULL;
	while ((*list)[next])
	{
		nextNode = (*list)[next];
		free((*list)[data]);
		free(*list);
		(*list) = nextNode;
	}
	free((*list)[data]);
	free(*list);
	(*list) = NULL;
}

void StringListAdd(char*** list, const char* str)
{
	if (!str) return;

	char** node_to_add = (char**)calloc(2, sizeof(char*));
	const int str_length = strlen(str) + 1;
	node_to_add[data] = (char*)calloc(str_length,sizeof(char));
	memcpy_s(node_to_add[data], str_length,str, str_length);
	node_to_add[next] = NULL;
	if (*list)
	{ 
		char** tempList = *list;
		while (tempList[next])
		{
			tempList = tempList[next];
		}
		tempList[next] = node_to_add;
	}
	else
	{
		*list = node_to_add;
	}
}

void StringListRemove(char*** list, const char* str)
{
	char** temp = *list;
	char** prev_node = NULL;
	if (*temp && !strcmp(temp[data], str))
	{
		*list = temp[next];
		free(temp);
		return;
	}

	while (*temp && strcmp(temp[data], str))
	{
		prev_node = temp;
		temp = temp[next];
	}

	if (!*temp)
	{
		printf("Node is absent! \n");
		return;
	}

	prev_node[next] = temp[next];
	free(temp);
	
}

int StringListSize(char** list)
{
	int size = 0;
	if (list)
	{
		while (list)
		{
			++size;
			list = list[next];
		}
	}

	return size;
}

int StringListIndexOf(char** list, char* str)
{
	char** temp = list;
	int index = 0;
	int list_size = StringListSize(list);
	while (list_size != index)
	{
		if (!strcmp(temp[data], str)) return index;
		++index;
		temp = temp[next];
	}

	if (StringListSize(list) == index)
	{
		printf("Node is absent! \n");
		return -1;
	}

	return index;
}

void StringListDisplay( char** list)
{
	if (list)
	{
		printf("List: \n");
		while (list)
		{
			printf("%s \n", (list[data]));
			list = list[next];
		}
	}
	else
	{
		printf("List is empty.\n");
	}
}

void StringListRemoveDuplicates(char*** list)
{
	if (!list) return;

	char** first_node = *list;
	char** second_node = NULL;
	char** previous_node = *list;

	while (first_node) {
		previous_node = first_node;
		second_node = first_node[next];
		while (second_node) {
			if (!strcmp(first_node[data], second_node[data])) {
				previous_node[next] = second_node[next];
				free(second_node[data]);
				free(second_node);
				second_node = previous_node;
			}
			previous_node = second_node;
			second_node = second_node[next];
		}
		first_node = first_node[next];
	}

}

void StringListReplaceInStrings(char*** list, const char* before, const char* after) {

	if (!list || !before || !after) return;
	char** current_node = *list;
	while (current_node) {
		if (!strcmp(current_node[data], before)) {
			char* tmp = (char*)calloc(strlen(after) + 1, sizeof(char));
			strcpy_s(tmp, strlen(after)+1, after);
			free(current_node[data]);
			current_node[data] = tmp;
		}
		current_node = (char*)current_node[next];
	}
}

void StringListSort(char*** list)
{
	if (!list) return;

	char** first_node = *list;
	char** second_node = NULL;

	while (first_node != NULL) {
		second_node = first_node[next];
		while (second_node != NULL) {
			if (strcmp(first_node[data], second_node[data]) > 0) {
				char** temp = first_node[data];
				first_node[data] = second_node[data];
				second_node[data] = temp;

			}
			else
				second_node = second_node[next];
		}
		first_node = first_node[next];
	}
}

