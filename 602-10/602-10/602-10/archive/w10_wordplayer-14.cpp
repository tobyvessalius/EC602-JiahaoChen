// AUTHOR Jiahao CHEN tobychen@bu.edu
// AUTHOR Yue SUN yuesun@bu.edu
// AUTHOR Yuning QIU qiuyn@bu.edu
// AUTHOR Xinran ZHANG zhangxr@bu.edu
//
//  w10_wordplayer.cpp
//  602-10
//  Copyright © 2016年 Boston University. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <map>

int main(int argc, const char * argv[]) {
    std::ifstream file;
    std::string mid, input_string, mid_string, mid_input_string;
    int input_number, i, j, k, a;
    std::multimap<int, std::string> input_map;
    std::multimap<int, std::string>::iterator it_input_map;
    std::map<std::string, int> sort_map;
    std::map<std::string, int>::iterator it_sort_map;
    bool flag = true;
    file.open(argv[1]);
    while ( file >> mid ) {
        input_map.insert(std::pair<int, std::string>(mid.length(), mid));
    }
    while ( flag ) {
        try {
        std::cin >> input_string;
        std::cin >> input_number;
            if (input_number == 0)
                flag = false;
    i = 0;
    for ( it_input_map = input_map.begin() ; it_input_map
         != input_map.end() ; it_input_map++ ) {
        if ( it_input_map->first == input_number ) {
            mid_string = it_input_map->second;
            mid_input_string = input_string;
            a = 0;
            for ( k = 0 ; k < mid_input_string.length() ; k++ ) {
                for ( j = 0 ; j < mid_string.length() ; j++ ) {
                    if ( mid_string[j] == mid_input_string[k] ) {
                            if (mid_string[j]
                                == '0' || mid_input_string[k] == '0')
                                continue;
                            mid_string[j] = '0';
                            mid_input_string[k] = '0';
                            a++;
                    }
                }
            }
            if ( a == input_number ) {
                sort_map[it_input_map->second] = i;
            }
        }
    }
    for ( it_sort_map = sort_map.begin() ; it_sort_map
         != sort_map.end() ; it_sort_map++ )
        std::cout << it_sort_map->first << std::endl;
    if ( input_number != 0 )
        std::cout << '.' << std::endl;
    sort_map.clear();
        }
        catch(std::exception) {
        }
    }
}
