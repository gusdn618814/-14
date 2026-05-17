#include "LinkedList.h"

/* 공백 리스트를 생성하고 Head를 NULL로 초기화 */
LinkedList* createLinkedList() {
    LinkedList* li = (LinkedList*)malloc(sizeof(LinkedList));
    if (li == NULL) return NULL;
    li->head = NULL;
    li->size = 0;
    return li;
}

/* 모든 노드의 메모리를 해제하고 리스트 구조체 소멸 */
int destroyLinkedList(LinkedList* li) {
    if (li == NULL) return -1;
    PointType* cur = li->head;
    while (cur != NULL) {
        PointType* next = cur->next;
        free(cur);
        cur = next;
    }
    free(li);
    return 0;
}

/* 리스트가 비어있으면 true(1), 아니면 false(0) 반환 */
int isEmptyLinkedList(LinkedList* li) {
    if (li == NULL) return 1;
    return (li->size == 0) ? 1 : 0;
}

/* 현재 리스트에 포함된 노드의 총 개수 반환 */
int sizeLinkedList(LinkedList* li) {
    if (li == NULL) return 0;
    return li->size;
}

/* 리스트의 맨 앞에 새로운 노드 삽입 */
LinkedList* insertFirstLinkedList(LinkedList* li, PointType item) {
    if (li == NULL) return NULL;
    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    if (nPtr == NULL) return NULL;
    nPtr->x    = item.x;
    nPtr->y    = item.y;
    nPtr->next = li->head;
    li->head   = nPtr;
    li->size++;
    return li;
}

/* 리스트의 맨 뒤에 새로운 노드 삽입 */
LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
    if (li == NULL) return NULL;
    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    if (nPtr == NULL) return NULL;
    nPtr->x    = item.x;
    nPtr->y    = item.y;
    nPtr->next = NULL;

    if (li->head == NULL) {
        li->head = nPtr;
    } else {
        PointType* cur = li->head;
        while (cur->next != NULL) cur = cur->next;
        cur->next = nPtr;
    }
    li->size++;
    return li;
}

/* 특정 노드(pre) 다음에 새로운 노드 삽입 (pre==NULL이면 맨 앞에 삽입) */
LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item) {
    if (li == NULL) return NULL;
    if (pre == NULL) {
        return insertFirstLinkedList(li, item);
    }
    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    if (nPtr == NULL) return NULL;
    nPtr->x    = item.x;
    nPtr->y    = item.y;
    nPtr->next = pre->next;
    pre->next  = nPtr;
    li->size++;
    return li;
}

/* 리스트의 at번째 위치(0-based)에 새로운 노드 삽입 */
LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item) {
    if (li == NULL || at < 0 || at > li->size) return NULL;
    if (at == 0) return insertFirstLinkedList(li, item);

    PointType* cur = li->head;
    for (int i = 0; i < at - 1; i++) cur = cur->next;
    return insertItemLinkedList(li, cur, item);
}

/* 첫 번째 노드를 삭제하고 데이터 반환 */
PointType deleteFirstLinkedList(LinkedList* li) {
    PointType result = {-1, -1, NULL};
    if (li == NULL || li->head == NULL) return result;
    PointType* temp = li->head;
    result          = *temp;
    result.next     = NULL;
    li->head        = temp->next;
    free(temp);
    li->size--;
    return result;
}

/* 마지막 노드를 삭제하고 데이터 반환 */
PointType deleteLastLinkedList(LinkedList* li) {
    PointType result = {-1, -1, NULL};
    if (li == NULL || li->head == NULL) return result;

    if (li->head->next == NULL) {
        return deleteFirstLinkedList(li);
    }
    PointType* cur = li->head;
    while (cur->next->next != NULL) cur = cur->next;
    result      = *(cur->next);
    result.next = NULL;
    free(cur->next);
    cur->next = NULL;
    li->size--;
    return result;
}

/* 특정 위치(pos, 0-based)의 노드를 삭제하고 데이터 반환 */
PointType deleteAtLinkedList(LinkedList* li, int at) {
    PointType result = {-1, -1, NULL};
    if (li == NULL || at < 0 || at >= li->size) return result;
    if (at == 0) return deleteFirstLinkedList(li);

    PointType* cur = li->head;
    for (int i = 0; i < at - 1; i++) cur = cur->next;
    PointType* temp = cur->next;
    result          = *temp;
    result.next     = NULL;
    cur->next       = temp->next;
    free(temp);
    li->size--;
    return result;
}

/* 특정 위치(pos, 0-based)의 데이터를 반환 */
PointType getItemLinkedList(LinkedList* li, int pos) {
    PointType result = {-1, -1, NULL};
    if (li == NULL || pos < 0 || pos >= li->size) return result;
    PointType* cur = li->head;
    for (int i = 0; i < pos; i++) cur = cur->next;
    return *cur;
}

/* 특정 위치(pos, 0-based)의 데이터를 새로운 값으로 교체 */
LinkedList* replaceItemLinkedList(LinkedList* li, int pos, PointType item) {
    if (li == NULL || pos < 0 || pos >= li->size) return NULL;
    PointType* cur = li->head;
    for (int i = 0; i < pos; i++) cur = cur->next;
    cur->x = item.x;
    cur->y = item.y;
    return li;
}

/* pre 위치의 다음 데이터를 반환 (순차 탐색용) */
PointType* nextItemLinkedList(LinkedList* li, PointType* pre) {
    if (li == NULL) return NULL;
    if (pre == NULL) return li->head;
    return pre->next;
}

/* 모든 노드의 데이터를 순서대로 출력 */
int printLinkedList(LinkedList* li) {
    if (li == NULL) return -1;
    printf("=== 현재 리스트 (크기: %d) ===\n", li->size);
    if (li->size == 0) {
        printf("  (비어 있음)\n");
        return 0;
    }
    PointType* cur = li->head;
    int i = 0;
    while (cur != NULL) {
        printf("  [%d] %d\n", i++, cur->x);
        cur = cur->next;
    }
    printf("==============================\n");
    return 0;
}
