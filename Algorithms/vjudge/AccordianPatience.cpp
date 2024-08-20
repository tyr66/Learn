#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Pile {
    char rank;
    char suit;
    Pile *next{nullptr};
};

struct Tile{
    Pile* pile;
    int count{0};
    Tile* next{nullptr}, *prev{nullptr};
};

const int N = 52;

Pile pile[52];
Tile tiles[60];

bool is_suit(Pile* a, Pile* b)
{
    if (a==nullptr || b== nullptr)
        return false;

    return a->suit == b->suit || a->rank == b->rank;
}

void link(Tile* a,Tile* b)
{
    if (a != nullptr)
        a->next = b;
    if (b != nullptr)
        b->prev = a;
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string str;
    int k = 0;
    int base = 3;

    tiles[0].next = tiles + 1;
    tiles[1].prev = tiles;
    tiles[1].next = tiles + 2;
    tiles[2].prev = tiles + 1;

    while (cin >> str && str != "#")
    {
        pile[k].rank = str[0];
        pile[k].suit = str[1];
        pile[k].next = nullptr;
        auto& tile = tiles[base + k];
        auto& prev_tile = tiles[base + k -1];
        tile.pile = pile + k;
        tile.count = 1;
        link(&prev_tile, &tile);

        if (++k != N)
            continue;

        Tile* t = tiles + base;
        int cnt = N;

        while (t != nullptr) {

            Pile* p = t->pile;
            Tile* tar_t = t;
            Tile*  nt = t->next;

            while (true) {
                Tile* pppt = tar_t->prev->prev->prev;
                Tile* pt = tar_t->prev;
                if (is_suit(pppt->pile, p)) {
                    tar_t = pppt;
                } else if (is_suit(pt->pile, p)) {
                    tar_t = pt;
                } else 
                    break;

            }

            if (tar_t != t) {
                // exchange
                t->pile = t->pile->next;
                t->count--;
                p->next = tar_t->pile;
                tar_t->pile = p;
                tar_t->count++;

                if (t->count == 0)  {
                    if (t->pile != nullptr)
                    assert(t->pile == nullptr);
                    cnt--;
                    link(t->prev, t->next);
                }
                nt = tar_t->next;
            }

            t = nt;
        }

        t = tiles[base - 1].next;
        if (cnt != 1)
            cout << cnt << " piles remaining:";
        else 
            cout << cnt << " pile remaining:";

        while (t != nullptr) {
            cout <<" " << t->count;
            t = t->next;
        }
        cout << endl;
        k = 0;
    }

    return 0;
}
