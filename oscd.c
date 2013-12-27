/*
 *  Copyright (C) 2004 Steve Harris, Uwe Koloska
 *              -added OSC to UDP client (C) 2013 Jesse Forgues
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation; either version 2.1 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  $Id$
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <lo/lo.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SRV_IP "127.0.0.1"
#define PORT 9930
#define BUFSIZE 2048

/*
 * error - wrapper for perror
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

int done = 0;
int int_arg1 = 0;
int int_arg2 = 0;
int int_arg3 = 0;
int int_arg4 = 0;
int int_arg5 = 0;
int int_arg6 = 0;
int int_arg7 = 0;
int int_arg8 = 0;
int int_arg9 = 0;
int int_arg10 = 0;
int int_arg11 = 0;
int int_arg12 = 0;
int int_arg13 = 0;
int int_arg14 = 0;
int int_arg15 = 0;
int int_arg16 = 0;
int int_arg17 = 0;
int int_arg18 = 0;
int int_arg19 = 0;
int int_arg20 = 0;
int int_arg21 = 0;
int int_arg22 = 0;
int int_arg23 = 0;
int int_arg24 = 0;
int int_arg25 = 0;
int int_arg26 = 0;
int int_arg27 = 0;
int int_arg28 = 0;
int int_arg29 = 0;
int int_arg30 = 0;
int int_arg31 = 0;
int int_arg32 = 0;
int int_arg33 = 0;
int int_arg34 = 0;
int int_arg35 = 0;
int int_arg36 = 0;
int int_arg37 = 0;
int int_arg38 = 0;
int int_arg39 = 0;
int int_arg40 = 0;
int int_arg41 = 0;
int int_arg42 = 0;
int int_arg43 = 0;
int int_arg44 = 0;
int int_arg45 = 0;
int int_arg46 = 0;
int int_arg47 = 0;
int int_arg48 = 0;
int int_arg49 = 0;
int int_arg50 = 0;
int int_arg51 = 0;
int int_arg52 = 0;
int int_arg53 = 0;
int int_arg54 = 0;
int int_arg55 = 0;
int int_arg56 = 0;
int int_arg57 = 0;
int int_arg58 = 0;
int int_arg59 = 0;
int int_arg60 = 0;
int int_arg61 = 0;
int int_arg62 = 0;
int int_arg63 = 0;
int int_arg64 = 0;
int int_arg65 = 0;
int int_arg66 = 0;
int int_arg67 = 0;
int int_arg68 = 0;
int int_arg69 = 0;
int int_arg70 = 0;
int int_arg71 = 0;
int int_arg72 = 0;
int int_arg73 = 0;
int int_arg74 = 0;
int int_arg75 = 0;
int int_arg76 = 0;
int int_arg77 = 0;
int int_arg78 = 0;
int int_arg79 = 0;
int int_arg80 = 0;
int int_arg81 = 0;
int int_arg82 = 0;
int int_arg83 = 0;
int int_arg84 = 0;
int int_arg85 = 0;
int int_arg86 = 0;
int int_arg87 = 0;
int int_arg88 = 0;
int int_arg89 = 0;
int int_arg90 = 0;
int int_arg91 = 0;
int int_arg92 = 0;
int int_arg93 = 0;
int int_arg94 = 0;
int int_arg95 = 0;
int int_arg96 = 0;
int int_arg97 = 0;
int int_arg98 = 0;
int int_arg99 = 0;
int int_arg100 = 0;
int int_arg101 = 0;
int int_arg102 = 0;
int int_arg103 = 0;
int int_arg104 = 0;
int int_arg105 = 0;
int int_arg106 = 0;
int int_arg107 = 0;
int int_arg108 = 0;
int int_arg109 = 0;
int int_arg110 = 0;
int int_arg111 = 0;
int int_arg112 = 0;
int int_arg113 = 0;
int int_arg114 = 0;
int int_arg115 = 0;
int int_arg116 = 0;
int int_arg117 = 0;
int int_arg118 = 0;
int int_arg119 = 0;
int int_arg120 = 0;
int int_arg121 = 0;
int int_arg122 = 0;
int int_arg123 = 0;
int int_arg124 = 0;
int int_arg125 = 0;
int int_arg126 = 0;
int int_arg127 = 0;
int int_arg128 = 0;

int generic_handler(const char *path, const char *types, lo_arg ** argv,
                    int argc, void *data, void *user_data);

int foo_handler(const char *path, const char *types, lo_arg ** argv,
                int argc, void *data, void *user_data);

int quit_handler(const char *path, const char *types, lo_arg ** argv,
                 int argc, void *data, void *user_data);

int main() {

    /* start a new server on port 8000 */
    lo_server_thread st = lo_server_thread_new("8000", error);

    /* add method that will match any path and args */
    lo_server_thread_add_method(st, NULL, NULL, generic_handler, NULL);

    /* add method that will match the path /foo/bar, with two numbers, coerced
     * to float and int */
    lo_server_thread_add_method(st, "/foo/bar", "fi", foo_handler, NULL);

    /* add method that will match the path /quit with no args */
    lo_server_thread_add_method(st, "/quit", "", quit_handler, NULL);

    lo_server_thread_start(st);

    while (!done) {
#ifdef WIN32
        Sleep(1);
#else
        usleep(1000);
#endif
    }

    lo_server_thread_free(st);

    return 0;
}

