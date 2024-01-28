#include <stdio.h>
#include <stdlib.h>
int isleap(int year){
    int leapyears[71] = {1210,1214,1218,1222,1226,1230,1234,
                         1238,1243,1247,1251,1255,1259,1263,
                         1267,1271,1276,1280,1284,1288,1292,
                         1296,1300,1304,1309,1313,1317,1321,
                         1325,1329,1333,1337,1342,1346,1350,
                         1354,1358,1362,1366,1370,1375,1379,
                         1383,1387,1391,1395,1399,1403,1408,
                         1412,1416,1420,1424,1428,1432,1436,
                         1441,1445,1449,1453,1457,1461,1465,
                         1469,1474,1478,1482,1486,1490,1494,
                         1498};
    
    for (int i = 0 ; i < 71 ; i++){
        if (year == leapyears[i]){
            return 1;
        }
    }
    return 0;
}
int distance(int year,int month,int day){
    int leapyears[71] = {1210,1214,1218,1222,1226,1230,1234,
                         1238,1243,1247,1251,1255,1259,1263,
                         1267,1271,1276,1280,1284,1288,1292,
                         1296,1300,1304,1309,1313,1317,1321,
                         1325,1329,1333,1337,1342,1346,1350,
                         1354,1358,1362,1366,1370,1375,1379,
                         1383,1387,1391,1395,1399,1403,1408,
                         1412,1416,1420,1424,1428,1432,1436,
                         1441,1445,1449,1453,1457,1461,1465,
                         1469,1474,1478,1482,1486,1490,1494,
                         1498};
    int sum = 0;
    sum+=(year - 1206);
    sum*=365;
    if (month <= 7){
        sum+=((month - 1) * 31);
    }
    else {
        sum+=186;
        sum+=((month - 7) * 30);
    }
    for (int i = 0 ; i < 71 ; i++){
        if (year <= leapyears[i]){
            sum+=i;
            break;
        }
    }
    sum+=day;
    sum--;
    return sum;
}
void gregorianconvert(int year,int month,int day){
    int y,m,d;
    if (month == 10 && day < 12){
        y = year + 621;
    }
    else if (month < 10){
        y = year + 621;
    }
    else {
        y = year + 622;
    }
    if (month == 10 && day >= 12){
        m = 1;
        d = day - 11;
    }
    else if (month == 11 && day <= 12){
        m = 1;
        d = day + 19;
    }
    else if (month == 11 && day >= 13){
        m = 2;
        d = day - 12;
    }
    else if (month == 12 && day <= 10){
        m = 2;
        d = day + 18;
    }
    else if (month == 12 && day >= 11){
        m = 3;
        d = day - 10;
    }
    else if (month == 1 && day <= 12){
        m = 3;
        d = day + 19;
    }
    else if (month == 1 && day >= 13){
        m = 4;
        d = day - 12;
    }
    else if (month == 2 && day <= 11){
        m = 4;
        d = day + 19;
    }
    else if (month == 2 && day >= 12){
        m = 5;
        d = day - 11;
    }
    else if (month == 3 && day <= 11){
        m = 5;
        d = day + 19;
    }
    else if (month == 3 && day >= 12){
        m = 6;
        d = day - 11;
    }
    else if (month == 4 && day <= 10){
        m = 6;
        d = day + 20;
    }
    else if (month == 4 && day >= 11){
        m = 7;
        d = day - 10;
    }
    else if (month == 5 && day <= 10){
        m = 7;
        d = day + 21;
    }
    else if (month == 5 && day >= 11){
        m = 8;
        d = day - 10;
    }
    else if (month == 6 && day <= 10){
        m = 8;
        d = day + 21;
    }
    else if (month == 6 && day >= 11){
        m = 9;
        d = day - 10;
    }
    else if (month == 7 && day <= 9){
        m = 9;
        d = day + 21;
    }
    else if (month == 7 && day >= 10){
        m = 10;
        d = day - 9;
    }
    else if (month == 8 && day <= 10){
        m = 10;
        d = day + 21;
    }
    else if (month == 8 && day >= 11){
        m = 11;
        d = day - 10;
    }
    else if (month == 9 && day <= 10){
        m = 11;
        d = day + 20;
    }
    else if (month == 9 && day >= 11){
        m = 12;
        d = day - 10;
    }
    else if (month == 10 && day <= 11){
        m = 12;
        d = day + 20;
    }
    d++;
    if (d == 32){
        m++;
        d = 1;
        if (m == 13){
            m = 1;
            y++;
        }
    }
    else if (d == 31){
        if (m == 4 || m == 6 || m == 9 || m == 11){
            m++;
            d = 1;
        }
    }
    else if (d == 29){
        if (m == 2){
            m++;
            d = 1;
        }
    }
    printf("Gregorian date : %d %d %d\n",y,m,d);
    for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
}
void solarconvert(int year,int month,int day){
    int y,m,d;
    if (month == 3 && day < 20){
        y = year - 622;
    }
    else if (month < 3){
        y = year - 622;
    }
    else {
        y = year - 621;
    }
    if (month == 3 && day >= 20){
        m = 1;
        d = day - 19;
    }
    else if (month == 4 && day <= 19){
        m = 1;
        d = day + 12;
    }
    else if (month == 4 && day >= 20){
        m = 2;
        d = day - 19;
    }
    else if (month == 5 && day <= 20){
        m = 2;
        d = day + 11;
    }
    else if (month == 5 && day >= 21){
        m = 3;
        d = day - 20;
    }
    else if (month == 6 && day <= 20){
        m = 3;
        d = day + 11;
    }
    else if (month == 6 && day >= 21){
        m = 4;
        d = day - 20;
    }
    else if (month == 7 && day <= 21){
        m = 4;
        d = day + 10;
    }
    else if (month == 7 && day >= 22){
        m = 5;
        d = day - 21;
    }
    else if (month == 8 && day <= 21){
        m = 5;
        d = day + 10;
    }
    else if (month == 8 && day >= 22){
        m = 6;
        d = day - 21;
    }
    else if (month == 9 && day <= 21){
        m = 6;
        d = day + 10;
    }
    else if (month == 9 && day >= 22){
        m = 7;
        d = day - 21;
    }
    else if (month == 10 && day <= 21){
        m = 7;
        d = day + 9;
    }
    else if (month == 10 && day >= 22){
        m = 8;
        d = day - 21;
    }
    else if (month == 11 && day <= 20){
        m = 8;
        d = day + 10;
    }
    else if (month == 11 && day >= 21){
        m = 9;
        d = day - 20;
    }
    else if (month == 12 && day <= 20){
        m = 9;
        d = day + 10;
    }
    else if (month == 12 && day >= 21){
        m = 10;
        d = day - 20;
    }
    else if (month == 1 && day <= 19){
        m = 10;
        d = day + 12;
    }
    else if (month == 1 && day >= 20){
        m = 11;
        d = day - 19;
    }
    else if (month == 2 && day <= 18){
        m = 11;
        d = day + 12;
    }
    else if (month == 2 && day >= 19){
        m = 12;
        d = day - 18;
    }
    else if (month == 3 && day <= 19){
        m = 12;
        d = day + 10;
    }
    d--;
    if (d == 0){
        if (m == 1){
            d = 29;
            m = 12;
            y--;
        }
        else if (m == 2 || m == 3 || m == 4 || m == 5 || m == 6 || m == 7){
            m--;
            d = 31;
        }
        else {
            m--;
            d = 30;
        }
    }
    printf("SOlar date : %d %d %d\n",y,m,d);
    for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
}

