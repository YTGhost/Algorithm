#include <iostream>

int n;
long count;
const int N = 100010;
int q[N], temp[N];

void merge(int q[], int l, int r)
{
    if(l >= r) return;
    
    int mid = (l + r) >> 1;
    
    merge(q, l, mid);
    merge(q, mid+1, r);
    
    int k = 0, i = l, j = mid+1;
    
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]){
            temp[k++] = q[i++];
        } 
        else{
            count += mid - i + 1;
            temp[k++] = q[j++];
        }
    }
    
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    
    for(int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    merge(q, 0, n-1);
    
    printf("%ld", count);
    
    return 0;
}