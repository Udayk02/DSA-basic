void transform(){
    Node *tmp = NULL;
    tmp = new Node();
    Node *tmp2 = NULL;
    tmp2 = head;
    tmp = head;
    int i=0;
    while(tmp->addr!=NULL){
        tmp = tmp->addr;
        i++;
    }
    head = tmp;
    while(i>=1){
        Node *tmp1 = NULL;
        tmp1 = tmp2;
        for(int j=1;j<i;j++){
            tmp1 = tmp1->addr;
        }
        tmp->addr = tmp1;
        tmp = tmp1;
        i--;
    }
}