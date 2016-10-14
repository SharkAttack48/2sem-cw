#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct node
{
    unsigned inf;
    node * ref;
};

void print (node *a)
{
    node *p;
    for (p=a; p; p=p->ref)
        cout <<" "<< p->inf;
    cout << '\n';
}

node * create (unsigned n)
{
    node *b, *p;
    unsigned i;
    b = new node;
    b -> inf = 1;
    p = b;
    for (i=1; i<n; i++)
    {
        p -> ref = new node;
        p = p -> ref;
        p -> inf = i + 1;
    }
    p -> ref = NULL;
    return b;
}

void dellist (node * a, unsigned b)
{
    node *p, *q;
    unsigned t;
	for (t = a -> inf; t*t <= b; t++)
    {
        p = a -> ref;
        while (p -> ref)
        {
            if ((p -> ref -> inf) % t == 0)
            {
                q = p -> ref;
                p -> ref = q -> ref;
                delete q;
            }
            else p = p -> ref;
        }
    }
}

void destroy (node * a)
{
    node *p;
    while(a)
    {
        p=a;
        a=a->ref;
        delete p;
    }
}

int main ()
{
	clock_t the_time1;
    double elapsed_time1;

    the_time1 = clock();

    node *s;
    unsigned r;
    cout << "Enter N = ";
    cin >> r;
    s = create (r);
	cout << "4ll NUMB3R5: \n";
    print (s);
	
	elapsed_time1 = double(clock() - the_time1) / CLOCKS_PER_SEC;
    std::cout << "Elapsed time " << elapsed_time1 << " sec." << std::endl;

	clock_t the_time;
    double elapsed_time;

    the_time = clock();

    dellist (s -> ref, r);
	cout << "PR1M3 NUMB3R5: \n";
	print (s);
	
	elapsed_time = double(clock() - the_time) / CLOCKS_PER_SEC;
    std::cout << "Elapsed time " << elapsed_time << " sec." << std::endl;

    destroy (s);
}
