#include <iostream>
#include <string.h>
using namespace std;

int checkcharacter(int args, char** letter)
{
	int value;
	int sum = 0;
	for (int count = 2; count <= args - 1; count++)
	{
		string word = letter[count];

		for (int i = 0; i <= (word.length() - 1); i++)
		{
			value = letter[count][i];
			if ((value == 43 || value == 45) && (word.length() == 1))
			{
				sum = sum + 1;
			}
			else if (((48 <= value) && (value <= 57)) || (value == 43) || (value == 45))
				sum = sum;
			else
			{
				sum = sum + 1;
			}
		}
	}
	return sum;

}

int checknumber(int args, char** letter)
{
	int sum = 0;
	int value;
	for (int count = 2; count <= args - 1; count++)
	{
		string word = letter[count];
		for (int i = 0; i <= (word.length() - 1); i++)
		{
			value = letter[count][i];

			if ((48 <= value) && (value <= 57))
				sum = sum + 1;
		}
	}
	return sum;
}

int checkcertain(char* letter)
{
	int value;
	int sum = 0;
	string word = letter;

	for (int i = 0; i <= (word.length() - 1); i++)
	{
		value = letter[i];

		if ((value == 43 || value == 45) && (word.length() == 1))
		{
			sum = sum + 1;
		}
		else if (((48 <= value) && (value <= 57)) || (value == 43) || (value == 45))
			sum = sum;
		else
		{
			sum = sum + 1;
		}
	}

	return sum;
}

int checksmallletter(char letter)
{
	int value;
	int sum = 0;
	char word = letter;
	value = word;
	if ((97 <= value) && (value <= 122))
		sum = sum;
	else
	{
		sum = sum + 1;
	}

	return sum;
}
////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
  if ((argc == 1) || ((string(argv[1]) != "print") && (string(argv[1]) != "reverse") && (string(argv[1]) != "upper") && (string(argv[1]) != "shuffle") && (string(argv[1]) != "shuffleStatement") && (string(argv[1]) != "delete") && (string(argv[1]) != "middle") && (string(argv[1]) != "add") && (string(argv[1]) != "random")))
  {
		cout << "Undefined Command";
  }
  else
  { 
	if (argc == 1 || argc == 2)
	{
		cout << "Incorrect Number of Arguments";
	}

	else
	{
		if (string(argv[1]) == "print")
		{
			for (int count = 2; count <= argc - 1; count++)
				cout << argv[count] << " ";

		}
		////////////////////////////////////////////////////
		else if (string(argv[1]) == "reverse")
		{
			for (int count = argc - 1; count >= 2; count--)
				cout << argv[count] << " ";

		}
		///////////////////////////////////////////////////
		else if (string(argv[1]) == "upper")
		{

			for (int count = 2; count <= argc - 1; count++)
			{
				string word = argv[count];
				int length = word.length();

				for (int i = 0; i <= length - 1; i++)
				{
					int value = checksmallletter(argv[count][i]);
					if (value == 0)
					{
						argv[count][i] = argv[count][i] - 32;
					}
				}

				cout << argv[count] << " ";

			}

		}
		//////////////////////////////////////////////////
		else if (string(argv[1]) == "shuffle")
			if (argc > 3)
			{
				cout << "Incorrect Number of Arguments";
			}
			else
			{
				int length;
				for (int count = 2; count <= argc - 1; count++)
				{
					string word = argv[count];
					length = word.length();
					if (length == 1)
						cout << argv[count];
					else
					{
						for (int i = 0; i <= (length / 2 - 1); i++)
						{
							char k;
							k = argv[count][2 * i];
							argv[count][2 * i] = argv[count][2 * i + 1];
							argv[count][2 * i + 1] = k;
						}
						cout << argv[count] << " ";
					}
				}

			}
		///////////////////////////////////////////////////
		else if (string(argv[1]) == "shuffleStatement")
		{
			for (int count = 1; count <= (argc / 2 - 1); count++)
			{

				char* k;
				k = argv[count * 2];
				argv[count * 2] = argv[count * 2 + 1];
				argv[count * 2 + 1] = k;



			}
			for (int count = 2; count <= argc - 1; count++)
			{
				cout << argv[count] << " ";
			}
		}
		///////////////////////////////////////////////////
		else if (string(argv[1]) == "delete")
		{
			int i;
			i = atoi(argv[2]) + 2;
			if (argc == 3)
			{
				cout << "Incorrect Number of Arguments";
			}
			else if (i <= 2)
			{
				cout << "Incorrect Data Type";
			}
			else if (i > argc - 1)
			{
				cout << "Incorrect Number of Arguments";
			}
			else
			{
				int value = checkcertain(argv[2]);
				if (value != 0)
				{
					cout << "Incorrect Data Type";
				}
				else
				{
					for (int count = 3; count <= i - 1; count++)
					{
						cout << argv[count] << " ";
					}
					for (int count = i; count <= argc - 1; count++)
					{
						argv[count] = argv[count + 1];
						cout << argv[count + 1] << " ";
					}
				}
			}

		}
		///////////////////////////////////////////////////
		else if (string(argv[1]) == "middle")
		{
			int k = argc % 2;
			switch (k)
			{
			case 0:
			{
				cout << argv[(argc / 2)] << " " << argv[(argc / 2) + 1];
				break;
			}
			case 1:
			{
				cout << argv[(argc / 2) + 1];
				break;
			}

			}

		}
		/////////////////////////////////////////////////
		else if (string(argv[1]) == "add")
		{
			int value = checkcharacter(argc, argv);
			if (value != 0)
			{
				cout << "Incorrect Data Type";
			}
			else
			{
				int sum = 0;
				for (int count = 2; count <= argc - 1; count++)
				{
					sum = atoi(argv[count]) + sum;
				}
				cout << sum;
			}
		}
		///////////////////////////////////////////////////
		else if (string(argv[1]) == "random")
		{
			if (argc != 6)
			{
				cout << "Incorrect Number of Arguments";
			}
			else
			{
				int value = checkcharacter(argc, argv);
				if (value != 0)
				{
					cout << "Incorrect Data Type";
				}
				else
				{
					int seed = atoi(argv[argc - 1]);
					int start = atoi(argv[3]);
					int end = atoi(argv[4]);
					int length = atoi(argv[2]);

					if ((start > end) || (length <= 0))
					{
						cout << "Incorrect Data Type";
					}
					else
					{
						srand(seed);
						for (int count = 1; count <= length; count++)
						{
							int random = (rand() % (end - start + 1)) + start;
							cout << random << " ";
						}
					}
				}
			}
		}
	}
  }
  return 0;
}
