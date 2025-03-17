
//https://app.asana.com/1/656176460444/project/1208315729461187/task/1209655350170889

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

std::string to_binary(int x) {
    std::string res;

    while (x > 0) {
        res = std::to_string(x % 2) + res;
        x /= 2;
    }

    while (res.size() < 8) {
        res = "0" + res;
    }

    return res;
}

int from_binary(const std::string &s) {
    int res = 0;

    for (int i = 0; i < s.size(); i++) {
        res = res * 2 + (s[i] - '0');
    }

    return res;
}

std::string encode(const std::string& s) {

    assert(s.size() % 2 == 0);

    std::string res = "";
    for (int i = 0; i < s.size(); i += 2) {
        res += static_cast<char>(std::stoi(s.substr(i, 2)) + ' ');
    }

    return res;
}

std::string decode(const std::string& s) {
    std::string res = "";

    // Проходим по строке с шагом 1, т.к. каждый символ был преобразован
    for (int i = 0; i < s.size(); i++) {
        // Преобразуем символ обратно в число, вычитая пробел
        int num = static_cast<int>(s[i]) - ' ';
        
        // Преобразуем число в строку и добавляем к результату
        res += std::to_string(num);
    }

    return res;
}


// Decoding function
std::string test(const std::vector<int>& v) {
    std::string decoded_string;
    for (int val : v) {
        // Convert the integer value back to its binary representation
        std::string binary = to_binary(val);

        // Split the binary into 8-bit chunks (representing a character)
        for (int i = 0; i < 4; ++i) {
            std::string char_binary = binary.substr(i * 8, 8);
            int char_val = from_binary(char_binary);
            decoded_string += static_cast<char>(char_val);
        }
    }
    return decoded_string;
}


void Run_4_Encode() {
    std::string s = "aaaa";
    assert(s.size() % 4 == 0);

    std::vector<int> v(s.size() / 4);
    for (int i = 0; i < s.size() / 4; i++) {
        v[i] = from_binary(to_binary(s[i * 4]) + to_binary(s[i * 4 + 1]) + to_binary(s[i * 4 + 2]) + to_binary(s[i * 4 + 3]));
    }

    std::string res_code = "";
    for (int i = 0; i < v.size(); i++) {
        res_code += encode(std::to_string(v[i]));
    }

    std::cout << res_code << std::endl;
}

void Run_4_Decode() {
    std::string s = "-b`gP1e8)/1SOWf1d?uo";
    std::string stringVector = "";

    for (int i = 0; i < s.size(); i++) {
        stringVector += decode(std::string(1, s[i]));
    }

    std::cout << stringVector << std::endl;

    std::vector<int> intVector;

    for (char c : stringVector) {
        intVector.push_back(c - '0');
    }
   
    std::cout << test(intVector) << std::endl;
}


