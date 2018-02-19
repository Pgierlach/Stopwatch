#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <dos.h>
#include <vector>

using namespace std;

void PrintLaps(vector<double>);
void MainMenu();

int main()
{
	clock_t begin, end, storage;
	double duration = 0;
	char input;
	vector<double> laps;
	bool running = false;
	bool exit = false;
	bool first = true;
	while (exit == false)
	{
		system("cls");
		MainMenu();
		PrintLaps(laps);

		if (running == true)
		{
			end = clock();
			duration = (double)(end - begin) / CLOCKS_PER_SEC;					
		}
		cout << duration << endl;

		if (kbhit())
		{
			input = getch();
			fflush(stdin);
			switch (input)
			{
				case '1':
				{
					if (running == false)
					{
						if (first == false)
						{
							begin = clock() + begin-end;
						}
						else
						{
							begin = clock();
							first = false;
						}						
						running = true;						
					}						
					break;
				}
				case '2':
				{
					if (running == true)
					{
						if (laps.size() == 10)
						{
							laps.erase(laps.begin());
						}
						laps.push_back(duration);						
					}
					break;
				}
				case '3':
				{
					if (running == true)
					{						
						end = clock();
						running = false;
						
					}	
					break;
				}
				case '4':
				{
					begin = clock();
					duration = 0;
					break;
				}
				case '5':
				{
					exit = true;
					break;
				}
			}
		}
		Sleep(35);
	}
	return 0;
}

void MainMenu()
{
	cout << "1. Start" << endl;
	cout << "2. Lap" << endl;
	cout << "3. Stop" << endl;
	cout << "4. Reset" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
}

void PrintLaps(vector<double> laps)
{
	for (int i = 0; i < laps.size(); i++)
	{
		cout << i + 1 << ".\t" << laps[i] << endl;
	}
	cout << endl;
}