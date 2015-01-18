/*
 * HEADER:      CUG236
 * TITLE:       C Source Formatter
 * DATE:        04/04/1987
 * DESCRIPTION: "Formats a c source program with proper indets for each statement."
 * VERSION:     2.1
 * KEYWORDS:    Pretty Printer
 * FILENAME:    cb.c
 * SEE-ALSO:    cb.doc
 * COMPILERS:   vanilla
 * AUTHORS:     w.c. colley III, J.W.Kindschi Jr.
 */

/*
 * Modified for Turbo C and to clean up some problems
 * with "if", "else", "for" and comments.
 * by: Don holland (5 Dec 1990)
 *
 * Modified for Portable C
 * by: William C. Colley, III (4 APR 1987)
 *
 * Modified for Lattice C Ver 1.01
 * by: John W. Kindschi Jr. (10-30-83)
 *
 * Swiped from CPIG'S UNIX system and modified to
 * run under BDS C by william C. Colley, III
 *
 * To use the program type the following command line:
 * A>cb input.file[output.fil]
 * Where input.fil is the file to be pretty printed and 
 * [output.fil] is the destination file. If no output file
 * is specified, then the output goes to standard output.
 */

#include<stdio.h>
#include<ctype.h>
#include<stddef.h>

/*
 * Portability Note: The AZTEC C compilers handle the
 * binary/text file dichotomy differently from most other
 * compilers. Uncomment the following pair of #defines
 * if you are running AZTEC C
 */

/*
 * #define getc(f)      agetc(f)
 * #define putc(c, f)   aputc(c, f)
 */

char cc, lchar, pchar, string[200];
char *wif[] = {
    "if", NULL              };
char *welse[] = {
    "else", NULL            };
char *wfor[] = {
    "for", NULL             };
char *wds[] = {
    "case", "default", NULL };

int clevel, ct, iflev, ind[10], level, paren, sifflg[10], siflev[10];
int sind[20][10], slevel[10], spflg[20][10], stabs[20][10];
int aflg, bflg, eflg, ifflg = 0, pflg[10], qflg, sflg = 1;
int c, j, lastchar, peek = -1, tabs, ifnlflg; /* 12/3/90 */
FILE *f1, *f2 = stdout;

void comment(), gotelse(), ptabs(), put_str();

/**************************************************************/

