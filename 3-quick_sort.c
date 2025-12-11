#include "sort.h"

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: Array to sort
 * @low: Starting index of partition
 * @high: Ending index of partition
 * @size: Full size of the array (for printing)
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low, j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high)
    {
        temp = array[i];
        array[i] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i);
}

/**
 * quick_sort_recursive - Recursively applies quicksort
 * @array: Array to sort
 * @low: Starting index of partition
 * @high: Ending index of partition
 * @size: Full size of array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array using Quick Sort (Lomuto partition)
 * @array: Array to sort
 * @size: Number of elements
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
