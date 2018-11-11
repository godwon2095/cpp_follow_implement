//
//  FaceBook.cpp
//  Facebook
//
//  Created by 장성원 on 05/11/2018.
//  Copyright © 2018 장성원. All rights reserved.
//

#include <iostream>
#include "FaceBook.hpp"
#include <string>

using namespace std;


template<class LE>
ListNode<LE>::ListNode(const LE &userName, ListNode *next)
: userName(userName),
next(next)
{}


template<class LE>
List<LE>::List(int ignored)
{
    head = 0, cursor = 0;
}

template<class LE>
List<LE>::~List()
{
    this->clear();
}


template<class LE>
void List<LE>::insert(const LE &newUser)
{
    if (head == NULL)
    {
        ListNode<LE> *newNode = new ListNode<LE>(newUser, NULL);
        head = newNode;
        cursor = newNode;
    }
    else if (this->checkUserName(newUser) == true)
    {
        cout << "Sorry! that user name already exist!" << endl;
    }
    else
    {
        ListNode<LE> *newNode = new ListNode<LE>(newUser, cursor->next);
        cursor->next = newNode;
        cursor = cursor->next;
    }
}

template<class LE>
bool List<LE>::checkUserName(const LE &newUser)
{
    bool result(false);
    for (ListNode<LE> *temp = head; temp != 0; temp = temp->next)
    {
        if (temp->userName == newUser)
            result = true;
    }
    
    return result;
}


template<class LE>
void List<LE>::remove()
{
    if (head == NULL)
        cout << "User List is empty!" << endl;
    else {
        if (cursor != head)
        {
            ListNode<LE> *saveCursor = cursor->next;
            ListNode<LE> *deleteCursor = cursor;
            
            this->gotoPrior();
            cursor->next = saveCursor;
            
            delete deleteCursor;
        }
        else
        {
            ListNode<LE> *saveCursor = cursor->next;
            ListNode<LE> *deleteCursor = cursor;
            
            this->gotoNext();
            head = saveCursor;
            
            delete deleteCursor;
        }
    }
}


template<class LE>
bool List<LE>::gotoBeginning()
{
    if (head == NULL)
        cout << "User list is empty!" << endl;
    else
    {
        cursor = head;
    }
    
    return false;
}

template<class LE>
bool List<LE>::gotoEnd()
{
    if (head == NULL)
        cout << "User List is empty!" << endl;
    else
    {
        this->gotoBeginning();
        do
        {
            this->gotoNext();
        }while(cursor->next != NULL);
        return true;
    }
}

template<class LE>
bool List<LE>::gotoNext()
{
    if (head == NULL)
        cout << "User List is empty!" << endl;
    else if (cursor -> next == NULL) return false;
    else
    {
        cursor = cursor->next;
        return true;
    }
}

template<class LE>
bool List<LE>::gotoPrior()
{
    if (head == NULL)
    {
        cout << "User list is empty!" << endl;
        return false;
    }
    else
    {
        if (cursor == head) return false;
        else
        {
            int count(1), retrieve(0);
            
            while(this->gotoNext())
                count++;
            
            retrieve = this->userListSize() - count;
            this->gotoBeginning();
            while(retrieve > 1)
            {
                this->gotoNext();
                retrieve--;
            }
        }
    }
    return true;
}


template<class LE>
void List<LE>::clear()
{
    if (head == NULL)
    {
        cout << "User list is empty !" << endl;
    }
    else
    {
        int count = userListSize();
        this->gotoEnd();
        do
        {
            this->remove();
            count--;
        }while(count != 0);
    }
}


template<class LE>
int List<LE>::userListSize() const
{
    return userListSizeSub(head);
}

template<class LE>
int List<LE>::userListSizeSub(ListNode<LE> *p) const
{
    int result(0);
    
    if (p == 0)
        return result;
    else
    {
        result = (userListSizeSub(p->next) + 1);
        return result;
    }
}


