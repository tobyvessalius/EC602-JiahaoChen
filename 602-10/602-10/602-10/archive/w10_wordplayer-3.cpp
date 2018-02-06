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
    string mid, input_string, mid_string, mid_input_string;
    int input_number, i, j, k;
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

    
    i = 0;
    
    for ( it_input_map = input_map.begin(); it_input_map != input_map.end(); it_input_map++)
    {
        if ( it_input_map->first == input_number )
        {
            mid_string=it_input_map->second;
            mid_input_string = input_string;
            
            for (k=0;k<mid_input_string.length();k++)
                for ( j=0;j<mid_string.length();j++)
                {
                    if (mid_string[j]==mid_input_string[k])
                        {
                            mid_string.erase(mid_string.begin()+j);
                            mid_input_string.erase(mid_input_string.begin()+k);
                        }
                }
            //cout << sort_string_value << endl;
            if (mid_string.empty())
            {
                cout << it_input_map->second;
                sort_map[it_input_map->second]=i;
            }
        }
    }
    
    
    
    for ( it_sort_map = sort_map.begin(); it_sort_map != sort_map.end(); it_sort_map++)
        cout << it_sort_map->first <<endl;
    
    cout << '.' << endl;
    
    return 0;
}
