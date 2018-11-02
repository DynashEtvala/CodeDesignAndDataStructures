#pragma once
#include <vector>

using std::vector;

template<typename t>
void Merge(t * arr, size_t p, size_t q, size_t r)
{
	size_t LeftEnd = q - p + 1;
	size_t RightEnd = r - q;

	t * LeftArray = new int[LeftEnd];
	t * RightArray = new int[RightEnd];

	for (int i = p; i <= q; i++)
	{
		LeftArray[i - p] = arr[i];
	}
	for (int i = q + 1; i <= r; i++)
	{
		RightArray[i - q] = arr[i];
	}

	int i = 0;
	int j = 0;
	for (int k = p; p <= r; k++)
	{
		if (j >= RightEnd || (i < LeftEnd && LeftArray[i] <= RightArray[j]))
		{
			arr[k] = LeftArray[i];
			i++;
		}
		else
		{
			arr[k] = RightArray[j];
			j++;
		}
	}
	delete LeftArray;
	delete RightArray;
};

template <typename t>
void MergeSort(t * arr, size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = (p + r) / 2;
		MergeSort<t>(arr, p, q);
		MergeSort<t>(arr, q + 1, r);
		Merge<t>(arr, p, q, r);
	}
};

template<typename t>
void Merge(vector<t> arr, size_t p, size_t q, size_t r)
{
	size_t LeftEnd = q - p + 1;
	size_t RightEnd = r - q;

	vector<t> LeftArray;
	LeftArray.reserve(LeftEnd);
	vector<t> RightArray;
	RightArray.reserve(RightEnd);

	for (int i = p; p < q; i++)
	{
		LeftArray[i - p] = arr[i];
	}
	for (int i = q; q <= r; i++)
	{
		LeftArray[i - q] = arr[i];
	}

	int i = 0;
	int j = 0;
	for (int k = p; p <= r; k++)
	{
		if (j >= RightEnd || (i < LeftEnd && LeftArray[i] <= RightArray[j]))
		{
			arr[k] = LeftArray[i];
			i++;
		}
		else
		{
			arr[k] = RightArray[j];
			j++;
		}
	}
};

template <typename t>
void MergeSort(vector<t> arr, size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = (p + r) / 2;
		MergeSort<t>(arr, p, q);
		MergeSort<t>(arr, q + 1, r);
		Merge<t>(arr, p, q, r);
	}
};