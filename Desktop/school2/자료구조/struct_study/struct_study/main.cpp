//
//  main.cpp
//  struct_study
//
//  Created by 손현기 on 2018. 3. 26..
//  Copyright © 2018년 손현기. All rights reserved.
//

#include <iostream>

class stack_data{
    
public:
    char arraystack[100];
    int top =0;
public:
    void push(char data){
        arraystack[top++] = data;
    }
    char pop(){
        return arraystack[top-1];
    }
    char pop2(){
        int a = top--;
        return arraystack[a-1];
        
    }
    
    int Empty(){
        return -1;
    }
    int Full(){
        return 99;
    }
    void display();
    int getter(){
        return top;
    }
    
    //stack_data calc(char a[]);
    
    
    
};

void stack_data::display(){
    for (int i=0; i<top; i++) {
        printf("%c\n",arraystack[i]);
    }
}

stack_data calc(char a[]){
    stack_data result_data;
    stack_data ram;
    char sign_data1[] = {'(','+','*',')'};
    char sign_data2[] = {'(','-','/',')'};
    char data;
    int token;
    int top =0;
    int count =0;
    while (1) {
        //printf("%d\n",count);
        //ram.display();
        token = -1;
        data = a[count];
        if (data == '$') {
            result_data.push(ram.pop2());
            break;
        }
        else{
            for (int i = 0 ; i<4; i++) {
                if (sign_data1[i] == data) {
                    token = i;
                    break;
                }
                else if (sign_data2[i] == data){
                    token = i;
                    break;
                }
            }
            if (token == -1) {
                result_data.push(data);
            }
            else{
                if (ram.getter()==0) {
                    ram.push(data);
                }
                else{
                    //ram.display();
                    for (int i = 0 ; i<4; i++) {
                        
                        if (sign_data1[i] == ram.pop()) {
                            top = i;
                            break;
                        }
                        else if (sign_data2[i] == ram.pop()){
                
                            top = i;
                            break;
                        }
                    }
                    if (data == '(') {
                        ram.push(data);
                    }
                    else if (data == ')'){
                        while (1) {
                            char pop2 = ram.pop2();
                            if (pop2=='(') {
                                break;
                            }
                            else{
                                result_data.push(pop2);
                                //printf("%c\t",pop2);
                            }
                        }
                    }
                    else if (token > top){
                        ram.push(data);
                    }
                    else if (token <= top){
                        result_data.push(ram.pop2());
                        ram.push(data);
                        
                    }
                }
            }
            
            
        }
        count++;
    }
   result_data.display();
    
    
    
    return result_data;
}

int main(int argc, const char * argv[]) {
    
    char new_data [] = {'7','*','8','-','(','2','+','3',')','$'};
    
    stack_data *a;
    
    calc(new_data);
   
    
    return 0;
}
