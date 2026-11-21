#include <bits/stdc++.h>
using namespace std;

struct T 
{
    int v;
    T* l;
    T* r;
    T(int x) : v(x), l(nullptr), r(nullptr) {}
};

T* add(T* t, int x) 
{
    if (!t) return new T(x);
    if (x < t->v) t->l = add(t->l, x);
    else if (x > t->v) t->r = add(t->r, x);
    return t;
}

bool has(T* t, int x) 
{
    if (!t) return false;
    if (t->v == x) return true;
    if (x < t->v) return has(t->l, x);
    return has(t->r, x);
}

void nlr(T* t) 
{
    if (!t) return;
    cout << t->v << ' ';
    nlr(t->l);
    nlr(t->r);
}

void lnr(T* t) 
{
    if (!t) return;
    lnr(t->l);
    cout << t->v << ' ';
    lnr(t->r);
}

void lrn(T* t) 
{
    if (!t) return;
    lrn(t->l);
    lrn(t->r);
    cout << t->v << ' ';
}

void lvl(T* t) 
{
    if (!t) return;
    queue<T*> q;
    q.push(t);
    while (!q.empty()) {
        T* p = q.front();
        q.pop();
        cout << p->v << ' ';
        if (p->l) q.push(p->l);
        if (p->r) q.push(p->r);
    }
}

int h(T* t) 
{
    if (!t) return 0;
    return 1 + max(h(t->l), h(t->r));
}

int main() 
{
    T* t = nullptr;
    int a[] = {5, 3, 8, 1, 4, 7, 9};
    for (int x : a) t = add(t, x);
    nlr(t);
    cout << '\n';
    lnr(t);
    cout << '\n';
    lrn(t);
    cout << '\n';
    lvl(t);
    cout << '\n';
    cout << h(t) << ' ' << has(t, 4) << ' ' << has(t, 6) << '\n';
    return 0;
}