template<class LE>
void List<LE>::showAllUsers() const
{
    if (head != NULL)
    {
        cout << "User List :" << endl;
        for(ListNode<LE> *temp = head; temp !=0; temp=temp->next)
            cout << temp->userName << endl;
    }
}



template<class LE>
void List<LE>::beFriend(const LE &user1, const LE &user2)
{
    if (checkUserName(user1) == false || checkUserName(user2) == false)
        cout << "There's no that user name !" << endl;
    else {
//            moveCursorByName(user1);
//            cout << cursorPosition() << endl;
//            moveCursorByName(user2);
//            cout << cursorPosition() << endl;
        moveCursorByName(user1);

        int user1_friends_count(0), user2_friends_count(0);
        for (int i = 0; i<100; i++)
        {
            if (!cursor->friends[i].empty())
                user1_friends_count++;
        }

        if (checkAlreadyFriend(user2) != true)
        {
            cursor->friends[user1_friends_count] = user2;
            cout << user1 << " and " << user2 << " are friends from now!!" << endl;
        }
        else
            cout << user2 << "is already your friend!" << endl;

        moveCursorByName(user2);

        for (int i = 0; i<100; i++)
        {
            if(!cursor->friends[i].empty())
                user2_friends_count++;
        }

        if (checkAlreadyFriend(user1) != true)
            cursor->friends[user1_friends_count] = user1;
        else
            cout << user2 << " is already your friend!" << endl;
        
    }
}

template<class LE>
bool List<LE>::checkAlreadyFriend(const LE & userName)
{
    bool result(false);
    
    for (int i = 0; i<100; i++)
    {
        if (cursor->friends[i] == userName)
            result = true;
    }
    
    return result;
}

template<class LE>
void List<LE>::moveCursorByName(const LE &userName)
{
    if (this->checkUserName(userName) == false)
        cout << "There's no user name " << userName << endl;
    else
    {
        ListNode<LE> *saveCursor(cursor);
        for (ListNode<LE> *temp = head; temp != 0; temp = temp->next)
        {
            if (temp->userName == userName)
            {
                saveCursor = temp;
            }
        }
        cursor = saveCursor;
    }
}



template<class LE>
void List<LE>::showFriends(const LE &userName)
{
    moveCursorByName(userName);
    cout << "cursor position: " << cursorPosition() << endl;
    cout << userName << "'s friends are: " << endl;
    
    for (int i = 0; i<100; i++)
    {
        if (!cursor->friends[i].empty())
            cout << cursor->friends[i] << " ";
    }
    cout << endl;
}


template<class LE>
void List<LE>::breachFriend(const LE &user1, const LE &user2)
{
    if (checkUserName(user1) == false || checkUserName(user2) == false)
        cout << "There's no that user name !" << endl;
    else
    {
        moveCursorByName(user1);
        breachFriendSub(user2);
        
        moveCursorByName(user2);
        breachFriendSub(user1);
    }
}

template<class LE>
void List<LE>::breachFriendSub(const LE &userName)
{
    for(int i = 0; i<100; i++)
    {
        if (cursor->friends[i] == userName)
        {
            
            if (!cursor->friends[i+1].empty())
            {
                for (int j = i; j < 100; j++)
                {
                    cursor->friends[j] = cursor->friends[j+1];
                }
            }
            else
            {
                cursor->friends[i].clear();
            }
        }
    }
}


template<class LE>
bool List<LE>::isFriend(const LE &user1, const LE &user2)
{
    bool result(false);
    
    moveCursorByName(user1);
    for (int i = 0; i<100; i++)
    {
        if (cursor->friends[i] == user2)
            result = true;
    }
    
    return result;
}


template<class LE>
int List<LE>::cursorPosition() const
{
    int count(0);
    
    if (head != NULL)
    {
        for (ListNode<LE> *temp = cursor->next; temp != 0; temp = temp->next)
        {
            count++;
        }
    }
    
    return (userListSize() - count - 1);
}
