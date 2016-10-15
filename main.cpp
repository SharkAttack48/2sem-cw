#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct node * create (unsigned);//Creating linked list
void print (node *);
void dellist (node *, unsigned);//List processing
void destroy (node *);

struct node
{
    unsigned inf;
    node * ref;
};

int main ()
{
    node *s;
    unsigned r;
    cout << "Enter N = ";
    cin >> r;

    double e1;
	clock_t t1;
    t1 = clock();

    s = create (r);

	e1 = double(clock() - t1) / CLOCKS_PER_SEC;

	cout << "All numbers: \n";
    print (s);

    cout << "Elapsed time of creation linked list: " << e1 << " sec.\n";

	clock_t t2;
    double e2;
    t2 = clock();

    dellist (s -> ref, r);
	
	e2 = double(clock() - t2) / CLOCKS_PER_SEC;

	cout << "Prime numbers: \n";
	print (s);

    cout << "Elapsed time of deleting composite numbers: " << e2 << " sec.\n";

    destroy (s);
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

void print (node *a)
{
    node *p;
    for (p=a; p; p=p->ref)
        cout <<" "<< p->inf;
    cout << '\n';
}

void dellist (node * a, unsigned b)
{
    node *p, *q;
    unsigned t;
	for (t = a -> inf; t*t <= b; a = a -> ref, t = a -> inf)
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
