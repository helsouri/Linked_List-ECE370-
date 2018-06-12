#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <sstream>
#include <conio.h>
#define max_num_lines 50

using namespace std;

struct myNode
{
   string name= "NULL"; // empty stings are set to NULL
   int score=-1; // empty scores are set to -1
   struct myNode *next;
}*top=NULL;

void myInsert(int value, string tmpName)
{
    /* 1. allocate node */
    struct myNode* newNode;
    newNode =new (myNode);
    struct myNode* current;
    /* 2. put in the data */
    newNode->score = value;
    newNode->name=tmpName;
    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    newNode->next = NULL;
    /* 4. If the Linked List is empty, then make the new node as head */
    if (top == NULL)
    {
       top = newNode;
    }
    else
    {
        current=top;
        while(current->next != NULL)
        {
            if(current->name == tmpName)
            {
                current->score=value;
            }
            current=current->next;
        }
        current->next = newNode;
    }
  // cout<<endl<<"insertion is successful"<<endl;
}

void myDelete(string tmpName)
{
    struct myNode *current, *previous;
    previous=NULL;
    for(current=top;current->next!=NULL;previous=current, current=current->next)
    {
        if(current->name==tmpName)
        {
            if(previous==NULL)
                top=current->next;
            else{
                previous->next=current->next;
            }
            free(current);
        }
    }
}

void visit()
{
   if(top == NULL)
      cout<<endl<<"Stack is Empty"<<endl;
   else{
     myNode *temp = top;
      while(temp->next != NULL)
        {
            cout<<"---> "<<temp->name<<" "<<temp->score<<endl;
            temp = temp -> next;
        }
      cout<<"---> "<<temp->name<<" "<<temp->score<<endl<<"---> NULL "<<endl;
   }
}

void mySort()
{
    struct myNode *temp=top;
    int count1=0, tmpValue;
    string tmpStr;
    while(temp->next != NULL)
    {
        temp=temp->next;
        count1++;
    }
    temp=top;
    for(int i=0;i<count1; i++)
    {
        while(temp->next != NULL)
        {
            if (temp->name >= temp->next->name )
            {
                tmpValue=temp->score;
                temp->score=temp->next->score;
                temp->next->score=tmpValue;

                tmpStr = temp->name;
                temp->name=temp->next->name;
                temp->next->name= tmpStr;
            }
            temp= temp->next;
        }
        temp=top;
    }
}

void mySearch(string tmpName)
{
    struct myNode *temp=top;
    bool found=false;
    while(temp->next != NULL)
    {
        if(temp->name == tmpName)
        {
            cout<<temp->name<<" "<<temp->score<<endl;
            found==true;
            break;
        }
        temp=temp->next;
    }
    if(temp->next == NULL && found== false)
    {
        cout<<tmpName<<" does not exist in the link list just like my will to live because of this class :P"<<endl;
    }
}

int getData(char filename[], string str[max_num_lines])
{
    ifstream ins;
    ins.open(filename);
    int i=0;
    while (!ins.eof())
    {
        getline(ins, str[i]);
        i++;
    }
    return(i);
}

int parseData(int numLines, string data[max_num_lines], string names[max_num_lines], string action[max_num_lines/2], string scoreStr[max_num_lines], int index[max_num_lines/2])
{
    int i,j=0,k=0, strLength=0, spaceIndex, numActions=0;
    string tempStr;
    for(i=0;i<numLines;i++)
    {
        strLength=0;
        spaceIndex=0; //clear counts
        tempStr=data[i];
        strLength=tempStr.length();
        if(tempStr[0]=='%')
        {
            action[j]=tempStr.substr(1,strLength);
            index[j]=i;
            cout<<endl<<action[j]<<endl<<endl;
            numActions++;
            j++;
        }
        else
        {
            spaceIndex=tempStr.find(' ');
            if(spaceIndex!=std::string::npos)
            {
                names[k]=tempStr.substr(0, spaceIndex);
                scoreStr[k]=tempStr.substr(spaceIndex, strLength);
                cout<<names[k]<<" "<<scoreStr[k]<<endl;//<<" index: " <<k<<endl;
            }
            else
            {
                names[k]=tempStr;
                scoreStr[k]="00";
                cout<<names[k]<<endl;
            }
            k++;
        }
    }
     return(numActions);
}

void convStrtoInt(int numLines, int scores[max_num_lines], string scoreStr[max_num_lines])
{
    int tempNumber,i;
    for(i=0;i<numLines;i++)
    {
        tempNumber=atoi(scoreStr[i].c_str());
        if(tempNumber!=0)
        {
            scores[i]=tempNumber;
        }
    }
}

void buildLinkList(int numLines, int numActions, string names[max_num_lines], string action[max_num_lines/2], int scores[max_num_lines], int index[max_num_lines/2])
{
    int i,k;
    for(k=0;k<numActions;k++)
    {
        if(k==0)
        {
            cout<<"INSERT"<<endl;
            for(i=0;i<=10;i++)
            {
                myInsert(scores[i],names[i]);
            }
        }
         else if(k==1)
        {
            cout<<"VISIT"<<endl;
            visit();
        }
        else if(k==2)
         {
             cout<<"Delete 1:"<<endl;
             for(i=10;i<=12;i++)
                {
                    myDelete(names[i]);
                    cout<<"Deleted "<< names[i]<<endl;
                }
         }
         else if(k==3)
         {
             cout<<"visit 2"<<endl;
             visit();
         }
         else if(k==4)
         {
             cout<<"Search 1"<<endl;
             for(;i<=15;i++)
             {
                 mySearch(names[i]);
             }
         }
         else if(k==5)
         {
             cout<<"Insert 2"<<endl;
                for(i=15;i<=18;i++)
                {
                    myInsert(scores[i],names[i]);
                }
         }
         else if(k==6)
         {
             cout<<"Visit 3"<<endl;
             visit();
         }
         else if(k==7)
         {
             cout<<"Insert 3"<<endl;
             i++;
             myInsert(scores[i],names[i]);
         }
         else if(k==8)
         {
             cout<<"Delete 2"<<endl;
             cout<<"Deleted: "<<names[i]<<endl;
             myDelete(names[i]);
         }
         else if(k==9)
         {
             cout<<"Search 2"<<endl;
             i++;
             mySearch(names[i]);
         }
         else if(k==10)
         {
             cout<<"Visit 4"<<endl;
             visit();
         }
         else if(k==11)
         {
             cout<<"Sort"<<endl;
             mySort();
         }
         else if(k==12)
         {

             visit();
         }
         else if(k==13)
         {
             cout<<"END"<<endl;
         }

        }
}


int main()
{
    int numLines=0, index[max_num_lines/2], scores[max_num_lines], scoresIns[max_num_lines/2], numActions=0;
    string data[max_num_lines], names[max_num_lines], action[max_num_lines/2], scoreStr[max_num_lines], namesIns[max_num_lines/2];
    numLines=getData("a5.txt", data);
    cout<<"Number of Lines: "<<numLines<<endl;
    cout<<"**************** Parsed Data ****************"<<endl;
    numActions=parseData(numLines,data,names,action, scoreStr, index);
    convStrtoInt(numLines, scores, scoreStr);
    cout<<"*****************Linked List***************"<<endl;
    buildLinkList(numLines, numActions,names,action,scores,index);
    return 0;
}
