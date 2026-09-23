#include <stdio.h>

typedef struct
{
    char id[5];
    int weight;
} Package;

int comparisons = 0;

void swap(Package *a, Package *b)
{
    Package temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Package a[], int low, int high)
{
    int pivot = a[high].weight;
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        comparisons++;

        if (a[j].weight <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(Package a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
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

    quickSort(a, 0, n - 1);

    printf("\nAfter Quick Sort:\n");
    display(a, n);

    printf("\nNumber of comparisons = %d\n", comparisons);

    return 0;
}
