#include <stdio.h>
#include <stdlib.h>
int i = 0;
    struct product{
        char name[30];
        int price;
    }pro[101];
void bill(void);
void addpro(void);
void main()
{
    int j = 0;
    system("CLS");
    system("COLOR 0E");
    printf("\n\n .----------------.  .----------------.  .----------------.  .----------------.");
    printf("\n| .--------------. || .--------------. || .--------------. || .--------------. |");
    printf("\n| |   ______     | || |     _____    | || |   _____      | || |   _____      | |");
    printf("\n| |  |_   _ \\    | || |    |_   _|   | || |  |_   _|     | || |  |_   _|     | |");
    printf("\n| |    | |_) |   | || |      | |     | || |    | |       | || |    | |       | |");
    printf("\n| |    |  __'.   | || |      | |     | || |    | |   _   | || |    | |   _   | |");
    printf("\n| |   _| |__) |  | || |     _| |_    | || |   _| |__/ |  | || |   _| |__/ |  | |");
    printf("\n| |  |_______/   | || |    |_____|   | || |  |________|  | || |  |________|  | |");
    printf("\n| |              | || |              | || |              | || |              | |");
    printf("\n| '--------------' || '--------------' || '--------------' || '--------------' |");
    printf("\n '----------------'  '----------------'  '----------------'  '----------------' ");
    printf("\n\n What do you want to do?\n");
    printf("\n [1] Add new product");
    printf("\n [2] All product(s) list");
    printf("\n [3] Bill");
    printf("\n Your choice: ");
    char menuchk;
    menuchk= getche();
    switch(menuchk){
        case '1':
            addpro();
            break;
        case '2':
            system("CLS");
            if (i == 0){
                printf("\n No product here. Do you want to add new product? [y/n]");
                char addproduct;
                addproduct= getche();
                switch(addproduct){
                    case 'y':
                        addpro();
                        break;
                    case 'n':
                        main();
                        break;
                }
            }
            else{
                printf("\n Name\tPrice\n");
                for(j=0;j<i;j++){
                    printf("\n %s\t%d THB\n",pro[j].name,pro[j].price);
                }
                printf("\n____________________________________________________________");
                printf(" \n\nBack to main menu? [y]");
                char back_to_main;
                back_to_main= getche();
                switch(back_to_main){
                    case 'y':
                        main();
                        break;
                }
            }
            break;
          case '3':
              bill();
              break;
            }

}
void addpro(){
    system("CLS");
    printf("\n\n Product name: ");
    scanf("%s",pro[i].name);
    printf("\n Price: ");
    scanf("%d",&pro[i].price);
    i++;
    printf("\n____________________________________________________________");
    printf("\n\n Product added success. Add more product? [y/n]");
    char yn;
    yn= getche();
    switch(yn){
        case 'y':
            addpro();
            break;
        case 'n':
            main();
            break;

    }
}
void bill(){
    int k = 0,p[101],amt[101],l=0,m=0,n,last_total=0;
    char chk;
    system("CLS");
    for(k=0;k<i;k++){
        printf("\n [%d] Product name: %s   Price: %d THB\n",k,pro[k].name,pro[k].price);
    }
    printf("\n Enter amount of product type:");
    scanf("%d", &n);
    for(l=0;l<n;l++){
        printf("\n Enter product number: ");
        scanf("%d", &p[l]);
        printf("\n Enter amount: ");
        scanf("%d", &amt[m]);
        m++;
    }
    printf("\n\n Press [y] to check your bill");
    chk= getche();
    switch(chk){
        case 'y':
            system("CLS");
            for(k=0;k<l;k++){
                printf("\n\n Name: %s   Price: %d THB  Amount: %d  Total: %d THB\n",pro[p[k]].name,pro[p[k]].price,amt[k],(amt[k]*pro[p[k]].price));
                last_total = last_total+(amt[k]*pro[p[k]].price);
            }
            printf("\n    Last total: %dTHB", last_total);
            break;
    }
    printf("\n____________________________________________________________");
    sleep(3);
    printf("\n\n Create more bill? [y/n]",&pro[i].price);
    char yn;
    yn= getche();
    switch(yn){
        case 'y':
            bill();
            break;
        case 'n':
            main();
            break;



    }
}
