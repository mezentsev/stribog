#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>
#include <QDebug>

#include "stribog.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);

    if (argc > 2){
        // char -> hex
        char *in = argv[2];
        int len = 512;
        try {
            if ( atoi(argv[1]) == 256)
                len = 256;

        } catch (const char * msg)
        {
            printf("%s", msg);
            return 0;
        }

        byte *message = (byte*)in;
        byte out[64];
        hash(message, out, len);
        printf("\nHASH: \n");
        for (int i = 0; i < (len >> 3); i++)
        {
            printf("%.2x", out[i]);
        }
    }
    else
    {
        printf("Usage: [bit len (256, 512)] \"[message]\"");
    }

    return a.exec();
}
