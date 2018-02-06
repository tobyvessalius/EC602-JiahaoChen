// AUTHOR Jiahao CHEN tobychen@bu.edu
// AUTHOR Yue SUN yuesun@bu.edu
// AUTHOR Yuning QIU qiuyn@bu.edu
// AUTHOR Xinran ZHANG zhangxr@bu.edu
//  w10_wordplayer.cpp
//  602-10
//  Copyright © 2016年 Boston University. All rights reserved.
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
int main(int argc, const char * argv[]) {
    std::ifstream file;
    std::string mid, mid_mid, input_string, mid_string, mid_input_string;
    int input_number, i, a, c;
    std::map<int, std::map<std::string, std::vector<std::string>>> big_map;
    std::map<std::string, std::vector<std::string>> small_map;
    std::map<std::string, std::vector<std::string>>::iterator it_small_map;
    std::vector<std::string> string_list;
    file.open(argv[1]);
    while ( file >> mid ) {
        mid_mid = mid;
        sort(mid_mid.begin(), mid_mid.end());
        big_map[mid.size()][mid_mid].push_back(mid);
    }
    while ( true ) {
        std::cin >> input_string;
        std::cin >> input_number;
        sort(input_string.begin(), input_string.end());
        string_list.clear();
        if ( input_number == 0 ) {
            break;
        } else if ( input_number == input_string.length() ) {
            string_list = big_map[input_number][input_string];
        } else if ( input_number != input_string.length() ) {
            small_map = big_map[input_number];
            for ( it_small_map = small_map.begin() ; it_small_map
                 != small_map.end() ; it_small_map++ ) {
                    c = 0;
                    mid_string = it_small_map->first;
                    mid_input_string = input_string;
                    for ( a = 0 ; a < mid_input_string.length() ; a++ ) {
                        if (mid_input_string[a] == mid_string[0]) {
                            mid_string.erase(mid_string.begin());
                            c++;
                        }
                    }
                    if ( c == input_number ) {
                        for ( auto e : it_small_map->second)
                            string_list.push_back(e);
                    }
                }
            }
            sort(string_list.begin(), string_list.end());
            for ( i = 0 ; i < string_list.size() ; i++ )
                std::cout << string_list[i] << std::endl;
            std::cout << '.' << std::endl;
        }
    return 0;
}
