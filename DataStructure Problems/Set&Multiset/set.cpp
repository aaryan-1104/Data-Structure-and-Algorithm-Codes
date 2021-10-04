#include <iostream>
using namespace std;
#include <set>
//time complexity for deleting and adding is O(log(n)) as data is stored as in Binary Search tree

int main()
{
    cout<<"Set"<<endl;
    set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(1);

    s.erase(4);
    s.erase(s.find(1));
    s.insert(1);

    for (auto i : s)
    {
        cout << i << endl;
    }

    if ((s.find(4) == s.end()))
    {
        cout << "not found"<<endl<<endl;
    }

    // cout<<s.contains(2);
    cout<<"MultiSet"<<endl;
    multiset<int> s1;

    s1.insert(1);
    s1.insert(4);
    s1.insert(1);
    s1.insert(3);
    s1.insert(1);
    s1.insert(1);

    for (auto i : s1)
    {
        cout << i;
        cout<<" ";

    }
    cout<<endl;

    s.erase(s.find(1));//will remove onlt first instance of 1
    
    for (auto i : s1)
    {
        cout << i;
        cout<<" ";

    }
    cout<<endl;


    s.erase(1);//will remove all instance of 1

    for (auto i : s1)
    {
        cout << i;
        cout<<" ";
    }
}