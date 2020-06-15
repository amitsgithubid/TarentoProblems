#include<iostream>
#include <list>
#include <string>
using namespace std;
 
#include <stdio.h>

void ArrangeStringsRecursive(string p, string q, string r, string &s, int idx)
{
    if (idx < 0)
        return;
    s[idx*3+2] = r[idx];
    s[idx*3+1] = q[idx];
    s[idx*3]   = p[idx];
	
	//Calling it recursively
    ArrangeStringsRecursive(p,q,r,s,idx-1);
}

int main()
{   
    string p("12345"), q ("abcde") , r("ABCDE");
    string s;
	// Resizing
    s.resize(p.size() * 3 + 1);
	
    ArrangeStringsRecursive(p,q,r,s,4);
    s[p.size() * 3 + 1] = '\0';
    cout << "Output String" << endl << s << endl;
    return 0;
}