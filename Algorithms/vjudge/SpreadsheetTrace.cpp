#include <iostream>
#include <vector>

using namespace std;

enum OperationType { NONE, DC, DR, IC, IR, EX, };

struct Operation
{
    OperationType type;
    int data[11];
};

OperationType get_operation_type(string&op)
{
    if (op == "DC")
        return DC;
    if (op == "DR")
        return DR;
    if (op == "IC")
        return IC;
    if (op == "IR")
        return IR;
    if (op == "EX")
        return EX;

    return NONE;
}

void op_DC(Operation&op, int* r, int* c)
{
    int cnt = 0;

    for (int i = 1; i <= op.data[0]; i++)
    {
        if (op.data[i] == *c) {
            *r = *c = -1; 
            return;
        } else if (op.data[i] < *c) {
            cnt++;
        }
    }

    *c = *c - cnt;
}

void op_DR(Operation&op, int* r, int* c)
{
    int cnt = 0;

    for (int i = 1; i <= op.data[0]; i++)
    {
        if (op.data[i] < *r) {
            cnt++;
        } else if (op.data[i] == *r) {
            *r = *c = -1;
            return;
        }
    }

    *r = *r - cnt;
}

void op_IC(Operation&op, int* r, int* c)
{
    int cnt = 0;

    for (int i = 1; i <= op.data[0]; i++)
    {
        if (op.data[i] <= *c) {
            cnt++;
        }
    }

    *c = *c + cnt;
}

void op_IR(Operation&op, int* r, int* c)
{
    int cnt = 0;
    
    for (int i = 1; i <= op.data[0]; i++)
    {
        if (op.data[i] <= *r) {
            cnt++;
        }
    }

    *r = *r + cnt;
}

void op_EX(Operation&op, int* r, int* c)
{
    if (*r == op.data[1] && *c == op.data[2]) {
        *r = op.data[3];
        *c = op.data[4];
    } else if (*r == op.data[3] && *c == op.data[4]) {
        *r = op.data[1];
        *c = op.data[2];
    }
}

int main()
{
    vector<Operation> operations;

    int R, C;
    int N;
    int idx = 1;

    while (cin >> R && cin >> C && R != 0 && C != 0)
    {
        cin >> N;

        string op;
        operations.clear();
        operations.resize(N);

        for (int i = 0; i < N; i++)
        {
            cin >> op;
            operations[i].type = get_operation_type(op);

            if (operations[i].type != EX)
                cin >> operations[i].data[0];
            else 
                operations[i].data[0] = 4;

            for (int j = 1; j <= operations[i].data[0]; j++)
                cin >> operations[i].data[j];


        }

        if (idx != 1)
            cout << endl;

        cout << "Spreadsheet #" << idx++ << endl;

        cin >> N;
        int r,c;
        int origin_r, origin_c;
        for (int i = 0; i < N; i++)
        {
            cin >> origin_r >> origin_c;
            r = origin_r;
            c = origin_c;

            bool gone = false;

            for (Operation& op : operations)
            {
                switch(op.type)
                {
                    case DC: op_DC(op, &r, &c); break;
                    case DR: op_DR(op, &r, &c); break;
                    case IC: op_IC(op, &r, &c); break;
                    case IR: op_IR(op, &r, &c); break;
                    case EX: op_EX(op, &r, &c); break;
                    case NONE: break;
                }

                gone =  r == -1 && c == -1;
            }

            if (!gone)
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", origin_r, origin_c, r, c);
            else 
                printf("Cell data in (%d,%d) GONE\n", origin_r, origin_c);
        }
            
    }

    return 0;
}
