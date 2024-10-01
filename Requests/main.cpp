#include <iostream>
#include <string>
#include <cpr/cpr.h>
using namespace std;

int main()
{
    string command;
    while(command != "exit")
    {
        cout << "Input command:" << endl;
        cin >> command;
        if (command == "get")
        {
            cpr::Response r1 = cpr::Get(cpr::URL("http://httpbin.org/get"));
            cout << r1.text << endl;
        }
        if (command == "post")
        {
            cpr::Response r2 = cpr::Post(cpr::URL("http://httpbin.org/post"));
            cout << r2.text << endl;
        }
        if (command == "put")
        {
            cpr::Response r3 = cpr::Put(cpr::URL("http://httpbin.org/put"));
            cout << r3.text << endl;
        }
        if (command == "delete")
        {
            cpr::Response r4 = cpr::Delete(cpr::URL("http://httpbin.org/delete"));
            cout << r4.text << endl;
        }
        if (command == "patch")
        {
            cpr::Response r5 = cpr::Patch(cpr::URL("http://httpbin.org/patch"));
            cout << r5.text << endl;
        }
    }
}