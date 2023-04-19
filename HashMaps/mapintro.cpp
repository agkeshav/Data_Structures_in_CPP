#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> mp;

    // insertion

    // 1
    pair<string, int> p = make_pair("babbar", 1);
    mp.insert(p);

    // 2
    pair<string, int> pair2("love", 3);
    mp.insert(pair2);

    // 3
    mp["mera"] = 1;
    mp["mera"] = 2;

    // Searching

    cout << mp["mera"] << endl;
    cout << mp.at("babbar") << endl;
    cout << mp["unknownkey"] << endl;
    cout << mp.at("unknownkey") << endl;

    // /size
    cout << mp.size() << endl;

    cout << mp.count("babbar") << endl;
    cout << mp.count("unknownkey") << endl;

    // Iterator

    unordered_map<string, int>::iterator it = mp.begin();
    while(it != mp.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    
    return 0;
}