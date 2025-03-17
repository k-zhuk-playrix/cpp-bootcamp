//https://app.asana.com/1/656176460444/project/1208315729461187/task/1209655350170891

#include <iostream>
#include <chrono>
#include <ctime>  

const int MIN_DT_MS = 100;
const int PATH_WIDTH = 10;
//const lvalues

void print_line(std::string&& line) {
    //std::string&& line - rvalue
    std::cout << line << std::endl;
}

void update(int dt_ms, bool side = true) {
    static int idx = 0;
    static bool goRight = true;

    std::string line = "";
   
    if (side) {
        for (int i = 0; i < idx % (PATH_WIDTH + 1); i++) {
            line += " ";
        }
    } else {
        for (int i = 0; i < (PATH_WIDTH - idx % (PATH_WIDTH + 1)); i++) {
            line += " ";
        }
    }

    //всё что выше -> lvalue

    print_line(std::move(line + "X"));
    //rvalue

    if (side) {
        idx += side ? 1 : -1; 
    } else {
        idx += !side ? 1 : -1;
    }

    //тернарки rvalue

    goRight = idx == PATH_WIDTH ? false : idx == 0 ? true : goRight;
}

int Run_3() {
    auto last_dt = std::chrono::system_clock::now();
    auto curr_dt = std::chrono::system_clock::now();
    //auto не компилится
    int dt_ms = 0;
    //lvalues

    while (true) {
        curr_dt = std::chrono::system_clock::now();
        dt_ms = std::chrono::duration_cast<std::chrono::milliseconds>(curr_dt - last_dt).count();
        if (dt_ms < MIN_DT_MS) {
            continue;
        } else {
            last_dt = curr_dt;
        }

        update(dt_ms, true);
        update(dt_ms, false);
    }
    
    return 0;
}