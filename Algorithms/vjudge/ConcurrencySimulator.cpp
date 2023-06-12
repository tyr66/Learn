#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <map>

using namespace std;


int t[5];
int N, Q;

queue<string> proc[1001];
map<string, string> vars;
deque<int> deq;
queue<int> lock_que;
bool is_lock;

int get_cmd_id(string& str)
{
    int idx = str.find(' ');
    string cmd = str.substr(0, idx);

    if (cmd == "print")
        return 1;
    if (cmd == "lock")
        return 2;
    if (cmd == "unlock")
        return 3;
    return 0;
}

void assignment_cmd(int proc_id, string & var_name, string & val)
{
    vars[var_name] = val;
}

bool lock_cmd(int proc_id)
{
    if (is_lock) {

        lock_que.push(proc_id);
        return false;
    } 
    is_lock = true;
    return true;
}

void unlock_cmd(int proc_id)
{
    is_lock = false;

    if (!lock_que.empty())
    {
        int lock_front = lock_que.front();
        lock_que.pop();
        deq.push_front(lock_front);
    }
}

void print_cmd(int proc_id, string var_name)
{
    printf("%d:%s\n", proc_id + 1, vars[var_name].c_str());
}

int main()
{
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    while (T-- > 0)
    {
        cin >> N;
        for (int i = 0; i < 5; i++) cin >> t[i];
        cin >> Q;

        string str; getchar();

        for (int i = 0; i < N; i++) {
            while (getline(cin, str)) {
                proc[i].push(str);
                if (str == "end")
                    break;
            }
            deq.push_back(i);
        }

        while (!deq.empty()) {

            const int id = deq.front(); deq.pop_front();
            int remain = Q;
            bool set_to_lock = false;

            while (remain > 0 && !proc[id].empty()) {

                str = proc[id].front();
                int idx = str.find(' ');
                string cmd = str.substr(0, idx);
                for (auto& c : cmd) c = tolower(c);

                if (cmd == "print") {
                    print_cmd(id, str.substr(idx + 1, str.size() - idx - 1));
                    remain -= t[1];
                }
                else if (cmd == "lock") {
                    if (lock_cmd(id)) {
                        remain -= t[2];
                    }
                    else {
                        set_to_lock = true;
                        break;
                    }
                }
                else if (cmd == "unlock") {
                    unlock_cmd(id);
                    remain -= t[3];
                }
                else if (cmd == "end") {
                    remain -= t[4];
                } else {
                    // var = var
                    string val = str.substr(idx + 3, str.size() - idx - 3);
                    assignment_cmd(id, cmd, val);
                    remain -= t[0];
                }

                proc[id].pop();
            }


            if (set_to_lock) {
                continue;
            } 

            if (!proc[id].empty()) {
                deq.push_back(id);
            }

        }
    }
    return 0;
}