//
//  main.cpp
//  Facebook
//
//  Created by 장성원 on 05/11/2018.
//  Copyright © 2018 장성원. All rights reserved.
//

#include <iostream>
#include "FaceBook.cpp"

using namespace std;

int main()
{
    List<string> userList;
    string userName1, userName2;
    char cmd;
    
    do {
    cout << endl << "Commends:" << endl;
    cout << "P : Create a user record of the speciﬁed name" << endl;
    cout << "F : Record that the two speciﬁed users are friends" << endl;
    cout << "U : Record that the two speciﬁed users are no longer friends" << endl;
    cout << "L : Print out the friends of the speciﬁed user" << endl;
    cout << "Q : Check whether the two users are friends" << endl;
    cout << "X : terminate the porgram" << endl; cout << endl;
    
    userList.showAllUsers();
    
        cout << endl << "Commend: ";
        cin >> cmd;
        cin.ignore(32767, '\n');; cout << endl;
        
        switch(cmd)
        {
            case 'P': case 'p':
                cout << "New User Name: ";
                getline(cin, userName1);
                userList.insert(userName1);
                break;
                
            case 'F': case 'f':
                cout << "Input two users' name: " << endl;
                cout << "User 1: "; getline(cin, userName1);
                cout << "User 2: "; getline(cin, userName2);
                userList.beFriend(userName1, userName2);
                break;
                
            case 'L': case 'l':
                cout << "Input user name: "; getline(cin, userName1);
                userList.showFriends(userName1);
                break;
                
            case 'U': case 'u':
                cout << "Input two users' name: " << endl;
                cout << "User 1: "; getline(cin, userName1);
                cout << "User 2: "; getline(cin, userName2);
                userList.breachFriend(userName1, userName2);
                break;
                
            case 'Q': case 'q':
                cout << "Input two users' name: " << endl;
                cout << "User 1: "; getline(cin, userName1);
                cout << "User 2: "; getline(cin, userName2);
                if (userList.isFriend(userName1, userName2) == true)
                    cout << "They are friends!" << endl;
                else
                    cout << "They are not friends!" << endl;
                break;
        }
        
    }while (cmd != 'X' && cmd != 'x');
}
