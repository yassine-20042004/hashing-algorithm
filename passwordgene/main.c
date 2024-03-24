#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void string_to_hex(const char *input, char *output) {
    int len = strlen(input);
    for (int i = 0, j = 0; i < len; ++i, j += 2) {
        sprintf(output + j, "%02x", input[i]);
    }
}

int main()
{
  FILE* ff=fopen("passwordslist.txt","a+");
  FILE* fb=fopen("hashlist.txt","a+");

  int i,j,randomnumber=NULL;

  char *password;

  char *numbers="0123456789";

  char *upcar="QWERTYUIOPASDFGHJKLZXCVBNM";

  char *lowcar="qwertyuiopasdfghjklzxcvbnm";

  char *specialcar="@#-()?&!=/";

  password=(char *) malloc(sizeof(char)*10);

  srand(time(NULL));


  randomnumber= rand() % 26;
  password[0]=upcar[randomnumber];
  randomnumber= rand() % 26;
  password[1]=lowcar[randomnumber];
  randomnumber= rand() % 26;
  password[2]=lowcar[randomnumber];
  randomnumber= rand() % 26;
  password[3]=upcar[randomnumber];
  randomnumber= rand() % 26;
  password[4]=lowcar[randomnumber];
  randomnumber= rand() % 10;
  password[5]=specialcar[randomnumber];
  randomnumber= rand() % 10;
  password[6]=numbers[randomnumber];
  randomnumber= rand() % 10;
  password[7]=numbers[randomnumber];
  randomnumber= rand() % 10;
  password[8]=numbers[randomnumber];
  randomnumber= rand() % 10;
  password[9]=specialcar[randomnumber];

  password[10]='\0';

  fprintf(ff,"%s \n",password);



    char hex_string[20];

    char hashstring[20];

    string_to_hex(password, hex_string);

    i=0;
    j=19;
    while(i<20)
        {
            hashstring[i]=hex_string[j];
            i++;
            j--;
        }
    for(i=0;i<10;i++)
        {
            hex_string[i]=hashstring[i+10];
        }
      for(i=0;i<10;i++)
        {
            hex_string[i+10]=hashstring[i];
        }

    fprintf(fb,"%s \n",hex_string);

   fclose(fb);
   fclose(ff);

    return 0;
}
