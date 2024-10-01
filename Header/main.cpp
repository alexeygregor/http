#include <iostream>
#include <string>
#include <cpr/cpr.h>
using namespace std;

string find(string buff)
{
    string buff2;
    bool ch = false;
    for (int i = 0; i < buff.length(); i++)
    {
        if (buff[i] == '<' && buff[i + 1] == 'h' && buff[i + 2] == '1' && buff[i + 3] == '>')
        {
            i += 4;
            ch = true;
        }
        if (buff[i] == '<' && buff[i + 1] == '/' && buff[i + 2] == 'h' && buff[i + 3] == '1')
        {
            ch = false;
        }
        if(ch)
        {
            buff2 += buff[i];
        }
    }
    return buff2;
}

int main()
{
    cpr::Response r = cpr::Get(cpr::URL("http://httpbin.org/html"));
        cpr::Header({"Accept", "text/html"});
    cout << r.text << endl;
    string buff = r.text;
    cout << find(buff) << endl;
}