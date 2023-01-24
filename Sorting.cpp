#include <iostream>
using namespace std;

class Sort
{
public:
    void swap(int ar[], int a, int b)
    {
        int temp = ar[a];
        ar[a] = ar[b];
        ar[b] = temp;
    }

    void SelectionSort(int ar[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (ar[j] < ar[min])
                    min = j;
            }
            swap(ar, i, min);
        }
    }
    void BubbleSort(int ar[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (ar[j] > ar[j + 1])
                    swap(ar, j, j + 1);
            }
        }
    }
    void InsertionSort(int ar[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int key = ar[i];

            while (j >= 0 && key < ar[j])
            {
                ar[j + 1] = ar[j];
                j--;
            }
            ar[j + 1] = key;
        }
    }
    void Merge(int ar[], int start, int mid, int end)
    {
        int M[end - start + 1];
        int i1 = start;
        int i2 = mid + 1;
        int t = 0, i, j;
        while (i1 <= mid && i2 <= end)
        {
            if (ar[i1] <= ar[i2])
            {
                M[t] = ar[i1];
                i1++;
                t++;
            }
            else
            {
                M[t] = ar[i2];
                i2++;
                t++;
            }
        }
        while (i1 <= mid)
        {
            M[t] = ar[i1];
            t++;
            i1++;
        }
        while (i2 <= end)
        {
            M[t] = ar[i2];
            t++;
            i2++;
        }
        for (i = 0, j = start; i < end - start + 1; j++, i++)
        {
            ar[j] = M[i];
        }
    }
    void MergeSort(int ar[], int start, int end)
    {
        // Divides the array:
        int mid;
        if (start < end)
        {
            mid = (start + end) / 2;
            MergeSort(ar, start, mid);
            MergeSort(ar, mid + 1, end);
            Merge(ar, start, mid, end);
        }
    }

    void quickSort(int ar[], int l, int h)
    {
        if (l >= h)
            return;

        int start = l;
        int end = h;
        int mid = (end - start) / 2;
        int piv = ar[mid];
        while (start <= end)
        {
            while (ar[start] < piv)
                start++;
            while (ar[end] > piv)
                end--;
            if (start <= end)
            {
                // Violation: Swap start and end
                swap(ar, start, end);
                start++;
                end--;
            }
        }
        // Now pivot is in correct index:
        // Now end < start
        quickSort(ar, l, end);
        quickSort(ar, start, h);
    }
    void heapify(int ar[], int ind, int n)
    {
        int largest = ind;
        int left = 2 * ind;
        int right = 2 * ind + 1;
        // Checking overflow and condition:
        if (left <= n && ar[left] > ar[largest])
            largest = left;
        if (right <= n && ar[right] > ar[largest])
            largest = right;
        if (largest != ind)
        {
            swap(ar, ind, largest);
            heapify(ar, largest, n);
        }
    }
    void buildHeap(int ar[], int n)
    {
        for (int i = n / 2; i >= 1; i--)
            heapify(ar, i, n);
    }
    void heapSort(int ar[], int n)
    {
        buildHeap(ar, n);
        for (int i = n; i >= 2; i--)
        {
            swap(ar, i, 1);
            heapify(ar, 1, i - 1);
        }
    }
};

void Display(int ar[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int ar[] = {2, 1, 8, 6, 5};
    int ar[] = {0, 5, 4, 3, 2, 1};
    Sort s;
    Display(ar, 5);
    s.heapSort(ar, 5);
    Display(ar, 5);
    return 0;
}