#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
char Stack[100];
int myindex = -1;
void push(char a) {
    myindex++;
    Stack[myindex] = a;
}
char pop() {
    char tmp = Stack[myindex];
    myindex--;
    return tmp;
}
int empty() {
    if (myindex < 0)
        return 1;
    return 0;
}
char top() {
    return Stack[myindex];
}

int high(char a) {
    if (empty() == 1)
        return 1;
    else if (top() == '(') {
        if (a != '(')
            return 1;
    }

    else if (top() == '+' || top() == '-') {
        if (a == '*' || a == '/')
            return 1;
        else
            return 0;
    }
    return 0;
}
int main() {
    char infix[100] = { 0, };
    char res[100] = { 0, };
    int ridx = 0;
    int i, z;

    scanf("%s", &infix);

    for (i = 0; infix[i]; i++) {
        if (infix[i] == ' ')
            continue;
        if (infix[i] >= '0' && infix[i] <= '9') {
            res[ridx] = infix[i];
            ridx++;
        }
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (top() != '(') {
                res[ridx] = pop();
                ridx++;
            }
            pop();
        }
        else {
            while (high(infix[i]) == 0) {
                res[ridx] = pop();
                ridx++;
            }
            push(infix[i]);
        }
    }
    while (empty() == 0) {
        res[ridx] = pop();
        ridx++;
    }
    for (z = 0; res[z]; z++)
        printf("%c ", res[z]);
    printf("\n");

    return 0;
}