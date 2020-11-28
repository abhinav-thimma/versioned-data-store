//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<windows.h>
//
//struct student
//{
//	int n;
//	char name[32];
//};
//
//
//
//struct marks
//{
//	int sid;
//	int m[4];
//};
//
//
//struct dataPageStd
//{
//	byte pageType;
//	byte tableId;
//	struct student data[3];
//	char unused[18];
//};
//
//
//struct dataPageMarks
//{
//	byte pageType;
//	byte tableId;
//	int sid;
//	char unused[4];
//	struct marks marksData[6];
//
//};
//
//struct indexPage
//{
//	byte tableId;
//	byte pageType;
//	int pageIds[16];
//	int key[15];
//	char unused[2];
//};
//
//struct tablePage
//{
//	byte pageType;
//	byte tableId;
//	int rootPageId[10];
//	char tableName[10][8];
//};
//
//
//
////this function returns token of string based on delimiter
//char** getT(char* str, char* delim)
//{
//	if (str[strlen(str) - 1] == '\n')
//		str[strlen(str) - 1] = '\0';
//
//	char** arr = (char**)malloc(sizeof(char*) * 10);
//	char* s;
//	int i = 1;
//
//
//	arr[0] = strtok(str, delim);
//
//	while (s = strtok(NULL, delim))
//	{
//		arr[i] = s;
//		i++;
//	}
//
//	return arr;
//}
//
//
//
//int main()
//{
//
//
//
//	FILE* input = fopen("randomuserdata.csv", "r");
//	struct dataPageStd *arr = (struct dataPageStd*)malloc(sizeof(struct dataPageStd));
//
//	char* buff = (char*)malloc(sizeof(char) * 1000);
//	fgets(buff, 1000, input);
//
//	FILE* fp = fopen("output.bin", "wb");
//
//
//
//	for (int i = 0; i < 16; i++)
//	{
//
//		fgets(buff, 1000, input);
//		buff[strlen(buff) - 1] = '\0';
//		char** tokens = getT(buff, ",");
//
//		arr->data[0].n = atoi(tokens[0]);
//		strcpy(arr->data[0].name, tokens[1]);
//
//
//
//		fgets(buff, 1000, input);
//		if (buff == NULL)
//			break;
//		buff[strlen(buff) - 1] = '\0';
//		tokens = getT(buff, ",");
//
//		arr->data[1].n = atoi(tokens[0]);
//		strcpy(arr->data[2].name, tokens[1]);
//
//
//		fgets(buff, 1000, input);
//		if (buff == NULL)
//			break;
//		buff[strlen(buff) - 1] = '\0';
//		tokens = getT(buff, ",");
//
//		arr->data[0].n = atoi(tokens[0]);
//		strcpy(arr->data[0].name, tokens[1]);
//
//		fwrite(arr, sizeof(struct dataPageStd), 1, fp);
//
//	}
//
//
//
//	fclose(fp);
//	fclose(input);
//
//
//
//	int size = 0;
//
//	FILE* outputWrite = fopen("out1.txt", "ab");
//	FILE* outputRead = fopen("out1.txt", "rb");
//
//
//	struct indexPage * indexNode = (struct indexPage*)malloc(sizeof(struct indexPage));
//
//
//	for (int j = 0; j < 16; j++)
//	{
//		struct dataPageStd* dataNode = (struct dataPageStd*)malloc(sizeof(struct dataPageStd));
//
//		fread(dataNode, sizeof(struct dataPageStd), 1, outputRead);
//
//		if (j != 0)
//		{
//			indexNode->key[j - 1] = dataNode->data[0].n;
//
//
//			printf("key for %d: %d \n", j, indexNode->key[j - 1]);
//		}
//
//		indexNode->pageIds[j] = size;
//		size += 128;
//	}
//
//	fwrite(indexNode, sizeof(struct indexPage), 1, outputWrite);
//
//	fclose(outputWrite);
//	fclose(outputRead);
//
//
//
//}