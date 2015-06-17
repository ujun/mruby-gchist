#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/string.h"
#include "mruby/array.h"
#include "/usr/include/sqlite3.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

  mrb_state* mrb = mrb_open();
  FILE* f = fopen("/Users/juchino/myruby/src/ujun/mruby_build/mruby-gchist/gchist.rb", "r");
  mrb_load_file(mrb, f);
  fclose(f);

  mrb_value ret;

  if(argc == 1) {
    char *s = "";
    mrb_value str = mrb_str_new(mrb, s, 0);
    ret = mrb_funcall(mrb, mrb_top_self(mrb), "gchist", 1, str);
  }else{
    mrb_value str = mrb_str_new(mrb, argv[1], strlen(argv[1]));
    ret = mrb_funcall(mrb, mrb_top_self(mrb), "gchist", 1, str);
  }

  mrb_close(mrb);

  for(int i = 0; i < RARRAY_LEN(ret); i++){
    printf("%s\n", RSTRING_PTR(mrb_ary_ref(mrb, ret, i)));
  }

  return 0;
}
