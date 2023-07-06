#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

const int MAX_N = 50 + 5;
const int MAX_DIST = 1000 + 1;

int x_0[MAX_N], x_1[MAX_N];
int z_0[MAX_N], z_1[MAX_N];
int y_0[MAX_N], y_1[MAX_N];
int dx[MAX_N * 2], dy[MAX_N * 2], dz[MAX_N * 2];
int N;
int cnt_x, cnt_y, cnt_z;
int grid[MAX_N * 2][MAX_N * 2][MAX_N * 2];

int nx[] = {0, 0, -1, 1, 0, 0};
int ny[] = {1, -1, 0, 0, 0, 0};
int nz[] = {0, 0,  0, 0, -1, 1};

struct Node
{
    int x,y,z;

    int get_volume()
    {
        return (dx[x + 1] - dx[x]) * (dy[y + 1] - dy[y]) * (dz[z + 1] - dz[z]);
    }

    Node get_neighbour(int i)
    {
        return Node{x + nx[i], y + ny[i], z + nz[i]};
    }

    bool is_vailed()
    {
        return x >= 0 && x <cnt_x - 1 && y >= 0 && y < cnt_y - 1 && z >=0 && z < cnt_z - 1;
    }

    int get_color()
    {
        return grid[x][y][z];
    }

    void set_color(int i)
    {
        grid[x][y][z] = i;
    }

    int get_surface_area(int i)
    {
        if (nx[i] != 0)
            return (dy[y + 1] - dy[y]) * (dz[z + 1] - dz[z]); // 左右侧面的表面积
        else if (ny[i] != 0)
            return (dx[x + 1] - dx[x]) * (dz[z + 1] - dz[z]); // 上下侧面的表面积
        else 
            return  (dx[x + 1] - dx[x]) * (dy[y + 1] - dy[y]); // 前后侧面的表面积
    }
};

void bfs(int &s, int &v)
{
    queue<Node> que; que.push({0, 0, 0});
    grid[0][0][0] = 2;
    s = v = 0;
    // printf("cnt_x = %d, cnt_y = %d, cnt_z = %d\n", cnt_x, cnt_y, cnt_z);
    while (!que.empty())
    {
        auto node = que.front(); que.pop();
        v += node.get_volume();
        // cout << node.get_volume()<< endl;

        // printf("{%d, %d, %d}\n", node.x, node.y, node.z);

        // 遍历6个邻接点
        for (int i = 0; i < 6; i++)
        {
            auto next_node = node.get_neighbour(i);

            if (!next_node.is_vailed()) continue;

            int color = next_node.get_color();
            // 计算表面积
            if (color == 1)
                s += node.get_surface_area(i);
            else if (color == 0) {
                next_node.set_color(2);
                que.push(next_node);
            }
        }
    }

    v = MAX_DIST * MAX_DIST * MAX_DIST - v;

}

int get_id(int * arr, int sz, int tar)
{
    return (lower_bound(arr, arr + sz, tar) - arr);
}

void get_input()
{
    cin >> N;

    dx[0] = dy[0] = dz[0] = 0;
    dx[1] = dy[1] = dz[1] = MAX_DIST;

    int cnt = 2;
    int x,y,z;
    for (int i = 0; i < N; i++)
    {
        cin >> x_0[i] >> y_0[i] >> z_0[i]>> x >> y >> z;
        x_1[i] = x_0[i] + x; y_1[i] = y_0[i] + y; z_1[i] = z_0[i] + z;

        dx[cnt] = x_0[i]; dx[cnt + 1] = x_1[i];
        dy[cnt] = y_0[i]; dy[cnt + 1] = y_1[i];
        dz[cnt] = z_0[i]; dz[cnt + 1] = z_1[i];
        cnt += 2;
    }

}

void discretize()
{
    int cnt = N * 2 + 2;
    sort(dx, dx + cnt);
    sort(dy, dy + cnt);
    sort(dz, dz + cnt);

    cnt_x = (unique(dx, dx + cnt) - dx);
    cnt_y =(unique(dy, dy + cnt) - dy);
    cnt_z = (unique(dz, dz + cnt) - dz);
}

void test_input()
{
    cout << endl << "test input " << endl;
    for (int i = 0; i < N; i++) {
        printf("%d %d %d %d %d %d\n", x_0[i], y_0[i], z_0[i], x_1[i], y_1[i], z_1[i]);
    }
    cout << endl;

    cout << "dx = ";
    for (int i = 0; i < N * 2 + 2; i++) {
        cout << " " << dx[i];
    }

    cout << endl << "dy = ";
    for (int i = 0; i < N * 2 + 2; i++)
        cout << " " << dy[i];

    cout << endl << "dz = ";
    for (int i = 0; i < N * 2 + 2; i++)
        cout << " " << dz[i];
}

void fill_color()
{
    for (int i = 0; i < N; i++)
    {
        int x0_id = get_id(dx, cnt_x, x_0[i]), x1_id = get_id(dx, cnt_x, x_1[i]);
        int y0_id = get_id(dy, cnt_y, y_0[i]), y1_id = get_id(dy, cnt_y, y_1[i]);
        int z0_id = get_id(dz, cnt_z, z_0[i]), z1_id = get_id(dz, cnt_z, z_1[i]);

        for (int x = x0_id; x < x1_id; x++)
        {
            for (int y = y0_id; y < y1_id; y++)
            {
                for (int z = z0_id; z < z1_id; z++)
                {
                    grid[x][y][z] = 1;
                }
            }
        }
    }
}

void test_color()
{
    for (int x = 0; x < cnt_x; x++)
    {
        for (int y = 0; y < cnt_y; y ++)
        {
            for (int z = 0; z < cnt_z; z++)
            {
                if (grid[x][y][z] == 1)
                    printf("{%d, %d, %d} == 1\n", x, y, z);
            }
        }
    }
}

void clear_grid()
{
    memset(grid, 0, sizeof(grid));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" ,stdout);

    int T; cin >> T;

    while (T-- > 0)
    {
        int s, v;
        get_input();
        // test_input();
        discretize();

        fill_color();

        // test_color();
        bfs(s, v);

        clear_grid();

        cout << s << " " << v << endl;
    }


    return 0;
}
