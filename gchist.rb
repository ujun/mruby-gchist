# -*- coding: utf-8 -*-

db = SQLite3::Database.new('/Users/juchino/Library/Application Support/Google/Chrome/Default/History')

db.execute("select * from urls") do |row, column|
  print row[1] + "------------" + row[2] + "\n"
end
