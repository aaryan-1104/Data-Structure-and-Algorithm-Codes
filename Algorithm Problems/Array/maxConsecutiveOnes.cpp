#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << endl;

    vector<int> oz(n);
    for (auto &i : oz)
    {
        cin >> i;
    }
    cout << endl;

    int zeroes = 0;
    int i = 0;
    int ans = 0;

    for (int j = 0; j < n; j++)
    {
        if (oz[j] == 0)
        {
            zeroes++;
        }
        while (zeroes > k)
        {
            if (oz[i] == 0)
            {
                zeroes--;
            }
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
}