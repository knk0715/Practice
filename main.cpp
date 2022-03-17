#include <string>
#include <vector>
#include <iostream>

using namespace std;

int close(int& present, string& name) {
    int left = 0;
    int present_right = present;
    while(name[present] == 'A') {
        cout << "----------------1--------------" << endl;
        if(present == 0) {
            present = name.length()-1;
            left ++;
            cout << "----------------2--------------" << endl;
        }
        present --;
        left ++;
    }
    
    int right = 0;
    while(name[present_right] == 'A') {
        cout << "----------------3--------------" << endl;
        if(present_right == name.length()-1) {
            present_right = 0;
            right ++;
            cout << "----------------4--------------" << endl;
        }
        present_right --;
        right ++;
    }
    cout << left << "    " << right << endl;
    if(left < right) {
        name[present] = 'A';
        return left;
    }
    else {
        name[present_right] = 'A';
        present = present_right;
        return right;
    }
}

int solution(string name) {
    int answer = 0;
    for(int i=0;i<name.length();i++) {
        if(name[i]<=78) {
            int up = name[i]-'A';
            answer += up;
        }
        else if(name[i]>78) {
            int down = 91-name[i];
            answer += down;
        }
    }
    int present = 0;
    int move = 0;
    string compare = "";
    for(int i=0;i<name.length();i++) {
        compare +='A';
    }

    while(name != compare) {
        move += close(present,name);
        cout << move <<"    "<<present << "    " << name << endl;
    }
    return answer+move;
}
 