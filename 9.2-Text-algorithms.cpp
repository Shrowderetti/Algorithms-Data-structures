#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int NWW()
{
    string s, p;

    srand((unsigned)time (NULL));

    s="";
    for(int i=0;i<100;i++)
        s=s+char(88+(rand()%3));

    p="";
    for(int i=0;i<3;i++)
        p=p+char(88+(rand()%3));

    cout<<"Naiwne wyszukiwanie wzorca"<<endl<<p<<endl;

    cout<< s <<endl;

    for(int i=0;i<97;i++)
    {
        if(p==s.substr(i,3))
        {
            cout<<"^";
        }
        else cout<<" ";
    }
    cout<<endl;

    for(int i=0;i<97;i++)
        cout<< (p==s.substr(i,3)? "|": " ");
    return 0;
}

int lettersCount()
{
    string s="";
    int counter[123]={};
    int len=0;


    cout<<"Wprowadz tekst: "<<endl;
    getline(cin, s);
    cout<<endl;

    len=s.length();
    cout<<"dlugosc tekstu: "<<endl;
    cout<<len<<endl;

    for(int i=0;i<len;i++)
    {
        counter[(char)s[i]]++;
    }

    for(int i=97;i<123;i++)
    {
        if(counter[i]>0)
            cout<<(char)i<<" - "<<counter[i]<<endl;
    }

    for(int i=65;i<90;i++)
    {
        if(counter[i]>0)
            cout<<(char)i<<" - "<<counter[i]<<endl;
    }

    return 0;
}


int main()
{
    setlocale(LC_CTYPE,"Polish");
    NWW();
    cout<<endl;
    lettersCount();

    return 0;
}