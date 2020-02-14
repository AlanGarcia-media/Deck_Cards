//
//  main.cpp
//  GarciaGarza_Alan_Hw4
//
//  Created by Alan Garcia on 3/20/19.
//  Copyright © 2019 Alan Garcia. All rights reserved.
//

#include <iostream> // libraries
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct Card{ // card struct
    int value;
    char suit;
};
struct bagNode{ // bag node struct
    Card*card;
    bagNode*next;
    char value1;
    char suit1;
};

class Linked_list{ // linked list class
    bagNode*head,*tail; // creating bag and tail pointer
    
public:
    Linked_list(){ // making head and tail NULL
        head=NULL;
        tail=NULL;
    }
    void add(int value,char suit){ //void fucntion that adds individual cards into the list
        bagNode* node = new bagNode(); // opens bag
        node->value1=value; //adds values in node
        node->suit1=suit; //adds char in node
        node->next=NULL; //makes next null to fill
        if(head==NULL){
            head=node;
            tail=node;
            node=NULL;
        }else{
            tail->next=node;
            tail=node;
        }
    }
    void print(){ //prints function to test the assigment and make sure they
        bagNode*node=new bagNode; //opens bag
        node=head; // makes node head
        while(node!=NULL){ // checks node in not null
            printf("\n[%d-%c]\n",node->value1,node->suit1); // prints the value of 1 and char
            node=node->next;// goes to nect node
        }
    }
    void fillWithCards(){ // fills card decks
        char suit[4]={'H','D','S','C'}; // array of chars
        for(int j=0; j<4;j++){
            for(int i=1; i<=13;i++){
                char suit1=suit[j]; // finds index of the the array
                add(i,suit1); //adds the int and char to the add functiion
            }
        }
    }
    void getCurrentSize(){ //finds current size of the list
        int counter = 0;// int =0
        struct bagNode* node = head; // opens bag and node = head
        while (node != NULL){ // while node not equal to null
            counter++; // counter adds if node is there
            node = node->next; // next node
        }
        cout<<"\nSize of Deck: "<<counter;// prints
        if(counter<=34){ // if counter is less than 34
            cout<<"\nWait patiently as we add another Deck in the Bag"<<endl; // print
            fillWithCards();// fills deck with 52 cards
        }
    }
    void isEmpty(){ // checks if list is empty
        struct bagNode* node=head;
        if(head==NULL){ // if head null
            cout<<"Deck is Empty"<<endl;// print
        }
    }
    int grab(int& n){ // grabs and returns function
        struct bagNode*node=head; // opens bag
        if(n==1){ // if number is 1
            head= node->next;// make head next node
            printf("Card Drawn: [%d-%c]",node->value1,node->suit1); //prints the values of the head
            cout<<endl;
            int card_Value=node->value1;// sets the value equal to card_value
            getCurrentSize(); // gets size of list
            Higher(card_Value);// sends the value to higher function
            Lower(card_Value);//sends the value to lower function
            Same(card_Value);//sends the value to samme function
            delete node; // delets node
            return card_Value; // returns the value
        }else{
            node=head;// node = head
            for(int i=1;i<n-1;i++)// for n -1 index
                node=node->next; // node = node next
            struct bagNode* node2=node->next; // opens bag
            node->next=node2->next; // sets the second node to node
            printf("Card Drawn: [%d-%c] ",node2->value1,node2->suit1);// prints the node in orther
            cout<<endl;
            int card_Value=node2->value1; // sets the node value as card value
            getCurrentSize(); // gets current size
            Higher(card_Value); // sends value to higher function
            Lower(card_Value); // sends value to lower function
            Same(card_Value); // sends value to same funtion
            delete node2; // delets the node
            return card_Value; // returns card value
        }
    }
    void Empty(){ // function to delete linked list
        struct bagNode* node=head; // opens bag
        
        while(node!=NULL){ // when not not equal to null
            head=node->next; // head nod next
            delete node;// delete node
            node=node->next;// next node
        }
    }
    void getFrequencyof(){ // gets the average of each card being in deck
        struct bagNode* node =new bagNode; // opens bag
        node=head;// node = head
        double ace=0,two=0,three=0,fourth=0,fifth=0,sixth=0,seventh=0,eight=0,ninth=0,tenth=0,jack=0,queen=0,king=0; // int
        while(node!=NULL){ // while node not null
            switch(node->value1){ // case to find the amount of values in each the list
                case 1:
                    ace++;
                    break;
                    
                case 2:
                    two++;
                    break;
                    
                case 3:
                    three++;
                    break;
                    
                case 4:
                    fourth++;
                    break;
                    
                case 5:
                    fifth++;
                    break;
                    
                case 6:
                    sixth++;
                    break;
                case 7:
                    seventh++;
                    break;
                case 8:
                    eight++;
                    break;
                    
                case 9:
                    ninth++;
                    break;
                    
                case 10:
                    tenth++;
                    break;
                    
                case 11:
                    jack++;
                    break;
                case 12:
                    queen++;
                    break;
                    
                case 13:
                    king++;
                    break;
            }
            node=node->next; // node = node next
        }
        double summation= ace+two+three+fourth+fifth+sixth+seventh+eight+ninth+tenth+jack+queen+king; // addition of all
        double ace1=(ace/summation)*100,two2=(two/summation)*100,three2=(three/summation)*100,fourth2=(fourth/summation)*100,fifth2=(fifth/summation)*100,sixth2=(sixth/summation)*100,seventh2=(seventh/summation)*100,eight2=(eight/summation)*100,ninth2=(ninth/summation)*100,tenth2=(tenth/summation)*100,jack2=(jack/summation)*100,queen2=(queen/summation)*100,king2=(king/summation)*100; //math to find the probability oif each class
        
        cout<<"\nProabability of next card being:\n"<<"A=1    "<<fixed << setprecision(2)<<ace1<<"%"<<endl<<"2      "<<fixed << setprecision(2)<<two2<<"%"<<endl<<"3      "<<fixed << setprecision(2)<<three2<<"%"<<endl<<"4      "<<fixed << setprecision(2)<<fourth2<<"%"<<endl<<"5      "<<fixed << setprecision(2)<<fifth2<<"%"<<endl<<
        "6      "<<fixed << setprecision(2)<<sixth2<<"%"<<endl<<"7      "<<fixed << setprecision(2)<<seventh2<<"%"<<endl<<"8      "<<fixed << setprecision(2)<<eight2<<"%"<<endl<<"9      "<<fixed << setprecision(2)<<ninth2<<"%"<<endl<<"10     "<<fixed << setprecision(2)<<tenth2<<"%"<<endl<<"J=11   "<<fixed << setprecision(2)<<jack2<<"%"<<endl<<
        "Q=12   "<<fixed << setprecision(2)<<queen2<<"%"<<endl<<"K=13   "<<fixed << setprecision(2)<<king2<<"%"<<endl;// prints the probabilities
    }
    void Higher(int& n){ // funtion to find probability of higher
        struct bagNode* node =new bagNode; // open bag
        node=head; // node = head
        int counter = 0; // counter =0
        int z=n;
        double ace=0,two=0,three=0,fourth=0,fifth=0,sixth=0,seventh=0,eight=0,ninth=0,tenth=0,jack=0,queen=0,king=0;
        while(node!=NULL){ // node not equal to null
            switch(node->value1){ // switch statment to take the value from the card and check to see if how many cards are higher
                case 1:
                    if(z<1){
                        ace++;
                    }
                    break;
                    
                case 2:
                    if(z<2){
                        two++;
                    }
                    break;
                    
                case 3:
                    if(z<3){
                        three++;
                    }
                    break;
                    
                case 4:
                    if(z<4){
                        fourth++;
                    }
                    break;
                    
                case 5:
                    if(z<5){
                        fifth++;
                    }
                    break;
                    
                case 6:
                    if(z<6){
                        sixth++;
                    }
                    break;
                case 7:
                    if(z<7){
                        seventh++;
                    }
                    break;
                case 8:
                    if(z<8){
                        eight++;
                    }
                    break;
                    
                case 9:
                    if(z<9){
                        ninth++;
                    }
                    break;
                    
                case 10:
                    if(z<10){
                        tenth++;
                    }
                    break;
                    
                case 11:
                    if(z<11){
                        jack++;
                    }
                    break;
                case 12:
                    if(z<12){
                        queen++;
                    }
                    break;
                    
                case 13:
                    if(z<13){
                        king++;
                    }
                    break;
            }
            node=node->next; // node next
        }
        int counter4 = 0;
        struct bagNode* node2 = head; // opens bag
        while (node2 != NULL){ // checks current size of list
            counter4++;
            node2 = node2->next; // node = node next
        }
        double probability=ace+two+three+fourth+fifth+sixth+seventh+eight+ninth+tenth+jack+queen+king; // adds the amount of numbers
        double higher=(probability/counter4)*100;// finds probability of higher values positibilty
        cout<<"\nProabability of next card being Higher: "<<fixed << setprecision(2)<<higher<<"%"; // prints
    }
    void Lower(int& n){ // probability of lower function
        struct bagNode* node =new bagNode; //opens bag
        node=head; // node = head
        int z=n;
        double ace=0,two=0,three=0,fourth=0,fifth=0,sixth=0,seventh=0,eight=0,ninth=0,tenth=0,jack=0,queen=0,king=0;
        while(node!=NULL){ //node not NULL
            switch(node->value1){ // goes through each value  on case to find numbers lower than value
                case 1:
                    if(z>1){
                        ace++;
                    }
                    break;
                    
                case 2:
                    if(z>2){
                        two++;
                    }
                    break;
                    
                case 3:
                    if(z>3){
                        three++;
                    }
                    break;
                    
                case 4:
                    if(z>4){
                        fourth++;
                    }
                    break;
                    
                case 5:
                    if(z>5){
                        fifth++;
                    }
                    break;
                    
                case 6:
                    if(z>6){
                        sixth++;
                    }
                    break;
                case 7:
                    if(z>7){
                        seventh++;
                    }
                    break;
                case 8:
                    if(z>8){
                        eight++;
                    }
                    break;
                    
                case 9:
                    if(z>9){
                        ninth++;
                    }
                    break;
                    
                case 10:
                    if(z>10){
                        tenth++;
                    }
                    break;
                    
                case 11:
                    if(z>11){
                        jack++;
                    }
                    break;
                case 12:
                    if(z>12){
                        queen++;
                    }
                    break;
                    
                case 13:
                    if(z>13){
                        king++;
                    }
                    break;
            }
            node=node->next; // goes to next node
        }
        int counter4 = 0;
        struct bagNode* node2 = head; // node to open bag to find current size
        while (node2 != NULL){
            counter4++;
            node2 = node2->next;
        }
        double probability1=ace+two+three+fourth+fifth+sixth+seventh+eight+ninth+tenth+jack+queen+king; // adds the numbers that are lower
        double higher1=(probability1/counter4)*100; // finds the probability
        cout<<"\nProabability of next card being Lower: "<<fixed << setprecision(2)<<higher1<<"%"; // prints
    }
    void Same(int& n){ //voids to find if values are same
        struct bagNode* node =new bagNode; // opens bag
        node=head; // node = head
        int z=n;
        //int y=grab(z);
        double ace=0,two=0,three=0,fourth=0,fifth=0,sixth=0,seventh=0,eight=0,ninth=0,tenth=0,jack=0,queen=0,king=0;
        while(node!=NULL){ // node not null
            switch(node->value1){ //switch statment to find the numbers in the same values
                case 1:
                    if(z==1){
                        ace++;
                    }
                    break;
                    
                case 2:
                    if(z==2){
                        two++;
                    }
                    break;
                    
                case 3:
                    if(z==3){
                        three++;
                    }
                    break;
                    
                case 4:
                    if(z==4){
                        fourth++;
                    }
                    break;
                    
                case 5:
                    if(z==5){
                        fifth++;
                    }
                    break;
                    
                case 6:
                    if(z==6){
                        sixth++;
                    }
                    break;
                case 7:
                    if(z==7){
                        seventh++;
                    }
                    break;
                case 8:
                    if(z==8){
                        eight++;
                    }
                    break;
                    
                case 9:
                    if(z==9){
                        ninth++;
                    }
                    break;
                    
                case 10:
                    if(z==10){
                        tenth++;
                    }
                    break;
                    
                case 11:
                    if(z==11){
                        jack++;
                    }
                    break;
                case 12:
                    if(z==12){
                        queen++;
                    }
                    break;
                    
                case 13:
                    if(z==13){
                        king++;
                    }
                    break;
            }
            node=node->next;
        }
        int counter4 = 0;
        struct bagNode* node2 = head; // while loop to find current sixze of list
        while (node2 != NULL){
            counter4++;
            node2 = node2->next;
        }
        double probability2=ace+two+three+fourth+fifth+sixth+seventh+eight+ninth+tenth+jack+queen+king; // adds the amout of same values
        double higher2=(probability2/counter4)*100;//finds probability of same
        cout<<"\nProabability of next card being Same: "<<fixed << setprecision(2)<<higher2<<"%"; // prints
    }
    int currentSize(int x){ // side of list function that retutns current
        int counter2 = 0;
        struct bagNode* node = head;
        while (node != NULL){
            counter2++;
            node = node->next;
        }
        return counter2;
    }
};


