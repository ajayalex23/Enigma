#include <stdio.h>
#include <string.h>

void rotor_right(char arr1[], char a1);
void rotor_middle(char a2, int n1);
void rotor_left(char a3, int n2);
void reflector(char a4, int n3);
void rev_reflector(char a5,int n4);
void left_rotor(char a6,int n5);
void middle_rotor(char a7,int n6); 
void middle_changing(char arr2[], char arr3[]);
void left_changing(char arr4[],char arr5[]);
void right_rotor(char a8,int n7);
void result(int n8);

char plugboard1[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  char plugboard2[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
char reflector1[26] = {'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'};
  char reflector2[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 
char middle1[26] ={'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'};

char left1[26] = {'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'};

char left2[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  char middle2[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  char right1[26] = {'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'};
  
  char right2[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//Main Function
int main(void)
{
    int i;
    for(;;){
  printf("Enter a letter: ");
  char x1;
  scanf("%c",&x1);
 //Input
  
   
   for(i=0; i<26; i++){
      if(x1 == plugboard1[i]){
    char a;   
    char temp1 = right1[0];
    for(int k=0;k<26;k++){
        right1[k] = right1[k+1];
    }
    right1[25] = temp1;
     a= right1[i];
     rotor_right(right2,a);
     //Variables passed to rotor_right function
     if(right2[i]== 'v'){
         middle_changing(middle1,middle2);
     }
     //Variables will be passed to middle_changing function when right rotor shows 'w' 
     if(left2[i]== 'f'){
         left_changing(left1,left2);
     }
     //Variables will be passed to left_changing function when middle rotor shows 'f'
        }
       
   }
        
}
  
  

}

void rotor_right(char arr1[], char a1){
    char temp = arr1[0];//First element of array is stored in temp 
  
  // rotate elements from index 0 until the 2nd last index to the left in right2
  for (int i = 0; i < 26; i++)
    arr1[i] = arr1[i + 1];

  // put the former first element of the array as the new last element in right2
  arr1[25] = temp;
  
    printf("Rotor Position = ");
    printf("%c ", left2[0]);
    printf("%c ",middle2[0]);
    printf("%c ",arr1[0]);
    //Showing rotor position
    printf("\nEncryption steps :");
  //Showing encryption steps
 
  char b1;
  int k1;
  for (int k = 0; k<26; k++)
  {
      if(a1 == arr1[k])
      {
          
          printf("\n");
          k1=k;
          b1 = arr1[k];
          printf("Wheel 1 encryption: %c",b1);
          rotor_middle(b1,k1);
          //Variable passed to rotor_middle function
      }
  }
}

void middle_changing(char arr2[],char arr3[]){
    char temp2 = arr2[0];
    for(int i=0;i<26;i++){
        arr2[i] = arr2[i+1];
    }
    arr2[25] = temp2;
    //Variables in middle1 got changed
    char temp3 = arr3[0];
    for(int j=0;j<26;j++){
        
        arr3[j] = arr3[j+1];
    }
    arr3[25] = temp3;
    //Variables in middle2 got changed
}

void left_changing(char arr4[],char arr5[]){
    char temp4 = arr4[0];
    for(int i=0;i<26;i++){
        arr4[i] = arr4[i+1];
    }
    arr4[25] = temp4;
    //Variables in left1 got changed
    
    char temp5 = arr5[0];
    for(int j=0;j<26;j++){
        arr5[j] = arr5[j+1];
    }
    arr5[25] = temp5;
    //Variables in left2 got changed
}

void rotor_middle(char a2, int n1){
   
 
  int k2;
  char b2;
  
      
      for(int i=0;i<26;i++){
          if(middle2[i]==middle1[n1]){
              printf("\nWheel 2 encryption: %c",middle2[i]);
              
              k2=i;
              b2 = middle2[i];
              rotor_left(b2,k2);
              //Variable passed to rotor_left function
          }
      }
  
}

void rotor_left(char a3,int n2){
    
  
  int k3;
  char b3;
  
  
  for(int i=0;i<26;i++){
          if(left2[i]==left1[n2]){
              printf("\nWheel 3 encryption: %c",left2[i]);
              
              k3=i;
              b3 = left2[i];
              reflector(b3,k3);
              //Variable passed to reflector function
          }
      }
  
}

void reflector(char a4, int n3){
  
  int k4;
  char b4;
  
 
  for(int i=0;i<26;i++){
          if(reflector2[i]==reflector1[n3]){
              printf("\nReflector encryption: %c",reflector2[i]);
              k4 = i;
              b4 = reflector2[i];
              rev_reflector(b4,k4);
          }
      }
  
}

void rev_reflector(char a5,int n4){
   int k5;
  char b5;
  
  
  b5 = reflector1[n4];
  k5 = n4;
  //Variable getting reflected and moving to left_rotor function
              left_rotor(b5,k5);
       
        
}

void left_rotor(char a6,int n5){
    int k6;
  char b6;
  
  
  for(int i=0;i<26;i++){
          if(left1[i]==left2[n5]){
              printf("\nWheel 1 encryption: %c",left1[i]);
            
              k6 = i;
              b6 = left1[i];
              middle_rotor(b6,k6);
              //Variable moving to middle_rotor function
          }
      }
}

void middle_rotor(char a7, int n6){
    int k7;
  char b7;
  
  
  for(int i=0;i<26;i++){
          if(middle1[i]==middle2[n6]){
              printf("\nWheel 2 encryption: %c",middle1[i]);
              
              k7 = i;
              b7 = middle1[i];
              right_rotor(b7,k7);
              //Variable moving to right_rotor function
          }
      }
}

void right_rotor(char a8,int n7){
    int k8;
    char b8;
    
    
  for(int i=0;i<26;i++){
          if(right1[i]==right2[n7]){
              printf("\nWheel 3 encryption: %c",right1[i]);
              
              k8 = i;
              b8 = right1[i];
              result(k8);
              
          }
      }
    
}

void result(int n8){
    printf("\nOutput: %c\n\n",plugboard1[n8]);
    //Output
}