
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comparacao(int frame1[320][240][3], int frame2[320][240][3]);
int comparacao1(int frame1[140][130][3], int frame2[140][130][3]);
void inicialiazarVideo(char *nome, int quantFrames);
void inicializarVideo1();
void inicializarVideo2();

int main(int argc, char *argv[])
{

    char nome[100];

    int quantFrames = 0, opc = 0;

    printf("1 - Video1\n2 - video2\n3 - Outro video a sua escolha\n");
    scanf("%d", &opc);

    if (opc == 1)
    {
        inicializarVideo1();
    }
    else if (opc == 2)
    {
        inicializarVideo2();
    }
    else
    {
        printf("Digite a o nome da pasta que contem os frames(sem espaco no nome da pasta):");
        scanf("%s", nome);
        printf("Digite a quantidade de frames:");
        scanf("%d", &quantFrames);
        inicialiazarVideo(nome, quantFrames);
    }

    return 0;
}

void inicializarVideo1()
{
    FILE *video1, *videoResp;
    int teste = 0;
    int frame1[140][130][3];
    int frameConsequente[140][130][3];
    char filename[100], num[100], nome[100];
    strcpy(nome, "video1");
    video1 = fopen("video1/001.rgb", "rb");
    videoResp = fopen("video1Mudancas.txt", "w+");

    for (int i = 0; i < 320; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i >= 180 && j >= 110)
                {
                    frame1[i - 180][j-110][k] = fgetc(video1);
                }
                else
                {
                    teste= fgetc(video1);
                }
            }
        }
    }
    fclose(video1);

    for (int x = 2; x <= 591; x++)
    {
        itoa(x, num, 10);
        strcat(num, ".rgb");
        if (x < 10)
        {
            strcat(strcpy(filename, nome), "/00");
            strcat(filename, num);
        }
        else if (x < 100)
        {
            strcat(strcpy(filename, nome), "/0");
            strcat(filename, num);
        }
        else
        {
            strcat(strcpy(filename, nome), "/");
            strcat(filename, num);
        }
        video1 = fopen(filename, "rb");
        filename[0] = '\0';
        for (int i = 0; i < 320; i++)
        {
            for (int j = 0; j < 240; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i >= 180 && j >= 110)
                    {
                    	
                        frameConsequente[i - 180][j-110][k] = fgetc(video1);
                        
                    }
                    else
                    {
                        teste=fgetc(video1);
                    }
                }
            }
        }        
        if (comparacao1(frame1, frameConsequente) > 200498)
        {   
            printf("Houve mudanca no frame: %d\n", x);
            fprintf(videoResp, "frame: %d\n", x);
        }
        fclose(video1);
    }
    fclose(videoResp);
}

void inicializarVideo2()
{
    FILE *video1, *videoResp;
    int frame1[320][240][3];
    int frameConsequente[320][240][3];
    char filename[100], num[100], nome[100];
    strcpy(nome, "video2");
    video1 = fopen("video2/001.rgb", "rb");
    videoResp = fopen("video2Mudancas.txt", "w+");

    for (int i = 0; i < 320; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                frame1[i][j][k] = fgetc(video1);
            }
        }
    }
    fclose(video1);

    for (int x = 2; x <= 31; x++)
    {
        itoa(x, num, 10);
        strcat(num, ".rgb");
        if (x < 10)
        {
            strcat(strcpy(filename, nome), "/00");
            strcat(filename, num);
        }
        else if (x < 100)
        {
            strcat(strcpy(filename, nome), "/0");
            strcat(filename, num);
        }
        else
        {
            strcat(strcpy(filename, nome), "/");
            strcat(filename, num);
        }
        video1 = fopen(filename, "rb");
        filename[0] = '\0';
        for (int i = 0; i < 320; i++)
        {
            for (int j = 0; j < 240; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    frameConsequente[i][j][k] = fgetc(video1);
                }
            }
        }
        if (comparacao(frame1, frameConsequente) > 2554780)
        {
            printf("Houve mudanca no frame: %d\n", x);
            fprintf(videoResp, "frame: %d\n", x);
        }
        fclose(video1);
    }
    fclose(videoResp);
}

void inicialiazarVideo(char *nome, int quantFrames)
{
    FILE *video1, *videoResp;

    int frame1[320][240][3];
    int frameConsequente[320][240][3];
    char filename[100], num[100], teste[100];
    strcat(strcpy(filename, nome), "/001.rgb");
    video1 = fopen(filename, "rb");
    strcat(strcpy(filename, nome), "Mudancas.txt");
    videoResp = fopen(filename, "w+");

    for (int i = 0; i < 320; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                frame1[i][j][k] = fgetc(video1);
            }
        }
    }
    fclose(video1);

    for (int x = 2; x <= quantFrames; x++)
    {
        itoa(x, num, 10);
        if (x < 10)
        {
            strcat(strcpy(teste, nome), "/00");
            strcat(num, ".rgb");
            strcat(strcpy(filename, teste), num);
        }
        else if (x < 100)
        {
            strcat(strcpy(teste, nome), "/0");
            strcat(num, ".rgb");
            strcat(strcpy(filename, teste), num);
        }
        else
        {
            strcat(strcpy(teste, nome), "/");
            strcat(num, ".rgb");
            strcat(strcpy(filename, teste), num);
        }
        video1 = fopen(filename, "rb");
        filename[0] = '\0';
        teste[0] = '\0';
        for (int i = 0; i < 320; i++)
        {
            for (int j = 0; j < 240; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    frameConsequente[i][j][k] = fgetc(video1);
                }
            }
        }
        if (comparacao(frame1, frameConsequente) > 2554780)
        {
            printf("Houve mudanca no frame: %d\n", x);
            fprintf(videoResp, "frame: %d\n", x);
        }
        fclose(video1);
    }
    fclose(videoResp);
}

int comparacao(int frame1[320][240][3], int frame2[320][240][3])
{
    int aux = 0, count = 0;
    for (int i = 0; i < 320; i++)
    {
        for (int j = 0; j < 240; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                aux = abs(frame1[i][j][k] - frame2[i][j][k]);
                count = count + aux;
            }
        }
    }
    return count;
}

int comparacao1(int frame1[140][130][3], int frame2[140][130][3])
{
    int aux = 0, count = 0;
    for (int i = 0; i < 140; i++)
    {
        for (int j = 0; j < 130; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                aux = abs(frame1[i][j][k] - frame2[i][j][k]);
                count = count + aux;
            }
        }
    }
    return count;
}
