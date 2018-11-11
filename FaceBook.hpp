//
//  FaceBook.hpp
//  Facebook
//
//  Created by 장성원 on 05/11/2018.
//  Copyright © 2018 장성원. All rights reserved.
//

#ifndef FaceBook_hpp
#define FaceBook_hpp

#include<string>

template < class LE >
class List;
template < class LE >
class ListNode;


template < class LE >
class ListNode
{
private:
    
    ListNode (const LE &user, ListNode *nextPtr);
    
    LE          userName;
    ListNode *next;
    std::string friends[100];
    
    friend class List<LE>;
};

//--------------------------------------------------------------------

template < class LE >
class List
{
public:
    
    List(int ignored = 0);
    ~List(); 
    
    void insert(const LE &newElement);        // Insert new User
    bool checkUserName(const LE &newUser);    // check if UserName already exist
    void remove();                             // remove the user on cursor
    void clear();                           // Clear list
        
    bool gotoBeginning();                    // Go to beginning
    bool gotoEnd();                          // Go to end
    bool gotoNext();                         // Go to next user
    bool gotoPrior();                        // Go to prior user
    int userListSize() const;
    int userListSizeSub(ListNode<LE> *p) const;
    
    void showAllUsers() const;
    
    void beFriend(const LE &user1, const LE &user2);         // make two users be friend
    bool checkAlreadyFriend(const LE & userName);              //check firends list if the userName already present
    void moveCursorByName(const LE &userName);                // move cursor by user's name
    void breachFriend(const LE &user1, const LE &user2);    // breach
    void breachFriendSub(const LE &userName);
    bool isFriend(const LE &user1, const LE &user2);        //check if two users are friend
    
    int cursorPosition() const;
    void showFriends(const LE &userName);                     // show friends by user's name
    
    
private:
    ListNode<LE>    *head,     // Pointer to the beginning of the list
    *cursor;   // Cursor pointer
};

#endif /* FaceBook_hpp */
