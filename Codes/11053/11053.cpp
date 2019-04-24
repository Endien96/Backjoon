#include <iostream>
using namespace std;

int arr[1001];
int lst[1001];

int main(){
    int n;
    int max = 0;
    cin >> n;
 
    for (int i = 1; i <= n; i++)
        cin >> lst[i];
 
    for (int i = 1; i <= n; i++)
    {
        int min = 0;
        for (int j = 0; j < i; j++){
            if (lst[i]>lst[j]){
                if (min < arr[j])
                    min = arr[j];
            }
        }
        arr[i] = min + 1;
        if (max < arr[i])
            max = arr[i];
    }
 
    printf("%d\n", max);
    
    return 0;
}
