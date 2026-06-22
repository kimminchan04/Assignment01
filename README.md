# Assignment01

C 언어로 구현한 **스택 기반 주소록(연락처) 관리 프로그램**입니다.  
이름과 주소를 스택에 Push/Pop하고, 삭제·복원·출력 기능을 제공합니다.

## 주요 기능

| 메뉴 | 기능 |
|------|------|
| 1 Push | 주소 추가 (또는 삭제 스택에서 복원) |
| 2 Pop | 주소 꺼내기 → 삭제 스택으로 이동 |
| 3 Print | 주소 스택·삭제 스택 전체 출력 |
| 4 Remove | 이름으로 특정 항목 삭제 |
| 5 Close | 프로그램 종료 |

### Push 세부 동작

- **복원(1)**: 삭제 스택(`d`)에서 하나를 꺼내 주소 스택(`s`)으로 되돌림
- **신규 추가(2)**: 이름·주소 입력 후 주소 스택에 Push

## 기술 스택

| 구분 | 기술 |
|------|------|
| Language | C |
| 자료구조 | Stack (배열 기반) |
| Platform | Windows (`windows.h` — UTF-8 콘솔) |

## 프로젝트 구조

```
Assignment01/
└── Assignement01/
    └── Code01.c    # 스택 구현 + 주소록 main
```

## 실행 방법

### Windows

```bash
gcc Assignement01/Code01.c -o addressbook.exe
addressbook.exe
```

프로그램은 UTF-8 콘솔(`SetConsoleOutputCP(65001)`)을 사용합니다.

## 자료구조

```c
typedef struct {
  char name[50];
  char address[100];
} Information;

typedef struct {
  int max;
  int ptr;
  Information* stk;
} Stack;
```

- **주소 스택 `s`**: 현재 저장된 연락처 (최대 10개)
- **삭제 스택 `d`**: Pop으로 제거된 연락처 (복원용)

## 학습 포인트

- 스택 Push / Pop / Peek 패턴
- 두 개의 스택을 이용한 **Undo(복원)** 개념
- `calloc`, `free`를 이용한 동적 배열 관리
- `strcmp` 기반 이름 검색 삭제
