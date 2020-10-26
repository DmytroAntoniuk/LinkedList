#include"LinkedList.h"

int main() {
	char** list;
	StringListInit(&list);
	StringListAdd(&list,"First");
	StringListRemove(&list, "First");
	StringListDisplay(list);
	StringListAdd(&list,"Second");
	StringListAdd(&list,"Third");
	StringListDisplay(list);
	StringListRemove(&list, "Second");
	StringListDisplay(list);
	printf("%d \n", StringListSize(list));
	StringListAdd(&list, "Fourth");
	StringListDisplay(list);
	printf("%d \n",StringListSize(list));
	printf("%d \n", StringListIndexOf(list, "qwe"));
	StringListAdd(&list, "Second");
	StringListAdd(&list, "Third");
	StringListSort(&list);
	StringListReplaceInStrings(&list, "Third", "QQQ");
	StringListDisplay(list);
	StringListRemoveDuplicates(&list);
	StringListDisplay(list);
	StringListDestroy(&list);
}