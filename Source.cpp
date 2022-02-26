#include<iostream>

#include<fstream>

using namespace std;

bool checkcount(char* arr, char* arr2, int arrsize)
{

	int count = 0;
	for (int i = 0; i < arrsize; i++)
	{
		if (arr[i] == arr2[i])
		{
			count++;
		}

	}
	if ((arrsize-1) == count)
	{
		return true;
	}
	else 
	{
		return false;
	}

}

void checkans(char* arr, int arrsize)
{
	int chance = 5;
	char guess;
	char* arr2 = new char[arrsize];
	for (int j = 0; j < arrsize; j++)
	{
		arr2[j] = '-';
	}
	
	bool flag;

	while(chance!=0)
	{
		
		flag = false;

		cin >> guess;
		
		for (int j = 0; j < arrsize; j++)
		{

			if (guess == arr[j])
			{
				
				arr2[j] = arr[j];
				flag = true;
			}

		}

		for (int k = 0; k < arrsize-1; k++)
		{
			cout << arr2[k]<<" ";

		}
		cout << endl;

		bool ans = checkcount(arr, arr2, arrsize);

		if (ans == true)
		{
			cout << "You win\n";
			break;
		}


		if (flag == true)
		{
			cout << "You have "<<chance<<" chances remaining\n";
		
		}
		else
		{
			chance--;

			cout << "You have " << chance << " chances remaining\n";
			
			if (chance == 0)
			{
				cout << "You Lost\n";

			}
		}
	}

}

int main()
{
	cout << "				Welcome to Hangman\n";


	ifstream fin;
	
	int arrsize;

	fin.open("input.txt", ios::in);

	fin >> arrsize;
	cout << "Character size = " << arrsize << endl;
	arrsize++;
	
	char* arr = new char[arrsize];
	
	for (int j = 0; j < arrsize - 1; j++)
	{
		fin >> arr[j];
	}

	fin.close();

	cout << "You have 5 chances to guess the word\n";


	checkans(arr, arrsize);

	system("pause");

	return 0;


}