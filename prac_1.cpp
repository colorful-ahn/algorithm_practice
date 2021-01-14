#include<stdio.h>
#define MAX_STACK_SIZE 1000
#define ABS(a) (((a)>0)?(a):(-(a)))

void NUM(int x);
void POP();
void INV();
void DUP();
void SWP();
int ADD();
int SUB();
int MUL();
int DIV();
int MOD();
void END();

int stack[MAX_STACK_SIZE];
int top=-1;
 
int IsEmpty(){
    if(top<0)
        return true;
    else
        return false;
    }
int IsFull(){
    if(top>=MAX_STACK_SIZE-1)
        return true;
    else
        return false;
}
 
void push(int value){
    if(IsFull()==true)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top]=value; 
}
 
int pop(){
    if(IsEmpty()==true)
        printf("스택이 비었습니다.");
    else {
    	stack[top] = 0;
    	return stack[top--];
	}
        
}


int main(){
    
    while(1){
    char string[10];
    int error = 1;
    scanf("%s",&string);
    if(string[0] == 'N'){
        int x;
        scanf("%d",&x);
        if(x < 1000000000 && x>0)
        NUM(x);
        else
        error = -1;
    }
    else if(string[0] == 'P'){
        POP();
    }
    else if(string[0] == 'I'){
        INV();
    }
    else if(string[0] == 'D'){
        DUP();
    }
    else if(string[0] == 'S'){
        if(string[1] == 'W'){
            SWP();
        }
        else if(string[1] == 'U'){
            SUB();
        }
    }
    else if(string[0] == 'A'){
        error = ADD();
    }
    else if(string[0] == 'M'){
        if(string[1] == 'U'){
            error = MUL();
        }
        else if(string[1] == 'O'){
            error = MOD();
        }
    }
    else if(string[0] == 'D'){
        error = DIV();
    }
    else if(string[0] == 'E'){
        END();
        printf("\n");
    }
    else if(string[0] == 'Q'){
        break;
    }
    else if(error == -1){
        printf("error");
		break;
    }
    
    
    }
    return 0; 
}

void NUM(int x){
    push(x);
}

void POP(){
    pop();
}
void INV(){
    int num;
    num = pop();
    num *= -1;
    push(num);
}
void DUP(){
    int num = pop();
   push(num);
    push(num);
}
void SWP(){
    int num_first = pop();
    int num_second = pop();
    push(num_second);
    push(num_first);
}
int ADD(){
    int num_first = pop();
    int num_second = pop();
    int result = num_first + num_second;
    if(result < 1000000000){
    	push(result);
    	return 1;
	}
    
    else
    return -1;
    
}
int SUB(){
    int num_first = pop();
    int num_second = pop();
    int result = num_second - num_first;
   if(result < 1000000000){
    	push(result);
    	return 1;
	}
    
    else
    return -1;
}
int MUL(){
    int num_first = pop();
    int num_second = pop();
    int result = num_second * num_first;
    if(result < 1000000000){
    	push(result);
    	return 1;
	}
    
    else
    return -1;
}
int DIV(){
    
    int num_first = pop();
    if(IsEmpty){
        return -1;
    }
    else{
        int num_second = pop();
        int result = ABS(num_second) / ABS(num_first);
        if(result < 1000000000){
    	push(result);
    	return 1;
	}
    
    else
    return -1;
    }
    
}
int MOD(){
    int num_first = pop();
    if(IsEmpty){
        return -1;
    }
    else{
        int num_second = pop();
        int result = ABS(num_second) % ABS(num_first);
        if(result < 1000000000){
    	push(result);
    	return 1;
	}
    
    else
    return -1;
    }
}
void END(){
    int i=0;
    for(i=sizeof(stack)/sizeof(int); i>=0;i--){
    	if(stack[i]!=0){
    		printf("%d\n",stack[i]);
		}
    	
	}
}
