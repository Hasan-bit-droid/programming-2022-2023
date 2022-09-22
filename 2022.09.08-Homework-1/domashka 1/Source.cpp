#include <iostream>

#include <cstdlib>

#include <ostream>

#include <list>

#include <string>



using namespace std;



struct Subscriber

{

    string name;

    int year;

    string address;

};


int main()

{

    Subscriber a = { "Tony Stark - ", 48, " - New York" };

    Subscriber b = { "Stive Rodjers - ", 75, " - Boston" };

    Subscriber c = { "Stiven Strengh - ", 43, " - New Jersy" };

    Subscriber d = { "Tor - ", 37, " - New Azgard" };

    Subscriber e = { "Bruse Banner - ", 49, " - London" };

    list<Subscriber> l;

    l.push_back(a);

    l.push_back(b);

    l.push_back(c);

    l.push_back(d);

    l.push_back(e);

    /* l.push_fond(a);

    l.push_fond(b);

    l.push_fond(c);

    l.push_fond(d);

    l.push_fond(e); */


    list<Subscriber>::iterator i;


    for (i = l.begin(); i != l.end(); ++i)

        cout << (*i).name << (*i).year << (*i).address << endl;


    return EXIT_SUCCESS;

}

