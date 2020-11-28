#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

//assuming page size is 128 bytes

//this structure occupies  36 bytes
struct student
{
	int n;
	char name[32];
	//char district[20];
};

//this stores three student records (36*3 = 108 is maximum that can fit in 128 bytes) 128-108 = 20 bytes are unused
struct dataPage
{
	struct student data[3];
	char unused[20];
};

//no of keys  = no of children -1  so ( k + k-1 )* 4 <= 128 , k = 16 ,unused bytes = 4
struct indexPage
{
	int pageIds[16];
	int key[15];
	char unused[4];
};



//this function returns token of string based on delimiter
char** getT(char* str, char* delim)
{
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';

	char** arr = (char**)malloc(sizeof(char*) * 10);
	char* s;
	int i = 1;


	arr[0] = strtok(str, delim);

	while (s = strtok(NULL, delim))
	{
		arr[i] = s;
		i++;
	}

	return arr;
}



void t()
{
	/*for (int i = 0; i < 6; i++)
	{
	char* buff = (char*)malloc(sizeof(char) * 100);
	fgets(buff, 100, input);


	char** tokens = getT(buff,"\t");

	arr[i].n = atoi(tokens[0]);
	strcpy(arr[i].name, tokens[1]);
	}




	fclose(input);


	//writing the structures into the array as a single unit instead of seperatly storing data
	//
	FILE* output = fopen("output.txt", "wb");

	fwrite(arr, sizeof(struct student), 6, output);
	fclose(output);


	output = fopen("output.txt", "rb");
	struct student *arr1 = (struct student*)malloc(sizeof(struct student) * 6);
	fread(arr1, sizeof(struct student), 6, output);
	for (int i = 0; i < 6; i++)
	{
	printf("%d,%s\n", arr1[i].n, arr1[i].name);
	}
	fclose(output);*/
}



int main()
{
	FILE* input = fopen("randomuserdata.csv", "r");
	struct dataPage *arr = (struct dataPage*)malloc(sizeof(struct dataPage));

	char* buff = (char*)malloc(sizeof(char) * 1000);
	//struct indexPage* indexNode = (struct indexPage*)malloc(sizeof(struct indexPage)*16);
	fgets(buff, 1000, input);


	FILE* fp = fopen("out1.txt", "wb");

	for (int j = 0; j < 16; j++)
	{

		for (int i = 0; i < 16; i++)
		{

			fgets(buff, 1000, input);
			buff[strlen(buff) - 1] = '\0';
			char** tokens = getT(buff, ",");

			arr->data[0].n = atoi(tokens[0]);
			strcpy(arr->data[0].name, tokens[1]);



			fgets(buff, 1000, input);
			if (buff == NULL)
				break;
			buff[strlen(buff) - 1] = '\0';
			tokens = getT(buff, ",");

			arr->data[1].n = atoi(tokens[0]);
			strcpy(arr->data[2].name, tokens[1]);


			fgets(buff, 1000, input);
			if (buff == NULL)
				break;
			buff[strlen(buff) - 1] = '\0';
			tokens = getT(buff, ",");

			arr->data[0].n = atoi(tokens[0]);
			strcpy(arr->data[0].name, tokens[1]);


			/*if (i != 0)
			{
			indexNode[j].key[i - 1] = arr[3 * i].data[0].n;

			//printf("key %d: %d\n", i - 1, indexNode->key[i - 1]);
			}
			indexNode[j].pageIds[i] = 128 * i;
			*/

			fwrite(arr, sizeof(struct dataPage), 1, fp);

		}
	}




	fclose(fp);
	//fclose(input);


	int size = 0;

	FILE* outputWrite = fopen("out1.txt", "ab");
	FILE* outputRead = fopen("out1.txt", "rb");


	for (int i = 0; i < 16; i++)
	{
		struct indexPage * indexNode = (struct indexPage*)malloc(sizeof(struct indexPage));


		for (int j = 0; j < 16; j++)
		{
			struct dataPage* dataNode = (struct dataPage*)malloc(sizeof(struct dataPage));

			fread(dataNode, sizeof(struct dataPage), 1, outputRead);

			if (j != 0)
			{
				indexNode->key[j - 1] = dataNode->data[0].n;


				printf("key for %d %d: %d \n", i, j, indexNode->key[j - 1]);
			}

			indexNode->pageIds[j] = size;
			size += 128;
		}

		fwrite(indexNode, sizeof(struct indexPage), 1, outputWrite);
	}
		printf("offset: %d\n", size);

		fclose(outputWrite);
		fclose(outputRead);

		
		outputRead = fopen("out1.txt", "rb");  fseek(outputRead, 256 * 128, SEEK_SET);
		outputWrite = fopen("out1.txt", "ab");



		
		//fseek(output, 0, SEEK_SET);


		struct indexPage* secondLvlIndexNode = (struct indexPage*)malloc(sizeof(struct indexPage));
		for (int i = 0; i < 16; i++)
		{
			struct indexPage * indexNode = (struct indexPage*)malloc(sizeof(struct indexPage));

			fread(indexNode, sizeof(struct indexPage), 1, outputRead);

			if(i != 0)
			{
				secondLvlIndexNode->key[i - 1] = indexNode->key[0];
				printf("second level key for %d : %d\n", i, secondLvlIndexNode->key[i - 1]);
			}

			secondLvlIndexNode->pageIds[i] = size;
			size += 128;
		}

		fwrite(secondLvlIndexNode, sizeof(struct indexPage), 1, outputWrite);


		fclose(outputRead);
		fclose(outputWrite);

		//fclose(input);

		/*input = fopen("out1.txt", "rb");

		buff = (char*)malloc(128);
		fread(buff,128,1,input);

		struct dataPage* a = (struct dataPage*)buff;

		printf("%d",a->data[1].n);

		fclose(input);*/

		getchar();


		return 0;
	}
