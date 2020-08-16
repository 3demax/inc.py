#include <stdio.h>
#include "runtime.h"

#define DISPLAY 2
#define IN 1
#define OUT 0

#define FILENAME_MAX_LENGTH 100
#define CMD_MAX_LENGTH 100


static void print_ptr_rec(FILE* port, ptr x, int state) {
  if ((x & fx_mask) == fx_tag) {
    fprintf(port, "%d", ((int) x) >> fx_shift);
  } else if (x == bool_f) {
    fprintf(port, "False");
  } else if (x == bool_t) {
    fprintf(port, "True");
  } else if (x == list_nil) {
    fprintf(port, "None");
//  } else if (x == eof_obj) {
//    fprintf(port, "#!eof");
//  } else if ((x & char_mask) == char_tag) {
//    char c = (char) (x >> char_shift);
//    if (state == DISPLAY) {
//      fputc(c, port);
//    } else {
//      if      (c == '\t') fprintf(port, "#\\tab");
//      else if (c == '\n') fprintf(port, "#\\newline");
//      else if (c == '\r') fprintf(port, "#\\return");
//      else if (c == ' ')  fprintf(port, "#\\space");
//      else                fprintf(port, "#\\%c", c);
//    }
//  } else if ((x & obj_mask) == pair_tag) {
//    if (state == OUT) fprintf(port, "(");
//    ptr car = ((cell*)(x-pair_tag))->car;
//    print_ptr_rec(port, car, OUT);
//    ptr cdr = ((cell*)(x-pair_tag))->cdr;
//    if (cdr != list_nil) {
//      if ((cdr & obj_mask) != pair_tag) {
//        fprintf(port, " . ");
//        print_ptr_rec(port, cdr, OUT);
//      } else {
//        fprintf(port, " ");
//        print_ptr_rec(port, cdr, IN);
//      }
//    }
//    if (state == OUT) fprintf(port, ")");
//  } else if ((x & obj_mask) == vector_tag) {
//    fprintf(port, "#(");
//
//    vector* p = (vector*)(x-vector_tag);
//    unsigned int n = p->length >> fx_shift;
//    unsigned int i;
//    for (i = 0; i < n; i++) {
//      if (i > 0) fprintf(port, " ");
//      print_ptr_rec(port, p->buf[i], OUT);
//    }
//
//    fprintf(port, ")");
//  } else if ((x & obj_mask) == string_tag) {
//    int q = state != DISPLAY;
//    if (q) fprintf(port, "\"");
//
//    string* p = (string*)(x-string_tag);
//    unsigned int n = p->length >> fx_shift;
//    unsigned int i;
//    for (i = 0; i < n; i++) {
//      int c = p->buf[i];
//      if      (q && c == '"' ) fprintf(port, "\\\"");
//      else if (q && c == '\\') fprintf(port, "\\\\");
//      else                     fputc(c, port);
//    }
//
//    if (q) fprintf(port, "\"");
//  } else if ((x & obj_mask) == symbol_tag) {
//    print_ptr_rec(port, (x - symbol_tag) | string_tag, DISPLAY);
//  } else if ((x & obj_mask) == closure_tag) {
//    fprintf(port, "#<procedure>");
  } else {
    fprintf(port, "#<unknown 0x%08x>", x);
  }
}

static void print_ptr(ptr x) {
  print_ptr_rec(stdout, x, OUT);
  printf("\n");
}


int main(int argc, char** argv) {
  print_ptr(py_entry());
  return 0;
}
