 ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        int h=count/2;
        if(count%2!=0){
           while(count!=h+1){
                temp=temp->next;
                count--;
           }
        }
        else{
            while(count!=h){
                temp=temp->next;
                count--;
            }
        }
        return temp;
    }