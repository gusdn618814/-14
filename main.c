#include "LinkedList.h"

void printMenu() {
    printf("\n========== 정수 연결 리스트 메뉴 ==========\n");
    printf("  1. 맨 앞에 추가\n");
    printf("  2. 맨 뒤에 추가\n");
    printf("  3. 특정 위치에 추가\n");
    printf("  4. 특정 위치 삭제\n");
    printf("  5. 전체 목록 출력\n");
    printf("  6. 리스트 크기 확인\n");
    printf("  0. 종료\n");
    printf("==========================================\n");
    printf("선택: ");
}

int main() {
    LinkedList* li = createLinkedList();
    if (li == NULL) {
        printf("리스트 생성 실패\n");
        return 1;
    }

    int choice;
    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            /* 잘못된 입력 처리 */
            while (getchar() != '\n');
            printf("  [오류] 숫자를 입력하세요.\n");
            continue;
        }

        if (choice == 0) {
            /* 종료: 모든 메모리 해제 */
            destroyLinkedList(li);
            printf("\n  모든 메모리를 해제하고 프로그램을 종료합니다.\n");
            break;

        } else if (choice == 1) {
            /* 맨 앞에 추가 */
            int val;
            printf("  추가할 정수 입력: ");
            scanf("%d", &val);
            insertFirstLinkedList(li, (PointType){val, 0, NULL});
            printf("  [%d] 을(를) 맨 앞에 추가했습니다.\n", val);

        } else if (choice == 2) {
            /* 맨 뒤에 추가 */
            int val;
            printf("  추가할 정수 입력: ");
            scanf("%d", &val);
            insertLastLinkedList(li, (PointType){val, 0, NULL});
            printf("  [%d] 을(를) 맨 뒤에 추가했습니다.\n", val);

        } else if (choice == 3) {
            /* 특정 위치에 추가 */
            int pos, val;
            printf("  삽입할 위치(index, 0부터 시작) 입력: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > li->size) {
                printf("  [오류] 유효하지 않은 위치입니다. (0 ~ %d)\n", li->size);
                continue;
            }
            printf("  추가할 정수 입력: ");
            scanf("%d", &val);
            insertAtLinkedList(li, pos, (PointType){val, 0, NULL});
            printf("  [%d] 을(를) %d번 위치에 추가했습니다.\n", val, pos);

        } else if (choice == 4) {
            /* 특정 위치 삭제 */
            if (isEmptyLinkedList(li)) {
                printf("  [오류] 리스트가 비어 있습니다.\n");
                continue;
            }
            int pos;
            printf("  삭제할 위치(index, 0부터 시작) 입력: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= li->size) {
                printf("  [오류] 유효하지 않은 위치입니다. (0 ~ %d)\n", li->size - 1);
                continue;
            }
            PointType deleted = deleteAtLinkedList(li, pos);
            printf("  %d번 위치의 값 [%d] 을(를) 삭제했습니다.\n", pos, deleted.x);

        } else if (choice == 5) {
            /* 전체 목록 출력 */
            printLinkedList(li);

        } else if (choice == 6) {
            /* 리스트 크기 확인 */
            printf("  현재 리스트 크기: %d\n", sizeLinkedList(li));

        } else {
            printf("  [오류] 올바른 메뉴 번호를 선택하세요.\n");
        }
    }

    return 0;
}
