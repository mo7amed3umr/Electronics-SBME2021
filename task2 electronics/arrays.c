
void ascending_order(number[], n){
    int i.j,a;
            for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (number[i] > number[j]) 
                {
 
                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;
 
                }
 
            }
 
        }
 
        printf("The numbers arranged in ascending order are given below \n");
        for (i = 0; i < n; ++i)
            printf("%d\n", number[i]);
 
    }
}

void descending_order(number[], n){
     int i, j, a; 
        for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j) 
            {
                if (number[i] < number[j]) 
                {
                    a = number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }
 
        printf("The numbers arranged in descending order are given below\n");
 
        for (i = 0; i < n; ++i) 
        {
            printf("%d\n", number[i]);
        }
}

void main(){

    int arr = [0,7,3,2,5,9,4];
    int n = sizeof(arr)
    ascending_order(arr , n)

}