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
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream file;
    string mid, input_string, mid_string, mid_input_string;
    int input_number, i, j, k, a;
    multimap<int, string> input_map;
    multimap<int, string>::iterator it_input_map;
    map<string, int> sort_map;
    map<string, int>::iterator it_sort_map;
    file.open("big_wordlist.txt");
    while ( file >> mid ){
        input_map.insert(std::pair<int,string>(mid.length(),mid));
    }
    

    
    while(input_number!=0)
    {
        cin >> input_string;
        cin >> input_number;
     if(input_number==0)
         continue;
    
    i = 0;
    for ( it_input_map = input_map.begin(); it_input_map != input_map.end(); it_input_map++)
    {
        if ( it_input_map->first == input_number )
        {
            mid_string=it_input_map->second;
            mid_input_string = input_string;
            a = 0;
            
            for (k=0;k<mid_input_string.length();k++)
            {
                for ( j=0;j<mid_string.length();j++)
                {
                    if (mid_string[j]==mid_input_string[k])
                        {
                            if (mid_string[j]=='0' || mid_input_string[k]=='0')
                                continue;
                            mid_string[j]='0';
                            mid_input_string[k]='0';
                            a++;
                            
                        }
                }
            }
            if (a==input_number)
            {
                sort_map[it_input_map->second]=i;
            }
        }
    }
        
    for ( it_sort_map = sort_map.begin(); it_sort_map != sort_map.end(); it_sort_map++)
        cout << it_sort_map->first <<endl;
    cout << '.' << endl;
    
    }

}
