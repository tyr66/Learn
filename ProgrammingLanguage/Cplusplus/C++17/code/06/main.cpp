#include <iostream>
#include <tbb/task_group.h>
#include "reduce.h"
#include "scan.h"

int main() {

    Reduce reduce;
    reduce.run();

    Scan scan;
    scan.run();

    return 0;
}
