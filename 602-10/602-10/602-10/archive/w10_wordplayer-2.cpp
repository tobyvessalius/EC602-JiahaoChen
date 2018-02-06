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
    string mid, input_string, mid_string;
    int input_number, i, j, k, input_value, sort_string_value;
    multimap<int, string> input_map;
    multimap<int, string>::iterator it_input_map;
    map<string, int> sort_map;
    map<string, int>::iterator it_sort_map;
    
    file.open("big_wordlist.txt");
    
    while ( file >> mid ){
        input_map.insert(std::pair<int,string>(mid.length(),mid));
    }
    
    input_string = argv[1];
    input_number = stod(argv[2]);
    input_value = 0;

    
    for(i=0;i<input_string.length();i++)
        input_value += input_string[i];
    //cout << input_value << endl;
    
    i = 0;
    
    for ( it_input_map = input_map.begin(); it_input_map != input_map.end(); it_input_map++)
    {
        if ( it_input_map->first == input_number )
        {
            mid_string=it_input_map->second;
            sort_string_value = 0;
            for ( j=0;j<mid_string.length();j++)
                for (k=0;k<input_string.length();k++)
                {
                    if (mid_string[j]==input_string[k])
                        sort_string_value += mid_string[j];
                }
            //cout << sort_string_value << endl;
            if (sort_string_value==input_value)
                sort_map[it_input_map->second]=i;
        }
    }
    
    
    
    for ( it_sort_map = sort_map.begin(); it_sort_map != sort_map.end(); it_sort_map++)
        cout << it_sort_map->first <<endl;
    
    cout << '.' << endl;
    
    return 0;
}
