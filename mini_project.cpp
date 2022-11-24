#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;

class decimal_convert{
    float n;
    int base;
    int inte[100];
    int integ;
    int deca[100];
    int decam;
    public:
        decimal_convert()
        {
            cout << "Enter the number to be converted:\t";
            cin >> n;
            cout << "Enter the base to be converted into:\t";
            cin >> base;
            int_con(int(n));
            if(n-int(n) != 0)
            {
                dec_con(n-int(n));
            }
            cout << endl << string(40,'-');
            cout << "\n\nThe whole number in base " << base << " >> ";
            for(;integ>=0;integ--)
            {
                if(base!=16){
                        cout << inte[integ];
                    }
                    else{
                        cout << hexa_con(inte[integ]);
                    }
            }
            if(n-int(n) != 0){
                cout << ".";
                for(int j=0;j<decam;j++)
                {
                    if(base!=16){
                        cout << deca[j];
                    }
                    else{
                        cout << hexa_con(deca[j]);
                    }
                }
            }
        }
        void int_con(int n)
        {
            int i;
            cout << endl << endl << string(13,'-') << "FOR INTEGER PART" << string(13,'-') << endl;
            cout << endl << n << ":-" << endl;
            if(n==0){
                cout << "For Integer Part we get >> 0"<< endl << endl;
            }
            else{
                cout << "|" << setw(2) << base << "|" << setw(4) << n << "|" <<setw(2) << " " << "|" << endl;
                for(i=0;n!=0;i++){
                    inte[i] = n%base;
                    cout << "|" << setw(2) << base << "|" << setw(4) << n/base << "|" << setw(2) << n%base << "|" << endl;
                    n = n/base;
                }
                cout << endl << "For Integer Part we get >> ";
                integ = --i;
                for(;i>=0;i--)
                {
                    if(base!=16){
                        cout << inte[i];
                    }
                    else{
                        cout << hexa_con(inte[i]);
                    }
                }
                cout << endl << endl;
            }
        }
        void dec_con(float n)
        {
            int i;
            int t = 1;
            cout << string(13,'-') << "FOR DECIMAL PART" << string(14,'-') << endl;
            cout << setw(5) << fixed << setprecision(2) << n << endl;
            for(i=0;n!=0 && i<5;i++){
                cout << setw(t) << "X" << setw(4) << base << endl;
                cout << string(t-1,' ') << string(5,'-') << endl;
                if(i==4){
                    cout << string(t+3,' ') << setw(5) << fixed << setprecision(2) << n*base << "    <<--BREAK" << endl;
                }
                else{
                    cout << string(t+3,' ') << setw(5) << fixed << setprecision(2) << n*base << endl;
                }
                t+=4;
                deca[i] = int(n*base);
                n = (n*base) - int(n*base);
            }
            cout << endl;
            cout << "For Decimal part we get >> 0.";
            decam = i;
            for(int j=0;j<i;j++){
                if(base!=16){
                        cout << deca[j];
                    }
                    else{
                        cout << hexa_con(deca[j]);
                    }
            }
        }
        char hexa_con(int n){
            char hexa[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
            return hexa[n];
        }
};

class number_convert{
    int base;
    int decimal;
    int imp_i;
    double total = 0;
    char n[100];
    int m_n[100];
    public:
    void arr_con()
    {
        int dec = 0;
        int arr[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        for(int i=0;i<strlen(n);i++){
            if (int(n[i])==46){
                dec = 1;
                decimal = 1;
                m_n[i] = 9378468;
                imp_i = i;
            }
            else if (int(n[i])>47 && int(n[i])<57){
                if(dec==0){
                    m_n[i] = int(n[i])-48;
                }
                else{
                    m_n[i] = (int(n[i])-48);
                }
            }
            else if(int(n[i])>64 && int(n[i])<71){
                if (dec==0){
                    m_n[i] = int(n[i])-55;
                }
                else{
                    m_n[i] = (int(n[i])-55);
                }
            }
            else{
                cout << "\nPlease enter a valid number!" << endl;
                number_convert x;
                cout << endl << string(strlen(n)+1,' ') << "= " << total;
                abort();
            }
        }
    }
    
    void va_base()
    {
        if (base != 8 && base != 2 && base != 16){
            cout << "\nPlease enter a valid base!\t" << endl;
            number_convert x;
            cout << endl << string(strlen(n)+1,' ') << "= " << total;
            abort();
        }
    }
    
    void va_pair()
    {
        for(int i=0;i<strlen(n);i++){
            if(m_n[i]!=9378468)
            {
                if(base==2){
                    if(m_n[i]>1){
                        cout << "\nBase and the entered number do not match!\nPlease Enter Again!\n" << endl;
                        number_convert x;
                        cout << endl << string(strlen(n)+1,' ') << "= " << total;
                        abort();
                    }
                    }
                else if(base==8){
                    if(m_n[i]>7){
                        cout << "\nBase and the entered number do not match!\nPlease Enter Again!\n" << endl;
                        number_convert x;
                        cout << endl << string(strlen(n)+1,' ') << "= " << total;
                        abort();
                    }
                    }
                else if(base==16){
                    if(m_n[i]>15){
                        cout << "\nBase and the entered number do not match!\nPlease Enter Again!\n" << endl;
                        number_convert x;
                        cout << endl << string(strlen(n)+1,' ') << "= " << total;
                        abort();
                    }
                }
            }
        }
    }
    void convert()
    {
        cout << endl;
        int j = 0;
        cout << string(13,'*') << "CONVERTING INTO DECIMAL" << string(13,'*') << endl << endl;
        for(int i=0;i<strlen(n);i++){
            cout << n[i];
        }
        cout << " = ";
        if(decimal==0){
            for(int i=strlen(n)-1;i>=0;i--,j++){
                if(i==0){
                    cout << m_n[i] << "X(" << base << "**" << j << ")";
                }
                else{
                    cout << m_n[i] << "X(" << base << "**" << j << ")" << " + " ;
                }
                total += m_n[i]*(pow(base,j));
           }
       }
       else{
           j = 0;
           for(int i=imp_i-1;i>=0;i--,j++){
               cout << m_n[i] << "X(" << base << "**" << j << ")" << " + " ;
               total += m_n[i]*(pow(base,j));
           }
           j = -1;
           for(int i=imp_i+1;i<=strlen(n)-1;i++,j--){
               if(i==strlen(n)-1){
                    cout << m_n[i] << "X(" << base << "**" << j << ")";
                }
                else{
                    cout << m_n[i] << "X(" << base << "**" << j << ")" << " + " ;
                }
                total += m_n[i]*(pow(base,j));
           }
       }
       cout << endl << string(strlen(n)+1,' ') << "= " << total;
    }
    number_convert()
    {   
        cout << "Enter the number to be converted:\t";
        cin >> n;
        arr_con();
        cout << "Enter the base of the number:\t";
        cin >> base;
        va_base();
        va_pair();
        convert();
    }
};
void arr_con(int y); 
void va_base();
void va_pair(int y);
void con_bin_h(int y);
void con_bin_o(int y);
void add_bin(int y);
void ans(int y);
void bin_con(int y);
char hex(int y);
void eq_len();
void complement(int y,int g);
void add_func();
void final_comp(int g);
void Addition();

int carry;
char n[2][100];
int m_n[2][100];
int b[2][100];
int add[100];
int neg_n1 = 0;
int neg_n2 = 0;
int fin_add[100];
int base;
char neg=' ';
float total;
int main()
{
    int op;
    cout << "*******CONVERSION OF NUMBERS AND ARITHMETIC*********" << endl;
    cout << "\nSelect an option to be performed...\n\n1.Decimal to other Number systems\n2.Other Number Systems to Decimal.\n3.Addition/Subtraction using 2's compliment.\n";
    cin >> op;
    cout << endl << endl;
    op--;
    switch(op){
        case 0:{
            decimal_convert obj1;
            return 0;
        }
        case 1:{
            number_convert obj1;
            return 0;
        }
        case 2:{
            Addition();
            return 0;
        }
        default:{
            cout << "Please enter a valid option!\n";
            main();
            abort();
        }
    }
}
void Addition(){
    cout << "Enter Your First Number:\t" ;
    cin >> n[0];
    cout << "Enter Your Second Number:\t";
    cin >> n[1];
    eq_len();
    arr_con(0);
    arr_con(1);
    cout << "Enter the Base of both Number:\t";
    cin >> base;
    cout << endl;
    va_base();
    va_pair(0);
    va_pair(1);
    cout << endl << "---------------SOLUTION---------------"  << endl << endl;
    add_func();
}
void arr_con(int y)
{
    int dec = 0;
    int arr[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for(int i=0;i<=strlen(n[y])-1;i++){
        if (int(n[y][i])>47 && int(n[y][i])<58){
            m_n[y][i] = int(n[y][i])-48;
            m_n[y][i] = (int(n[y][i])-48);
        }
        else if(int(n[y][i])>64 && int(n[y][i])<71){
            m_n[y][i] = int(n[y][i])-55;
            m_n[y][i] = (int(n[y][i])-55);
        }
        else{
            cout << "\nPlease enter a valid number!" << endl;
            main();
            abort();
        }
    }
}
void va_base()
{
    if (base != 8 && base != 2 && base != 16){
        cout << "\nPlease enter a valid base!\t" << endl;
        main();
        abort();
    }
}
void va_pair(int y)
{
    for(int i=0;i<=strlen(n[y])-1;i++){
        
            if(base==2){
                if(m_n[y][i]>1){
                    cout << "\nBase and the entered number do not match!\nPlease Enter Again!\n" << endl;
                    main();
                    abort();
                }
                }
            else if(base==8){
                if(m_n[y][i]>7){
                    cout << "\nBase and the entered number do not match!\nPlease Enter Again!\n" << endl;
                    main();
                    abort();
                }
                }
            else if(base==16){
                if(m_n[y][i]>15){
                    cout << "\nBase and the entered number do not match!\nPlease Enter Again!\n" << endl;
                    main();
                    abort();
                }
            }
    }
}
void con_bin_h(int y)
{
    int m = 0;
    int z;
    int con[16][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
    for(int i=0;i<strlen(n[y]);i++){
        z = m_n[y][i];
        for(int j=0;j<4;j++,m++){
            b[y][m] = con[z][j];
        }
    }
}
void con_bin_o(int y){
    int m = 0;
    int z;
    int con[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    for(int i=0;i<strlen(n[y]);i++){
        z = m_n[y][i];
        for(int j=0;j<3;j++,m++){
            b[y][m] = con[z][j];
        }
    }
}
void add_bin(int g)
{
    int fk;
    if((strlen(n[1])*g)>=strlen(n[0])*g){
        fk = (strlen(n[1])*g);
    }
    else{
        fk = (strlen(n[0])*g);
    }
    cout << endl << "ADDITION OF BINARY NUMBERS" << endl << endl;
    cout << "    ";
    for(int i=0;i<fk;i++){
        cout << b[0][i];
        cout << " ";
        }
    cout << endl << "  + ";
    for(int i=0;i<fk;i++){
        cout << b[1][i];
        cout << " ";
        }
    cout << endl << "    ";
    for(int i=0;i<fk*2;i++){
        cout << "-";
    }
    for(int i=fk;i>=0;i--){
        if(carry==0){
            if(b[0][i]==0 && b[1][i]==0){
                add[i] = 0;
            }
            else if(b[0][i]==0 && b[1][i]==1){
                add[i] = 1;
            }
            else if(b[0][i]==1 && b[1][i]==0){
                add[i] = 1;
            }
            else{
                add[i] = 0;
                carry = 1;
            }
        }
        else{
            if(b[0][i]==0 && b[1][i]==0){
                add[i] = 1;
                carry = 0;
            }
            else if(b[0][i]==0 && b[1][i]==1){
                add[i] = 0;
                carry = 1;
            }
            else if(b[0][i]==1 && b[1][i]==0){
                add[i] = 0;
                carry = 1;
            }
            else{
                add[i] = 1;
                carry = 1;
            }
        }
    }
}
void ans(int g)
{
    for(int i=0;i<strlen(n[0]);i++){
    cout << n[0][i];
    }
    cout << " = ";
    for(int i=0;i<(strlen(n[0])*g);i++){
    if(i%g==0){
        cout << " ";
    }
    cout << b[0][i];
    }
    if(neg_n1==1){
        cout << "\n2s complement :\t";
        complement(0,g);
        for(int i=0;i<strlen(n[0])*g;i++){
            if(i%g==0){
                cout << " ";
            }
            cout << b[0][i];
        }
    } 
    cout << endl << endl;
    for(int i=0;i<strlen(n[1]);i++){
    cout << n[1][i];
    }
    cout << " = ";
    for(int i=0;i<(strlen(n[1])*g);i++){
    if(i%g==0){
        cout << " ";
    }
    cout << b[1][i];
    }
    if(neg_n2==1){
        cout << "\n2s complement :\t";
        complement(1,g);
        for(int i=0;i<strlen(n[1])*g;i++){
            if(i%g==0){
                cout << " ";
            }
            cout << b[1][i];
        }
    }
    cout << endl;
    add_bin(g);
    if(carry==1){
        cout << endl << "  1 ";
    }
    else{
    cout << endl << "    ";
    }
    for(int i=0;i<strlen(n[1])*g;i++)
    {
        cout << add[i];
        cout << " ";
    }
    cout << endl;
}
void bin_con(int g)
{
    int fk;
    int total = 0;
    int m = strlen(n[0])+1;
    int j = 0;
    if(carry==1){
        fin_add[0] = 1;
    }
    else{
        fin_add[0] = 0;
    }
    m--;
    if((strlen(n[1])*g)>=strlen(n[0])*g){
        fk = (strlen(n[1])*g);
    }
    else{
        fk = (strlen(n[0])*g);
    }
    for(int i=fk-1;i>=0;i--,j++){
        total += add[i]*(pow(2,j));
        if(j==g-1)
        {
            fin_add[m] = total;
            m--;
            total = 0;
            j = -1;
        }
    }
}
char hex(int y)
{
    char con[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    return con[y];
}
void eq_len()
{
    char dum[100];
    int x;
    int g;
    int f = strlen(n[0]);
    int v = strlen(n[1]);
    if(n[0][0]=='-'){
        n[0][0] = '0';
        neg_n1 = 1;
    }
    if(n[1][0]=='-'){
        n[1][0] = '0';
        neg_n2 = 1;
    }
    if(f>v){
        g = 1;
        x = f-v;
    }
    else{
        g = 0;
        x = v-f;
    }
    for(int i=0;i<x;i++){
        dum[i] = '0';
    }
    int y = x;
    for(int i=0;i<strlen(n[g]);i++,x++)
    {
        dum[x] = n[g][i];
    }
    for(int i=0;i<strlen(n[g])+y;i++){
        n[g][i] = dum[i];
    }
}
void add_func(){
    if(base!=2){
        cout << "CONVERSION INTO BINARY" << endl << endl;
        if(base==16){
            con_bin_h(0);
            con_bin_h(1);
            ans(4);
            if(neg_n1==1||neg_n2==1){
                final_comp(4);
            }
            bin_con(4);
        }
        else{
            con_bin_o(0);
            con_bin_o(1);
            ans(3);
            if(neg_n1==1||neg_n2==1){
                final_comp(3);
            }
            bin_con(3);
        }
        cout << endl << endl;
        cout << "Final Anwer is \t:";
        cout << neg;
        for(int i=0;i<strlen(n[0])+1;i++){
            if(base==16){
                cout << hex(fin_add[i]);
            }
            else{
                cout << fin_add[i];
            }
        }
    }
    else{
        for(int i=0;i<strlen(n[0]);i++){
            b[0][i] = m_n[0][i];
        }
        for(int i=0;i<strlen(n[1]);i++){
            b[1][i] = m_n[1][i];
        }
        if(neg_n1==1){
            complement(0,1);
            cout << "2'complement for number 1 is :\t";
            for(int i=0;i<strlen(n[0]);i++){
                cout << b[1][i];
            }
        }
        if(neg_n2==1){
            complement(1,1);
            cout << "2'complement for number 2 is :\t";
            for(int i=0;i<strlen(n[0]);i++){
                cout << b[1][i];
            }
        }
        add_bin(1);
        if(neg_n1==1||neg_n2==1){
            final_comp(1);
        }
        if(carry==1){
        cout << endl << "  1 ";
        }
        else{
        cout << endl << "    ";
        }
        for(int i=0;i<strlen(n[1]);i++)
        {
            cout << add[i];
            cout << " ";
        }
        cout << endl << endl;
        cout << "Final Anwer is \t:";
        if(carry==1){
            cout << 1;
        }
        cout << neg;
        for(int i=0;i<strlen(n[0]);i++){
            cout << add[i];
        }
    }
    cout << " with base " << base << endl;
    cout << endl << "----------------THE-END---------------";
}
void complement(int y,int g){
    int dtc = 0;
    for(int i=(strlen(n[0])*g)-1;i>=0;i--){
        if(dtc==0){
            if(b[y][i]==0){
                b[y][i] = 0;
            }
            else{
                b[y][i] = 1;
                dtc = 1;
            }
        }
        else{
            if(b[y][i]==0){
                b[y][i] = 1;
            }
            else{
                b[y][i] = 0;
            }
        }
    }
}
void final_comp(int g){
    int dtc=0;
    if(carry==0){
        neg = '-';
        for(int i=(strlen(n[0])*g)-1;i>=0;i--){
            if(dtc==0){
                if(add[i]==0){
                    add[i]=0;
                }
                else{
                    add[i]=1;
                    dtc = 1;
                }
            }
            else{
                if(add[i]==1){
                    add[i]=0;
                }
                else{
                    add[i]=1;
                }
            }
            
        }
        cout << "\nCarry is not generated, answer is negative and in 2's compliment form.\t:";
        for(int i=0;i<strlen(n[0])*g;i++){
            cout << add[i];
        }
    }
    else{
        cout << "Carry is generated, therefore discarding carry we get,\n";
        carry=0;
        if(neg_n1==1&&neg_n2==1){
            neg = '-';
            cout << "\nSince both numbers are negative take 2's compliment again\n";
            for(int i=(strlen(n[0])*g)-1;i>=0;i--){
                if(dtc==0){
                    if(add[i]==0){
                        add[i]=0;
                    }
                    else{
                        add[i]=1;
                        dtc = 1;
                    }
                }
                else{
                    if(add[i]==1){
                        add[i]=0;
                    }
                    else{
                        add[i]=1;
                    }
                }
            
        }
        }
    }
}