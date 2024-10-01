#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cpr/cpr.h>
using namespace std;

class Pair
{
    string GetReq, PostReq, buffer;
    map<string,string>arg;
    map<string, string>::iterator it;
  public:
    Pair(map<string,string>_arg)
    {
        arg = _arg;
    }
    string Get()
    {
        buffer = "?";
        for(it = arg.begin(); it != arg.end(); ++it)
        {
            buffer += it->first + "=" + it->second + "&";
        }
        for(int i = 0; i < buffer.length() - 1; ++i)
        {
            GetReq += buffer[i];
        }
        return GetReq;
    }
    string Payload()
    {
        for(it = arg.begin(); it != arg.end(); ++it)
        {
            buffer += "{\"" + it->first + "\", " + it->second + "}, ";
        }
        for(int i = 0; i < buffer.length() - 2; ++i)
        {
            PostReq += buffer[i];
        }
        return PostReq;
    }
};

int main()
{
    string value, command, v1, v2;
    vector<string>vec;
    map<string, string>arg;
    while(true)
    {
        cin >> value;
        if (value == "get" || value == "post")
        {
            command = value;
            break;
        }
        vec.push_back(value);
    }
    for(int i = 0; i < vec.size(); ++i)
    {
        v1 = vec[i];
        v2 = vec[i + 1];
        arg.insert(pair<string, string> (v1, v2));
        i += 1;
    }
    Pair P(arg);
    if (command == "get")
    {
        cpr::Response r1 = cpr::Get(cpr::URL({"http://httpbin.org/get"}, {P.Get()}));
        cout << r1.text << endl;
    }
    if (command == "post")
    {
        cpr::Response r2 = cpr::Post(cpr::URL("http://httpbin.org/post"), cpr::Payload({P.Payload()}));
        cout << r2.text << endl;

    }
}