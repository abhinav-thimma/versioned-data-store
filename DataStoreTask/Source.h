#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;


struct versionNode
{
	int version;
	int val;
};


int commit = 0;
int noOfCols = 2;
/*unordered_map<int,*/vector<vector<struct versionNode>> finalRow;


class Transaction
{
	vector<vector<struct versionNode>> row;
	int commitNo;
	int *colsUpdated;
	
	public:

	Transaction()
	{
		commitNo = 0;
		colsUpdated = (int*)malloc(sizeof(int)*noOfCols);

		for (int i = 0; i < noOfCols; i++)
		{
			vector<struct versionNode> a = finalRow[i];
			row.push_back(a);
		}
	}

	int* read(/*int rowNum*/)
	{

		/*vector<vector<struct versionNode>> *row = &table[rowNum];*/

		int * rowData = (int*)malloc(sizeof(int)*noOfCols);
		for (int i = 0; i < noOfCols  && i < row.size() ; i++)
		{
			for (int j = (finalRow).at(i).size() - 1; j >= 0; j--)
			{
				if (j <= commitNo)
				{
					rowData[i] = (finalRow)[i][j].val;
					break;
				}
			}
		}

		return rowData;
	}

	int* readLocal()
	{
		int * rowData = (int*)malloc(sizeof(int)*noOfCols);
		for (int i = 0; i < noOfCols && i < row.size(); i++)
		{
			for (int j = (row).at(i).size() - 1; j >= 0; j--)
			{
				if (j <= commitNo)
				{
					rowData[i] = (row)[i][j].val;
					break;
				}
			}
		}

		return rowData;
	}

	void write(int *cols, int *colValues, int noOfUpdateCols,/* int rowNum,*/ int version)
	{
		//vector<vector<struct versionNode>> *row = &table[rowNum];

		for (int i = 0; i < noOfUpdateCols; i++)
		{
			int col = cols[i];

			struct versionNode temp;// = (struct versionNode*)malloc(sizeof(struct versionNode));
			temp.val = colValues[i];
			temp.version = version;

			(row)[col].push_back(temp);

			//saving the updated row in colsUpdated bit vector
			colsUpdated[col] = 1;
		}

		
		
		commitNo = version;
	}


	void commit()
	{

		int* updatedRowData = readLocal();
		for (int i = 0; i < noOfCols; i++)
		{
			if (colsUpdated[i] == 1)
			{
				finalRow[i][0].val = updatedRowData[i];
			}
		}
	}
};


int main2()
{



	//vector<vector<struct versionNode>> row;

	struct versionNode* arr = (struct versionNode*)malloc(sizeof(struct versionNode*) * 2);
	arr[0].version = 0;  arr[0].val = 1;
	arr[1].version = 0;  arr[1].val = 2;

	vector<struct versionNode> a;
	a.push_back(arr[0]);

	vector<struct versionNode> b;
	b.push_back(arr[1]);


	finalRow.push_back(a);
	finalRow.push_back(b);





	Transaction t1;
	Transaction t2;


	int* colIndices = (int*)malloc(sizeof(int)*2);
	int* colValues = (int*)malloc(sizeof(int)*2);

	colIndices[0] = 0;	colIndices[1] = 1;
	colValues[0] = 5;	colValues[1] = 10;

	t1.write(colIndices, colValues, 2, 1);
	t1.commit();


	colIndices[0] = 0;	colIndices[1] = 1;
	colValues[0] = 1;	colValues[1] = 2;

	t2.write(colIndices, colValues, 1, 2);
	t2.commit();

	int* rowData = t1.read();

	for (int i = 0; i < noOfCols; i++)
		printf("%d \t", rowData[i]);
 
	getchar();

	return 0;
}






void init()
{

	/*
	//setting up the 
	vector<vector<struct versionNode>> row;

	struct versionNode* arr = (struct versionNode*)malloc(sizeof(struct versionNode*) * 2);
	arr[0].version = 0;  arr[0].val = 1;
	arr[1].version = 0;  arr[1].val = 2;

	vector<struct versionNode> a;
	a.push_back(arr[0]);

	vector<struct versionNode> b;
	b.push_back(arr[1]);


	row.push_back(a);
	row.push_back(b);

	//table[0] = row;


	Transaction t1;
	Transaction t2;

	int* rowData = t1.read(0);
	for (int i = 0; i < noOfCols; i++)
	{
		printf("%d \t", rowData[i]);
	}

	int* col = (int*)malloc(sizeof(int));
	int* colValues = (int*)malloc(sizeof(int));

	col[0] = 0;
	colValues[0] = 5;

	t2.write(col, colValues, 1, 0, 1);


	rowData = t1.read(0);
	for (int i = 0; i < noOfCols; i++)
	{
		printf("%d \t", rowData[i]);
	}

	*/
}