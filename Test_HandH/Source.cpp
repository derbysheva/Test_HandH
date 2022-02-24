#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool currentSizeExists(vector<int> &lastsizes, int position, int currentsize)
{
	bool result = false;
	for (int i = 0; i < position; i++)
		if (lastsizes[i] == currentsize) { result = true; break; }
	return result;
}
void createCurrentArray(int newarraysize, vector <double> &newarray )
{
	srand(static_cast<unsigned int>(time(0)));
	double maxvalue = 1000.;
	double minvalue = 0.;
	for (int i=0; i<newarraysize; i++)
		newarray[i] = minvalue + (double) (rand()) / ((double) (RAND_MAX / (maxvalue - minvalue)));
}
vector <vector<double>> createNarrayandSort(int n)
{
	int currentsize, minsize = 1;
	int maxsize = n * 100;
	vector <int> lastsize;
	vector <vector <double>> arr;

	arr.resize(n);
	lastsize.resize(n);
	srand(static_cast<unsigned int>(time(0)));
	lastsize[0] = minsize + rand() % maxsize;
	//creating of n-array
	arr[0].resize(lastsize[0]);
	createCurrentArray(lastsize[0], arr[0]);
	for (int i = 1; i < n; i++)
	{
		currentsize = minsize + rand() % maxsize;
		while (currentSizeExists(lastsize, i, currentsize)) currentsize = minsize + rand() % maxsize;
		lastsize[i] = currentsize;
		arr[i].resize(currentsize);
		createCurrentArray(currentsize, arr[i]);
	}
	//sorting of n-array
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) sort(arr[i].begin(), arr[i].end());
		else sort(arr[i].begin(), arr[i].end(), greater<int>());
	}
	return arr;
}

void main()
{
	int n;
	vector <vector <double>> resultArray;
	bool success = false;
	while(!success)
	{
		cout << "Enter natural number n " << endl;
		cin >> n;
		cin.ignore(INT_MAX, '\n');
		if (cin.good()) 
		{ 
			if (n > 0) 
				success = true; 
		}
		else
		{
			cout << "You entered the wrong number. Try again" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	} 
	if (success)
	{
		resultArray = createNarrayandSort(n);
		//output of sorted array
		for (auto cur : resultArray)
		{
			for (auto el : cur)
				cout << el << "\t";
			cout << endl << endl;
		}
	}
}