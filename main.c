#include <stdio.h> //добавляем библиотеку для ввода вывода
#include <stdbool.h> //эта для булевых функций
#include <windows.h> //эта для нормальной интерпритации русского языка, а не кракозябры
#include <ctype.h>


int findvar(const char *formula, char var[]){
    int count = 0;
    for (int i =0; formula[i]!= '\0'; i++){
        char x = formula[i];
        if (x >= 'a' && x<= 'z'){
            x = x- 'a' + 'A';
        }

        if (x>= 'A' && x<= 'Z'){
            bool found = false;

            for (int j = 0; j< count; j++)
            {
                if (var[j] == x)
                {
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                var[count] =x; //записываем х в массив переменных
                count++;
            }
            
        }
    }

    return count;

}






int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8); //тут тоже чтото для исправления крокозябр
    
    if (argc<2)
    {
        printf("Укажите имя файла!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r"); //открываем файл и читаем его с помощью "r"


    if (file == NULL) //если файл пустой, нулл=пустота
    {
        printf("Файл не найден\n");
        return 1;
    }


    char formula[1000]; //создали массив куда кладем формулу
    
    if (fgets(formula, 1000, file) != NULL)
    {
        printf("Формула:%s\n", formula);
        char var[26]; //возьмем массив из 26 символов тк в лат алфавите 26 букв
        
        int varcount = findvar(formula, var);


        for (int i =0; i<varcount; i++)
        {
            printf("%c ", var[i]);
            
        }
        printf("\n");
            int rows = 1 << varcount; // степени двойки для нахождения кол-ва переменных
        for (int i=0; i< rows; i++)
        {
            for (int j = 0; j < varcount; j++)
            {
                int bit = varcount-1-j; // получаем значения битов слева направо
                int value = (i>>bit)&1;
                printf("%d ", value);

            }
            printf("\n");
        }
    }
    else
    {
        printf("Файл пустой((\n");
    }
    fclose(file);

    return 0;
}



//cd ".\лаба 1" 
//gcc main.c -o main.exe
//.\main.exe formula.txt

/*
!    НЕ
*    И
^    XOR
+    ИЛИ
=    эквивалентность
>    импликация
<    коимпликация
%    стрелка Пирса
|    штрих Шеффера
*/