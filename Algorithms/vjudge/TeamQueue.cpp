#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);
    int CNT;
    int scenarioId = 1;
    while (cin >> CNT && CNT != 0)
    {
        int num, minIdx, teamID;
        map<int, queue<int>> teamToque;
        map<int, int> idToTeam;
        queue<int> teamQueue;

        for (int i = 0; i < CNT; i++) {
            cin >> num;

            for (int j = 0, id; j < num; j++) {
                cin >> id;
                idToTeam[id] = teamID;
            }

            teamID++;
        }

        string cmd;
        int id;

        printf("Scenario #%d\n", scenarioId);

        while (cin >> cmd) {

            if (cmd == "ENQUEUE") {
                cin >> id;
                int teamID = idToTeam[id];

                if (teamToque.find(teamID) == teamToque.end() || teamToque[teamID].empty())
                {
                    teamQueue.push(teamID);
                } 

                teamToque[teamID].push(id);

            } else if (cmd == "DEQUEUE") {

                int teamID = teamQueue.front();
                queue<int>& que = teamToque[teamID];

                cout << que.front() << endl;
                que.pop();

                if (que.empty())
                    teamQueue.pop();

            }
            else {
                break;
            }
        }

        scenarioId++;
        cout << endl;
    }
    return 0;
}