//Backjoon Problem No.25501
//https://www.acmicpc.net/problem/25501
//Mist16, 2022-12-25

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int recursionCount;

int recursion(const char* s, int l, int r) {
    recursionCount++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    recursionCount = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
    {
        char str[1002];
        cin >> str;
        cout << isPalindrome(str) << " ";
        cout << recursionCount << endl;
    }

}