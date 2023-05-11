#include <iostream>
using namespace std;

int abrar[38];
int cmp_count = 0; 
int mov_count = 0; 
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nmaksimum panjang array adalah 20" << endl;
	}

	cout << "\n==================" << endl;
	cout << "\nenter array element" << endl;
	cout << "\n==================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> abrar[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = abrar[x];
	abrar[x] = abrar[y];
	abrar[y] = temp;
}

void m_short(int low, int high)
{
	int pivot, i, ab;
	if (low > high)													
		return;

	pivot = abrar[low];													

	i = low + 1;														
	ab = high;															

	while (i <= ab)												
	{
	
		while ((abrar[i] <= pivot) && (i <= high))						
		{
			i++;														
			cmp_count++;
		}
		cmp_count++;
		
		while ((abrar[ab] > pivot) && (ab >= low))						
		{
			ab--;														
			cmp_count++;
		}
		cmp_count++;

		
		if (i < ab)	
		{
			swap(i, ab);
			mov_count++;
		}
	}

	if (low < ab)														
	{
		swap(low, ab);
		mov_count++;
	}
	
	m_short(low, ab - 1);												

	m_short(ab + 1, high);												


}


void display() {
	cout << "\n------------------" << endl;
	cout << "sorted array" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << abrar[i] << " ";
	}

	cout << "\n\Number of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{

	input();
	m_short(0, n - 1);
	display();
	system("pause");

	return 0;
}