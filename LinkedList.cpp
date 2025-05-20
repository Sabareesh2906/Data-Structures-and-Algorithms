#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
     Node (int data1)
     {
        data=data1;
        next=nullptr;
     }
     Node (int data1,Node* next1)
     {
        data=data1;
        next=next1;
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
     delete temp->next;
     temp->next=nullptr;

    return head;

}
Node* Deleteknode(Node* head,int k)
{
    int cnt=1;
    Node* prev=NULL;
    Node* temp=head;
    if(head==nullptr) return head;
    if(k==1)
    {
        head=head->next;
        delete temp;
        return head;
    }
    while(temp)
    {
        if(cnt==k)
        {

           prev->next=prev->next->next;
           delete temp;
           break;
        }
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    return head;
}
Node* DeleteEle(Node* head,int val)
{
    if(head==nullptr) return head;
    if(head->data==val)
    {
         Node* temp=head;
    head=head->next;
    delete temp;
    return head;
    }
    Node* temp=head->next;
    Node* prev=head;
    while(temp)
    {
        if(temp->data==val)
        {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;

    }
    return head;
}

Node* Insertbegin(Node* head,int val)
{
    // Node* newnode=new Node(val);
    // newnode->next=head;
    // head=newnode;
    // return head;
    Node* newnode=new Node(val,head);
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
    return head;
}
Node* InsertAtk(Node* head,int k,int val)
{
    int cnt=1;
    Node* temp=head;
    Node* prev=NULL;
    if(head==nullptr)
    {
        if(k==1){
         Node* newnode=new Node(val);
         return head;
            }
            else
            return nullptr;
    }
    if(k==1){
         Node* newnode=new Node(val,head);
         return newnode;
     }
    
    while(temp)
    {
        if(k==cnt)
        {
            Node* newnode=new Node(val,temp);
            prev->next=newnode;
            break;

        }
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    return head;

    
}
Node* Insertbeforeval(Node* head,int val,int ins)
{
  
    Node* temp=head;
    
    if(head==nullptr)
    {
        return nullptr;
    }
    if(head->data==val){
         Node* newnode=new Node(ins,head);
         return newnode;
     }
    
    while(temp->next!=nullptr)
    {
        if(temp->next->data==val)
        {
           Node* newnode=new Node(ins,temp->next);
           temp->next=newnode;
           break;

        }
        temp=temp->next;
       
       
    }
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
  //head=Deleteknode(head,6);

  //delete by element
  //head=DeleteEle(head,3);



  //Insertion

  //at begining
  //head=Insertbegin(head,0);

  //atlast
  //head=Insertlast(head,6);

  //Insert at position
  //head=InsertAtk(head,4,10);

  //InsertbeforeVal
  head=Insertbeforeval(head,5,6);


//   cout<<checkval(head,7);
  print(head);

}
