#include<stdio.h>

char Stack[100];
int idx = -1;

void push(char a) {
    idx++;
    Stack[idx] = a;
}

char pop() {
    char tmp = Stack[idx];
    idx--;
    return tmp;
}

int main() {
    char postfix[100] = { 0, };
    int v0, v1, v2, i, ch, myindex, result;
    myindex = 0;
    while (scanf("%c", &ch) != EOF) {
        postfix[myindex] = ch;
        myindex++;
    }
    for (i = 0; postfix[i]; i++) {
        if (postfix[i] == ' ')
            continue;
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            v0 = postfix[i] - '0';
            push(v0);
        }
        else if (postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-') {
            v2 = pop();
            v1 = pop();
            switch (postfix[i]) {
            case '+': push(v1 + v2); break;
            case '-': push(v1 - v2); break;
            case '*': push(v1 * v2); break;
            case '/': push(v1 / v2); break;
            }
        }
    }
    result = pop();
    printf("%d\n", result);

    return 0;
}