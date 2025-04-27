#include "stdio.h"
#include "stdlib.h"

/*
 *
 * 2.Add Two Number (Leetcode)
 * @author Marcos V. Silva Almeida
 * @date 04.27.2025
 * 
 */ 

struct ListNode {
    int val;
    struct ListNode *next;
};

void print_ListNode(struct ListNode* p) {
  while(p) {
    printf("-> %d ", p->val);
    p = p->next;
  }
  printf("\n");
}

struct ListNode* createNode(int v) {
  struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
  new->val = v;
  new->next = NULL;
  return new;
}

void scan_ListNode(int r, struct ListNode* p) {
  for(int i = 0; i < r; i++) {
    int temp;
    scanf("%d", &temp);
    if(i == 0) {
      p->val = temp;
      continue;
    }
    p->next = createNode(temp);
    p = p->next;
  }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode dummy;
  struct ListNode* res = &dummy;
  int remainder = 0, carry = 0;

  while(l1 || l2 || carry) {
    int sum = carry;
    if(l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if(l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    carry = sum / 10;
    sum = sum % 10;
    res->next = createNode(sum);
    res = res->next;
  }

  return dummy.next;
}

int main() {
  struct ListNode a;
  struct ListNode b;
  struct ListNode* res;
  int n;

  scanf("%d", &n);
  scan_ListNode(n, &a);

  scanf("%d", &n);
  scan_ListNode(n, &b);
  
  print_ListNode(&a);
  print_ListNode(&b);

  res = addTwoNumbers(&a, &b);
  print_ListNode(res);
  return 0;
}