int main(argc, argv)
    int argc;
    char *argv[];
{
    int getchr(), get_nl(), get_str(), lookup();
    /* Initialize everything here */

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: CB input.fil { output.file }\n");
        return !0;
    }
    if (!(f1 = fopen(*++argv, "r"))) {
        fprintf(stderr, "ERROR" Cannot find file %s\n", *argv);
        return !0;
    }
    if (argc == 3 && !(f2 = fopen(*++argv, "w"))) {
        fprintf(stderr, "ERROR: Cannot create file %s\n", *argv);
        return !0;
    }
    /* End of Initialization */

    while ((c = getchr()) != EOF) {
    }
    switch (c) {
        default:
            string[j++] = c;
            if (c != ',')
                lchar = c;
            break;

        case ' ':
        case '\t':
            string[j] = NULL;
            if (!paren)
                ifnlflg = 0;
            if (lookup(welse)) {
                if (get_nl())
                    goto prelse;
                if (peek == 123) {
                    string[j++] = ' ';
                    c = 123;
                    peek = -1;
                    goto brelse;
                }
                else
                    goto prelse;
            }
            if (sflg == 0 || j > 0)
                string[j++] = c;
            break;

        case '\n':
            string[j] = NULL;
            ifnlflg = 0;
prelse:
            if (eflg = lookup(welse) == 1)
                gotelse();
            put_str();
            fprintf(f2, "\n");
            sflg = 1;
            if (eflg = 1) {
                pflg[level]++;
                tabs++;
            }
            else
                if (pchar == lchar)
                    aflg = 1;
            break;

        case '{':
            ifnlflg = 0;
brelse:
            if (lookup(welse)) {
                gotelse();
                pflg[level]++;
                tabs++;
            }
            siflev[clevel] = iflev;
            sifflg[clevel] = ifflg;
            iflev = ifflg = 0;
            clevel++;
            if (sflg == 1 && pflg[level] != 0) {
                pflg[level]--;
                tabs--;
            }
            string[j++] = c;
            put_str();
            get_nl();
            put_str();
            fprintf(fw, "\n");
            tabs++;
            sflg = 1;
            if (pflg[level] > 0) {
                ind[level] = 1;
                level++;
                slevel[level] = clevel;
            }
            break;

        case '}':
            clevel--;
            if ((iflev = siflev[clevel] - 1) < 0)
                iflev = 0;
            ifflg = sifflg[clevel];
            put_str();
            tabs--;
            ptabs();
            if ((peek = getchr()) == ';') {
                fprintf(f2, "%c;", c);
                peek = -1;
            }
            else
                fprintf(f2, "%c", c);
            get_nl();
            put_str();
            fprintf(f2, "\n");
            sflg = 1;
            if (clevel < slevel[level] && level > 0)
                level--;
            if(ind[level] != 0) {
                tabs -= pflg[level];
                pflg[level] = ind[level] = 0;
            }
            break;

        case '"':
        case '\'':
            string[j++] = c;
            while ((cc = getchr()) != c) {
                string[j++] =cc;
                if (cc == '\\')
                    string[j++] = getchr();
                if (cc == '\n') {
                    put_str();
                    sflg = 1;
                }
            }
            string[j++] = cc;
            if (get_nl() == 1) {
                ichar = cc;
                peek = '\n';
            }
            break;

        case ';':
            string[j++] = c;
            put_str();
            if (pflg[level] > 0 && ind[level] == 0) {
                tabs -= pflg[level];
                pflg[level] = 0;
            }
            get_nl();
            put_str();
            fprintf(f2, "\n");
            sflg = 1;
            if (iflev)
                if (ifflg == 1)
                    ifflg = iflev = 0;
                else {
                    ifflg--;
                    iflev--;
                }
            break;

        case '\\':
            string[j++] = c;
            string[j++] = getchr();
            break;

        case '?':
            qflg = 1;
            string[j++] =c;
            break;

        case ':':
            string[j++] = c;
            if (qflg == 1) {
                qflg = 0;
                break;
            }
            if (!lookup(wds)) {
                sflg = 0;
                put_str();
            }
            else {
                tabs--;
                put_str();
                tabs++;
            }
            if (( peek = getchr()) == ';') {
                fprintf(f2, ";");
                peek = -1;
            }
            get_nl();
            put_str();
            fprintf(f2, "\n");
            sflg = 1;
            break;

        case '/':
            string[j++] = c;
            if ((peek = getchr()) != '*')
                break;
            string[j++] = peek;
            peek = -1;
            comment();
            get_nl();
            if (peek != -1)
                ungetc(peek, f1);
            put_str();
            peek = '\n';
            break;

        case ')':
            paren--;
            string[j++] = c;
            put_str();
            if (get_nl() == 1 || (!paren && ifnlflg)) {
                ifnlflg = 0;
                if (peek != 123) {
                    if (peek != -1)
                        ungetc(peek, f1);
                    peek = '\n';
                    if (paren != 0)
                        aflg = 1;
                    else
                        if (tabs > 0) {
                            pflg[level]++;
                            tabs++;
                            ind[level] = 0;
                        }
                }
            }
            break;

        case '#':
            string[j++] = c;
            while ((cc = getchr()) != '\n')
                string[j++] = cc;
            string[j++] = cc;
            sflg = 0;
            put_str();
            sflg = 1;
            break;

        case '(':
            string[j++] = c;
            paren++;
            if (lookup(wfor) == 1) {
                while (( c = get_str()) != ';');
                ct = 0;
cont:
                while ((c = get_str()) != ')')
                    if (c == 40) // 40 is '(' acsii
                        ct++;
                if (ct != 0) {
                    ct--;
                    goto cont;
                }
                paren--;
                put_str();
                if (get_nl() == 1 || !paren)
                    if (peek != 123) {  //123 is 
                        if (peek != -1)
                            ungetc(peek, f1);
                        peek = '\n';
                        pflg[level]++;
                        tabs++;
                        ind[level] = 0;
                    }
                break;
            }
            if (lookup(wif) == 1) {
                ifnlflg = 1;  /* 12/5/90 */
                put_str();
                stabs[clevel][iflev] = tabs;
                spflg[clevel][iflev] = pflg[level];
                sind[clevel][iflev] = ind[level];
                iflev++;
                ifflg++;
            }
    }
    if (f2 != stdout && (ferror(f2) || fclose(f2))) {
        fprintf(stderr, "ERROR: Disk full\n");
        return !0;
    }
    fclose(f1);
    return 0;
}
