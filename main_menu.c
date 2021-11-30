#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int n = 0;

void plot(char * fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","visualise.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","visualise.py",fname,(char*)NULL);
        };
    }
    exit(0);
}

void main_menu(int n, int matrix[n][n]){
    printf("\n\n \t\t\t\t\t\t\t\t\t\t MAIN MENU \n\n");
    printf("Select any one of the following options:-\n\n");
    printf("1) Does every website has a link to itself ?\n\n");
    printf("2) Is it possible to return back to previous website from current website in one step ? \n\n");
    printf("3) Does every website has links to all other websites which are reachable from it ? \n\n");
    printf("4) Does there exist any website which has link to itself ? \n\n");
    printf("5) Is it impossible to return to the previous website from current website in one step(excluding the case where previous and current website are same) ? \n\n");
    printf("6) Is it possible to divide network in multiple pieces such that every website is reachable from every other website in a piece is reachable from every other website in a piece? \n\n");
    printf("7) Is it possible to divide the network into multiple pieces such that every website in a piece is reachable from every other website in that piece ? \n\n");
    printf("8) Is the relation example of a poset ? \n\n");
    printf("9) Exit \n\n");
    printf("Enter the query number in accordance with the main menu\n\n");
    int input;
    scanf("%d",&input);
    int x;
    // int matrix[n][n] = {{1,0,0,1,0},{0,1,0,0,0},{0,0,1,0,0},{0,1,0,1,0},{0,0,0,0,1}}
;
    if(input == 1){    
        x = reflexive(n,matrix);
        if(x == 0){
            printf("%s\n","NO, the given relation is not reflexive!\n\n");
            printf("write 'yes' if you want to convert the given matrix into Reflexive!\n\n");
            menu2(n,matrix,input);
        }
        else{
            printf("%s\n","YES, the given relation is reflexive!\n\n");
        }
    }

    else if(input == 2){
        x = symmetric(n,matrix);
        if(x == 0){
            printf("%s\n","NO, it is not possible to always return back to the previous website from the current website in one step!\n\n");
            printf("write 'yes' if you want to convert the given matrix into Symmetric!\n\n");
            menu2(n,matrix,input);
        }
        else{
            printf("%s\n","YES, it is not possible to always return back to the previous website from the current website in one step!\n\n");
        }
    }

    else if(input == 3){
        x = transitive(n,matrix);
        if(x == 0){
            printf("%s\n","NO, every website do not have all the links to the websites!\n\n");
            printf("write 'yes' if you want to convert the given matrix into Transitive!\n\n");
            menu2(n,matrix,3);
        }
        else{
            printf("%s\n","YES, every website has all the links to the websites!\n\n");
        }
    }
   
    else if(input == 4){
        for(int j=0;j<n;j++){
            if(matrix[j][j] == 1){
                x = 1;
                break;
            }
            else{
                x = 0;
                continue;
            }
        } 
    }

    else if(input == 5){
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1){
                    if(matrix[i][j] == matrix[j][i]){
                        x = 0;
                        printf("NO");
                        exit(0);
                    }
                    else{
                        x = 1;
                        continue;
                    }
                }
            }
        }
    }
    
    else if(input == 6){
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                    continue;
                }
                if(matrix[i][j] == 1){
                    if(matrix[i][j] == matrix[j][i]){
                        x = 0;
                        break;
                    }
                    else{
                        x = 1;
                        continue;
                    }
                }
            }
        }
    }

    else if(input == 7){
        int arr[n][n];
        for(int i=0;i<n;i++){
            int y = 1;
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1){
                    arr[i][j] = j+1;  
                }
                if(matrix[i][j] == 0){
                    arr[i][j] = 0;  
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d",arr[i][j]);
                // if(arr[i][j] != 0){
                //     main_menu_7(arr,i,j);
                // } 
            }
        printf("\n");
        }
    }
    else if(input == 8){
        int a = 0;
        int x;
        a = reflexive(n,matrix);
        printf("%d\n",a);
        a = a + anti_symmetric(n,matrix);
        printf("%d\n",a);
        a = a + transitive(n,matrix);
        printf("%d\n",a);
        if(a!=3){
            printf("NO\n");
            exit(0);
        }
        else{
            printf("YES\n");
            printf("Taking you to menu 4\n");
            menu4(n,matrix);
        }
    }

    else if(input == 9){
        exit(0);
    }


    if(x == 0){
        printf("%s\n","NO");
    }

    else{
        printf("%s\n","YES");
    }
}

