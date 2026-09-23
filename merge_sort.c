#include <stdio.h>

typedef struct
{
    char id[5];
    int weight;
} Package;

int comparisons = 0;

void merge(Package a[], int low, int mid, int high)
{
    Package temp[50];

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        comparisons++;

        /* <= preserves the original order of equal weights */
        if (a[i].weight <= a[j].weight)
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(Package a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void display(Package a[], int n)
{
    int i;

    printf("Package ID\tWeight\n");

    for (i = 0; i < n; i++)
    {
        printf("%s\t\t%d\n", a[i].id, a[i].weight);
    }
}

int main()
{
    Package a[] =
    {
        {"P1", 20},
        {"P2", 15},
        {"P3", 20},
        {"P4", 10},
        {"P5", 15},
        {"P6", 20},
        {"P7", 25},
        {"P8", 10}
    };

    int n = 8;

    printf("Original Packages:\n");
    display(a, n);

    mergeSort(a, 0, n - 1);

    printf("\nAfter Merge Sort:\n");
    display(a, n);

    printf("\nNumber of comparisons = %d\n", comparisons);

    return 0;
}
