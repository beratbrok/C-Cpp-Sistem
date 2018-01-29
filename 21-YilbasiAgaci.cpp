/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: osman
 *
 * Created on 30 Aralık 2017 Cumartesi, 15:36
 */
#include<iostream> 
#include <cstdlib>
#include <unistd.h> 
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  
    // yilbasi agaci yapalim
    int sayac = 0;
    while(true){
        
            for(int j=10;j>=0;j--)
                    cout<<" ";
            cout<<" :):):):):) MUTLU YİLLAR (:(:(:(:(:(:\n";
        
        if(sayac++ %2 == 0){
            
            for(int j=10;j>=0;j--)
                    cout<<" ";
            cout<<"|\n";
            for(int i = 0; i<10;i++){
                for(int j=10;j>i;j--)
                    cout<<" ";
                cout<<"~";
                for(int k=0;k<=i*2;k++)
                    cout<<"*";
                cout<<"~";
                cout<<endl;

            }
            for(int i=0;i<=2;i++){
                for(int j=0;j<=8;j++)
                    cout<<" ";
                for(int j=0;j<3;j++)
                cout<<"||";
                cout<<endl;
            }
        }
        
        else{
            
            
                for(int j=40;j>=0;j--)
                        cout<<" ";
                cout<<"|\n";
                for(int i = 0; i<10;i++){
                    for(int j=40;j>i;j--)
                        cout<<" ";
                    cout<<"~";
                    for(int k=0;k<=i*2;k++)
                        cout<<"*";
                    cout<<"~";
                    cout<<endl;

                }
                for(int i=0;i<=2;i++){
                    for(int j=0;j<=38;j++)
                        cout<<" ";
                    for(int j=0;j<3;j++)
                    cout<<"||";
                    cout<<endl;
                }

                 
        }
        sleep(1);
        system("clear");
    }
    
    return 0;
}

