#include <iostream>
#include <string>
#include <vector>
#include <tbb/task_group.h>
#include <cmath>
#include <tbb/parallel_scan.h>
#include <tbb/blocked_range.h>

class Scan {
public:
    // 并行扫描
    void run()
    {
        std::cout << "********************Test Scan*****************" << std::endl;
        constexpr size_t N = 1 << 4;
        std::vector<size_t> a(N);
        size_t res = 0;
        constexpr size_t maxt = 4;
        // PART 1
        tbb::task_group tg1;
        std::vector<size_t> tmp_res(maxt);
        for (size_t t = 0; t < maxt; t++)
        {
            size_t begin = t * N / maxt;
            size_t end = std::min(N, (t+1) * N / maxt);
            tg1.run([&, t, begin, end](){
                size_t local_res = 0;
                for(size_t i = begin; i < end; i++)
                    local_res += i;
                tmp_res[t] = local_res;
            });
        }
        tg1.wait();
        // PART 2
        for (size_t t = 0; t< maxt; t++)
        {
            tmp_res[t] += res;
            res = tmp_res[t];
        }
        std::cout << std::endl;
        // PART 3
        tbb::task_group tg2;
        for (size_t t= 1; t < maxt; t++)
        {
            size_t begin = t * N / maxt - 1;
            size_t end = std::min(N, (t+1) * N / maxt) - 1;
            tg2.run([&, t, begin, end](){
                size_t local_res = tmp_res[t];
                for(size_t i = begin; i < end; i++)
                {
                    local_res += i;
                    a[i] = local_res;
                }
            });
        }
        tg2.wait();

        for (size_t i = 0; i < N; i++) {
            std::cout << a[i] << " " ;
        }
        std::cout << std::endl;


        res = tbb::parallel_scan(tbb::blocked_range<size_t>(0, N), (float)0, [&](tbb::blocked_range<size_t> r, float local_res, auto is_final) {

            for (size_t i = r.begin(); i < r.end(); i++) {

                local_res += i;

                if (is_final) {
                    a[i] = local_res;
                }
            }

            return local_res;
        }, [](float x, float y) {return x + y;});

        for (size_t i = 0; i < N; i++) {
            std::cout << a[i] << " " ;
        }
        std::cout << std::endl;
    }
};