void printer(int year,int month,int day,int age){
    int rem = distance(year,month,day)%7;
    int leap = isleap(year); 
    int i,j = 0;
    int k;
    if (month <= 6){
        k = 31;
    }
    else if (month >= 7 && month != 12){
        k = 30;
    }
    else if (month == 12 && leap){
        k = 30;
    }
    else{
        k = 29;
    }
    printf("ST SN MN TU WD TH FR\n");
    for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
    if (rem == 0){
        j = 5;
        printf("               ");
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 1){
        j = 6;
        printf("                  ");
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 2){
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
            
            printf("\n");
                for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 3){
        j = 1;
        printf("   ");
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 4){
        printf("      ");
        j = 2;
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 5){
        printf("         ");
        j = 3;
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 6){
        printf("            ");
        j = 4;
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            if (i == age){
                printf("\033[1;34m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
                j = 0;
            }
        }
    }
    printf("\n");
    for (int i = 0 ; i < 20 ; i++){
        printf("- ");
    }
    printf("\n");
}
void calendar(){
    int year,month;
    system("cls");
    while (1){
        printf("[0] Back to menu!\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Enter year : ");
        scanf("%d",&year);
        if (year == 0){
            system("cls");
            printf("Back to menu!");
            printf("\n");
            return;
        }
        else if (year > 1498 || year < 1206){
            while (1){
                system("cls");
                printf("[0] Back to menu!\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                printf("Invalid input! (year not found)\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                printf("Enter year : ");
                scanf("%d",&year);
                if (year == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
                }
                else if (year > 1498 || year < 1206){
                    continue;
                }
                else {
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                    printf("- ");
                    }
                    printf("\n");
                    printf("Enter year : %d\n",year);
                    break;
                }
            }
        }
        printf("Enter month : ");
        scanf("%d",&month);
        if (month == 0){
            system("cls");
            printf("Back to menu!");
            printf("\n");
            return;
        }
        else if (month > 12 || month < 1){
            while (1){
                system("cls");
                printf("[0] Back to menu!\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                printf("Invalid input! (month not found)\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                printf("Enter year : %d ",year);
                printf("\nEnter month : ");
                scanf("%d",&month);
                if (month == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
                }
                else if (month > 12 || month < 1){
                    continue;
                }
                else {
                    break;
                }
            }
        }
        system("cls");
        if (month == 1){
            printf("     Farvardin\n");
        }
        else if (month == 2){
            printf("    Ordibehesht\n");
        }
        else if (month == 3){
            printf("      khordad\n");
        }
        else if (month == 4){
            printf("        Tir\n");
        }
        else if (month == 5){
            printf("      Mordad\n");
        }
        else if (month == 6){
            printf("     shahrivar\n");
        }
        else if (month == 7){
            printf("        Mehr\n");
        }
        else if (month == 8){
            printf("        Aban\n");
        }
        else if (month == 9){
            printf("        Azar\n");
        }
        else if (month == 10){
            printf("        Dey\n");
        }
        else if (month == 11){
            printf("      Bahman\n");
        }
        else {
            printf("       Esfand\n");
        }
        printer(year,month,1,0);
    }
}

void agecalendar(int by,int bm,int bd){
    int n;
    printf("Extra options\n");
    for (int i = 0 ; i < 20 ; i++){
        printf("- ");
    }
    printf("\n");
    printf("[1] Show birthday in solar calendar\n[2] Show birthday in gregorian date\n[else] Exit\n");
    for (int i = 0 ; i < 20 ; i++){
        printf("- ");
    }
    printf("\nSelect : ");
    scanf("%d",&n);
    if (n == 2){
        system("cls");
        gregorianconvert(by,bm,bd);
    }
    else if (n == 1) {
        system("cls");
        if (bm == 1){
            printf("     Farvardin\n");
        }
        else if (bm == 2){
            printf("    Ordibehesht\n");
        }
        else if (bm == 3){
            printf("      khordad\n");
        }
        else if (bm == 4){
            printf("        Tir\n");
        }
        else if (bm == 5){
            printf("      Mordad\n");
        }
        else if (bm == 6){
            printf("     shahrivar\n");
        }
        else if (bm == 7){
            printf("        Mehr\n");
        }
        else if (bm == 8){
            printf("        Aban\n");
        }
        else if (bm == 9){
            printf("        Azar\n");
        }
        else if (bm == 10){
            printf("        Dey\n");
        }
        else if (bm == 11){
            printf("      Bahman\n");
        }
        else {
            printf("       Esfand\n");
        }
        printer(by,bm,1,bd);
    }
    else {
        system("cls");
        return;
    }

}
void agecalculator(int by,int bm,int bd,int cy,int cm,int cd){
    int a,b,totalday,temp,x;
    int year,month,day;
    int leap = 0;
    int i;
    a = distance(by,bm,bd);
    b = distance(cy,cm,cd);
    totalday = b - a;
    for (i = by ; i < cy ; i++){
        leap+=isleap(i);
    }
    year = totalday / 365;
    temp = totalday%365;
    temp-=leap;
    month = temp / 30;
    temp%=30;
    day = temp;
    x = distance(by,bm,bd)%7;
    printf("%d days has passed since your birthday\n",totalday);
    if (x == 0){
    printf("You were born on Thursday\n");
    }
    else if (x == 1){
    printf("You were born on friday\n");
    }
    else if (x == 2){
    printf("You were born on saturday\n");
    }
    else if (x == 3){
    printf("You were born on sunday\n");
    }
    else if (x == 4){
    printf("You were born on monday\n");
    }
    else if (x == 5){
    printf("You were born on tuesday\n");
    }
    else if (x == 6){
    printf("You were born on wednesday\n");
    }
    printf("You are");
    if (year != 0){
    printf(" %d year",year);
    }
    if (year > 1){
    printf("s");
    }
    if (month != 0){
    printf(" %d month",month);
    }
    if (month > 1){
    printf("s");
    }
    if (day != 0){
    printf(" %d day",day);
    }
    if (day > 1){
    printf("s");
    }
    printf(" old\n");
    for (int i = 0 ; i < 20 ; i++){
        printf("- ");
    }
    printf("\n");
    agecalendar(by,bm,bd);
}
void age(){
    int birthyear,birthmonth,birthday;
    int currentyear,currentmonth,currentday;
    system("cls");
    while (1){
            printf("[0] Back to menu!\n");
            for (int i = 0 ; i < 20 ; i++){
                printf("- ");
            }
            printf("\n");
            printf("[Format] year / month / day\n");
            for (int i = 0 ; i < 20 ; i++){
                printf("- ");
            }
            printf("\n");
            printf("Enter date of birth : ");
            scanf("%d",&birthyear);
            if (birthyear == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
            }
            scanf("%d",&birthmonth);
            if (birthmonth == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
            }
            scanf("%d",&birthday);
            if (birthday == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
            }
            if (birthday < 0 || birthday > 31 || birthmonth < 0 || birthmonth > 12 || birthyear < 0 ){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : ");
                    scanf("%d",&birthyear);
                    if (birthyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&birthmonth);
                    if (birthmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&birthday);
                    if (birthday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (birthday < 0 || birthday > 31 || birthmonth < 0 || birthmonth > 12 || birthyear < 0 ){
                        continue;
                    }
                    else {
                        system("cls");
                        printf("[0] Back to menu!\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                        printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                        printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                        break;
                    }
                }
            }
            else if (birthmonth > 6 && birthday > 30){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : ");
                    scanf("%d",&birthyear);
                    if (birthyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&birthmonth);
                    if (birthmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&birthday);
                    if (birthday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (birthday < 0 || birthday > 31 || birthmonth < 0 || birthmonth > 12 || birthyear < 0 ){
                        continue;
                    }
                    else if (birthmonth > 6 && birthday > 30){
                        continue;
                    }
                    else {
                        system("cls");
                        printf("[0] Back to menu!\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                        printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                        printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                        break;
                    }
                }
            }
            printf("Enter current date : ");
            scanf("%d",&currentyear);
            if (currentyear == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
            }
            scanf("%d",&currentmonth);
            if (currentmonth == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
            }
            scanf("%d",&currentday);
            if (currentday == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
            }
            if (currentday < 0 || currentday > 31 || currentmonth < 0 || currentmonth > 12 || currentyear < 0 ){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                    printf("Enter current date : ");
                    scanf("%d",&currentyear);
                    if (currentyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentmonth);
                    if (currentmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentday);
                    if (currentday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (currentday < 0 || currentday > 31 || currentmonth < 0 || currentmonth > 12 || currentyear < 0 ){
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (currentmonth > 6 && currentday > 30){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                    printf("Enter current date : ");
                    scanf("%d",&currentyear);
                    if (currentyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentmonth);
                    if (currentmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentday);
                    if (currentday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (currentday < 0 || currentday > 31 || currentmonth < 0 || currentmonth > 12 || currentyear < 0 ){
                        continue;
                    }
                    else if (currentmonth > 6 && currentday > 30){
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (currentyear < birthyear){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                    printf("Enter current date : ");
                    scanf("%d",&currentyear);
                    if (currentyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentmonth);
                    if (currentmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentday);
                    if (currentday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (currentday < 0 || currentday > 31 || currentmonth < 0 || currentmonth > 12 || currentyear < 0 ){
                        continue;
                    }
                    else if (currentmonth > 6 && currentday > 30){
                        continue;
                    }
                    else if (currentyear < birthyear){
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (currentyear == birthyear && currentmonth < birthmonth){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                    printf("Enter current date : ");
                    scanf("%d",&currentyear);
                    if (currentyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentmonth);
                    if (currentmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentday);
                    if (currentday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (currentday < 0 || currentday > 31 || currentmonth < 0 || currentmonth > 12 || currentyear < 0 ){
                        continue;
                    }
                    else if (currentmonth > 6 && currentday > 30){
                        continue;
                    }
                    else if (currentyear == birthyear && currentmonth < birthmonth){
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            else if (currentyear == birthyear && currentmonth == birthmonth && currentday < birthday){
                while (1){
                    system("cls");
                    printf("[0] Back to menu!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("[Format] year / month / day\n");
                        for (int i = 0 ; i < 20 ; i++){
                            printf("- ");
                        }
                        printf("\n");
                    printf("Invalid date!\n");
                    for (int i = 0 ; i < 20 ; i++){
                        printf("- ");
                    }
                    printf("\n");
                    printf("Enter date of birth : %d %d %d\n",birthyear,birthmonth,birthday);
                    printf("Enter current date : ");
                    scanf("%d",&currentyear);
                    if (currentyear == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentmonth);
                    if (currentmonth == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    scanf("%d",&currentday);
                    if (currentday == 0){
                        system("cls");
                        printf("Back to menu!");
                        printf("\n");
                        return;
                    }
                    if (currentday < 0 || currentday > 31 || currentmonth < 0 || currentmonth > 12 || currentyear < 0 ){
                        continue;
                    }
                    else if (currentmonth > 6 && currentday > 30){
                        continue;
                    }
                    else if (currentyear == birthyear && currentmonth == birthmonth && currentday < birthday){
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
            system("cls");
            agecalculator(birthyear,birthmonth,birthday,currentyear,currentmonth,currentday);
        }
}

void solar(){
    int year,month,day;
    system("cls");
    while (1){
        printf("[0] Back to menu!\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Enter year : ");
        scanf("%d",&year);
        if (year == 0){
            system("cls");
            return;
        }
        else if (year < 0){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        printf("Enter month : ");
        scanf("%d",&month);
        if (month == 0){
            system("cls");
            return;
        }
        else if (month < 0 || month > 12){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        printf("Enter day : ");
        scanf("%d",&day);
        if (day == 0){
            system("cls");
            return;
        }
        else if (day < 0 || day > 31){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11){
            if (day > 30){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
            }
        }
        else if (month == 2){
            if (day > 28){
                printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
            }
        }
        system("cls");
        solarconvert(year,month,day);
    }
}
void gregorian(){
    int year,month,day;
    system("cls");
    while (1){
        printf("[0] Back to menu!\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Enter year : ");
        scanf("%d",&year);
        if (year == 0){
            system("cls");
            return;
        }
        else if (year < 0){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        printf("Enter month : ");
        scanf("%d",&month);
        if (month == 0){
            system("cls");
            return;
        }
        else if (month < 0 || month > 12){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        printf("Enter day : ");
        scanf("%d",&day);
        if (day == 0){
            system("cls");
            return;
        }
        else if (day < 0 || day > 31){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        else if (month > 6 && day > 30){
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
            system("cls");
            continue;
        }
        system("cls");
        gregorianconvert(year,month,day);

    }
}
void convert(){
    int n;
    system("cls");
    while (1){
        printf("[0] Back to menu!\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("[1] Solar-Gregorian\n[2] Gregorian-Solar\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Select Option : ");
        scanf("%d",&n);
        if (n == 0){
            system("cls");
            printf("Back to menu!\n");
            return;
        }
        if (n == 1){
            gregorian();
        }
        else if (n == 2){
            solar();
        }
        else {
            system("cls");
            printf("Invalid input!\n");
            for (int i = 0 ; i < 20 ; i++){
            printf("- ");
            }
            printf("\n");
        }
    }
}


int main(){
    system("cls");
    printf("Welcome!\n");
    int n;
    while (1){
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("[0] Quit\n");
        printf("[1] Calendar\n");
        printf("[2] Age\n");
        printf("[3] convertion\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Select option : ");
        scanf("%d",&n);
        if (n == 0){
            system("cls");
            printf("Bye!");
            break;
        }
        else if(n == 1){
            calendar();
        }
        else if(n == 2){
            age();
        }
        else if(n == 3){
            convert();
        }
        else {
            system("cls");
            printf("Invalid input!\n");
        }
    }
}