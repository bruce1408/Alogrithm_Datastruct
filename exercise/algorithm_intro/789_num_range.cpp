long long result = 0;
void mergeSort(vector<int>&res, vector<int>&temp ,int l, int r)
{
    if(l>=r) return ;
    int mid = (l+r)>>1;
    mergeSort(res, temp, l, mid);
    mergeSort(res, temp, mid+1, r);
    int k=0, i =l, j = mid+1;
    while(i<=mid && j<=r)
    {
        if(res[i]<=res[j]) temp[k++] = res[i++];
        else
        {
            temp[k++] = res[j++];
            result+=mid - i + 1;
        }
    }
    while(i<=mid) temp[k++] = res[i++];
    while(j<=r) temp[k++] = res[j++];
    for(int i=0,j=l; j<=r; i++, j++)
    {
        res[j] = temp[i];
    }
}