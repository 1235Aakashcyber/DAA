#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

#define MAX_CHARS 256
#define MAX_NODES (MAX_CHARS * 2)

int weight[MAX_NODES], parent[MAX_NODES], left[MAX_NODES], right[MAX_NODES];
char codes[MAX_CHARS][MAX_CHARS];
int leaf_index[MAX_CHARS];

int main(void) {
     char input[1024];
     int freq[MAX_CHARS];
     int i, j;
     clrscr();

     if (!fgets(input, sizeof(input), stdin)) return 0;
     /* remove trailing newline */
     i = strlen(input);
     if (i > 0 && input[i-1] == '\n') input[i-1] = '\0';

     for (i = 0; i < MAX_CHARS; ++i) freq[i] = 0;
     for (i = 0; input[i]; ++i) freq[(unsigned char)input[i]]++;

     for (i = 0; i < MAX_CHARS; ++i) leaf_index[i] = -1;

     /* create leaves */
     int n = 0;
     for (i = 0; i < MAX_CHARS; ++i) {
          if (freq[i] > 0) {
                weight[n] = freq[i];
                parent[n] = left[n] = right[n] = -1;
                leaf_index[i] = n;
                n++;
          }
     }

     if (n == 0) { printf("No input chars.\n"); return 0; }
     if (n == 1) {
          /* single char: code "0" */
          for (i = 0; i < MAX_CHARS; ++i) codes[i][0] = '\0';
          for (i = 0; i < MAX_CHARS; ++i) if (leaf_index[i] != -1) strcpy(codes[i], "0");
     } else {
          int total = 2 * n - 1;
          /* build tree by repeatedly combining two smallest nodes with no parent */
          for (i = n; i < total; ++i) {
                int s1 = -1, s2 = -1, k;
                /* find smallest */
                for (k = 0; k < i; ++k) if (parent[k] == -1) {
                     if (s1 == -1 || weight[k] < weight[s1]) s1 = k;
                }
                /* find second smallest */
                for (k = 0; k < i; ++k) if (parent[k] == -1 && k != s1) {
                     if (s2 == -1 || weight[k] < weight[s2]) s2 = k;
                }
                weight[i] = weight[s1] + weight[s2];
                left[i] = s1; right[i] = s2;
                parent[s1] = parent[s2] = i;
                parent[i] = -1;
          }
          /* generate codes by walking from leaves to root */
          for (i = 0; i < MAX_CHARS; ++i) codes[i][0] = '\0';
          for (i = 0; i < MAX_CHARS; ++i) {
                int idx = leaf_index[i];
                if (idx == -1) continue;
                char rev[256];
                int pos = 0;
                int p = idx;
                while (parent[p] != -1) {
                     int par = parent[p];
                     if (left[par] == p) rev[pos++] = '0';
                     else rev[pos++] = '1';
                     p = par;
                }
                if (pos == 0) { rev[pos++] = '0'; } /* safety for single-node trees */
                rev[pos] = '\0';
                /* reverse into codes[i] */
                int a;
                for (a = 0; a < pos; ++a) codes[i][a] = rev[pos - 1 - a];
                codes[i][pos] = '\0';
          }
     }

     /* print codes */
     printf("Char  ASCII  Freq  Code\n");
     for (i = 0; i < MAX_CHARS; ++i) {
          if (leaf_index[i] != -1) {
                if (i >= 32 && i <= 126)
                     printf(" '%c'  %3d   %4d   %s\n", i, i, freq[i], codes[i]);
                else
                     printf(" 0x%02X  %3d   %4d   %s\n", i, i, freq[i], codes[i]);
          }
     }

     /* encode */
     char encoded[8192];
     encoded[0] = '\0';
     for (i = 0; input[i]; ++i) {
          int li = leaf_index[(unsigned char)input[i]];
          strcat(encoded, codes[(unsigned char)input[i]]);
     }
     printf("\nEncoded bits:\n%s\n", encoded);

     /* decode to verify */
     printf("\nDecoded string:\n");
     if (n == 1) {
          /* all bits decode to the single character */
          for (i = 0; i < (int)strlen(encoded); ++i) putchar((char) ( /* find the only char */ (int)0 ));
          /* simpler: print the unique char freq times */
          for (i = 0; i < MAX_CHARS; ++i) if (leaf_index[i] != -1) {
                int k;
                for (k = 0; k < freq[i]; ++k) putchar((char)i);
                break;
          }
          putchar('\n');
     } else {
          int root = 2*n - 2;
          int cur;
          cur = root;
          for (i = 0; encoded[i]; ++i) {
                if (encoded[i] == '0') cur = left[cur];
                else cur = right[cur];
                if (left[cur] == -1 && right[cur] == -1) { /* leaf */
                     /* find which character this leaf corresponds to */
                     int ch;
                     for (ch = 0; ch < MAX_CHARS; ++ch) if (leaf_index[ch] == cur) {
                          putchar((char)ch); break;
                     }
                     cur = root;
                }
          }
          putchar('\n');
     }
     getch();
     return 0;
}