/* catch any incoming messages and display them. returning 1 means that the
 * message has not been fully handled and the server should try other methods
 */

int generic_handler(const char *path, const char *types, lo_arg ** argv,
                    int argc, void *data, void *user_data)

{
    int i;

    int sockfd, portno, n;
    int serverlen;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];
    hostname = SRV_IP;
    portno = PORT;

    char system_path[512]; /* added this char */

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    /* printf("path: %s\n", path); */
    sprintf(system_path,"128");

    for (i = 0; i < argc; i++) { /* value outputs in hex for 0-254 intensity */

    if (strcmp(path, "/01") == 0) { /* path 01-128 supported, RGBW */
        int_arg1=argv[i]->f;
    } else if (strcmp(path, "/02") == 0) {
        int_arg2=argv[i]->f;
    } else if (strcmp(path, "/03") == 0) {
        int_arg3=argv[i]->f;
    } else if (strcmp(path, "/04") == 0) {
        int_arg4=argv[i]->f;
    } else if (strcmp(path, "/05") == 0) {
        int_arg5=argv[i]->f;
    } else if (strcmp(path, "/06") == 0) {
        int_arg6=argv[i]->f;
    } else if (strcmp(path, "/07") == 0) {
        int_arg7=argv[i]->f;
    } else if (strcmp(path, "/08") == 0) {
        int_arg8=argv[i]->f;
    } else if (strcmp(path, "/09") == 0) {
        int_arg9=argv[i]->f;
    } else if (strcmp(path, "/10") == 0) {
        int_arg10=argv[i]->f;
    } else if (strcmp(path, "/11") == 0) {
        int_arg11=argv[i]->f;
    } else if (strcmp(path, "/12") == 0) {
        int_arg12=argv[i]->f;
    } else if (strcmp(path, "/13") == 0) {
        int_arg13=argv[i]->f;
    } else if (strcmp(path, "/14") == 0) {
        int_arg14=argv[i]->f;
    } else if (strcmp(path, "/15") == 0) {
        int_arg15=argv[i]->f;
    } else if (strcmp(path, "/16") == 0) {
        int_arg16=argv[i]->f;
    } else if (strcmp(path, "/17") == 0) {
        int_arg17=argv[i]->f;
    } else if (strcmp(path, "/18") == 0) {
        int_arg18=argv[i]->f;
    } else if (strcmp(path, "/19") == 0) {
        int_arg19=argv[i]->f;
    } else if (strcmp(path, "/20") == 0) {
        int_arg20=argv[i]->f;
    } else if (strcmp(path, "/21") == 0) {
        int_arg21=argv[i]->f;
    } else if (strcmp(path, "/22") == 0) {
        int_arg22=argv[i]->f;
    } else if (strcmp(path, "/23") == 0) {
        int_arg23=argv[i]->f;
    } else if (strcmp(path, "/24") == 0) {
        int_arg24=argv[i]->f;
    } else if (strcmp(path, "/25") == 0) {
        int_arg25=argv[i]->f;
    } else if (strcmp(path, "/26") == 0) {
        int_arg26=argv[i]->f;
    } else if (strcmp(path, "/27") == 0) {
        int_arg27=argv[i]->f;
    } else if (strcmp(path, "/28") == 0) {
        int_arg28=argv[i]->f;
    } else if (strcmp(path, "/29") == 0) {
        int_arg29=argv[i]->f;
    } else if (strcmp(path, "/30") == 0) {
        int_arg30=argv[i]->f;
    } else if (strcmp(path, "/31") == 0) {
        int_arg31=argv[i]->f;
    } else if (strcmp(path, "/32") == 0) {
        int_arg32=argv[i]->f;
    } else if (strcmp(path, "/33") == 0) {
        int_arg33=argv[i]->f;
    } else if (strcmp(path, "/34") == 0) {
        int_arg34=argv[i]->f;
    } else if (strcmp(path, "/35") == 0) {
        int_arg35=argv[i]->f;
    } else if (strcmp(path, "/36") == 0) {
        int_arg36=argv[i]->f;
    } else if (strcmp(path, "/37") == 0) {
        int_arg37=argv[i]->f;
    } else if (strcmp(path, "/38") == 0) {
        int_arg38=argv[i]->f;
    } else if (strcmp(path, "/39") == 0) {
        int_arg39=argv[i]->f;
    } else if (strcmp(path, "/40") == 0) {
        int_arg40=argv[i]->f;
    } else if (strcmp(path, "/41") == 0) {
        int_arg41=argv[i]->f;
    } else if (strcmp(path, "/42") == 0) {
        int_arg42=argv[i]->f;
    } else if (strcmp(path, "/43") == 0) {
        int_arg43=argv[i]->f;
    } else if (strcmp(path, "/44") == 0) {
        int_arg44=argv[i]->f;
    } else if (strcmp(path, "/45") == 0) {
        int_arg45=argv[i]->f;
    } else if (strcmp(path, "/46") == 0) {
        int_arg46=argv[i]->f;
    } else if (strcmp(path, "/47") == 0) {
        int_arg47=argv[i]->f;
    } else if (strcmp(path, "/48") == 0) {
        int_arg48=argv[i]->f;
    } else if (strcmp(path, "/49") == 0) {
        int_arg49=argv[i]->f;
    } else if (strcmp(path, "/50") == 0) {
        int_arg50=argv[i]->f;
    } else if (strcmp(path, "/51") == 0) {
        int_arg51=argv[i]->f;
    } else if (strcmp(path, "/52") == 0) {
        int_arg52=argv[i]->f;
    } else if (strcmp(path, "/53") == 0) {
        int_arg53=argv[i]->f;
    } else if (strcmp(path, "/54") == 0) {
        int_arg54=argv[i]->f;
    } else if (strcmp(path, "/55") == 0) {
        int_arg55=argv[i]->f;
    } else if (strcmp(path, "/56") == 0) {
        int_arg56=argv[i]->f;
    } else if (strcmp(path, "/57") == 0) {
        int_arg57=argv[i]->f;
    } else if (strcmp(path, "/58") == 0) {
        int_arg58=argv[i]->f;
    } else if (strcmp(path, "/59") == 0) {
        int_arg59=argv[i]->f;
    } else if (strcmp(path, "/60") == 0) {
        int_arg60=argv[i]->f;
    } else if (strcmp(path, "/61") == 0) {
        int_arg61=argv[i]->f;
    } else if (strcmp(path, "/62") == 0) {
        int_arg62=argv[i]->f;
    } else if (strcmp(path, "/63") == 0) {
        int_arg63=argv[i]->f;
    } else if (strcmp(path, "/64") == 0) {
        int_arg64=argv[i]->f;
    } else if (strcmp(path, "/65") == 0) {
        int_arg65=argv[i]->f;
    } else if (strcmp(path, "/66") == 0) {
        int_arg66=argv[i]->f;
    } else if (strcmp(path, "/67") == 0) {
        int_arg67=argv[i]->f;
    } else if (strcmp(path, "/68") == 0) {
        int_arg68=argv[i]->f;
    } else if (strcmp(path, "/69") == 0) {
        int_arg69=argv[i]->f;
    } else if (strcmp(path, "/70") == 0) {
        int_arg70=argv[i]->f;
    } else if (strcmp(path, "/71") == 0) {
        int_arg71=argv[i]->f;
    } else if (strcmp(path, "/72") == 0) {
        int_arg72=argv[i]->f;
    } else if (strcmp(path, "/73") == 0) {
        int_arg73=argv[i]->f;
    } else if (strcmp(path, "/74") == 0) {
        int_arg74=argv[i]->f;
    } else if (strcmp(path, "/75") == 0) {
        int_arg75=argv[i]->f;
    } else if (strcmp(path, "/76") == 0) {
        int_arg76=argv[i]->f;
    } else if (strcmp(path, "/77") == 0) {
        int_arg77=argv[i]->f;
    } else if (strcmp(path, "/78") == 0) {
        int_arg78=argv[i]->f;
    } else if (strcmp(path, "/79") == 0) {
        int_arg79=argv[i]->f;
    } else if (strcmp(path, "/80") == 0) {
        int_arg80=argv[i]->f;
    } else if (strcmp(path, "/81") == 0) {
        int_arg81=argv[i]->f;
    } else if (strcmp(path, "/82") == 0) {
        int_arg82=argv[i]->f;
    } else if (strcmp(path, "/83") == 0) {
        int_arg83=argv[i]->f;
    } else if (strcmp(path, "/84") == 0) {
        int_arg84=argv[i]->f;
    } else if (strcmp(path, "/85") == 0) {
        int_arg85=argv[i]->f;
    } else if (strcmp(path, "/86") == 0) {
        int_arg86=argv[i]->f;
    } else if (strcmp(path, "/87") == 0) {
        int_arg87=argv[i]->f;
    } else if (strcmp(path, "/88") == 0) {
        int_arg88=argv[i]->f;
    } else if (strcmp(path, "/89") == 0) {
        int_arg89=argv[i]->f;
    } else if (strcmp(path, "/90") == 0) {
        int_arg90=argv[i]->f;
    } else if (strcmp(path, "/91") == 0) {
        int_arg91=argv[i]->f;
    } else if (strcmp(path, "/92") == 0) {
        int_arg92=argv[i]->f;
    } else if (strcmp(path, "/93") == 0) {
        int_arg93=argv[i]->f;
    } else if (strcmp(path, "/94") == 0) {
        int_arg94=argv[i]->f;
    } else if (strcmp(path, "/95") == 0) {
        int_arg95=argv[i]->f;
    } else if (strcmp(path, "/96") == 0) {
        int_arg96=argv[i]->f;
    } else if (strcmp(path, "/97") == 0) {
        int_arg97=argv[i]->f;
    } else if (strcmp(path, "/98") == 0) {
        int_arg98=argv[i]->f;
    } else if (strcmp(path, "/99") == 0) {
        int_arg99=argv[i]->f;
    } else if (strcmp(path, "/100") == 0) {
        int_arg100=argv[i]->f;
    } else if (strcmp(path, "/101") == 0) {
        int_arg101=argv[i]->f;
    } else if (strcmp(path, "/102") == 0) {
        int_arg102=argv[i]->f;
    } else if (strcmp(path, "/103") == 0) {
        int_arg103=argv[i]->f;
    } else if (strcmp(path, "/104") == 0) {
        int_arg104=argv[i]->f;
    } else if (strcmp(path, "/105") == 0) {
        int_arg105=argv[i]->f;
    } else if (strcmp(path, "/106") == 0) {
        int_arg106=argv[i]->f;
    } else if (strcmp(path, "/107") == 0) {
        int_arg107=argv[i]->f;
    } else if (strcmp(path, "/108") == 0) {
        int_arg108=argv[i]->f;
    } else if (strcmp(path, "/109") == 0) {
        int_arg109=argv[i]->f;
    } else if (strcmp(path, "/110") == 0) {
        int_arg110=argv[i]->f;
    } else if (strcmp(path, "/111") == 0) {
        int_arg111=argv[i]->f;
    } else if (strcmp(path, "/112") == 0) {
        int_arg112=argv[i]->f;
    } else if (strcmp(path, "/113") == 0) {
        int_arg113=argv[i]->f;
    } else if (strcmp(path, "/114") == 0) {
        int_arg114=argv[i]->f;
    } else if (strcmp(path, "/115") == 0) {
        int_arg115=argv[i]->f;
    } else if (strcmp(path, "/116") == 0) {
        int_arg116=argv[i]->f;
    } else if (strcmp(path, "/117") == 0) {
        int_arg117=argv[i]->f;
    } else if (strcmp(path, "/118") == 0) {
        int_arg118=argv[i]->f;
    } else if (strcmp(path, "/119") == 0) {
        int_arg119=argv[i]->f;
    } else if (strcmp(path, "/120") == 0) {
        int_arg120=argv[i]->f;
    } else if (strcmp(path, "/121") == 0) {
        int_arg121=argv[i]->f;
    } else if (strcmp(path, "/122") == 0) {
        int_arg122=argv[i]->f;
    } else if (strcmp(path, "/123") == 0) {
        int_arg123=argv[i]->f;
    } else if (strcmp(path, "/124") == 0) {
        int_arg124=argv[i]->f;
    } else if (strcmp(path, "/125") == 0) {
        int_arg125=argv[i]->f;
    } else if (strcmp(path, "/126") == 0) {
        int_arg126=argv[i]->f;
    } else if (strcmp(path, "/127") == 0) {
        int_arg127=argv[i]->f;
    } else if (strcmp(path, "/128") == 0) {
        int_arg128=argv[i]->f;
    } else {
        printf("I don't support this path yet!? path: %s\n", path); /* add more path support later */
    }

        /* udp values from the osc server */
        sprintf(buf,"%s %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i", system_path, int_arg1, int_arg2, int_arg3, int_arg4, int_arg5, int_arg6, int_arg7, int_arg8, int_arg9, int_arg10, int_arg11, int_arg12, int_arg13, int_arg14, int_arg15, int_arg16, int_arg17, int_arg18, int_arg19, int_arg20, int_arg21, int_arg22, int_arg23, int_arg24, int_arg25, int_arg26, int_arg27, int_arg28, int_arg29, int_arg30, int_arg31, int_arg32, int_arg33, int_arg34, int_arg35, int_arg36, int_arg37, int_arg38, int_arg39, int_arg40, int_arg41, int_arg42, int_arg43, int_arg44, int_arg45, int_arg46, int_arg47, int_arg48, int_arg49, int_arg50, int_arg51, int_arg52, int_arg53, int_arg54, int_arg55, int_arg56, int_arg57, int_arg58, int_arg59, int_arg60, int_arg61, int_arg62, int_arg63, int_arg64, int_arg65, int_arg66, int_arg67, int_arg68, int_arg69, int_arg70, int_arg71, int_arg72, int_arg73, int_arg74, int_arg75, int_arg76, int_arg77, int_arg78, int_arg79, int_arg80, int_arg81, int_arg82, int_arg83, int_arg84, int_arg85, int_arg86, int_arg87, int_arg88, int_arg89, int_arg90, int_arg91, int_arg92, int_arg93, int_arg94, int_arg95, int_arg96, int_arg97, int_arg98, int_arg99, int_arg100, int_arg101, int_arg102, int_arg103, int_arg104, int_arg105, int_arg106, int_arg107, int_arg108, int_arg109, int_arg110, int_arg111, int_arg112, int_arg113, int_arg114, int_arg115, int_arg116, int_arg117, int_arg118, int_arg119, int_arg120, int_arg121, int_arg122, int_arg123, int_arg124, int_arg125, int_arg126, int_arg127, int_arg128);

        /* send the message to the server */
        serverlen = sizeof(serveraddr);
        n = sendto(sockfd, buf, strlen(buf), 0, &serveraddr, serverlen);
        close(i);
        if (n < 0)
                error("ERROR in sendto");
        printf("\n");
    }
    fflush(stdout);
    return 1;
}

int foo_handler(const char *path, const char *types, lo_arg ** argv,
                int argc, void *data, void *user_data)
{
    /* example showing pulling the argument values out of the argv array */
    printf("%s <- f:%f, i:%d\n\n", path, argv[0]->f, argv[1]->i);
    fflush(stdout);

    return 0;
}

int quit_handler(const char *path, const char *types, lo_arg ** argv,
                 int argc, void *data, void *user_data)
{
    done = 1;
    printf("quiting\n\n");
    fflush(stdout);

    return 0;
}

/* vi:set ts=8 sts=4 sw=4: */