int main(int argc, const char * argv[]) {
    srand(time(NULL)); // time null for rand
    struct bagNode*head=NULL;// makes list empty
    Linked_list Deck; // calls list deck
    int n,num,z,x; // integers
    int player_Points=0; // int player points
    int current_Card=0; // int current card
    int previous_Card=0; // int previous cards
    Deck.fillWithCards(); // fills deck woth cards funtion called
    cout<<"Cards Drawn: "; // prints
    int y=Deck.currentSize(x); //find the current size to find random time
    y=y-1; //subtracts rand
    n=rand() % y; // finds rand
    n++; // adds 1 to n
    previous_Card=current_Card; // makes previous class equal to current
    current_Card=Deck.grab(n); // current card is the value of the bag
    cout<<endl;
    Deck.getFrequencyof(); // prints frequency function
    cout<<endl;
    cout<<"Points: "<<player_Points<<endl; // prints points
    int user; // user input
    do{ // do while
        cout<<"Choose Option: \n"<<"1   -   Next Card will be higher\n"<<"2   -   Next card will be lower\n"<<"3   -   Guess exact value\n"<<"4   -   Exit"<<endl;// prints menu
        cout<<"Select your option 1-2-3-4: ";
        cin>>user; // user input
        cout<<endl;
        y=Deck.currentSize(x); // finds the deck size
        y=y-1; //subreacts 1 from deck size
        n=rand() % y;// finds rand from deck size
        n++; // adds 1 to n
        previous_Card=current_Card; // makes previous  equal to current
        current_Card=Deck.grab(n); // makes value of card current card
        cout<<endl;
        switch(user){ // case for users input
            case 1:
                if(current_Card>previous_Card){ // if to check of the last card is less
                    player_Points=player_Points+2; // if its lower win 2 points
                    cout<<"\nYou wont two points!"<<endl; // print
                    cout<<"Current Points: "<<player_Points<<endl;//print
                }else{
                    cout<<"\nGAME OVER"<<endl;
                    cout<<"Points Earned: "<<player_Points<<endl;//if wrong quit and print
                    goto endLoop;// skip to end
                }
                cout<<endl;
                break;
            case 2:
                if(current_Card<previous_Card){ // if to checkl if nect card is lower
                    player_Points=player_Points+2; // if so win 2 points
                    cout<<"\nYou wont two points!"<<endl; // print
                    cout<<"Current Points: "<<player_Points<<endl;
                    cout<<"Points Earned: "<<player_Points<<endl;// print poinst
                }else{
                    cout<<"\nGAME OVER"<<endl; // else you loose
                    goto endLoop; // end program
                }
                cout<<endl;
                break;
            case 3:
                if(current_Card==previous_Card){ //if card is same
                    player_Points=player_Points+5; // win five points
                    cout<<"\nYou wont five points!"<<endl; // print
                    cout<<"Current Points: "<<player_Points<<endl; // prints points
                }else{
                    cout<<"\nGAME OVER"<<endl;
                    cout<<"Points Earned: "<<player_Points<<endl;// else you loose
                    goto endLoop; // endloop to quit
                }
                cout<<endl;
                break;
            case 4: // case 4 to exit in case
                break;
        }
        
        Deck.getFrequencyof(); // prints freuqncy function
        cout<<endl;
    }while(user!=4); // end of wile loop
endLoop:// end loop if user looses
    Deck.isEmpty(); // checks to see if deck is emopty
    Deck.Empty(); // deletes linked list
}
