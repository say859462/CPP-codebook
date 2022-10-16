int partition(int l, int r)
{
    int pivot = num[r];
    int i = l;
    for (int j = l; j < r; j++)
    {
        if (num[j] < pivot)
        {
            swap(num[j], num[i]);
            i++;
        }
    }
    swap(num[i], num[r]);
    return i;
}
void quickSort(int l, int r)
{
    if (l < r)
    {
        int j = partition(l, r);
        quickSort(l, j - 1);
        quickSort(j + 1, r);
    }
    return;
}
