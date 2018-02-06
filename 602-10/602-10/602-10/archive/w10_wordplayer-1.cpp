// AUTHOR Jiahao CHEN tobychen@bu.edu
// AUTHOR Yue SUN yuesun@bu.edu
// AUTHOR Yuning QIU qiuyn@bu.edu
// AUTHOR Xinran ZHANG zhangxr@bu.edu

//
//  main.cpp
//  602-10

//  Copyright © 2016年 Boston University. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <map>

using namespace std;



int main(int argc, const char * argv[]) {
    ifstream file;
    string mid, input_string;
    int input_number, i;
    multimap<int, string> input_map;
    multimap<int, string>::iterator it_input_map;
    map<string, int> sort_map;
    map<string, int>::iterator it_sort_map;
    
    file.open("big_wordlist.txt");
    
    cout << file.is_open() << endl;
    
    while ( file >> mid ){
        cout << mid;
        input_map.insert(std::pair<int,string>(mid.length(),mid));
    }
    
    input_number = stod(argv[2]);
    
    it_input_map = input_map.find(input_number);
    
    i = 0;
    
    for ( it_input_map = input_map.begin(); it_input_map != input_map.end(); it_input_map++)
        sort_map[it_input_map->second]=i;
    
    for ( it_sort_map = sort_map.begin(); it_sort_map != sort_map.end(); it_sort_map++)
        cout << it_sort_map->first <<endl;
    
    cout << '.' << endl;
    
    return 0;
}
