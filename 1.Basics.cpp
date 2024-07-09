// Target sum in sorted array

#include<iostream>
#include<vector>
#include<utility>

using namespace std;
void FindTargetSum(int arr[], int size, int targetsum, vector<pair<int, int>>& vec)
{
    int left = 0;
    int right = (size-1);

    while (left <= right)
    {
        if (targetsum == arr[left] + arr[right]) {
            vec.push_back(pair<int, int>(arr[left], arr[right]));
        }
        
        if ((arr[left] + arr[right]) <= targetsum  ) {
            left = left + 1;
        }
        else if((arr[left] + arr[right]) > targetsum) {
            right = right - 1;
        }
    }
}


int main()
{
    vector<pair<int, int>> vec;
    int arr[] = { 2,3,4,5,6,7,8,10,11,12,13 };

    int size = sizeof(arr) / sizeof(arr[0]);

    int targetsum = 18;

    FindTargetSum(arr, size, targetsum, vec);

    if (vec.size()) {
        cout << "Target sum found at these many places: " << vec.size()<<endl;

        cout << "Index are which are combing target sum: \n";
        for (auto p : vec)
        {
            cout << p.first << "  " << p.second << endl;
        }

    }
    else {
        cout << "Target sum not found" << endl<<endl;
    }

}