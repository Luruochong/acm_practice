#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;
long long parts[1000];

void init(){
    for(int i=0;i<1000;i++){
        parts[i] = 0;
    }   
}

string long_number_to_string(){
    bool nothing_to_print = true;
    //cout << "big number : ";
    
    stringstream ss;

    for(int i=999;i>=0;i--){
        if(nothing_to_print && parts[i] == 0)
            continue;
        else
            nothing_to_print = false;

        //cout << i << ":" << setfill('0') << setw(6) << parts[i] << " ";
        ss << setfill('0') << setw(6) << parts[i];
    }
    //cout << endl;
    return ss.str();   
}

int main(){
    string s;
    int n;
    while(cin>>s>>n){
        init();
        int base;
        int dot_position = s.find('.');  
        int zero_count = 0;
        long long base_ll = 0;
        if (dot_position != std::string::npos){
            zero_count = (6 - dot_position -1) * n; 
            string s_formated = s.erase(dot_position, 1);        
            //cout << s_formated << " " << zero_count << endl;
            base_ll = atoi(s_formated.c_str());
        }
        else{
            base_ll = atoi(s.c_str());
        }

        //cout << "zero_count:" << zero_count << endl;
        
        parts[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=999;j>=0;j--){
                parts[j] = parts[j] * base_ll;
                long long devident = parts[j] / 1000000;
                long long reminder = parts[j] % 1000000;
                
                parts[j+1] += devident;
                parts[j] = reminder;
                
                long long devident2 = parts[j+1] / 1000000;
                long long reminder2 = parts[j+1] % 1000000;

                parts[j+2] += devident2;
                parts[j+1] = reminder2;
            }
        }

        string very_long = long_number_to_string();
        
        very_long.erase(0, min(very_long.find_first_not_of('0'), very_long.size()-1));
        
        int digits_count = very_long.length();
        if(zero_count == 0){ 
            cout << very_long << endl;
            continue;
        }

        if(zero_count > digits_count){
            int pad_zero_count = zero_count - digits_count;
            very_long.insert(0, pad_zero_count, '0');
            very_long.insert(0, 1, '.');
        }
        else{

            int insert_pos = digits_count - zero_count;
            very_long.insert(insert_pos, 1, '.');
        }

        int zero_pos; 
        for(zero_pos=very_long.length()-1; zero_pos>0; zero_pos--){
            if(very_long[zero_pos] != '0'){
                break;
            }
        }
        very_long = very_long.substr(0, zero_pos+1);
        digits_count = very_long.length();
        if(very_long[digits_count-1] == '.'){
            very_long.erase(digits_count-1, 1);
        }

        cout << very_long << endl;
    }
    return 0;
}
