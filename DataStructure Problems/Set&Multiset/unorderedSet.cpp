#include <iostream>
using namespace std;
#include <unordered_set>
//order doesn't matters
//time complexity for deleting and adding is O(1)[average case] as data is stored by hashing technique
int main()
{
    unordered_set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(1);
    
    for (auto i : s)
    {
        cout << i << endl;
    }

    s.erase(4);
    s.erase(s.find(1));
    s.insert(1);

    cout<<"After deletion"<<endl;
    for (auto i : s)
    {
        cout << i << endl;
    }

    if ((s.find(4) == s.end()))
    {
        cout << "not found";
    }
    // cout<<s.contains(2);
}