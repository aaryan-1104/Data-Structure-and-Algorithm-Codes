#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

int main()
{
    int n;
    cin >> n;
    cout << endl;
    vector<int> num(n);

    for (auto &i : num)
    {
        cin >> i;
    }
    cout << endl;
    
    int target;
    cin >> target;
    cout << endl;
    
    int current = 0;
    bool flag = false;
    
    for (int i = 0; i < n; i++)
    {   
        sort(num.begin(),num.end());
        int start = i + 1;
        int end = num.size() - 1;

        while (start < end)
        {
            current = num[i] + num[start] + num[end];
            if (current == target)
            {
                flag = true;
                cout << "Match Found!!"<<endl<<num[i]<<" "<<num[start]<<" "<<num[end];
                return 0;
            }
            else if (current < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    cout << "Match not found!!";
}