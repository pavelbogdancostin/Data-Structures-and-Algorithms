#pragma once

// se parcurge consecutiv, usor pentru liste
template<typename DT>
void selectdirSort(DT* t, int n){
	int i, j, k;
	DT tmp;
	for (i = 0; i < n; i++){
		j = i;
		for (k = i; k < n; k++) // cautare minim
			if (t[j] > t[k])
				j = k;
		tmp = t[j]; // interschimbare
		t[j] = t[i];
		t[i] = tmp;
	}
}

template<class DT>
void insertdirSort(DT* t, int n){
	int i, j;
	DT tmp;
	for (i = 1; i < n; i++){
		tmp = t[i];
		for (j = i; j > 0; j--){
			if (t[j - 1] > tmp)
				t[j] = t[j - 1];
			else
				break;
		}
		t[j] = tmp;
	}
}

template<class DT>
void inserBinSort(DT* t, int n)
{
	int i, j, m, in, sf;
	DT tmp;
	for (i = 1; i < n; i++)
	{
		tmp = t[i];
		in = 0;
		sf = i - 1;
		m = (in + sf) / 2;
		while (in <= sf)//cautare binara
		{
			if (t[m] > tmp)
				sf = m - 1;
			else
				in = m + 1;
			m = (in + sf) / 2;
		}
		//insertia
		for (j = i - 1; j >= in; j--)
			t[j + 1] = t[j];
		t[in] = tmp;
	}
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high){
	int pivot = arr[high]; // pivot  
	int i = low - 1; // Index of smaller element  

	for (int j = low; j <= high - 1; j++){
		// If current element is smaller than the pivot  
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element  
			{ int tmp = arr[j]; arr[j] = arr[i]; arr[i] = tmp; }
		}
	}
	{ int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp; }
	//swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high){
	if (low < high){
		/* pi is partitioning index, arr[p] is now at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

template<class DT>
void quickSort_curs(DT* t, int n){
	int i = 0, j = n - 1;
	DT pivot, tmp;
	if (n == 1)
		return;
	pivot = t[n / 2];
	while (i < j)
	{
		while (t[i] < pivot)
			i++;
		while (t[j] > pivot)
			j--;
		if (i < j)
		{
			tmp = t[j];
			t[j] = t[i];
			t[i] = tmp;
		}
	}
	if (i > j)
		i = j;
	if (i > 0)
		quickSort_curs(t, i);
	if (n - i > 0)
		quickSort_curs(&t[i], n - i);
}

template<class DT>
void mergeSort(DT* vect, int dim){
	int d1 = dim / 2;
	int d2 = dim - d1;
	int i1, i2, j;
	if (dim > 1)
	{
		mergeSort(vect, d1);
		mergeSort(&vect[d1], d2);
	}
	else
		return;
	DT* tmp = new DT[dim];
	i1 = 0;
	i2 = 0;
	j = 0;
	DT* vect2 = &vect[d1];
	while (i1 < d1 && i2 < d2)
	{
		if (vect[i1] < vect2[i2])
		{
			tmp[j] = vect[i1];
			i1++;
		}
		else
		{
			tmp[j] = vect2[i2];
			i2++;
		}
		j++;
	}
	if (i1 == d1)// s-a ajuns la sfârșitul lui vect1; se descarcă restul lui vect2
		for (; j < dim; j++, i2++)
			tmp[j] = vect2[i2];
	else // s-a ajuns la sfârșitul lui vect2; se descarcă restul lui vect1
		for (; j < dim; j++, i1++)
			tmp[j] = vect[i1];
	for (j = 0; j < dim; j++)//copiază subșirul ordonat din tmp in vectorul inițial
		vect[j] = tmp[j];
	delete[] tmp;
}

template<class DT>
void bubbleSort(DT* t, int n)
{
	int i, j;
	bool sort = false;
	DT tmp;
	while (!sort)
	{
		sort = true;
		for (i = 0; i < n; i++)
			if (t[i] > t[i + 1])
			{
				tmp = t[i];
				t[i] = t[i + 1];
				t[i + 1] = tmp;
				sort = false;
			}
		n--;
	}
}

template<class DT>
void shellSort(DT* t, int n)
{
	int i, j, inc;
	DT tmp;
	for (inc = n / 2; inc > 0; inc /= 2)
		for (i = inc; i < n; i++)
			for (j = i - inc; j >= 0; j -= inc)
			{
				if (t[j + inc] < t[j])
				{
					tmp = t[j + inc];
					t[j + inc] = t[j];
					t[j] = tmp;
				}
				else
					break;
			}
}

template<class DT>
void shakeSort(DT* t, int n)
{
	int j, st = 0, dr = n - 1, k = n - 1;
	DT tmp;
	bool sortat = false;
	while (!sortat && st <= dr){
		sortat = true;
		for (j = dr; j >= st; j--)
			if (t[j] > t[j + 1]){
				tmp = t[j]; //switch
				t[j] = t[j + 1];
				t[j + 1] = tmp;
				k = j;//index ultim switch
				sortat = false;
			}
		st = k + 1;
		for (j = st; j <= dr; j++)
			if (t[j] > t[j + 1]){
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
				k = j;
				sortat = false;
			}
		dr = k - 1;
	}
}

// heap


//bst

