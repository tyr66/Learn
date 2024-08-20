#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>
#include <stack>
#include <stdexcept>
using namespace std;

struct Face {
    int x, y, z;
    int number;
};

class Dicey{
public:
    Dicey()
    {
        faces.push_back({0, 0, 1, 4});
        faces.push_back({0, 0, -1, 3});
        faces.push_back({-1, 0, 0, 2});
        faces.push_back({1, 0, 0, 5});
        faces.push_back({0, 1, 0, 1});
        faces.push_back({0, -1, 0, 6});
    }
    void init(int front , int top) {
        auto& face = getFace(front);

        while (face.x != 0)
            rollLeft();
        while (face.y != 0)
            rollUp();
        while (face.z != 1)
            rollUp();

        auto& topFace = getFace(top);

        while (topFace.y != 1)
            rollLeft();
    }

    Face& getFace(int number)
    {
        for (auto& face : faces)
            if (face.number == number)
                return face;
        assert(false);
    }

    int getFront()
    {
        for (auto& face : faces)
            if (face.z == 1)
                return face.number;
    }

    void rollLeft(){
        for (auto& face :faces) {
            face = { -face.y, face.x, face.z , face.number};
        }
    }
    void rollRight(){
        for (auto& face :faces) {
            face = { face.y, -face.x, face.z , face.number};
        }
    }
    void rollUp(){
        for (auto& face :faces) {
            face = { face.x, -face.z, face.y , face.number};
        }
    }
    void rollBottom(){
        for (auto& face :faces) {
            face = { face.x, face.z, -face.y , face.number};
        }
    }
    int getTop() {
        for (auto& face : faces) {
            if (face.y == 1)
                return face.number;
        }
        throw runtime_error("wrong dicey");
    }
    void clear() {
        faces.clear();
    }

    void rotate(int x, int z) {
        if (x == 1)
            rollUp();
        else if (x == -1)
            rollBottom();
        else if (z == 1)
            rollLeft();
        else 
            rollRight();
    }
    void print(){
        for (auto& face : faces) {
            if (face.x == -1)
                cout << "left : " << face.number << endl;
            if (face.x == 1)
                cout << "right : " << face.number << endl;
            if (face.y == 1)
                cout << "up : " << face.number << endl;
            if (face.y == -1)
                cout << "bottom : " << face.number << endl;
            if (face.z == 1)
                cout << "front : " << face.number << endl;
            if (face.z == -1)
                cout << "back : " << face.number << endl;
        }
    }
private:
    std::vector<Face> faces;
};

const int MAX_N = 11;
int maze[MAX_N][MAX_N];
vector<int> path;
int moveDir[] = {0, -1, 0, 1, -1, 0, 1,0, };
bool state[MAX_N][MAX_N][7][7];
int R, C;
int r, c;
int cnt = 1;

bool dfs(int i, int j, Dicey& dicey)
{
    path.push_back(i);path.push_back(j);

    if (i == r && j == c && cnt-- == 0 /* && visited[r][c]*/)
        return true;

    for (int k = 0; k < 8; k+=2)
    {
        int _i = i + moveDir[k];
        int _j = j + moveDir[k + 1];

        if (_i < 1 || _i > R) continue;
        if (_j < 1 || _j > C) continue;
        if (maze[_i][_j] == 0) continue;
        //if (visited[_i][_j] && !(_i == r && _j == c)) continue;
        if (maze[_i][_j] != dicey.getTop() && maze[_i][_j] != -1)  continue;

        dicey.rotate(moveDir[k], moveDir[k + 1]);
        if (state[_i][_j][dicey.getTop()][dicey.getFront()])
        {
			dicey.rotate(-moveDir[k], -moveDir[k + 1]);
			continue;
        }
		state[_i][_j][dicey.getTop()][dicey.getFront()] = true;

        if (dfs(_i, _j, dicey))
            return true;

		state[_i][_j][dicey.getTop()][dicey.getFront()] = false;

        dicey.rotate(-moveDir[k], -moveDir[k + 1]);

    }

    path.pop_back(); path.pop_back();

    return false;
}

int main()
{
    string mazeName;
    int front ,top;
    while (cin >> mazeName && mazeName != "END") {
        cin >> R >> C >> r >> c >> top >> front;
        Dicey dicey;
        dicey.init(front ,top);

        for(int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                cin >> maze[i][j];

        dfs(r, c, dicey);

        cout << mazeName ;
        for (int i = 0, j = 0; i < path.size(); i += 2)
        {
            if (j++ % 9 == 0)
            {
                if (j != 1)
                    cout << ",";
				printf("\n  (%d,%d)", path[i], path[i + 1]);
            }
            else 
            printf(",(%d,%d)", path[i], path[i+1]);
        }

        if (path.empty())
            cout << endl << "  No Solution Possible";
        cout << endl;

        cnt = 1;
        path.clear();
        dicey.clear();
        memset(state, 0, sizeof(state));
    }

    return 0;
}
