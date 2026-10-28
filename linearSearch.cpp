#include <iostream>
using namespace std;

int linearSearch(int arr[] , int n , int target , int index = 0){
    if(index == n)
        return -1 ;

    if(arr[index] == target)
        return index ;

    return linearSearch(arr , n , target , index + 1) ;
}

int main() {
    
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target ;
    cin >> target ;

    int result = linearSearch(arr , n , target) ;

    if(result == -1)
        cout << "Index Not Found" << endl ;
    else
        cout << "Index found :" << result << endl ;

    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)"  << endl;

    return 0 ;
}