void menu2(int n,int matrix[n][n],int input){
    char inp[3];
    scanf("%s",&inp);
    if(strcmp("yes",inp) == 0){
        printf("\t\t\t\t\t\tMenu 2\n\n\n");
        if(input == 1){
            make_reflexive(n,matrix);
        }

        if(input == 2){
            make_symmetric(n,matrix);
        }

        if(input == 3){
            make_transitive(n,matrix);
        }

        if(input == 7){

        }
        
    }
    else{
        scanf("%d",&input);
        main_menu(n,matrix);
    }
}


void menu4(int n, int matrix[n][n]){
    int z;
    char name[30];
    int input;
    scanf("%d",&input);

    if(input == 1){
        make_hasse(n,matrix);
    }

    if(input == 2){
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[j][i] == 1){
                    z = i;
        
                    continue;
                }
                else{
                    z = 0;
                    break;
                }
            }
            if(z){
                printf("Serial number of website whose link is in all websites is : %d\n",z+1);
            }
            else{
                printf("No such website exists!");
            }
        }
    }

    if(input == 3){
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    z = i;
                    continue;
                }
                else{
                    z = 0;
                    break;
                }
            }
            if(z){
                printf("Serial number of website who has link of all websites is :%d\n",z+1);
            }
            else{
                printf("No such website exists!");
            }
        }  
    }

    if(input == 4){
        z = 0;
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1 && i!=j){
                    z = 0;
                    continue;
                }
                else if(matrix[i][j] == 1 && i==j){
                    z = i;
                }
            }
            if(z){
                printf("Website which has link to no other website but itself is : %d\n",i+1);
            }
        }
    }

    if(input == 5){
        z = 0;
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1 && i!=j){
                    z = 0;
                    continue;
                }
                else if(matrix[i][j] == 1 && i==j){
                    z = i;
                }
            }
            if(z){
                printf("Website which has link to no other website but itself is : %d\n",i+1);
            }
        }
    }

    if(input == 6){

    }
    if(input == 7){

    }
    if(input == 8){

    }
    if(input == 9){
        main_menu(n,matrix);
    }

}

int reflexive(int n,int matrix[n][n]){
    int x;
    int k = n;
    for(int j=0;j<n;j++){
        if(matrix[j][j] == 1){
            x = 1;
            continue;
        }
        else{
            x = 0;
            break;
        }
    }
    return x;
}

int anti_symmetric(int n,int matrix[n][n]){
    int x;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j == i){
                continue;
            }
            if(matrix[i][j] == 1){
                if(matrix[i][j] == matrix[j][i]){
                    x = 0;
                    return x;
                }
                else{
                    x = 1;
                    continue;
                }
            }
        }
    }
    return x;
}

int transitive(int n,int matrix[n][n]){
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(matrix[i][j] && matrix[j][k]){
                    if(matrix[i][k]){
                        x = 1;
                        continue;
                    }
                    else{
                        x = 0;
                        return 0;
                    }
                }
                else{
                    continue;
                }
            }
        }
    }
    return 1;
}

int symmetric(int n,int matrix[n][n]){
    int x;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 1){
                if(matrix[i][j] == matrix[j][i]){
                    x = 1;

                    continue;
                }
                else{
                    x = 0;
                    return x;
                }
            }
        }
    }
    return x;
}

