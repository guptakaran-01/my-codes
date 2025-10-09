#include <iostream>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> linearsearch(int arr[][4], int row, int col, int target)
{
    pair<int, int> ans;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int maxsum(int arr[][4], int row, int col)
{
    int ans = INT8_MIN;
    int rownum;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
            ans = max(ans, sum);
        }
        if (sum == ans)
        {
            rownum = i;
        }
    }
    return rownum;
}

int diagonalsum(int arr[][3], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                ans += arr[i][j];
            }
            else if (j == n - 1 - i)
            {
                ans += arr[i][j];
            }
        }
    }
    return ans;
}

// int main()
// {
//     int arr[3][3] = {{1, 2, 4}, {1, 5, 7}, {9, 8, 2}};

//     // cout<<"Enter the matrix"<<endl;
//     // for (int i = 0; i < 3; i++)
//     // {
//     //     for (int j = 0; j < 4; j++)
//     //     {
//     //         cin>>arr[i][j];
//     //     }

//     // }

//     cout << "The matrix is as follows " << endl;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }

//     //    if(linearsearch(arr, 3 , 4, 14)){
//     //     cout<<"Present"<<endl;
//     //    }
//     //    else{
//     //     cout<<"Absent"<<endl;
//     //    }

//     // pair<int, int> ans=linearsearch(arr, 3,4,12);
//     // cout<<ans.first<<" "<<ans.second<<endl;

//     // cout << "the maximum sum is " << maxsum(arr, 3, 4) << endl;
//     // cout << "the maximum sum of the row is  " << maxsum(arr, 3, 4) << endl;
//     cout << "the digonal sum of the row is  " << diagonalsum(arr, 3) << endl;

//     return 0;
// }

void rotate(int arr[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
           swap(arr[i][j],arr[j][i]);
        }
}
}

void print(int arr[][3], int n)
{
    cout << "The matrix is as follows " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr,3);
    rotate(arr,3);
    cout<<endl;
    print(arr,3);

    return 0;
}
