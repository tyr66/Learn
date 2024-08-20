#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <string>
using namespace std;


struct ProgramState
{
    int id;
    int state;
};

enum InstallState
{
    NOT_INSTALL,
    EXPLICT_INSTALL,
    IMPLICT_INSTALL,
};

map<string, ProgramState> program;
map<int, string> idToProgram;
vector<vector<int>> graph;
vector<int> inDegree;
int idx = 0;

const string DEPEND = "DEPEND";
const string INSTALL = "INSTALL";
const string REMOVE = "REMOVE";
const string LIST = "LIST";
const string END = "END";

int get_program_id(string& pro)
{
    if (program.count(pro) == 0)
        program[pro] = { idx++, InstallState::NOT_INSTALL };
    return program[pro].id;
}

void generate_record(string& pro)
{
    if (program.count(pro))
        return;

    program[pro] = { idx++, InstallState::NOT_INSTALL };
    idToProgram[idx - 1] = pro;
    inDegree.push_back(0);
    graph.push_back(vector<int>());
}

void make_dependency(string& pro, string& dep)
{
    generate_record(pro); generate_record(dep);
    int pro_id = program[pro].id;
    int dep_id = program[dep].id;

    graph[pro_id].push_back(dep_id);
}

void handle_DEPEND(stringstream& ss)
{
    string pro, dep;
    ss >> pro;
    cout << DEPEND << " " << pro;

    while (ss >> dep) {
        make_dependency(pro, dep);
        cout << " " << dep;
    }
    cout << endl;
}

void install(string& pro)
{

    int id = program[pro].id;
    for (auto to : graph[id]) {

        string dep = idToProgram[to];
        inDegree[to]++;

        if (program[dep].state != NOT_INSTALL) {
            continue;
        }

        install(dep);
        program[dep].state = IMPLICT_INSTALL;

        cout << "   " << "Installing " << dep << endl;
    }
}

void handle_INSTALL(stringstream& ss)
{
    string pro; ss >> pro;
    generate_record(pro);
    cout << "INSTALL " << pro << endl;

    if (program[pro].state != InstallState::NOT_INSTALL) {
        cout << "   " << pro << " is already installed." << endl;
        return;
    }

    install(pro);

    program[pro].state = EXPLICT_INSTALL;

    cout << "   " << "Installing " << pro << endl;
}

void handle_REMOVE(stringstream& ss)
{
    string pro; ss >> pro;
    cout << REMOVE << " " << pro << endl;

    int pro_id = program[pro].id;

    if (inDegree[pro_id] != 0) {
        cout << "   " << pro << " is still needed" << endl;
        return;
    }

    if (program[pro].state == NOT_INSTALL) {
        cout << "   " << pro << " is not installed." << endl;
        return;
    }

    queue<int> que; que.push(pro_id);

    while (!que.empty())
    {
        int id = que.front(); que.pop();

        cout << "   Removing " << idToProgram[id] << endl;
        program[idToProgram[id]].state = NOT_INSTALL;

        for (auto nt_id : graph[id]) {
            --inDegree[nt_id];
            if (program[idToProgram[nt_id]].state == IMPLICT_INSTALL && inDegree[nt_id] == 0) {
                que.push(nt_id);
            }
        }
    }
}

void handle_LIST(stringstream& ss)
{
    cout << LIST << endl;

    for (auto& pair : program)
    {
        if (pair.second.state != NOT_INSTALL)
            cout << "   " << pair.first << endl;
    }
}

int main()
{
    //freopen("intput.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string str;
    string cmd;
    stringstream ss;

    while (true)
    {
        getline(cin, str);
        ss << str; str.clear();

        ss >> cmd;

        if (cmd == DEPEND) {
            handle_DEPEND(ss);
        }
        else if (cmd == INSTALL) {
            handle_INSTALL(ss);
        }
        else if (cmd == REMOVE) {
            handle_REMOVE(ss);
        }
        else if (cmd == LIST) {
            handle_LIST(ss);
        }
        else {
            cout << END << endl;
            break;
        }

        ss.clear();
    }
    return 0;
}

