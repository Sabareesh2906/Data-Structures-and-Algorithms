#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* back;
     Node (int data1)
     {
        data=data1;
        next=nullptr;
        back=nullptr;
     }
     Node (int data1,Node* next1,Node* back1)
     {
        data=data1;
        next=next1;
        back=back1;
     }

};
Node* convertArrtoLL(vector<int> arr)
{
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->back=mover;
        mover=temp;

    }
    return head;
}
void print(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
int checkval(Node* head,int val)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
       if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;

}

Node* DeletionAtbegin(Node* head)
{
    if(head==nullptr) return head;
    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    delete temp;
    return head;
}

Node* DeleteAtLast(Node* head)
{
    if(head==nullptr||head->next==nullptr) return nullptr;
    Node* temp=head;
    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* last=temp->next;
     temp->next=nullptr;
     last->back=nullptr;
     delete last;

    return head;

}
Node* Deleteknode(Node* head,int k)
{
    int cnt=1;
    Node* knode=head;
    while(knode)
    {
        if(cnt==k)
        break;
        knode=knode->next;
        cnt++;
    }
    Node* prev=knode->back;
    Node* front=knode->next;
    if(prev==nullptr&&front==nullptr)
    return NULL;
    else if(prev==NULL)
    return DeletionAtbegin(head);
    else if(front==NULL)
    return DeleteAtLast(head);

    prev->next=front;
    front->back=prev;
    delete knode;
    
    
    return head;
}
Node* DeleteEle(Node* head,int val)
{
    Node* knode=head;
    while(knode)
    {
        if(knode->data==val)
        break;
        knode=knode->next;
      
    }
    Node* prev=knode->back;
    Node* front=knode->next;
    if(prev==nullptr&&front==nullptr)
    return NULL;
    else if(prev==NULL)
    return DeletionAtbegin(head);
    else if(front==NULL)
    return DeleteAtLast(head);

    prev->next=front;
    front->back=prev;
    delete knode;
    
    
    return head;
}

Node* Insertbegin(Node* head,int val)
{
    // Node* newnode=new Node(val);
    // newnode->next=head;
    // head=newnode;
    // return head;
    Node* newnode=new Node(val,head,nullptr);
    head->back=newnode;
    return newnode;
}
Node* Insertlast(Node* head,int val)
{
    if(head==nullptr)
    {
        return new Node(val);
    }
    Node* newnode=new Node(val);
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->back=temp;
    return head;
}
Node* InsertAtk(Node* head,int k,int val)
{
    int cnt=0;
   Node* temp=head;
   if(k==1)
   {
       return Insertbegin(head,val);
      
   }
    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        temp=temp->next;
       
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
 return head;
    
}


int main()
{
  vector<int> arr={1,2,3,4,5};
  Node* head=convertArrtoLL(arr);

  //Deletion 

  //at begining
  //head=DeletionAtbegin(head);
   
  //at last
  //head=DeleteAtLast(head);

  //at kth node
  //head=Deleteknode(head,5);

  //delete by element
  //head=DeleteEle(head,3);



  //Insertion

  //at begining
  //head=Insertbegin(head,0);

  //atlast
  //head=Insertlast(head,6);

  //Insert at position
  //head=InsertAtk(head,5,10);

  


//   cout<<checkval(head,7);
  print(head);

}
