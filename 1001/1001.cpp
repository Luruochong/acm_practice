#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;
long long parts[1000];

void init(){
    for(int i=0;i<1000;i++){
        parts[i] = 0;
    }   
}

void print_whole(){
    bool nothing_to_print = true;
    cout << "big number : ";
    for(int i=999;i>=0;i--){
        if(nothing_to_print && parts[i] == 0)
            continue;
        else
            nothing_to_print = false;

        cout << i << ":" << setfill('0') << setw(6) << parts[i] << " ";
    }
    cout << endl;

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
            cout << s_formated << " " << zero_count << endl;
            base_ll = atoi(s_formated.c_str());
        }
        else{
            base_ll = atoi(s.c_str());
        }

        cout << base_ll << " " << n << endl;
        print_whole();
        parts[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=999;j>=0;j--){
                parts[j] = parts[j] * base_ll;
                long long devident = parts[j] / 1000000;
                long long reminder = parts[j] % 1000000;
                if(devident>0){
                    parts[j+1] = devident;
                    parts[j] = reminder;
                }
            }
        }

        print_whole();

    }
    return 0;
}
