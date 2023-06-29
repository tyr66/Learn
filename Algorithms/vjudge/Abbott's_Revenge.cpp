#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

struct Room
{
    bool active{ false };
    string path[4];
};
struct Node
{
    Node* par;
    int r, c, dir;
};

typedef std::pair<int, int> Vec2;
Room maze[9][9];
Node nodes[9 * 9 * 4];
bool is_used[9][9][4];
string dirs = "NSWE";
int generate_id;

Vec2 rotate_L(Vec2 dir) { return { -dir.second, dir.first }; }
Vec2 rotate_R(Vec2 dir) { return { dir.second, -dir.first }; }

Vec2 get_dir_vec(int c) {
    if (c == 0) return { -1, 0 };
    if (c == 1) return { 1, 0 };
    if (c == 2) return { 0, -1 };
    return { 0, 1 };
}

int dir_vect_to_idx(Vec2 dir)
{
    if (dir.first == -1 && dir.second == 0)
        return 0;
    if (dir.first == 1 && dir.second == 0)
        return 1;
    if (dir.first == 0 && dir.second == -1)
        return 2;
    return 3;
}

Node* generate_node(int r, int c, int dir)
{
    auto& node = nodes[generate_id++];
    node.r = r; node.c = c; node.dir = dir;
    return &node;
}

Node* walk(int r, int c, int dir, char lrf)
{
    Node* res = generate_node(r, c, dir);
    Vec2 move = get_dir_vec(dir);

    if (lrf == 'L')
        move = rotate_L(move);
    else if (lrf == 'R')
        move = rotate_R(move);

    res->r = r + move.first;
    res->c = c + move.second;
    res->dir = dir_vect_to_idx(move);

    if (!maze[res->r][res->c].active)
        return nullptr;
    return res;
}

int get_dir_idx(char c)
{
    switch (c)
    {
        case 'N': return 0;
        case 'S': return 1;
        case 'W': return 2;
        case 'E': return 3;
    }

    return -1;
}

void set_room(int r, int c, string& path)
{
    maze[r][c].path[get_dir_idx(path[0])] = path;
    maze[r][c].active = true;
}

void clear_room()
{
    for (int r = 1; r <= 9; r++)
    {
        for(int c = 1; c <= 9; c++) {
            Room& room = maze[r][c];
            room.active = false;
            for (int i = 0; i < 4; i++)
                room.path[i].clear();
        }
    }
}


void print_maze()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (maze[i][j].active)
            {
                printf("%d %d ", i, j);

                for (int k = 0; k < 4; k++)
                    cout << maze[i][j].path[k] << " ";
                cout << endl;
            }
        }
    }
}

void  print_res(string&name, Node* node)
{
    vector<Node*> arr;
    arr.push_back(node);

    while (node->par != nullptr)
    {
        node = node->par;
        arr.push_back(node);
    }

    int cnt = 0;
    cout << name << endl << " ";

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        printf(" (%d,%d)", arr[i]->r, arr[i]->c);

        if (++cnt == 10)
            cout << endl << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);

    string name;
    while (cin >> name && name != "END")
    {
        char dir_c; int start_r, start_c; int tar_r, tar_c; 
        cin >> start_r >> start_c >> dir_c >> tar_r >> tar_c;

        int r, c;
        string path;

        clear_room();

        while (cin >> r && r != 0 && cin >> c) {
            while (cin >> path && path != "*")
                set_room(r, c, path);
        }

        // print_maze();
        memset(is_used, 0, sizeof(is_used));

        Node* tarnode = nullptr;
        queue<Node*> que;
        Node* origin = walk(start_r, start_c, get_dir_idx(dir_c), 'F');

        if (origin != nullptr) {
            origin->par = generate_node(start_r, start_c, -1);
            que.push(origin);
            is_used[start_r][start_c][get_dir_idx(dir_c)] = true;
        }

        while (!que.empty() && tarnode == nullptr) {
            Node* p = que.front(); que.pop();
            auto& room = maze[p->r][p->c];
            string& path = room.path[p->dir];

            if (!room.active)
                continue;

            for (int i = 1; i < path.size(); i++) {

                Node* next_move = walk(p->r, p->c, p->dir, path[i]);

                if (next_move == nullptr)
                    continue;

                int r = next_move->r, c = next_move->c, dir = next_move->dir;

                if (is_used[r][c][dir]) continue;
                is_used[r][c][dir] = true;
                Node* node = generate_node(r, c, dir);
                node->par = p;

                if (r == tar_r && c == tar_c) {
                    tarnode = node; break;
                }
                que.push(node);
            }
        }

        if (tarnode == nullptr) {
            cout << name << endl;
            cout << "  No Solution Possible" << endl;
            continue;
        }

        print_res(name, tarnode);

    }
    return 0;
}
