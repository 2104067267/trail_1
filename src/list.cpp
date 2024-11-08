#include"list.h"
namespace mystl{

list:: list(int _val){
      this->head=(list_node*)malloc(sizeof(list_node));
      this->head->val=_val;
      this->head->next=NULL;
}

void list:: push_back(int val){
    list_node*p=(list_node*)malloc(sizeof(list_node));
    p->next=NULL;
    p->val=val;
    list_node*q=this->head;
    while(q->next){
        q=q->next;
    }
    q->next=p;
}

void list:: pop_front(){
    list_node*p=this->head;
    this->head=head->next;
    free(p);
}


}