void make_reflexive(int n,int matrix[n][n]){
    int k = n;
    for(int i = 0;i<k;i++){
        for(int j=0;j<k;j++){
            if(i==j){
                matrix[i][j] = 1;
            }
        }
    }
    print(n,matrix);
    write_to_file(n,matrix);
    exit(0);
}

void make_symmetric(int n,int matrix[n][n]){
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 1){
                if(matrix[i][j] != matrix[j][i]){
                    matrix[j][i] = 1;
                }
            }
        }
    }
    print(n,matrix);
    write_to_file(n,matrix);
    exit(0);
}

void make_transitive(int n,int matrix[n][n]){
    for(int k=0;k<n;k++){
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(matrix[i][k] && matrix[k][j]){
                    if(!matrix[i][j]){
                        matrix[i][j] = 1;
                    }
                }
            }
        }
    }
    print(n,matrix);
    write_to_file(n,matrix);
    exit(0);
}

void make_hasse(int n,int matrix[n][n]){
    int k = n;
    for(int i = 0;i<k;i++){
        for(int j=0;j<k;j++){
            if(i==j){
                matrix[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(matrix[i][j] && matrix[j][k]){
                    if(matrix[i][k]){
                        matrix[i][k] = 0;
                        continue;
                    }
                }
            }
        }
    }
    print(n,matrix);
}

void print(int n,int matrix[n][n]){
    int k =n;
    printf("Printing the matrix of %d x %d :- \n\n",k,k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void write_to_file(int n,int matrix[n][n]){
    int d =0;
    FILE *new_file_pointer = fopen("new.csv", "w");
    char *row;
    char array[1024];
    FILE *original_file_pointer = fopen("SampleInput.csv", "r");
    while (row = fgets(array, 1024, original_file_pointer)){
        d++;
        if(d==1){
            fputs(row, new_file_pointer);
        }
        else{
            char *field = strtok(array, ",");
            for (int j = 0; j <= n; j++){
                if (j != 0){
                    fputc(',',new_file_pointer);
                    fprintf(new_file_pointer,"%d",matrix[d-2][j-1]);
                }
                else{
                    fprintf(new_file_pointer,"%s",field);
                    // fputc(',',new_file_pointer);
                }
                field = strtok(NULL,",");
            }
            fprintf(new_file_pointer,"%s","\n");
        }
    }
    fclose(original_file_pointer);
    fclose(new_file_pointer);
    plot("new.csv");
}

int main(){
     char filename[100] ; 
//  printf("Enter the name of the file with a .csv extension\n\n"); 
//  scanf("%s",filename) ;
    FILE *fp = fopen("SampleInput.csv", "r"); // file pointer
    if (fp == NULL){
        printf("\n File opening failed");
    exit(0);
    }
    char buf[1024]; // stores the first 1024 lines into buf
    int row = 0;
    int col = 0;
    int i = 0, j = 0;
    //counting size of matrix
    while (fgets(buf, 1024, fp)){
        j = 0;
        row++;
        if (row == 1){
            char *string_splitter = strtok(buf, ",");
            while (string_splitter){
                string_splitter = strtok(NULL, ",");
                col++;
            }
            break;
        }
    }

    int matrix[col][col];
    char websiteNames[col][50] ;
    int temp[1][col];
    while (fgets(buf, 1024, fp)){
        j = 0;
        row++;
        char *string_splitter = strtok(buf, ",");
        if (row == 1){ // we do not want to take the labels
            // for(int i= 0;i<col;i++){
            //     websiteNames[i][50] = *string_splitter ;
            // }

        }
        for (int j = 0; j <= col; j++){
            if (j != 0){
            matrix[row - 2][j - 1] = *string_splitter - '0';
            }
        string_splitter = strtok(NULL, ",");
        }
    }
    int n = col;
    // for(int i = 0 ; i<n;i++){
    //     printf("%d",*websiteNames[i]);
    // }
    int test_matrix[4][4] = {{1,1,1,1},{0,1,1,1},{0,0,1,1},{0,0,0,1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    main_menu(4,test_matrix);

}