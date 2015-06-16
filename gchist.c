#include "mruby.h"
#include "mruby/compile.h"
#include "/usr/include/sqlite3.h"

int main() {
  char* code = "db = SQLite3::Database.new('/Users/juchino/Library/Application Support/Google/Chrome/Default/History') \n db.execute('select * from urls') do |row, column| \n print row[2] + '\n' end \n";

  mrb_state* mrb = mrb_open();
  mrb_load_string(mrb, code);
  mrb_close(mrb);

  return 0;
}
