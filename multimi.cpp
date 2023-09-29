#include <iostream>

using namespace std;

#define MIN_N 1
#define MAX_N 1000
#define MIN_M 1
#define MAX_M 1000
#define MAX_NR 1000

void rezolvare_metoda1(int n, int m);
void rezolvare_metoda2(int n, int m);

int main()
{
	int n;

	cout << "n = "; cin >> n;

	if (n < MIN_N || n > MAX_N)
	{
		cout << "Eroare valoare n\n";
		return 1;
	}

	int m;

	cout << "m = "; cin >> m;

	if (m < MIN_M || m > MAX_M)
	{
		cout << "Eroare valoare m\n";
		return 2;
	}

	// rezolvare_metoda1(n, m);

	rezolvare_metoda2(n, m);

	return 0;
}

void rezolvare_metoda1(int n, int m)
{
	int uz[MAX_NR+1], i;

	for (i = 0; i <= MAX_NR; i++)
	{
		uz[i] = 0;
	}

	int a[n];

	cout << "Elementele multimii A\n";

	for (i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = "; cin >> a[i];

		while (uz[a[i]])
		{
			cout << "Eroare: Acest numar exista deja in multimea A.\n";
			cout << "a[" << i << "] = "; cin >> a[i];
		}

		uz[a[i]] = 1;
	}
	
	for (i = 0; i <= MAX_NR; i++)
	{
		uz[i] = 0;
	}

	int b[m];

	cout << "\nElementele multimii B\n";

	for (i = 0; i < m; i++)
	{
		cout << "b[" << i << "] = "; cin >> b[i];

		while (uz[b[i]])
		{
			cout << "Eroare: Acest numar exista deja in multimea B.\n";
			cout << "b[" << i << "] = "; cin >> b[i];
		}

		uz[b[i]] = 1;
	}
	
	int min_nm = n < m ? n : m;

	int anb[min_nm], nr_anb = 0, j;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				anb[nr_anb++] = a[i];
			}
		}
	}

	cout << "\nAnB = ";

	for (i = 0; i < nr_anb; i++)
	{
		cout << anb[i] << " ";
	}

	int aub[n+m], nr_aub = 0;

	for (i = 0; i < nr_anb; i++)
	{
		aub[nr_aub++] = anb[i];
	}
	
	bool ok;

	for (i = 0; i < n; i++)
	{
		ok = 1;

		for (j = 0; j < nr_anb && ok; j++)
		{
			if (a[i] == anb[j])
			{
				ok = 0;
			}
		}

		if (ok)
		{
			aub[nr_aub++] = a[i];
		}
	}	

	for (i = 0; i < m; i++)
	{
		ok = 1;

		for (j = 0; j < nr_anb && ok; j++)
		{
			if (b[i] == anb[j])
			{
				ok = 0;
			}
		}

		if (ok)
		{
			aub[nr_aub++] = b[i];
		}
	}

	cout << "\nAuB: ";

	for (i = 0; i < nr_aub; i++)
	{
		cout << aub[i] << " ";
	}

	cout << "\n";
}

void rezolvare_metoda2(int n, int m)
{
	//TODO
}
