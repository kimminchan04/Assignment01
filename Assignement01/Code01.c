#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct {
    char name[50];
    char address[100];
} Information;
typedef struct {
    int max;
    int ptr;
    Information* stk;
} Stack;
int Initialize(Stack* s, int max) {
    if ((s->stk = calloc(max, sizeof(Information))) == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    s->ptr = 0;
    return 0;
}
int Push(Stack* s, Information v) {
    if (s->ptr > s->max) {
        
        return -1;
    }
    s->stk[s->ptr++] = v;
    return 0;
}
int Pop(Stack* s, Information* v) {
    if (s->ptr <= 0) {
        
        return -1;
    }
    *v = s->stk[--s->ptr];
    
    return 0;
}
int Restore(Stack* s, Stack* d) {
    Information e;
    if (Pop(d, &e) == -1) {
        
        return -1;
    }
    Push(s, e);
    return 0;
}
int Remove(Stack* s, char n[]) {
    for(int i = 0; i < s->ptr; i++) {
        if (strcmp(s->stk[i].name, n) == 0) {
            for (int j = i; j < s->max; j++) {
                s->stk[j] = s->stk[j + 1];
            }
            s->ptr--;
        }
    }
    return 0;
}
void Print(Stack* s) {
    for (int i = 0; i < s->ptr; i++) {
        printf("%d:\n", i + 1);
        printf("이름 = %s\n", s->stk[i].name);
        printf("주소 = %s\n", s->stk[i].address);
    }
}
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Stack s;
    Stack d;
    if (Initialize(&s, 10) == -1) {
        printf("주소 스택 생성을 실패했습니다");
        return 0;
    }
    if (Initialize(&d, 10) == -1) {
        printf("삭제 주소 스택 생성을 실패했습니다");
        return 0;
    }
    while (1) {
        int c;
        printf("Push = 1, Pop = 2, Print = 3, Remove = 4, Close = 5: ");
        scanf("%d", &c);
        if (c == 5){
            break;
        }
        Information i;
        switch(c) {
            case 1:
                int a;
                printf("삭제 주소록에 있는 한 개 데이터를 복원하시겠습니까? 1 = 네, 2 = 아니요: ");
                scanf("%d", &a);
                if (a == 1) {
                    if (Restore(&s, &d) == -1) {
                        printf("삭제 주소 스택에 데이터가 없습니다\n");
                    } else {
                        printf("데이터를 복원했습니다\n");
                    }
                    break;    
                } else if (a == 2) {
                printf("데이터 이름: ");
                scanf("%s", i.name);
                printf("데이터 주소: ");
                scanf("%s", i.address);
                if (Push(&s, i) == -1) {
                    printf("Stack is full");
                }
                break;
                } 
            case 2:
                if (Pop(&s, &i) == -1) {
                    printf("Stack is Empty");
                } else {   
                    printf("이름이 %s이고 주소가 %s인 데이터가 나왔습니다\n", 
i.name, i.address);
                    Push(&d, i);
                }
                break;
            case 3: 
                printf("<주소 스택>\n");
                Print(&s);
                printf("\n");
                printf("<삭제 주소 스택>\n");
                Print(&d);
                break;
            case 4:
                char n[50];
                printf("삭제할 데이터의 이름: ");
                scanf("%s", n);
                Remove(&s, n);
                break;
        }
    }
    free(s.stk);
    free(d.stk);
    
    return 0;
}